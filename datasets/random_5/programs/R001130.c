/*
 * Benchmark Program: R001130
 * Security Family: mixed_control_data
 * Generator Seed: 613013
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001130_3013_0 {
    int determinant;
    int scale;
    unsigned char stride;
    int buffer[3];
};

struct FilterState_R001130_3013_1 {
    unsigned char gain_db;
    int damping;
    short prev_out;
    short cutoff;
    int buffer[3];
};

struct Transaction_R001130_3013_2 {
    int rate;
    unsigned char fee;
    short account_id;
    int status;
    int buffer[3];
};

union PacketPayload_R001130_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001130_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001130_3013_0(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int stride_85 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_85 > 37) {
        acc = (acc + stride_85 * 2 + 5) & 127;
        aux ^= (stride_85 & 15);
    } else {
        acc = (acc - stride_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_25 = local_arr[aux % 3];
    acc = (acc + scale_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001130_3013_1(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001130_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_18 = (aux + st.buffer[1]) & 3;
    switch (quantum_18) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_57 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_57 = (accumulator_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_57) & 127;
    }
    int coefficient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001130_3013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001130_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int quantum_11 = local_arr[aux % 3];
    acc = (acc + quantum_11 * 2) & 127;
    int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_41 = (aux + st.buffer[1]) & 3;
    switch (window_41) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001130_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_82 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_82 > 34) {
        acc = (acc + accumulator_82 * 2 + 5) & 127;
        aux ^= (accumulator_82 & 15);
    } else {
        acc = (acc - accumulator_82 + 11) & 127;
        aux += 3;
    }
    int mask_48 = (aux + st.buffer[1]) & 3;
    switch (mask_48) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_68 = local_arr[aux % 3];
    acc = (acc + segment_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001130_3013_4(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int cursor_30 = local_arr[aux % 3];
    acc = (acc + cursor_30 * 2) & 127;
    int residue_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_41) & 63;
    acc ^= aux;
    int coefficient_69 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_69 > 29) {
        acc = (acc + coefficient_69 * 2 + 5) & 127;
        aux ^= (coefficient_69 & 15);
    } else {
        acc = (acc - coefficient_69 + 11) & 127;
        aux += 3;
    }
    int vector_19 = (aux + st.buffer[1]) & 3;
    switch (vector_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001130_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_52 = 0;
    for (int k = 0; k < 2; k++) {
        offset_52 = (offset_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_89 = 0;
    for (int k = 0; k < 3; k++) {
        metric_89 = (metric_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_89) & 127;
    }
    int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001130_3013_7(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001130_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int checksum_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_64) & 63;
    acc ^= aux;
    int tracker_76 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_76 > 47) {
        acc = (acc + tracker_76 * 2 + 5) & 127;
        aux ^= (tracker_76 & 15);
    } else {
        acc = (acc - tracker_76 + 11) & 127;
        aux += 3;
    }
    int pivot_17 = (aux + st.buffer[1]) & 3;
    switch (pivot_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_8(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int vector_49 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_49 > 44) {
        acc = (acc + vector_49 * 2 + 5) & 127;
        aux ^= (vector_49 & 15);
    } else {
        acc = (acc - vector_49 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_35 = local_arr[aux % 3];
    acc = (acc + offset_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001130_3013_9(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001130_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_23 = (aux + st.buffer[1]) & 3;
    switch (checksum_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_33 = 0;
    for (int k = 0; k < 2; k++) {
        stride_33 = (stride_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_33) & 127;
    }
    int pivot_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_38) & 63;
    acc ^= aux;
    int damping_70 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_70 > 28) {
        acc = (acc + damping_70 * 2 + 5) & 127;
        aux ^= (damping_70 & 15);
    } else {
        acc = (acc - damping_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_10(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_45 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_45 > 25) {
        acc = (acc + phase_45 * 2 + 5) & 127;
        aux ^= (phase_45 & 15);
    } else {
        acc = (acc - phase_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_11(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001130_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_34) & 63;
    acc ^= aux;
    int parity_61 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_61 > 44) {
        acc = (acc + parity_61 * 2 + 5) & 127;
        aux ^= (parity_61 & 15);
    } else {
        acc = (acc - parity_61 + 11) & 127;
        aux += 3;
    }
    int parity_88 = (aux + st.buffer[1]) & 3;
    switch (parity_88) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_99 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_99 = (pivot_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001130_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_82 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_82 > 36) {
        acc = (acc + residue_82 * 2 + 5) & 127;
        aux ^= (residue_82 & 15);
    } else {
        acc = (acc - residue_82 + 11) & 127;
        aux += 3;
    }
    int damping_82 = (aux + st.buffer[1]) & 3;
    switch (damping_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001130_3013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001130_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_29 = (aux + st.buffer[1]) & 3;
    switch (coefficient_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_80 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_80 = (cursor_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_80) & 127;
    }
    int parity_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001130_0;
    int sec_r001130_1;
    int sec_r001130_2;
    int sec_r001130_3;
    int sec_r001130_4;
    int sec_r001130_5;
    int sec_r001130_6;
    int sec_r001130_7;
    int sec_r001130_8;
    int sec_r001130_9;
    int sec_r001130_10;
    int sec_r001130_11;
    int sec_r001130_12;
    int sec_r001130_13;
    int sec_r001130_14;
    int sec_r001130_15;
    int sec_r001130_16;
    int sec_r001130_17;
    int sec_r001130_18;
    int sec_r001130_19;
    int sec_r001130_20;
    int pub_r001130_0;
    int pub_r001130_1;
    int pub_r001130_2;
    int pub_r001130_3;
    int pub_r001130_4;
    int pub_r001130_5;
    int pub_r001130_6;
    int pub_r001130_7;
    int pub_r001130_8;
    int pub_r001130_9;
    int pub_r001130_10;
    int pub_r001130_11;
    int pub_r001130_12;
    int pub_r001130_13;
    int pub_r001130_14;
    int pub_r001130_15;
    int pub_r001130_16;
    int pub_r001130_17;
    int pub_r001130_18;
    int pub_r001130_19;
    int pub_r001130_20;
    int pub_r001130_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001130_0 >= -100 && pub_r001130_0 <= 100);
    __CPROVER_assume(pub_r001130_1 >= -100 && pub_r001130_1 <= 100);
    __CPROVER_assume(pub_r001130_2 >= -100 && pub_r001130_2 <= 100);
    __CPROVER_assume(pub_r001130_3 >= -100 && pub_r001130_3 <= 100);
    __CPROVER_assume(pub_r001130_4 >= -100 && pub_r001130_4 <= 100);
    __CPROVER_assume(pub_r001130_5 >= -100 && pub_r001130_5 <= 100);
    __CPROVER_assume(pub_r001130_6 >= -100 && pub_r001130_6 <= 100);
    __CPROVER_assume(pub_r001130_7 >= -100 && pub_r001130_7 <= 100);
    __CPROVER_assume(pub_r001130_8 >= -100 && pub_r001130_8 <= 100);
    __CPROVER_assume(pub_r001130_9 >= -100 && pub_r001130_9 <= 100);
    __CPROVER_assume(pub_r001130_10 >= -100 && pub_r001130_10 <= 100);
    __CPROVER_assume(pub_r001130_11 >= -100 && pub_r001130_11 <= 100);
    __CPROVER_assume(pub_r001130_12 >= -100 && pub_r001130_12 <= 100);
    __CPROVER_assume(pub_r001130_13 >= -100 && pub_r001130_13 <= 100);
    __CPROVER_assume(pub_r001130_14 >= -100 && pub_r001130_14 <= 100);
    __CPROVER_assume(pub_r001130_15 >= -100 && pub_r001130_15 <= 100);
    __CPROVER_assume(pub_r001130_16 >= -100 && pub_r001130_16 <= 100);
    __CPROVER_assume(pub_r001130_17 >= -100 && pub_r001130_17 <= 100);
    __CPROVER_assume(pub_r001130_18 >= -100 && pub_r001130_18 <= 100);
    __CPROVER_assume(pub_r001130_19 >= -100 && pub_r001130_19 <= 100);
    __CPROVER_assume(pub_r001130_20 >= -100 && pub_r001130_20 <= 100);
    __CPROVER_assume(pub_r001130_21 >= -100 && pub_r001130_21 <= 100);
    __CPROVER_assume(sec_r001130_0 >= 0 && sec_r001130_0 <= 255);
    __CPROVER_assume(sec_r001130_1 >= 0 && sec_r001130_1 <= 255);
    __CPROVER_assume(sec_r001130_2 >= 0 && sec_r001130_2 <= 255);
    __CPROVER_assume(sec_r001130_3 >= 0 && sec_r001130_3 <= 255);
    __CPROVER_assume(sec_r001130_4 >= 0 && sec_r001130_4 <= 255);
    __CPROVER_assume(sec_r001130_5 >= 0 && sec_r001130_5 <= 255);
    __CPROVER_assume(sec_r001130_6 >= 0 && sec_r001130_6 <= 255);
    __CPROVER_assume(sec_r001130_7 >= 0 && sec_r001130_7 <= 255);
    __CPROVER_assume(sec_r001130_8 >= 0 && sec_r001130_8 <= 255);
    __CPROVER_assume(sec_r001130_9 >= 0 && sec_r001130_9 <= 255);
    __CPROVER_assume(sec_r001130_10 >= 0 && sec_r001130_10 <= 255);
    __CPROVER_assume(sec_r001130_11 >= 0 && sec_r001130_11 <= 255);
    __CPROVER_assume(sec_r001130_12 >= 0 && sec_r001130_12 <= 255);
    __CPROVER_assume(sec_r001130_13 >= 0 && sec_r001130_13 <= 255);
    __CPROVER_assume(sec_r001130_14 >= 0 && sec_r001130_14 <= 255);
    __CPROVER_assume(sec_r001130_15 >= 0 && sec_r001130_15 <= 255);
    __CPROVER_assume(sec_r001130_16 >= 0 && sec_r001130_16 <= 255);
    __CPROVER_assume(sec_r001130_17 >= 0 && sec_r001130_17 <= 255);
    __CPROVER_assume(sec_r001130_18 >= 0 && sec_r001130_18 <= 255);
    __CPROVER_assume(sec_r001130_19 >= 0 && sec_r001130_19 <= 255);
    __CPROVER_assume(sec_r001130_20 >= 0 && sec_r001130_20 <= 255);

    struct MatrixBlock_R001130_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001130_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001130_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001130_0 + 7) & 15;
    struct FilterState_R001130_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001130_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001130_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001130_0 + 9) & 15;
    struct Transaction_R001130_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001130_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001130_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001130_0 + 11) & 15;

    union PacketPayload_R001130_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001130_3013_0(sec_r001130_0, pub_r001130_1);
    int helper_flow_1 = fn_R001130_3013_1(sec_r001130_1, pub_r001130_2, pub_r001130_3);
    int helper_flow_2 = fn_R001130_3013_2(sec_r001130_2, pub_r001130_3, pub_r001130_4, pub_r001130_5);
    int helper_flow_3 = fn_R001130_3013_3(sec_r001130_3, sec_r001130_4, pub_r001130_5, pub_r001130_6, pub_r001130_7);
    int helper_flow_4 = fn_R001130_3013_4(sec_r001130_4, sec_r001130_5, pub_r001130_6);
    int helper_flow_5 = fn_R001130_3013_5(sec_r001130_5, sec_r001130_6, pub_r001130_7, pub_r001130_8, pub_r001130_9);
    int helper_flow_6 = fn_R001130_3013_6(sec_r001130_6, pub_r001130_7, pub_r001130_8, pub_r001130_9, pub_r001130_10);
    int helper_flow_7 = fn_R001130_3013_7(sec_r001130_7, pub_r001130_8, pub_r001130_9);
    int helper_flow_8 = fn_R001130_3013_8(sec_r001130_8, pub_r001130_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001130_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001130_18 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_1 > 22) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001130_8 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_2 > 37) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001130_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_4 > 25) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001130_7 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_6 > 49) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001130_3 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_7 > 39) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001130_16 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_8 > 32) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001130_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001130_13 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_10 > 28) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001130_12 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_11 > 45) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_12 > 48) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_14 > 26) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001130_10 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_15 > 21) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_16 > 22) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001130_18 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_17 > 32) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_18 > 27) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001130_2 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_19 > 28) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001130_8 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_20 > 23) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001130_14 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_21 > 48) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_22 > 45) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_23 > 36) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001130_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001130_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_26 > 30) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_27 > 43) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001130_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001130_1 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_29 > 23) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_30 > 38) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_31 > 29) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_32 > 46) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001130_2 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_33 > 44) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001130_13 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_34 > 41) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_35 > 41) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_36 > 30) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_37 > 32) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001130_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001130_11 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_39 > 22) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001130_15 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_40 > 31) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_41 > 40) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001130_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_43 > 22) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001130_15 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_44 > 23) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001130_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_46 > 38) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_47 > 25) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_48 > 37) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001130_19 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_49 > 46) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001130_2 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_50 > 49) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_51 > 20) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001130_17 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_52 > 33) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_53 > 37) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001130_14 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_54 > 27) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_55 > 34) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_56 > 28) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_57 > 30) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_58 > 30) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001130_15 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_59 > 45) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001130_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_61 > 28) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001130_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_63 > 37) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_64 > 22) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001130_10 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_65 > 47) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_66 > 48) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001130_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_68 > 29) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001130_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001130_6 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_70 > 28) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001130_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_72 > 25) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_73 > 24) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_74 > 44) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001130_11 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_75 > 40) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_76 > 25) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001130_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001130_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001130_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001130_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_81 > 29) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_82 > 21) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001130_9 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_83 > 24) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001130_18 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_84 > 36) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_85 > 37) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_87 > 50) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001130_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_89 > 48) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_90 > 41) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_91 > 25) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_92 > 32) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001130_15 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_93 > 46) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001130_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_95 > 49) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_96 > 33) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001130_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_98 > 46) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_99 > 39) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001130_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001130_20 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_101 > 44) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_102 > 31) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_103 > 36) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001130_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_105 > 34) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_106 > 31) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001130_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_108 > 39) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_109 > 48) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_110 > 31) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_111 > 37) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_112 > 41) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_113 > 48) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_114 > 49) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_115 > 30) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_116 > 39) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_117 > 31) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_118 > 29) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_119 > 34) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001130_1 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_120 > 26) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_121 > 25) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001130_12 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_122 > 41) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_123 > 22) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_124 > 28) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_125 > 21) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_126 > 39) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_127 > 36) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_128 > 39) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001130_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001130_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001130_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_132 > 34) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001130_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001130_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_135 > 38) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001130_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_137 > 31) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_138 > 33) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_139 > 43) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_140 > 44) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_141 > 35) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_142 > 34) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001130_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_144 > 20) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001130_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_146 > 30) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r001130_13 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_147 > 21) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_148 > 20) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_149 > 44) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_150 > 38) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001130_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_152 > 42) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001130_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_154 > 34) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001130_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_156 > 28) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001130_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001130_3 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_158 > 32) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001130_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_161 > 44) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001130_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_163 > 29) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r001130_16 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_164 > 33) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_165 > 30) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_166 > 37) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_167 > 37) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_169 > 28) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_170 > 33) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_171 > 44) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_172 > 50) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_173 > 39) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001130_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_175 > 35) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001130_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_177 > 44) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_178 > 48) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001130_20 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_179 > 24) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001130_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_182 > 25) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_183 > 41) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_184 > 33) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001130_2 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_185 > 25) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001130_4 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_186 > 29) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001130_19 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_187 > 39) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_188 > 48) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_189 > 22) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_190 > 39) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001130_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_192 > 46) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_193 > 39) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001130_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_195 > 39) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_196 > 35) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_197 > 40) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001130_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_199 > 23) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001130_8 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_200 > 30) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001130_1 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_201 > 37) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_202 > 35) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001130_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001130_4 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_204 > 26) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001130_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_206 > 22) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_207 > 45) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_208 > 45) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001130_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_210 > 50) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_211 > 43) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_212 > 26) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_213 > 46) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001130_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001130_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_216 > 40) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_217 > 41) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_218 > 23) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001130_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_220 > 33) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001130_1) & 127;
    if (stage_v_221 > 27) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001130_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_223 > 36) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001130_6) & 127;
    if (stage_v_224 > 32) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_225 > 29) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_226 > 31) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001130_19) & 127;
    if (stage_v_228 > 47) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_229 > 28) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001130_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001130_18 ^ 0x2A) * 2 + pub_r001130_2) & 127;
    if (stage_v_231 > 28) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_232 > 48) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r001130_10 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_233 > 38) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_234 > 39) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_235 > 45) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_236 > 33) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_237 > 43) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001130_9) & 127;
    if (stage_v_238 > 42) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_202 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_239 > 20) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001130_20) & 127;
    if (stage_v_240 > 31) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001130_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_242 > 39) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001130_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001130_13) & 127;
    if (stage_v_244 > 50) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_245 > 46) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001130_4) & 127;
    if (stage_v_246 > 44) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_196 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_247 > 20) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001130_18) & 127;
    if (stage_v_248 > 47) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_171 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_249 > 50) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_250 > 31) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001130_5) & 127;
    if (stage_v_251 > 25) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_252 > 46) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001130_0) & 127;
    if (stage_v_253 > 23) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_254 > 30) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r001130_3 ^ 0x2A) * 2 + pub_r001130_12) & 127;
    if (stage_v_255 > 37) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001130_17) & 127;
    if (stage_v_256 > 44) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_257 > 35) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001130_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001130_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001130_15) & 127;
    if (stage_v_260 > 36) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001130_11) & 127;
    if (stage_v_261 > 39) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001130_3) & 127;
    if (stage_v_262 > 38) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001130_8) & 127;
    if (stage_v_263 > 31) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_264 > 50) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001130_21) & 127;
    if (stage_v_265 > 46) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_218 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_266 > 26) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001130_7) & 127;
    if (stage_v_267 > 24) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_236 ^ 0x2A) * 2 + pub_r001130_16) & 127;
    if (stage_v_268 > 40) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_269 > 41) {
        out_sink = (out_sink + stage_v_269 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_269 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_263 ^ 0x2A) * 2 + pub_r001130_14) & 127;
    if (stage_v_270 > 31) {
        out_sink = (out_sink + stage_v_270 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_270 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001130_10) & 127;
    if (stage_v_271 > 45) {
        out_sink = (out_sink + stage_v_271 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_271 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_271) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
