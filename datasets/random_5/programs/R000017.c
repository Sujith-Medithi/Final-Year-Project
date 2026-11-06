/*
 * Benchmark Program: R000017
 * Security Family: nested_implicit_flow
 * Generator Seed: 501713
 * High Inputs: 21 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000017_1713_0 {
    short coord_z;
    int coord_x;
    unsigned char pitch;
    unsigned char heading;
    int norm_sq;
    int buffer[3];
};

struct StreamBuffer_R000017_1713_1 {
    short state;
    int head;
    int tail;
    int buffer[3];
};

union RegisterBank_R000017_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000017_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int window_18 = local_arr[aux % 3];
    acc = (acc + window_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_32 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_32 > 34) {
        acc = (acc + mask_32 * 2 + 5) & 127;
        aux ^= (mask_32 & 15);
    } else {
        acc = (acc - mask_32 + 11) & 127;
        aux += 3;
    }
    int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000017_1713_1(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_87) & 63;
    acc ^= aux;
    int threshold_53 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_53 > 18) {
        acc = (acc + threshold_53 * 2 + 5) & 127;
        aux ^= (threshold_53 & 15);
    } else {
        acc = (acc - threshold_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_58 = local_arr[aux % 3];
    acc = (acc + quantum_58 * 2) & 127;
    int threshold_22 = (aux + st.buffer[1]) & 3;
    switch (threshold_22) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_2(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_27 = local_arr[aux % 3];
    acc = (acc + sample_27 * 2) & 127;
    int cursor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_26) & 63;
    acc ^= aux;
    int pivot_96 = (aux + st.buffer[1]) & 3;
    switch (pivot_96) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_3(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_82 = local_arr[aux % 3];
    acc = (acc + offset_82 * 2) & 127;
    int scale_56 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_56 > 41) {
        acc = (acc + scale_56 * 2 + 5) & 127;
        aux ^= (scale_56 & 15);
    } else {
        acc = (acc - scale_56 + 11) & 127;
        aux += 3;
    }
    int weight_20 = (aux + st.buffer[1]) & 3;
    switch (weight_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int parity_99 = (aux + st.buffer[1]) & 3;
    switch (parity_99) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_95) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000017_1713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_70) & 63;
    acc ^= aux;
    int index_reg_56 = (aux + st.buffer[1]) & 3;
    switch (index_reg_56) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_24 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_24 > 45) {
        acc = (acc + residue_24 * 2 + 5) & 127;
        aux ^= (residue_24 & 15);
    } else {
        acc = (acc - residue_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_6(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_51 = (aux + st.buffer[1]) & 3;
    switch (tracker_51) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000017_1713_7(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_43 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_43 > 46) {
        acc = (acc + damping_43 * 2 + 5) & 127;
        aux ^= (damping_43 & 15);
    } else {
        acc = (acc - damping_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_19 = (aux + st.buffer[1]) & 3;
    switch (pivot_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_8(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int phase_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_16 = local_arr[aux % 3];
    acc = (acc + sample_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000017_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_48) & 63;
    acc ^= aux;
    int pivot_56 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_56 > 36) {
        acc = (acc + pivot_56 * 2 + 5) & 127;
        aux ^= (pivot_56 & 15);
    } else {
        acc = (acc - pivot_56 + 11) & 127;
        aux += 3;
    }
    int sample_81 = (aux + st.buffer[1]) & 3;
    switch (sample_81) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_18) & 63;
    acc ^= aux;
    int metric_91 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_91 > 34) {
        acc = (acc + metric_91 * 2 + 5) & 127;
        aux ^= (metric_91 & 15);
    } else {
        acc = (acc - metric_91 + 11) & 127;
        aux += 3;
    }
    int segment_62 = (aux + st.buffer[1]) & 3;
    switch (segment_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_11(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000017_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_81 = (aux + st.buffer[1]) & 3;
    switch (stride_81) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_52 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_52 > 11) {
        acc = (acc + weight_52 * 2 + 5) & 127;
        aux ^= (weight_52 & 15);
    } else {
        acc = (acc - weight_52 + 11) & 127;
        aux += 3;
    }
    int damping_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_13) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000017_1713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int factor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_37 > 38) {
        acc = (acc + factor_37 * 2 + 5) & 127;
        aux ^= (factor_37 & 15);
    } else {
        acc = (acc - factor_37 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_97 = local_arr[aux % 3];
    acc = (acc + parity_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000017_1713_13(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_51 = (aux + st.buffer[1]) & 3;
    switch (delta_51) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_66 = local_arr[aux % 3];
    acc = (acc + scale_66 * 2) & 127;
    int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000017_1713_14(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int stride_41 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_41 > 11) {
        acc = (acc + stride_41 * 2 + 5) & 127;
        aux ^= (stride_41 & 15);
    } else {
        acc = (acc - stride_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_19) & 63;
    acc ^= aux;
    int sample_15 = (aux + st.buffer[1]) & 3;
    switch (sample_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000017_1713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000017_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_47 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_47 > 16) {
        acc = (acc + tracker_47 * 2 + 5) & 127;
        aux ^= (tracker_47 & 15);
    } else {
        acc = (acc - tracker_47 + 11) & 127;
        aux += 3;
    }
    int quantum_75 = (aux + st.buffer[1]) & 3;
    switch (quantum_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_46) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000017_0;
    int sec_r000017_1;
    int sec_r000017_2;
    int sec_r000017_3;
    int sec_r000017_4;
    int sec_r000017_5;
    int sec_r000017_6;
    int sec_r000017_7;
    int sec_r000017_8;
    int sec_r000017_9;
    int sec_r000017_10;
    int sec_r000017_11;
    int sec_r000017_12;
    int sec_r000017_13;
    int sec_r000017_14;
    int sec_r000017_15;
    int sec_r000017_16;
    int sec_r000017_17;
    int sec_r000017_18;
    int sec_r000017_19;
    int sec_r000017_20;
    int pub_r000017_0;
    int pub_r000017_1;
    int pub_r000017_2;
    int pub_r000017_3;
    int pub_r000017_4;
    int pub_r000017_5;
    int pub_r000017_6;
    int pub_r000017_7;
    int pub_r000017_8;
    int pub_r000017_9;
    int pub_r000017_10;
    int pub_r000017_11;
    int pub_r000017_12;
    int pub_r000017_13;
    int pub_r000017_14;
    int pub_r000017_15;
    int pub_r000017_16;
    int pub_r000017_17;
    int pub_r000017_18;
    int pub_r000017_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000017_0 >= -100 && pub_r000017_0 <= 100);
    __CPROVER_assume(pub_r000017_1 >= -100 && pub_r000017_1 <= 100);
    __CPROVER_assume(pub_r000017_2 >= -100 && pub_r000017_2 <= 100);
    __CPROVER_assume(pub_r000017_3 >= -100 && pub_r000017_3 <= 100);
    __CPROVER_assume(pub_r000017_4 >= -100 && pub_r000017_4 <= 100);
    __CPROVER_assume(pub_r000017_5 >= -100 && pub_r000017_5 <= 100);
    __CPROVER_assume(pub_r000017_6 >= -100 && pub_r000017_6 <= 100);
    __CPROVER_assume(pub_r000017_7 >= -100 && pub_r000017_7 <= 100);
    __CPROVER_assume(pub_r000017_8 >= -100 && pub_r000017_8 <= 100);
    __CPROVER_assume(pub_r000017_9 >= -100 && pub_r000017_9 <= 100);
    __CPROVER_assume(pub_r000017_10 >= -100 && pub_r000017_10 <= 100);
    __CPROVER_assume(pub_r000017_11 >= -100 && pub_r000017_11 <= 100);
    __CPROVER_assume(pub_r000017_12 >= -100 && pub_r000017_12 <= 100);
    __CPROVER_assume(pub_r000017_13 >= -100 && pub_r000017_13 <= 100);
    __CPROVER_assume(pub_r000017_14 >= -100 && pub_r000017_14 <= 100);
    __CPROVER_assume(pub_r000017_15 >= -100 && pub_r000017_15 <= 100);
    __CPROVER_assume(pub_r000017_16 >= -100 && pub_r000017_16 <= 100);
    __CPROVER_assume(pub_r000017_17 >= -100 && pub_r000017_17 <= 100);
    __CPROVER_assume(pub_r000017_18 >= -100 && pub_r000017_18 <= 100);
    __CPROVER_assume(pub_r000017_19 >= -100 && pub_r000017_19 <= 100);
    __CPROVER_assume(sec_r000017_0 >= 0 && sec_r000017_0 <= 255);
    __CPROVER_assume(sec_r000017_1 >= 0 && sec_r000017_1 <= 255);
    __CPROVER_assume(sec_r000017_2 >= 0 && sec_r000017_2 <= 255);
    __CPROVER_assume(sec_r000017_3 >= 0 && sec_r000017_3 <= 255);
    __CPROVER_assume(sec_r000017_4 >= 0 && sec_r000017_4 <= 255);
    __CPROVER_assume(sec_r000017_5 >= 0 && sec_r000017_5 <= 255);
    __CPROVER_assume(sec_r000017_6 >= 0 && sec_r000017_6 <= 255);
    __CPROVER_assume(sec_r000017_7 >= 0 && sec_r000017_7 <= 255);
    __CPROVER_assume(sec_r000017_8 >= 0 && sec_r000017_8 <= 255);
    __CPROVER_assume(sec_r000017_9 >= 0 && sec_r000017_9 <= 255);
    __CPROVER_assume(sec_r000017_10 >= 0 && sec_r000017_10 <= 255);
    __CPROVER_assume(sec_r000017_11 >= 0 && sec_r000017_11 <= 255);
    __CPROVER_assume(sec_r000017_12 >= 0 && sec_r000017_12 <= 255);
    __CPROVER_assume(sec_r000017_13 >= 0 && sec_r000017_13 <= 255);
    __CPROVER_assume(sec_r000017_14 >= 0 && sec_r000017_14 <= 255);
    __CPROVER_assume(sec_r000017_15 >= 0 && sec_r000017_15 <= 255);
    __CPROVER_assume(sec_r000017_16 >= 0 && sec_r000017_16 <= 255);
    __CPROVER_assume(sec_r000017_17 >= 0 && sec_r000017_17 <= 255);
    __CPROVER_assume(sec_r000017_18 >= 0 && sec_r000017_18 <= 255);
    __CPROVER_assume(sec_r000017_19 >= 0 && sec_r000017_19 <= 255);
    __CPROVER_assume(sec_r000017_20 >= 0 && sec_r000017_20 <= 255);

    struct Vector3D_R000017_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000017_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000017_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000017_0 + 7) & 15;
    struct StreamBuffer_R000017_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000017_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000017_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000017_0 + 9) & 15;

    union RegisterBank_R000017_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 36) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 34) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 49) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 29) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 44) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 36) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 51) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 19) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 34) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 28) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 43) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 18) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 33) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 39) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 54) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 19) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 34) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 38) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 53) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000017_12 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_71 = (pub_r000017_11 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000017_11 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000017_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000017_17 & 2) != 0) {
            stage_v_72 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000017_12 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_73 = (pub_r000017_15 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000017_15 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000017_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000017_8 & 2) != 0) {
            stage_v_74 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000017_12 & 2) != 0) {
            stage_v_75 = (pub_r000017_11 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000017_11 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000017_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000017_19 & 2) != 0) {
            stage_v_76 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_77 = (pub_r000017_6 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000017_6 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000017_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000017_20 & 2) != 0) {
            stage_v_78 = (pub_r000017_16 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000017_16 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000017_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000017_11 & 2) != 0) {
            stage_v_79 = (pub_r000017_15 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000017_15 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000017_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000017_3 & 2) != 0) {
            stage_v_80 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000017_8 & 2) != 0) {
            stage_v_81 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000017_6 & 2) != 0) {
            stage_v_82 = (pub_r000017_15 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000017_15 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000017_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_83 = (pub_r000017_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000017_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000017_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000017_1 & 1) != 0) {
        if ((sec_r000017_11 & 2) != 0) {
            stage_v_84 = (pub_r000017_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000017_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000017_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_85 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000017_6 & 1) != 0) {
        if ((sec_r000017_3 & 2) != 0) {
            stage_v_86 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000017_8 & 2) != 0) {
            stage_v_87 = (pub_r000017_15 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000017_15 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000017_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_88 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000017_13 & 1) != 0) {
        if ((sec_r000017_15 & 2) != 0) {
            stage_v_89 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000017_10 & 1) != 0) {
        if ((sec_r000017_6 & 2) != 0) {
            stage_v_90 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000017_1 & 2) != 0) {
            stage_v_91 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_92 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000017_12 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_93 = (pub_r000017_12 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000017_12 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000017_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000017_5 & 2) != 0) {
            stage_v_94 = (pub_r000017_12 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000017_12 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000017_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000017_4 & 2) != 0) {
            stage_v_95 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_96 = (pub_r000017_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000017_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000017_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000017_4 & 1) != 0) {
        if ((sec_r000017_15 & 2) != 0) {
            stage_v_97 = (pub_r000017_17 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000017_17 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000017_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000017_1 & 2) != 0) {
            stage_v_98 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000017_20 & 2) != 0) {
            stage_v_99 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000017_4 & 2) != 0) {
            stage_v_100 = (pub_r000017_16 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000017_16 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000017_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000017_1 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_101 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000017_0 & 2) != 0) {
            stage_v_102 = (pub_r000017_8 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000017_8 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000017_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000017_3 & 1) != 0) {
        if ((sec_r000017_18 & 2) != 0) {
            stage_v_103 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_104 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000017_3 & 2) != 0) {
            stage_v_105 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000017_13 & 1) != 0) {
        if ((sec_r000017_12 & 2) != 0) {
            stage_v_106 = (pub_r000017_17 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000017_17 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000017_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000017_11 & 1) != 0) {
        if ((sec_r000017_19 & 2) != 0) {
            stage_v_107 = (pub_r000017_0 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000017_0 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000017_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_108 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000017_7 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_109 = (pub_r000017_13 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000017_13 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000017_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_110 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000017_2 & 1) != 0) {
        if ((sec_r000017_20 & 2) != 0) {
            stage_v_111 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_112 = (pub_r000017_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000017_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000017_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_113 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000017_8 & 2) != 0) {
            stage_v_114 = (pub_r000017_4 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000017_4 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000017_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000017_5 & 2) != 0) {
            stage_v_115 = (pub_r000017_9 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000017_9 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000017_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000017_15 & 2) != 0) {
            stage_v_116 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000017_6 & 2) != 0) {
            stage_v_117 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000017_16 & 2) != 0) {
            stage_v_118 = (pub_r000017_15 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000017_15 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000017_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000017_16 & 2) != 0) {
            stage_v_119 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000017_12 & 2) != 0) {
            stage_v_120 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_121 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_122 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000017_19 & 2) != 0) {
            stage_v_123 = (pub_r000017_12 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000017_12 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000017_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000017_19 & 1) != 0) {
        if ((sec_r000017_17 & 2) != 0) {
            stage_v_124 = (pub_r000017_17 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000017_17 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000017_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000017_2 & 2) != 0) {
            stage_v_125 = (pub_r000017_16 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000017_16 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000017_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000017_0 & 2) != 0) {
            stage_v_126 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_127 = (pub_r000017_17 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000017_17 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000017_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000017_11 & 1) != 0) {
        if ((sec_r000017_15 & 2) != 0) {
            stage_v_128 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000017_3 & 2) != 0) {
            stage_v_129 = (pub_r000017_17 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000017_17 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000017_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000017_17 & 1) != 0) {
        if ((sec_r000017_5 & 2) != 0) {
            stage_v_130 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_131 = (pub_r000017_3 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000017_3 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000017_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000017_10 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_132 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_133 = (pub_r000017_1 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000017_1 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000017_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000017_19 & 2) != 0) {
            stage_v_134 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_135 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000017_1 & 1) != 0) {
        if ((sec_r000017_9 & 2) != 0) {
            stage_v_136 = (pub_r000017_16 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000017_16 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000017_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000017_14 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_137 = (pub_r000017_5 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000017_5 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000017_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000017_2 & 2) != 0) {
            stage_v_138 = (pub_r000017_8 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000017_8 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000017_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000017_20 & 1) != 0) {
        if ((sec_r000017_20 & 2) != 0) {
            stage_v_139 = (pub_r000017_16 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000017_16 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000017_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000017_16 & 2) != 0) {
            stage_v_140 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_141 = (pub_r000017_11 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000017_11 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000017_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_142 = (pub_r000017_8 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000017_8 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000017_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000017_18 & 1) != 0) {
        if ((sec_r000017_12 & 2) != 0) {
            stage_v_143 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_144 = (pub_r000017_7 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000017_7 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000017_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000017_5 & 1) != 0) {
        if ((sec_r000017_8 & 2) != 0) {
            stage_v_145 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000017_13 & 1) != 0) {
        if ((sec_r000017_5 & 2) != 0) {
            stage_v_146 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000017_7 & 2) != 0) {
            stage_v_147 = (pub_r000017_6 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000017_6 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000017_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000017_10 & 2) != 0) {
            stage_v_148 = (pub_r000017_19 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000017_19 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000017_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000017_5 & 2) != 0) {
            stage_v_149 = (pub_r000017_2 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000017_2 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000017_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000017_5 & 1) != 0) {
        if ((sec_r000017_13 & 2) != 0) {
            stage_v_150 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000017_16 & 1) != 0) {
        if ((sec_r000017_12 & 2) != 0) {
            stage_v_151 = (pub_r000017_14 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000017_14 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000017_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000017_9 & 2) != 0) {
            stage_v_152 = (pub_r000017_12 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000017_12 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000017_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000017_1 & 2) != 0) {
            stage_v_153 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000017_11 & 2) != 0) {
            stage_v_154 = (pub_r000017_1 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000017_1 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000017_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000017_9 & 1) != 0) {
        if ((sec_r000017_14 & 2) != 0) {
            stage_v_155 = (pub_r000017_6 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000017_6 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000017_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000017_18 & 1) != 0) {
        if ((sec_r000017_19 & 2) != 0) {
            stage_v_156 = (pub_r000017_8 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000017_8 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000017_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000017_8 & 1) != 0) {
        if ((sec_r000017_6 & 2) != 0) {
            stage_v_157 = (pub_r000017_10 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000017_10 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000017_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000017_16 & 2) != 0) {
            stage_v_158 = (pub_r000017_18 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000017_18 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000017_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
