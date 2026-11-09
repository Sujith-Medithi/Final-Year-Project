/*
 * Benchmark Program: R001140
 * Security Family: mixed_control_data
 * Generator Seed: 614013
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001140_4013_0 {
    int seq;
    unsigned char code;
    int timestamp;
    int buffer[3];
};

struct MatrixBlock_R001140_4013_1 {
    unsigned char density;
    unsigned char stride;
    unsigned char determinant;
    int buffer[3];
};

struct Vector3D_R001140_4013_2 {
    short coord_z;
    unsigned char coord_y;
    short coord_x;
    unsigned char heading;
    int norm_sq;
    int buffer[3];
};

struct CipherContext_R001140_4013_3 {
    int counter;
    int iv;
    short tag;
    int buffer[3];
};

union ColorPixel_R001140_4013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001140_4013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001140_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_70 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_70 > 24) {
        acc = (acc + residue_70 * 2 + 5) & 127;
        aux ^= (residue_70 & 15);
    } else {
        acc = (acc - residue_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_69 = local_arr[aux % 3];
    acc = (acc + factor_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001140_4013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_58 = 0;
    for (int k = 0; k < 2; k++) {
        segment_58 = (segment_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_58) & 127;
    }
    int vector_56 = (aux + st.buffer[1]) & 3;
    switch (vector_56) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_27 = local_arr[aux % 3];
    acc = (acc + pivot_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001140_4013_2(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001140_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_80) & 63;
    acc ^= aux;
    int accumulator_43 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_43 > 21) {
        acc = (acc + accumulator_43 * 2 + 5) & 127;
        aux ^= (accumulator_43 & 15);
    } else {
        acc = (acc - accumulator_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001140_4013_3(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001140_4013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_83 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_83 = (tracker_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_83) & 127;
    }
    int segment_85 = (aux + st.buffer[1]) & 3;
    switch (segment_85) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_36 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_36 > 39) {
        acc = (acc + margin_36 * 2 + 5) & 127;
        aux ^= (margin_36 & 15);
    } else {
        acc = (acc - margin_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001140_4013_4(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_95 = 0;
    for (int k = 0; k < 3; k++) {
        tally_95 = (tally_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_95) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_14 = local_arr[aux % 3];
    acc = (acc + weight_14 * 2) & 127;
    int mask_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_38) & 63;
    acc ^= aux;
    int scale_70 = (aux + st.buffer[1]) & 3;
    switch (scale_70) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_91 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_91 > 12) {
        acc = (acc + tracker_91 * 2 + 5) & 127;
        aux ^= (tracker_91 & 15);
    } else {
        acc = (acc - tracker_91 + 11) & 127;
        aux += 3;
    }
    int delta_21 = (aux + st.buffer[1]) & 3;
    switch (delta_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_22) & 63;
    acc ^= aux;
    int mask_68 = 0;
    for (int k = 0; k < 3; k++) {
        mask_68 = (mask_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_68) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_6(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_43 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_43 > 35) {
        acc = (acc + residue_43 * 2 + 5) & 127;
        aux ^= (residue_43 & 15);
    } else {
        acc = (acc - residue_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_15 = (aux + st.buffer[1]) & 3;
    switch (bound_15) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_7(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_98 = (aux + st.buffer[1]) & 3;
    switch (anchor_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_81 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_81 > 34) {
        acc = (acc + tally_81 * 2 + 5) & 127;
        aux ^= (tally_81 & 15);
    } else {
        acc = (acc - tally_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_8(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001140_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int segment_50 = (aux + st.buffer[1]) & 3;
    switch (segment_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_74 = 0;
    for (int k = 0; k < 2; k++) {
        bound_74 = (bound_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_74) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_44 = local_arr[aux % 3];
    acc = (acc + metric_44 * 2) & 127;
    int margin_15 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_15 > 23) {
        acc = (acc + margin_15 * 2 + 5) & 127;
        aux ^= (margin_15 & 15);
    } else {
        acc = (acc - margin_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001140_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_10 = 0;
    for (int k = 0; k < 2; k++) {
        bound_10 = (bound_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_10) & 127;
    }
    int tracker_94 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_94 > 40) {
        acc = (acc + tracker_94 * 2 + 5) & 127;
        aux ^= (tracker_94 & 15);
    } else {
        acc = (acc - tracker_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_10(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001140_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_24 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_24 = (quotient_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_24) & 127;
    }
    int window_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_86) & 63;
    acc ^= aux;
    int tracker_33 = (aux + st.buffer[1]) & 3;
    switch (tracker_33) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_73 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_73 > 15) {
        acc = (acc + mask_73 * 2 + 5) & 127;
        aux ^= (mask_73 & 15);
    } else {
        acc = (acc - mask_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_11(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001140_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int coefficient_41 = local_arr[aux % 3];
    acc = (acc + coefficient_41 * 2) & 127;
    int margin_90 = 0;
    for (int k = 0; k < 2; k++) {
        margin_90 = (margin_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_90) & 127;
    }
    int scale_37 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_37 > 30) {
        acc = (acc + scale_37 * 2 + 5) & 127;
        aux ^= (scale_37 & 15);
    } else {
        acc = (acc - scale_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_12(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001140_4013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_59 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_59 > 22) {
        acc = (acc + tally_59 * 2 + 5) & 127;
        aux ^= (tally_59 & 15);
    } else {
        acc = (acc - tally_59 + 11) & 127;
        aux += 3;
    }
    int threshold_54 = (aux + st.buffer[1]) & 3;
    switch (threshold_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_77 = local_arr[aux % 3];
    acc = (acc + anchor_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001140_4013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001140_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int window_34 = 0;
    for (int k = 0; k < 2; k++) {
        window_34 = (window_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_34) & 127;
    }
    int weight_32 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_32 > 21) {
        acc = (acc + weight_32 * 2 + 5) & 127;
        aux ^= (weight_32 & 15);
    } else {
        acc = (acc - weight_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_14(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001140_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_84 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_84 > 44) {
        acc = (acc + index_reg_84 * 2 + 5) & 127;
        aux ^= (index_reg_84 & 15);
    } else {
        acc = (acc - index_reg_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001140_4013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001140_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_36) & 63;
    acc ^= aux;
    int parity_21 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_21 > 14) {
        acc = (acc + parity_21 * 2 + 5) & 127;
        aux ^= (parity_21 & 15);
    } else {
        acc = (acc - parity_21 + 11) & 127;
        aux += 3;
    }
    int stride_41 = (aux + st.buffer[1]) & 3;
    switch (stride_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001140_0;
    int sec_r001140_1;
    int sec_r001140_2;
    int sec_r001140_3;
    int sec_r001140_4;
    int sec_r001140_5;
    int sec_r001140_6;
    int sec_r001140_7;
    int sec_r001140_8;
    int sec_r001140_9;
    int sec_r001140_10;
    int sec_r001140_11;
    int sec_r001140_12;
    int sec_r001140_13;
    int sec_r001140_14;
    int sec_r001140_15;
    int sec_r001140_16;
    int sec_r001140_17;
    int sec_r001140_18;
    int sec_r001140_19;
    int pub_r001140_0;
    int pub_r001140_1;
    int pub_r001140_2;
    int pub_r001140_3;
    int pub_r001140_4;
    int pub_r001140_5;
    int pub_r001140_6;
    int pub_r001140_7;
    int pub_r001140_8;
    int pub_r001140_9;
    int pub_r001140_10;
    int pub_r001140_11;
    int pub_r001140_12;
    int pub_r001140_13;
    int pub_r001140_14;
    int pub_r001140_15;
    int pub_r001140_16;
    int pub_r001140_17;
    int pub_r001140_18;
    int pub_r001140_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001140_0 >= -100 && pub_r001140_0 <= 100);
    __CPROVER_assume(pub_r001140_1 >= -100 && pub_r001140_1 <= 100);
    __CPROVER_assume(pub_r001140_2 >= -100 && pub_r001140_2 <= 100);
    __CPROVER_assume(pub_r001140_3 >= -100 && pub_r001140_3 <= 100);
    __CPROVER_assume(pub_r001140_4 >= -100 && pub_r001140_4 <= 100);
    __CPROVER_assume(pub_r001140_5 >= -100 && pub_r001140_5 <= 100);
    __CPROVER_assume(pub_r001140_6 >= -100 && pub_r001140_6 <= 100);
    __CPROVER_assume(pub_r001140_7 >= -100 && pub_r001140_7 <= 100);
    __CPROVER_assume(pub_r001140_8 >= -100 && pub_r001140_8 <= 100);
    __CPROVER_assume(pub_r001140_9 >= -100 && pub_r001140_9 <= 100);
    __CPROVER_assume(pub_r001140_10 >= -100 && pub_r001140_10 <= 100);
    __CPROVER_assume(pub_r001140_11 >= -100 && pub_r001140_11 <= 100);
    __CPROVER_assume(pub_r001140_12 >= -100 && pub_r001140_12 <= 100);
    __CPROVER_assume(pub_r001140_13 >= -100 && pub_r001140_13 <= 100);
    __CPROVER_assume(pub_r001140_14 >= -100 && pub_r001140_14 <= 100);
    __CPROVER_assume(pub_r001140_15 >= -100 && pub_r001140_15 <= 100);
    __CPROVER_assume(pub_r001140_16 >= -100 && pub_r001140_16 <= 100);
    __CPROVER_assume(pub_r001140_17 >= -100 && pub_r001140_17 <= 100);
    __CPROVER_assume(pub_r001140_18 >= -100 && pub_r001140_18 <= 100);
    __CPROVER_assume(pub_r001140_19 >= -100 && pub_r001140_19 <= 100);
    __CPROVER_assume(sec_r001140_0 >= 0 && sec_r001140_0 <= 255);
    __CPROVER_assume(sec_r001140_1 >= 0 && sec_r001140_1 <= 255);
    __CPROVER_assume(sec_r001140_2 >= 0 && sec_r001140_2 <= 255);
    __CPROVER_assume(sec_r001140_3 >= 0 && sec_r001140_3 <= 255);
    __CPROVER_assume(sec_r001140_4 >= 0 && sec_r001140_4 <= 255);
    __CPROVER_assume(sec_r001140_5 >= 0 && sec_r001140_5 <= 255);
    __CPROVER_assume(sec_r001140_6 >= 0 && sec_r001140_6 <= 255);
    __CPROVER_assume(sec_r001140_7 >= 0 && sec_r001140_7 <= 255);
    __CPROVER_assume(sec_r001140_8 >= 0 && sec_r001140_8 <= 255);
    __CPROVER_assume(sec_r001140_9 >= 0 && sec_r001140_9 <= 255);
    __CPROVER_assume(sec_r001140_10 >= 0 && sec_r001140_10 <= 255);
    __CPROVER_assume(sec_r001140_11 >= 0 && sec_r001140_11 <= 255);
    __CPROVER_assume(sec_r001140_12 >= 0 && sec_r001140_12 <= 255);
    __CPROVER_assume(sec_r001140_13 >= 0 && sec_r001140_13 <= 255);
    __CPROVER_assume(sec_r001140_14 >= 0 && sec_r001140_14 <= 255);
    __CPROVER_assume(sec_r001140_15 >= 0 && sec_r001140_15 <= 255);
    __CPROVER_assume(sec_r001140_16 >= 0 && sec_r001140_16 <= 255);
    __CPROVER_assume(sec_r001140_17 >= 0 && sec_r001140_17 <= 255);
    __CPROVER_assume(sec_r001140_18 >= 0 && sec_r001140_18 <= 255);
    __CPROVER_assume(sec_r001140_19 >= 0 && sec_r001140_19 <= 255);

    struct EventLog_R001140_4013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001140_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001140_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001140_0 + 7) & 15;
    struct MatrixBlock_R001140_4013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001140_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001140_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001140_0 + 9) & 15;
    struct Vector3D_R001140_4013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001140_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001140_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001140_0 + 11) & 15;
    struct CipherContext_R001140_4013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001140_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001140_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001140_0 + 13) & 15;

    union ColorPixel_R001140_4013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001140_4013_0(sec_r001140_0, pub_r001140_1, pub_r001140_2, pub_r001140_3);
    int helper_flow_1 = fn_R001140_4013_1(sec_r001140_1, sec_r001140_2, pub_r001140_3, pub_r001140_4, pub_r001140_5);
    int helper_flow_2 = fn_R001140_4013_2(sec_r001140_2, pub_r001140_3);
    int helper_flow_3 = fn_R001140_4013_3(sec_r001140_3, pub_r001140_4, pub_r001140_5);
    int helper_flow_4 = fn_R001140_4013_4(sec_r001140_4, sec_r001140_5, pub_r001140_6);
    int helper_flow_5 = fn_R001140_4013_5(sec_r001140_5, pub_r001140_6, pub_r001140_7, pub_r001140_8);
    int helper_flow_6 = fn_R001140_4013_6(sec_r001140_6, sec_r001140_7, pub_r001140_8);
    int helper_flow_7 = fn_R001140_4013_7(sec_r001140_7, sec_r001140_8, pub_r001140_9);
    int helper_flow_8 = fn_R001140_4013_8(sec_r001140_8, pub_r001140_9);
    int helper_flow_9 = fn_R001140_4013_9(sec_r001140_9, sec_r001140_10, pub_r001140_11, pub_r001140_12, pub_r001140_13);
    int helper_flow_10 = fn_R001140_4013_10(sec_r001140_10, sec_r001140_11, pub_r001140_12);
    int helper_flow_11 = fn_R001140_4013_11(sec_r001140_11, sec_r001140_12, pub_r001140_13);
    int helper_flow_12 = fn_R001140_4013_12(sec_r001140_12, sec_r001140_13, pub_r001140_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001140_7 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_0 > 36) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001140_6 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_1 > 50) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_2 > 22) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001140_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001140_16 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_4 > 29) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001140_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001140_16 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_6 > 39) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001140_7 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_7 > 48) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001140_4 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_8 > 27) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001140_17 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_9 > 49) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001140_15 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_10 > 39) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001140_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_12 > 22) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001140_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001140_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001140_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_16 > 48) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001140_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_18 > 47) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001140_7 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_19 > 23) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_20 > 35) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001140_13 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_21 > 27) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001140_18 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_22 > 28) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001140_19 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_23 > 45) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001140_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_25 > 29) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_26 > 25) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_27 > 26) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_28 > 33) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_29 > 29) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001140_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001140_11 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_31 > 26) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_32 > 28) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001140_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_34 > 31) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001140_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_36 > 35) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_37 > 29) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_38 > 26) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001140_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_40 > 48) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001140_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_42 > 36) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_43 > 23) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001140_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001140_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001140_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001140_16 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_47 > 28) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001140_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_49 > 49) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001140_2 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_50 > 43) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_51 > 27) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_52 > 48) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_53 > 30) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_54 > 45) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_55 > 26) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001140_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_57 > 45) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001140_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_59 > 37) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001140_15 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_60 > 26) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001140_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_62 > 44) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001140_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_64 > 21) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001140_8 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_65 > 36) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001140_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001140_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001140_0 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_68 > 25) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001140_9 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_69 > 44) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_70 > 34) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001140_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_72 > 27) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001140_10 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_73 > 34) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_74 > 47) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001140_3 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_75 > 20) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_76 > 27) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001140_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_78 > 32) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001140_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_80 > 39) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_81 > 46) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_82 > 38) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001140_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001140_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_86 > 33) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_87 > 41) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001140_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_89 > 32) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001140_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001140_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_92 > 29) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_93 > 38) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_94 > 37) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_95 > 43) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_96 > 47) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001140_12 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_97 > 44) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_98 > 29) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_99 > 25) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001140_14 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_100 > 50) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_101 > 45) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_102 > 22) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_103 > 49) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_104 > 48) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_105 > 36) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_106 > 35) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_107 > 42) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_108 > 35) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001140_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_110 > 43) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001140_7 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_111 > 37) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_112 > 28) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_113 > 27) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001140_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001140_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001140_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_117 > 36) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001140_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_119 > 31) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001140_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001140_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_122 > 50) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_123 > 24) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_124 > 27) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_125 > 49) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_126 > 37) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_127 > 37) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001140_3 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_128 > 30) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_129 > 22) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_130 > 43) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_131 > 44) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_132 > 41) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_133 > 46) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_134 > 23) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_135 > 37) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001140_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_137 > 45) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_138 > 47) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001140_1 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_139 > 45) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_140 > 31) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001140_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_142 > 25) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_144 > 26) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_145 > 44) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001140_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_147 > 27) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_148 > 30) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_150 > 32) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_151 > 40) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001140_7 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_152 > 50) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_153 > 35) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_154 > 41) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_155 > 50) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_156 > 33) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_157 > 48) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001140_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_159 > 20) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001140_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_161 > 44) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_162 > 20) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001140_16 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_163 > 40) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001140_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_166 > 40) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001140_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001140_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_170 > 28) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_171 > 48) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_172 > 39) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001140_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_174 > 36) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001140_17 ^ 0x2A) * 2 + pub_r001140_17) & 127;
    if (stage_v_175 > 36) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001140_8 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_176 > 44) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_177 > 47) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_178 > 32) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_179 > 34) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001140_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_181 > 50) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_182 > 47) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001140_6 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_183 > 27) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_184 > 25) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_185 > 42) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001140_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_187 > 33) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_188 > 42) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001140_9) & 127;
    if (stage_v_189 > 26) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_190 > 48) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001140_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001140_4) & 127;
    if (stage_v_192 > 36) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001140_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_194 > 31) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_195 > 24) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_196 > 23) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_197 > 25) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001140_1) & 127;
    if (stage_v_198 > 46) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_199 > 29) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001140_10) & 127;
    if (stage_v_200 > 35) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001140_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001140_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_203 > 38) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001140_12) & 127;
    if (stage_v_204 > 39) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001140_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_206 > 37) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001140_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_208 > 37) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001140_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_210 > 22) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001140_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_212 > 40) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_213 > 24) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_214 > 35) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_215 > 25) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001140_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_217 > 35) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001140_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001140_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_220 > 48) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_221 > 44) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_222 > 43) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001140_4 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_223 > 40) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001140_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001140_5) & 127;
    if (stage_v_225 > 25) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_226 > 27) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_227 > 35) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_228 > 43) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_229 > 21) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001140_16) & 127;
    if (stage_v_230 > 46) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001140_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_232 > 27) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_233 > 24) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001140_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_235 > 23) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_196 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_236 > 36) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_237 > 25) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_238 > 47) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001140_8) & 127;
    if (stage_v_239 > 27) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r001140_8 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_240 > 21) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r001140_17 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_241 > 48) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001140_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001140_3) & 127;
    if (stage_v_243 > 24) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001140_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001140_0) & 127;
    if (stage_v_245 > 32) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_246 > 23) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_247 > 36) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_248 > 29) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001140_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001140_18) & 127;
    if (stage_v_250 > 33) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001140_6) & 127;
    if (stage_v_251 > 23) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001140_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_253 > 41) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_254 > 31) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_255 > 21) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r001140_19 ^ 0x2A) * 2 + pub_r001140_7) & 127;
    if (stage_v_256 > 25) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001140_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001140_2) & 127;
    if (stage_v_258 > 48) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001140_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001140_11) & 127;
    if (stage_v_260 > 37) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001140_13) & 127;
    if (stage_v_261 > 28) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001140_14) & 127;
    if (stage_v_262 > 46) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001140_15) & 127;
    if (stage_v_263 > 45) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001140_19) & 127;
    if (stage_v_264 > 27) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
