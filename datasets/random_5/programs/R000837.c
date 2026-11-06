/*
 * Benchmark Program: R000837
 * Security Family: nested_implicit_flow
 * Generator Seed: 583713
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000837_3713_0 {
    int iv;
    int round_key;
    int tag;
    int counter;
    int buffer[3];
};

struct Vector3D_R000837_3713_1 {
    int heading;
    unsigned char coord_x;
    short coord_y;
    int coord_z;
    int pitch;
    int buffer[3];
};

union RegisterBank_R000837_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000837_3713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_60) & 63;
    acc ^= aux;
    int weight_50 = (aux + st.buffer[1]) & 3;
    switch (weight_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_23 = (aux + st.buffer[1]) & 3;
    switch (tally_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_40 = local_arr[aux % 3];
    acc = (acc + parity_40 * 2) & 127;
    int mask_71 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_71 > 38) {
        acc = (acc + mask_71 * 2 + 5) & 127;
        aux ^= (mask_71 & 15);
    } else {
        acc = (acc - mask_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_2(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int margin_55 = local_arr[aux % 3];
    acc = (acc + margin_55 * 2) & 127;
    int accumulator_35 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_35 > 44) {
        acc = (acc + accumulator_35 * 2 + 5) & 127;
        aux ^= (accumulator_35 & 15);
    } else {
        acc = (acc - accumulator_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int weight_21 = local_arr[aux % 3];
    acc = (acc + weight_21 * 2) & 127;
    int index_reg_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_17 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_17 > 50) {
        acc = (acc + cursor_17 * 2 + 5) & 127;
        aux ^= (cursor_17 & 15);
    } else {
        acc = (acc - cursor_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_77 > 27) {
        acc = (acc + cursor_77 * 2 + 5) & 127;
        aux ^= (cursor_77 & 15);
    } else {
        acc = (acc - cursor_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_89 = local_arr[aux % 3];
    acc = (acc + parity_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_80) & 63;
    acc ^= aux;
    int tracker_69 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_69 > 44) {
        acc = (acc + tracker_69 * 2 + 5) & 127;
        aux ^= (tracker_69 & 15);
    } else {
        acc = (acc - tracker_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_6(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_51 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_51 > 24) {
        acc = (acc + threshold_51 * 2 + 5) & 127;
        aux ^= (threshold_51 & 15);
    } else {
        acc = (acc - threshold_51 + 11) & 127;
        aux += 3;
    }
    int cursor_29 = (aux + st.buffer[1]) & 3;
    switch (cursor_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int metric_16 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_16 > 47) {
        acc = (acc + metric_16 * 2 + 5) & 127;
        aux ^= (metric_16 & 15);
    } else {
        acc = (acc - metric_16 + 11) & 127;
        aux += 3;
    }
    int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_35 = (aux + st.buffer[1]) & 3;
    switch (bound_35) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_54 = local_arr[aux % 3];
    acc = (acc + scale_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_9(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int offset_40 = local_arr[aux % 3];
    acc = (acc + offset_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_65 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_65 > 33) {
        acc = (acc + checksum_65 * 2 + 5) & 127;
        aux ^= (checksum_65 & 15);
    } else {
        acc = (acc - checksum_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_10(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int accumulator_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_32) & 63;
    acc ^= aux;
    int offset_30 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_30 > 43) {
        acc = (acc + offset_30 * 2 + 5) & 127;
        aux ^= (offset_30 & 15);
    } else {
        acc = (acc - offset_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000837_3713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int coefficient_32 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_32 > 35) {
        acc = (acc + coefficient_32 * 2 + 5) & 127;
        aux ^= (coefficient_32 & 15);
    } else {
        acc = (acc - coefficient_32 + 11) & 127;
        aux += 3;
    }
    int coefficient_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_85) & 63;
    acc ^= aux;
    int tracker_98 = (aux + st.buffer[1]) & 3;
    switch (tracker_98) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000837_3713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_30 = (aux + st.buffer[1]) & 3;
    switch (damping_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_70 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_70 > 26) {
        acc = (acc + stride_70 * 2 + 5) & 127;
        aux ^= (stride_70 & 15);
    } else {
        acc = (acc - stride_70 + 11) & 127;
        aux += 3;
    }
    int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000837_3713_15(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_54) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_90 = local_arr[aux % 3];
    acc = (acc + tracker_90 * 2) & 127;
    int metric_16 = (aux + st.buffer[1]) & 3;
    switch (metric_16) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_16(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000837_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_23 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_23 > 26) {
        acc = (acc + vector_23 * 2 + 5) & 127;
        aux ^= (vector_23 & 15);
    } else {
        acc = (acc - vector_23 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_93 = local_arr[aux % 3];
    acc = (acc + factor_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000837_3713_17(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000837_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_43 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_43 > 25) {
        acc = (acc + factor_43 * 2 + 5) & 127;
        aux ^= (factor_43 & 15);
    } else {
        acc = (acc - factor_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_48 = local_arr[aux % 3];
    acc = (acc + sample_48 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000837_0;
    int sec_r000837_1;
    int sec_r000837_2;
    int sec_r000837_3;
    int sec_r000837_4;
    int sec_r000837_5;
    int sec_r000837_6;
    int sec_r000837_7;
    int sec_r000837_8;
    int sec_r000837_9;
    int sec_r000837_10;
    int sec_r000837_11;
    int sec_r000837_12;
    int sec_r000837_13;
    int sec_r000837_14;
    int sec_r000837_15;
    int sec_r000837_16;
    int sec_r000837_17;
    int sec_r000837_18;
    int sec_r000837_19;
    int sec_r000837_20;
    int pub_r000837_0;
    int pub_r000837_1;
    int pub_r000837_2;
    int pub_r000837_3;
    int pub_r000837_4;
    int pub_r000837_5;
    int pub_r000837_6;
    int pub_r000837_7;
    int pub_r000837_8;
    int pub_r000837_9;
    int pub_r000837_10;
    int pub_r000837_11;
    int pub_r000837_12;
    int pub_r000837_13;
    int pub_r000837_14;
    int pub_r000837_15;
    int pub_r000837_16;
    int pub_r000837_17;
    int pub_r000837_18;
    int pub_r000837_19;
    int pub_r000837_20;
    int pub_r000837_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000837_0 >= -100 && pub_r000837_0 <= 100);
    __CPROVER_assume(pub_r000837_1 >= -100 && pub_r000837_1 <= 100);
    __CPROVER_assume(pub_r000837_2 >= -100 && pub_r000837_2 <= 100);
    __CPROVER_assume(pub_r000837_3 >= -100 && pub_r000837_3 <= 100);
    __CPROVER_assume(pub_r000837_4 >= -100 && pub_r000837_4 <= 100);
    __CPROVER_assume(pub_r000837_5 >= -100 && pub_r000837_5 <= 100);
    __CPROVER_assume(pub_r000837_6 >= -100 && pub_r000837_6 <= 100);
    __CPROVER_assume(pub_r000837_7 >= -100 && pub_r000837_7 <= 100);
    __CPROVER_assume(pub_r000837_8 >= -100 && pub_r000837_8 <= 100);
    __CPROVER_assume(pub_r000837_9 >= -100 && pub_r000837_9 <= 100);
    __CPROVER_assume(pub_r000837_10 >= -100 && pub_r000837_10 <= 100);
    __CPROVER_assume(pub_r000837_11 >= -100 && pub_r000837_11 <= 100);
    __CPROVER_assume(pub_r000837_12 >= -100 && pub_r000837_12 <= 100);
    __CPROVER_assume(pub_r000837_13 >= -100 && pub_r000837_13 <= 100);
    __CPROVER_assume(pub_r000837_14 >= -100 && pub_r000837_14 <= 100);
    __CPROVER_assume(pub_r000837_15 >= -100 && pub_r000837_15 <= 100);
    __CPROVER_assume(pub_r000837_16 >= -100 && pub_r000837_16 <= 100);
    __CPROVER_assume(pub_r000837_17 >= -100 && pub_r000837_17 <= 100);
    __CPROVER_assume(pub_r000837_18 >= -100 && pub_r000837_18 <= 100);
    __CPROVER_assume(pub_r000837_19 >= -100 && pub_r000837_19 <= 100);
    __CPROVER_assume(pub_r000837_20 >= -100 && pub_r000837_20 <= 100);
    __CPROVER_assume(pub_r000837_21 >= -100 && pub_r000837_21 <= 100);
    __CPROVER_assume(sec_r000837_0 >= 0 && sec_r000837_0 <= 255);
    __CPROVER_assume(sec_r000837_1 >= 0 && sec_r000837_1 <= 255);
    __CPROVER_assume(sec_r000837_2 >= 0 && sec_r000837_2 <= 255);
    __CPROVER_assume(sec_r000837_3 >= 0 && sec_r000837_3 <= 255);
    __CPROVER_assume(sec_r000837_4 >= 0 && sec_r000837_4 <= 255);
    __CPROVER_assume(sec_r000837_5 >= 0 && sec_r000837_5 <= 255);
    __CPROVER_assume(sec_r000837_6 >= 0 && sec_r000837_6 <= 255);
    __CPROVER_assume(sec_r000837_7 >= 0 && sec_r000837_7 <= 255);
    __CPROVER_assume(sec_r000837_8 >= 0 && sec_r000837_8 <= 255);
    __CPROVER_assume(sec_r000837_9 >= 0 && sec_r000837_9 <= 255);
    __CPROVER_assume(sec_r000837_10 >= 0 && sec_r000837_10 <= 255);
    __CPROVER_assume(sec_r000837_11 >= 0 && sec_r000837_11 <= 255);
    __CPROVER_assume(sec_r000837_12 >= 0 && sec_r000837_12 <= 255);
    __CPROVER_assume(sec_r000837_13 >= 0 && sec_r000837_13 <= 255);
    __CPROVER_assume(sec_r000837_14 >= 0 && sec_r000837_14 <= 255);
    __CPROVER_assume(sec_r000837_15 >= 0 && sec_r000837_15 <= 255);
    __CPROVER_assume(sec_r000837_16 >= 0 && sec_r000837_16 <= 255);
    __CPROVER_assume(sec_r000837_17 >= 0 && sec_r000837_17 <= 255);
    __CPROVER_assume(sec_r000837_18 >= 0 && sec_r000837_18 <= 255);
    __CPROVER_assume(sec_r000837_19 >= 0 && sec_r000837_19 <= 255);
    __CPROVER_assume(sec_r000837_20 >= 0 && sec_r000837_20 <= 255);

    struct CipherContext_R000837_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000837_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000837_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000837_0 + 7) & 15;
    struct Vector3D_R000837_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000837_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000837_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000837_0 + 9) & 15;

    union RegisterBank_R000837_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 21) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 36) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 27) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 42) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 33) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 48) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 35) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 50) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 40) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 55) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 22) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 37) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 33) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 48) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 12) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 27) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 11) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 26) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 38) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 53) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 17) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 32) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 31) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 46) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
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
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000837_4 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_87 = (pub_r000837_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000837_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000837_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000837_12 & 2) != 0) {
            stage_v_88 = (pub_r000837_18 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000837_18 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000837_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000837_8 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_89 = (pub_r000837_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000837_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000837_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_90 = (pub_r000837_4 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000837_4 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000837_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000837_1 & 2) != 0) {
            stage_v_91 = (pub_r000837_10 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000837_10 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000837_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000837_15 & 2) != 0) {
            stage_v_92 = (pub_r000837_11 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000837_11 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000837_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000837_5 & 2) != 0) {
            stage_v_93 = (pub_r000837_0 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000837_0 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000837_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000837_16 & 2) != 0) {
            stage_v_94 = (pub_r000837_9 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000837_9 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000837_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000837_11 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_95 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000837_13 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_96 = (pub_r000837_15 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000837_15 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000837_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000837_9 & 2) != 0) {
            stage_v_97 = (pub_r000837_9 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000837_9 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000837_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000837_0 & 1) != 0) {
        if ((sec_r000837_4 & 2) != 0) {
            stage_v_98 = (pub_r000837_21 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000837_21 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000837_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000837_4 & 2) != 0) {
            stage_v_99 = (pub_r000837_2 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000837_2 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000837_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_3 & 2) != 0) {
            stage_v_100 = (pub_r000837_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000837_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000837_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_5 & 2) != 0) {
            stage_v_101 = (pub_r000837_11 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000837_11 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000837_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_102 = (pub_r000837_6 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000837_6 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000837_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000837_20 & 2) != 0) {
            stage_v_103 = (pub_r000837_2 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000837_2 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000837_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000837_0 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_104 = (pub_r000837_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000837_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000837_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_9 & 2) != 0) {
            stage_v_105 = (pub_r000837_3 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000837_3 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000837_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000837_14 & 1) != 0) {
        if ((sec_r000837_2 & 2) != 0) {
            stage_v_106 = (pub_r000837_6 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000837_6 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000837_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_15 & 2) != 0) {
            stage_v_107 = (pub_r000837_13 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000837_13 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000837_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_108 = (pub_r000837_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000837_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000837_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000837_3 & 1) != 0) {
        if ((sec_r000837_18 & 2) != 0) {
            stage_v_109 = (pub_r000837_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000837_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000837_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000837_9 & 2) != 0) {
            stage_v_110 = (pub_r000837_21 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000837_21 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000837_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000837_1 & 2) != 0) {
            stage_v_111 = (pub_r000837_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000837_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000837_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_12 & 2) != 0) {
            stage_v_112 = (pub_r000837_6 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000837_6 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000837_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_4 & 2) != 0) {
            stage_v_113 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000837_17 & 2) != 0) {
            stage_v_114 = (pub_r000837_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000837_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000837_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000837_2 & 2) != 0) {
            stage_v_115 = (pub_r000837_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000837_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000837_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000837_6 & 2) != 0) {
            stage_v_116 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000837_18 & 1) != 0) {
        if ((sec_r000837_8 & 2) != 0) {
            stage_v_117 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000837_17 & 2) != 0) {
            stage_v_118 = (pub_r000837_20 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000837_20 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000837_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000837_3 & 2) != 0) {
            stage_v_119 = (pub_r000837_15 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000837_15 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000837_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000837_16 & 1) != 0) {
        if ((sec_r000837_10 & 2) != 0) {
            stage_v_120 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_121 = (pub_r000837_5 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000837_5 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000837_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000837_6 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_122 = (pub_r000837_20 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000837_20 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000837_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000837_2 & 2) != 0) {
            stage_v_123 = (pub_r000837_0 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000837_0 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000837_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000837_2 & 2) != 0) {
            stage_v_124 = (pub_r000837_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000837_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000837_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000837_17 & 1) != 0) {
        if ((sec_r000837_20 & 2) != 0) {
            stage_v_125 = (pub_r000837_12 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000837_12 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000837_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000837_18 & 1) != 0) {
        if ((sec_r000837_0 & 2) != 0) {
            stage_v_126 = (pub_r000837_16 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000837_16 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000837_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000837_8 & 1) != 0) {
        if ((sec_r000837_10 & 2) != 0) {
            stage_v_127 = (pub_r000837_21 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000837_21 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000837_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000837_16 & 2) != 0) {
            stage_v_128 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000837_20 & 2) != 0) {
            stage_v_129 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000837_13 & 1) != 0) {
        if ((sec_r000837_15 & 2) != 0) {
            stage_v_130 = (pub_r000837_20 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000837_20 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000837_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000837_18 & 2) != 0) {
            stage_v_131 = (pub_r000837_11 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000837_11 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000837_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_132 = (pub_r000837_3 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000837_3 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000837_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000837_17 & 1) != 0) {
        if ((sec_r000837_11 & 2) != 0) {
            stage_v_133 = (pub_r000837_9 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000837_9 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000837_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000837_2 & 2) != 0) {
            stage_v_134 = (pub_r000837_20 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000837_20 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000837_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000837_8 & 1) != 0) {
        if ((sec_r000837_15 & 2) != 0) {
            stage_v_135 = (pub_r000837_9 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000837_9 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000837_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_136 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000837_9 & 2) != 0) {
            stage_v_137 = (pub_r000837_17 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000837_17 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000837_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000837_6 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_138 = (pub_r000837_10 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000837_10 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000837_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000837_18 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_139 = (pub_r000837_16 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000837_16 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000837_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000837_16 & 2) != 0) {
            stage_v_140 = (pub_r000837_6 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000837_6 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000837_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000837_3 & 2) != 0) {
            stage_v_141 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000837_19 & 1) != 0) {
        if ((sec_r000837_17 & 2) != 0) {
            stage_v_142 = (pub_r000837_2 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000837_2 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000837_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_143 = (pub_r000837_3 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000837_3 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000837_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000837_9 & 2) != 0) {
            stage_v_144 = (pub_r000837_11 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000837_11 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000837_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000837_18 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_145 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000837_17 & 2) != 0) {
            stage_v_146 = (pub_r000837_19 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000837_19 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000837_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000837_16 & 2) != 0) {
            stage_v_147 = (pub_r000837_14 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000837_14 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000837_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000837_7 & 2) != 0) {
            stage_v_148 = (pub_r000837_1 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000837_1 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000837_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r000837_19 & 2) != 0) {
            stage_v_149 = (pub_r000837_1 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000837_1 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000837_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000837_5 & 1) != 0) {
        if ((sec_r000837_0 & 2) != 0) {
            stage_v_150 = (pub_r000837_21 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000837_21 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000837_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000837_4 & 1) != 0) {
        if ((sec_r000837_16 & 2) != 0) {
            stage_v_151 = (pub_r000837_6 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000837_6 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000837_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000837_18 & 2) != 0) {
            stage_v_152 = (pub_r000837_20 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000837_20 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000837_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000837_13 & 2) != 0) {
            stage_v_153 = (pub_r000837_8 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000837_8 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000837_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
