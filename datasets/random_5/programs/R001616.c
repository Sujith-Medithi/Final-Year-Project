/*
 * Benchmark Program: R001616
 * Security Family: implicit_flow
 * Generator Seed: 661613
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001616_1613_0 {
    short coord_y;
    unsigned char coord_x;
    short norm_sq;
    unsigned char pitch;
    short heading;
    int buffer[3];
};

struct Transaction_R001616_1613_1 {
    int account_id;
    int status;
    int balance;
    int buffer[3];
};

union TelemetryField_R001616_1613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001616_1613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001616_1613_0(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_25 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_25 > 25) {
        acc = (acc + pivot_25 * 2 + 5) & 127;
        aux ^= (pivot_25 & 15);
    } else {
        acc = (acc - pivot_25 + 11) & 127;
        aux += 3;
    }
    int pivot_63 = (aux + st.buffer[1]) & 3;
    switch (pivot_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_1(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_68 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_68 > 16) {
        acc = (acc + parity_68 * 2 + 5) & 127;
        aux ^= (parity_68 & 15);
    } else {
        acc = (acc - parity_68 + 11) & 127;
        aux += 3;
    }
    int residue_20 = (aux + st.buffer[1]) & 3;
    switch (residue_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_2(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_36 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_36 = (accumulator_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_36) & 127;
    }
    int coefficient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_22) & 63;
    acc ^= aux;
    int damping_25 = (aux + st.buffer[1]) & 3;
    switch (damping_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_3(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_45 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_45 = (index_reg_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_4(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int stride_47 = local_arr[aux % 3];
    acc = (acc + stride_47 * 2) & 127;
    int accumulator_29 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_29 > 21) {
        acc = (acc + accumulator_29 * 2 + 5) & 127;
        aux ^= (accumulator_29 & 15);
    } else {
        acc = (acc - accumulator_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_5(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_54) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_34 = local_arr[aux % 3];
    acc = (acc + segment_34 * 2) & 127;
    int damping_92 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_92 > 21) {
        acc = (acc + damping_92 * 2 + 5) & 127;
        aux ^= (damping_92 & 15);
    } else {
        acc = (acc - damping_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_97 = (aux + st.buffer[1]) & 3;
    switch (threshold_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001616_1613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_72) & 63;
    acc ^= aux;
    int factor_63 = (aux + st.buffer[1]) & 3;
    switch (factor_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 31) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001616_1613_8(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_30 = 0;
    for (int k = 0; k < 2; k++) {
        offset_30 = (offset_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_30) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_49 = local_arr[aux % 3];
    acc = (acc + index_reg_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001616_1613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_38 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_38 = (quantum_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_38) & 127;
    }
    int damping_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_32) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_49 = local_arr[aux % 3];
    acc = (acc + quotient_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001616_1613_10(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_44 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_44 > 29) {
        acc = (acc + parity_44 * 2 + 5) & 127;
        aux ^= (parity_44 & 15);
    } else {
        acc = (acc - parity_44 + 11) & 127;
        aux += 3;
    }
    int checksum_19 = (aux + st.buffer[1]) & 3;
    switch (checksum_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_78) & 63;
    acc ^= aux;
    int coefficient_79 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_79 = (coefficient_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_79) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int damping_22 = local_arr[aux % 3];
    acc = (acc + damping_22 * 2) & 127;
    int parity_68 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_68 > 13) {
        acc = (acc + parity_68 * 2 + 5) & 127;
        aux ^= (parity_68 & 15);
    } else {
        acc = (acc - parity_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int parity_78 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_78 > 12) {
        acc = (acc + parity_78 * 2 + 5) & 127;
        aux ^= (parity_78 & 15);
    } else {
        acc = (acc - parity_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_74 = local_arr[aux % 3];
    acc = (acc + index_reg_74 * 2) & 127;
    int segment_10 = (aux + st.buffer[1]) & 3;
    switch (segment_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_25 = 0;
    for (int k = 0; k < 3; k++) {
        damping_25 = (damping_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_25) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_93 = local_arr[aux % 3];
    acc = (acc + metric_93 * 2) & 127;
    int cursor_88 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_88 > 41) {
        acc = (acc + cursor_88 * 2 + 5) & 127;
        aux ^= (cursor_88 & 15);
    } else {
        acc = (acc - cursor_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_14(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001616_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_19 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_19 > 27) {
        acc = (acc + damping_19 * 2 + 5) & 127;
        aux ^= (damping_19 & 15);
    } else {
        acc = (acc - damping_19 + 11) & 127;
        aux += 3;
    }
    int scale_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001616_1613_15(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int metric_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_88) & 63;
    acc ^= aux;
    int checksum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_32 > 44) {
        acc = (acc + checksum_32 * 2 + 5) & 127;
        aux ^= (checksum_32 & 15);
    } else {
        acc = (acc - checksum_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001616_1613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001616_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_24 = local_arr[aux % 3];
    acc = (acc + factor_24 * 2) & 127;
    int coefficient_55 = (aux + st.buffer[1]) & 3;
    switch (coefficient_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001616_0;
    int sec_r001616_1;
    int sec_r001616_2;
    int sec_r001616_3;
    int sec_r001616_4;
    int sec_r001616_5;
    int sec_r001616_6;
    int sec_r001616_7;
    int sec_r001616_8;
    int sec_r001616_9;
    int sec_r001616_10;
    int sec_r001616_11;
    int sec_r001616_12;
    int sec_r001616_13;
    int sec_r001616_14;
    int sec_r001616_15;
    int pub_r001616_0;
    int pub_r001616_1;
    int pub_r001616_2;
    int pub_r001616_3;
    int pub_r001616_4;
    int pub_r001616_5;
    int pub_r001616_6;
    int pub_r001616_7;
    int pub_r001616_8;
    int pub_r001616_9;
    int pub_r001616_10;
    int pub_r001616_11;
    int pub_r001616_12;
    int pub_r001616_13;
    int pub_r001616_14;
    int pub_r001616_15;
    int pub_r001616_16;
    int pub_r001616_17;
    int pub_r001616_18;
    int pub_r001616_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001616_0 >= -100 && pub_r001616_0 <= 100);
    __CPROVER_assume(pub_r001616_1 >= -100 && pub_r001616_1 <= 100);
    __CPROVER_assume(pub_r001616_2 >= -100 && pub_r001616_2 <= 100);
    __CPROVER_assume(pub_r001616_3 >= -100 && pub_r001616_3 <= 100);
    __CPROVER_assume(pub_r001616_4 >= -100 && pub_r001616_4 <= 100);
    __CPROVER_assume(pub_r001616_5 >= -100 && pub_r001616_5 <= 100);
    __CPROVER_assume(pub_r001616_6 >= -100 && pub_r001616_6 <= 100);
    __CPROVER_assume(pub_r001616_7 >= -100 && pub_r001616_7 <= 100);
    __CPROVER_assume(pub_r001616_8 >= -100 && pub_r001616_8 <= 100);
    __CPROVER_assume(pub_r001616_9 >= -100 && pub_r001616_9 <= 100);
    __CPROVER_assume(pub_r001616_10 >= -100 && pub_r001616_10 <= 100);
    __CPROVER_assume(pub_r001616_11 >= -100 && pub_r001616_11 <= 100);
    __CPROVER_assume(pub_r001616_12 >= -100 && pub_r001616_12 <= 100);
    __CPROVER_assume(pub_r001616_13 >= -100 && pub_r001616_13 <= 100);
    __CPROVER_assume(pub_r001616_14 >= -100 && pub_r001616_14 <= 100);
    __CPROVER_assume(pub_r001616_15 >= -100 && pub_r001616_15 <= 100);
    __CPROVER_assume(pub_r001616_16 >= -100 && pub_r001616_16 <= 100);
    __CPROVER_assume(pub_r001616_17 >= -100 && pub_r001616_17 <= 100);
    __CPROVER_assume(pub_r001616_18 >= -100 && pub_r001616_18 <= 100);
    __CPROVER_assume(pub_r001616_19 >= -100 && pub_r001616_19 <= 100);
    __CPROVER_assume(sec_r001616_0 >= 0 && sec_r001616_0 <= 255);
    __CPROVER_assume(sec_r001616_1 >= 0 && sec_r001616_1 <= 255);
    __CPROVER_assume(sec_r001616_2 >= 0 && sec_r001616_2 <= 255);
    __CPROVER_assume(sec_r001616_3 >= 0 && sec_r001616_3 <= 255);
    __CPROVER_assume(sec_r001616_4 >= 0 && sec_r001616_4 <= 255);
    __CPROVER_assume(sec_r001616_5 >= 0 && sec_r001616_5 <= 255);
    __CPROVER_assume(sec_r001616_6 >= 0 && sec_r001616_6 <= 255);
    __CPROVER_assume(sec_r001616_7 >= 0 && sec_r001616_7 <= 255);
    __CPROVER_assume(sec_r001616_8 >= 0 && sec_r001616_8 <= 255);
    __CPROVER_assume(sec_r001616_9 >= 0 && sec_r001616_9 <= 255);
    __CPROVER_assume(sec_r001616_10 >= 0 && sec_r001616_10 <= 255);
    __CPROVER_assume(sec_r001616_11 >= 0 && sec_r001616_11 <= 255);
    __CPROVER_assume(sec_r001616_12 >= 0 && sec_r001616_12 <= 255);
    __CPROVER_assume(sec_r001616_13 >= 0 && sec_r001616_13 <= 255);
    __CPROVER_assume(sec_r001616_14 >= 0 && sec_r001616_14 <= 255);
    __CPROVER_assume(sec_r001616_15 >= 0 && sec_r001616_15 <= 255);

    struct Vector3D_R001616_1613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001616_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001616_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001616_0 + 7) & 15;
    struct Transaction_R001616_1613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001616_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001616_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001616_0 + 9) & 15;

    union TelemetryField_R001616_1613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001616_1613_0(sec_r001616_0, pub_r001616_1);
    int helper_flow_1 = fn_R001616_1613_1(sec_r001616_1, sec_r001616_2, pub_r001616_3);
    int helper_flow_2 = fn_R001616_1613_2(sec_r001616_2, sec_r001616_3);
    int helper_flow_3 = fn_R001616_1613_3(sec_r001616_3, pub_r001616_4);
    int helper_flow_4 = fn_R001616_1613_4(sec_r001616_4, sec_r001616_5, pub_r001616_6);
    int helper_flow_5 = fn_R001616_1613_5(sec_r001616_5, sec_r001616_6);
    int helper_flow_6 = fn_R001616_1613_6(sec_r001616_6, sec_r001616_7, pub_r001616_8, pub_r001616_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_5 + pub_r001616_10 * 2 + 5) & 127;
    if (stage_v_0 > 31) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001616_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001616_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_0 + pub_r001616_9 * 2 + 14) & 127;
    if (stage_v_3 > 36) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001616_0 + pub_r001616_16 * 2 + 17) & 127;
    if (stage_v_4 > 45) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_1 + pub_r001616_14 * 2 + 20) & 127;
    if (stage_v_5 > 19) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001616_2 + pub_r001616_5 * 2 + 23) & 127;
    if (stage_v_6 > 54) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_6 + pub_r001616_8 * 2 + 26) & 127;
    if (stage_v_7 > 19) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001616_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001616_14 + pub_r001616_11 * 2 + 32) & 127;
    if (stage_v_9 > 26) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001616_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001616_15 + pub_r001616_1 * 2 + 38) & 127;
    if (stage_v_11 > 35) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001616_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001616_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001616_10 + pub_r001616_2 * 2 + 47) & 127;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001616_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001616_8 + pub_r001616_3 * 2 + 53) & 127;
    if (stage_v_16 > 60) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001616_15 + pub_r001616_2 * 2 + 56) & 127;
    if (stage_v_17 > 52) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001616_14 + pub_r001616_19 * 2 + 59) & 127;
    if (stage_v_18 > 36) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_0 + pub_r001616_8 * 2 + 62) & 127;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_2 + pub_r001616_11 * 2 + 65) & 127;
    if (stage_v_20 > 52) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001616_13 + pub_r001616_19 * 2 + 68) & 127;
    if (stage_v_21 > 39) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_20 + pub_r001616_7 * 2 + 71) & 127;
    if (stage_v_22 > 38) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001616_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001616_13 + pub_r001616_1 * 2 + 77) & 127;
    if (stage_v_24 > 53) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001616_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_2 + pub_r001616_13 * 2 + 83) & 127;
    if (stage_v_26 > 19) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001616_6 + pub_r001616_8 * 2 + 86) & 127;
    if (stage_v_27 > 22) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001616_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001616_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001616_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001616_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001616_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001616_2 + pub_r001616_7 * 2 + 104) & 127;
    if (stage_v_33 > 44) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001616_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001616_5 + pub_r001616_17 * 2 + 110) & 127;
    if (stage_v_35 > 40) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001616_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_18 + pub_r001616_5 * 2 + 116) & 127;
    if (stage_v_37 > 24) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001616_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001616_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001616_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_17 + pub_r001616_7 * 2 + 128) & 127;
    if (stage_v_41 > 15) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001616_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_26 + pub_r001616_1 * 2 + 134) & 127;
    if (stage_v_43 > 16) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_3 + pub_r001616_17 * 2 + 137) & 127;
    if (stage_v_44 > 28) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001616_8 + pub_r001616_12 * 2 + 140) & 127;
    if (stage_v_45 > 49) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001616_7 + pub_r001616_19 * 2 + 143) & 127;
    if (stage_v_46 > 33) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001616_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001616_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001616_12 + pub_r001616_17 * 2 + 152) & 127;
    if (stage_v_49 > 31) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_9 + pub_r001616_17 * 2 + 155) & 127;
    if (stage_v_50 > 50) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001616_14 + pub_r001616_5 * 2 + 158) & 127;
    if (stage_v_51 > 41) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_5 + pub_r001616_2 * 2 + 161) & 127;
    if (stage_v_52 > 41) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_22 + pub_r001616_1 * 2 + 164) & 127;
    if (stage_v_53 > 27) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_19 + pub_r001616_4 * 2 + 167) & 127;
    if (stage_v_54 > 58) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001616_8 + pub_r001616_12 * 2 + 170) & 127;
    if (stage_v_55 > 59) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_21 + pub_r001616_9 * 2 + 173) & 127;
    if (stage_v_56 > 60) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_3 + pub_r001616_18 * 2 + 176) & 127;
    if (stage_v_57 > 33) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001616_12 + pub_r001616_9 * 2 + 179) & 127;
    if (stage_v_58 > 30) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_57 + pub_r001616_14 * 2 + 182) & 127;
    if (stage_v_59 > 60) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001616_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (helper_flow_6 + pub_r001616_6 * 2 + 188) & 127;
    if (stage_v_61 > 18) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_0 + pub_r001616_3 * 2 + 191) & 127;
    if (stage_v_62 > 21) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001616_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_2 + pub_r001616_14 * 2 + 197) & 127;
    if (stage_v_64 > 36) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001616_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_41 + pub_r001616_5 * 2 + 203) & 127;
    if (stage_v_66 > 27) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_5 + pub_r001616_2 * 2 + 206) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_16 + pub_r001616_16 * 2 + 209) & 127;
    if (stage_v_68 > 53) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_6 + pub_r001616_14 * 2 + 212) & 127;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (helper_flow_6 + pub_r001616_19 * 2 + 215) & 127;
    if (stage_v_70 > 34) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001616_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001616_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_14 + pub_r001616_1 * 2 + 224) & 127;
    if (stage_v_73 > 34) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001616_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001616_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_41 + pub_r001616_14 * 2 + 233) & 127;
    if (stage_v_76 > 19) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_54 + pub_r001616_12 * 2 + 236) & 127;
    if (stage_v_77 > 48) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001616_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_17 + pub_r001616_15 * 2 + 242) & 127;
    if (stage_v_79 > 36) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_41 + pub_r001616_14 * 2 + 245) & 127;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001616_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_79 + pub_r001616_13 * 2 + 251) & 127;
    if (stage_v_82 > 28) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_57 + pub_r001616_13 * 2 + 254) & 127;
    if (stage_v_83 > 39) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001616_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001616_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_76 + pub_r001616_16 * 2 + 263) & 127;
    if (stage_v_86 > 35) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001616_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_41 + pub_r001616_4 * 2 + 269) & 127;
    if (stage_v_88 > 23) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_44 + pub_r001616_3 * 2 + 272) & 127;
    if (stage_v_89 > 29) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001616_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001616_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001616_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001616_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001616_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001616_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_11 + pub_r001616_4 * 2 + 293) & 127;
    if (stage_v_96 > 50) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001616_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001616_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_16 + pub_r001616_11 * 2 + 302) & 127;
    if (stage_v_99 > 29) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001616_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001616_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_17 + pub_r001616_10 * 2 + 311) & 127;
    if (stage_v_102 > 36) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_7 + pub_r001616_15 * 2 + 314) & 127;
    if (stage_v_103 > 25) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001616_0 + pub_r001616_18 * 2 + 317) & 127;
    if (stage_v_104 > 43) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001616_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001616_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_59 + pub_r001616_2 * 2 + 326) & 127;
    if (stage_v_107 > 58) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_9 + pub_r001616_1 * 2 + 329) & 127;
    if (stage_v_108 > 46) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_107 + pub_r001616_13 * 2 + 332) & 127;
    if (stage_v_109 > 30) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_20 + pub_r001616_17 * 2 + 335) & 127;
    if (stage_v_110 > 37) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_77 + pub_r001616_10 * 2 + 338) & 127;
    if (stage_v_111 > 15) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_46 + pub_r001616_1 * 2 + 341) & 127;
    if (stage_v_112 > 15) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001616_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001616_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001616_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_41 + pub_r001616_6 * 2 + 353) & 127;
    if (stage_v_116 > 44) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_79 + pub_r001616_18 * 2 + 356) & 127;
    if (stage_v_117 > 27) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_18 + pub_r001616_19 * 2 + 359) & 127;
    if (stage_v_118 > 26) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_77 + pub_r001616_5 * 2 + 362) & 127;
    if (stage_v_119 > 15) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_56 + pub_r001616_8 * 2 + 365) & 127;
    if (stage_v_120 > 26) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001616_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001616_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_22 + pub_r001616_9 * 2 + 374) & 127;
    if (stage_v_123 > 35) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001616_8 + pub_r001616_9 * 2 + 377) & 127;
    if (stage_v_124 > 24) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001616_11 + pub_r001616_18 * 2 + 380) & 127;
    if (stage_v_125 > 59) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_9 + pub_r001616_7 * 2 + 383) & 127;
    if (stage_v_126 > 59) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_44 + pub_r001616_16 * 2 + 386) & 127;
    if (stage_v_127 > 48) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001616_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_41 + pub_r001616_3 * 2 + 392) & 127;
    if (stage_v_129 > 29) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001616_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001616_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_9 + pub_r001616_1 * 2 + 401) & 127;
    if (stage_v_132 > 43) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001616_6 + pub_r001616_4 * 2 + 404) & 127;
    if (stage_v_133 > 16) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_9 + pub_r001616_8 * 2 + 407) & 127;
    if (stage_v_134 > 43) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_6 + pub_r001616_18 * 2 + 410) & 127;
    if (stage_v_135 > 31) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_41 + pub_r001616_5 * 2 + 413) & 127;
    if (stage_v_136 > 37) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001616_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_86 + pub_r001616_6 * 2 + 419) & 127;
    if (stage_v_138 > 59) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_133 + pub_r001616_9 * 2 + 422) & 127;
    if (stage_v_139 > 31) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001616_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_132 + pub_r001616_5 * 2 + 428) & 127;
    if (stage_v_141 > 38) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_117 + pub_r001616_10 * 2 + 431) & 127;
    if (stage_v_142 > 20) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_123 + pub_r001616_12 * 2 + 434) & 127;
    if (stage_v_143 > 33) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001616_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001616_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_99 + pub_r001616_0 * 2 + 443) & 127;
    if (stage_v_146 > 26) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_61 + pub_r001616_3 * 2 + 446) & 127;
    if (stage_v_147 > 44) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001616_0 + pub_r001616_12 * 2 + 449) & 127;
    if (stage_v_148 > 23) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_14 + pub_r001616_2 * 2 + 452) & 127;
    if (stage_v_149 > 29) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_20 + pub_r001616_16 * 2 + 455) & 127;
    if (stage_v_150 > 32) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_56 + pub_r001616_6 * 2 + 458) & 127;
    if (stage_v_151 > 34) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_86 + pub_r001616_17 * 2 + 461) & 127;
    if (stage_v_152 > 16) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001616_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_146 + pub_r001616_5 * 2 + 467) & 127;
    if (stage_v_154 > 58) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001616_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (helper_flow_1 + pub_r001616_7 * 2 + 473) & 127;
    if (stage_v_156 > 29) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_59 + pub_r001616_9 * 2 + 476) & 127;
    if (stage_v_157 > 56) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001616_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001616_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001616_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_3 + pub_r001616_5 * 2 + 488) & 127;
    if (stage_v_161 > 41) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001616_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_126 + pub_r001616_15 * 2 + 494) & 127;
    if (stage_v_163 > 46) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_139 + pub_r001616_5 * 2 + 497) & 127;
    if (stage_v_164 > 52) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_50 + pub_r001616_2 * 2 + 500) & 127;
    if (stage_v_165 > 22) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_33 + pub_r001616_7 * 2 + 503) & 127;
    if (stage_v_166 > 47) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_123 + pub_r001616_14 * 2 + 506) & 127;
    if (stage_v_167 > 27) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_76 + pub_r001616_12 * 2 + 509) & 127;
    if (stage_v_168 > 28) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_135 + pub_r001616_2 * 2 + 512) & 127;
    if (stage_v_169 > 39) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001616_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001616_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_116 + pub_r001616_1 * 2 + 521) & 127;
    if (stage_v_172 > 29) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001616_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001616_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001616_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_64 + pub_r001616_6 * 2 + 533) & 127;
    if (stage_v_176 > 47) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_82 + pub_r001616_13 * 2 + 536) & 127;
    if (stage_v_177 > 54) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_168 + pub_r001616_9 * 2 + 539) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_59 + pub_r001616_1 * 2 + 542) & 127;
    if (stage_v_179 > 52) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_55 + pub_r001616_7 * 2 + 545) & 127;
    if (stage_v_180 > 33) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001616_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001616_12 + pub_r001616_12 * 2 + 551) & 127;
    if (stage_v_182 > 52) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_111 + pub_r001616_11 * 2 + 554) & 127;
    if (stage_v_183 > 15) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001616_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_112 + pub_r001616_9 * 2 + 560) & 127;
    if (stage_v_185 > 18) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_18 + pub_r001616_1 * 2 + 563) & 127;
    if (stage_v_186 > 49) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_69 + pub_r001616_11 * 2 + 566) & 127;
    if (stage_v_187 > 36) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_70 + pub_r001616_2 * 2 + 569) & 127;
    if (stage_v_188 > 51) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_156 + pub_r001616_18 * 2 + 572) & 127;
    if (stage_v_189 > 44) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_165 + pub_r001616_10 * 2 + 575) & 127;
    if (stage_v_190 > 44) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_108 + pub_r001616_18 * 2 + 578) & 127;
    if (stage_v_191 > 55) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_56 + pub_r001616_14 * 2 + 581) & 127;
    if (stage_v_192 > 57) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_164 + pub_r001616_3 * 2 + 584) & 127;
    if (stage_v_193 > 57) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001616_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001616_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_54 + pub_r001616_13 * 2 + 593) & 127;
    if (stage_v_196 > 52) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001616_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001616_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001616_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001616_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_102 + pub_r001616_16 * 2 + 608) & 127;
    if (stage_v_201 > 20) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_43 + pub_r001616_18 * 2 + 611) & 127;
    if (stage_v_202 > 59) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_27 + pub_r001616_0 * 2 + 614) & 127;
    if (stage_v_203 > 42) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_16 + pub_r001616_9 * 2 + 617) & 127;
    if (stage_v_204 > 53) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_68 + pub_r001616_10 * 2 + 620) & 127;
    if (stage_v_205 > 60) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_183 + pub_r001616_15 * 2 + 623) & 127;
    if (stage_v_206 > 30) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_52 + pub_r001616_9 * 2 + 626) & 127;
    if (stage_v_207 > 55) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (helper_flow_6 + pub_r001616_1 * 2 + 629) & 127;
    if (stage_v_208 > 16) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_123 + pub_r001616_12 * 2 + 632) & 127;
    if (stage_v_209 > 38) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_52 + pub_r001616_18 * 2 + 635) & 127;
    if (stage_v_210 > 50) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001616_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001616_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_163 + pub_r001616_2 * 2 + 644) & 127;
    if (stage_v_213 > 16) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001616_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r001616_12 + pub_r001616_11 * 2 + 650) & 127;
    if (stage_v_215 > 32) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001616_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_169 + pub_r001616_11 * 2 + 656) & 127;
    if (stage_v_217 > 48) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_127 + pub_r001616_0 * 2 + 659) & 127;
    if (stage_v_218 > 27) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_117 + pub_r001616_4 * 2 + 662) & 127;
    if (stage_v_219 > 56) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r001616_15 + pub_r001616_17 * 2 + 665) & 127;
    if (stage_v_220 > 30) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001616_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_27 + pub_r001616_8 * 2 + 671) & 127;
    if (stage_v_222 > 25) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_127 + pub_r001616_15 * 2 + 674) & 127;
    if (stage_v_223 > 41) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_67 + pub_r001616_13 * 2 + 677) & 127;
    if (stage_v_224 > 35) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_9 + pub_r001616_18 * 2 + 680) & 127;
    if (stage_v_225 > 42) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_88 + pub_r001616_18 * 2 + 683) & 127;
    if (stage_v_226 > 42) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_143 + pub_r001616_19 * 2 + 686) & 127;
    if (stage_v_227 > 23) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_50 + pub_r001616_9 * 2 + 689) & 127;
    if (stage_v_228 > 21) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_56 + pub_r001616_10 * 2 + 692) & 127;
    if (stage_v_229 > 33) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_9 + pub_r001616_12 * 2 + 695) & 127;
    if (stage_v_230 > 52) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_21 + pub_r001616_2 * 2 + 698) & 127;
    if (stage_v_231 > 58) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_117 + pub_r001616_17 * 2 + 701) & 127;
    if (stage_v_232 > 46) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_123 + pub_r001616_15 * 2 + 704) & 127;
    if (stage_v_233 > 51) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_165 + pub_r001616_11 * 2 + 707) & 127;
    if (stage_v_234 > 56) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_127 + pub_r001616_18 * 2 + 710) & 127;
    if (stage_v_235 > 46) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001616_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001616_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001616_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (sec_r001616_10 + pub_r001616_17 * 2 + 722) & 127;
    if (stage_v_239 > 36) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_99 + pub_r001616_8 * 2 + 725) & 127;
    if (stage_v_240 > 49) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_210 + pub_r001616_7 * 2 + 728) & 127;
    if (stage_v_241 > 49) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001616_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001616_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_152 + pub_r001616_11 * 2 + 737) & 127;
    if (stage_v_244 > 19) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_80 + pub_r001616_7 * 2 + 740) & 127;
    if (stage_v_245 > 19) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_177 + pub_r001616_18 * 2 + 743) & 127;
    if (stage_v_246 > 44) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_59 + pub_r001616_8 * 2 + 746) & 127;
    if (stage_v_247 > 50) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001616_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001616_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_246 + pub_r001616_0 * 2 + 755) & 127;
    if (stage_v_250 > 16) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_168 + pub_r001616_6 * 2 + 758) & 127;
    if (stage_v_251 > 24) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001616_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_104 + pub_r001616_7 * 2 + 764) & 127;
    if (stage_v_253 > 17) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001616_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001616_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_82 + pub_r001616_10 * 2 + 773) & 127;
    if (stage_v_256 > 37) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_222 + pub_r001616_2 * 2 + 776) & 127;
    if (stage_v_257 > 26) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
        sec_accum ^= (stage_v_257 & 31);
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
