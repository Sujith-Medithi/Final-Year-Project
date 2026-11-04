/*
 * Benchmark Program: R000645
 * Family: nested_implicit_flow
 * Generator Seed: 464513
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000645_4513_0 {
    int calib;
    short status;
    int offset;
    short threshold;
    short gain;
    int reading;
    int buffer[3];
};

struct FilterState_R000645_4513_1 {
    int damping;
    short gain_db;
    short cutoff;
    int buffer[3];
};

struct MatrixBlock_R000645_4513_2 {
    unsigned char scale;
    int determinant;
    short density;
    int buffer[3];
};

union PacketPayload_R000645_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000645_4513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000645_4513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_19 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_19 > 33) {
        acc = (acc + margin_19 * 2 + 5) & 127;
        aux ^= (margin_19 & 15);
    } else {
        acc = (acc - margin_19 + 11) & 127;
        aux += 3;
    }
    int coefficient_50 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_50 = (coefficient_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_50) & 127;
    }
    int threshold_84 = (aux + st.buffer[1]) & 3;
    switch (threshold_84) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_1(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_22) & 63;
    acc ^= aux;
    int anchor_16 = (aux + st.buffer[1]) & 3;
    switch (anchor_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_45 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_45 > 33) {
        acc = (acc + mask_45 * 2 + 5) & 127;
        aux ^= (mask_45 & 15);
    } else {
        acc = (acc - mask_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_59 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_59 > 37) {
        acc = (acc + vector_59 * 2 + 5) & 127;
        aux ^= (vector_59 & 15);
    } else {
        acc = (acc - vector_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_35 = local_arr[aux % 3];
    acc = (acc + window_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_77 = (aux + st.buffer[1]) & 3;
    switch (offset_77) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_3(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int metric_40 = 0;
    for (int k = 0; k < 2; k++) {
        metric_40 = (metric_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_40) & 127;
    }
    int parity_45 = (aux + st.buffer[1]) & 3;
    switch (parity_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_26 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_26 > 20) {
        acc = (acc + pivot_26 * 2 + 5) & 127;
        aux ^= (pivot_26 & 15);
    } else {
        acc = (acc - pivot_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_4(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int segment_51 = local_arr[aux % 3];
    acc = (acc + segment_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_36 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_36 > 48) {
        acc = (acc + margin_36 * 2 + 5) & 127;
        aux ^= (margin_36 & 15);
    } else {
        acc = (acc - margin_36 + 11) & 127;
        aux += 3;
    }
    int vector_99 = (aux + st.buffer[1]) & 3;
    switch (vector_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_5(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_78 = (aux + st.buffer[1]) & 3;
    switch (damping_78) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_32 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_32 > 48) {
        acc = (acc + phase_32 * 2 + 5) & 127;
        aux ^= (phase_32 & 15);
    } else {
        acc = (acc - phase_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int sample_94 = local_arr[aux % 3];
    acc = (acc + sample_94 * 2) & 127;
    int pivot_59 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_59 > 40) {
        acc = (acc + pivot_59 * 2 + 5) & 127;
        aux ^= (pivot_59 & 15);
    } else {
        acc = (acc - pivot_59 + 11) & 127;
        aux += 3;
    }
    int pivot_19 = (aux + st.buffer[1]) & 3;
    switch (pivot_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_88 = local_arr[aux % 3];
    acc = (acc + window_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_78 = (aux + st.buffer[1]) & 3;
    switch (segment_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_92 = 0;
    for (int k = 0; k < 2; k++) {
        stride_92 = (stride_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_92) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_16 = local_arr[aux % 3];
    acc = (acc + quotient_16 * 2) & 127;
    int cursor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000645_4513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int pivot_43 = local_arr[aux % 3];
    acc = (acc + pivot_43 * 2) & 127;
    int delta_11 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_11 > 16) {
        acc = (acc + delta_11 * 2 + 5) & 127;
        aux ^= (delta_11 & 15);
    } else {
        acc = (acc - delta_11 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_75 = (aux + st.buffer[1]) & 3;
    switch (quotient_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_10(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_49 = (aux + st.buffer[1]) & 3;
    switch (coefficient_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_48 = 0;
    for (int k = 0; k < 2; k++) {
        residue_48 = (residue_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_94) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_82 = local_arr[aux % 3];
    acc = (acc + tracker_82 * 2) & 127;
    int stride_56 = (aux + st.buffer[1]) & 3;
    switch (stride_56) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_74 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_74 > 10) {
        acc = (acc + cursor_74 * 2 + 5) & 127;
        aux ^= (cursor_74 & 15);
    } else {
        acc = (acc - cursor_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_72) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_82 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_82 > 40) {
        acc = (acc + parity_82 * 2 + 5) & 127;
        aux ^= (parity_82 & 15);
    } else {
        acc = (acc - parity_82 + 11) & 127;
        aux += 3;
    }
    int stride_62 = (aux + st.buffer[1]) & 3;
    switch (stride_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_13(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int margin_55 = local_arr[aux % 3];
    acc = (acc + margin_55 * 2) & 127;
    int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000645_4513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_30 = (aux + st.buffer[1]) & 3;
    switch (anchor_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_45 = 0;
    for (int k = 0; k < 2; k++) {
        residue_45 = (residue_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_45) & 127;
    }
    int scale_90 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_90 > 15) {
        acc = (acc + scale_90 * 2 + 5) & 127;
        aux ^= (scale_90 & 15);
    } else {
        acc = (acc - scale_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int residue_33 = 0;
    for (int k = 0; k < 3; k++) {
        residue_33 = (residue_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_33) & 127;
    }
    int weight_47 = (aux + st.buffer[1]) & 3;
    switch (weight_47) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_34 = local_arr[aux % 3];
    acc = (acc + bound_34 * 2) & 127;
    int parity_51 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_51 > 13) {
        acc = (acc + parity_51 * 2 + 5) & 127;
        aux ^= (parity_51 & 15);
    } else {
        acc = (acc - parity_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000645_0;
    int sec_r000645_1;
    int sec_r000645_2;
    int sec_r000645_3;
    int sec_r000645_4;
    int sec_r000645_5;
    int sec_r000645_6;
    int sec_r000645_7;
    int sec_r000645_8;
    int sec_r000645_9;
    int sec_r000645_10;
    int sec_r000645_11;
    int sec_r000645_12;
    int sec_r000645_13;
    int sec_r000645_14;
    int sec_r000645_15;
    int sec_r000645_16;
    int sec_r000645_17;
    int sec_r000645_18;
    int sec_r000645_19;
    int sec_r000645_20;
    int sec_r000645_21;
    int pub_r000645_0;
    int pub_r000645_1;
    int pub_r000645_2;
    int pub_r000645_3;
    int pub_r000645_4;
    int pub_r000645_5;
    int pub_r000645_6;
    int pub_r000645_7;
    int pub_r000645_8;
    int pub_r000645_9;
    int pub_r000645_10;
    int pub_r000645_11;
    int pub_r000645_12;
    int pub_r000645_13;
    int pub_r000645_14;
    int pub_r000645_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000645_0 >= -100 && pub_r000645_0 <= 100);
    __CPROVER_assume(pub_r000645_1 >= -100 && pub_r000645_1 <= 100);
    __CPROVER_assume(pub_r000645_2 >= -100 && pub_r000645_2 <= 100);
    __CPROVER_assume(pub_r000645_3 >= -100 && pub_r000645_3 <= 100);
    __CPROVER_assume(pub_r000645_4 >= -100 && pub_r000645_4 <= 100);
    __CPROVER_assume(pub_r000645_5 >= -100 && pub_r000645_5 <= 100);
    __CPROVER_assume(pub_r000645_6 >= -100 && pub_r000645_6 <= 100);
    __CPROVER_assume(pub_r000645_7 >= -100 && pub_r000645_7 <= 100);
    __CPROVER_assume(pub_r000645_8 >= -100 && pub_r000645_8 <= 100);
    __CPROVER_assume(pub_r000645_9 >= -100 && pub_r000645_9 <= 100);
    __CPROVER_assume(pub_r000645_10 >= -100 && pub_r000645_10 <= 100);
    __CPROVER_assume(pub_r000645_11 >= -100 && pub_r000645_11 <= 100);
    __CPROVER_assume(pub_r000645_12 >= -100 && pub_r000645_12 <= 100);
    __CPROVER_assume(pub_r000645_13 >= -100 && pub_r000645_13 <= 100);
    __CPROVER_assume(pub_r000645_14 >= -100 && pub_r000645_14 <= 100);
    __CPROVER_assume(pub_r000645_15 >= -100 && pub_r000645_15 <= 100);
    __CPROVER_assume(sec_r000645_0 >= 0 && sec_r000645_0 <= 255);
    __CPROVER_assume(sec_r000645_1 >= 0 && sec_r000645_1 <= 255);
    __CPROVER_assume(sec_r000645_2 >= 0 && sec_r000645_2 <= 255);
    __CPROVER_assume(sec_r000645_3 >= 0 && sec_r000645_3 <= 255);
    __CPROVER_assume(sec_r000645_4 >= 0 && sec_r000645_4 <= 255);
    __CPROVER_assume(sec_r000645_5 >= 0 && sec_r000645_5 <= 255);
    __CPROVER_assume(sec_r000645_6 >= 0 && sec_r000645_6 <= 255);
    __CPROVER_assume(sec_r000645_7 >= 0 && sec_r000645_7 <= 255);
    __CPROVER_assume(sec_r000645_8 >= 0 && sec_r000645_8 <= 255);
    __CPROVER_assume(sec_r000645_9 >= 0 && sec_r000645_9 <= 255);
    __CPROVER_assume(sec_r000645_10 >= 0 && sec_r000645_10 <= 255);
    __CPROVER_assume(sec_r000645_11 >= 0 && sec_r000645_11 <= 255);
    __CPROVER_assume(sec_r000645_12 >= 0 && sec_r000645_12 <= 255);
    __CPROVER_assume(sec_r000645_13 >= 0 && sec_r000645_13 <= 255);
    __CPROVER_assume(sec_r000645_14 >= 0 && sec_r000645_14 <= 255);
    __CPROVER_assume(sec_r000645_15 >= 0 && sec_r000645_15 <= 255);
    __CPROVER_assume(sec_r000645_16 >= 0 && sec_r000645_16 <= 255);
    __CPROVER_assume(sec_r000645_17 >= 0 && sec_r000645_17 <= 255);
    __CPROVER_assume(sec_r000645_18 >= 0 && sec_r000645_18 <= 255);
    __CPROVER_assume(sec_r000645_19 >= 0 && sec_r000645_19 <= 255);
    __CPROVER_assume(sec_r000645_20 >= 0 && sec_r000645_20 <= 255);
    __CPROVER_assume(sec_r000645_21 >= 0 && sec_r000645_21 <= 255);

    struct SensorNode_R000645_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000645_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000645_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000645_0 + 7) & 15;
    struct FilterState_R000645_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000645_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000645_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000645_0 + 9) & 15;
    struct MatrixBlock_R000645_4513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000645_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000645_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000645_0 + 11) & 15;

    union PacketPayload_R000645_4513_0 u_var;
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
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 19) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 34) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 37) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 52) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 40) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 55) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 22) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 37) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 16) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 31) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

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
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 10) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 25) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 12) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 27) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 29) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 44) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 14) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 29) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
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
    int stage_v_59 = (st_var_2.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 14) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 29) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 38) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 53) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 13) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 28) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 19) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 34) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 30) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 45) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 39) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] ^ 102) & 3;
    switch (stage_v_99) {
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

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 20) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 35) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 12) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 27) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 23) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 38) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 25) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 40) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_125 = (stage_v_125 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] * 2 + 385) & 63;
    if (stage_v_126 > 12) {
        out_sink = (out_sink + stage_v_126 - 5) & 255;
        if (stage_v_126 > 27) {
            chk_sum ^= (stage_v_126 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_126 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (out_sink > 100) ? (chk_sum & 31) : (136 & 31);
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= (stage_v_131 << 1) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 16) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 31) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_141 = (stage_v_141 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 12) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 27) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = table[1];
    table[1] = (table[2] + 307) & 63;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_1.buffer[1] * 2 + 487) & 63;
    if (stage_v_160 > 12) {
        out_sink = (out_sink + stage_v_160 - 5) & 255;
        if (stage_v_160 > 27) {
            chk_sum ^= (stage_v_160 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_160 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (out_sink > 100) ? (chk_sum & 31) : (167 & 31);
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= (stage_v_162 << 1) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 36) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 51) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] ^ 168) & 3;
    switch (stage_v_165) {
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

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 169) & 15;
    int stage_v_168 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= stage_v_168;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = table[3];
    table[3] = (table[0] + 343) & 63;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[1] * 2 + 532) & 63;
    if (stage_v_175 > 16) {
        out_sink = (out_sink + stage_v_175 - 5) & 255;
        if (stage_v_175 > 31) {
            chk_sum ^= (stage_v_175 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_175 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 176 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 179) & 15;
    int stage_v_178 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= stage_v_178;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = table[3];
    table[3] = (table[0] + 359) & 63;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (out_sink > 100) ? (chk_sum & 31) : (185 & 31);
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= (stage_v_180 << 1) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (out_sink > 100) ? (chk_sum & 31) : (187 & 31);
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= (stage_v_182 << 1) & 127;

    /* Execution Pipeline Stage 183 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 184) & 15;
    int stage_v_183 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= stage_v_183;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_185 = (stage_v_185 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_185) & 127;
    }
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (out_sink > 100) ? (chk_sum & 31) : (191 & 31);
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= (stage_v_186 << 1) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[1] * 2 + 568) & 63;
    if (stage_v_187 > 10) {
        out_sink = (out_sink + stage_v_187 - 5) & 255;
        if (stage_v_187 > 25) {
            chk_sum ^= (stage_v_187 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_187 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_189 = (stage_v_189 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_189) & 127;
    }
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_190 = (stage_v_190 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_190) & 127;
    }
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 192) & 15;
    int stage_v_191 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= stage_v_191;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] ^ 195) & 3;
    switch (stage_v_192) {
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

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_2.buffer[0] ^ 197) & 3;
    switch (stage_v_194) {
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

    /* Execution Pipeline Stage 195 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 196) & 15;
    int stage_v_195 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    chk_sum ^= stage_v_195;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_1.buffer[1] * 2 + 595) & 63;
    if (stage_v_196 > 24) {
        out_sink = (out_sink + stage_v_196 - 5) & 255;
        if (stage_v_196 > 39) {
            chk_sum ^= (stage_v_196 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_196 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 197 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 198) & 15;
    int stage_v_197 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    chk_sum ^= stage_v_197;

    /* Security Information Flow: Family = nested_implicit_flow */
    if ((sec_r000645_2 & 1) != 0) {
        if ((sec_r000645_5 & 2) != 0) {
            out_sink += 41;
        } else {
            out_sink += 17;
        }
    } else {
        if ((sec_r000645_12 & 4) != 0) {
            out_sink -= 23;
        } else {
            out_sink -= 51;
        }
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
