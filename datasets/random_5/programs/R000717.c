/*
 * Benchmark Program: R000717
 * Security Family: nested_implicit_flow
 * Generator Seed: 571713
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000717_1713_0 {
    short coord_z;
    unsigned char coord_x;
    short norm_sq;
    int buffer[3];
};

struct CipherContext_R000717_1713_1 {
    int round_key;
    int tag;
    int nonce;
    short counter;
    unsigned char iv;
    int flags;
    int buffer[3];
};

struct FilterState_R000717_1713_2 {
    int damping;
    unsigned char prev_out;
    short cutoff;
    int buffer[3];
};

union RegisterBank_R000717_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000717_1713_0(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_23 = (aux + st.buffer[1]) & 3;
    switch (residue_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_83) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_71 = local_arr[aux % 3];
    acc = (acc + bound_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_41 = local_arr[aux % 3];
    acc = (acc + delta_41 * 2) & 127;
    int coefficient_96 = (aux + st.buffer[1]) & 3;
    switch (coefficient_96) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_90 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_90 > 25) {
        acc = (acc + sample_90 * 2 + 5) & 127;
        aux ^= (sample_90 & 15);
    } else {
        acc = (acc - sample_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_3(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_92 = (aux + st.buffer[1]) & 3;
    switch (sample_92) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_51 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_51 > 21) {
        acc = (acc + parity_51 * 2 + 5) & 127;
        aux ^= (parity_51 & 15);
    } else {
        acc = (acc - parity_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_59 = (aux + st.buffer[1]) & 3;
    switch (margin_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_75 = local_arr[aux % 3];
    acc = (acc + quotient_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_5(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_87 = local_arr[aux % 3];
    acc = (acc + margin_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_95 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_95 > 27) {
        acc = (acc + segment_95 * 2 + 5) & 127;
        aux ^= (segment_95 & 15);
    } else {
        acc = (acc - segment_95 + 11) & 127;
        aux += 3;
    }
    int quotient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_42 = (aux + st.buffer[1]) & 3;
    switch (accumulator_42) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_15 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_15 > 15) {
        acc = (acc + delta_15 * 2 + 5) & 127;
        aux ^= (delta_15 & 15);
    } else {
        acc = (acc - delta_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_25 = local_arr[aux % 3];
    acc = (acc + sample_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_8(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tally_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_16) & 63;
    acc ^= aux;
    int offset_97 = (aux + st.buffer[1]) & 3;
    switch (offset_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_10 > 46) {
        acc = (acc + cursor_10 * 2 + 5) & 127;
        aux ^= (cursor_10 & 15);
    } else {
        acc = (acc - cursor_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_44 = local_arr[aux % 3];
    acc = (acc + scale_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int metric_20 = local_arr[aux % 3];
    acc = (acc + metric_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_70 = (aux + st.buffer[1]) & 3;
    switch (checksum_70) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_10(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_96 = (aux + st.buffer[1]) & 3;
    switch (segment_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_57 = local_arr[aux % 3];
    acc = (acc + coefficient_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000717_1713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_79 = (aux + st.buffer[1]) & 3;
    switch (quotient_79) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_34 = local_arr[aux % 3];
    acc = (acc + margin_34 * 2) & 127;
    int checksum_64 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_64 > 16) {
        acc = (acc + checksum_64 * 2 + 5) & 127;
        aux ^= (checksum_64 & 15);
    } else {
        acc = (acc - checksum_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_12(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int residue_26 = local_arr[aux % 3];
    acc = (acc + residue_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_94 = (aux + st.buffer[1]) & 3;
    switch (accumulator_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_13(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int scale_36 = local_arr[aux % 3];
    acc = (acc + scale_36 * 2) & 127;
    int factor_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_33) & 63;
    acc ^= aux;
    int tracker_29 = (aux + st.buffer[1]) & 3;
    switch (tracker_29) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000717_1713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_91) & 63;
    acc ^= aux;
    int pivot_13 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_13 > 41) {
        acc = (acc + pivot_13 * 2 + 5) & 127;
        aux ^= (pivot_13 & 15);
    } else {
        acc = (acc - pivot_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000717_0;
    int sec_r000717_1;
    int sec_r000717_2;
    int sec_r000717_3;
    int sec_r000717_4;
    int sec_r000717_5;
    int sec_r000717_6;
    int sec_r000717_7;
    int sec_r000717_8;
    int sec_r000717_9;
    int sec_r000717_10;
    int sec_r000717_11;
    int sec_r000717_12;
    int sec_r000717_13;
    int sec_r000717_14;
    int sec_r000717_15;
    int sec_r000717_16;
    int sec_r000717_17;
    int sec_r000717_18;
    int pub_r000717_0;
    int pub_r000717_1;
    int pub_r000717_2;
    int pub_r000717_3;
    int pub_r000717_4;
    int pub_r000717_5;
    int pub_r000717_6;
    int pub_r000717_7;
    int pub_r000717_8;
    int pub_r000717_9;
    int pub_r000717_10;
    int pub_r000717_11;
    int pub_r000717_12;
    int pub_r000717_13;
    int pub_r000717_14;
    int pub_r000717_15;
    int pub_r000717_16;
    int pub_r000717_17;
    int pub_r000717_18;
    int pub_r000717_19;
    int pub_r000717_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000717_0 >= -100 && pub_r000717_0 <= 100);
    __CPROVER_assume(pub_r000717_1 >= -100 && pub_r000717_1 <= 100);
    __CPROVER_assume(pub_r000717_2 >= -100 && pub_r000717_2 <= 100);
    __CPROVER_assume(pub_r000717_3 >= -100 && pub_r000717_3 <= 100);
    __CPROVER_assume(pub_r000717_4 >= -100 && pub_r000717_4 <= 100);
    __CPROVER_assume(pub_r000717_5 >= -100 && pub_r000717_5 <= 100);
    __CPROVER_assume(pub_r000717_6 >= -100 && pub_r000717_6 <= 100);
    __CPROVER_assume(pub_r000717_7 >= -100 && pub_r000717_7 <= 100);
    __CPROVER_assume(pub_r000717_8 >= -100 && pub_r000717_8 <= 100);
    __CPROVER_assume(pub_r000717_9 >= -100 && pub_r000717_9 <= 100);
    __CPROVER_assume(pub_r000717_10 >= -100 && pub_r000717_10 <= 100);
    __CPROVER_assume(pub_r000717_11 >= -100 && pub_r000717_11 <= 100);
    __CPROVER_assume(pub_r000717_12 >= -100 && pub_r000717_12 <= 100);
    __CPROVER_assume(pub_r000717_13 >= -100 && pub_r000717_13 <= 100);
    __CPROVER_assume(pub_r000717_14 >= -100 && pub_r000717_14 <= 100);
    __CPROVER_assume(pub_r000717_15 >= -100 && pub_r000717_15 <= 100);
    __CPROVER_assume(pub_r000717_16 >= -100 && pub_r000717_16 <= 100);
    __CPROVER_assume(pub_r000717_17 >= -100 && pub_r000717_17 <= 100);
    __CPROVER_assume(pub_r000717_18 >= -100 && pub_r000717_18 <= 100);
    __CPROVER_assume(pub_r000717_19 >= -100 && pub_r000717_19 <= 100);
    __CPROVER_assume(pub_r000717_20 >= -100 && pub_r000717_20 <= 100);
    __CPROVER_assume(sec_r000717_0 >= 0 && sec_r000717_0 <= 255);
    __CPROVER_assume(sec_r000717_1 >= 0 && sec_r000717_1 <= 255);
    __CPROVER_assume(sec_r000717_2 >= 0 && sec_r000717_2 <= 255);
    __CPROVER_assume(sec_r000717_3 >= 0 && sec_r000717_3 <= 255);
    __CPROVER_assume(sec_r000717_4 >= 0 && sec_r000717_4 <= 255);
    __CPROVER_assume(sec_r000717_5 >= 0 && sec_r000717_5 <= 255);
    __CPROVER_assume(sec_r000717_6 >= 0 && sec_r000717_6 <= 255);
    __CPROVER_assume(sec_r000717_7 >= 0 && sec_r000717_7 <= 255);
    __CPROVER_assume(sec_r000717_8 >= 0 && sec_r000717_8 <= 255);
    __CPROVER_assume(sec_r000717_9 >= 0 && sec_r000717_9 <= 255);
    __CPROVER_assume(sec_r000717_10 >= 0 && sec_r000717_10 <= 255);
    __CPROVER_assume(sec_r000717_11 >= 0 && sec_r000717_11 <= 255);
    __CPROVER_assume(sec_r000717_12 >= 0 && sec_r000717_12 <= 255);
    __CPROVER_assume(sec_r000717_13 >= 0 && sec_r000717_13 <= 255);
    __CPROVER_assume(sec_r000717_14 >= 0 && sec_r000717_14 <= 255);
    __CPROVER_assume(sec_r000717_15 >= 0 && sec_r000717_15 <= 255);
    __CPROVER_assume(sec_r000717_16 >= 0 && sec_r000717_16 <= 255);
    __CPROVER_assume(sec_r000717_17 >= 0 && sec_r000717_17 <= 255);
    __CPROVER_assume(sec_r000717_18 >= 0 && sec_r000717_18 <= 255);

    struct Vector3D_R000717_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000717_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000717_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000717_0 + 7) & 15;
    struct CipherContext_R000717_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000717_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000717_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000717_0 + 9) & 15;
    struct FilterState_R000717_1713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000717_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000717_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000717_0 + 11) & 15;

    union RegisterBank_R000717_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 29) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 44) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 26) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 41) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 28) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 43) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 36) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 51) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 31) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 46) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 17) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 32) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 24) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 39) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 12) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 27) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

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
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 30) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 45) {
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
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000717_2 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_51 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000717_1 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_52 = (pub_r000717_11 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000717_11 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000717_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_53 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_54 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_55 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_56 = (pub_r000717_4 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000717_4 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000717_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_57 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000717_1 & 2) != 0) {
            stage_v_58 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000717_9 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_59 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000717_0 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_60 = (pub_r000717_16 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000717_16 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000717_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000717_12 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_61 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000717_6 & 2) != 0) {
            stage_v_62 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_63 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_64 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_65 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_66 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000717_2 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_67 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_68 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000717_18 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_69 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000717_13 & 2) != 0) {
            stage_v_70 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_71 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000717_14 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_72 = (pub_r000717_10 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000717_10 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000717_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000717_18 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_73 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_74 = (pub_r000717_4 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000717_4 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000717_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000717_14 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_75 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_76 = (pub_r000717_10 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000717_10 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000717_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000717_8 & 2) != 0) {
            stage_v_77 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000717_12 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_78 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000717_11 & 2) != 0) {
            stage_v_79 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000717_7 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_80 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_81 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_82 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_83 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000717_4 & 1) != 0) {
        if ((sec_r000717_13 & 2) != 0) {
            stage_v_84 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_85 = (pub_r000717_16 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000717_16 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000717_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_86 = (pub_r000717_15 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000717_15 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000717_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_87 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000717_6 & 2) != 0) {
            stage_v_88 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_89 = (pub_r000717_16 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000717_16 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000717_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000717_11 & 2) != 0) {
            stage_v_90 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000717_2 & 2) != 0) {
            stage_v_91 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000717_3 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_92 = (pub_r000717_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000717_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000717_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000717_8 & 1) != 0) {
        if ((sec_r000717_7 & 2) != 0) {
            stage_v_93 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000717_4 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_94 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000717_9 & 1) != 0) {
        if ((sec_r000717_6 & 2) != 0) {
            stage_v_95 = (pub_r000717_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000717_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000717_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000717_14 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_96 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_97 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000717_5 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_98 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000717_18 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_99 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000717_4 & 1) != 0) {
        if ((sec_r000717_13 & 2) != 0) {
            stage_v_100 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_101 = (pub_r000717_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000717_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000717_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000717_10 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_102 = (pub_r000717_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000717_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000717_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_103 = (pub_r000717_10 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000717_10 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000717_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000717_3 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_104 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_105 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_106 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000717_4 & 1) != 0) {
        if ((sec_r000717_11 & 2) != 0) {
            stage_v_107 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_108 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_109 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000717_17 & 1) != 0) {
        if ((sec_r000717_7 & 2) != 0) {
            stage_v_110 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000717_5 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_111 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_112 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_113 = (pub_r000717_15 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000717_15 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000717_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_114 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000717_2 & 2) != 0) {
            stage_v_115 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000717_2 & 1) != 0) {
        if ((sec_r000717_13 & 2) != 0) {
            stage_v_116 = (pub_r000717_7 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000717_7 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000717_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000717_10 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_117 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_118 = (pub_r000717_3 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000717_3 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000717_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000717_1 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_119 = (pub_r000717_4 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000717_4 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000717_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000717_7 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_120 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000717_13 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_121 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_122 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_123 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000717_2 & 2) != 0) {
            stage_v_124 = (pub_r000717_7 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000717_7 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000717_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_125 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_126 = (pub_r000717_18 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000717_18 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000717_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_127 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_128 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_129 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000717_13 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_130 = (pub_r000717_11 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000717_11 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000717_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000717_12 & 2) != 0) {
            stage_v_131 = (pub_r000717_18 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000717_18 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000717_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000717_6 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_132 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000717_12 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_133 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000717_7 & 2) != 0) {
            stage_v_134 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000717_15 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_135 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_136 = (pub_r000717_16 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000717_16 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000717_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000717_2 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_137 = (pub_r000717_18 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000717_18 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000717_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_138 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000717_9 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_139 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000717_11 & 2) != 0) {
            stage_v_140 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_141 = (pub_r000717_11 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000717_11 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000717_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000717_5 & 2) != 0) {
            stage_v_142 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_143 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000717_17 & 2) != 0) {
            stage_v_144 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_145 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000717_8 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_146 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000717_12 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_147 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_148 = (pub_r000717_0 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000717_0 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000717_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000717_0 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_149 = (pub_r000717_13 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000717_13 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000717_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_150 = (pub_r000717_6 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000717_6 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000717_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000717_6 & 2) != 0) {
            stage_v_151 = (pub_r000717_8 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000717_8 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000717_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000717_5 & 1) != 0) {
        if ((sec_r000717_3 & 2) != 0) {
            stage_v_152 = (pub_r000717_15 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000717_15 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000717_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000717_8 & 2) != 0) {
            stage_v_153 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000717_10 & 2) != 0) {
            stage_v_154 = (pub_r000717_11 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000717_11 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000717_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000717_18 & 2) != 0) {
            stage_v_155 = (pub_r000717_14 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000717_14 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000717_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_156 = (pub_r000717_16 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000717_16 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000717_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000717_16 & 2) != 0) {
            stage_v_157 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000717_16 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_158 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r000717_8 & 2) != 0) {
            stage_v_159 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000717_0 & 2) != 0) {
            stage_v_160 = (pub_r000717_2 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000717_2 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000717_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000717_8 & 2) != 0) {
            stage_v_161 = (pub_r000717_19 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000717_19 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000717_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000717_1 & 2) != 0) {
            stage_v_162 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000717_9 & 2) != 0) {
            stage_v_163 = (pub_r000717_1 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000717_1 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000717_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000717_18 & 1) != 0) {
        if ((sec_r000717_8 & 2) != 0) {
            stage_v_164 = (pub_r000717_12 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000717_12 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000717_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000717_2 & 2) != 0) {
            stage_v_165 = (pub_r000717_9 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000717_9 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000717_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r000717_15 & 2) != 0) {
            stage_v_166 = (pub_r000717_5 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000717_5 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000717_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_167 = (pub_r000717_20 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000717_20 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000717_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_167 & 1) != 0) {
        if ((sec_r000717_13 & 2) != 0) {
            stage_v_168 = (pub_r000717_11 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000717_11 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000717_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000717_4 & 2) != 0) {
            stage_v_169 = (pub_r000717_20 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000717_20 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000717_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000717_14 & 2) != 0) {
            stage_v_170 = (pub_r000717_17 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000717_17 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000717_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
