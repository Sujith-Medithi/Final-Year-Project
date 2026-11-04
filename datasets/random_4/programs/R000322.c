/*
 * Benchmark Program: R000322
 * Family: arithmetic_flow
 * Generator Seed: 432213
 * High Inputs: 18 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000322_2213_0 {
    int gain;
    int reading;
    int status;
    short offset;
    int threshold;
    short calib;
    int buffer[3];
};

struct EventLog_R000322_2213_1 {
    unsigned char signature;
    int severity;
    int seq;
    int code;
    int buffer[3];
};

struct Vector3D_R000322_2213_2 {
    int coord_z;
    int coord_y;
    int norm_sq;
    short heading;
    int coord_x;
    int buffer[3];
};

union RegisterBank_R000322_2213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000322_2213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_80) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_73 = local_arr[aux % 3];
    acc = (acc + bound_73 * 2) & 127;
    int mask_85 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_85 > 46) {
        acc = (acc + mask_85 * 2 + 5) & 127;
        aux ^= (mask_85 & 15);
    } else {
        acc = (acc - mask_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_1(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_19 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_19 > 41) {
        acc = (acc + accumulator_19 * 2 + 5) & 127;
        aux ^= (accumulator_19 & 15);
    } else {
        acc = (acc - accumulator_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_91 = local_arr[aux % 3];
    acc = (acc + stride_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int offset_23 = local_arr[aux % 3];
    acc = (acc + offset_23 * 2) & 127;
    int factor_69 = (aux + st.buffer[1]) & 3;
    switch (factor_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_54 > 47) {
        acc = (acc + factor_54 * 2 + 5) & 127;
        aux ^= (factor_54 & 15);
    } else {
        acc = (acc - factor_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_3(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_46 = (aux + st.buffer[1]) & 3;
    switch (threshold_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_61 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_61 > 48) {
        acc = (acc + offset_61 * 2 + 5) & 127;
        aux ^= (offset_61 & 15);
    } else {
        acc = (acc - offset_61 + 11) & 127;
        aux += 3;
    }
    int stride_22 = 0;
    for (int k = 0; k < 3; k++) {
        stride_22 = (stride_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_22) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_4(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_79 = (aux + st.buffer[1]) & 3;
    switch (quantum_79) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_17 = local_arr[aux % 3];
    acc = (acc + tracker_17 * 2) & 127;
    int threshold_39 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_39 > 37) {
        acc = (acc + threshold_39 * 2 + 5) & 127;
        aux ^= (threshold_39 & 15);
    } else {
        acc = (acc - threshold_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_5(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_98 = (aux + st.buffer[1]) & 3;
    switch (quotient_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_92 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_92 > 23) {
        acc = (acc + damping_92 * 2 + 5) & 127;
        aux ^= (damping_92 & 15);
    } else {
        acc = (acc - damping_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_24 = local_arr[aux % 3];
    acc = (acc + damping_24 * 2) & 127;
    int damping_22 = (aux + st.buffer[1]) & 3;
    switch (damping_22) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_7(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_60 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_60 = (quotient_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_60) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_8(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int mask_63 = local_arr[aux % 3];
    acc = (acc + mask_63 * 2) & 127;
    int tracker_20 = (aux + st.buffer[1]) & 3;
    switch (tracker_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_70) & 63;
    acc ^= aux;
    int checksum_52 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_52 > 38) {
        acc = (acc + checksum_52 * 2 + 5) & 127;
        aux ^= (checksum_52 & 15);
    } else {
        acc = (acc - checksum_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int margin_95 = local_arr[aux % 3];
    acc = (acc + margin_95 * 2) & 127;
    int stride_42 = (aux + st.buffer[1]) & 3;
    switch (stride_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_52 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_52 = (threshold_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_52) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_10(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int accumulator_86 = local_arr[aux % 3];
    acc = (acc + accumulator_86 * 2) & 127;
    int delta_97 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_97 > 36) {
        acc = (acc + delta_97 * 2 + 5) & 127;
        aux ^= (delta_97 & 15);
    } else {
        acc = (acc - delta_97 + 11) & 127;
        aux += 3;
    }
    int damping_66 = 0;
    for (int k = 0; k < 3; k++) {
        damping_66 = (damping_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_78 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_78 = (cursor_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_78) & 127;
    }
    int metric_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_47 = local_arr[aux % 3];
    acc = (acc + coefficient_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_12(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_45 = (aux + st.buffer[1]) & 3;
    switch (coefficient_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_69 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_69 > 23) {
        acc = (acc + threshold_69 * 2 + 5) & 127;
        aux ^= (threshold_69 & 15);
    } else {
        acc = (acc - threshold_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000322_2213_13(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000322_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_78 = 0;
    for (int k = 0; k < 2; k++) {
        stride_78 = (stride_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_78) & 127;
    }
    int segment_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_95) & 63;
    acc ^= aux;
    int quotient_98 = (aux + st.buffer[1]) & 3;
    switch (quotient_98) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_51 = local_arr[aux % 3];
    acc = (acc + quotient_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int metric_62 = 0;
    for (int k = 0; k < 3; k++) {
        metric_62 = (metric_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_62) & 127;
    }
    int scale_58 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_58 > 50) {
        acc = (acc + scale_58 * 2 + 5) & 127;
        aux ^= (scale_58 & 15);
    } else {
        acc = (acc - scale_58 + 11) & 127;
        aux += 3;
    }
    int sample_86 = (aux + st.buffer[1]) & 3;
    switch (sample_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000322_2213_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int window_20 = local_arr[aux % 3];
    acc = (acc + window_20 * 2) & 127;
    int vector_26 = (aux + st.buffer[1]) & 3;
    switch (vector_26) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000322_0;
    int sec_r000322_1;
    int sec_r000322_2;
    int sec_r000322_3;
    int sec_r000322_4;
    int sec_r000322_5;
    int sec_r000322_6;
    int sec_r000322_7;
    int sec_r000322_8;
    int sec_r000322_9;
    int sec_r000322_10;
    int sec_r000322_11;
    int sec_r000322_12;
    int sec_r000322_13;
    int sec_r000322_14;
    int sec_r000322_15;
    int sec_r000322_16;
    int sec_r000322_17;
    int pub_r000322_0;
    int pub_r000322_1;
    int pub_r000322_2;
    int pub_r000322_3;
    int pub_r000322_4;
    int pub_r000322_5;
    int pub_r000322_6;
    int pub_r000322_7;
    int pub_r000322_8;
    int pub_r000322_9;
    int pub_r000322_10;
    int pub_r000322_11;
    int pub_r000322_12;
    int pub_r000322_13;
    int pub_r000322_14;
    int pub_r000322_15;
    int pub_r000322_16;
    int pub_r000322_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000322_0 >= -100 && pub_r000322_0 <= 100);
    __CPROVER_assume(pub_r000322_1 >= -100 && pub_r000322_1 <= 100);
    __CPROVER_assume(pub_r000322_2 >= -100 && pub_r000322_2 <= 100);
    __CPROVER_assume(pub_r000322_3 >= -100 && pub_r000322_3 <= 100);
    __CPROVER_assume(pub_r000322_4 >= -100 && pub_r000322_4 <= 100);
    __CPROVER_assume(pub_r000322_5 >= -100 && pub_r000322_5 <= 100);
    __CPROVER_assume(pub_r000322_6 >= -100 && pub_r000322_6 <= 100);
    __CPROVER_assume(pub_r000322_7 >= -100 && pub_r000322_7 <= 100);
    __CPROVER_assume(pub_r000322_8 >= -100 && pub_r000322_8 <= 100);
    __CPROVER_assume(pub_r000322_9 >= -100 && pub_r000322_9 <= 100);
    __CPROVER_assume(pub_r000322_10 >= -100 && pub_r000322_10 <= 100);
    __CPROVER_assume(pub_r000322_11 >= -100 && pub_r000322_11 <= 100);
    __CPROVER_assume(pub_r000322_12 >= -100 && pub_r000322_12 <= 100);
    __CPROVER_assume(pub_r000322_13 >= -100 && pub_r000322_13 <= 100);
    __CPROVER_assume(pub_r000322_14 >= -100 && pub_r000322_14 <= 100);
    __CPROVER_assume(pub_r000322_15 >= -100 && pub_r000322_15 <= 100);
    __CPROVER_assume(pub_r000322_16 >= -100 && pub_r000322_16 <= 100);
    __CPROVER_assume(pub_r000322_17 >= -100 && pub_r000322_17 <= 100);
    __CPROVER_assume(sec_r000322_0 >= 0 && sec_r000322_0 <= 255);
    __CPROVER_assume(sec_r000322_1 >= 0 && sec_r000322_1 <= 255);
    __CPROVER_assume(sec_r000322_2 >= 0 && sec_r000322_2 <= 255);
    __CPROVER_assume(sec_r000322_3 >= 0 && sec_r000322_3 <= 255);
    __CPROVER_assume(sec_r000322_4 >= 0 && sec_r000322_4 <= 255);
    __CPROVER_assume(sec_r000322_5 >= 0 && sec_r000322_5 <= 255);
    __CPROVER_assume(sec_r000322_6 >= 0 && sec_r000322_6 <= 255);
    __CPROVER_assume(sec_r000322_7 >= 0 && sec_r000322_7 <= 255);
    __CPROVER_assume(sec_r000322_8 >= 0 && sec_r000322_8 <= 255);
    __CPROVER_assume(sec_r000322_9 >= 0 && sec_r000322_9 <= 255);
    __CPROVER_assume(sec_r000322_10 >= 0 && sec_r000322_10 <= 255);
    __CPROVER_assume(sec_r000322_11 >= 0 && sec_r000322_11 <= 255);
    __CPROVER_assume(sec_r000322_12 >= 0 && sec_r000322_12 <= 255);
    __CPROVER_assume(sec_r000322_13 >= 0 && sec_r000322_13 <= 255);
    __CPROVER_assume(sec_r000322_14 >= 0 && sec_r000322_14 <= 255);
    __CPROVER_assume(sec_r000322_15 >= 0 && sec_r000322_15 <= 255);
    __CPROVER_assume(sec_r000322_16 >= 0 && sec_r000322_16 <= 255);
    __CPROVER_assume(sec_r000322_17 >= 0 && sec_r000322_17 <= 255);

    struct SensorNode_R000322_2213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000322_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000322_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000322_0 + 7) & 15;
    struct EventLog_R000322_2213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000322_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000322_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000322_0 + 9) & 15;
    struct Vector3D_R000322_2213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000322_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000322_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000322_0 + 11) & 15;

    union RegisterBank_R000322_2213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 19) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 34) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
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
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 27) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 42) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 26) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 41) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 42) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 28) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 43) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 27) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 42) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 17) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 32) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 34) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 49) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 36) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 51) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 21) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 36) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 40) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 55) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = table[3];
    table[3] = (table[0] + 199) & 63;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 37) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 52) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_101 = (stage_v_101 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (out_sink > 100) ? (chk_sum & 31) : (107 & 31);
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= (stage_v_102 << 1) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 34) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 49) {
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
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_109 = (stage_v_109 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 11) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 26) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
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

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 12) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 27) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_2.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 127) & 15;
    int stage_v_126 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= stage_v_126;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (out_sink > 100) ? (chk_sum & 31) : (132 & 31);
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= (stage_v_127 << 1) & 127;

    /* Execution Pipeline Stage 128 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 32) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 47) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 15) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 30) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 27) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 42) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[1] * 2 + 442) & 63;
    if (stage_v_145 > 30) {
        out_sink = (out_sink + stage_v_145 - 5) & 255;
        if (stage_v_145 > 45) {
            chk_sum ^= (stage_v_145 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_145 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 18) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 33) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[1] * 2 + 460) & 63;
    if (stage_v_151 > 24) {
        out_sink = (out_sink + stage_v_151 - 5) & 255;
        if (stage_v_151 > 39) {
            chk_sum ^= (stage_v_151 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_151 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 152 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_1.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = table[1];
    table[1] = (table[2] + 315) & 63;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 26) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 41) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_2.buffer[0] ^ 164) & 3;
    switch (stage_v_161) {
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

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 39) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 54) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
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

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_1.buffer[1] * 2 + 523) & 63;
    if (stage_v_172 > 34) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 49) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = table[3];
    table[3] = (table[0] + 351) & 63;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 27) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 42) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = table[1];
    table[1] = (table[2] + 355) & 63;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 179) & 15;
    int stage_v_178 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= stage_v_178;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (out_sink > 100) ? (chk_sum & 31) : (185 & 31);
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= (stage_v_180 << 1) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (out_sink > 100) ? (chk_sum & 31) : (186 & 31);
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= (stage_v_181 << 1) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_182 = (stage_v_182 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_182) & 127;
    }
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = table[3];
    table[3] = (table[0] + 367) & 63;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_184 = (stage_v_184 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 188) & 15;
    int stage_v_187 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= stage_v_187;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (out_sink > 100) ? (chk_sum & 31) : (193 & 31);
    out_sink = (out_sink + stage_v_188) & 255;
    chk_sum ^= (stage_v_188 << 1) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_0.buffer[0] * 2 + 574) & 63;
    if (stage_v_189 > 33) {
        out_sink = (out_sink + stage_v_189 - 5) & 255;
        if (stage_v_189 > 48) {
            chk_sum ^= (stage_v_189 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_189 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_1.buffer[1] * 2 + 577) & 63;
    if (stage_v_190 > 18) {
        out_sink = (out_sink + stage_v_190 - 5) & 255;
        if (stage_v_190 > 33) {
            chk_sum ^= (stage_v_190 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_190 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_2.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] ^ 195) & 3;
    switch (stage_v_192) {
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

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 195) & 15;
    int stage_v_194 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    chk_sum ^= stage_v_194;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 196 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 197) & 15;
    int stage_v_196 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    chk_sum ^= stage_v_196;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 40) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 55) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (st_var_1.buffer[0] ^ 202) & 3;
    switch (stage_v_199) {
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

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (st_var_2.buffer[0] ^ 203) & 3;
    switch (stage_v_200) {
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

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (st_var_0.buffer[0] ^ 204) & 3;
    switch (stage_v_201) {
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

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (out_sink > 100) ? (chk_sum & 31) : (207 & 31);
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= (stage_v_202 << 1) & 127;

    /* Execution Pipeline Stage 203 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 204) & 15;
    int stage_v_203 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    chk_sum ^= stage_v_203;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = table[0];
    table[0] = (table[1] + 409) & 63;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = table[1];
    table[1] = (table[2] + 411) & 63;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = table[2];
    table[2] = (table[3] + 413) & 63;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (st_var_0.buffer[0] ^ 210) & 3;
    switch (stage_v_207) {
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

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000322_3 * 3 + pub_r000322_16) & 127;
    int arith_v_1 = (arith_v_0 ^ (sec_r000322_9 * 2)) & 127;
    int arith_v_2 = (arith_v_1 - (sec_r000322_2 * 2)) & 127;
    out_sink += arith_v_2 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
