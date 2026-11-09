/*
 * Benchmark Program: R001145
 * Security Family: bitwise_flow
 * Generator Seed: 614513
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001145_4513_0 {
    short norm_sq;
    int heading;
    short coord_x;
    int coord_z;
    short pitch;
    short coord_y;
    int buffer[3];
};

struct EventLog_R001145_4513_1 {
    unsigned char code;
    int facility;
    short signature;
    short severity;
    int buffer[3];
};

struct StreamBuffer_R001145_4513_2 {
    short checksum;
    int head;
    short capacity;
    unsigned char watermark;
    short state;
    int buffer[3];
};

union RegisterBank_R001145_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001145_4513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001145_4513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001145_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int vector_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_65) & 63;
    acc ^= aux;
    int anchor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_31 > 31) {
        acc = (acc + anchor_31 * 2 + 5) & 127;
        aux ^= (anchor_31 & 15);
    } else {
        acc = (acc - anchor_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_35) & 63;
    acc ^= aux;
    int threshold_70 = (aux + st.buffer[1]) & 3;
    switch (threshold_70) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_24 = 0;
    for (int k = 0; k < 3; k++) {
        phase_24 = (phase_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_24) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_2(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_79 = (aux + st.buffer[1]) & 3;
    switch (coefficient_79) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_29 = local_arr[aux % 3];
    acc = (acc + accumulator_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001145_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int checksum_33 = local_arr[aux % 3];
    acc = (acc + checksum_33 * 2) & 127;
    int window_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001145_4513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_83 = 0;
    for (int k = 0; k < 3; k++) {
        phase_83 = (phase_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001145_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_49 = (aux + st.buffer[1]) & 3;
    switch (threshold_49) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_30) & 63;
    acc ^= aux;
    int factor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_24 > 41) {
        acc = (acc + factor_24 * 2 + 5) & 127;
        aux ^= (factor_24 & 15);
    } else {
        acc = (acc - factor_24 + 11) & 127;
        aux += 3;
    }
    int checksum_10 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_10 = (checksum_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001145_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int offset_29 = 0;
    for (int k = 0; k < 3; k++) {
        offset_29 = (offset_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_29) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001145_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_48) & 63;
    acc ^= aux;
    int vector_46 = (aux + st.buffer[1]) & 3;
    switch (vector_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_86 = local_arr[aux % 3];
    acc = (acc + bound_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_8(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001145_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int quantum_34 = local_arr[aux % 3];
    acc = (acc + quantum_34 * 2) & 127;
    int accumulator_32 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_32 > 36) {
        acc = (acc + accumulator_32 * 2 + 5) & 127;
        aux ^= (accumulator_32 & 15);
    } else {
        acc = (acc - accumulator_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001145_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_15 = (aux + st.buffer[1]) & 3;
    switch (coefficient_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_10(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001145_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_86 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_86 > 37) {
        acc = (acc + phase_86 * 2 + 5) & 127;
        aux ^= (phase_86 & 15);
    } else {
        acc = (acc - phase_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_11(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int scale_86 = local_arr[aux % 3];
    acc = (acc + scale_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_12(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_57 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_57 > 15) {
        acc = (acc + threshold_57 * 2 + 5) & 127;
        aux ^= (threshold_57 & 15);
    } else {
        acc = (acc - threshold_57 + 11) & 127;
        aux += 3;
    }
    int coefficient_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001145_4513_13(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001145_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_67 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_67 = (quantum_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_14(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001145_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_51 = (aux + st.buffer[1]) & 3;
    switch (mask_51) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_80 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_80 > 37) {
        acc = (acc + mask_80 * 2 + 5) & 127;
        aux ^= (mask_80 & 15);
    } else {
        acc = (acc - mask_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_93 = local_arr[aux % 3];
    acc = (acc + vector_93 * 2) & 127;
    int metric_39 = 0;
    for (int k = 0; k < 3; k++) {
        metric_39 = (metric_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001145_4513_15(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001145_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_24 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_24 = (coefficient_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_24) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001145_0;
    int sec_r001145_1;
    int sec_r001145_2;
    int sec_r001145_3;
    int sec_r001145_4;
    int sec_r001145_5;
    int sec_r001145_6;
    int sec_r001145_7;
    int sec_r001145_8;
    int sec_r001145_9;
    int sec_r001145_10;
    int sec_r001145_11;
    int sec_r001145_12;
    int sec_r001145_13;
    int sec_r001145_14;
    int sec_r001145_15;
    int sec_r001145_16;
    int sec_r001145_17;
    int sec_r001145_18;
    int sec_r001145_19;
    int sec_r001145_20;
    int sec_r001145_21;
    int sec_r001145_22;
    int sec_r001145_23;
    int pub_r001145_0;
    int pub_r001145_1;
    int pub_r001145_2;
    int pub_r001145_3;
    int pub_r001145_4;
    int pub_r001145_5;
    int pub_r001145_6;
    int pub_r001145_7;
    int pub_r001145_8;
    int pub_r001145_9;
    int pub_r001145_10;
    int pub_r001145_11;
    int pub_r001145_12;
    int pub_r001145_13;
    int pub_r001145_14;
    int pub_r001145_15;
    int pub_r001145_16;
    int pub_r001145_17;
    int pub_r001145_18;
    int pub_r001145_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001145_0 >= -100 && pub_r001145_0 <= 100);
    __CPROVER_assume(pub_r001145_1 >= -100 && pub_r001145_1 <= 100);
    __CPROVER_assume(pub_r001145_2 >= -100 && pub_r001145_2 <= 100);
    __CPROVER_assume(pub_r001145_3 >= -100 && pub_r001145_3 <= 100);
    __CPROVER_assume(pub_r001145_4 >= -100 && pub_r001145_4 <= 100);
    __CPROVER_assume(pub_r001145_5 >= -100 && pub_r001145_5 <= 100);
    __CPROVER_assume(pub_r001145_6 >= -100 && pub_r001145_6 <= 100);
    __CPROVER_assume(pub_r001145_7 >= -100 && pub_r001145_7 <= 100);
    __CPROVER_assume(pub_r001145_8 >= -100 && pub_r001145_8 <= 100);
    __CPROVER_assume(pub_r001145_9 >= -100 && pub_r001145_9 <= 100);
    __CPROVER_assume(pub_r001145_10 >= -100 && pub_r001145_10 <= 100);
    __CPROVER_assume(pub_r001145_11 >= -100 && pub_r001145_11 <= 100);
    __CPROVER_assume(pub_r001145_12 >= -100 && pub_r001145_12 <= 100);
    __CPROVER_assume(pub_r001145_13 >= -100 && pub_r001145_13 <= 100);
    __CPROVER_assume(pub_r001145_14 >= -100 && pub_r001145_14 <= 100);
    __CPROVER_assume(pub_r001145_15 >= -100 && pub_r001145_15 <= 100);
    __CPROVER_assume(pub_r001145_16 >= -100 && pub_r001145_16 <= 100);
    __CPROVER_assume(pub_r001145_17 >= -100 && pub_r001145_17 <= 100);
    __CPROVER_assume(pub_r001145_18 >= -100 && pub_r001145_18 <= 100);
    __CPROVER_assume(pub_r001145_19 >= -100 && pub_r001145_19 <= 100);
    __CPROVER_assume(sec_r001145_0 >= 0 && sec_r001145_0 <= 255);
    __CPROVER_assume(sec_r001145_1 >= 0 && sec_r001145_1 <= 255);
    __CPROVER_assume(sec_r001145_2 >= 0 && sec_r001145_2 <= 255);
    __CPROVER_assume(sec_r001145_3 >= 0 && sec_r001145_3 <= 255);
    __CPROVER_assume(sec_r001145_4 >= 0 && sec_r001145_4 <= 255);
    __CPROVER_assume(sec_r001145_5 >= 0 && sec_r001145_5 <= 255);
    __CPROVER_assume(sec_r001145_6 >= 0 && sec_r001145_6 <= 255);
    __CPROVER_assume(sec_r001145_7 >= 0 && sec_r001145_7 <= 255);
    __CPROVER_assume(sec_r001145_8 >= 0 && sec_r001145_8 <= 255);
    __CPROVER_assume(sec_r001145_9 >= 0 && sec_r001145_9 <= 255);
    __CPROVER_assume(sec_r001145_10 >= 0 && sec_r001145_10 <= 255);
    __CPROVER_assume(sec_r001145_11 >= 0 && sec_r001145_11 <= 255);
    __CPROVER_assume(sec_r001145_12 >= 0 && sec_r001145_12 <= 255);
    __CPROVER_assume(sec_r001145_13 >= 0 && sec_r001145_13 <= 255);
    __CPROVER_assume(sec_r001145_14 >= 0 && sec_r001145_14 <= 255);
    __CPROVER_assume(sec_r001145_15 >= 0 && sec_r001145_15 <= 255);
    __CPROVER_assume(sec_r001145_16 >= 0 && sec_r001145_16 <= 255);
    __CPROVER_assume(sec_r001145_17 >= 0 && sec_r001145_17 <= 255);
    __CPROVER_assume(sec_r001145_18 >= 0 && sec_r001145_18 <= 255);
    __CPROVER_assume(sec_r001145_19 >= 0 && sec_r001145_19 <= 255);
    __CPROVER_assume(sec_r001145_20 >= 0 && sec_r001145_20 <= 255);
    __CPROVER_assume(sec_r001145_21 >= 0 && sec_r001145_21 <= 255);
    __CPROVER_assume(sec_r001145_22 >= 0 && sec_r001145_22 <= 255);
    __CPROVER_assume(sec_r001145_23 >= 0 && sec_r001145_23 <= 255);

    struct Vector3D_R001145_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001145_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001145_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001145_0 + 7) & 15;
    struct EventLog_R001145_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001145_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001145_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001145_0 + 9) & 15;
    struct StreamBuffer_R001145_4513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001145_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001145_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001145_0 + 11) & 15;

    union RegisterBank_R001145_4513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001145_4513_0(sec_r001145_0, sec_r001145_1, pub_r001145_2, pub_r001145_3);
    int helper_flow_1 = fn_R001145_4513_1(sec_r001145_1, sec_r001145_2, pub_r001145_3, pub_r001145_4);
    int helper_flow_2 = fn_R001145_4513_2(sec_r001145_2, sec_r001145_3, pub_r001145_4);
    int helper_flow_3 = fn_R001145_4513_3(sec_r001145_3, sec_r001145_4, pub_r001145_5, pub_r001145_6);
    int helper_flow_4 = fn_R001145_4513_4(sec_r001145_4, pub_r001145_5, pub_r001145_6, pub_r001145_7, pub_r001145_8);
    int helper_flow_5 = fn_R001145_4513_5(sec_r001145_5, pub_r001145_6, pub_r001145_7, pub_r001145_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001145_9 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001145_17 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001145_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001145_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001145_21 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001145_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001145_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001145_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001145_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001145_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001145_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001145_20 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001145_21 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001145_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001145_12 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001145_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001145_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001145_16 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_14 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001145_8 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001145_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001145_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001145_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_17 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_3 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_24 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001145_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_5 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001145_14 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_5 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001145_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001145_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001145_22 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_18 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001145_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001145_20 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001145_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001145_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_25 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001145_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001145_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001145_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001145_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001145_19 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001145_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001145_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001145_4 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001145_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001145_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001145_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_25 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_0 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001145_19 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001145_2 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_2 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001145_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_17 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_53 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001145_3 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001145_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_19 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001145_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_3 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001145_11 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_50 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001145_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001145_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_35 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001145_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001145_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001145_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001145_1 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001145_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_63 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_17 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_0 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001145_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_12 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001145_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001145_21 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001145_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_3 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001145_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_58 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001145_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001145_22 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001145_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001145_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001145_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_57 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001145_19 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_64 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001145_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001145_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001145_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001145_9 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_28 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_2 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001145_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001145_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_90 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001145_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((helper_flow_3 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_56 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_35 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001145_20 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001145_23 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001145_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001145_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001145_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001145_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_18 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_97 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001145_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r001145_7 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((helper_flow_1 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001145_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001145_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_83 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_83 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001145_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001145_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001145_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001145_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001145_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_58 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_62 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001145_6 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001145_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_50 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((helper_flow_2 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001145_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_100 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001145_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001145_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001145_11 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001145_13 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_103 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001145_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_64 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001145_15 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_100 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001145_14 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_132 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001145_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001145_7 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_141 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001145_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_95 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_102 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_129 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001145_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001145_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001145_7 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001145_4 << 1) ^ (pub_r001145_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_85 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001145_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001145_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_137 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_60 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001145_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_146 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_62 << 1) ^ (pub_r001145_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_29 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001145_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001145_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_139 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_74 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001145_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_71 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001145_20 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_33 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001145_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001145_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_125 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001145_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_12 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_174 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_145 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001145_1 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_153 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001145_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001145_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001145_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_35 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001145_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_17 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_105 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001145_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001145_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001145_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_115 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_171 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001145_6 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_73 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001145_8 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_180 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_105 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001145_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_179 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_96 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001145_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r001145_22 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001145_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_135 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001145_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_202 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001145_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001145_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001145_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001145_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001145_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001145_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_89 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_112 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001145_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001145_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001145_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001145_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_97 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001145_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_167 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001145_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001145_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001145_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001145_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001145_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001145_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_33 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_177 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_64 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001145_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001145_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_111 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_71 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_73 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_132 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001145_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_60 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_4 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001145_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_199 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_139 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001145_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001145_23 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001145_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_176 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_57 << 1) ^ (pub_r001145_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001145_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001145_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_32 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001145_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_127 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_73 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001145_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001145_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_154 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001145_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_195 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001145_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_17 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001145_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_142 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_90 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001145_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001145_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((helper_flow_1 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001145_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_197 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001145_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001145_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001145_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_238 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_260 << 1) ^ (pub_r001145_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_230 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001145_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_119 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_75 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_176 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_79 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_126 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_166 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001145_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_200 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001145_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001145_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001145_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001145_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_81 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001145_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_150 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_277 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_85 << 1) ^ (pub_r001145_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_81 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_132 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001145_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001145_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_103 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001145_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_195 << 1) ^ (pub_r001145_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001145_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001145_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001145_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001145_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((helper_flow_4 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001145_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_77 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001145_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_213 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_192 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001145_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001145_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_263 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001145_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_236 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_171 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_252 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((sec_r001145_7 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_75 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001145_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001145_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_166 << 1) ^ (pub_r001145_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001145_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((sec_r001145_3 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001145_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001145_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_290 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r001145_9 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_192 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_52 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((sec_r001145_20 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001145_19 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001145_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_118 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r001145_5 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001145_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001145_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001145_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_204 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_292 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_58 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_148 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r001145_1 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((helper_flow_1 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((sec_r001145_12 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_191 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_14 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_103 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001145_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r001145_19 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_221 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001145_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_135 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001145_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001145_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_73 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_246 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_308 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_23 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001145_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001145_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_176 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001145_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((sec_r001145_14 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_14 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_135 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_244 << 1) ^ (pub_r001145_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_328 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001145_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001145_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001145_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001145_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_180 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001145_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001145_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001145_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_204 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001145_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_73 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001145_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_32 << 1) ^ (pub_r001145_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001145_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_292 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001145_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001145_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001145_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001145_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_281 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_143 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_343 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001145_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_52 << 1) ^ (pub_r001145_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001145_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001145_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001145_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((sec_r001145_11 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_293 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_161 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001145_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_266 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_380 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001145_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_341 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001145_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_281 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_349 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_193 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_345 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001145_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_367 << 1) ^ (pub_r001145_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_387 << 1) ^ (pub_r001145_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001145_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001145_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001145_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001145_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001145_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001145_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001145_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001145_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001145_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001145_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001145_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_119 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_290 << 1) ^ (pub_r001145_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001145_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001145_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_100 << 1) ^ (pub_r001145_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001145_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_142 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001145_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001145_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_316 << 1) ^ (pub_r001145_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_195 << 1) ^ (pub_r001145_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_14 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001145_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_11 << 1) ^ (pub_r001145_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001145_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001145_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_402 << 1) ^ (pub_r001145_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_438 + 1) & 15;
    out_sink ^= (stage_v_438 & 63);

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_326 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((sec_r001145_7 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((sec_r001145_9 << 1) ^ (pub_r001145_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001145_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_407 << 1) ^ (pub_r001145_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_422 << 1) ^ (pub_r001145_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_333 << 1) ^ (pub_r001145_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_104 << 1) ^ (pub_r001145_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_247 << 1) ^ (pub_r001145_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
