/*
 * Benchmark Program: R001247
 * Security Family: nested_implicit_flow
 * Generator Seed: 624713
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001247_4713_0 {
    unsigned char heading;
    int norm_sq;
    int coord_y;
    int pitch;
    unsigned char coord_x;
    int buffer[3];
};

struct FilterState_R001247_4713_1 {
    int mode;
    int cutoff;
    unsigned char damping;
    unsigned char prev_in;
    int buffer[3];
};

struct Transaction_R001247_4713_2 {
    short rate;
    unsigned char status;
    int fee;
    unsigned char account_id;
    int buffer[3];
};

union RegisterBank_R001247_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001247_4713_0(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tracker_47 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_47 = (tracker_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_47) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_46 = (aux + st.buffer[1]) & 3;
    switch (phase_46) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_35 = local_arr[aux % 3];
    acc = (acc + threshold_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_74 = (aux + st.buffer[1]) & 3;
    switch (anchor_74) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_71 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_71 = (threshold_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int cursor_21 = local_arr[aux % 3];
    acc = (acc + cursor_21 * 2) & 127;
    int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_70) & 63;
    acc ^= aux;
    int anchor_58 = (aux + st.buffer[1]) & 3;
    switch (anchor_58) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_3(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001247_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_48 = local_arr[aux % 3];
    acc = (acc + cursor_48 * 2) & 127;
    int window_47 = 0;
    for (int k = 0; k < 2; k++) {
        window_47 = (window_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001247_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int margin_61 = (aux + st.buffer[1]) & 3;
    switch (margin_61) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_58 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_58 > 25) {
        acc = (acc + accumulator_58 * 2 + 5) & 127;
        aux ^= (accumulator_58 & 15);
    } else {
        acc = (acc - accumulator_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_5(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001247_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_74 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_74 > 23) {
        acc = (acc + vector_74 * 2 + 5) & 127;
        aux ^= (vector_74 & 15);
    } else {
        acc = (acc - vector_74 + 11) & 127;
        aux += 3;
    }
    int weight_62 = 0;
    for (int k = 0; k < 2; k++) {
        weight_62 = (weight_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_62) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001247_4713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001247_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_41 = (aux + st.buffer[1]) & 3;
    switch (delta_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_10) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_51 = local_arr[aux % 3];
    acc = (acc + weight_51 * 2) & 127;
    int window_88 = 0;
    for (int k = 0; k < 3; k++) {
        window_88 = (window_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_88) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_48 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_48 > 36) {
        acc = (acc + coefficient_48 * 2 + 5) & 127;
        aux ^= (coefficient_48 & 15);
    } else {
        acc = (acc - coefficient_48 + 11) & 127;
        aux += 3;
    }
    int tally_51 = 0;
    for (int k = 0; k < 3; k++) {
        tally_51 = (tally_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_51) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_95 = local_arr[aux % 3];
    acc = (acc + stride_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_8(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int scale_82 = local_arr[aux % 3];
    acc = (acc + scale_82 * 2) & 127;
    int parity_60 = 0;
    for (int k = 0; k < 3; k++) {
        parity_60 = (parity_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_60) & 127;
    }
    int cursor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_68) & 63;
    acc ^= aux;
    int quotient_86 = (aux + st.buffer[1]) & 3;
    switch (quotient_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001247_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_69 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_69 > 22) {
        acc = (acc + vector_69 * 2 + 5) & 127;
        aux ^= (vector_69 & 15);
    } else {
        acc = (acc - vector_69 + 11) & 127;
        aux += 3;
    }
    int weight_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001247_4713_10(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_32 = 0;
    for (int k = 0; k < 3; k++) {
        parity_32 = (parity_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_32) & 127;
    }
    int metric_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001247_4713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001247_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int delta_10 = (aux + st.buffer[1]) & 3;
    switch (delta_10) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_90 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_90 > 40) {
        acc = (acc + margin_90 * 2 + 5) & 127;
        aux ^= (margin_90 & 15);
    } else {
        acc = (acc - margin_90 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_69 = local_arr[aux % 3];
    acc = (acc + parity_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001247_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001247_4713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001247_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_58 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_58 > 40) {
        acc = (acc + quotient_58 * 2 + 5) & 127;
        aux ^= (quotient_58 & 15);
    } else {
        acc = (acc - quotient_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_82 = (aux + st.buffer[1]) & 3;
    switch (damping_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_58 = 0;
    for (int k = 0; k < 3; k++) {
        vector_58 = (vector_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001247_4713_14(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001247_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int stride_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_33) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int segment_85 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_85 > 43) {
        acc = (acc + segment_85 * 2 + 5) & 127;
        aux ^= (segment_85 & 15);
    } else {
        acc = (acc - segment_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_10 = local_arr[aux % 3];
    acc = (acc + delta_10 * 2) & 127;
    int weight_63 = 0;
    for (int k = 0; k < 2; k++) {
        weight_63 = (weight_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_63) & 127;
    }
    int pivot_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001247_4713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001247_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_23 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_23 > 21) {
        acc = (acc + mask_23 * 2 + 5) & 127;
        aux ^= (mask_23 & 15);
    } else {
        acc = (acc - mask_23 + 11) & 127;
        aux += 3;
    }
    int sample_28 = (aux + st.buffer[1]) & 3;
    switch (sample_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_28 = local_arr[aux % 3];
    acc = (acc + quantum_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001247_4713_17(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001247_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int vector_12 = local_arr[aux % 3];
    acc = (acc + vector_12 * 2) & 127;
    int index_reg_72 = (aux + st.buffer[1]) & 3;
    switch (index_reg_72) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_69 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_69 > 26) {
        acc = (acc + index_reg_69 * 2 + 5) & 127;
        aux ^= (index_reg_69 & 15);
    } else {
        acc = (acc - index_reg_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001247_0;
    int sec_r001247_1;
    int sec_r001247_2;
    int sec_r001247_3;
    int sec_r001247_4;
    int sec_r001247_5;
    int sec_r001247_6;
    int sec_r001247_7;
    int sec_r001247_8;
    int sec_r001247_9;
    int sec_r001247_10;
    int sec_r001247_11;
    int sec_r001247_12;
    int sec_r001247_13;
    int sec_r001247_14;
    int sec_r001247_15;
    int sec_r001247_16;
    int sec_r001247_17;
    int sec_r001247_18;
    int pub_r001247_0;
    int pub_r001247_1;
    int pub_r001247_2;
    int pub_r001247_3;
    int pub_r001247_4;
    int pub_r001247_5;
    int pub_r001247_6;
    int pub_r001247_7;
    int pub_r001247_8;
    int pub_r001247_9;
    int pub_r001247_10;
    int pub_r001247_11;
    int pub_r001247_12;
    int pub_r001247_13;
    int pub_r001247_14;
    int pub_r001247_15;
    int pub_r001247_16;
    int pub_r001247_17;
    int pub_r001247_18;
    int pub_r001247_19;
    int pub_r001247_20;
    int pub_r001247_21;
    int pub_r001247_22;
    int pub_r001247_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001247_0 >= -100 && pub_r001247_0 <= 100);
    __CPROVER_assume(pub_r001247_1 >= -100 && pub_r001247_1 <= 100);
    __CPROVER_assume(pub_r001247_2 >= -100 && pub_r001247_2 <= 100);
    __CPROVER_assume(pub_r001247_3 >= -100 && pub_r001247_3 <= 100);
    __CPROVER_assume(pub_r001247_4 >= -100 && pub_r001247_4 <= 100);
    __CPROVER_assume(pub_r001247_5 >= -100 && pub_r001247_5 <= 100);
    __CPROVER_assume(pub_r001247_6 >= -100 && pub_r001247_6 <= 100);
    __CPROVER_assume(pub_r001247_7 >= -100 && pub_r001247_7 <= 100);
    __CPROVER_assume(pub_r001247_8 >= -100 && pub_r001247_8 <= 100);
    __CPROVER_assume(pub_r001247_9 >= -100 && pub_r001247_9 <= 100);
    __CPROVER_assume(pub_r001247_10 >= -100 && pub_r001247_10 <= 100);
    __CPROVER_assume(pub_r001247_11 >= -100 && pub_r001247_11 <= 100);
    __CPROVER_assume(pub_r001247_12 >= -100 && pub_r001247_12 <= 100);
    __CPROVER_assume(pub_r001247_13 >= -100 && pub_r001247_13 <= 100);
    __CPROVER_assume(pub_r001247_14 >= -100 && pub_r001247_14 <= 100);
    __CPROVER_assume(pub_r001247_15 >= -100 && pub_r001247_15 <= 100);
    __CPROVER_assume(pub_r001247_16 >= -100 && pub_r001247_16 <= 100);
    __CPROVER_assume(pub_r001247_17 >= -100 && pub_r001247_17 <= 100);
    __CPROVER_assume(pub_r001247_18 >= -100 && pub_r001247_18 <= 100);
    __CPROVER_assume(pub_r001247_19 >= -100 && pub_r001247_19 <= 100);
    __CPROVER_assume(pub_r001247_20 >= -100 && pub_r001247_20 <= 100);
    __CPROVER_assume(pub_r001247_21 >= -100 && pub_r001247_21 <= 100);
    __CPROVER_assume(pub_r001247_22 >= -100 && pub_r001247_22 <= 100);
    __CPROVER_assume(pub_r001247_23 >= -100 && pub_r001247_23 <= 100);
    __CPROVER_assume(sec_r001247_0 >= 0 && sec_r001247_0 <= 255);
    __CPROVER_assume(sec_r001247_1 >= 0 && sec_r001247_1 <= 255);
    __CPROVER_assume(sec_r001247_2 >= 0 && sec_r001247_2 <= 255);
    __CPROVER_assume(sec_r001247_3 >= 0 && sec_r001247_3 <= 255);
    __CPROVER_assume(sec_r001247_4 >= 0 && sec_r001247_4 <= 255);
    __CPROVER_assume(sec_r001247_5 >= 0 && sec_r001247_5 <= 255);
    __CPROVER_assume(sec_r001247_6 >= 0 && sec_r001247_6 <= 255);
    __CPROVER_assume(sec_r001247_7 >= 0 && sec_r001247_7 <= 255);
    __CPROVER_assume(sec_r001247_8 >= 0 && sec_r001247_8 <= 255);
    __CPROVER_assume(sec_r001247_9 >= 0 && sec_r001247_9 <= 255);
    __CPROVER_assume(sec_r001247_10 >= 0 && sec_r001247_10 <= 255);
    __CPROVER_assume(sec_r001247_11 >= 0 && sec_r001247_11 <= 255);
    __CPROVER_assume(sec_r001247_12 >= 0 && sec_r001247_12 <= 255);
    __CPROVER_assume(sec_r001247_13 >= 0 && sec_r001247_13 <= 255);
    __CPROVER_assume(sec_r001247_14 >= 0 && sec_r001247_14 <= 255);
    __CPROVER_assume(sec_r001247_15 >= 0 && sec_r001247_15 <= 255);
    __CPROVER_assume(sec_r001247_16 >= 0 && sec_r001247_16 <= 255);
    __CPROVER_assume(sec_r001247_17 >= 0 && sec_r001247_17 <= 255);
    __CPROVER_assume(sec_r001247_18 >= 0 && sec_r001247_18 <= 255);

    struct Vector3D_R001247_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001247_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001247_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001247_0 + 7) & 15;
    struct FilterState_R001247_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001247_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001247_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001247_0 + 9) & 15;
    struct Transaction_R001247_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001247_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001247_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001247_0 + 11) & 15;

    union RegisterBank_R001247_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001247_4713_0(sec_r001247_0, pub_r001247_1);
    int helper_flow_1 = fn_R001247_4713_1(sec_r001247_1, sec_r001247_2, pub_r001247_3, pub_r001247_4, pub_r001247_5);
    int helper_flow_2 = fn_R001247_4713_2(sec_r001247_2, pub_r001247_3, pub_r001247_4, pub_r001247_5);
    int helper_flow_3 = fn_R001247_4713_3(sec_r001247_3, pub_r001247_4);
    int helper_flow_4 = fn_R001247_4713_4(sec_r001247_4, pub_r001247_5, pub_r001247_6, pub_r001247_7, pub_r001247_8);
    int helper_flow_5 = fn_R001247_4713_5(sec_r001247_5, pub_r001247_6);
    int helper_flow_6 = fn_R001247_4713_6(sec_r001247_6, sec_r001247_7, pub_r001247_8, pub_r001247_9, pub_r001247_10);
    int helper_flow_7 = fn_R001247_4713_7(sec_r001247_7, pub_r001247_8, pub_r001247_9, pub_r001247_10, pub_r001247_11);
    int helper_flow_8 = fn_R001247_4713_8(sec_r001247_8, sec_r001247_9, pub_r001247_10);
    int helper_flow_9 = fn_R001247_4713_9(sec_r001247_9, sec_r001247_10, pub_r001247_11, pub_r001247_12);
    int helper_flow_10 = fn_R001247_4713_10(sec_r001247_10, pub_r001247_11, pub_r001247_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001247_4 ^ pub_r001247_6) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001247_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_3 ^ pub_r001247_10) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001247_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (stage_v_2 ^ pub_r001247_4) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001247_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001247_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_2 ^ pub_r001247_8) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001247_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001247_18 ^ pub_r001247_19) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001247_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001247_16 ^ pub_r001247_20) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_10 ^ pub_r001247_1) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001247_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001247_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001247_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001247_0 ^ pub_r001247_20) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001247_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_8 ^ pub_r001247_10) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001247_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001247_10 ^ pub_r001247_1) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001247_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_6 ^ pub_r001247_1) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001247_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001247_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001247_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001247_14 ^ pub_r001247_0) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001247_10 ^ pub_r001247_10) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001247_8 ^ pub_r001247_21) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001247_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001247_16 ^ pub_r001247_2) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001247_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001247_3 ^ pub_r001247_2) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_7 ^ pub_r001247_9) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001247_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001247_8 ^ pub_r001247_23) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001247_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001247_6 ^ pub_r001247_14) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_7 ^ pub_r001247_1) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001247_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001247_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001247_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001247_10 ^ pub_r001247_1) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001247_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001247_12 ^ pub_r001247_12) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001247_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001247_4 ^ pub_r001247_12) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001247_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001247_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001247_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_7 ^ pub_r001247_6) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_26 ^ pub_r001247_18) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001247_13 ^ pub_r001247_3) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001247_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001247_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001247_16 ^ pub_r001247_17) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_23 ^ pub_r001247_16) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001247_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_0 ^ pub_r001247_2) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r001247_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_22 ^ pub_r001247_6) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001247_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001247_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001247_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001247_10 ^ pub_r001247_17) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001247_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_2 ^ pub_r001247_2) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001247_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001247_17 ^ pub_r001247_0) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001247_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001247_3 ^ pub_r001247_4) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001247_17 ^ pub_r001247_15) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001247_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_55 ^ pub_r001247_15) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_9 ^ pub_r001247_6) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001247_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001247_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_56 ^ pub_r001247_1) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001247_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001247_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_33 ^ pub_r001247_9) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_28 ^ pub_r001247_23) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001247_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001247_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_63 ^ pub_r001247_12) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_22 ^ pub_r001247_4) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_26 ^ pub_r001247_4) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001247_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001247_9 ^ pub_r001247_22) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001247_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001247_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001247_12 ^ pub_r001247_12) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001247_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001247_11 ^ pub_r001247_15) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001247_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001247_23 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_13 ^ pub_r001247_0) & 63;
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
    int stage_v_77 = (helper_flow_5 ^ pub_r001247_13) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_1 ^ pub_r001247_13) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001247_3 ^ pub_r001247_5) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001247_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_20 ^ pub_r001247_20) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_2 ^ pub_r001247_21) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_17 ^ pub_r001247_9) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001247_13 ^ pub_r001247_13) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001247_21 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_17 ^ pub_r001247_8) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001247_18 ^ pub_r001247_4) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001247_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001247_10 ^ pub_r001247_14) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_51 ^ pub_r001247_7) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001247_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_2 ^ pub_r001247_4) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001247_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001247_5 ^ pub_r001247_15) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001247_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_30 ^ pub_r001247_18) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_0 ^ pub_r001247_17) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001247_6 ^ pub_r001247_13) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001247_14 ^ pub_r001247_18) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001247_22 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001247_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_36 ^ pub_r001247_13) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001247_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_0 ^ pub_r001247_12) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r001247_2 ^ pub_r001247_14) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001247_7 ^ pub_r001247_15) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r001247_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001247_3 ^ pub_r001247_0) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_53 ^ pub_r001247_18) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_103 ^ pub_r001247_23) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001247_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_105 ^ pub_r001247_5) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001247_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001247_7 ^ pub_r001247_15) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r001247_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001247_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_53 ^ pub_r001247_7) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r001247_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_84 ^ pub_r001247_18) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_76 ^ pub_r001247_8) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001247_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001247_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001247_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001247_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001247_13 ^ pub_r001247_9) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (helper_flow_3 ^ pub_r001247_14) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001247_6 ^ pub_r001247_0) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_104 ^ pub_r001247_4) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r001247_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001247_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_20 ^ pub_r001247_14) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r001247_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001247_11 ^ pub_r001247_4) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_102 ^ pub_r001247_8) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001247_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_36 ^ pub_r001247_7) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001247_15 ^ pub_r001247_19) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r001247_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (helper_flow_6 ^ pub_r001247_6) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_22 ^ pub_r001247_11) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001247_9 ^ pub_r001247_22) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_81 ^ pub_r001247_8) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001247_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_28 ^ pub_r001247_0) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001247_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_22 ^ pub_r001247_16) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r001247_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_20 ^ pub_r001247_8) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001247_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001247_13 ^ pub_r001247_11) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r001247_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001247_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_16 ^ pub_r001247_20) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_48 ^ pub_r001247_8) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001247_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_101 ^ pub_r001247_2) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_76 ^ pub_r001247_6) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r001247_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r001247_17 ^ pub_r001247_0) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_104 ^ pub_r001247_3) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001247_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_82 ^ pub_r001247_5) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_41 ^ pub_r001247_13) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_78 ^ pub_r001247_17) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_79 ^ pub_r001247_20) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001247_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_7 ^ pub_r001247_2) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001247_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001247_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_21 ^ pub_r001247_8) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001247_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001247_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_119 ^ pub_r001247_18) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_33 ^ pub_r001247_10) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((sec_r001247_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_104 ^ pub_r001247_22) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_111 ^ pub_r001247_19) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (helper_flow_8 ^ pub_r001247_18) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001247_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001247_20 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_21 ^ pub_r001247_22) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001247_8 ^ pub_r001247_15) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001247_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001247_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (helper_flow_2 ^ pub_r001247_8) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((sec_r001247_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_44 ^ pub_r001247_17) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_143 ^ pub_r001247_8) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_86 ^ pub_r001247_10) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001247_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001247_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001247_21 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001247_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_172 ^ pub_r001247_19) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_148 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_86 ^ pub_r001247_23) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001247_17 ^ pub_r001247_3) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_93 ^ pub_r001247_22) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001247_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_137 ^ pub_r001247_9) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_170 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_166 ^ pub_r001247_11) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001247_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001247_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (helper_flow_9 ^ pub_r001247_18) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_144 ^ pub_r001247_15) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001247_21 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001247_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_90 ^ pub_r001247_4) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((sec_r001247_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_41 ^ pub_r001247_16) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_82 ^ pub_r001247_8) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001247_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_68 ^ pub_r001247_3) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001247_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001247_22 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_53 ^ pub_r001247_22) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001247_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_170 ^ pub_r001247_23) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_82 ^ pub_r001247_12) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_160 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_78 ^ pub_r001247_20) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((sec_r001247_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001247_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_187 ^ pub_r001247_16) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
