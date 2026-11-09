/*
 * Benchmark Program: R001950
 * Security Family: mixed_control_data
 * Generator Seed: 695013
 * High Inputs: 18 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001950_5013_0 {
    int account_id;
    int fee;
    short rate;
    unsigned char balance;
    int buffer[3];
};

struct CipherContext_R001950_5013_1 {
    short counter;
    short tag;
    short nonce;
    short flags;
    unsigned char round_key;
    int buffer[3];
};

struct Vector3D_R001950_5013_2 {
    int coord_z;
    short heading;
    short pitch;
    int buffer[3];
};

union RegisterBank_R001950_5013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001950_5013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_48 = (aux + st.buffer[1]) & 3;
    switch (accumulator_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_35 = local_arr[aux % 3];
    acc = (acc + margin_35 * 2) & 127;
    int tally_58 = 0;
    for (int k = 0; k < 2; k++) {
        tally_58 = (tally_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001950_5013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_61 = (aux + st.buffer[1]) & 3;
    switch (stride_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_61 = local_arr[aux % 3];
    acc = (acc + quotient_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_2(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_84 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_84 = (checksum_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_84) & 127;
    }
    int checksum_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_45 = local_arr[aux % 3];
    acc = (acc + mask_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001950_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int parity_67 = 0;
    for (int k = 0; k < 2; k++) {
        parity_67 = (parity_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_67) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_85 = local_arr[aux % 3];
    acc = (acc + mask_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001950_5013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001950_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int factor_34 = 0;
    for (int k = 0; k < 3; k++) {
        factor_34 = (factor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_34) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_71 = local_arr[aux % 3];
    acc = (acc + segment_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_5(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_69 > 19) {
        acc = (acc + anchor_69 * 2 + 5) & 127;
        aux ^= (anchor_69 & 15);
    } else {
        acc = (acc - anchor_69 + 11) & 127;
        aux += 3;
    }
    int threshold_59 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_59 = (threshold_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_59) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_86 = local_arr[aux % 3];
    acc = (acc + index_reg_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001950_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_76 = (aux + st.buffer[1]) & 3;
    switch (anchor_76) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_48 = 0;
    for (int k = 0; k < 3; k++) {
        window_48 = (window_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_48) & 127;
    }
    int metric_34 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_34 > 32) {
        acc = (acc + metric_34 * 2 + 5) & 127;
        aux ^= (metric_34 & 15);
    } else {
        acc = (acc - metric_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001950_5013_7(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001950_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_64 = (aux + st.buffer[1]) & 3;
    switch (threshold_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_49 = local_arr[aux % 3];
    acc = (acc + cursor_49 * 2) & 127;
    int accumulator_40 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_40 > 11) {
        acc = (acc + accumulator_40 * 2 + 5) & 127;
        aux ^= (accumulator_40 & 15);
    } else {
        acc = (acc - accumulator_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001950_5013_8(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int window_60 = local_arr[aux % 3];
    acc = (acc + window_60 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_15 = 0;
    for (int k = 0; k < 2; k++) {
        damping_15 = (damping_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_15) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001950_5013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_77 = (aux + st.buffer[1]) & 3;
    switch (index_reg_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_26 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_26 > 31) {
        acc = (acc + offset_26 * 2 + 5) & 127;
        aux ^= (offset_26 & 15);
    } else {
        acc = (acc - offset_26 + 11) & 127;
        aux += 3;
    }
    int scale_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001950_5013_10(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001950_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_18) & 63;
    acc ^= aux;
    int damping_74 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_74 > 26) {
        acc = (acc + damping_74 * 2 + 5) & 127;
        aux ^= (damping_74 & 15);
    } else {
        acc = (acc - damping_74 + 11) & 127;
        aux += 3;
    }
    int pivot_37 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_37 = (pivot_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_37) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_24 = local_arr[aux % 3];
    acc = (acc + pivot_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_11(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001950_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_79 = 0;
    for (int k = 0; k < 3; k++) {
        vector_79 = (vector_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_79) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_23 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_23 > 13) {
        acc = (acc + segment_23 * 2 + 5) & 127;
        aux ^= (segment_23 & 15);
    } else {
        acc = (acc - segment_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001950_5013_12(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001950_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int threshold_46 = local_arr[aux % 3];
    acc = (acc + threshold_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001950_5013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001950_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_65) & 63;
    acc ^= aux;
    int anchor_19 = (aux + st.buffer[1]) & 3;
    switch (anchor_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001950_0;
    int sec_r001950_1;
    int sec_r001950_2;
    int sec_r001950_3;
    int sec_r001950_4;
    int sec_r001950_5;
    int sec_r001950_6;
    int sec_r001950_7;
    int sec_r001950_8;
    int sec_r001950_9;
    int sec_r001950_10;
    int sec_r001950_11;
    int sec_r001950_12;
    int sec_r001950_13;
    int sec_r001950_14;
    int sec_r001950_15;
    int sec_r001950_16;
    int sec_r001950_17;
    int pub_r001950_0;
    int pub_r001950_1;
    int pub_r001950_2;
    int pub_r001950_3;
    int pub_r001950_4;
    int pub_r001950_5;
    int pub_r001950_6;
    int pub_r001950_7;
    int pub_r001950_8;
    int pub_r001950_9;
    int pub_r001950_10;
    int pub_r001950_11;
    int pub_r001950_12;
    int pub_r001950_13;
    int pub_r001950_14;
    int pub_r001950_15;
    int pub_r001950_16;
    int pub_r001950_17;
    int pub_r001950_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001950_0 >= -100 && pub_r001950_0 <= 100);
    __CPROVER_assume(pub_r001950_1 >= -100 && pub_r001950_1 <= 100);
    __CPROVER_assume(pub_r001950_2 >= -100 && pub_r001950_2 <= 100);
    __CPROVER_assume(pub_r001950_3 >= -100 && pub_r001950_3 <= 100);
    __CPROVER_assume(pub_r001950_4 >= -100 && pub_r001950_4 <= 100);
    __CPROVER_assume(pub_r001950_5 >= -100 && pub_r001950_5 <= 100);
    __CPROVER_assume(pub_r001950_6 >= -100 && pub_r001950_6 <= 100);
    __CPROVER_assume(pub_r001950_7 >= -100 && pub_r001950_7 <= 100);
    __CPROVER_assume(pub_r001950_8 >= -100 && pub_r001950_8 <= 100);
    __CPROVER_assume(pub_r001950_9 >= -100 && pub_r001950_9 <= 100);
    __CPROVER_assume(pub_r001950_10 >= -100 && pub_r001950_10 <= 100);
    __CPROVER_assume(pub_r001950_11 >= -100 && pub_r001950_11 <= 100);
    __CPROVER_assume(pub_r001950_12 >= -100 && pub_r001950_12 <= 100);
    __CPROVER_assume(pub_r001950_13 >= -100 && pub_r001950_13 <= 100);
    __CPROVER_assume(pub_r001950_14 >= -100 && pub_r001950_14 <= 100);
    __CPROVER_assume(pub_r001950_15 >= -100 && pub_r001950_15 <= 100);
    __CPROVER_assume(pub_r001950_16 >= -100 && pub_r001950_16 <= 100);
    __CPROVER_assume(pub_r001950_17 >= -100 && pub_r001950_17 <= 100);
    __CPROVER_assume(pub_r001950_18 >= -100 && pub_r001950_18 <= 100);
    __CPROVER_assume(sec_r001950_0 >= 0 && sec_r001950_0 <= 255);
    __CPROVER_assume(sec_r001950_1 >= 0 && sec_r001950_1 <= 255);
    __CPROVER_assume(sec_r001950_2 >= 0 && sec_r001950_2 <= 255);
    __CPROVER_assume(sec_r001950_3 >= 0 && sec_r001950_3 <= 255);
    __CPROVER_assume(sec_r001950_4 >= 0 && sec_r001950_4 <= 255);
    __CPROVER_assume(sec_r001950_5 >= 0 && sec_r001950_5 <= 255);
    __CPROVER_assume(sec_r001950_6 >= 0 && sec_r001950_6 <= 255);
    __CPROVER_assume(sec_r001950_7 >= 0 && sec_r001950_7 <= 255);
    __CPROVER_assume(sec_r001950_8 >= 0 && sec_r001950_8 <= 255);
    __CPROVER_assume(sec_r001950_9 >= 0 && sec_r001950_9 <= 255);
    __CPROVER_assume(sec_r001950_10 >= 0 && sec_r001950_10 <= 255);
    __CPROVER_assume(sec_r001950_11 >= 0 && sec_r001950_11 <= 255);
    __CPROVER_assume(sec_r001950_12 >= 0 && sec_r001950_12 <= 255);
    __CPROVER_assume(sec_r001950_13 >= 0 && sec_r001950_13 <= 255);
    __CPROVER_assume(sec_r001950_14 >= 0 && sec_r001950_14 <= 255);
    __CPROVER_assume(sec_r001950_15 >= 0 && sec_r001950_15 <= 255);
    __CPROVER_assume(sec_r001950_16 >= 0 && sec_r001950_16 <= 255);
    __CPROVER_assume(sec_r001950_17 >= 0 && sec_r001950_17 <= 255);

    struct Transaction_R001950_5013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001950_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001950_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001950_0 + 7) & 15;
    struct CipherContext_R001950_5013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001950_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001950_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001950_0 + 9) & 15;
    struct Vector3D_R001950_5013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001950_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001950_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001950_0 + 11) & 15;

    union RegisterBank_R001950_5013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001950_5013_0(sec_r001950_0, sec_r001950_1, pub_r001950_2, pub_r001950_3);
    int helper_flow_1 = fn_R001950_5013_1(sec_r001950_1, pub_r001950_2, pub_r001950_3, pub_r001950_4);
    int helper_flow_2 = fn_R001950_5013_2(sec_r001950_2, pub_r001950_3);
    int helper_flow_3 = fn_R001950_5013_3(sec_r001950_3, sec_r001950_4, pub_r001950_5, pub_r001950_6, pub_r001950_7);
    int helper_flow_4 = fn_R001950_5013_4(sec_r001950_4, sec_r001950_5, pub_r001950_6, pub_r001950_7);
    int helper_flow_5 = fn_R001950_5013_5(sec_r001950_5, pub_r001950_6, pub_r001950_7);
    int helper_flow_6 = fn_R001950_5013_6(sec_r001950_6, sec_r001950_7, pub_r001950_8, pub_r001950_9);
    int helper_flow_7 = fn_R001950_5013_7(sec_r001950_7, pub_r001950_8);
    int helper_flow_8 = fn_R001950_5013_8(sec_r001950_8, sec_r001950_9, pub_r001950_10);
    int helper_flow_9 = fn_R001950_5013_9(sec_r001950_9, sec_r001950_10, pub_r001950_11, pub_r001950_12);
    int helper_flow_10 = fn_R001950_5013_10(sec_r001950_10, sec_r001950_11, pub_r001950_12);
    int helper_flow_11 = fn_R001950_5013_11(sec_r001950_11, sec_r001950_12, pub_r001950_13);
    int helper_flow_12 = fn_R001950_5013_12(sec_r001950_12, sec_r001950_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_0 > 39) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_1 > 44) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_2 > 33) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_3 > 45) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001950_7 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_4 > 40) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_5 > 46) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001950_1 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_7 > 33) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001950_12 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_8 > 48) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001950_9 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_9 > 45) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001950_3 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001950_17 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_11 > 22) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001950_0 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_12 > 37) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001950_8 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_13 > 26) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001950_4 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_14 > 48) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001950_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001950_11 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001950_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001950_0 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_18 > 25) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001950_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_20 > 39) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_21 > 46) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_22 > 50) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_23 > 30) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001950_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001950_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_26 > 48) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001950_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001950_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_29 > 43) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001950_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001950_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_32 > 44) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001950_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_34 > 24) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001950_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001950_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_37 > 26) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001950_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001950_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_40 > 44) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001950_0 ^ 0x2A) * 2 + pub_r001950_12) & 127;
    if (stage_v_41 > 50) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001950_14 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_42 > 47) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001950_11 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_43 > 36) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001950_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_45 > 47) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_46 > 49) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_47 > 48) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_48 > 27) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001950_10 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_49 > 46) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001950_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001950_6 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_51 > 26) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_52 > 24) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_53 > 48) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_54 > 22) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001950_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001950_8 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_56 > 30) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_57 > 21) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_58 > 41) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_59 > 37) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_60 > 35) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001950_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_63 > 47) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_64 > 22) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_65 > 31) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001950_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_67 > 38) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_68 > 21) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_69 > 41) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_70 > 20) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_71 > 41) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_72 > 43) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_73 > 30) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001950_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_75 > 32) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001950_5 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_76 > 43) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001950_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001950_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001950_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001950_14 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_80 > 28) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_81 > 34) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_82 > 26) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_83 > 44) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001950_1 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_84 > 49) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_85 > 50) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001950_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_87 > 42) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_88 > 49) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_89 > 35) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001950_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_92 > 23) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_93 > 27) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_94 > 38) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_95 > 24) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001950_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_97 > 28) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001950_7 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_98 > 50) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001950_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001950_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_101 > 30) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001950_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001950_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_104 > 43) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001950_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001950_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001950_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001950_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001950_10 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_109 > 25) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_110 > 46) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_111 > 27) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_112 > 31) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001950_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_114 > 41) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_115 > 22) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_116 > 49) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_117 > 34) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_118 > 33) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001950_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001950_5 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_121 > 38) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001950_6 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_122 > 40) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001950_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_124 > 40) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_125 > 37) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001950_12 ^ 0x2A) * 2 + pub_r001950_0) & 127;
    if (stage_v_127 > 20) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_128 > 20) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001950_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_130 > 45) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_131 > 42) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_132 > 25) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001950_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_134 > 31) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_135 > 47) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_136 > 30) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_137 > 35) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_138 > 42) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001950_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_140 > 45) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_141 > 50) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_142 > 36) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_143 > 44) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001950_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001950_0 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_145 > 31) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001950_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_147 > 41) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_149 > 26) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_150 > 35) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_151 > 22) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_152 > 25) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001950_16 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_153 > 35) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_154 > 24) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001950_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_156 > 33) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_157 > 25) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_158 > 40) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_159 > 25) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_160 > 35) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_161 > 45) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_162 > 50) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_163 > 49) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_164 > 28) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_165 > 42) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_167 > 26) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_168 > 49) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_169 > 36) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001950_12) & 127;
    if (stage_v_170 > 30) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r001950_12 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_171 > 29) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001950_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_173 > 33) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_174 > 45) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_175 > 37) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001950_16 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_176 > 29) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_177 > 20) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001950_10 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_178 > 42) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_179 > 26) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_180 > 20) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001950_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_182 > 20) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_183 > 27) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_184 > 30) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_185 > 37) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001950_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_187 > 40) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_188 > 28) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001950_0) & 127;
    if (stage_v_189 > 43) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001950_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001950_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001950_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001950_12) & 127;
    if (stage_v_193 > 22) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r001950_12 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_194 > 37) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_195 > 49) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_196 > 32) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_197 > 28) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_198 > 22) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_200 > 32) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001950_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001950_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001950_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_204 > 22) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_205 > 35) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_206 > 50) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001950_0) & 127;
    if (stage_v_207 > 38) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001950_0) & 127;
    if (stage_v_208 > 50) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_209 > 28) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_210 > 21) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001950_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_212 > 20) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_213 > 50) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_214 > 35) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_215 > 35) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001950_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001950_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001950_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_219 > 31) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001950_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_221 > 26) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001950_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001950_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_224 > 48) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_225 > 33) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001950_6) & 127;
    if (stage_v_226 > 43) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_227 > 22) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_228 > 49) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001950_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001950_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_231 > 39) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_232 > 49) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001950_8) & 127;
    if (stage_v_233 > 27) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_234 > 45) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_234 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_235 > 50) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_236 > 46) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_237 > 32) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001950_17) & 127;
    if (stage_v_238 > 41) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r001950_13 ^ 0x2A) * 2 + pub_r001950_2) & 127;
    if (stage_v_239 > 41) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001950_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001950_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_242 > 38) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001950_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_166 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_244 > 40) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_245 > 26) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001950_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001950_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001950_0) & 127;
    if (stage_v_248 > 45) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001950_12) & 127;
    if (stage_v_249 > 43) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001950_1) & 127;
    if (stage_v_250 > 44) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001950_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_252 > 21) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001950_17 ^ 0x2A) * 2 + pub_r001950_9) & 127;
    if (stage_v_253 > 50) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001950_3) & 127;
    if (stage_v_254 > 45) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001950_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001950_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_257 > 32) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r001950_12 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_258 > 43) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001950_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r001950_16 ^ 0x2A) * 2 + pub_r001950_5) & 127;
    if (stage_v_260 > 45) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001950_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001950_18) & 127;
    if (stage_v_262 > 50) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001950_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001950_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001950_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001950_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_267 > 41) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001950_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_269 > 41) {
        out_sink = (out_sink + stage_v_269 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_269 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001950_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001950_4) & 127;
    if (stage_v_271 > 35) {
        out_sink = (out_sink + stage_v_271 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_271 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_272 > 32) {
        out_sink = (out_sink + stage_v_272 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_272 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_273 > 26) {
        out_sink = (out_sink + stage_v_273 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_273 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001950_11) & 127;
    if (stage_v_274 > 39) {
        out_sink = (out_sink + stage_v_274 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_274 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001950_15) & 127;
    if (stage_v_275 > 20) {
        out_sink = (out_sink + stage_v_275 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_275 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001950_16) & 127;
    if (stage_v_276 > 35) {
        out_sink = (out_sink + stage_v_276 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_276 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((sec_r001950_8 ^ 0x2A) * 2 + pub_r001950_14) & 127;
    if (stage_v_277 > 32) {
        out_sink = (out_sink + stage_v_277 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_277 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001950_13) & 127;
    if (stage_v_278 > 38) {
        out_sink = (out_sink + stage_v_278 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_278 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001950_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_214 ^ 0x2A) * 2 + pub_r001950_12) & 127;
    if (stage_v_280 > 47) {
        out_sink = (out_sink + stage_v_280 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_280 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001950_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001950_10) & 127;
    if (stage_v_282 > 41) {
        out_sink = (out_sink + stage_v_282 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_282 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001950_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001950_7) & 127;
    if (stage_v_284 > 20) {
        out_sink = (out_sink + stage_v_284 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_284 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_284) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
