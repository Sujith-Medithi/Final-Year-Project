/*
 * Benchmark Program: R001966
 * Security Family: implicit_flow
 * Generator Seed: 696613
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001966_6613_0 {
    int heading;
    unsigned char pitch;
    unsigned char norm_sq;
    unsigned char coord_y;
    int buffer[3];
};

struct StreamBuffer_R001966_6613_1 {
    short capacity;
    int tail;
    int state;
    short head;
    int buffer[3];
};

struct CipherContext_R001966_6613_2 {
    int tag;
    int round_key;
    int nonce;
    int buffer[3];
};

union TelemetryField_R001966_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001966_6613_0(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int weight_70 = (aux + st.buffer[1]) & 3;
    switch (weight_70) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_84) & 63;
    acc ^= aux;
    int bound_37 = 0;
    for (int k = 0; k < 2; k++) {
        bound_37 = (bound_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_37) & 127;
    }
    int factor_84 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_84 > 28) {
        acc = (acc + factor_84 * 2 + 5) & 127;
        aux ^= (factor_84 & 15);
    } else {
        acc = (acc - factor_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_75 = local_arr[aux % 3];
    acc = (acc + metric_75 * 2) & 127;
    int delta_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001966_6613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int phase_15 = local_arr[aux % 3];
    acc = (acc + phase_15 * 2) & 127;
    int parity_32 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_32 > 26) {
        acc = (acc + parity_32 * 2 + 5) & 127;
        aux ^= (parity_32 & 15);
    } else {
        acc = (acc - parity_32 + 11) & 127;
        aux += 3;
    }
    int anchor_43 = (aux + st.buffer[1]) & 3;
    switch (anchor_43) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_3(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_78 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_78 = (anchor_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_78) & 127;
    }
    int bound_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_30) & 63;
    acc ^= aux;
    int accumulator_23 = (aux + st.buffer[1]) & 3;
    switch (accumulator_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_4(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_53 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_53 > 23) {
        acc = (acc + margin_53 * 2 + 5) & 127;
        aux ^= (margin_53 & 15);
    } else {
        acc = (acc - margin_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_57 = local_arr[aux % 3];
    acc = (acc + vector_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_5(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int offset_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_10 = local_arr[aux % 3];
    acc = (acc + threshold_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_6(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_26 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_26 > 24) {
        acc = (acc + offset_26 * 2 + 5) & 127;
        aux ^= (offset_26 & 15);
    } else {
        acc = (acc - offset_26 + 11) & 127;
        aux += 3;
    }
    int damping_31 = 0;
    for (int k = 0; k < 2; k++) {
        damping_31 = (damping_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_31) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_31 = local_arr[aux % 3];
    acc = (acc + parity_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_7(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int bound_37 = local_arr[aux % 3];
    acc = (acc + bound_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_8(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_12) & 63;
    acc ^= aux;
    int vector_99 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_99 > 48) {
        acc = (acc + vector_99 * 2 + 5) & 127;
        aux ^= (vector_99 & 15);
    } else {
        acc = (acc - vector_99 + 11) & 127;
        aux += 3;
    }
    int delta_80 = (aux + st.buffer[1]) & 3;
    switch (delta_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_69 = 0;
    for (int k = 0; k < 3; k++) {
        factor_69 = (factor_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_9(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int weight_76 = 0;
    for (int k = 0; k < 3; k++) {
        weight_76 = (weight_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_76) & 127;
    }
    int sample_19 = (aux + st.buffer[1]) & 3;
    switch (sample_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_25) & 63;
    acc ^= aux;
    int coefficient_63 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_63 > 37) {
        acc = (acc + coefficient_63 * 2 + 5) & 127;
        aux ^= (coefficient_63 & 15);
    } else {
        acc = (acc - coefficient_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_10(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_86 = local_arr[aux % 3];
    acc = (acc + accumulator_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_11(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_59) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_12(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int checksum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_93 = local_arr[aux % 3];
    acc = (acc + metric_93 * 2) & 127;
    int pivot_52 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_52 > 19) {
        acc = (acc + pivot_52 * 2 + 5) & 127;
        aux ^= (pivot_52 & 15);
    } else {
        acc = (acc - pivot_52 + 11) & 127;
        aux += 3;
    }
    int accumulator_16 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_16 = (accumulator_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_13(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001966_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quantum_10 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_10 > 18) {
        acc = (acc + quantum_10 * 2 + 5) & 127;
        aux ^= (quantum_10 & 15);
    } else {
        acc = (acc - quantum_10 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_85 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_85 = (pivot_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_85) & 127;
    }
    int vector_84 = (aux + st.buffer[1]) & 3;
    switch (vector_84) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_70) & 63;
    acc ^= aux;
    int accumulator_52 = (aux + st.buffer[1]) & 3;
    switch (accumulator_52) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_39 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_39 > 14) {
        acc = (acc + tally_39 * 2 + 5) & 127;
        aux ^= (tally_39 & 15);
    } else {
        acc = (acc - tally_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001966_6613_15(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_93 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_93 = (threshold_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_93) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_50 = local_arr[aux % 3];
    acc = (acc + segment_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001966_6613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_32 = local_arr[aux % 3];
    acc = (acc + factor_32 * 2) & 127;
    int window_53 = (st.buffer[0] * 3 + aux) & 63;
    if (window_53 > 39) {
        acc = (acc + window_53 * 2 + 5) & 127;
        aux ^= (window_53 & 15);
    } else {
        acc = (acc - window_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001966_0;
    int sec_r001966_1;
    int sec_r001966_2;
    int sec_r001966_3;
    int sec_r001966_4;
    int sec_r001966_5;
    int sec_r001966_6;
    int sec_r001966_7;
    int sec_r001966_8;
    int sec_r001966_9;
    int sec_r001966_10;
    int sec_r001966_11;
    int sec_r001966_12;
    int sec_r001966_13;
    int sec_r001966_14;
    int sec_r001966_15;
    int pub_r001966_0;
    int pub_r001966_1;
    int pub_r001966_2;
    int pub_r001966_3;
    int pub_r001966_4;
    int pub_r001966_5;
    int pub_r001966_6;
    int pub_r001966_7;
    int pub_r001966_8;
    int pub_r001966_9;
    int pub_r001966_10;
    int pub_r001966_11;
    int pub_r001966_12;
    int pub_r001966_13;
    int pub_r001966_14;
    int pub_r001966_15;
    int pub_r001966_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001966_0 >= -100 && pub_r001966_0 <= 100);
    __CPROVER_assume(pub_r001966_1 >= -100 && pub_r001966_1 <= 100);
    __CPROVER_assume(pub_r001966_2 >= -100 && pub_r001966_2 <= 100);
    __CPROVER_assume(pub_r001966_3 >= -100 && pub_r001966_3 <= 100);
    __CPROVER_assume(pub_r001966_4 >= -100 && pub_r001966_4 <= 100);
    __CPROVER_assume(pub_r001966_5 >= -100 && pub_r001966_5 <= 100);
    __CPROVER_assume(pub_r001966_6 >= -100 && pub_r001966_6 <= 100);
    __CPROVER_assume(pub_r001966_7 >= -100 && pub_r001966_7 <= 100);
    __CPROVER_assume(pub_r001966_8 >= -100 && pub_r001966_8 <= 100);
    __CPROVER_assume(pub_r001966_9 >= -100 && pub_r001966_9 <= 100);
    __CPROVER_assume(pub_r001966_10 >= -100 && pub_r001966_10 <= 100);
    __CPROVER_assume(pub_r001966_11 >= -100 && pub_r001966_11 <= 100);
    __CPROVER_assume(pub_r001966_12 >= -100 && pub_r001966_12 <= 100);
    __CPROVER_assume(pub_r001966_13 >= -100 && pub_r001966_13 <= 100);
    __CPROVER_assume(pub_r001966_14 >= -100 && pub_r001966_14 <= 100);
    __CPROVER_assume(pub_r001966_15 >= -100 && pub_r001966_15 <= 100);
    __CPROVER_assume(pub_r001966_16 >= -100 && pub_r001966_16 <= 100);
    __CPROVER_assume(sec_r001966_0 >= 0 && sec_r001966_0 <= 255);
    __CPROVER_assume(sec_r001966_1 >= 0 && sec_r001966_1 <= 255);
    __CPROVER_assume(sec_r001966_2 >= 0 && sec_r001966_2 <= 255);
    __CPROVER_assume(sec_r001966_3 >= 0 && sec_r001966_3 <= 255);
    __CPROVER_assume(sec_r001966_4 >= 0 && sec_r001966_4 <= 255);
    __CPROVER_assume(sec_r001966_5 >= 0 && sec_r001966_5 <= 255);
    __CPROVER_assume(sec_r001966_6 >= 0 && sec_r001966_6 <= 255);
    __CPROVER_assume(sec_r001966_7 >= 0 && sec_r001966_7 <= 255);
    __CPROVER_assume(sec_r001966_8 >= 0 && sec_r001966_8 <= 255);
    __CPROVER_assume(sec_r001966_9 >= 0 && sec_r001966_9 <= 255);
    __CPROVER_assume(sec_r001966_10 >= 0 && sec_r001966_10 <= 255);
    __CPROVER_assume(sec_r001966_11 >= 0 && sec_r001966_11 <= 255);
    __CPROVER_assume(sec_r001966_12 >= 0 && sec_r001966_12 <= 255);
    __CPROVER_assume(sec_r001966_13 >= 0 && sec_r001966_13 <= 255);
    __CPROVER_assume(sec_r001966_14 >= 0 && sec_r001966_14 <= 255);
    __CPROVER_assume(sec_r001966_15 >= 0 && sec_r001966_15 <= 255);

    struct Vector3D_R001966_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001966_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001966_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001966_0 + 7) & 15;
    struct StreamBuffer_R001966_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001966_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001966_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001966_0 + 9) & 15;
    struct CipherContext_R001966_6613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001966_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001966_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001966_0 + 11) & 15;

    union TelemetryField_R001966_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001966_6613_0(sec_r001966_0, sec_r001966_1);
    int helper_flow_1 = fn_R001966_6613_1(sec_r001966_1, sec_r001966_2, pub_r001966_3, pub_r001966_4);
    int helper_flow_2 = fn_R001966_6613_2(sec_r001966_2, pub_r001966_3, pub_r001966_4, pub_r001966_5);
    int helper_flow_3 = fn_R001966_6613_3(sec_r001966_3, sec_r001966_4);
    int helper_flow_4 = fn_R001966_6613_4(sec_r001966_4, sec_r001966_5);
    int helper_flow_5 = fn_R001966_6613_5(sec_r001966_5, pub_r001966_6, pub_r001966_7);
    int helper_flow_6 = fn_R001966_6613_6(sec_r001966_6, pub_r001966_7, pub_r001966_8);
    int helper_flow_7 = fn_R001966_6613_7(sec_r001966_7, pub_r001966_8);
    int helper_flow_8 = fn_R001966_6613_8(sec_r001966_8, pub_r001966_9);
    int helper_flow_9 = fn_R001966_6613_9(sec_r001966_9, sec_r001966_10, pub_r001966_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001966_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_0 + pub_r001966_9 * 2 + 8) & 127;
    if (stage_v_1 > 48) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001966_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001966_15 + pub_r001966_15 * 2 + 14) & 127;
    if (stage_v_3 > 56) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001966_11 + pub_r001966_10 * 2 + 17) & 127;
    if (stage_v_4 > 54) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001966_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001966_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001966_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001966_14 + pub_r001966_12 * 2 + 29) & 127;
    if (stage_v_8 > 17) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_0 + pub_r001966_12 * 2 + 32) & 127;
    if (stage_v_9 > 24) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001966_0 + pub_r001966_16 * 2 + 35) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001966_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001966_15 + pub_r001966_1 * 2 + 41) & 127;
    if (stage_v_12 > 43) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001966_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001966_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001966_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001966_0 + pub_r001966_9 * 2 + 53) & 127;
    if (stage_v_16 > 54) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001966_8 + pub_r001966_4 * 2 + 56) & 127;
    if (stage_v_17 > 60) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001966_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001966_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001966_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001966_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001966_1 + pub_r001966_0 * 2 + 71) & 127;
    if (stage_v_22 > 58) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_8 + pub_r001966_13 * 2 + 74) & 127;
    if (stage_v_23 > 33) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001966_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001966_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001966_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001966_8 + pub_r001966_14 * 2 + 86) & 127;
    if (stage_v_27 > 56) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001966_9 + pub_r001966_15 * 2 + 89) & 127;
    if (stage_v_28 > 33) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001966_5 + pub_r001966_2 * 2 + 92) & 127;
    if (stage_v_29 > 36) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_28 + pub_r001966_7 * 2 + 95) & 127;
    if (stage_v_30 > 21) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001966_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001966_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001966_0 + pub_r001966_5 * 2 + 104) & 127;
    if (stage_v_33 > 34) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_2 + pub_r001966_2 * 2 + 107) & 127;
    if (stage_v_34 > 50) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_1 + pub_r001966_10 * 2 + 110) & 127;
    if (stage_v_35 > 45) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001966_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_3 + pub_r001966_0 * 2 + 116) & 127;
    if (stage_v_37 > 48) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001966_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_33 + pub_r001966_2 * 2 + 122) & 127;
    if (stage_v_39 > 24) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001966_8 + pub_r001966_8 * 2 + 125) & 127;
    if (stage_v_40 > 19) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001966_6 + pub_r001966_13 * 2 + 128) & 127;
    if (stage_v_41 > 55) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001966_12 + pub_r001966_11 * 2 + 131) & 127;
    if (stage_v_42 > 26) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001966_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_1 + pub_r001966_6 * 2 + 137) & 127;
    if (stage_v_44 > 19) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001966_14 + pub_r001966_8 * 2 + 140) & 127;
    if (stage_v_45 > 29) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001966_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_34 + pub_r001966_10 * 2 + 146) & 127;
    if (stage_v_47 > 31) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001966_11 + pub_r001966_1 * 2 + 149) & 127;
    if (stage_v_48 > 38) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_7 + pub_r001966_12 * 2 + 152) & 127;
    if (stage_v_49 > 18) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_0 + pub_r001966_8 * 2 + 155) & 127;
    if (stage_v_50 > 25) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_17 + pub_r001966_12 * 2 + 158) & 127;
    if (stage_v_51 > 54) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001966_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001966_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001966_11 + pub_r001966_4 * 2 + 167) & 127;
    if (stage_v_54 > 58) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001966_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_35 + pub_r001966_9 * 2 + 173) & 127;
    if (stage_v_56 > 18) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001966_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_22 + pub_r001966_16 * 2 + 179) & 127;
    if (stage_v_58 > 47) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001966_1 + pub_r001966_6 * 2 + 182) & 127;
    if (stage_v_59 > 26) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001966_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001966_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_23 + pub_r001966_10 * 2 + 191) & 127;
    if (stage_v_62 > 60) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001966_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_4 + pub_r001966_1 * 2 + 197) & 127;
    if (stage_v_64 > 37) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001966_1 + pub_r001966_5 * 2 + 200) & 127;
    if (stage_v_65 > 33) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_7 + pub_r001966_1 * 2 + 203) & 127;
    if (stage_v_66 > 53) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001966_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001966_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001966_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001966_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001966_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_3 + pub_r001966_5 * 2 + 221) & 127;
    if (stage_v_72 > 33) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001966_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_64 + pub_r001966_9 * 2 + 227) & 127;
    if (stage_v_74 > 40) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_54 + pub_r001966_14 * 2 + 230) & 127;
    if (stage_v_75 > 19) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001966_3 + pub_r001966_10 * 2 + 233) & 127;
    if (stage_v_76 > 32) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_12 + pub_r001966_5 * 2 + 236) & 127;
    if (stage_v_77 > 15) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_62 + pub_r001966_3 * 2 + 239) & 127;
    if (stage_v_78 > 59) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_8 + pub_r001966_3 * 2 + 242) & 127;
    if (stage_v_79 > 30) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_50 + pub_r001966_14 * 2 + 245) & 127;
    if (stage_v_80 > 59) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_0 + pub_r001966_12 * 2 + 248) & 127;
    if (stage_v_81 > 55) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_48 + pub_r001966_0 * 2 + 251) & 127;
    if (stage_v_82 > 53) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_62 + pub_r001966_14 * 2 + 254) & 127;
    if (stage_v_83 > 42) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_79 + pub_r001966_7 * 2 + 257) & 127;
    if (stage_v_84 > 17) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_39 + pub_r001966_0 * 2 + 260) & 127;
    if (stage_v_85 > 52) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_62 + pub_r001966_5 * 2 + 263) & 127;
    if (stage_v_86 > 43) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001966_14 + pub_r001966_15 * 2 + 266) & 127;
    if (stage_v_87 > 43) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_30 + pub_r001966_13 * 2 + 269) & 127;
    if (stage_v_88 > 51) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_72 + pub_r001966_1 * 2 + 272) & 127;
    if (stage_v_89 > 59) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001966_7 + pub_r001966_5 * 2 + 275) & 127;
    if (stage_v_90 > 16) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_90 + pub_r001966_16 * 2 + 278) & 127;
    if (stage_v_91 > 20) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_3 + pub_r001966_10 * 2 + 281) & 127;
    if (stage_v_92 > 53) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001966_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001966_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_51 + pub_r001966_13 * 2 + 290) & 127;
    if (stage_v_95 > 22) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001966_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_16 + pub_r001966_8 * 2 + 296) & 127;
    if (stage_v_97 > 48) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001966_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_58 + pub_r001966_7 * 2 + 302) & 127;
    if (stage_v_99 > 58) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_17 + pub_r001966_3 * 2 + 305) & 127;
    if (stage_v_100 > 41) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001966_3 + pub_r001966_5 * 2 + 308) & 127;
    if (stage_v_101 > 24) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_30 + pub_r001966_5 * 2 + 311) & 127;
    if (stage_v_102 > 25) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_23 + pub_r001966_7 * 2 + 314) & 127;
    if (stage_v_103 > 15) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001966_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_85 + pub_r001966_4 * 2 + 320) & 127;
    if (stage_v_105 > 39) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_27 + pub_r001966_5 * 2 + 323) & 127;
    if (stage_v_106 > 50) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001966_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_103 + pub_r001966_11 * 2 + 329) & 127;
    if (stage_v_108 > 26) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_1 + pub_r001966_9 * 2 + 332) & 127;
    if (stage_v_109 > 55) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_49 + pub_r001966_0 * 2 + 335) & 127;
    if (stage_v_110 > 46) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001966_2 + pub_r001966_0 * 2 + 338) & 127;
    if (stage_v_111 > 16) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_37 + pub_r001966_2 * 2 + 341) & 127;
    if (stage_v_112 > 28) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_102 + pub_r001966_1 * 2 + 344) & 127;
    if (stage_v_113 > 50) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_92 + pub_r001966_1 * 2 + 347) & 127;
    if (stage_v_114 > 38) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001966_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001966_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_75 + pub_r001966_12 * 2 + 356) & 127;
    if (stage_v_117 > 54) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_72 + pub_r001966_2 * 2 + 359) & 127;
    if (stage_v_118 > 34) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_95 + pub_r001966_3 * 2 + 362) & 127;
    if (stage_v_119 > 55) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_86 + pub_r001966_0 * 2 + 365) & 127;
    if (stage_v_120 > 48) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001966_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_56 + pub_r001966_4 * 2 + 371) & 127;
    if (stage_v_122 > 45) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_37 + pub_r001966_5 * 2 + 374) & 127;
    if (stage_v_123 > 38) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001966_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001966_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_34 + pub_r001966_0 * 2 + 383) & 127;
    if (stage_v_126 > 31) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001966_6 + pub_r001966_16 * 2 + 386) & 127;
    if (stage_v_127 > 24) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_110 + pub_r001966_6 * 2 + 389) & 127;
    if (stage_v_128 > 36) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001966_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001966_2 + pub_r001966_1 * 2 + 395) & 127;
    if (stage_v_130 > 18) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001966_1 + pub_r001966_7 * 2 + 398) & 127;
    if (stage_v_131 > 37) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_34 + pub_r001966_11 * 2 + 401) & 127;
    if (stage_v_132 > 30) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_117 + pub_r001966_4 * 2 + 404) & 127;
    if (stage_v_133 > 24) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_101 + pub_r001966_5 * 2 + 407) & 127;
    if (stage_v_134 > 30) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001966_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_130 + pub_r001966_14 * 2 + 413) & 127;
    if (stage_v_136 > 39) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_89 + pub_r001966_6 * 2 + 416) & 127;
    if (stage_v_137 > 28) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_66 + pub_r001966_4 * 2 + 419) & 127;
    if (stage_v_138 > 21) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_54 + pub_r001966_5 * 2 + 422) & 127;
    if (stage_v_139 > 35) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_87 + pub_r001966_0 * 2 + 425) & 127;
    if (stage_v_140 > 23) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_34 + pub_r001966_16 * 2 + 428) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001966_13 + pub_r001966_1 * 2 + 431) & 127;
    if (stage_v_142 > 60) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_92 + pub_r001966_4 * 2 + 434) & 127;
    if (stage_v_143 > 47) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001966_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_48 + pub_r001966_11 * 2 + 440) & 127;
    if (stage_v_145 > 19) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_87 + pub_r001966_0 * 2 + 443) & 127;
    if (stage_v_146 > 54) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001966_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_42 + pub_r001966_13 * 2 + 449) & 127;
    if (stage_v_148 > 59) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_101 + pub_r001966_13 * 2 + 452) & 127;
    if (stage_v_149 > 19) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001966_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001966_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_42 + pub_r001966_10 * 2 + 461) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_148 + pub_r001966_6 * 2 + 464) & 127;
    if (stage_v_153 > 37) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001966_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001966_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_118 + pub_r001966_3 * 2 + 473) & 127;
    if (stage_v_156 > 22) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_83 + pub_r001966_13 * 2 + 476) & 127;
    if (stage_v_157 > 54) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001966_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001966_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001966_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001966_2 + pub_r001966_9 * 2 + 488) & 127;
    if (stage_v_161 > 51) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_106 + pub_r001966_2 * 2 + 491) & 127;
    if (stage_v_162 > 35) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001966_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (helper_flow_7 + pub_r001966_12 * 2 + 497) & 127;
    if (stage_v_164 > 58) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001966_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_138 + pub_r001966_12 * 2 + 503) & 127;
    if (stage_v_166 > 30) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001966_1 + pub_r001966_14 * 2 + 506) & 127;
    if (stage_v_167 > 22) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001966_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_142 + pub_r001966_7 * 2 + 512) & 127;
    if (stage_v_169 > 26) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001966_7 + pub_r001966_7 * 2 + 515) & 127;
    if (stage_v_170 > 30) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_133 + pub_r001966_14 * 2 + 518) & 127;
    if (stage_v_171 > 26) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_141 + pub_r001966_10 * 2 + 521) & 127;
    if (stage_v_172 > 21) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_16 + pub_r001966_1 * 2 + 524) & 127;
    if (stage_v_173 > 30) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_161 + pub_r001966_0 * 2 + 527) & 127;
    if (stage_v_174 > 47) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001966_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_174 + pub_r001966_1 * 2 + 533) & 127;
    if (stage_v_176 > 54) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_28 + pub_r001966_8 * 2 + 536) & 127;
    if (stage_v_177 > 24) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_56 + pub_r001966_16 * 2 + 539) & 127;
    if (stage_v_178 > 28) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001966_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_136 + pub_r001966_14 * 2 + 545) & 127;
    if (stage_v_180 > 34) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_136 + pub_r001966_8 * 2 + 548) & 127;
    if (stage_v_181 > 17) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_126 + pub_r001966_4 * 2 + 551) & 127;
    if (stage_v_182 > 42) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_87 + pub_r001966_0 * 2 + 554) & 127;
    if (stage_v_183 > 23) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_92 + pub_r001966_5 * 2 + 557) & 127;
    if (stage_v_184 > 53) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_22 + pub_r001966_11 * 2 + 560) & 127;
    if (stage_v_185 > 20) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001966_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_148 + pub_r001966_13 * 2 + 566) & 127;
    if (stage_v_187 > 54) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001966_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_27 + pub_r001966_7 * 2 + 572) & 127;
    if (stage_v_189 > 49) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_80 + pub_r001966_2 * 2 + 575) & 127;
    if (stage_v_190 > 45) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001966_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_132 + pub_r001966_11 * 2 + 581) & 127;
    if (stage_v_192 > 41) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_166 + pub_r001966_12 * 2 + 584) & 127;
    if (stage_v_193 > 15) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (helper_flow_0 + pub_r001966_0 * 2 + 587) & 127;
    if (stage_v_194 > 55) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_34 + pub_r001966_7 * 2 + 590) & 127;
    if (stage_v_195 > 44) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (helper_flow_2 + pub_r001966_2 * 2 + 593) & 127;
    if (stage_v_196 > 60) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_162 + pub_r001966_3 * 2 + 596) & 127;
    if (stage_v_197 > 22) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001966_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_187 + pub_r001966_13 * 2 + 602) & 127;
    if (stage_v_199 > 52) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_58 + pub_r001966_11 * 2 + 605) & 127;
    if (stage_v_200 > 18) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001966_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001966_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001966_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001966_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001966_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_139 + pub_r001966_9 * 2 + 623) & 127;
    if (stage_v_206 > 37) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001966_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001966_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_146 + pub_r001966_2 * 2 + 632) & 127;
    if (stage_v_209 > 49) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001966_5 + pub_r001966_16 * 2 + 635) & 127;
    if (stage_v_210 > 47) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001966_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_29 + pub_r001966_1 * 2 + 641) & 127;
    if (stage_v_212 > 59) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_185 + pub_r001966_4 * 2 + 644) & 127;
    if (stage_v_213 > 25) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_169 + pub_r001966_13 * 2 + 647) & 127;
    if (stage_v_214 > 32) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_110 + pub_r001966_16 * 2 + 650) & 127;
    if (stage_v_215 > 46) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001966_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_44 + pub_r001966_6 * 2 + 656) & 127;
    if (stage_v_217 > 20) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001966_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_120 + pub_r001966_12 * 2 + 662) & 127;
    if (stage_v_219 > 50) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
