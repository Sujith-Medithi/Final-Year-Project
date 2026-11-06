/*
 * Benchmark Program: R000847
 * Security Family: nested_implicit_flow
 * Generator Seed: 584713
 * High Inputs: 21 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000847_4713_0 {
    int heading;
    short coord_z;
    unsigned char coord_x;
    int norm_sq;
    unsigned char coord_y;
    int pitch;
    int buffer[3];
};

struct Transaction_R000847_4713_1 {
    int fee;
    short status;
    int balance;
    int buffer[3];
};

struct DeviceConfig_R000847_4713_2 {
    unsigned char stop_bits;
    unsigned char parity;
    unsigned char baud_rate;
    int buffer[3];
};

union TelemetryField_R000847_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000847_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000847_4713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_15 = local_arr[aux % 3];
    acc = (acc + segment_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_70 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_70 > 48) {
        acc = (acc + vector_70 * 2 + 5) & 127;
        aux ^= (vector_70 & 15);
    } else {
        acc = (acc - vector_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000847_4713_1(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_2(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_94) & 63;
    acc ^= aux;
    int segment_41 = (aux + st.buffer[1]) & 3;
    switch (segment_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_72 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_72 > 14) {
        acc = (acc + factor_72 * 2 + 5) & 127;
        aux ^= (factor_72 & 15);
    } else {
        acc = (acc - factor_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000847_4713_3(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_74 = (aux + st.buffer[1]) & 3;
    switch (offset_74) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_42 = local_arr[aux % 3];
    acc = (acc + offset_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int coefficient_93 = local_arr[aux % 3];
    acc = (acc + coefficient_93 * 2) & 127;
    int mask_61 = (aux + st.buffer[1]) & 3;
    switch (mask_61) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_88) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_99 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_99 > 45) {
        acc = (acc + bound_99 * 2 + 5) & 127;
        aux ^= (bound_99 & 15);
    } else {
        acc = (acc - bound_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000847_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_67) & 63;
    acc ^= aux;
    int sample_50 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_50 > 25) {
        acc = (acc + sample_50 * 2 + 5) & 127;
        aux ^= (sample_50 & 15);
    } else {
        acc = (acc - sample_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_83) & 63;
    acc ^= aux;
    int bound_10 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_10 > 23) {
        acc = (acc + bound_10 * 2 + 5) & 127;
        aux ^= (bound_10 & 15);
    } else {
        acc = (acc - bound_10 + 11) & 127;
        aux += 3;
    }
    int metric_93 = (aux + st.buffer[1]) & 3;
    switch (metric_93) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_99 = local_arr[aux % 3];
    acc = (acc + coefficient_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_68 = (aux + st.buffer[1]) & 3;
    switch (quotient_68) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_13) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_81 = local_arr[aux % 3];
    acc = (acc + metric_81 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_10(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int metric_68 = local_arr[aux % 3];
    acc = (acc + metric_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_11(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int pivot_62 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_62 > 15) {
        acc = (acc + pivot_62 * 2 + 5) & 127;
        aux ^= (pivot_62 & 15);
    } else {
        acc = (acc - pivot_62 + 11) & 127;
        aux += 3;
    }
    int tracker_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_98 = local_arr[aux % 3];
    acc = (acc + margin_98 * 2) & 127;
    int metric_30 = (aux + st.buffer[1]) & 3;
    switch (metric_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000847_4713_12(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int index_reg_45 = (aux + st.buffer[1]) & 3;
    switch (index_reg_45) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000847_4713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_33 > 28) {
        acc = (acc + factor_33 * 2 + 5) & 127;
        aux ^= (factor_33 & 15);
    } else {
        acc = (acc - factor_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000847_4713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000847_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_36 = (aux + st.buffer[1]) & 3;
    switch (phase_36) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000847_4713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_24 = (aux + st.buffer[1]) & 3;
    switch (checksum_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000847_4713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000847_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_79 = (aux + st.buffer[1]) & 3;
    switch (coefficient_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000847_4713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000847_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int coefficient_77 = local_arr[aux % 3];
    acc = (acc + coefficient_77 * 2) & 127;
    int offset_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_43) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000847_0;
    int sec_r000847_1;
    int sec_r000847_2;
    int sec_r000847_3;
    int sec_r000847_4;
    int sec_r000847_5;
    int sec_r000847_6;
    int sec_r000847_7;
    int sec_r000847_8;
    int sec_r000847_9;
    int sec_r000847_10;
    int sec_r000847_11;
    int sec_r000847_12;
    int sec_r000847_13;
    int sec_r000847_14;
    int sec_r000847_15;
    int sec_r000847_16;
    int sec_r000847_17;
    int sec_r000847_18;
    int sec_r000847_19;
    int sec_r000847_20;
    int pub_r000847_0;
    int pub_r000847_1;
    int pub_r000847_2;
    int pub_r000847_3;
    int pub_r000847_4;
    int pub_r000847_5;
    int pub_r000847_6;
    int pub_r000847_7;
    int pub_r000847_8;
    int pub_r000847_9;
    int pub_r000847_10;
    int pub_r000847_11;
    int pub_r000847_12;
    int pub_r000847_13;
    int pub_r000847_14;
    int pub_r000847_15;
    int pub_r000847_16;
    int pub_r000847_17;
    int pub_r000847_18;
    int pub_r000847_19;
    int pub_r000847_20;
    int pub_r000847_21;
    int pub_r000847_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000847_0 >= -100 && pub_r000847_0 <= 100);
    __CPROVER_assume(pub_r000847_1 >= -100 && pub_r000847_1 <= 100);
    __CPROVER_assume(pub_r000847_2 >= -100 && pub_r000847_2 <= 100);
    __CPROVER_assume(pub_r000847_3 >= -100 && pub_r000847_3 <= 100);
    __CPROVER_assume(pub_r000847_4 >= -100 && pub_r000847_4 <= 100);
    __CPROVER_assume(pub_r000847_5 >= -100 && pub_r000847_5 <= 100);
    __CPROVER_assume(pub_r000847_6 >= -100 && pub_r000847_6 <= 100);
    __CPROVER_assume(pub_r000847_7 >= -100 && pub_r000847_7 <= 100);
    __CPROVER_assume(pub_r000847_8 >= -100 && pub_r000847_8 <= 100);
    __CPROVER_assume(pub_r000847_9 >= -100 && pub_r000847_9 <= 100);
    __CPROVER_assume(pub_r000847_10 >= -100 && pub_r000847_10 <= 100);
    __CPROVER_assume(pub_r000847_11 >= -100 && pub_r000847_11 <= 100);
    __CPROVER_assume(pub_r000847_12 >= -100 && pub_r000847_12 <= 100);
    __CPROVER_assume(pub_r000847_13 >= -100 && pub_r000847_13 <= 100);
    __CPROVER_assume(pub_r000847_14 >= -100 && pub_r000847_14 <= 100);
    __CPROVER_assume(pub_r000847_15 >= -100 && pub_r000847_15 <= 100);
    __CPROVER_assume(pub_r000847_16 >= -100 && pub_r000847_16 <= 100);
    __CPROVER_assume(pub_r000847_17 >= -100 && pub_r000847_17 <= 100);
    __CPROVER_assume(pub_r000847_18 >= -100 && pub_r000847_18 <= 100);
    __CPROVER_assume(pub_r000847_19 >= -100 && pub_r000847_19 <= 100);
    __CPROVER_assume(pub_r000847_20 >= -100 && pub_r000847_20 <= 100);
    __CPROVER_assume(pub_r000847_21 >= -100 && pub_r000847_21 <= 100);
    __CPROVER_assume(pub_r000847_22 >= -100 && pub_r000847_22 <= 100);
    __CPROVER_assume(sec_r000847_0 >= 0 && sec_r000847_0 <= 255);
    __CPROVER_assume(sec_r000847_1 >= 0 && sec_r000847_1 <= 255);
    __CPROVER_assume(sec_r000847_2 >= 0 && sec_r000847_2 <= 255);
    __CPROVER_assume(sec_r000847_3 >= 0 && sec_r000847_3 <= 255);
    __CPROVER_assume(sec_r000847_4 >= 0 && sec_r000847_4 <= 255);
    __CPROVER_assume(sec_r000847_5 >= 0 && sec_r000847_5 <= 255);
    __CPROVER_assume(sec_r000847_6 >= 0 && sec_r000847_6 <= 255);
    __CPROVER_assume(sec_r000847_7 >= 0 && sec_r000847_7 <= 255);
    __CPROVER_assume(sec_r000847_8 >= 0 && sec_r000847_8 <= 255);
    __CPROVER_assume(sec_r000847_9 >= 0 && sec_r000847_9 <= 255);
    __CPROVER_assume(sec_r000847_10 >= 0 && sec_r000847_10 <= 255);
    __CPROVER_assume(sec_r000847_11 >= 0 && sec_r000847_11 <= 255);
    __CPROVER_assume(sec_r000847_12 >= 0 && sec_r000847_12 <= 255);
    __CPROVER_assume(sec_r000847_13 >= 0 && sec_r000847_13 <= 255);
    __CPROVER_assume(sec_r000847_14 >= 0 && sec_r000847_14 <= 255);
    __CPROVER_assume(sec_r000847_15 >= 0 && sec_r000847_15 <= 255);
    __CPROVER_assume(sec_r000847_16 >= 0 && sec_r000847_16 <= 255);
    __CPROVER_assume(sec_r000847_17 >= 0 && sec_r000847_17 <= 255);
    __CPROVER_assume(sec_r000847_18 >= 0 && sec_r000847_18 <= 255);
    __CPROVER_assume(sec_r000847_19 >= 0 && sec_r000847_19 <= 255);
    __CPROVER_assume(sec_r000847_20 >= 0 && sec_r000847_20 <= 255);

    struct Vector3D_R000847_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000847_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000847_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000847_0 + 7) & 15;
    struct Transaction_R000847_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000847_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000847_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000847_0 + 9) & 15;
    struct DeviceConfig_R000847_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000847_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000847_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000847_0 + 11) & 15;

    union TelemetryField_R000847_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 30) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 45) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 28) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 43) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 40) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 55) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 32) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 47) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

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
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 13) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 28) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 16) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 31) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 31) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 46) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000847_4 & 1) != 0) {
        if ((sec_r000847_11 & 2) != 0) {
            stage_v_39 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000847_1 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_40 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000847_4 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_41 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_42 = (pub_r000847_9 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000847_9 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000847_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000847_1 & 1) != 0) {
        if ((sec_r000847_11 & 2) != 0) {
            stage_v_43 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_44 = (pub_r000847_2 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000847_2 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000847_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_45 = (pub_r000847_18 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000847_18 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000847_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000847_3 & 1) != 0) {
        if ((sec_r000847_12 & 2) != 0) {
            stage_v_46 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_47 = (pub_r000847_16 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000847_16 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000847_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_48 = (pub_r000847_7 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000847_7 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000847_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000847_9 & 2) != 0) {
            stage_v_49 = (pub_r000847_9 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000847_9 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000847_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_50 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000847_16 & 1) != 0) {
        if ((sec_r000847_17 & 2) != 0) {
            stage_v_51 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_52 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000847_17 & 2) != 0) {
            stage_v_53 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_4 & 2) != 0) {
            stage_v_54 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_55 = (pub_r000847_6 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000847_6 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000847_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_56 = (pub_r000847_9 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000847_9 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000847_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_57 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000847_5 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_58 = (pub_r000847_18 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000847_18 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000847_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000847_0 & 2) != 0) {
            stage_v_59 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000847_3 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_60 = (pub_r000847_20 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000847_20 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000847_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000847_18 & 2) != 0) {
            stage_v_61 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_62 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_63 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_64 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000847_4 & 2) != 0) {
            stage_v_65 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000847_7 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_66 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000847_11 & 1) != 0) {
        if ((sec_r000847_9 & 2) != 0) {
            stage_v_67 = (pub_r000847_15 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000847_15 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000847_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000847_20 & 2) != 0) {
            stage_v_68 = (pub_r000847_18 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000847_18 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000847_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000847_3 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_69 = (pub_r000847_15 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000847_15 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000847_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000847_3 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_70 = (pub_r000847_2 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000847_2 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000847_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000847_18 & 2) != 0) {
            stage_v_71 = (pub_r000847_13 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000847_13 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000847_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_72 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000847_9 & 2) != 0) {
            stage_v_73 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000847_9 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_74 = (pub_r000847_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000847_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000847_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_75 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000847_17 & 2) != 0) {
            stage_v_76 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_77 = (pub_r000847_6 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000847_6 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000847_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000847_5 & 2) != 0) {
            stage_v_78 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000847_8 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_79 = (pub_r000847_18 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000847_18 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000847_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_80 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_81 = (pub_r000847_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000847_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000847_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_82 = (pub_r000847_21 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000847_21 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000847_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000847_7 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_83 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000847_15 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_84 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000847_5 & 2) != 0) {
            stage_v_85 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_86 = (pub_r000847_7 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000847_7 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000847_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_87 = (pub_r000847_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000847_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000847_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000847_15 & 2) != 0) {
            stage_v_88 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_89 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000847_17 & 2) != 0) {
            stage_v_90 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000847_0 & 1) != 0) {
        if ((sec_r000847_6 & 2) != 0) {
            stage_v_91 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_92 = (pub_r000847_2 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000847_2 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000847_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000847_15 & 2) != 0) {
            stage_v_93 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000847_16 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_94 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000847_13 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_95 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_96 = (pub_r000847_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000847_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000847_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000847_16 & 1) != 0) {
        if ((sec_r000847_2 & 2) != 0) {
            stage_v_97 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_98 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000847_9 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_99 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_12 & 2) != 0) {
            stage_v_100 = (pub_r000847_6 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000847_6 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000847_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000847_20 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_101 = (pub_r000847_12 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000847_12 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000847_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000847_15 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_102 = (pub_r000847_20 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000847_20 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000847_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000847_7 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_103 = (pub_r000847_12 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000847_12 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000847_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_104 = (pub_r000847_22 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000847_22 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000847_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_105 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000847_11 & 2) != 0) {
            stage_v_106 = (pub_r000847_13 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000847_13 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000847_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000847_19 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_107 = (pub_r000847_16 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000847_16 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000847_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_108 = (pub_r000847_22 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000847_22 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000847_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000847_2 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_109 = (pub_r000847_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000847_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000847_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_110 = (pub_r000847_4 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000847_4 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000847_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_111 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000847_10 & 2) != 0) {
            stage_v_112 = (pub_r000847_5 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000847_5 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000847_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_18 & 2) != 0) {
            stage_v_113 = (pub_r000847_21 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000847_21 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000847_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_5 & 2) != 0) {
            stage_v_114 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000847_6 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_115 = (pub_r000847_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000847_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000847_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000847_14 & 2) != 0) {
            stage_v_116 = (pub_r000847_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000847_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000847_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000847_16 & 2) != 0) {
            stage_v_117 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000847_7 & 1) != 0) {
        if ((sec_r000847_8 & 2) != 0) {
            stage_v_118 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_119 = (pub_r000847_16 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000847_16 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000847_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_120 = (pub_r000847_11 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000847_11 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000847_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_121 = (pub_r000847_17 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000847_17 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000847_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000847_12 & 1) != 0) {
        if ((sec_r000847_6 & 2) != 0) {
            stage_v_122 = (pub_r000847_16 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000847_16 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000847_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_123 = (pub_r000847_8 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000847_8 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000847_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000847_0 & 2) != 0) {
            stage_v_124 = (pub_r000847_14 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000847_14 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000847_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000847_20 & 2) != 0) {
            stage_v_125 = (pub_r000847_15 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000847_15 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000847_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_126 = (pub_r000847_14 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000847_14 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000847_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000847_1 & 1) != 0) {
        if ((sec_r000847_9 & 2) != 0) {
            stage_v_127 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000847_0 & 2) != 0) {
            stage_v_128 = (pub_r000847_0 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000847_0 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000847_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000847_3 & 1) != 0) {
        if ((sec_r000847_3 & 2) != 0) {
            stage_v_129 = (pub_r000847_19 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000847_19 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000847_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000847_7 & 1) != 0) {
        if ((sec_r000847_1 & 2) != 0) {
            stage_v_130 = (pub_r000847_20 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000847_20 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000847_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000847_19 & 2) != 0) {
            stage_v_131 = (pub_r000847_9 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000847_9 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000847_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000847_7 & 2) != 0) {
            stage_v_132 = (pub_r000847_6 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000847_6 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000847_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000847_0 & 2) != 0) {
            stage_v_133 = (pub_r000847_1 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000847_1 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000847_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000847_0 & 1) != 0) {
        if ((sec_r000847_6 & 2) != 0) {
            stage_v_134 = (pub_r000847_14 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000847_14 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000847_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000847_15 & 1) != 0) {
        if ((sec_r000847_11 & 2) != 0) {
            stage_v_135 = (pub_r000847_22 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000847_22 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000847_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000847_5 & 2) != 0) {
            stage_v_136 = (pub_r000847_6 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000847_6 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000847_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000847_20 & 1) != 0) {
        if ((sec_r000847_13 & 2) != 0) {
            stage_v_137 = (pub_r000847_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000847_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000847_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000847_6 & 2) != 0) {
            stage_v_138 = (pub_r000847_21 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000847_21 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000847_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
