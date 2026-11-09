/*
 * Benchmark Program: R001047
 * Security Family: nested_implicit_flow
 * Generator Seed: 604713
 * High Inputs: 20 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001047_4713_0 {
    int balance;
    int status;
    short fee;
    short account_id;
    short rate;
    int buffer[3];
};

struct MatrixBlock_R001047_4713_1 {
    int density;
    unsigned char scale;
    int dim;
    unsigned char trace;
    int determinant;
    short stride;
    int buffer[3];
};

union TelemetryField_R001047_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001047_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001047_4713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_83 = local_arr[aux % 3];
    acc = (acc + accumulator_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_11 = (aux + st.buffer[1]) & 3;
    switch (segment_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_64 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_64 > 40) {
        acc = (acc + quotient_64 * 2 + 5) & 127;
        aux ^= (quotient_64 & 15);
    } else {
        acc = (acc - quotient_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_2(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int sample_86 = local_arr[aux % 3];
    acc = (acc + sample_86 * 2) & 127;
    int weight_55 = (aux + st.buffer[1]) & 3;
    switch (weight_55) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001047_4713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_23) & 63;
    acc ^= aux;
    int metric_69 = (aux + st.buffer[1]) & 3;
    switch (metric_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int stride_17 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_17 > 19) {
        acc = (acc + stride_17 * 2 + 5) & 127;
        aux ^= (stride_17 & 15);
    } else {
        acc = (acc - stride_17 + 11) & 127;
        aux += 3;
    }
    int quotient_48 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_48 = (quotient_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_48) & 127;
    }
    int window_32 = (aux + st.buffer[1]) & 3;
    switch (window_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int phase_40 = local_arr[aux % 3];
    acc = (acc + phase_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_46) & 63;
    acc ^= aux;
    int offset_26 = 0;
    for (int k = 0; k < 3; k++) {
        offset_26 = (offset_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_20 = local_arr[aux % 3];
    acc = (acc + quotient_20 * 2) & 127;
    int weight_25 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_25 > 29) {
        acc = (acc + weight_25 * 2 + 5) & 127;
        aux ^= (weight_25 & 15);
    } else {
        acc = (acc - weight_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int offset_66 = local_arr[aux % 3];
    acc = (acc + offset_66 * 2) & 127;
    int quotient_60 = (aux + st.buffer[1]) & 3;
    switch (quotient_60) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_38) & 63;
    acc ^= aux;
    int sample_71 = 0;
    for (int k = 0; k < 2; k++) {
        sample_71 = (sample_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_8(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_37 = (aux + st.buffer[1]) & 3;
    switch (mask_37) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_28 = local_arr[aux % 3];
    acc = (acc + phase_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int index_reg_65 = local_arr[aux % 3];
    acc = (acc + index_reg_65 * 2) & 127;
    int mask_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_32 = (aux + st.buffer[1]) & 3;
    switch (delta_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_78 = 0;
    for (int k = 0; k < 3; k++) {
        window_78 = (window_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_11(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_12 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_12 > 23) {
        acc = (acc + segment_12 * 2 + 5) & 127;
        aux ^= (segment_12 & 15);
    } else {
        acc = (acc - segment_12 + 11) & 127;
        aux += 3;
    }
    int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_76 = local_arr[aux % 3];
    acc = (acc + quotient_76 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_27 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_27 > 47) {
        acc = (acc + residue_27 * 2 + 5) & 127;
        aux ^= (residue_27 & 15);
    } else {
        acc = (acc - residue_27 + 11) & 127;
        aux += 3;
    }
    int scale_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_27) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_57 = local_arr[aux % 3];
    acc = (acc + sample_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_13(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int coefficient_52 = local_arr[aux % 3];
    acc = (acc + coefficient_52 * 2) & 127;
    int tracker_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_39) & 63;
    acc ^= aux;
    int margin_25 = (aux + st.buffer[1]) & 3;
    switch (margin_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_21 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_21 = (accumulator_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001047_4713_14(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_23 = local_arr[aux % 3];
    acc = (acc + segment_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001047_4713_15(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tracker_42 = local_arr[aux % 3];
    acc = (acc + tracker_42 * 2) & 127;
    int weight_35 = 0;
    for (int k = 0; k < 2; k++) {
        weight_35 = (weight_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_35) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_18 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_18 > 23) {
        acc = (acc + pivot_18 * 2 + 5) & 127;
        aux ^= (pivot_18 & 15);
    } else {
        acc = (acc - pivot_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001047_0;
    int sec_r001047_1;
    int sec_r001047_2;
    int sec_r001047_3;
    int sec_r001047_4;
    int sec_r001047_5;
    int sec_r001047_6;
    int sec_r001047_7;
    int sec_r001047_8;
    int sec_r001047_9;
    int sec_r001047_10;
    int sec_r001047_11;
    int sec_r001047_12;
    int sec_r001047_13;
    int sec_r001047_14;
    int sec_r001047_15;
    int sec_r001047_16;
    int sec_r001047_17;
    int sec_r001047_18;
    int sec_r001047_19;
    int pub_r001047_0;
    int pub_r001047_1;
    int pub_r001047_2;
    int pub_r001047_3;
    int pub_r001047_4;
    int pub_r001047_5;
    int pub_r001047_6;
    int pub_r001047_7;
    int pub_r001047_8;
    int pub_r001047_9;
    int pub_r001047_10;
    int pub_r001047_11;
    int pub_r001047_12;
    int pub_r001047_13;
    int pub_r001047_14;
    int pub_r001047_15;
    int pub_r001047_16;
    int pub_r001047_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001047_0 >= -100 && pub_r001047_0 <= 100);
    __CPROVER_assume(pub_r001047_1 >= -100 && pub_r001047_1 <= 100);
    __CPROVER_assume(pub_r001047_2 >= -100 && pub_r001047_2 <= 100);
    __CPROVER_assume(pub_r001047_3 >= -100 && pub_r001047_3 <= 100);
    __CPROVER_assume(pub_r001047_4 >= -100 && pub_r001047_4 <= 100);
    __CPROVER_assume(pub_r001047_5 >= -100 && pub_r001047_5 <= 100);
    __CPROVER_assume(pub_r001047_6 >= -100 && pub_r001047_6 <= 100);
    __CPROVER_assume(pub_r001047_7 >= -100 && pub_r001047_7 <= 100);
    __CPROVER_assume(pub_r001047_8 >= -100 && pub_r001047_8 <= 100);
    __CPROVER_assume(pub_r001047_9 >= -100 && pub_r001047_9 <= 100);
    __CPROVER_assume(pub_r001047_10 >= -100 && pub_r001047_10 <= 100);
    __CPROVER_assume(pub_r001047_11 >= -100 && pub_r001047_11 <= 100);
    __CPROVER_assume(pub_r001047_12 >= -100 && pub_r001047_12 <= 100);
    __CPROVER_assume(pub_r001047_13 >= -100 && pub_r001047_13 <= 100);
    __CPROVER_assume(pub_r001047_14 >= -100 && pub_r001047_14 <= 100);
    __CPROVER_assume(pub_r001047_15 >= -100 && pub_r001047_15 <= 100);
    __CPROVER_assume(pub_r001047_16 >= -100 && pub_r001047_16 <= 100);
    __CPROVER_assume(pub_r001047_17 >= -100 && pub_r001047_17 <= 100);
    __CPROVER_assume(sec_r001047_0 >= 0 && sec_r001047_0 <= 255);
    __CPROVER_assume(sec_r001047_1 >= 0 && sec_r001047_1 <= 255);
    __CPROVER_assume(sec_r001047_2 >= 0 && sec_r001047_2 <= 255);
    __CPROVER_assume(sec_r001047_3 >= 0 && sec_r001047_3 <= 255);
    __CPROVER_assume(sec_r001047_4 >= 0 && sec_r001047_4 <= 255);
    __CPROVER_assume(sec_r001047_5 >= 0 && sec_r001047_5 <= 255);
    __CPROVER_assume(sec_r001047_6 >= 0 && sec_r001047_6 <= 255);
    __CPROVER_assume(sec_r001047_7 >= 0 && sec_r001047_7 <= 255);
    __CPROVER_assume(sec_r001047_8 >= 0 && sec_r001047_8 <= 255);
    __CPROVER_assume(sec_r001047_9 >= 0 && sec_r001047_9 <= 255);
    __CPROVER_assume(sec_r001047_10 >= 0 && sec_r001047_10 <= 255);
    __CPROVER_assume(sec_r001047_11 >= 0 && sec_r001047_11 <= 255);
    __CPROVER_assume(sec_r001047_12 >= 0 && sec_r001047_12 <= 255);
    __CPROVER_assume(sec_r001047_13 >= 0 && sec_r001047_13 <= 255);
    __CPROVER_assume(sec_r001047_14 >= 0 && sec_r001047_14 <= 255);
    __CPROVER_assume(sec_r001047_15 >= 0 && sec_r001047_15 <= 255);
    __CPROVER_assume(sec_r001047_16 >= 0 && sec_r001047_16 <= 255);
    __CPROVER_assume(sec_r001047_17 >= 0 && sec_r001047_17 <= 255);
    __CPROVER_assume(sec_r001047_18 >= 0 && sec_r001047_18 <= 255);
    __CPROVER_assume(sec_r001047_19 >= 0 && sec_r001047_19 <= 255);

    struct Transaction_R001047_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001047_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001047_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001047_0 + 7) & 15;
    struct MatrixBlock_R001047_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001047_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001047_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001047_0 + 9) & 15;

    union TelemetryField_R001047_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001047_4713_0(sec_r001047_0, sec_r001047_1, pub_r001047_2, pub_r001047_3);
    int helper_flow_1 = fn_R001047_4713_1(sec_r001047_1, sec_r001047_2, pub_r001047_3, pub_r001047_4);
    int helper_flow_2 = fn_R001047_4713_2(sec_r001047_2, sec_r001047_3);
    int helper_flow_3 = fn_R001047_4713_3(sec_r001047_3, pub_r001047_4, pub_r001047_5, pub_r001047_6);
    int helper_flow_4 = fn_R001047_4713_4(sec_r001047_4, sec_r001047_5, pub_r001047_6, pub_r001047_7, pub_r001047_8);
    int helper_flow_5 = fn_R001047_4713_5(sec_r001047_5, pub_r001047_6, pub_r001047_7, pub_r001047_8);
    int helper_flow_6 = fn_R001047_4713_6(sec_r001047_6, pub_r001047_7, pub_r001047_8, pub_r001047_9);
    int helper_flow_7 = fn_R001047_4713_7(sec_r001047_7, sec_r001047_8, pub_r001047_9, pub_r001047_10);
    int helper_flow_8 = fn_R001047_4713_8(sec_r001047_8, sec_r001047_9);
    int helper_flow_9 = fn_R001047_4713_9(sec_r001047_9, pub_r001047_10, pub_r001047_11, pub_r001047_12, pub_r001047_13);
    int helper_flow_10 = fn_R001047_4713_10(sec_r001047_10, pub_r001047_11, pub_r001047_12, pub_r001047_13, pub_r001047_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001047_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001047_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001047_19 ^ pub_r001047_9) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001047_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001047_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001047_13 ^ pub_r001047_4) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001047_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001047_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001047_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001047_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001047_13 ^ pub_r001047_5) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001047_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001047_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001047_13 ^ pub_r001047_16) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001047_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_1 ^ pub_r001047_4) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001047_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001047_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001047_19 ^ pub_r001047_13) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001047_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_5 ^ pub_r001047_5) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001047_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001047_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001047_0 ^ pub_r001047_1) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001047_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_10 ^ pub_r001047_4) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001047_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_9 ^ pub_r001047_8) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001047_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001047_8 ^ pub_r001047_13) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_10 ^ pub_r001047_5) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001047_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001047_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001047_3 ^ pub_r001047_12) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r001047_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_4 ^ pub_r001047_17) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (helper_flow_5 ^ pub_r001047_9) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001047_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001047_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001047_14 ^ pub_r001047_0) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001047_6 ^ pub_r001047_17) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001047_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_7 ^ pub_r001047_15) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001047_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_31 ^ pub_r001047_0) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001047_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001047_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001047_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_12 ^ pub_r001047_13) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001047_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001047_12 ^ pub_r001047_4) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001047_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_3 ^ pub_r001047_12) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001047_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001047_1 ^ pub_r001047_9) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_23 ^ pub_r001047_9) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001047_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001047_16 ^ pub_r001047_10) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001047_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_19 ^ pub_r001047_6) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001047_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001047_1 ^ pub_r001047_11) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r001047_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001047_12 ^ pub_r001047_1) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001047_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_37 ^ pub_r001047_4) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r001047_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001047_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_47 ^ pub_r001047_12) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001047_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001047_7 ^ pub_r001047_3) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001047_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_4 ^ pub_r001047_0) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001047_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001047_9 ^ pub_r001047_3) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001047_10 ^ pub_r001047_0) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_22 ^ pub_r001047_6) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_47 ^ pub_r001047_5) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001047_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001047_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_2 ^ pub_r001047_15) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001047_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_59 ^ pub_r001047_1) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001047_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001047_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001047_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001047_8 ^ pub_r001047_0) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001047_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001047_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001047_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001047_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001047_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001047_3 ^ pub_r001047_17) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001047_7 ^ pub_r001047_13) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001047_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_27 ^ pub_r001047_0) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001047_10 ^ pub_r001047_0) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_59 ^ pub_r001047_4) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_30 ^ pub_r001047_7) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_0 ^ pub_r001047_3) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r001047_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001047_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (helper_flow_10 ^ pub_r001047_8) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_42 ^ pub_r001047_3) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_43 ^ pub_r001047_0) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_37 ^ pub_r001047_16) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001047_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001047_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_0 ^ pub_r001047_16) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r001047_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001047_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001047_1 ^ pub_r001047_8) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (helper_flow_3 ^ pub_r001047_12) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_9 ^ pub_r001047_17) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001047_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001047_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_83 ^ pub_r001047_7) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_7 ^ pub_r001047_4) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (helper_flow_9 ^ pub_r001047_17) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001047_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001047_16 ^ pub_r001047_7) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r001047_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_7 ^ pub_r001047_11) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001047_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001047_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001047_0 ^ pub_r001047_13) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001047_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001047_1 ^ pub_r001047_14) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_92 ^ pub_r001047_16) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001047_5 ^ pub_r001047_6) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001047_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001047_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_3 ^ pub_r001047_0) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001047_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_39 ^ pub_r001047_7) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r001047_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_5 ^ pub_r001047_6) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_48 ^ pub_r001047_10) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r001047_16 ^ pub_r001047_4) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_57 ^ pub_r001047_7) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r001047_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001047_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_28 ^ pub_r001047_13) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001047_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001047_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_26 ^ pub_r001047_15) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001047_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001047_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_59 ^ pub_r001047_3) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001047_3 ^ pub_r001047_14) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001047_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001047_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001047_16 ^ pub_r001047_15) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_122 ^ pub_r001047_13) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r001047_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_105 ^ pub_r001047_16) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r001047_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_118 ^ pub_r001047_4) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_101 ^ pub_r001047_4) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001047_3 ^ pub_r001047_15) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_54 ^ pub_r001047_7) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_128 ^ pub_r001047_6) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001047_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_78 ^ pub_r001047_14) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_90 ^ pub_r001047_6) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_91 ^ pub_r001047_17) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001047_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001047_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001047_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_135 ^ pub_r001047_16) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001047_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_9 ^ pub_r001047_10) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_48 ^ pub_r001047_3) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001047_0 ^ pub_r001047_11) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_64 ^ pub_r001047_1) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_94 ^ pub_r001047_17) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001047_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_140 ^ pub_r001047_6) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001047_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_104 ^ pub_r001047_4) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001047_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_96 ^ pub_r001047_17) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_54 ^ pub_r001047_2) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r001047_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001047_19 ^ pub_r001047_15) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_42 ^ pub_r001047_4) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r001047_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_33 ^ pub_r001047_17) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_140 ^ pub_r001047_4) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001047_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001047_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_8 ^ pub_r001047_17) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001047_0 ^ pub_r001047_10) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001047_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_108 ^ pub_r001047_17) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001047_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_73 ^ pub_r001047_13) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((sec_r001047_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_46 ^ pub_r001047_7) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((sec_r001047_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_43 ^ pub_r001047_12) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001047_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (helper_flow_10 ^ pub_r001047_12) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001047_2 ^ pub_r001047_1) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001047_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_170 ^ pub_r001047_12) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001047_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001047_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001047_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_148 ^ pub_r001047_7) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((sec_r001047_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_2 ^ pub_r001047_7) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001047_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001047_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001047_12 ^ pub_r001047_7) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_46 ^ pub_r001047_16) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((sec_r001047_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001047_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001047_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_21 ^ pub_r001047_5) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_127 ^ pub_r001047_13) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_118 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_12 ^ pub_r001047_14) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_155 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_170 ^ pub_r001047_12) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_170 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001047_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_153 ^ pub_r001047_15) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_184 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_116 ^ pub_r001047_9) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001047_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001047_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001047_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001047_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_163 ^ pub_r001047_3) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((sec_r001047_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001047_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_152 ^ pub_r001047_3) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_30 ^ pub_r001047_1) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (helper_flow_10 ^ pub_r001047_12) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (helper_flow_3 ^ pub_r001047_2) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_23 ^ pub_r001047_0) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (helper_flow_5 ^ pub_r001047_8) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001047_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001047_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001047_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_5 ^ pub_r001047_14) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001047_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001047_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_88 ^ pub_r001047_4) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_161 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001047_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_186 ^ pub_r001047_14) & 63;
    if ((stage_v_211 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_211 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_211 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_181 ^ pub_r001047_15) & 63;
    if ((stage_v_212 & 1) != 0) {
        if ((stage_v_163 & 2) != 0) {
            out_sink = (out_sink + stage_v_212 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_212 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001047_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_83 ^ pub_r001047_0) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_202 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001047_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001047_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_155 ^ pub_r001047_14) & 63;
    if ((stage_v_217 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_217 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_217 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_84 ^ pub_r001047_11) & 63;
    if ((stage_v_218 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_218 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_218 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_30 ^ pub_r001047_8) & 63;
    if ((stage_v_219 & 1) != 0) {
        if ((stage_v_202 & 2) != 0) {
            out_sink = (out_sink + stage_v_219 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_219 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_148 ^ pub_r001047_17) & 63;
    if ((stage_v_220 & 1) != 0) {
        if ((stage_v_190 & 2) != 0) {
            out_sink = (out_sink + stage_v_220 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_220 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_95 ^ pub_r001047_11) & 63;
    if ((stage_v_221 & 1) != 0) {
        if ((sec_r001047_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_221 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_221 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_132 ^ pub_r001047_10) & 63;
    if ((stage_v_222 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_222 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_222 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001047_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_144 ^ pub_r001047_2) & 63;
    if ((stage_v_224 & 1) != 0) {
        if ((stage_v_197 & 2) != 0) {
            out_sink = (out_sink + stage_v_224 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_224 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (sec_r001047_13 ^ pub_r001047_14) & 63;
    if ((stage_v_225 & 1) != 0) {
        if ((stage_v_150 & 2) != 0) {
            out_sink = (out_sink + stage_v_225 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_225 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001047_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r001047_15 ^ pub_r001047_17) & 63;
    if ((stage_v_227 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_227 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_227 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (sec_r001047_9 ^ pub_r001047_7) & 63;
    if ((stage_v_228 & 1) != 0) {
        if ((stage_v_222 & 2) != 0) {
            out_sink = (out_sink + stage_v_228 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_228 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_166 ^ pub_r001047_12) & 63;
    if ((stage_v_229 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_229 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_229 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (helper_flow_4 ^ pub_r001047_6) & 63;
    if ((stage_v_230 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_230 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_230 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_225 ^ pub_r001047_12) & 63;
    if ((stage_v_231 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_231 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_231 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_32 ^ pub_r001047_5) & 63;
    if ((stage_v_232 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_232 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_232 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001047_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001047_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001047_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_222 ^ pub_r001047_17) & 63;
    if ((stage_v_236 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_236 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_236 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_148 ^ pub_r001047_4) & 63;
    if ((stage_v_237 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_237 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_237 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_74 ^ pub_r001047_8) & 63;
    if ((stage_v_238 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_238 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_238 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_163 ^ pub_r001047_12) & 63;
    if ((stage_v_239 & 1) != 0) {
        if ((sec_r001047_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_239 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_239 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001047_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001047_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_121 ^ pub_r001047_12) & 63;
    if ((stage_v_242 & 1) != 0) {
        if ((stage_v_144 & 2) != 0) {
            out_sink = (out_sink + stage_v_242 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_242 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
