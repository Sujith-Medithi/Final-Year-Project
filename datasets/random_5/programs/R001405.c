/*
 * Benchmark Program: R001405
 * Security Family: bitwise_flow
 * Generator Seed: 640513
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001405_513_0 {
    int norm_sq;
    int pitch;
    int coord_x;
    short coord_z;
    int buffer[3];
};

struct CipherContext_R001405_513_1 {
    int flags;
    int counter;
    unsigned char round_key;
    int buffer[3];
};

union PacketPayload_R001405_513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001405_513_0(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_46 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_46 > 37) {
        acc = (acc + weight_46 * 2 + 5) & 127;
        aux ^= (weight_46 & 15);
    } else {
        acc = (acc - weight_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_1(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int phase_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_82) & 63;
    acc ^= aux;
    int weight_19 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_19 > 26) {
        acc = (acc + weight_19 * 2 + 5) & 127;
        aux ^= (weight_19 & 15);
    } else {
        acc = (acc - weight_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_2(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_24 = 0;
    for (int k = 0; k < 3; k++) {
        factor_24 = (factor_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_24) & 127;
    }
    int vector_42 = (aux + st.buffer[1]) & 3;
    switch (vector_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_95 > 16) {
        acc = (acc + quantum_95 * 2 + 5) & 127;
        aux ^= (quantum_95 & 15);
    } else {
        acc = (acc - quantum_95 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001405_513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_34 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_34 > 24) {
        acc = (acc + bound_34 * 2 + 5) & 127;
        aux ^= (bound_34 & 15);
    } else {
        acc = (acc - bound_34 + 11) & 127;
        aux += 3;
    }
    int tracker_59 = (aux + st.buffer[1]) & 3;
    switch (tracker_59) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int pivot_45 = (aux + st.buffer[1]) & 3;
    switch (pivot_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_95 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_95 > 40) {
        acc = (acc + cursor_95 * 2 + 5) & 127;
        aux ^= (cursor_95 & 15);
    } else {
        acc = (acc - cursor_95 + 11) & 127;
        aux += 3;
    }
    int stride_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001405_513_5(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001405_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int index_reg_24 = local_arr[aux % 3];
    acc = (acc + index_reg_24 * 2) & 127;
    int segment_83 = 0;
    for (int k = 0; k < 2; k++) {
        segment_83 = (segment_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_83) & 127;
    }
    int quotient_72 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_72 > 49) {
        acc = (acc + quotient_72 * 2 + 5) & 127;
        aux ^= (quotient_72 & 15);
    } else {
        acc = (acc - quotient_72 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001405_513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001405_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_63) & 63;
    acc ^= aux;
    int phase_50 = 0;
    for (int k = 0; k < 2; k++) {
        phase_50 = (phase_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_50) & 127;
    }
    int phase_99 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_99 > 17) {
        acc = (acc + phase_99 * 2 + 5) & 127;
        aux ^= (phase_99 & 15);
    } else {
        acc = (acc - phase_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_7(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_31 = local_arr[aux % 3];
    acc = (acc + factor_31 * 2) & 127;
    int vector_18 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_18 > 27) {
        acc = (acc + vector_18 * 2 + 5) & 127;
        aux ^= (vector_18 & 15);
    } else {
        acc = (acc - vector_18 + 11) & 127;
        aux += 3;
    }
    int threshold_81 = (aux + st.buffer[1]) & 3;
    switch (threshold_81) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_8(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_45 = 0;
    for (int k = 0; k < 2; k++) {
        residue_45 = (residue_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_9(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_70 = local_arr[aux % 3];
    acc = (acc + weight_70 * 2) & 127;
    int tracker_93 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_93 = (tracker_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int threshold_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_20) & 63;
    acc ^= aux;
    int quotient_32 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_32 = (quotient_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_32) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_37 = local_arr[aux % 3];
    acc = (acc + mask_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001405_513_11(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001405_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_91 = (aux + st.buffer[1]) & 3;
    switch (tally_91) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_49 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_49 = (cursor_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_49) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_71 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_71 > 11) {
        acc = (acc + weight_71 * 2 + 5) & 127;
        aux ^= (weight_71 & 15);
    } else {
        acc = (acc - weight_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int anchor_61 = local_arr[aux % 3];
    acc = (acc + anchor_61 * 2) & 127;
    int mask_89 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_89 > 48) {
        acc = (acc + mask_89 * 2 + 5) & 127;
        aux ^= (mask_89 & 15);
    } else {
        acc = (acc - mask_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_27 = 0;
    for (int k = 0; k < 3; k++) {
        offset_27 = (offset_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_27) & 127;
    }
    int sample_75 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_75 > 17) {
        acc = (acc + sample_75 * 2 + 5) & 127;
        aux ^= (sample_75 & 15);
    } else {
        acc = (acc - sample_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001405_513_14(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001405_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_69 = local_arr[aux % 3];
    acc = (acc + weight_69 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001405_0;
    int sec_r001405_1;
    int sec_r001405_2;
    int sec_r001405_3;
    int sec_r001405_4;
    int sec_r001405_5;
    int sec_r001405_6;
    int sec_r001405_7;
    int sec_r001405_8;
    int sec_r001405_9;
    int sec_r001405_10;
    int sec_r001405_11;
    int sec_r001405_12;
    int sec_r001405_13;
    int sec_r001405_14;
    int sec_r001405_15;
    int sec_r001405_16;
    int sec_r001405_17;
    int sec_r001405_18;
    int sec_r001405_19;
    int sec_r001405_20;
    int sec_r001405_21;
    int sec_r001405_22;
    int pub_r001405_0;
    int pub_r001405_1;
    int pub_r001405_2;
    int pub_r001405_3;
    int pub_r001405_4;
    int pub_r001405_5;
    int pub_r001405_6;
    int pub_r001405_7;
    int pub_r001405_8;
    int pub_r001405_9;
    int pub_r001405_10;
    int pub_r001405_11;
    int pub_r001405_12;
    int pub_r001405_13;
    int pub_r001405_14;
    int pub_r001405_15;
    int pub_r001405_16;
    int pub_r001405_17;
    int pub_r001405_18;
    int pub_r001405_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001405_0 >= -100 && pub_r001405_0 <= 100);
    __CPROVER_assume(pub_r001405_1 >= -100 && pub_r001405_1 <= 100);
    __CPROVER_assume(pub_r001405_2 >= -100 && pub_r001405_2 <= 100);
    __CPROVER_assume(pub_r001405_3 >= -100 && pub_r001405_3 <= 100);
    __CPROVER_assume(pub_r001405_4 >= -100 && pub_r001405_4 <= 100);
    __CPROVER_assume(pub_r001405_5 >= -100 && pub_r001405_5 <= 100);
    __CPROVER_assume(pub_r001405_6 >= -100 && pub_r001405_6 <= 100);
    __CPROVER_assume(pub_r001405_7 >= -100 && pub_r001405_7 <= 100);
    __CPROVER_assume(pub_r001405_8 >= -100 && pub_r001405_8 <= 100);
    __CPROVER_assume(pub_r001405_9 >= -100 && pub_r001405_9 <= 100);
    __CPROVER_assume(pub_r001405_10 >= -100 && pub_r001405_10 <= 100);
    __CPROVER_assume(pub_r001405_11 >= -100 && pub_r001405_11 <= 100);
    __CPROVER_assume(pub_r001405_12 >= -100 && pub_r001405_12 <= 100);
    __CPROVER_assume(pub_r001405_13 >= -100 && pub_r001405_13 <= 100);
    __CPROVER_assume(pub_r001405_14 >= -100 && pub_r001405_14 <= 100);
    __CPROVER_assume(pub_r001405_15 >= -100 && pub_r001405_15 <= 100);
    __CPROVER_assume(pub_r001405_16 >= -100 && pub_r001405_16 <= 100);
    __CPROVER_assume(pub_r001405_17 >= -100 && pub_r001405_17 <= 100);
    __CPROVER_assume(pub_r001405_18 >= -100 && pub_r001405_18 <= 100);
    __CPROVER_assume(pub_r001405_19 >= -100 && pub_r001405_19 <= 100);
    __CPROVER_assume(sec_r001405_0 >= 0 && sec_r001405_0 <= 255);
    __CPROVER_assume(sec_r001405_1 >= 0 && sec_r001405_1 <= 255);
    __CPROVER_assume(sec_r001405_2 >= 0 && sec_r001405_2 <= 255);
    __CPROVER_assume(sec_r001405_3 >= 0 && sec_r001405_3 <= 255);
    __CPROVER_assume(sec_r001405_4 >= 0 && sec_r001405_4 <= 255);
    __CPROVER_assume(sec_r001405_5 >= 0 && sec_r001405_5 <= 255);
    __CPROVER_assume(sec_r001405_6 >= 0 && sec_r001405_6 <= 255);
    __CPROVER_assume(sec_r001405_7 >= 0 && sec_r001405_7 <= 255);
    __CPROVER_assume(sec_r001405_8 >= 0 && sec_r001405_8 <= 255);
    __CPROVER_assume(sec_r001405_9 >= 0 && sec_r001405_9 <= 255);
    __CPROVER_assume(sec_r001405_10 >= 0 && sec_r001405_10 <= 255);
    __CPROVER_assume(sec_r001405_11 >= 0 && sec_r001405_11 <= 255);
    __CPROVER_assume(sec_r001405_12 >= 0 && sec_r001405_12 <= 255);
    __CPROVER_assume(sec_r001405_13 >= 0 && sec_r001405_13 <= 255);
    __CPROVER_assume(sec_r001405_14 >= 0 && sec_r001405_14 <= 255);
    __CPROVER_assume(sec_r001405_15 >= 0 && sec_r001405_15 <= 255);
    __CPROVER_assume(sec_r001405_16 >= 0 && sec_r001405_16 <= 255);
    __CPROVER_assume(sec_r001405_17 >= 0 && sec_r001405_17 <= 255);
    __CPROVER_assume(sec_r001405_18 >= 0 && sec_r001405_18 <= 255);
    __CPROVER_assume(sec_r001405_19 >= 0 && sec_r001405_19 <= 255);
    __CPROVER_assume(sec_r001405_20 >= 0 && sec_r001405_20 <= 255);
    __CPROVER_assume(sec_r001405_21 >= 0 && sec_r001405_21 <= 255);
    __CPROVER_assume(sec_r001405_22 >= 0 && sec_r001405_22 <= 255);

    struct Vector3D_R001405_513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001405_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001405_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001405_0 + 7) & 15;
    struct CipherContext_R001405_513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001405_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001405_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001405_0 + 9) & 15;

    union PacketPayload_R001405_513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001405_513_0(sec_r001405_0, sec_r001405_1);
    int helper_flow_1 = fn_R001405_513_1(sec_r001405_1, sec_r001405_2, pub_r001405_3);
    int helper_flow_2 = fn_R001405_513_2(sec_r001405_2, pub_r001405_3, pub_r001405_4);
    int helper_flow_3 = fn_R001405_513_3(sec_r001405_3, sec_r001405_4, pub_r001405_5, pub_r001405_6);
    int helper_flow_4 = fn_R001405_513_4(sec_r001405_4, pub_r001405_5, pub_r001405_6, pub_r001405_7, pub_r001405_8);
    int helper_flow_5 = fn_R001405_513_5(sec_r001405_5, sec_r001405_6, pub_r001405_7);
    int helper_flow_6 = fn_R001405_513_6(sec_r001405_6, sec_r001405_7, pub_r001405_8, pub_r001405_9, pub_r001405_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001405_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001405_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001405_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001405_21 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001405_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001405_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001405_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_3 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001405_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001405_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001405_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001405_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001405_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_7 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001405_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001405_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001405_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001405_21 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001405_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_17 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_19 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_0 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001405_14 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001405_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001405_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001405_2 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001405_5 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_19 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_5 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001405_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001405_10 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001405_9 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001405_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_2 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001405_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001405_4 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001405_15 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001405_4 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_0 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001405_21 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001405_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001405_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001405_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001405_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_3 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_27 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001405_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001405_3 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001405_20 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001405_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001405_5 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001405_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001405_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001405_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001405_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001405_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_22 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001405_13 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001405_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001405_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001405_16 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001405_10 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_50 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001405_2 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001405_16 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001405_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_5 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_5 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001405_9 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001405_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001405_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_0 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_39 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001405_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001405_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001405_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_72 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001405_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001405_18 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001405_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_33 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001405_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001405_2 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_1 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_30 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_84 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001405_7 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001405_17 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001405_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001405_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_71 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_3 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_44 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001405_12 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_13 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_6 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001405_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001405_7 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001405_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001405_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001405_14 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001405_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001405_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_39 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001405_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001405_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001405_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001405_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001405_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_71 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_71 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_17 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001405_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_1 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_36 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001405_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_91 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_17 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_39 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001405_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_17 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001405_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_33 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001405_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001405_3 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_85 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001405_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001405_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001405_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001405_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001405_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001405_15 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001405_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_31 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001405_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001405_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001405_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_109 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001405_4 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_117 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001405_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001405_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_91 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_35 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((helper_flow_6 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001405_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001405_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001405_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001405_17 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001405_13 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_149 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_93 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001405_7 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_30 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001405_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_60 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001405_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_3 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_28 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_63 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_157 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001405_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001405_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001405_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_27 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001405_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001405_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001405_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001405_21 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001405_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001405_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((helper_flow_5 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001405_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_150 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001405_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_114 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_137 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_113 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_155 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_50 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_76 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_160 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001405_10 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001405_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001405_19 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_180 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001405_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_148 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_20 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_176 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001405_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001405_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_150 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_110 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001405_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001405_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001405_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_64 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001405_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001405_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001405_5 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_124 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_44 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001405_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_111 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001405_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001405_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_83 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001405_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_7 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_157 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_120 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_204 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001405_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001405_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_56 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_3 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001405_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_68 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_216 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_60 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001405_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001405_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_176 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001405_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_93 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001405_21 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r001405_21 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001405_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_189 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_27 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_173 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_66 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_30 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001405_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_50 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001405_13 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001405_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_182 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001405_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_103 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001405_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001405_2 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001405_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_240 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((sec_r001405_11 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_232 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_76 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001405_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001405_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_155 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_226 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001405_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001405_12 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r001405_17 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001405_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_150 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_47 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001405_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001405_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001405_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_219 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_3 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001405_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_39 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_60 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_179 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_120 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001405_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_173 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001405_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_229 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((sec_r001405_11 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001405_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_113 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_271 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001405_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001405_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_30 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_109 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001405_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_246 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001405_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_257 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001405_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_215 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_13 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001405_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001405_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_38 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_111 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r001405_14 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001405_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001405_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001405_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_25 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001405_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001405_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((sec_r001405_13 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001405_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001405_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_111 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_157 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001405_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_220 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001405_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((helper_flow_4 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001405_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001405_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_264 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_246 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001405_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_30 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001405_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_97 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_193 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001405_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001405_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001405_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_271 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_142 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((helper_flow_6 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001405_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001405_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001405_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001405_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_64 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001405_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_87 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_226 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001405_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001405_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_274 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001405_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_264 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_320 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001405_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001405_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001405_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001405_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_281 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001405_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_71 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_279 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001405_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_176 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001405_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001405_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((sec_r001405_6 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r001405_21 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001405_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_76 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001405_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_20 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001405_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001405_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001405_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_148 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001405_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_329 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((sec_r001405_16 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_153 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001405_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_21 << 1) ^ (pub_r001405_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001405_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001405_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_306 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((helper_flow_2 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_152 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((helper_flow_3 << 1) ^ (pub_r001405_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001405_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001405_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001405_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((sec_r001405_17 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((sec_r001405_20 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001405_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001405_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_218 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001405_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001405_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001405_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001405_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001405_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001405_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_109 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001405_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001405_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_369 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001405_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001405_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_229 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_138 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_60 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001405_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001405_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001405_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001405_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001405_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_264 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_204 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001405_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_20 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001405_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001405_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_377 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001405_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_399 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001405_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_310 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_103 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001405_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001405_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001405_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001405_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_328 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_76 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001405_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_125 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_204 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_408 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001405_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_209 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001405_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_368 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_401 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_157 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_266 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_229 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001405_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_72 << 1) ^ (pub_r001405_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_315 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001405_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001405_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_357 << 1) ^ (pub_r001405_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001405_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_160 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_226 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_50 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_345 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_438 + 1) & 15;
    out_sink ^= (stage_v_438 & 63);

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_223 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001405_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001405_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001405_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_181 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_343 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001405_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001405_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_71 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_44 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_238 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_235 << 1) ^ (pub_r001405_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((helper_flow_0 << 1) ^ (pub_r001405_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001405_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_262 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_453 + 1) & 15;
    out_sink ^= (stage_v_453 & 63);

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001405_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_401 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001405_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_171 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_457 + 1) & 15;
    out_sink ^= (stage_v_457 & 63);

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001405_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((sec_r001405_5 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_398 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001405_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_436 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001405_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((helper_flow_0 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_464 + 1) & 15;
    out_sink ^= (stage_v_464 & 63);

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_334 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_465 + 1) & 15;
    out_sink ^= (stage_v_465 & 63);

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001405_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_232 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001405_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001405_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((stage_v_285 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_470 + 1) & 15;
    out_sink ^= (stage_v_470 & 63);

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001405_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_351 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_438 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_473 + 1) & 15;
    out_sink ^= (stage_v_473 & 63);

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001405_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((sec_r001405_4 << 1) ^ (pub_r001405_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_475 + 1) & 15;
    out_sink ^= (stage_v_475 & 63);

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = ((stage_v_373 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_476 + 1) & 15;
    out_sink ^= (stage_v_476 & 63);

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001405_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001405_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001405_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_464 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_480 + 1) & 15;
    out_sink ^= (stage_v_480 & 63);

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = ((sec_r001405_13 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_481 + 1) & 15;
    out_sink ^= (stage_v_481 & 63);

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_93 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_482 + 1) & 15;
    out_sink ^= (stage_v_482 & 63);

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_219 << 1) ^ (pub_r001405_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_483 + 1) & 15;
    out_sink ^= (stage_v_483 & 63);

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_187 << 1) ^ (pub_r001405_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_484 + 1) & 15;
    out_sink ^= (stage_v_484 & 63);

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001405_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = ((stage_v_345 << 1) ^ (pub_r001405_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_486 + 1) & 15;
    out_sink ^= (stage_v_486 & 63);

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_406 << 1) ^ (pub_r001405_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_487 + 1) & 15;
    out_sink ^= (stage_v_487 & 63);

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_281 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_488 + 1) & 15;
    out_sink ^= (stage_v_488 & 63);

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001405_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = ((stage_v_178 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_490 + 1) & 15;
    out_sink ^= (stage_v_490 & 63);

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001405_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = ((stage_v_451 << 1) ^ (pub_r001405_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_492 + 1) & 15;
    out_sink ^= (stage_v_492 & 63);

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_275 << 1) ^ (pub_r001405_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_493 + 1) & 15;
    out_sink ^= (stage_v_493 & 63);

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_443 << 1) ^ (pub_r001405_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_494 + 1) & 15;
    out_sink ^= (stage_v_494 & 63);

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001405_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = ((stage_v_66 << 1) ^ (pub_r001405_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_496 + 1) & 15;
    out_sink ^= (stage_v_496 & 63);

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001405_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001405_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001405_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = ((stage_v_326 << 1) ^ (pub_r001405_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_500 + 1) & 15;
    out_sink ^= (stage_v_500 & 63);

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001405_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001405_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = ((stage_v_242 << 1) ^ (pub_r001405_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_503 + 1) & 15;
    out_sink ^= (stage_v_503 & 63);

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001405_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001405_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001405_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_149 << 1) ^ (pub_r001405_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_507 + 1) & 15;
    out_sink ^= (stage_v_507 & 63);

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_219 << 1) ^ (pub_r001405_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_508 + 1) & 15;
    out_sink ^= (stage_v_508 & 63);

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001405_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001405_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = ((stage_v_175 << 1) ^ (pub_r001405_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_511 + 1) & 15;
    out_sink ^= (stage_v_511 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
