/*
 * Benchmark Program: R000777
 * Security Family: nested_implicit_flow
 * Generator Seed: 577713
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000777_7713_0 {
    int determinant;
    unsigned char trace;
    short density;
    int dim;
    int stride;
    int buffer[3];
};

struct Transaction_R000777_7713_1 {
    int balance;
    int status;
    int fee;
    int buffer[3];
};

struct Vector3D_R000777_7713_2 {
    int heading;
    int coord_x;
    int norm_sq;
    short coord_y;
    int coord_z;
    int pitch;
    int buffer[3];
};

union TelemetryField_R000777_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000777_7713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_77 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_77 > 36) {
        acc = (acc + vector_77 * 2 + 5) & 127;
        aux ^= (vector_77 & 15);
    } else {
        acc = (acc - vector_77 + 11) & 127;
        aux += 3;
    }
    int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_43) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_27 = local_arr[aux % 3];
    acc = (acc + quotient_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_1(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000777_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_75 = local_arr[aux % 3];
    acc = (acc + mask_75 * 2) & 127;
    int damping_34 = (aux + st.buffer[1]) & 3;
    switch (damping_34) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000777_7713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000777_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_72 = local_arr[aux % 3];
    acc = (acc + stride_72 * 2) & 127;
    int mask_12 = (aux + st.buffer[1]) & 3;
    switch (mask_12) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000777_7713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000777_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int offset_93 = local_arr[aux % 3];
    acc = (acc + offset_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000777_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int weight_45 = local_arr[aux % 3];
    acc = (acc + weight_45 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000777_7713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_42 = (aux + st.buffer[1]) & 3;
    switch (anchor_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_30 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_30 > 44) {
        acc = (acc + quantum_30 * 2 + 5) & 127;
        aux ^= (quantum_30 & 15);
    } else {
        acc = (acc - quantum_30 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000777_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_83 = (aux + st.buffer[1]) & 3;
    switch (phase_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_72 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_72 > 33) {
        acc = (acc + damping_72 * 2 + 5) & 127;
        aux ^= (damping_72 & 15);
    } else {
        acc = (acc - damping_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_72 = local_arr[aux % 3];
    acc = (acc + factor_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_7(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_88) & 63;
    acc ^= aux;
    int metric_35 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_35 > 39) {
        acc = (acc + metric_35 * 2 + 5) & 127;
        aux ^= (metric_35 & 15);
    } else {
        acc = (acc - metric_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_42 = local_arr[aux % 3];
    acc = (acc + cursor_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000777_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int index_reg_21 = local_arr[aux % 3];
    acc = (acc + index_reg_21 * 2) & 127;
    int stride_56 = (aux + st.buffer[1]) & 3;
    switch (stride_56) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_79 > 43) {
        acc = (acc + cursor_79 * 2 + 5) & 127;
        aux ^= (cursor_79 & 15);
    } else {
        acc = (acc - cursor_79 + 11) & 127;
        aux += 3;
    }
    int threshold_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000777_7713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_92) & 63;
    acc ^= aux;
    int bound_85 = (aux + st.buffer[1]) & 3;
    switch (bound_85) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_10 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_10 > 44) {
        acc = (acc + vector_10 * 2 + 5) & 127;
        aux ^= (vector_10 & 15);
    } else {
        acc = (acc - vector_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000777_7713_10(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_55 = local_arr[aux % 3];
    acc = (acc + quantum_55 * 2) & 127;
    int index_reg_18 = (aux + st.buffer[1]) & 3;
    switch (index_reg_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000777_7713_11(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int phase_84 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_84 > 21) {
        acc = (acc + phase_84 * 2 + 5) & 127;
        aux ^= (phase_84 & 15);
    } else {
        acc = (acc - phase_84 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_73 = local_arr[aux % 3];
    acc = (acc + factor_73 * 2) & 127;
    int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000777_7713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000777_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000777_7713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000777_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_29 = (aux + st.buffer[1]) & 3;
    switch (quotient_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_37 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_37 > 24) {
        acc = (acc + metric_37 * 2 + 5) & 127;
        aux ^= (metric_37 & 15);
    } else {
        acc = (acc - metric_37 + 11) & 127;
        aux += 3;
    }
    int threshold_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000777_0;
    int sec_r000777_1;
    int sec_r000777_2;
    int sec_r000777_3;
    int sec_r000777_4;
    int sec_r000777_5;
    int sec_r000777_6;
    int sec_r000777_7;
    int sec_r000777_8;
    int sec_r000777_9;
    int sec_r000777_10;
    int sec_r000777_11;
    int sec_r000777_12;
    int sec_r000777_13;
    int sec_r000777_14;
    int sec_r000777_15;
    int sec_r000777_16;
    int sec_r000777_17;
    int sec_r000777_18;
    int pub_r000777_0;
    int pub_r000777_1;
    int pub_r000777_2;
    int pub_r000777_3;
    int pub_r000777_4;
    int pub_r000777_5;
    int pub_r000777_6;
    int pub_r000777_7;
    int pub_r000777_8;
    int pub_r000777_9;
    int pub_r000777_10;
    int pub_r000777_11;
    int pub_r000777_12;
    int pub_r000777_13;
    int pub_r000777_14;
    int pub_r000777_15;
    int pub_r000777_16;
    int pub_r000777_17;
    int pub_r000777_18;
    int pub_r000777_19;
    int pub_r000777_20;
    int pub_r000777_21;
    int pub_r000777_22;
    int pub_r000777_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000777_0 >= -100 && pub_r000777_0 <= 100);
    __CPROVER_assume(pub_r000777_1 >= -100 && pub_r000777_1 <= 100);
    __CPROVER_assume(pub_r000777_2 >= -100 && pub_r000777_2 <= 100);
    __CPROVER_assume(pub_r000777_3 >= -100 && pub_r000777_3 <= 100);
    __CPROVER_assume(pub_r000777_4 >= -100 && pub_r000777_4 <= 100);
    __CPROVER_assume(pub_r000777_5 >= -100 && pub_r000777_5 <= 100);
    __CPROVER_assume(pub_r000777_6 >= -100 && pub_r000777_6 <= 100);
    __CPROVER_assume(pub_r000777_7 >= -100 && pub_r000777_7 <= 100);
    __CPROVER_assume(pub_r000777_8 >= -100 && pub_r000777_8 <= 100);
    __CPROVER_assume(pub_r000777_9 >= -100 && pub_r000777_9 <= 100);
    __CPROVER_assume(pub_r000777_10 >= -100 && pub_r000777_10 <= 100);
    __CPROVER_assume(pub_r000777_11 >= -100 && pub_r000777_11 <= 100);
    __CPROVER_assume(pub_r000777_12 >= -100 && pub_r000777_12 <= 100);
    __CPROVER_assume(pub_r000777_13 >= -100 && pub_r000777_13 <= 100);
    __CPROVER_assume(pub_r000777_14 >= -100 && pub_r000777_14 <= 100);
    __CPROVER_assume(pub_r000777_15 >= -100 && pub_r000777_15 <= 100);
    __CPROVER_assume(pub_r000777_16 >= -100 && pub_r000777_16 <= 100);
    __CPROVER_assume(pub_r000777_17 >= -100 && pub_r000777_17 <= 100);
    __CPROVER_assume(pub_r000777_18 >= -100 && pub_r000777_18 <= 100);
    __CPROVER_assume(pub_r000777_19 >= -100 && pub_r000777_19 <= 100);
    __CPROVER_assume(pub_r000777_20 >= -100 && pub_r000777_20 <= 100);
    __CPROVER_assume(pub_r000777_21 >= -100 && pub_r000777_21 <= 100);
    __CPROVER_assume(pub_r000777_22 >= -100 && pub_r000777_22 <= 100);
    __CPROVER_assume(pub_r000777_23 >= -100 && pub_r000777_23 <= 100);
    __CPROVER_assume(sec_r000777_0 >= 0 && sec_r000777_0 <= 255);
    __CPROVER_assume(sec_r000777_1 >= 0 && sec_r000777_1 <= 255);
    __CPROVER_assume(sec_r000777_2 >= 0 && sec_r000777_2 <= 255);
    __CPROVER_assume(sec_r000777_3 >= 0 && sec_r000777_3 <= 255);
    __CPROVER_assume(sec_r000777_4 >= 0 && sec_r000777_4 <= 255);
    __CPROVER_assume(sec_r000777_5 >= 0 && sec_r000777_5 <= 255);
    __CPROVER_assume(sec_r000777_6 >= 0 && sec_r000777_6 <= 255);
    __CPROVER_assume(sec_r000777_7 >= 0 && sec_r000777_7 <= 255);
    __CPROVER_assume(sec_r000777_8 >= 0 && sec_r000777_8 <= 255);
    __CPROVER_assume(sec_r000777_9 >= 0 && sec_r000777_9 <= 255);
    __CPROVER_assume(sec_r000777_10 >= 0 && sec_r000777_10 <= 255);
    __CPROVER_assume(sec_r000777_11 >= 0 && sec_r000777_11 <= 255);
    __CPROVER_assume(sec_r000777_12 >= 0 && sec_r000777_12 <= 255);
    __CPROVER_assume(sec_r000777_13 >= 0 && sec_r000777_13 <= 255);
    __CPROVER_assume(sec_r000777_14 >= 0 && sec_r000777_14 <= 255);
    __CPROVER_assume(sec_r000777_15 >= 0 && sec_r000777_15 <= 255);
    __CPROVER_assume(sec_r000777_16 >= 0 && sec_r000777_16 <= 255);
    __CPROVER_assume(sec_r000777_17 >= 0 && sec_r000777_17 <= 255);
    __CPROVER_assume(sec_r000777_18 >= 0 && sec_r000777_18 <= 255);

    struct MatrixBlock_R000777_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000777_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000777_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000777_0 + 7) & 15;
    struct Transaction_R000777_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000777_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000777_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000777_0 + 9) & 15;
    struct Vector3D_R000777_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000777_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000777_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000777_0 + 11) & 15;

    union TelemetryField_R000777_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 17) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 32) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 30) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 45) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 21) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 36) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 16) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 31) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 36) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 51) {
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
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 28) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 43) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 31) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 46) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 16) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 31) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
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
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 47) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 37) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 52) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 39) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 54) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 34) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 49) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000777_4 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_92 = (pub_r000777_12 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000777_12 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000777_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000777_18 & 1) != 0) {
        if ((sec_r000777_3 & 2) != 0) {
            stage_v_93 = (pub_r000777_22 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000777_22 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000777_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_94 = (pub_r000777_20 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000777_20 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000777_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000777_6 & 2) != 0) {
            stage_v_95 = (pub_r000777_21 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000777_21 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000777_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000777_6 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_96 = (pub_r000777_18 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000777_18 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000777_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000777_0 & 1) != 0) {
        if ((sec_r000777_17 & 2) != 0) {
            stage_v_97 = (pub_r000777_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000777_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000777_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000777_3 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_98 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000777_9 & 1) != 0) {
        if ((sec_r000777_18 & 2) != 0) {
            stage_v_99 = (pub_r000777_23 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000777_23 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000777_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_100 = (pub_r000777_16 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000777_16 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000777_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000777_7 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_101 = (pub_r000777_2 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000777_2 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000777_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000777_14 & 1) != 0) {
        if ((sec_r000777_1 & 2) != 0) {
            stage_v_102 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000777_9 & 2) != 0) {
            stage_v_103 = (pub_r000777_15 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000777_15 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000777_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000777_18 & 2) != 0) {
            stage_v_104 = (pub_r000777_7 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000777_7 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000777_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000777_7 & 1) != 0) {
        if ((sec_r000777_1 & 2) != 0) {
            stage_v_105 = (pub_r000777_23 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000777_23 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000777_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000777_3 & 1) != 0) {
        if ((sec_r000777_17 & 2) != 0) {
            stage_v_106 = (pub_r000777_3 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000777_3 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000777_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000777_15 & 1) != 0) {
        if ((sec_r000777_7 & 2) != 0) {
            stage_v_107 = (pub_r000777_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000777_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000777_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_108 = (pub_r000777_13 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000777_13 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000777_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000777_13 & 1) != 0) {
        if ((sec_r000777_3 & 2) != 0) {
            stage_v_109 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_110 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000777_6 & 2) != 0) {
            stage_v_111 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_112 = (pub_r000777_5 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000777_5 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000777_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000777_3 & 2) != 0) {
            stage_v_113 = (pub_r000777_17 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000777_17 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000777_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000777_6 & 1) != 0) {
        if ((sec_r000777_9 & 2) != 0) {
            stage_v_114 = (pub_r000777_14 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000777_14 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000777_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_115 = (pub_r000777_5 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000777_5 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000777_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000777_5 & 2) != 0) {
            stage_v_116 = (pub_r000777_17 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000777_17 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000777_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_117 = (pub_r000777_6 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000777_6 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000777_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000777_13 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_118 = (pub_r000777_6 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000777_6 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000777_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000777_5 & 2) != 0) {
            stage_v_119 = (pub_r000777_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000777_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000777_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000777_15 & 2) != 0) {
            stage_v_120 = (pub_r000777_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000777_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000777_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_121 = (pub_r000777_12 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000777_12 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000777_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000777_12 & 2) != 0) {
            stage_v_122 = (pub_r000777_14 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000777_14 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000777_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000777_17 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_123 = (pub_r000777_0 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000777_0 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000777_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_124 = (pub_r000777_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000777_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000777_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_125 = (pub_r000777_2 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000777_2 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000777_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000777_0 & 2) != 0) {
            stage_v_126 = (pub_r000777_12 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000777_12 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000777_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_127 = (pub_r000777_12 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000777_12 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000777_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_128 = (pub_r000777_15 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000777_15 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000777_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000777_1 & 1) != 0) {
        if ((sec_r000777_2 & 2) != 0) {
            stage_v_129 = (pub_r000777_2 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000777_2 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000777_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000777_11 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_130 = (pub_r000777_17 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000777_17 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000777_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000777_18 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_131 = (pub_r000777_7 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000777_7 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000777_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000777_9 & 2) != 0) {
            stage_v_132 = (pub_r000777_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000777_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000777_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000777_3 & 2) != 0) {
            stage_v_133 = (pub_r000777_21 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000777_21 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000777_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_134 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000777_16 & 1) != 0) {
        if ((sec_r000777_0 & 2) != 0) {
            stage_v_135 = (pub_r000777_7 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000777_7 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000777_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_136 = (pub_r000777_20 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000777_20 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000777_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000777_1 & 2) != 0) {
            stage_v_137 = (pub_r000777_9 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000777_9 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000777_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000777_17 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_138 = (pub_r000777_9 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000777_9 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000777_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_139 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_140 = (pub_r000777_23 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000777_23 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000777_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_141 = (pub_r000777_22 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000777_22 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000777_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000777_11 & 1) != 0) {
        if ((sec_r000777_5 & 2) != 0) {
            stage_v_142 = (pub_r000777_16 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000777_16 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000777_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000777_17 & 2) != 0) {
            stage_v_143 = (pub_r000777_1 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000777_1 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000777_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000777_8 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_144 = (pub_r000777_5 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000777_5 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000777_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000777_15 & 2) != 0) {
            stage_v_145 = (pub_r000777_20 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000777_20 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000777_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000777_11 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_146 = (pub_r000777_15 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000777_15 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000777_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_147 = (pub_r000777_6 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000777_6 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000777_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000777_8 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_148 = (pub_r000777_2 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000777_2 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000777_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000777_18 & 2) != 0) {
            stage_v_149 = (pub_r000777_9 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000777_9 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000777_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000777_15 & 2) != 0) {
            stage_v_150 = (pub_r000777_20 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000777_20 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000777_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000777_18 & 1) != 0) {
        if ((sec_r000777_0 & 2) != 0) {
            stage_v_151 = (pub_r000777_10 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000777_10 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000777_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_152 = (pub_r000777_3 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000777_3 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000777_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_153 = (pub_r000777_12 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000777_12 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000777_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000777_11 & 1) != 0) {
        if ((sec_r000777_7 & 2) != 0) {
            stage_v_154 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000777_17 & 2) != 0) {
            stage_v_155 = (pub_r000777_0 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000777_0 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000777_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000777_17 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_156 = (pub_r000777_21 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000777_21 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000777_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_157 = (pub_r000777_9 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000777_9 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000777_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000777_9 & 1) != 0) {
        if ((sec_r000777_1 & 2) != 0) {
            stage_v_158 = (pub_r000777_8 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000777_8 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000777_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000777_6 & 2) != 0) {
            stage_v_159 = (pub_r000777_0 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000777_0 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000777_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000777_10 & 1) != 0) {
        if ((sec_r000777_6 & 2) != 0) {
            stage_v_160 = (pub_r000777_19 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000777_19 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000777_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000777_7 & 1) != 0) {
        if ((sec_r000777_13 & 2) != 0) {
            stage_v_161 = (pub_r000777_8 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000777_8 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000777_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_162 = (pub_r000777_4 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000777_4 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000777_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000777_6 & 2) != 0) {
            stage_v_163 = (pub_r000777_16 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000777_16 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000777_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000777_18 & 2) != 0) {
            stage_v_164 = (pub_r000777_17 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000777_17 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000777_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000777_10 & 2) != 0) {
            stage_v_165 = (pub_r000777_21 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000777_21 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000777_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((sec_r000777_3 & 1) != 0) {
        if ((sec_r000777_7 & 2) != 0) {
            stage_v_166 = (pub_r000777_2 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000777_2 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000777_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000777_11 & 1) != 0) {
        if ((sec_r000777_4 & 2) != 0) {
            stage_v_167 = (pub_r000777_7 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000777_7 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000777_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000777_9 & 2) != 0) {
            stage_v_168 = (pub_r000777_18 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000777_18 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000777_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((sec_r000777_7 & 1) != 0) {
        if ((sec_r000777_12 & 2) != 0) {
            stage_v_169 = (pub_r000777_9 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000777_9 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000777_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000777_8 & 2) != 0) {
            stage_v_170 = (pub_r000777_14 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000777_14 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000777_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((sec_r000777_9 & 1) != 0) {
        if ((sec_r000777_12 & 2) != 0) {
            stage_v_171 = (pub_r000777_8 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000777_8 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000777_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((sec_r000777_3 & 1) != 0) {
        if ((sec_r000777_7 & 2) != 0) {
            stage_v_172 = (pub_r000777_0 + 31) & 127;
        } else {
            stage_v_172 = (pub_r000777_0 + 13) & 127;
        }
    } else {
        stage_v_172 = (pub_r000777_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000777_17 & 2) != 0) {
            stage_v_173 = (pub_r000777_13 + 31) & 127;
        } else {
            stage_v_173 = (pub_r000777_13 + 13) & 127;
        }
    } else {
        stage_v_173 = (pub_r000777_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    if ((stage_v_163 & 1) != 0) {
        if ((sec_r000777_15 & 2) != 0) {
            stage_v_174 = (pub_r000777_21 + 31) & 127;
        } else {
            stage_v_174 = (pub_r000777_21 + 13) & 127;
        }
    } else {
        stage_v_174 = (pub_r000777_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r000777_11 & 2) != 0) {
            stage_v_175 = (pub_r000777_6 + 31) & 127;
        } else {
            stage_v_175 = (pub_r000777_6 + 13) & 127;
        }
    } else {
        stage_v_175 = (pub_r000777_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
