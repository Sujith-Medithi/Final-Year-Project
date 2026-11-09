/*
 * Benchmark Program: R001228
 * Security Family: secret_dependent_loops
 * Generator Seed: 622813
 * High Inputs: 21 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001228_2813_0 {
    unsigned char seq;
    int severity;
    unsigned char code;
    int buffer[3];
};

struct MatrixBlock_R001228_2813_1 {
    int scale;
    unsigned char trace;
    int density;
    int dim;
    int stride;
    int determinant;
    int buffer[3];
};

struct Vector3D_R001228_2813_2 {
    unsigned char coord_z;
    int coord_x;
    int pitch;
    int buffer[3];
};

struct StreamBuffer_R001228_2813_3 {
    unsigned char head;
    int state;
    unsigned char checksum;
    int tail;
    int watermark;
    int buffer[3];
};

union PacketPayload_R001228_2813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001228_2813_0(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001228_2813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_99) & 63;
    acc ^= aux;
    int damping_83 = (aux + st.buffer[1]) & 3;
    switch (damping_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_1(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001228_2813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_54 = 0;
    for (int k = 0; k < 3; k++) {
        stride_54 = (stride_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_54) & 127;
    }
    int margin_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001228_2813_2(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int cursor_28 = local_arr[aux % 3];
    acc = (acc + cursor_28 * 2) & 127;
    int index_reg_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_12) & 63;
    acc ^= aux;
    int phase_41 = 0;
    for (int k = 0; k < 3; k++) {
        phase_41 = (phase_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_41) & 127;
    }
    int delta_30 = (aux + st.buffer[1]) & 3;
    switch (delta_30) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_45 = (aux + st.buffer[1]) & 3;
    switch (damping_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_27 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_27 > 19) {
        acc = (acc + offset_27 * 2 + 5) & 127;
        aux ^= (offset_27 & 15);
    } else {
        acc = (acc - offset_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_62 = local_arr[aux % 3];
    acc = (acc + threshold_62 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001228_2813_4(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_37 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_37 = (cursor_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_37) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001228_2813_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_56 = local_arr[aux % 3];
    acc = (acc + cursor_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001228_2813_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001228_2813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int accumulator_21 = local_arr[aux % 3];
    acc = (acc + accumulator_21 * 2) & 127;
    int segment_90 = (aux + st.buffer[1]) & 3;
    switch (segment_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_7(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tally_90 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_90 > 44) {
        acc = (acc + tally_90 * 2 + 5) & 127;
        aux ^= (tally_90 & 15);
    } else {
        acc = (acc - tally_90 + 11) & 127;
        aux += 3;
    }
    int index_reg_95 = (aux + st.buffer[1]) & 3;
    switch (index_reg_95) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001228_2813_8(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_36 = local_arr[aux % 3];
    acc = (acc + factor_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001228_2813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_40 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_40 = (threshold_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_40) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001228_2813_10(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int vector_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_26) & 63;
    acc ^= aux;
    int bound_96 = (aux + st.buffer[1]) & 3;
    switch (bound_96) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_11(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int offset_49 = local_arr[aux % 3];
    acc = (acc + offset_49 * 2) & 127;
    int damping_77 = 0;
    for (int k = 0; k < 3; k++) {
        damping_77 = (damping_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_12(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_89 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_89 = (tracker_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_89) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_10 > 46) {
        acc = (acc + cursor_10 * 2 + 5) & 127;
        aux ^= (cursor_10 & 15);
    } else {
        acc = (acc - cursor_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001228_2813_13(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001228_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int coefficient_12 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_12 = (coefficient_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_12) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_81 = local_arr[aux % 3];
    acc = (acc + parity_81 * 2) & 127;
    int cursor_26 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_26 > 22) {
        acc = (acc + cursor_26 * 2 + 5) & 127;
        aux ^= (cursor_26 & 15);
    } else {
        acc = (acc - cursor_26 + 11) & 127;
        aux += 3;
    }
    int checksum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001228_2813_14(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001228_2813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_13 = (aux + st.buffer[1]) & 3;
    switch (factor_13) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_65) & 63;
    acc ^= aux;
    int tally_61 = 0;
    for (int k = 0; k < 3; k++) {
        tally_61 = (tally_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_61) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_34 = local_arr[aux % 3];
    acc = (acc + tally_34 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001228_0;
    int sec_r001228_1;
    int sec_r001228_2;
    int sec_r001228_3;
    int sec_r001228_4;
    int sec_r001228_5;
    int sec_r001228_6;
    int sec_r001228_7;
    int sec_r001228_8;
    int sec_r001228_9;
    int sec_r001228_10;
    int sec_r001228_11;
    int sec_r001228_12;
    int sec_r001228_13;
    int sec_r001228_14;
    int sec_r001228_15;
    int sec_r001228_16;
    int sec_r001228_17;
    int sec_r001228_18;
    int sec_r001228_19;
    int sec_r001228_20;
    int pub_r001228_0;
    int pub_r001228_1;
    int pub_r001228_2;
    int pub_r001228_3;
    int pub_r001228_4;
    int pub_r001228_5;
    int pub_r001228_6;
    int pub_r001228_7;
    int pub_r001228_8;
    int pub_r001228_9;
    int pub_r001228_10;
    int pub_r001228_11;
    int pub_r001228_12;
    int pub_r001228_13;
    int pub_r001228_14;
    int pub_r001228_15;
    int pub_r001228_16;
    int pub_r001228_17;
    int pub_r001228_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001228_0 >= -100 && pub_r001228_0 <= 100);
    __CPROVER_assume(pub_r001228_1 >= -100 && pub_r001228_1 <= 100);
    __CPROVER_assume(pub_r001228_2 >= -100 && pub_r001228_2 <= 100);
    __CPROVER_assume(pub_r001228_3 >= -100 && pub_r001228_3 <= 100);
    __CPROVER_assume(pub_r001228_4 >= -100 && pub_r001228_4 <= 100);
    __CPROVER_assume(pub_r001228_5 >= -100 && pub_r001228_5 <= 100);
    __CPROVER_assume(pub_r001228_6 >= -100 && pub_r001228_6 <= 100);
    __CPROVER_assume(pub_r001228_7 >= -100 && pub_r001228_7 <= 100);
    __CPROVER_assume(pub_r001228_8 >= -100 && pub_r001228_8 <= 100);
    __CPROVER_assume(pub_r001228_9 >= -100 && pub_r001228_9 <= 100);
    __CPROVER_assume(pub_r001228_10 >= -100 && pub_r001228_10 <= 100);
    __CPROVER_assume(pub_r001228_11 >= -100 && pub_r001228_11 <= 100);
    __CPROVER_assume(pub_r001228_12 >= -100 && pub_r001228_12 <= 100);
    __CPROVER_assume(pub_r001228_13 >= -100 && pub_r001228_13 <= 100);
    __CPROVER_assume(pub_r001228_14 >= -100 && pub_r001228_14 <= 100);
    __CPROVER_assume(pub_r001228_15 >= -100 && pub_r001228_15 <= 100);
    __CPROVER_assume(pub_r001228_16 >= -100 && pub_r001228_16 <= 100);
    __CPROVER_assume(pub_r001228_17 >= -100 && pub_r001228_17 <= 100);
    __CPROVER_assume(pub_r001228_18 >= -100 && pub_r001228_18 <= 100);
    __CPROVER_assume(sec_r001228_0 >= 0 && sec_r001228_0 <= 255);
    __CPROVER_assume(sec_r001228_1 >= 0 && sec_r001228_1 <= 255);
    __CPROVER_assume(sec_r001228_2 >= 0 && sec_r001228_2 <= 255);
    __CPROVER_assume(sec_r001228_3 >= 0 && sec_r001228_3 <= 255);
    __CPROVER_assume(sec_r001228_4 >= 0 && sec_r001228_4 <= 255);
    __CPROVER_assume(sec_r001228_5 >= 0 && sec_r001228_5 <= 255);
    __CPROVER_assume(sec_r001228_6 >= 0 && sec_r001228_6 <= 255);
    __CPROVER_assume(sec_r001228_7 >= 0 && sec_r001228_7 <= 255);
    __CPROVER_assume(sec_r001228_8 >= 0 && sec_r001228_8 <= 255);
    __CPROVER_assume(sec_r001228_9 >= 0 && sec_r001228_9 <= 255);
    __CPROVER_assume(sec_r001228_10 >= 0 && sec_r001228_10 <= 255);
    __CPROVER_assume(sec_r001228_11 >= 0 && sec_r001228_11 <= 255);
    __CPROVER_assume(sec_r001228_12 >= 0 && sec_r001228_12 <= 255);
    __CPROVER_assume(sec_r001228_13 >= 0 && sec_r001228_13 <= 255);
    __CPROVER_assume(sec_r001228_14 >= 0 && sec_r001228_14 <= 255);
    __CPROVER_assume(sec_r001228_15 >= 0 && sec_r001228_15 <= 255);
    __CPROVER_assume(sec_r001228_16 >= 0 && sec_r001228_16 <= 255);
    __CPROVER_assume(sec_r001228_17 >= 0 && sec_r001228_17 <= 255);
    __CPROVER_assume(sec_r001228_18 >= 0 && sec_r001228_18 <= 255);
    __CPROVER_assume(sec_r001228_19 >= 0 && sec_r001228_19 <= 255);
    __CPROVER_assume(sec_r001228_20 >= 0 && sec_r001228_20 <= 255);

    struct EventLog_R001228_2813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001228_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001228_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001228_0 + 7) & 15;
    struct MatrixBlock_R001228_2813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001228_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001228_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001228_0 + 9) & 15;
    struct Vector3D_R001228_2813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001228_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001228_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001228_0 + 11) & 15;
    struct StreamBuffer_R001228_2813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001228_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001228_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001228_0 + 13) & 15;

    union PacketPayload_R001228_2813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001228_2813_0(sec_r001228_0, sec_r001228_1);
    int helper_flow_1 = fn_R001228_2813_1(sec_r001228_1, sec_r001228_2);
    int helper_flow_2 = fn_R001228_2813_2(sec_r001228_2, sec_r001228_3);
    int helper_flow_3 = fn_R001228_2813_3(sec_r001228_3, pub_r001228_4, pub_r001228_5, pub_r001228_6, pub_r001228_7);
    int helper_flow_4 = fn_R001228_2813_4(sec_r001228_4, pub_r001228_5, pub_r001228_6);
    int helper_flow_5 = fn_R001228_2813_5(sec_r001228_5, sec_r001228_6, pub_r001228_7);
    int helper_flow_6 = fn_R001228_2813_6(sec_r001228_6, pub_r001228_7, pub_r001228_8, pub_r001228_9);
    int helper_flow_7 = fn_R001228_2813_7(sec_r001228_7, pub_r001228_8);
    int helper_flow_8 = fn_R001228_2813_8(sec_r001228_8, pub_r001228_9);
    int helper_flow_9 = fn_R001228_2813_9(sec_r001228_9, sec_r001228_10, pub_r001228_11, pub_r001228_12);
    int helper_flow_10 = fn_R001228_2813_10(sec_r001228_10, sec_r001228_11, pub_r001228_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001228_17 & 15)) & 63;
        if ((sec_r001228_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (sec_r001228_18 & 15)) & 63;
        if ((sec_r001228_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001228_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001228_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001228_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001228_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_8 = (stage_v_8 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_8 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_8 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (sec_r001228_15 & 15)) & 63;
        if ((sec_r001228_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (sec_r001228_10 & 15)) & 63;
        if ((sec_r001228_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_14 = (stage_v_14 + it * 3 + (sec_r001228_2 & 15)) & 63;
        if ((sec_r001228_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_14 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_14 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001228_8 & 15)) & 63;
        if ((sec_r001228_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001228_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_22 = (stage_v_22 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_22 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_22 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001228_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001228_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (sec_r001228_18 & 15)) & 63;
        if ((sec_r001228_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_27 = (stage_v_27 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_27 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_27 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001228_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (sec_r001228_3 & 15)) & 63;
        if ((sec_r001228_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001228_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (sec_r001228_16 & 15)) & 63;
        if ((sec_r001228_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001228_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_33 = (stage_v_33 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_33 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_33 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001228_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (sec_r001228_19 & 15)) & 63;
        if ((sec_r001228_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (sec_r001228_9 & 15)) & 63;
        if ((sec_r001228_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001228_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001228_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_41 = (stage_v_41 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_41 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_41 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (sec_r001228_0 & 15)) & 63;
        if ((sec_r001228_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001228_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001228_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (sec_r001228_3 & 15)) & 63;
        if ((sec_r001228_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001228_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (sec_r001228_9 & 15)) & 63;
        if ((sec_r001228_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_52 = (stage_v_52 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_52 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_52 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001228_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001228_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001228_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001228_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001228_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (sec_r001228_20 & 15)) & 63;
        if ((sec_r001228_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001228_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001228_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (stage_v_52 & 15)) & 63;
        if ((stage_v_52 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_65 = (stage_v_65 + it * 3 + (sec_r001228_19 & 15)) & 63;
        if ((sec_r001228_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_65 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_65 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (sec_r001228_19 & 15)) & 63;
        if ((sec_r001228_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (sec_r001228_6 & 15)) & 63;
        if ((sec_r001228_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (sec_r001228_18 & 15)) & 63;
        if ((sec_r001228_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001228_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001228_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001228_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001228_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_76 = (stage_v_76 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_76 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_76 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_77 = (stage_v_77 + it * 3 + (stage_v_45 & 15)) & 63;
        if ((stage_v_45 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_77 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_77 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_52 & 15)) & 63;
        if ((stage_v_52 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (sec_r001228_18 & 15)) & 63;
        if ((sec_r001228_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (sec_r001228_6 & 15)) & 63;
        if ((sec_r001228_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (sec_r001228_8 & 15)) & 63;
        if ((sec_r001228_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001228_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001228_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001228_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_87 = (stage_v_87 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_87 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_87 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001228_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (sec_r001228_15 & 15)) & 63;
        if ((sec_r001228_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001228_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001228_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (sec_r001228_16 & 15)) & 63;
        if ((sec_r001228_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001228_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001228_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (sec_r001228_2 & 15)) & 63;
        if ((sec_r001228_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001228_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001228_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001228_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001228_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001228_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001228_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (sec_r001228_8 & 15)) & 63;
        if ((sec_r001228_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001228_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001228_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001228_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (stage_v_33 & 15)) & 63;
        if ((stage_v_33 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001228_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (stage_v_8 & 15)) & 63;
        if ((stage_v_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001228_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001228_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (sec_r001228_9 & 15)) & 63;
        if ((sec_r001228_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_120 = (stage_v_120 + it * 3 + (sec_r001228_17 & 15)) & 63;
        if ((sec_r001228_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_120 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_120 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001228_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001228_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (stage_v_14 & 15)) & 63;
        if ((stage_v_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (stage_v_17 & 15)) & 63;
        if ((stage_v_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_126 & 15)) & 63;
        if ((stage_v_126 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001228_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_126 & 15)) & 63;
        if ((stage_v_126 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (stage_v_17 & 15)) & 63;
        if ((stage_v_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001228_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001228_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (stage_v_41 & 15)) & 63;
        if ((stage_v_41 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001228_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_136 = (stage_v_136 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_136 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_136 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_135 & 15)) & 63;
        if ((stage_v_135 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (sec_r001228_8 & 15)) & 63;
        if ((sec_r001228_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (sec_r001228_16 & 15)) & 63;
        if ((sec_r001228_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001228_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_95 & 15)) & 63;
        if ((stage_v_95 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001228_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_145 = (stage_v_145 + it * 3 + (stage_v_112 & 15)) & 63;
        if ((stage_v_112 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_145 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_145 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (stage_v_79 & 15)) & 63;
        if ((stage_v_79 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (stage_v_119 & 15)) & 63;
        if ((stage_v_119 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (sec_r001228_10 & 15)) & 63;
        if ((sec_r001228_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_65 & 15)) & 63;
        if ((stage_v_65 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (sec_r001228_5 & 15)) & 63;
        if ((sec_r001228_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_112 & 15)) & 63;
        if ((stage_v_112 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001228_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_153 = (stage_v_153 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_153 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_153 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (stage_v_60 & 15)) & 63;
        if ((stage_v_60 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_155 = (stage_v_155 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_155 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_155 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_153 & 15)) & 63;
        if ((stage_v_153 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_158 = (stage_v_158 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_158 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_158 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_159 = (stage_v_159 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_159 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_159 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (sec_r001228_11 & 15)) & 63;
        if ((sec_r001228_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001228_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_66 & 15)) & 63;
        if ((stage_v_66 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_165 = (stage_v_165 + it * 3 + (stage_v_115 & 15)) & 63;
        if ((stage_v_115 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_165 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_165 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_160 & 15)) & 63;
        if ((stage_v_160 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001228_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_171 = (stage_v_171 + it * 3 + (sec_r001228_3 & 15)) & 63;
        if ((sec_r001228_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_171 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_171 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_150 & 15)) & 63;
        if ((stage_v_150 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (sec_r001228_1 & 15)) & 63;
        if ((sec_r001228_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (stage_v_158 & 15)) & 63;
        if ((stage_v_158 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_8 & 15)) & 63;
        if ((stage_v_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001228_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001228_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001228_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001228_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_139 & 15)) & 63;
        if ((stage_v_139 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (stage_v_38 & 15)) & 63;
        if ((stage_v_38 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (stage_v_153 & 15)) & 63;
        if ((stage_v_153 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001228_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001228_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (stage_v_81 & 15)) & 63;
        if ((stage_v_81 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001228_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001228_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_65 & 15)) & 63;
        if ((stage_v_65 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (sec_r001228_11 & 15)) & 63;
        if ((sec_r001228_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001228_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001228_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_201 = (stage_v_201 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_201 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_201 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_171 & 15)) & 63;
        if ((stage_v_171 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001228_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_133 & 15)) & 63;
        if ((stage_v_133 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001228_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001228_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_207 = (stage_v_207 + it * 3 + (stage_v_88 & 15)) & 63;
        if ((stage_v_88 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_207 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_207 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
