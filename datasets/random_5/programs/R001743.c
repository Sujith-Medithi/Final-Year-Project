/*
 * Benchmark Program: R001743
 * Security Family: multi_step_explicit
 * Generator Seed: 674313
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001743_4313_0 {
    int parity;
    short baud_rate;
    int port;
    int buffer[3];
};

struct Vector3D_R001743_4313_1 {
    int pitch;
    short coord_x;
    int norm_sq;
    short coord_z;
    int buffer[3];
};

struct StreamBuffer_R001743_4313_2 {
    unsigned char tail;
    int watermark;
    int head;
    int buffer[3];
};

union RegisterBank_R001743_4313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001743_4313_0(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int margin_98 = 0;
    for (int k = 0; k < 3; k++) {
        margin_98 = (margin_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_98) & 127;
    }
    int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_92) & 63;
    acc ^= aux;
    int threshold_69 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_69 > 33) {
        acc = (acc + threshold_69 * 2 + 5) & 127;
        aux ^= (threshold_69 & 15);
    } else {
        acc = (acc - threshold_69 + 11) & 127;
        aux += 3;
    }
    int phase_13 = (aux + st.buffer[1]) & 3;
    switch (phase_13) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_1(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int phase_20 = local_arr[aux % 3];
    acc = (acc + phase_20 * 2) & 127;
    int tally_27 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_27 > 15) {
        acc = (acc + tally_27 * 2 + 5) & 127;
        aux ^= (tally_27 & 15);
    } else {
        acc = (acc - tally_27 + 11) & 127;
        aux += 3;
    }
    int offset_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001743_4313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_16 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_16 > 27) {
        acc = (acc + quotient_16 * 2 + 5) & 127;
        aux ^= (quotient_16 & 15);
    } else {
        acc = (acc - quotient_16 + 11) & 127;
        aux += 3;
    }
    int quotient_73 = (aux + st.buffer[1]) & 3;
    switch (quotient_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_47 = local_arr[aux % 3];
    acc = (acc + accumulator_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001743_4313_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_98 = (aux + st.buffer[1]) & 3;
    switch (phase_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001743_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_60) & 63;
    acc ^= aux;
    int threshold_85 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_85 = (threshold_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_5(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001743_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int segment_22 = local_arr[aux % 3];
    acc = (acc + segment_22 * 2) & 127;
    int coefficient_41 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_41 > 38) {
        acc = (acc + coefficient_41 * 2 + 5) & 127;
        aux ^= (coefficient_41 & 15);
    } else {
        acc = (acc - coefficient_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_6(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_25) & 63;
    acc ^= aux;
    int bound_67 = (aux + st.buffer[1]) & 3;
    switch (bound_67) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_7(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_49 = local_arr[aux % 3];
    acc = (acc + checksum_49 * 2) & 127;
    int vector_15 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_15 > 21) {
        acc = (acc + vector_15 * 2 + 5) & 127;
        aux ^= (vector_15 & 15);
    } else {
        acc = (acc - vector_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_8(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int damping_84 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_84 > 40) {
        acc = (acc + damping_84 * 2 + 5) & 127;
        aux ^= (damping_84 & 15);
    } else {
        acc = (acc - damping_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_36 = local_arr[aux % 3];
    acc = (acc + vector_36 * 2) & 127;
    int vector_46 = 0;
    for (int k = 0; k < 3; k++) {
        vector_46 = (vector_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_46) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001743_4313_9(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_97 = local_arr[aux % 3];
    acc = (acc + checksum_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001743_4313_10(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_52 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_52 > 35) {
        acc = (acc + tally_52 * 2 + 5) & 127;
        aux ^= (tally_52 & 15);
    } else {
        acc = (acc - tally_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_62 = (aux + st.buffer[1]) & 3;
    switch (vector_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_11(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_77 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_77 > 46) {
        acc = (acc + parity_77 * 2 + 5) & 127;
        aux ^= (parity_77 & 15);
    } else {
        acc = (acc - parity_77 + 11) & 127;
        aux += 3;
    }
    int vector_19 = 0;
    for (int k = 0; k < 3; k++) {
        vector_19 = (vector_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_19) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_75 = local_arr[aux % 3];
    acc = (acc + index_reg_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001743_4313_12(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int window_41 = 0;
    for (int k = 0; k < 3; k++) {
        window_41 = (window_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_41) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001743_4313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int phase_83 = local_arr[aux % 3];
    acc = (acc + phase_83 * 2) & 127;
    int window_64 = (st.buffer[0] * 3 + aux) & 63;
    if (window_64 > 10) {
        acc = (acc + window_64 * 2 + 5) & 127;
        aux ^= (window_64 & 15);
    } else {
        acc = (acc - window_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001743_4313_14(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001743_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_78 = (aux + st.buffer[1]) & 3;
    switch (quotient_78) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_51 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_51 > 40) {
        acc = (acc + stride_51 * 2 + 5) & 127;
        aux ^= (stride_51 & 15);
    } else {
        acc = (acc - stride_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001743_4313_15(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001743_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int tally_63 = local_arr[aux % 3];
    acc = (acc + tally_63 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_12) & 63;
    acc ^= aux;
    int residue_65 = (aux + st.buffer[1]) & 3;
    switch (residue_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001743_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_64 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_64 = (pivot_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001743_4313_17(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001743_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int cursor_64 = local_arr[aux % 3];
    acc = (acc + cursor_64 * 2) & 127;
    int stride_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001743_0;
    int sec_r001743_1;
    int sec_r001743_2;
    int sec_r001743_3;
    int sec_r001743_4;
    int sec_r001743_5;
    int sec_r001743_6;
    int sec_r001743_7;
    int sec_r001743_8;
    int sec_r001743_9;
    int sec_r001743_10;
    int sec_r001743_11;
    int sec_r001743_12;
    int sec_r001743_13;
    int sec_r001743_14;
    int sec_r001743_15;
    int sec_r001743_16;
    int sec_r001743_17;
    int sec_r001743_18;
    int pub_r001743_0;
    int pub_r001743_1;
    int pub_r001743_2;
    int pub_r001743_3;
    int pub_r001743_4;
    int pub_r001743_5;
    int pub_r001743_6;
    int pub_r001743_7;
    int pub_r001743_8;
    int pub_r001743_9;
    int pub_r001743_10;
    int pub_r001743_11;
    int pub_r001743_12;
    int pub_r001743_13;
    int pub_r001743_14;
    int pub_r001743_15;
    int pub_r001743_16;
    int pub_r001743_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001743_0 >= -100 && pub_r001743_0 <= 100);
    __CPROVER_assume(pub_r001743_1 >= -100 && pub_r001743_1 <= 100);
    __CPROVER_assume(pub_r001743_2 >= -100 && pub_r001743_2 <= 100);
    __CPROVER_assume(pub_r001743_3 >= -100 && pub_r001743_3 <= 100);
    __CPROVER_assume(pub_r001743_4 >= -100 && pub_r001743_4 <= 100);
    __CPROVER_assume(pub_r001743_5 >= -100 && pub_r001743_5 <= 100);
    __CPROVER_assume(pub_r001743_6 >= -100 && pub_r001743_6 <= 100);
    __CPROVER_assume(pub_r001743_7 >= -100 && pub_r001743_7 <= 100);
    __CPROVER_assume(pub_r001743_8 >= -100 && pub_r001743_8 <= 100);
    __CPROVER_assume(pub_r001743_9 >= -100 && pub_r001743_9 <= 100);
    __CPROVER_assume(pub_r001743_10 >= -100 && pub_r001743_10 <= 100);
    __CPROVER_assume(pub_r001743_11 >= -100 && pub_r001743_11 <= 100);
    __CPROVER_assume(pub_r001743_12 >= -100 && pub_r001743_12 <= 100);
    __CPROVER_assume(pub_r001743_13 >= -100 && pub_r001743_13 <= 100);
    __CPROVER_assume(pub_r001743_14 >= -100 && pub_r001743_14 <= 100);
    __CPROVER_assume(pub_r001743_15 >= -100 && pub_r001743_15 <= 100);
    __CPROVER_assume(pub_r001743_16 >= -100 && pub_r001743_16 <= 100);
    __CPROVER_assume(pub_r001743_17 >= -100 && pub_r001743_17 <= 100);
    __CPROVER_assume(sec_r001743_0 >= 0 && sec_r001743_0 <= 255);
    __CPROVER_assume(sec_r001743_1 >= 0 && sec_r001743_1 <= 255);
    __CPROVER_assume(sec_r001743_2 >= 0 && sec_r001743_2 <= 255);
    __CPROVER_assume(sec_r001743_3 >= 0 && sec_r001743_3 <= 255);
    __CPROVER_assume(sec_r001743_4 >= 0 && sec_r001743_4 <= 255);
    __CPROVER_assume(sec_r001743_5 >= 0 && sec_r001743_5 <= 255);
    __CPROVER_assume(sec_r001743_6 >= 0 && sec_r001743_6 <= 255);
    __CPROVER_assume(sec_r001743_7 >= 0 && sec_r001743_7 <= 255);
    __CPROVER_assume(sec_r001743_8 >= 0 && sec_r001743_8 <= 255);
    __CPROVER_assume(sec_r001743_9 >= 0 && sec_r001743_9 <= 255);
    __CPROVER_assume(sec_r001743_10 >= 0 && sec_r001743_10 <= 255);
    __CPROVER_assume(sec_r001743_11 >= 0 && sec_r001743_11 <= 255);
    __CPROVER_assume(sec_r001743_12 >= 0 && sec_r001743_12 <= 255);
    __CPROVER_assume(sec_r001743_13 >= 0 && sec_r001743_13 <= 255);
    __CPROVER_assume(sec_r001743_14 >= 0 && sec_r001743_14 <= 255);
    __CPROVER_assume(sec_r001743_15 >= 0 && sec_r001743_15 <= 255);
    __CPROVER_assume(sec_r001743_16 >= 0 && sec_r001743_16 <= 255);
    __CPROVER_assume(sec_r001743_17 >= 0 && sec_r001743_17 <= 255);
    __CPROVER_assume(sec_r001743_18 >= 0 && sec_r001743_18 <= 255);

    struct DeviceConfig_R001743_4313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001743_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001743_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001743_0 + 7) & 15;
    struct Vector3D_R001743_4313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001743_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001743_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001743_0 + 9) & 15;
    struct StreamBuffer_R001743_4313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001743_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001743_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001743_0 + 11) & 15;

    union RegisterBank_R001743_4313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001743_4313_0(sec_r001743_0, pub_r001743_1, pub_r001743_2);
    int helper_flow_1 = fn_R001743_4313_1(sec_r001743_1, pub_r001743_2, pub_r001743_3);
    int helper_flow_2 = fn_R001743_4313_2(sec_r001743_2, sec_r001743_3, pub_r001743_4, pub_r001743_5, pub_r001743_6);
    int helper_flow_3 = fn_R001743_4313_3(sec_r001743_3, sec_r001743_4, pub_r001743_5, pub_r001743_6, pub_r001743_7);
    int helper_flow_4 = fn_R001743_4313_4(sec_r001743_4, sec_r001743_5, pub_r001743_6, pub_r001743_7);
    int helper_flow_5 = fn_R001743_4313_5(sec_r001743_5, pub_r001743_6);
    int helper_flow_6 = fn_R001743_4313_6(sec_r001743_6, sec_r001743_7);
    int helper_flow_7 = fn_R001743_4313_7(sec_r001743_7, sec_r001743_8, pub_r001743_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_2 * 3) + pub_r001743_6 + 33) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001743_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001743_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001743_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001743_6 * 3) + pub_r001743_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_4 * 3) + pub_r001743_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001743_3 * 3) + pub_r001743_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_4 * 3) + pub_r001743_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001743_11 * 3) + pub_r001743_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001743_12 * 3) + pub_r001743_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001743_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001743_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001743_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001743_4 * 3) + pub_r001743_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001743_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001743_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001743_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001743_0 * 3) + pub_r001743_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001743_5 * 3) + pub_r001743_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_0 * 3) + pub_r001743_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_13 * 3) + pub_r001743_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001743_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001743_3 * 3) + pub_r001743_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001743_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001743_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001743_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001743_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001743_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001743_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001743_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001743_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_17 * 3) + pub_r001743_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_2 * 3) + pub_r001743_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001743_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001743_15 * 3) + pub_r001743_16 + 24) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001743_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_18 * 3) + pub_r001743_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001743_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001743_1 * 3) + pub_r001743_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001743_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001743_10 * 3) + pub_r001743_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001743_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001743_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001743_14 * 3) + pub_r001743_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001743_13 * 3) + pub_r001743_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001743_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_7 * 3) + pub_r001743_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001743_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_36 * 3) + pub_r001743_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001743_15 * 3) + pub_r001743_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_31 * 3) + pub_r001743_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001743_1 * 3) + pub_r001743_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001743_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001743_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_34 * 3) + pub_r001743_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((helper_flow_2 * 3) + pub_r001743_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001743_13 * 3) + pub_r001743_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56 * 2) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_48 * 3) + pub_r001743_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_22 * 3) + pub_r001743_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001743_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_36 * 3) + pub_r001743_5 + 42) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001743_4 * 3) + pub_r001743_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001743_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001743_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001743_9 * 3) + pub_r001743_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_4 * 3) + pub_r001743_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_36 * 3) + pub_r001743_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001743_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_32 * 3) + pub_r001743_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001743_12 * 3) + pub_r001743_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001743_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_32 * 3) + pub_r001743_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001743_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001743_9 * 3) + pub_r001743_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001743_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_58 * 3) + pub_r001743_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001743_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001743_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_0 * 3) + pub_r001743_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001743_7 * 3) + pub_r001743_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001743_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001743_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001743_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001743_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001743_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001743_17 * 3) + pub_r001743_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_40 * 3) + pub_r001743_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_64 * 3) + pub_r001743_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_85 * 3) + pub_r001743_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001743_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_22 * 3) + pub_r001743_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_46 * 3) + pub_r001743_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((helper_flow_0 * 3) + pub_r001743_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001743_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001743_17 * 3) + pub_r001743_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001743_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001743_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_90 * 3) + pub_r001743_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_87 * 3) + pub_r001743_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001743_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_4 * 3) + pub_r001743_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001743_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001743_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001743_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001743_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001743_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_32 * 3) + pub_r001743_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001743_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_78 * 3) + pub_r001743_16 + 7) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001743_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_32 * 3) + pub_r001743_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001743_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((helper_flow_6 * 3) + pub_r001743_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r001743_16 * 3) + pub_r001743_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_5 * 3) + pub_r001743_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001743_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001743_5 * 3) + pub_r001743_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_108 * 3) + pub_r001743_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_91 * 3) + pub_r001743_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_92 * 3) + pub_r001743_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001743_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001743_7 * 3) + pub_r001743_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_97 * 3) + pub_r001743_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001743_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001743_12 * 3) + pub_r001743_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_2 * 3) + pub_r001743_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001743_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001743_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001743_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001743_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_49 * 3) + pub_r001743_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_50 * 3) + pub_r001743_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_20 * 3) + pub_r001743_3 + 21) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_86 * 3) + pub_r001743_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001743_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001743_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001743_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_131 * 3) + pub_r001743_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_112 * 3) + pub_r001743_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_88 * 3) + pub_r001743_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001743_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001743_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_97 * 3) + pub_r001743_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001743_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001743_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_5 * 3) + pub_r001743_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_17 * 3) + pub_r001743_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_9 * 3) + pub_r001743_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001743_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001743_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_121 * 3) + pub_r001743_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_86 * 3) + pub_r001743_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001743_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001743_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_73 * 3) + pub_r001743_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001743_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001743_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_146 * 3) + pub_r001743_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_150 * 3) + pub_r001743_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_18 * 3) + pub_r001743_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_61 * 3) + pub_r001743_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_55 * 3) + pub_r001743_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_58 * 3) + pub_r001743_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_60 * 3) + pub_r001743_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_133 * 3) + pub_r001743_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_132 * 3) + pub_r001743_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_117 * 3) + pub_r001743_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001743_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001743_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001743_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001743_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_121 * 3) + pub_r001743_17 + 33) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_160 * 3) + pub_r001743_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_38 * 3) + pub_r001743_5 + 12) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001743_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001743_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_86 * 3) + pub_r001743_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_38 * 3) + pub_r001743_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_5 * 3) + pub_r001743_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001743_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_86 * 3) + pub_r001743_11 + 41) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_112 * 3) + pub_r001743_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181 * 2) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_158 * 3) + pub_r001743_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001743_2 * 3) + pub_r001743_12 + 18) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((helper_flow_3 * 3) + pub_r001743_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001743_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001743_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001743_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001743_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_158 * 3) + pub_r001743_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_86 * 3) + pub_r001743_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001743_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001743_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001743_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r001743_12 * 3) + pub_r001743_7 + 27) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001743_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001743_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001743_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001743_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_113 * 3) + pub_r001743_4 + 39) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199 * 2) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001743_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001743_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001743_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001743_15 * 3) + pub_r001743_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_22 * 3) + pub_r001743_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001743_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001743_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001743_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001743_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001743_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_181 * 3) + pub_r001743_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_106 * 3) + pub_r001743_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_31 * 3) + pub_r001743_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001743_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001743_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_118 * 3) + pub_r001743_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_17 * 3) + pub_r001743_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001743_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001743_6 * 3) + pub_r001743_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001743_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001743_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001743_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_130 * 3) + pub_r001743_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_48 * 3) + pub_r001743_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001743_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r001743_13 * 3) + pub_r001743_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225 * 2) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001743_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_60 * 3) + pub_r001743_0 + 27) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001743_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001743_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_20 * 3) + pub_r001743_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_19 * 3) + pub_r001743_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001743_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_189 * 3) + pub_r001743_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_119 * 3) + pub_r001743_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_17 * 3) + pub_r001743_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001743_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001743_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_92 * 3) + pub_r001743_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238 * 2) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_203 * 3) + pub_r001743_16 + 38) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001743_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001743_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001743_13 * 3) + pub_r001743_17 + 28) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001743_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_13 * 3) + pub_r001743_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001743_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_91 * 3) + pub_r001743_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001743_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_94 * 3) + pub_r001743_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248 * 2) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001743_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001743_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_22 * 3) + pub_r001743_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001743_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_164 * 3) + pub_r001743_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r001743_17 * 3) + pub_r001743_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_38 * 3) + pub_r001743_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_113 * 3) + pub_r001743_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001743_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_88 * 3) + pub_r001743_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258 * 2) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_194 * 3) + pub_r001743_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_124 * 3) + pub_r001743_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_51 * 3) + pub_r001743_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r001743_6 * 3) + pub_r001743_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001743_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((helper_flow_6 * 3) + pub_r001743_15 + 44) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((helper_flow_2 * 3) + pub_r001743_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_92 * 3) + pub_r001743_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((helper_flow_5 * 3) + pub_r001743_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_116 * 3) + pub_r001743_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001743_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001743_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001743_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001743_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001743_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001743_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001743_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001743_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001743_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_54 * 3) + pub_r001743_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001743_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_98 * 3) + pub_r001743_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001743_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_90 * 3) + pub_r001743_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001743_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((sec_r001743_8 * 3) + pub_r001743_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001743_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_160 * 3) + pub_r001743_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_254 * 3) + pub_r001743_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_138 * 3) + pub_r001743_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001743_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_246 * 3) + pub_r001743_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001743_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((helper_flow_4 * 3) + pub_r001743_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_171 * 3) + pub_r001743_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001743_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_161 * 3) + pub_r001743_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r001743_4 * 3) + pub_r001743_4 + 41) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_50 * 3) + pub_r001743_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297 * 2) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001743_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_292 * 3) + pub_r001743_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299 * 2) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_260 * 3) + pub_r001743_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((helper_flow_1 * 3) + pub_r001743_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_94 * 3) + pub_r001743_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_133 * 3) + pub_r001743_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001743_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_256 * 3) + pub_r001743_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001743_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001743_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001743_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_18 * 3) + pub_r001743_12 + 20) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001743_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001743_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001743_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_85 * 3) + pub_r001743_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001743_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_87 * 3) + pub_r001743_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001743_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001743_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001743_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001743_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001743_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_222 * 3) + pub_r001743_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001743_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_36 * 3) + pub_r001743_14 + 31) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((helper_flow_4 * 3) + pub_r001743_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_100 * 3) + pub_r001743_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_246 * 3) + pub_r001743_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_225 * 3) + pub_r001743_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_159 * 3) + pub_r001743_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_280 * 3) + pub_r001743_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_69 * 3) + pub_r001743_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001743_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001743_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_297 * 3) + pub_r001743_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001743_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001743_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_65 * 3) + pub_r001743_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_173 * 3) + pub_r001743_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001743_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001743_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001743_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001743_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_325 * 3) + pub_r001743_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_55 * 3) + pub_r001743_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001743_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001743_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_300 * 3) + pub_r001743_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_122 * 3) + pub_r001743_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((sec_r001743_16 * 3) + pub_r001743_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_347 * 3) + pub_r001743_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_325 * 3) + pub_r001743_14 + 43) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_255 * 3) + pub_r001743_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_349 * 3) + pub_r001743_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_64 * 3) + pub_r001743_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_85 * 3) + pub_r001743_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_4 * 3) + pub_r001743_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_343 * 3) + pub_r001743_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001743_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001743_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_295 * 3) + pub_r001743_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_353 * 3) + pub_r001743_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_329 * 3) + pub_r001743_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((sec_r001743_12 * 3) + pub_r001743_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362 * 2) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001743_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_350 * 3) + pub_r001743_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001743_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001743_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_172 * 3) + pub_r001743_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001743_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001743_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_36 * 3) + pub_r001743_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_328 * 3) + pub_r001743_9 + 45) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001743_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_355 * 3) + pub_r001743_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001743_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001743_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_121 * 3) + pub_r001743_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001743_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_199 * 3) + pub_r001743_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((sec_r001743_0 * 3) + pub_r001743_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_55 * 3) + pub_r001743_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_178 * 3) + pub_r001743_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001743_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001743_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001743_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001743_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_88 * 3) + pub_r001743_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001743_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_381 * 3) + pub_r001743_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_315 * 3) + pub_r001743_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((helper_flow_4 * 3) + pub_r001743_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001743_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001743_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001743_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_297 * 3) + pub_r001743_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001743_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_18 * 3) + pub_r001743_2 + 45) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_350 * 3) + pub_r001743_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_58 * 3) + pub_r001743_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_88 * 3) + pub_r001743_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_399) & 255;
    out_sink = (out_sink + stage_v_399 * 2) & 255;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_61 * 3) + pub_r001743_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_54 * 3) + pub_r001743_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001743_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_189 * 3) + pub_r001743_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001743_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((helper_flow_0 * 3) + pub_r001743_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001743_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001743_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001743_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001743_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_302 * 3) + pub_r001743_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_58 * 3) + pub_r001743_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001743_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((sec_r001743_12 * 3) + pub_r001743_11 + 41) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_60 * 3) + pub_r001743_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001743_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001743_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_86 * 3) + pub_r001743_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001743_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_364 * 3) + pub_r001743_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001743_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001743_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_145 * 3) + pub_r001743_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_54 * 3) + pub_r001743_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_286 * 3) + pub_r001743_17 + 44) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001743_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_233 * 3) + pub_r001743_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_330 * 3) + pub_r001743_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((helper_flow_7 * 3) + pub_r001743_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_428) & 255;
    out_sink = (out_sink + stage_v_428 * 2) & 255;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001743_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_262 * 3) + pub_r001743_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001743_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_397 * 3) + pub_r001743_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_51 * 3) + pub_r001743_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001743_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001743_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_94 * 3) + pub_r001743_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_371 * 3) + pub_r001743_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_437) & 255;
    out_sink = (out_sink + stage_v_437 * 2) & 255;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001743_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001743_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_184 * 3) + pub_r001743_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_379 * 3) + pub_r001743_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001743_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001743_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_151 * 3) + pub_r001743_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001743_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_212 * 3) + pub_r001743_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001743_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_422 * 3) + pub_r001743_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_297 * 3) + pub_r001743_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_388 * 3) + pub_r001743_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_290 * 3) + pub_r001743_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001743_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001743_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_61 * 3) + pub_r001743_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_454) & 255;
    out_sink = (out_sink + stage_v_454 * 2) & 255;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_91 * 3) + pub_r001743_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_92 * 3) + pub_r001743_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_313 * 3) + pub_r001743_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_342 * 3) + pub_r001743_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_458) & 255;
    out_sink = (out_sink + stage_v_458 * 2) & 255;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001743_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((sec_r001743_13 * 3) + pub_r001743_7 + 38) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_309 * 3) + pub_r001743_3 + 39) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001743_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_90 * 3) + pub_r001743_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_444 * 3) + pub_r001743_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001743_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_238 * 3) + pub_r001743_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_466) & 255;
    out_sink = (out_sink + stage_v_466 * 2) & 255;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_138 * 3) + pub_r001743_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001743_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001743_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((stage_v_124 * 3) + pub_r001743_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_470) & 255;
    out_sink = (out_sink + stage_v_470 * 2) & 255;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_137 * 3) + pub_r001743_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((sec_r001743_13 * 3) + pub_r001743_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_230 * 3) + pub_r001743_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001743_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_329 * 3) + pub_r001743_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = ((stage_v_400 * 3) + pub_r001743_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_476) & 255;
    out_sink = (out_sink + stage_v_476 * 2) & 255;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_295 * 3) + pub_r001743_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_477) & 255;
    out_sink = (out_sink + stage_v_477 * 2) & 255;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001743_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_216 * 3) + pub_r001743_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_479) & 255;
    out_sink = (out_sink + stage_v_479 * 2) & 255;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001743_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = ((stage_v_300 * 3) + pub_r001743_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_481) & 255;
    out_sink = (out_sink + stage_v_481 * 2) & 255;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_194 * 3) + pub_r001743_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_482) & 255;
    out_sink = (out_sink + stage_v_482 * 2) & 255;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_204 * 3) + pub_r001743_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_483) & 255;
    out_sink = (out_sink + stage_v_483 * 2) & 255;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001743_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001743_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = ((stage_v_464 * 3) + pub_r001743_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_486) & 255;
    out_sink = (out_sink + stage_v_486 * 2) & 255;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_85 * 3) + pub_r001743_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_487) & 255;
    out_sink = (out_sink + stage_v_487 * 2) & 255;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_475 * 3) + pub_r001743_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_488) & 255;
    out_sink = (out_sink + stage_v_488 * 2) & 255;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001743_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001743_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001743_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = ((stage_v_256 * 3) + pub_r001743_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_492) & 255;
    out_sink = (out_sink + stage_v_492 * 2) & 255;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_367 * 3) + pub_r001743_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_493) & 255;
    out_sink = (out_sink + stage_v_493 * 2) & 255;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001743_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001743_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001743_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_367 * 3) + pub_r001743_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_497) & 255;
    out_sink = (out_sink + stage_v_497 * 2) & 255;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((stage_v_22 * 3) + pub_r001743_0 + 39) & 127;
    sec_accum = (sec_accum + stage_v_498) & 255;
    out_sink = (out_sink + stage_v_498 * 2) & 255;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001743_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001743_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((sec_r001743_11 * 3) + pub_r001743_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_501) & 255;
    out_sink = (out_sink + stage_v_501 * 2) & 255;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = ((stage_v_440 * 3) + pub_r001743_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_502) & 255;
    out_sink = (out_sink + stage_v_502 * 2) & 255;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = ((sec_r001743_15 * 3) + pub_r001743_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_503) & 255;
    out_sink = (out_sink + stage_v_503 * 2) & 255;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_117 * 3) + pub_r001743_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_504) & 255;
    out_sink = (out_sink + stage_v_504 * 2) & 255;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = ((stage_v_118 * 3) + pub_r001743_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_505) & 255;
    out_sink = (out_sink + stage_v_505 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
