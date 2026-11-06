/*
 * Benchmark Program: R000427
 * Security Family: nested_implicit_flow
 * Generator Seed: 542713
 * High Inputs: 24 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000427_2713_0 {
    unsigned char norm_sq;
    int coord_z;
    short pitch;
    int heading;
    int buffer[3];
};

struct MatrixBlock_R000427_2713_1 {
    unsigned char stride;
    unsigned char dim;
    unsigned char scale;
    int trace;
    short density;
    int buffer[3];
};

struct Transaction_R000427_2713_2 {
    short fee;
    short rate;
    int status;
    int auth_code;
    int buffer[3];
};

struct StreamBuffer_R000427_2713_3 {
    int capacity;
    int checksum;
    int tail;
    int buffer[3];
};

union RegisterBank_R000427_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000427_2713_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_90 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_90 > 50) {
        acc = (acc + phase_90 * 2 + 5) & 127;
        aux ^= (phase_90 & 15);
    } else {
        acc = (acc - phase_90 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_69 = local_arr[aux % 3];
    acc = (acc + accumulator_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tracker_49 = (aux + st.buffer[1]) & 3;
    switch (tracker_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_23) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_99 = local_arr[aux % 3];
    acc = (acc + threshold_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_2(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_34 = (aux + st.buffer[1]) & 3;
    switch (phase_34) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_37 = local_arr[aux % 3];
    acc = (acc + window_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int window_60 = local_arr[aux % 3];
    acc = (acc + window_60 * 2) & 127;
    int weight_31 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_31 > 23) {
        acc = (acc + weight_31 * 2 + 5) & 127;
        aux ^= (weight_31 & 15);
    } else {
        acc = (acc - weight_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_38 = (aux + st.buffer[1]) & 3;
    switch (checksum_38) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_81 = (st.buffer[0] * 3 + aux) & 63;
    if (window_81 > 44) {
        acc = (acc + window_81 * 2 + 5) & 127;
        aux ^= (window_81 & 15);
    } else {
        acc = (acc - window_81 + 11) & 127;
        aux += 3;
    }
    int phase_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_5(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_60 = (aux + st.buffer[1]) & 3;
    switch (residue_60) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_90) & 63;
    acc ^= aux;
    int vector_96 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_96 > 32) {
        acc = (acc + vector_96 * 2 + 5) & 127;
        aux ^= (vector_96 & 15);
    } else {
        acc = (acc - vector_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_99 = (aux + st.buffer[1]) & 3;
    switch (anchor_99) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_95 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_95 > 50) {
        acc = (acc + sample_95 * 2 + 5) & 127;
        aux ^= (sample_95 & 15);
    } else {
        acc = (acc - sample_95 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_19) & 63;
    acc ^= aux;
    int tracker_49 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_49 > 14) {
        acc = (acc + tracker_49 * 2 + 5) & 127;
        aux ^= (tracker_49 & 15);
    } else {
        acc = (acc - tracker_49 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_78 = local_arr[aux % 3];
    acc = (acc + delta_78 * 2) & 127;
    int threshold_17 = (aux + st.buffer[1]) & 3;
    switch (threshold_17) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int cursor_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_44) & 63;
    acc ^= aux;
    int segment_51 = (aux + st.buffer[1]) & 3;
    switch (segment_51) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_60 = (aux + st.buffer[1]) & 3;
    switch (threshold_60) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_11(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 14) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_81 = local_arr[aux % 3];
    acc = (acc + checksum_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_12(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int vector_88 = local_arr[aux % 3];
    acc = (acc + vector_88 * 2) & 127;
    int damping_20 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_20 > 27) {
        acc = (acc + damping_20 * 2 + 5) & 127;
        aux ^= (damping_20 & 15);
    } else {
        acc = (acc - damping_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int sample_75 = local_arr[aux % 3];
    acc = (acc + sample_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_42 = (aux + st.buffer[1]) & 3;
    switch (anchor_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_14(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_53 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_53 > 25) {
        acc = (acc + weight_53 * 2 + 5) & 127;
        aux ^= (weight_53 & 15);
    } else {
        acc = (acc - weight_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_59 = (aux + st.buffer[1]) & 3;
    switch (weight_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_83 = local_arr[aux % 3];
    acc = (acc + parity_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int phase_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_59 = local_arr[aux % 3];
    acc = (acc + checksum_59 * 2) & 127;
    int threshold_71 = (aux + st.buffer[1]) & 3;
    switch (threshold_71) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_86 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_86 > 14) {
        acc = (acc + tracker_86 * 2 + 5) & 127;
        aux ^= (tracker_86 & 15);
    } else {
        acc = (acc - tracker_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_16(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000427_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_16 = local_arr[aux % 3];
    acc = (acc + delta_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_17(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_97 = local_arr[aux % 3];
    acc = (acc + vector_97 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000427_0;
    int sec_r000427_1;
    int sec_r000427_2;
    int sec_r000427_3;
    int sec_r000427_4;
    int sec_r000427_5;
    int sec_r000427_6;
    int sec_r000427_7;
    int sec_r000427_8;
    int sec_r000427_9;
    int sec_r000427_10;
    int sec_r000427_11;
    int sec_r000427_12;
    int sec_r000427_13;
    int sec_r000427_14;
    int sec_r000427_15;
    int sec_r000427_16;
    int sec_r000427_17;
    int sec_r000427_18;
    int sec_r000427_19;
    int sec_r000427_20;
    int sec_r000427_21;
    int sec_r000427_22;
    int sec_r000427_23;
    int pub_r000427_0;
    int pub_r000427_1;
    int pub_r000427_2;
    int pub_r000427_3;
    int pub_r000427_4;
    int pub_r000427_5;
    int pub_r000427_6;
    int pub_r000427_7;
    int pub_r000427_8;
    int pub_r000427_9;
    int pub_r000427_10;
    int pub_r000427_11;
    int pub_r000427_12;
    int pub_r000427_13;
    int pub_r000427_14;
    int pub_r000427_15;
    int pub_r000427_16;
    int pub_r000427_17;
    int pub_r000427_18;
    int pub_r000427_19;
    int pub_r000427_20;
    int pub_r000427_21;
    int pub_r000427_22;
    int pub_r000427_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000427_0 >= -100 && pub_r000427_0 <= 100);
    __CPROVER_assume(pub_r000427_1 >= -100 && pub_r000427_1 <= 100);
    __CPROVER_assume(pub_r000427_2 >= -100 && pub_r000427_2 <= 100);
    __CPROVER_assume(pub_r000427_3 >= -100 && pub_r000427_3 <= 100);
    __CPROVER_assume(pub_r000427_4 >= -100 && pub_r000427_4 <= 100);
    __CPROVER_assume(pub_r000427_5 >= -100 && pub_r000427_5 <= 100);
    __CPROVER_assume(pub_r000427_6 >= -100 && pub_r000427_6 <= 100);
    __CPROVER_assume(pub_r000427_7 >= -100 && pub_r000427_7 <= 100);
    __CPROVER_assume(pub_r000427_8 >= -100 && pub_r000427_8 <= 100);
    __CPROVER_assume(pub_r000427_9 >= -100 && pub_r000427_9 <= 100);
    __CPROVER_assume(pub_r000427_10 >= -100 && pub_r000427_10 <= 100);
    __CPROVER_assume(pub_r000427_11 >= -100 && pub_r000427_11 <= 100);
    __CPROVER_assume(pub_r000427_12 >= -100 && pub_r000427_12 <= 100);
    __CPROVER_assume(pub_r000427_13 >= -100 && pub_r000427_13 <= 100);
    __CPROVER_assume(pub_r000427_14 >= -100 && pub_r000427_14 <= 100);
    __CPROVER_assume(pub_r000427_15 >= -100 && pub_r000427_15 <= 100);
    __CPROVER_assume(pub_r000427_16 >= -100 && pub_r000427_16 <= 100);
    __CPROVER_assume(pub_r000427_17 >= -100 && pub_r000427_17 <= 100);
    __CPROVER_assume(pub_r000427_18 >= -100 && pub_r000427_18 <= 100);
    __CPROVER_assume(pub_r000427_19 >= -100 && pub_r000427_19 <= 100);
    __CPROVER_assume(pub_r000427_20 >= -100 && pub_r000427_20 <= 100);
    __CPROVER_assume(pub_r000427_21 >= -100 && pub_r000427_21 <= 100);
    __CPROVER_assume(pub_r000427_22 >= -100 && pub_r000427_22 <= 100);
    __CPROVER_assume(pub_r000427_23 >= -100 && pub_r000427_23 <= 100);
    __CPROVER_assume(sec_r000427_0 >= 0 && sec_r000427_0 <= 255);
    __CPROVER_assume(sec_r000427_1 >= 0 && sec_r000427_1 <= 255);
    __CPROVER_assume(sec_r000427_2 >= 0 && sec_r000427_2 <= 255);
    __CPROVER_assume(sec_r000427_3 >= 0 && sec_r000427_3 <= 255);
    __CPROVER_assume(sec_r000427_4 >= 0 && sec_r000427_4 <= 255);
    __CPROVER_assume(sec_r000427_5 >= 0 && sec_r000427_5 <= 255);
    __CPROVER_assume(sec_r000427_6 >= 0 && sec_r000427_6 <= 255);
    __CPROVER_assume(sec_r000427_7 >= 0 && sec_r000427_7 <= 255);
    __CPROVER_assume(sec_r000427_8 >= 0 && sec_r000427_8 <= 255);
    __CPROVER_assume(sec_r000427_9 >= 0 && sec_r000427_9 <= 255);
    __CPROVER_assume(sec_r000427_10 >= 0 && sec_r000427_10 <= 255);
    __CPROVER_assume(sec_r000427_11 >= 0 && sec_r000427_11 <= 255);
    __CPROVER_assume(sec_r000427_12 >= 0 && sec_r000427_12 <= 255);
    __CPROVER_assume(sec_r000427_13 >= 0 && sec_r000427_13 <= 255);
    __CPROVER_assume(sec_r000427_14 >= 0 && sec_r000427_14 <= 255);
    __CPROVER_assume(sec_r000427_15 >= 0 && sec_r000427_15 <= 255);
    __CPROVER_assume(sec_r000427_16 >= 0 && sec_r000427_16 <= 255);
    __CPROVER_assume(sec_r000427_17 >= 0 && sec_r000427_17 <= 255);
    __CPROVER_assume(sec_r000427_18 >= 0 && sec_r000427_18 <= 255);
    __CPROVER_assume(sec_r000427_19 >= 0 && sec_r000427_19 <= 255);
    __CPROVER_assume(sec_r000427_20 >= 0 && sec_r000427_20 <= 255);
    __CPROVER_assume(sec_r000427_21 >= 0 && sec_r000427_21 <= 255);
    __CPROVER_assume(sec_r000427_22 >= 0 && sec_r000427_22 <= 255);
    __CPROVER_assume(sec_r000427_23 >= 0 && sec_r000427_23 <= 255);

    struct Vector3D_R000427_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000427_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000427_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000427_0 + 7) & 15;
    struct MatrixBlock_R000427_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000427_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000427_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000427_0 + 9) & 15;
    struct Transaction_R000427_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000427_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000427_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000427_0 + 11) & 15;
    struct StreamBuffer_R000427_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000427_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000427_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000427_0 + 13) & 15;

    union RegisterBank_R000427_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 36) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 51) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 36) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 51) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 39) {
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
    if (stage_v_5 > 19) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 34) {
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
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 28) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 43) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 24) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 39) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 12) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 27) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 24) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 39) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 40) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 55) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 10) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 25) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 39) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 54) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000427_10 & 1) != 0) {
        if ((sec_r000427_1 & 2) != 0) {
            stage_v_72 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_73 = (pub_r000427_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000427_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000427_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_74 = (pub_r000427_22 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000427_22 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000427_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_75 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000427_18 & 1) != 0) {
        if ((sec_r000427_17 & 2) != 0) {
            stage_v_76 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000427_2 & 2) != 0) {
            stage_v_77 = (pub_r000427_1 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000427_1 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000427_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000427_7 & 2) != 0) {
            stage_v_78 = (pub_r000427_19 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000427_19 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000427_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_79 = (pub_r000427_19 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000427_19 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000427_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000427_6 & 2) != 0) {
            stage_v_80 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000427_20 & 2) != 0) {
            stage_v_81 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000427_9 & 1) != 0) {
        if ((sec_r000427_18 & 2) != 0) {
            stage_v_82 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000427_5 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_83 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000427_11 & 2) != 0) {
            stage_v_84 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000427_13 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_85 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_86 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_87 = (pub_r000427_16 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000427_16 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000427_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_88 = (pub_r000427_22 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000427_22 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000427_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000427_7 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_89 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_90 = (pub_r000427_11 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000427_11 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000427_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_91 = (pub_r000427_11 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000427_11 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000427_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000427_1 & 2) != 0) {
            stage_v_92 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_93 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000427_15 & 2) != 0) {
            stage_v_94 = (pub_r000427_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000427_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000427_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_95 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000427_1 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_96 = (pub_r000427_19 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000427_19 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000427_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000427_17 & 2) != 0) {
            stage_v_97 = (pub_r000427_18 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000427_18 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000427_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000427_4 & 2) != 0) {
            stage_v_98 = (pub_r000427_10 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000427_10 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000427_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_99 = (pub_r000427_7 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000427_7 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000427_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000427_20 & 2) != 0) {
            stage_v_100 = (pub_r000427_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000427_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000427_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000427_0 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_101 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000427_13 & 2) != 0) {
            stage_v_102 = (pub_r000427_17 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000427_17 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000427_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000427_13 & 2) != 0) {
            stage_v_103 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000427_19 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_104 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000427_1 & 2) != 0) {
            stage_v_105 = (pub_r000427_10 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000427_10 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000427_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000427_15 & 1) != 0) {
        if ((sec_r000427_17 & 2) != 0) {
            stage_v_106 = (pub_r000427_3 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000427_3 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000427_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000427_11 & 1) != 0) {
        if ((sec_r000427_4 & 2) != 0) {
            stage_v_107 = (pub_r000427_13 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000427_13 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000427_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_108 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000427_6 & 1) != 0) {
        if ((sec_r000427_0 & 2) != 0) {
            stage_v_109 = (pub_r000427_17 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000427_17 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000427_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000427_0 & 1) != 0) {
        if ((sec_r000427_8 & 2) != 0) {
            stage_v_110 = (pub_r000427_15 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000427_15 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000427_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000427_14 & 1) != 0) {
        if ((sec_r000427_8 & 2) != 0) {
            stage_v_111 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000427_17 & 2) != 0) {
            stage_v_112 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_113 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000427_4 & 2) != 0) {
            stage_v_114 = (pub_r000427_13 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000427_13 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000427_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000427_23 & 2) != 0) {
            stage_v_115 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_116 = (pub_r000427_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000427_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000427_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000427_6 & 2) != 0) {
            stage_v_117 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000427_0 & 2) != 0) {
            stage_v_118 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000427_17 & 2) != 0) {
            stage_v_119 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000427_2 & 2) != 0) {
            stage_v_120 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_121 = (pub_r000427_19 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000427_19 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000427_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000427_21 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_122 = (pub_r000427_5 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000427_5 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000427_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_123 = (pub_r000427_9 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000427_9 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000427_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_124 = (pub_r000427_17 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000427_17 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000427_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_125 = (pub_r000427_1 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000427_1 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000427_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000427_10 & 1) != 0) {
        if ((sec_r000427_11 & 2) != 0) {
            stage_v_126 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000427_5 & 2) != 0) {
            stage_v_127 = (pub_r000427_8 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000427_8 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000427_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_128 = (pub_r000427_5 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000427_5 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000427_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_129 = (pub_r000427_23 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000427_23 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000427_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000427_4 & 2) != 0) {
            stage_v_130 = (pub_r000427_16 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000427_16 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000427_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000427_18 & 2) != 0) {
            stage_v_131 = (pub_r000427_17 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000427_17 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000427_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000427_2 & 2) != 0) {
            stage_v_132 = (pub_r000427_15 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000427_15 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000427_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_133 = (pub_r000427_0 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000427_0 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000427_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_134 = (pub_r000427_5 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000427_5 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000427_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000427_14 & 2) != 0) {
            stage_v_135 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000427_14 & 2) != 0) {
            stage_v_136 = (pub_r000427_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000427_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000427_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000427_2 & 2) != 0) {
            stage_v_137 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000427_8 & 1) != 0) {
        if ((sec_r000427_5 & 2) != 0) {
            stage_v_138 = (pub_r000427_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000427_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000427_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_139 = (pub_r000427_7 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000427_7 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000427_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000427_21 & 2) != 0) {
            stage_v_140 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000427_3 & 1) != 0) {
        if ((sec_r000427_20 & 2) != 0) {
            stage_v_141 = (pub_r000427_7 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000427_7 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000427_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000427_0 & 2) != 0) {
            stage_v_142 = (pub_r000427_7 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000427_7 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000427_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000427_15 & 1) != 0) {
        if ((sec_r000427_10 & 2) != 0) {
            stage_v_143 = (pub_r000427_2 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000427_2 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000427_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000427_20 & 2) != 0) {
            stage_v_144 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_145 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000427_23 & 2) != 0) {
            stage_v_146 = (pub_r000427_18 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000427_18 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000427_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000427_0 & 2) != 0) {
            stage_v_147 = (pub_r000427_23 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000427_23 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000427_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000427_11 & 2) != 0) {
            stage_v_148 = (pub_r000427_22 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000427_22 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000427_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000427_14 & 1) != 0) {
        if ((sec_r000427_16 & 2) != 0) {
            stage_v_149 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000427_2 & 1) != 0) {
        if ((sec_r000427_9 & 2) != 0) {
            stage_v_150 = (pub_r000427_11 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000427_11 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000427_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000427_3 & 2) != 0) {
            stage_v_151 = (pub_r000427_21 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000427_21 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000427_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000427_9 & 1) != 0) {
        if ((sec_r000427_2 & 2) != 0) {
            stage_v_152 = (pub_r000427_0 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000427_0 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000427_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000427_0 & 2) != 0) {
            stage_v_153 = (pub_r000427_9 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000427_9 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000427_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_154 = (pub_r000427_0 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000427_0 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000427_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000427_22 & 2) != 0) {
            stage_v_155 = (pub_r000427_22 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000427_22 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000427_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000427_5 & 1) != 0) {
        if ((sec_r000427_19 & 2) != 0) {
            stage_v_156 = (pub_r000427_0 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000427_0 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000427_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000427_12 & 2) != 0) {
            stage_v_157 = (pub_r000427_20 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000427_20 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000427_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000427_18 & 2) != 0) {
            stage_v_158 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000427_4 & 2) != 0) {
            stage_v_159 = (pub_r000427_6 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000427_6 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000427_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000427_5 & 2) != 0) {
            stage_v_160 = (pub_r000427_0 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000427_0 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000427_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r000427_18 & 2) != 0) {
            stage_v_161 = (pub_r000427_14 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000427_14 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000427_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
