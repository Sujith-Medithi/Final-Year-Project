/*
 * Benchmark Program: R001087
 * Security Family: nested_implicit_flow
 * Generator Seed: 608713
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001087_8713_0 {
    short dim;
    unsigned char stride;
    int determinant;
    short density;
    unsigned char trace;
    int scale;
    int buffer[3];
};

struct AudioFrame_R001087_8713_1 {
    short gain;
    int sample_rate;
    short channels;
    unsigned char envelope;
    int peak;
    int rms;
    int buffer[3];
};

union TelemetryField_R001087_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001087_8713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001087_8713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_10 = (aux + st.buffer[1]) & 3;
    switch (threshold_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_61 = local_arr[aux % 3];
    acc = (acc + delta_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int pivot_53 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_53 = (pivot_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_53) & 127;
    }
    int threshold_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001087_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_68 = (aux + st.buffer[1]) & 3;
    switch (residue_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_82 = local_arr[aux % 3];
    acc = (acc + parity_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int coefficient_58 = local_arr[aux % 3];
    acc = (acc + coefficient_58 * 2) & 127;
    int sample_70 = 0;
    for (int k = 0; k < 2; k++) {
        sample_70 = (sample_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_70) & 127;
    }
    int margin_91 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_91 > 44) {
        acc = (acc + margin_91 * 2 + 5) & 127;
        aux ^= (margin_91 & 15);
    } else {
        acc = (acc - margin_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001087_8713_4(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int segment_93 = 0;
    for (int k = 0; k < 3; k++) {
        segment_93 = (segment_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_93) & 127;
    }
    int segment_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001087_8713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int metric_85 = local_arr[aux % 3];
    acc = (acc + metric_85 * 2) & 127;
    int margin_67 = 0;
    for (int k = 0; k < 2; k++) {
        margin_67 = (margin_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_67) & 127;
    }
    int index_reg_19 = (aux + st.buffer[1]) & 3;
    switch (index_reg_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_33 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_33 > 50) {
        acc = (acc + parity_33 * 2 + 5) & 127;
        aux ^= (parity_33 & 15);
    } else {
        acc = (acc - parity_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001087_8713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int damping_54 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_54 > 43) {
        acc = (acc + damping_54 * 2 + 5) & 127;
        aux ^= (damping_54 & 15);
    } else {
        acc = (acc - damping_54 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_53 = (aux + st.buffer[1]) & 3;
    switch (checksum_53) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_80 = local_arr[aux % 3];
    acc = (acc + quantum_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_7(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_45 = 0;
    for (int k = 0; k < 2; k++) {
        phase_45 = (phase_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_45) & 127;
    }
    int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_63 = local_arr[aux % 3];
    acc = (acc + parity_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_54 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_54 > 44) {
        acc = (acc + tracker_54 * 2 + 5) & 127;
        aux ^= (tracker_54 & 15);
    } else {
        acc = (acc - tracker_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001087_8713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_77 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_77 > 24) {
        acc = (acc + index_reg_77 * 2 + 5) & 127;
        aux ^= (index_reg_77 & 15);
    } else {
        acc = (acc - index_reg_77 + 11) & 127;
        aux += 3;
    }
    int phase_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001087_8713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int margin_58 = (aux + st.buffer[1]) & 3;
    switch (margin_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_41 = local_arr[aux % 3];
    acc = (acc + damping_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int checksum_88 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_88 > 23) {
        acc = (acc + checksum_88 * 2 + 5) & 127;
        aux ^= (checksum_88 & 15);
    } else {
        acc = (acc - checksum_88 + 11) & 127;
        aux += 3;
    }
    int accumulator_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001087_8713_12(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_85 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_85 = (threshold_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_85) & 127;
    }
    int quantum_46 = (aux + st.buffer[1]) & 3;
    switch (quantum_46) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_32 = local_arr[aux % 3];
    acc = (acc + accumulator_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001087_8713_13(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_50 = (aux + st.buffer[1]) & 3;
    switch (segment_50) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_43 = local_arr[aux % 3];
    acc = (acc + quantum_43 * 2) & 127;
    int pivot_51 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_51 > 33) {
        acc = (acc + pivot_51 * 2 + 5) & 127;
        aux ^= (pivot_51 & 15);
    } else {
        acc = (acc - pivot_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001087_8713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_71 = (aux + st.buffer[1]) & 3;
    switch (anchor_71) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_45 = (st.buffer[0] * 3 + aux) & 63;
    if (window_45 > 35) {
        acc = (acc + window_45 * 2 + 5) & 127;
        aux ^= (window_45 & 15);
    } else {
        acc = (acc - window_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001087_0;
    int sec_r001087_1;
    int sec_r001087_2;
    int sec_r001087_3;
    int sec_r001087_4;
    int sec_r001087_5;
    int sec_r001087_6;
    int sec_r001087_7;
    int sec_r001087_8;
    int sec_r001087_9;
    int sec_r001087_10;
    int sec_r001087_11;
    int sec_r001087_12;
    int sec_r001087_13;
    int sec_r001087_14;
    int sec_r001087_15;
    int sec_r001087_16;
    int sec_r001087_17;
    int sec_r001087_18;
    int pub_r001087_0;
    int pub_r001087_1;
    int pub_r001087_2;
    int pub_r001087_3;
    int pub_r001087_4;
    int pub_r001087_5;
    int pub_r001087_6;
    int pub_r001087_7;
    int pub_r001087_8;
    int pub_r001087_9;
    int pub_r001087_10;
    int pub_r001087_11;
    int pub_r001087_12;
    int pub_r001087_13;
    int pub_r001087_14;
    int pub_r001087_15;
    int pub_r001087_16;
    int pub_r001087_17;
    int pub_r001087_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001087_0 >= -100 && pub_r001087_0 <= 100);
    __CPROVER_assume(pub_r001087_1 >= -100 && pub_r001087_1 <= 100);
    __CPROVER_assume(pub_r001087_2 >= -100 && pub_r001087_2 <= 100);
    __CPROVER_assume(pub_r001087_3 >= -100 && pub_r001087_3 <= 100);
    __CPROVER_assume(pub_r001087_4 >= -100 && pub_r001087_4 <= 100);
    __CPROVER_assume(pub_r001087_5 >= -100 && pub_r001087_5 <= 100);
    __CPROVER_assume(pub_r001087_6 >= -100 && pub_r001087_6 <= 100);
    __CPROVER_assume(pub_r001087_7 >= -100 && pub_r001087_7 <= 100);
    __CPROVER_assume(pub_r001087_8 >= -100 && pub_r001087_8 <= 100);
    __CPROVER_assume(pub_r001087_9 >= -100 && pub_r001087_9 <= 100);
    __CPROVER_assume(pub_r001087_10 >= -100 && pub_r001087_10 <= 100);
    __CPROVER_assume(pub_r001087_11 >= -100 && pub_r001087_11 <= 100);
    __CPROVER_assume(pub_r001087_12 >= -100 && pub_r001087_12 <= 100);
    __CPROVER_assume(pub_r001087_13 >= -100 && pub_r001087_13 <= 100);
    __CPROVER_assume(pub_r001087_14 >= -100 && pub_r001087_14 <= 100);
    __CPROVER_assume(pub_r001087_15 >= -100 && pub_r001087_15 <= 100);
    __CPROVER_assume(pub_r001087_16 >= -100 && pub_r001087_16 <= 100);
    __CPROVER_assume(pub_r001087_17 >= -100 && pub_r001087_17 <= 100);
    __CPROVER_assume(pub_r001087_18 >= -100 && pub_r001087_18 <= 100);
    __CPROVER_assume(sec_r001087_0 >= 0 && sec_r001087_0 <= 255);
    __CPROVER_assume(sec_r001087_1 >= 0 && sec_r001087_1 <= 255);
    __CPROVER_assume(sec_r001087_2 >= 0 && sec_r001087_2 <= 255);
    __CPROVER_assume(sec_r001087_3 >= 0 && sec_r001087_3 <= 255);
    __CPROVER_assume(sec_r001087_4 >= 0 && sec_r001087_4 <= 255);
    __CPROVER_assume(sec_r001087_5 >= 0 && sec_r001087_5 <= 255);
    __CPROVER_assume(sec_r001087_6 >= 0 && sec_r001087_6 <= 255);
    __CPROVER_assume(sec_r001087_7 >= 0 && sec_r001087_7 <= 255);
    __CPROVER_assume(sec_r001087_8 >= 0 && sec_r001087_8 <= 255);
    __CPROVER_assume(sec_r001087_9 >= 0 && sec_r001087_9 <= 255);
    __CPROVER_assume(sec_r001087_10 >= 0 && sec_r001087_10 <= 255);
    __CPROVER_assume(sec_r001087_11 >= 0 && sec_r001087_11 <= 255);
    __CPROVER_assume(sec_r001087_12 >= 0 && sec_r001087_12 <= 255);
    __CPROVER_assume(sec_r001087_13 >= 0 && sec_r001087_13 <= 255);
    __CPROVER_assume(sec_r001087_14 >= 0 && sec_r001087_14 <= 255);
    __CPROVER_assume(sec_r001087_15 >= 0 && sec_r001087_15 <= 255);
    __CPROVER_assume(sec_r001087_16 >= 0 && sec_r001087_16 <= 255);
    __CPROVER_assume(sec_r001087_17 >= 0 && sec_r001087_17 <= 255);
    __CPROVER_assume(sec_r001087_18 >= 0 && sec_r001087_18 <= 255);

    struct MatrixBlock_R001087_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001087_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001087_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001087_0 + 7) & 15;
    struct AudioFrame_R001087_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001087_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001087_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001087_0 + 9) & 15;

    union TelemetryField_R001087_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001087_8713_0(sec_r001087_0, sec_r001087_1, pub_r001087_2, pub_r001087_3, pub_r001087_4);
    int helper_flow_1 = fn_R001087_8713_1(sec_r001087_1, pub_r001087_2, pub_r001087_3, pub_r001087_4, pub_r001087_5);
    int helper_flow_2 = fn_R001087_8713_2(sec_r001087_2, sec_r001087_3, pub_r001087_4);
    int helper_flow_3 = fn_R001087_8713_3(sec_r001087_3, sec_r001087_4, pub_r001087_5, pub_r001087_6);
    int helper_flow_4 = fn_R001087_8713_4(sec_r001087_4, pub_r001087_5, pub_r001087_6);
    int helper_flow_5 = fn_R001087_8713_5(sec_r001087_5, sec_r001087_6, pub_r001087_7, pub_r001087_8, pub_r001087_9);
    int helper_flow_6 = fn_R001087_8713_6(sec_r001087_6, pub_r001087_7, pub_r001087_8, pub_r001087_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001087_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_2 ^ pub_r001087_9) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001087_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001087_0 ^ pub_r001087_5) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (stage_v_1 ^ pub_r001087_14) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001087_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001087_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001087_13 ^ pub_r001087_16) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001087_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001087_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001087_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001087_0 ^ pub_r001087_5) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001087_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001087_18 ^ pub_r001087_9) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001087_0 ^ pub_r001087_9) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001087_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001087_15 ^ pub_r001087_4) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001087_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001087_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_12 ^ pub_r001087_11) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001087_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001087_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001087_18 ^ pub_r001087_6) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001087_4 ^ pub_r001087_12) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001087_15 ^ pub_r001087_5) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001087_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_12 ^ pub_r001087_2) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001087_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_22 ^ pub_r001087_17) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001087_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_19 ^ pub_r001087_3) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_23 ^ pub_r001087_17) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_6 ^ pub_r001087_10) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_19 ^ pub_r001087_7) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001087_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_24 ^ pub_r001087_13) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001087_1 ^ pub_r001087_4) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001087_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001087_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001087_12 ^ pub_r001087_11) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_18 ^ pub_r001087_7) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001087_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001087_14 ^ pub_r001087_13) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001087_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001087_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001087_0 ^ pub_r001087_14) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_19 ^ pub_r001087_8) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001087_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001087_2 ^ pub_r001087_12) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_15 ^ pub_r001087_9) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001087_2 ^ pub_r001087_13) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001087_5 ^ pub_r001087_18) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001087_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001087_16 ^ pub_r001087_16) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_2 ^ pub_r001087_12) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001087_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_6 ^ pub_r001087_16) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_1 ^ pub_r001087_13) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_27 ^ pub_r001087_9) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001087_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001087_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_23 ^ pub_r001087_7) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r001087_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001087_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_22 ^ pub_r001087_15) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001087_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_33 ^ pub_r001087_18) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001087_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001087_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001087_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001087_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001087_4 ^ pub_r001087_4) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001087_2 ^ pub_r001087_13) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001087_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_43 ^ pub_r001087_13) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001087_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_47 ^ pub_r001087_14) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r001087_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_9 ^ pub_r001087_6) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_34 ^ pub_r001087_1) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001087_10 ^ pub_r001087_13) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_63 ^ pub_r001087_14) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_46 ^ pub_r001087_14) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001087_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001087_1 ^ pub_r001087_0) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001087_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001087_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_43 ^ pub_r001087_15) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001087_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001087_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_1 ^ pub_r001087_3) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001087_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_67 ^ pub_r001087_7) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001087_7 ^ pub_r001087_0) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001087_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_50 ^ pub_r001087_5) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_71 ^ pub_r001087_13) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_15 ^ pub_r001087_4) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001087_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001087_9 ^ pub_r001087_11) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001087_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001087_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (helper_flow_6 ^ pub_r001087_7) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_74 ^ pub_r001087_2) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_60 ^ pub_r001087_8) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001087_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001087_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_12 ^ pub_r001087_8) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (helper_flow_3 ^ pub_r001087_4) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_71 ^ pub_r001087_8) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_80 ^ pub_r001087_4) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_28 ^ pub_r001087_7) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_38 ^ pub_r001087_5) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_27 ^ pub_r001087_2) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_12 ^ pub_r001087_9) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001087_5 ^ pub_r001087_14) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001087_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001087_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_77 ^ pub_r001087_1) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001087_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_63 ^ pub_r001087_16) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_1 ^ pub_r001087_5) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001087_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001087_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_91 ^ pub_r001087_15) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001087_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001087_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001087_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001087_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001087_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_15 ^ pub_r001087_5) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_33 ^ pub_r001087_3) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_38 ^ pub_r001087_6) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001087_4 ^ pub_r001087_12) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_44 ^ pub_r001087_1) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001087_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_57 ^ pub_r001087_6) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001087_15 ^ pub_r001087_7) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r001087_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001087_2 ^ pub_r001087_3) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (helper_flow_6 ^ pub_r001087_17) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_28 ^ pub_r001087_8) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r001087_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_71 ^ pub_r001087_3) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001087_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_18 ^ pub_r001087_10) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001087_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_87 ^ pub_r001087_9) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_107 ^ pub_r001087_12) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001087_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001087_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_85 ^ pub_r001087_3) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_123 ^ pub_r001087_12) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_26 ^ pub_r001087_13) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r001087_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_122 ^ pub_r001087_0) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001087_17 ^ pub_r001087_7) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001087_2 ^ pub_r001087_10) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001087_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_43 ^ pub_r001087_4) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_86 ^ pub_r001087_8) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001087_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001087_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_52 ^ pub_r001087_5) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r001087_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001087_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_25 ^ pub_r001087_0) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001087_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_93 ^ pub_r001087_12) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_119 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_98 ^ pub_r001087_1) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001087_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_135 ^ pub_r001087_3) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001087_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r001087_8 ^ pub_r001087_18) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001087_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_46 ^ pub_r001087_7) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_127 ^ pub_r001087_12) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_40 ^ pub_r001087_5) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r001087_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_42 ^ pub_r001087_1) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001087_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001087_12 ^ pub_r001087_4) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r001087_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_2 ^ pub_r001087_9) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_50 ^ pub_r001087_4) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_62 ^ pub_r001087_5) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001087_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001087_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_52 ^ pub_r001087_12) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_37 ^ pub_r001087_8) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_164 ^ pub_r001087_5) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001087_5 ^ pub_r001087_12) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_22 ^ pub_r001087_2) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_66 ^ pub_r001087_11) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((sec_r001087_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (helper_flow_0 ^ pub_r001087_15) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001087_0 ^ pub_r001087_7) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_28 ^ pub_r001087_13) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r001087_3 ^ pub_r001087_4) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r001087_12 ^ pub_r001087_3) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((sec_r001087_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001087_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_146 ^ pub_r001087_11) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001087_14 ^ pub_r001087_17) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001087_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_131 ^ pub_r001087_6) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_12 ^ pub_r001087_16) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_146 ^ pub_r001087_4) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_93 ^ pub_r001087_12) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_122 ^ pub_r001087_12) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_50 ^ pub_r001087_5) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001087_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_121 ^ pub_r001087_5) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001087_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_182 ^ pub_r001087_5) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_3 ^ pub_r001087_13) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((sec_r001087_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001087_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001087_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001087_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_131 ^ pub_r001087_9) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((sec_r001087_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_172 ^ pub_r001087_6) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001087_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_171 ^ pub_r001087_11) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r001087_9 ^ pub_r001087_10) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_177 ^ pub_r001087_12) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((sec_r001087_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_65 ^ pub_r001087_0) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_197 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001087_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_170 ^ pub_r001087_1) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r001087_7 ^ pub_r001087_0) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001087_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001087_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_172 ^ pub_r001087_13) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
