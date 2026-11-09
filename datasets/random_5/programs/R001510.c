/*
 * Benchmark Program: R001510
 * Security Family: mixed_control_data
 * Generator Seed: 651013
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001510_1013_0 {
    int round_key;
    int tag;
    short nonce;
    int buffer[3];
};

struct StreamBuffer_R001510_1013_1 {
    int capacity;
    unsigned char checksum;
    int head;
    int tail;
    unsigned char state;
    unsigned char watermark;
    int buffer[3];
};

struct Vector3D_R001510_1013_2 {
    short heading;
    int coord_y;
    int pitch;
    int buffer[3];
};

struct Transaction_R001510_1013_3 {
    short fee;
    int balance;
    int account_id;
    unsigned char auth_code;
    int buffer[3];
};

union TelemetryField_R001510_1013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001510_1013_0(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int sample_32 = (aux + st.buffer[1]) & 3;
    switch (sample_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_66 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_66 = (coefficient_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_1(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001510_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_68 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_68 > 48) {
        acc = (acc + segment_68 * 2 + 5) & 127;
        aux ^= (segment_68 & 15);
    } else {
        acc = (acc - segment_68 + 11) & 127;
        aux += 3;
    }
    int factor_97 = 0;
    for (int k = 0; k < 2; k++) {
        factor_97 = (factor_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_97) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_64 = (aux + st.buffer[1]) & 3;
    switch (index_reg_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_88 = local_arr[aux % 3];
    acc = (acc + delta_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_3(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int pivot_95 = local_arr[aux % 3];
    acc = (acc + pivot_95 * 2) & 127;
    int residue_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_79) & 63;
    acc ^= aux;
    int window_42 = 0;
    for (int k = 0; k < 2; k++) {
        window_42 = (window_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_4(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001510_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int vector_12 = local_arr[aux % 3];
    acc = (acc + vector_12 * 2) & 127;
    int phase_77 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_77 > 48) {
        acc = (acc + phase_77 * 2 + 5) & 127;
        aux ^= (phase_77 & 15);
    } else {
        acc = (acc - phase_77 + 11) & 127;
        aux += 3;
    }
    int metric_67 = (aux + st.buffer[1]) & 3;
    switch (metric_67) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int stride_81 = (aux + st.buffer[1]) & 3;
    switch (stride_81) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_61) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_96 = local_arr[aux % 3];
    acc = (acc + sample_96 * 2) & 127;
    int anchor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_29 > 22) {
        acc = (acc + anchor_29 * 2 + 5) & 127;
        aux ^= (anchor_29 & 15);
    } else {
        acc = (acc - anchor_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_6(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_50 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_50 > 32) {
        acc = (acc + weight_50 * 2 + 5) & 127;
        aux ^= (weight_50 & 15);
    } else {
        acc = (acc - weight_50 + 11) & 127;
        aux += 3;
    }
    int sample_25 = 0;
    for (int k = 0; k < 3; k++) {
        sample_25 = (sample_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_25) & 127;
    }
    int factor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_41 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_41 > 17) {
        acc = (acc + quotient_41 * 2 + 5) & 127;
        aux ^= (quotient_41 & 15);
    } else {
        acc = (acc - quotient_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_80 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_80 > 50) {
        acc = (acc + offset_80 * 2 + 5) & 127;
        aux ^= (offset_80 & 15);
    } else {
        acc = (acc - offset_80 + 11) & 127;
        aux += 3;
    }
    int metric_13 = 0;
    for (int k = 0; k < 3; k++) {
        metric_13 = (metric_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_58 = local_arr[aux % 3];
    acc = (acc + delta_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001510_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_61 = local_arr[aux % 3];
    acc = (acc + margin_61 * 2) & 127;
    int index_reg_58 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_58 = (index_reg_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_58) & 127;
    }
    int quotient_13 = (aux + st.buffer[1]) & 3;
    switch (quotient_13) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_44 = (aux + st.buffer[1]) & 3;
    switch (pivot_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_20 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_20 > 48) {
        acc = (acc + vector_20 * 2 + 5) & 127;
        aux ^= (vector_20 & 15);
    } else {
        acc = (acc - vector_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_53 = (aux + st.buffer[1]) & 3;
    switch (weight_53) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_85 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_85 > 40) {
        acc = (acc + index_reg_85 * 2 + 5) & 127;
        aux ^= (index_reg_85 & 15);
    } else {
        acc = (acc - index_reg_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001510_1013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_25 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_25 = (quantum_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_89 > 35) {
        acc = (acc + quantum_89 * 2 + 5) & 127;
        aux ^= (quantum_89 & 15);
    } else {
        acc = (acc - quantum_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_37 = local_arr[aux % 3];
    acc = (acc + tally_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_14(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001510_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quantum_65 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_65 > 50) {
        acc = (acc + quantum_65 * 2 + 5) & 127;
        aux ^= (quantum_65 & 15);
    } else {
        acc = (acc - quantum_65 + 11) & 127;
        aux += 3;
    }
    int delta_36 = 0;
    for (int k = 0; k < 3; k++) {
        delta_36 = (delta_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_36) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_60 = local_arr[aux % 3];
    acc = (acc + tally_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001510_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_67 = (aux + st.buffer[1]) & 3;
    switch (damping_67) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_82 = local_arr[aux % 3];
    acc = (acc + scale_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001510_1013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001510_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_71 = (st.buffer[0] * 3 + aux) & 63;
    if (window_71 > 26) {
        acc = (acc + window_71 * 2 + 5) & 127;
        aux ^= (window_71 & 15);
    } else {
        acc = (acc - window_71 + 11) & 127;
        aux += 3;
    }
    int bound_53 = (aux + st.buffer[1]) & 3;
    switch (bound_53) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_61 = 0;
    for (int k = 0; k < 3; k++) {
        damping_61 = (damping_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_61) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001510_0;
    int sec_r001510_1;
    int sec_r001510_2;
    int sec_r001510_3;
    int sec_r001510_4;
    int sec_r001510_5;
    int sec_r001510_6;
    int sec_r001510_7;
    int sec_r001510_8;
    int sec_r001510_9;
    int sec_r001510_10;
    int sec_r001510_11;
    int sec_r001510_12;
    int sec_r001510_13;
    int sec_r001510_14;
    int sec_r001510_15;
    int sec_r001510_16;
    int sec_r001510_17;
    int sec_r001510_18;
    int pub_r001510_0;
    int pub_r001510_1;
    int pub_r001510_2;
    int pub_r001510_3;
    int pub_r001510_4;
    int pub_r001510_5;
    int pub_r001510_6;
    int pub_r001510_7;
    int pub_r001510_8;
    int pub_r001510_9;
    int pub_r001510_10;
    int pub_r001510_11;
    int pub_r001510_12;
    int pub_r001510_13;
    int pub_r001510_14;
    int pub_r001510_15;
    int pub_r001510_16;
    int pub_r001510_17;
    int pub_r001510_18;
    int pub_r001510_19;
    int pub_r001510_20;
    int pub_r001510_21;
    int pub_r001510_22;
    int pub_r001510_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001510_0 >= -100 && pub_r001510_0 <= 100);
    __CPROVER_assume(pub_r001510_1 >= -100 && pub_r001510_1 <= 100);
    __CPROVER_assume(pub_r001510_2 >= -100 && pub_r001510_2 <= 100);
    __CPROVER_assume(pub_r001510_3 >= -100 && pub_r001510_3 <= 100);
    __CPROVER_assume(pub_r001510_4 >= -100 && pub_r001510_4 <= 100);
    __CPROVER_assume(pub_r001510_5 >= -100 && pub_r001510_5 <= 100);
    __CPROVER_assume(pub_r001510_6 >= -100 && pub_r001510_6 <= 100);
    __CPROVER_assume(pub_r001510_7 >= -100 && pub_r001510_7 <= 100);
    __CPROVER_assume(pub_r001510_8 >= -100 && pub_r001510_8 <= 100);
    __CPROVER_assume(pub_r001510_9 >= -100 && pub_r001510_9 <= 100);
    __CPROVER_assume(pub_r001510_10 >= -100 && pub_r001510_10 <= 100);
    __CPROVER_assume(pub_r001510_11 >= -100 && pub_r001510_11 <= 100);
    __CPROVER_assume(pub_r001510_12 >= -100 && pub_r001510_12 <= 100);
    __CPROVER_assume(pub_r001510_13 >= -100 && pub_r001510_13 <= 100);
    __CPROVER_assume(pub_r001510_14 >= -100 && pub_r001510_14 <= 100);
    __CPROVER_assume(pub_r001510_15 >= -100 && pub_r001510_15 <= 100);
    __CPROVER_assume(pub_r001510_16 >= -100 && pub_r001510_16 <= 100);
    __CPROVER_assume(pub_r001510_17 >= -100 && pub_r001510_17 <= 100);
    __CPROVER_assume(pub_r001510_18 >= -100 && pub_r001510_18 <= 100);
    __CPROVER_assume(pub_r001510_19 >= -100 && pub_r001510_19 <= 100);
    __CPROVER_assume(pub_r001510_20 >= -100 && pub_r001510_20 <= 100);
    __CPROVER_assume(pub_r001510_21 >= -100 && pub_r001510_21 <= 100);
    __CPROVER_assume(pub_r001510_22 >= -100 && pub_r001510_22 <= 100);
    __CPROVER_assume(pub_r001510_23 >= -100 && pub_r001510_23 <= 100);
    __CPROVER_assume(sec_r001510_0 >= 0 && sec_r001510_0 <= 255);
    __CPROVER_assume(sec_r001510_1 >= 0 && sec_r001510_1 <= 255);
    __CPROVER_assume(sec_r001510_2 >= 0 && sec_r001510_2 <= 255);
    __CPROVER_assume(sec_r001510_3 >= 0 && sec_r001510_3 <= 255);
    __CPROVER_assume(sec_r001510_4 >= 0 && sec_r001510_4 <= 255);
    __CPROVER_assume(sec_r001510_5 >= 0 && sec_r001510_5 <= 255);
    __CPROVER_assume(sec_r001510_6 >= 0 && sec_r001510_6 <= 255);
    __CPROVER_assume(sec_r001510_7 >= 0 && sec_r001510_7 <= 255);
    __CPROVER_assume(sec_r001510_8 >= 0 && sec_r001510_8 <= 255);
    __CPROVER_assume(sec_r001510_9 >= 0 && sec_r001510_9 <= 255);
    __CPROVER_assume(sec_r001510_10 >= 0 && sec_r001510_10 <= 255);
    __CPROVER_assume(sec_r001510_11 >= 0 && sec_r001510_11 <= 255);
    __CPROVER_assume(sec_r001510_12 >= 0 && sec_r001510_12 <= 255);
    __CPROVER_assume(sec_r001510_13 >= 0 && sec_r001510_13 <= 255);
    __CPROVER_assume(sec_r001510_14 >= 0 && sec_r001510_14 <= 255);
    __CPROVER_assume(sec_r001510_15 >= 0 && sec_r001510_15 <= 255);
    __CPROVER_assume(sec_r001510_16 >= 0 && sec_r001510_16 <= 255);
    __CPROVER_assume(sec_r001510_17 >= 0 && sec_r001510_17 <= 255);
    __CPROVER_assume(sec_r001510_18 >= 0 && sec_r001510_18 <= 255);

    struct CipherContext_R001510_1013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001510_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001510_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001510_0 + 7) & 15;
    struct StreamBuffer_R001510_1013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001510_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001510_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001510_0 + 9) & 15;
    struct Vector3D_R001510_1013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001510_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001510_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001510_0 + 11) & 15;
    struct Transaction_R001510_1013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001510_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001510_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001510_0 + 13) & 15;

    union TelemetryField_R001510_1013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001510_1013_0(sec_r001510_0, pub_r001510_1, pub_r001510_2);
    int helper_flow_1 = fn_R001510_1013_1(sec_r001510_1, pub_r001510_2);
    int helper_flow_2 = fn_R001510_1013_2(sec_r001510_2, pub_r001510_3, pub_r001510_4, pub_r001510_5, pub_r001510_6);
    int helper_flow_3 = fn_R001510_1013_3(sec_r001510_3, pub_r001510_4, pub_r001510_5);
    int helper_flow_4 = fn_R001510_1013_4(sec_r001510_4, pub_r001510_5, pub_r001510_6);
    int helper_flow_5 = fn_R001510_1013_5(sec_r001510_5, sec_r001510_6, pub_r001510_7, pub_r001510_8);
    int helper_flow_6 = fn_R001510_1013_6(sec_r001510_6, sec_r001510_7);
    int helper_flow_7 = fn_R001510_1013_7(sec_r001510_7, pub_r001510_8, pub_r001510_9, pub_r001510_10, pub_r001510_11);
    int helper_flow_8 = fn_R001510_1013_8(sec_r001510_8, pub_r001510_9, pub_r001510_10, pub_r001510_11);
    int helper_flow_9 = fn_R001510_1013_9(sec_r001510_9, sec_r001510_10, pub_r001510_11, pub_r001510_12);
    int helper_flow_10 = fn_R001510_1013_10(sec_r001510_10, sec_r001510_11, pub_r001510_12, pub_r001510_13, pub_r001510_14);
    int helper_flow_11 = fn_R001510_1013_11(sec_r001510_11, pub_r001510_12, pub_r001510_13, pub_r001510_14, pub_r001510_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_0 > 36) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001510_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001510_12 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_2 > 23) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001510_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001510_8) & 127;
    if (stage_v_4 > 48) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_5 > 38) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001510_0 ^ 0x2A) * 2 + pub_r001510_6) & 127;
    if (stage_v_6 > 36) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001510_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001510_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001510_16 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_9 > 50) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_10 > 20) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_11 > 42) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_12 > 32) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001510_13 ^ 0x2A) * 2 + pub_r001510_14) & 127;
    if (stage_v_13 > 33) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_14 > 31) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_15 > 44) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001510_6 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_16 > 42) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001510_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_18 > 35) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001510_4 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_19 > 44) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_20 > 20) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_21 > 46) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001510_14 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_23 > 24) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_24 > 31) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001510_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001510_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_27 > 35) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_28 > 29) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001510_8 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_29 > 30) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001510_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001510_1 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_31 > 29) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_32 > 32) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_33 > 26) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_34 > 44) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_35 > 48) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_36 > 28) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_37 > 43) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001510_16 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_38 > 37) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001510_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_40 > 28) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_41 > 27) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001510_3 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_42 > 34) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_43 > 29) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_44 > 49) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001510_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_46 > 33) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_47 > 25) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001510_2 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_48 > 34) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_49 > 46) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_50 > 49) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001510_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001510_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_14) & 127;
    if (stage_v_53 > 24) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_54 > 50) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_55 > 47) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_56 > 45) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001510_7 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_57 > 37) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_58 > 33) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001510_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_60 > 50) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_61 > 48) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_62 > 20) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_63 > 37) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001510_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_65 > 22) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_66 > 29) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_67 > 49) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001510_8) & 127;
    if (stage_v_68 > 50) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_69 > 27) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001510_8) & 127;
    if (stage_v_70 > 44) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001510_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_72 > 49) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001510_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001510_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001510_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001510_4 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_76 > 31) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_77 > 49) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001510_14 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_78 > 46) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_79 > 34) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001510_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_81 > 20) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_82 > 28) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001510_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001510_23 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_85 > 36) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001510_1) & 127;
    if (stage_v_86 > 22) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_87 > 27) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001510_14) & 127;
    if (stage_v_88 > 31) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_89 > 26) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_90 > 33) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_91 > 23) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_92 > 47) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_93 > 25) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_94 > 25) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001510_14) & 127;
    if (stage_v_95 > 32) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001510_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_97 > 22) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001510_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001510_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_100 > 21) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_101 > 25) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_102 > 37) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001510_4 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_103 > 35) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_104 > 46) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001510_14) & 127;
    if (stage_v_105 > 49) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_106 > 28) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001510_1) & 127;
    if (stage_v_107 > 41) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001510_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_109 > 20) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001510_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_111 > 20) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001510_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001510_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_114 > 20) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_115 > 41) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_116 > 48) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_117 > 33) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001510_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001510_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001510_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_121 > 33) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_122 > 41) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_123 > 20) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001510_23 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001510_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_126 > 47) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_127 > 35) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001510_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_129 > 34) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_130 > 23) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_131 > 39) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_6) & 127;
    if (stage_v_132 > 36) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_133 > 38) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001510_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_135 > 43) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001510_1) & 127;
    if (stage_v_136 > 31) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001510_21 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_138 > 50) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_139 > 29) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_140 > 35) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_141 > 35) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_142 > 23) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001510_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_144 > 35) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_145 > 26) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_146 > 41) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_147 > 29) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_148 > 28) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_149 > 38) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001510_3 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_150 > 49) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001510_8) & 127;
    if (stage_v_151 > 35) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001510_17 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_152 > 21) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001510_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_154 > 23) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001510_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_156 > 33) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r001510_1 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_157 > 26) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_158 > 42) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001510_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001510_3 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_160 > 48) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_161 > 30) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001510_5 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_162 > 42) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_163 > 21) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001510_22 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001510_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001510_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_168 > 34) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_169 > 48) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001510_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001510_3) & 127;
    if (stage_v_171 > 45) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_172 > 28) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_173 > 21) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001510_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001510_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_176 > 47) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_177 > 32) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_178 > 21) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_179 > 35) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001510_12 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_180 > 44) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001510_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001510_12) & 127;
    if (stage_v_182 > 47) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001510_1) & 127;
    if (stage_v_183 > 40) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001510_15) & 127;
    if (stage_v_184 > 25) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001510_8) & 127;
    if (stage_v_185 > 49) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001510_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001510_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001510_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001510_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001510_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_191 > 47) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_192 > 47) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001510_18 ^ 0x2A) * 2 + pub_r001510_6) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001510_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001510_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_196 > 47) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_197 > 35) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001510_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001510_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001510_8 ^ 0x2A) * 2 + pub_r001510_6) & 127;
    if (stage_v_200 > 31) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001510_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001510_21 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_204 > 40) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_205 > 34) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001510_2) & 127;
    if (stage_v_206 > 46) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001510_12 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_207 > 20) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_208 > 37) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_209 > 25) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001510_1) & 127;
    if (stage_v_210 > 29) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_211 > 44) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r001510_12 ^ 0x2A) * 2 + pub_r001510_17) & 127;
    if (stage_v_212 > 47) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001510_7) & 127;
    if (stage_v_213 > 36) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001510_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_215 > 31) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r001510_3 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_216 > 36) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001510_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_218 > 46) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001510_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001510_4) & 127;
    if (stage_v_220 > 29) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_221 > 33) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001510_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_223 > 23) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001510_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_225 > 29) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_226 > 28) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001510_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r001510_17 ^ 0x2A) * 2 + pub_r001510_5) & 127;
    if (stage_v_228 > 37) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_229 > 42) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001510_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_231 > 35) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_232 > 31) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001510_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001510_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001510_22) & 127;
    if (stage_v_235 > 32) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_226 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_236 > 39) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001510_20 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001510_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001510_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001510_13) & 127;
    if (stage_v_240 > 25) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_241 > 50) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_242 > 41) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_243 > 25) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001510_15 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_244 > 32) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001510_0) & 127;
    if (stage_v_245 > 39) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_246 > 24) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001510_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001510_16) & 127;
    if (stage_v_248 > 26) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001510_11) & 127;
    if (stage_v_249 > 35) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001510_10) & 127;
    if (stage_v_250 > 44) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001510_23) & 127;
    if (stage_v_251 > 49) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001510_19) & 127;
    if (stage_v_252 > 48) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001510_18) & 127;
    if (stage_v_253 > 30) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001510_20) & 127;
    if (stage_v_254 > 20) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001510_9) & 127;
    if (stage_v_255 > 48) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001510_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001510_21) & 127;
    if (stage_v_257 > 23) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
