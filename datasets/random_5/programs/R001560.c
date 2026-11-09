/*
 * Benchmark Program: R001560
 * Security Family: mixed_control_data
 * Generator Seed: 656013
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001560_6013_0 {
    int auth_code;
    int account_id;
    unsigned char status;
    unsigned char balance;
    short rate;
    short fee;
    int buffer[3];
};

struct MatrixBlock_R001560_6013_1 {
    short scale;
    short trace;
    int determinant;
    short density;
    int dim;
    int buffer[3];
};

struct CipherContext_R001560_6013_2 {
    unsigned char tag;
    int nonce;
    int round_key;
    int buffer[3];
};

union PacketPayload_R001560_6013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001560_6013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001560_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_11 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_11 = (pivot_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_11) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_28 = (aux + st.buffer[1]) & 3;
    switch (residue_28) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_1(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_90 = (aux + st.buffer[1]) & 3;
    switch (segment_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_45 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_45 = (anchor_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quotient_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_44 = local_arr[aux % 3];
    acc = (acc + window_44 * 2) & 127;
    int checksum_96 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_96 > 15) {
        acc = (acc + checksum_96 * 2 + 5) & 127;
        aux ^= (checksum_96 & 15);
    } else {
        acc = (acc - checksum_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int mask_55 = local_arr[aux % 3];
    acc = (acc + mask_55 * 2) & 127;
    int parity_21 = (aux + st.buffer[1]) & 3;
    switch (parity_21) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_19 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_19 > 35) {
        acc = (acc + vector_19 * 2 + 5) & 127;
        aux ^= (vector_19 & 15);
    } else {
        acc = (acc - vector_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001560_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_35) & 63;
    acc ^= aux;
    int mask_65 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_65 > 22) {
        acc = (acc + mask_65 * 2 + 5) & 127;
        aux ^= (mask_65 & 15);
    } else {
        acc = (acc - mask_65 + 11) & 127;
        aux += 3;
    }
    int parity_75 = (aux + st.buffer[1]) & 3;
    switch (parity_75) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_56 = local_arr[aux % 3];
    acc = (acc + pivot_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001560_6013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001560_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_86 = (aux + st.buffer[1]) & 3;
    switch (index_reg_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_20 = 0;
    for (int k = 0; k < 3; k++) {
        stride_20 = (stride_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_20) & 127;
    }
    int delta_10 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_10 > 46) {
        acc = (acc + delta_10 * 2 + 5) & 127;
        aux ^= (delta_10 & 15);
    } else {
        acc = (acc - delta_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_88 = local_arr[aux % 3];
    acc = (acc + cursor_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001560_6013_6(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_38 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_38 > 19) {
        acc = (acc + delta_38 * 2 + 5) & 127;
        aux ^= (delta_38 & 15);
    } else {
        acc = (acc - delta_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_15 = local_arr[aux % 3];
    acc = (acc + bound_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001560_6013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_38 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_38 > 17) {
        acc = (acc + threshold_38 * 2 + 5) & 127;
        aux ^= (threshold_38 & 15);
    } else {
        acc = (acc - threshold_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_73 = local_arr[aux % 3];
    acc = (acc + damping_73 * 2) & 127;
    int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001560_6013_8(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int sample_28 = 0;
    for (int k = 0; k < 2; k++) {
        sample_28 = (sample_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_28) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_80 = local_arr[aux % 3];
    acc = (acc + segment_80 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_92 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_92 > 43) {
        acc = (acc + parity_92 * 2 + 5) & 127;
        aux ^= (parity_92 & 15);
    } else {
        acc = (acc - parity_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_9(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int index_reg_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_94) & 63;
    acc ^= aux;
    int coefficient_71 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_71 = (coefficient_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_10(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001560_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int metric_36 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_36 > 33) {
        acc = (acc + metric_36 * 2 + 5) & 127;
        aux ^= (metric_36 & 15);
    } else {
        acc = (acc - metric_36 + 11) & 127;
        aux += 3;
    }
    int metric_42 = 0;
    for (int k = 0; k < 2; k++) {
        metric_42 = (metric_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_42) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001560_6013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001560_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_16 = (aux + st.buffer[1]) & 3;
    switch (tracker_16) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_29 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_29 > 13) {
        acc = (acc + segment_29 * 2 + 5) & 127;
        aux ^= (segment_29 & 15);
    } else {
        acc = (acc - segment_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_88 = (aux + st.buffer[1]) & 3;
    switch (weight_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_15 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_15 > 25) {
        acc = (acc + stride_15 * 2 + 5) & 127;
        aux ^= (stride_15 & 15);
    } else {
        acc = (acc - stride_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_18 = 0;
    for (int k = 0; k < 2; k++) {
        weight_18 = (weight_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_14(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001560_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_27 = 0;
    for (int k = 0; k < 3; k++) {
        window_27 = (window_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_27) & 127;
    }
    int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_57 = local_arr[aux % 3];
    acc = (acc + parity_57 * 2) & 127;
    int cursor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_97 > 13) {
        acc = (acc + cursor_97 * 2 + 5) & 127;
        aux ^= (cursor_97 & 15);
    } else {
        acc = (acc - cursor_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_15(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001560_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_27 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_27 > 32) {
        acc = (acc + cursor_27 * 2 + 5) & 127;
        aux ^= (cursor_27 & 15);
    } else {
        acc = (acc - cursor_27 + 11) & 127;
        aux += 3;
    }
    int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_34) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001560_6013_16(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001560_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_48 = (aux + st.buffer[1]) & 3;
    switch (residue_48) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_32) & 63;
    acc ^= aux;
    int weight_39 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_39 > 13) {
        acc = (acc + weight_39 * 2 + 5) & 127;
        aux ^= (weight_39 & 15);
    } else {
        acc = (acc - weight_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001560_6013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001560_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001560_0;
    int sec_r001560_1;
    int sec_r001560_2;
    int sec_r001560_3;
    int sec_r001560_4;
    int sec_r001560_5;
    int sec_r001560_6;
    int sec_r001560_7;
    int sec_r001560_8;
    int sec_r001560_9;
    int sec_r001560_10;
    int sec_r001560_11;
    int sec_r001560_12;
    int sec_r001560_13;
    int sec_r001560_14;
    int sec_r001560_15;
    int sec_r001560_16;
    int sec_r001560_17;
    int sec_r001560_18;
    int sec_r001560_19;
    int sec_r001560_20;
    int sec_r001560_21;
    int sec_r001560_22;
    int sec_r001560_23;
    int pub_r001560_0;
    int pub_r001560_1;
    int pub_r001560_2;
    int pub_r001560_3;
    int pub_r001560_4;
    int pub_r001560_5;
    int pub_r001560_6;
    int pub_r001560_7;
    int pub_r001560_8;
    int pub_r001560_9;
    int pub_r001560_10;
    int pub_r001560_11;
    int pub_r001560_12;
    int pub_r001560_13;
    int pub_r001560_14;
    int pub_r001560_15;
    int pub_r001560_16;
    int pub_r001560_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001560_0 >= -100 && pub_r001560_0 <= 100);
    __CPROVER_assume(pub_r001560_1 >= -100 && pub_r001560_1 <= 100);
    __CPROVER_assume(pub_r001560_2 >= -100 && pub_r001560_2 <= 100);
    __CPROVER_assume(pub_r001560_3 >= -100 && pub_r001560_3 <= 100);
    __CPROVER_assume(pub_r001560_4 >= -100 && pub_r001560_4 <= 100);
    __CPROVER_assume(pub_r001560_5 >= -100 && pub_r001560_5 <= 100);
    __CPROVER_assume(pub_r001560_6 >= -100 && pub_r001560_6 <= 100);
    __CPROVER_assume(pub_r001560_7 >= -100 && pub_r001560_7 <= 100);
    __CPROVER_assume(pub_r001560_8 >= -100 && pub_r001560_8 <= 100);
    __CPROVER_assume(pub_r001560_9 >= -100 && pub_r001560_9 <= 100);
    __CPROVER_assume(pub_r001560_10 >= -100 && pub_r001560_10 <= 100);
    __CPROVER_assume(pub_r001560_11 >= -100 && pub_r001560_11 <= 100);
    __CPROVER_assume(pub_r001560_12 >= -100 && pub_r001560_12 <= 100);
    __CPROVER_assume(pub_r001560_13 >= -100 && pub_r001560_13 <= 100);
    __CPROVER_assume(pub_r001560_14 >= -100 && pub_r001560_14 <= 100);
    __CPROVER_assume(pub_r001560_15 >= -100 && pub_r001560_15 <= 100);
    __CPROVER_assume(pub_r001560_16 >= -100 && pub_r001560_16 <= 100);
    __CPROVER_assume(pub_r001560_17 >= -100 && pub_r001560_17 <= 100);
    __CPROVER_assume(sec_r001560_0 >= 0 && sec_r001560_0 <= 255);
    __CPROVER_assume(sec_r001560_1 >= 0 && sec_r001560_1 <= 255);
    __CPROVER_assume(sec_r001560_2 >= 0 && sec_r001560_2 <= 255);
    __CPROVER_assume(sec_r001560_3 >= 0 && sec_r001560_3 <= 255);
    __CPROVER_assume(sec_r001560_4 >= 0 && sec_r001560_4 <= 255);
    __CPROVER_assume(sec_r001560_5 >= 0 && sec_r001560_5 <= 255);
    __CPROVER_assume(sec_r001560_6 >= 0 && sec_r001560_6 <= 255);
    __CPROVER_assume(sec_r001560_7 >= 0 && sec_r001560_7 <= 255);
    __CPROVER_assume(sec_r001560_8 >= 0 && sec_r001560_8 <= 255);
    __CPROVER_assume(sec_r001560_9 >= 0 && sec_r001560_9 <= 255);
    __CPROVER_assume(sec_r001560_10 >= 0 && sec_r001560_10 <= 255);
    __CPROVER_assume(sec_r001560_11 >= 0 && sec_r001560_11 <= 255);
    __CPROVER_assume(sec_r001560_12 >= 0 && sec_r001560_12 <= 255);
    __CPROVER_assume(sec_r001560_13 >= 0 && sec_r001560_13 <= 255);
    __CPROVER_assume(sec_r001560_14 >= 0 && sec_r001560_14 <= 255);
    __CPROVER_assume(sec_r001560_15 >= 0 && sec_r001560_15 <= 255);
    __CPROVER_assume(sec_r001560_16 >= 0 && sec_r001560_16 <= 255);
    __CPROVER_assume(sec_r001560_17 >= 0 && sec_r001560_17 <= 255);
    __CPROVER_assume(sec_r001560_18 >= 0 && sec_r001560_18 <= 255);
    __CPROVER_assume(sec_r001560_19 >= 0 && sec_r001560_19 <= 255);
    __CPROVER_assume(sec_r001560_20 >= 0 && sec_r001560_20 <= 255);
    __CPROVER_assume(sec_r001560_21 >= 0 && sec_r001560_21 <= 255);
    __CPROVER_assume(sec_r001560_22 >= 0 && sec_r001560_22 <= 255);
    __CPROVER_assume(sec_r001560_23 >= 0 && sec_r001560_23 <= 255);

    struct Transaction_R001560_6013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001560_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001560_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001560_0 + 7) & 15;
    struct MatrixBlock_R001560_6013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001560_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001560_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001560_0 + 9) & 15;
    struct CipherContext_R001560_6013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001560_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001560_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001560_0 + 11) & 15;

    union PacketPayload_R001560_6013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001560_6013_0(sec_r001560_0, sec_r001560_1, pub_r001560_2, pub_r001560_3, pub_r001560_4);
    int helper_flow_1 = fn_R001560_6013_1(sec_r001560_1, sec_r001560_2, pub_r001560_3);
    int helper_flow_2 = fn_R001560_6013_2(sec_r001560_2, pub_r001560_3, pub_r001560_4, pub_r001560_5, pub_r001560_6);
    int helper_flow_3 = fn_R001560_6013_3(sec_r001560_3, sec_r001560_4, pub_r001560_5, pub_r001560_6);
    int helper_flow_4 = fn_R001560_6013_4(sec_r001560_4, sec_r001560_5, pub_r001560_6, pub_r001560_7);
    int helper_flow_5 = fn_R001560_6013_5(sec_r001560_5, sec_r001560_6, pub_r001560_7, pub_r001560_8, pub_r001560_9);
    int helper_flow_6 = fn_R001560_6013_6(sec_r001560_6, pub_r001560_7);
    int helper_flow_7 = fn_R001560_6013_7(sec_r001560_7, sec_r001560_8, pub_r001560_9, pub_r001560_10, pub_r001560_11);
    int helper_flow_8 = fn_R001560_6013_8(sec_r001560_8, sec_r001560_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001560_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001560_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_2 > 41) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_3 > 24) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001560_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001560_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001560_5 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_6 > 30) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001560_8 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_8 > 45) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_9 > 26) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001560_5 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_10 > 50) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001560_15) & 127;
    if (stage_v_11 > 20) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_12 > 44) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001560_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001560_23 ^ 0x2A) * 2 + pub_r001560_15) & 127;
    if (stage_v_14 > 42) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001560_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_16 > 23) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001560_5 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_17 > 47) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001560_4 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_18 > 27) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001560_22 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_19 > 22) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001560_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001560_13 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_21 > 44) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001560_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001560_18 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_23 > 48) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_24 > 34) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_25 > 49) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001560_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_27 > 22) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_28 > 32) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001560_9 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_29 > 39) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_30 > 37) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_31 > 39) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001560_14 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_32 > 30) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001560_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_34 > 41) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_35 > 43) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_36 > 23) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_37 > 25) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001560_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001560_4 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_39 > 42) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001560_10 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_40 > 50) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_41 > 29) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_42 > 28) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_43 > 37) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001560_15) & 127;
    if (stage_v_45 > 21) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_46 > 47) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_47 > 36) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001560_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_49 > 48) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001560_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001560_4 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_51 > 40) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001560_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001560_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001560_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_55 > 22) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_56 > 33) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001560_12 ^ 0x2A) * 2 + pub_r001560_15) & 127;
    if (stage_v_57 > 48) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001560_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001560_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_60 > 25) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_61 > 37) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001560_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_63 > 41) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001560_20 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_64 > 22) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_65 > 46) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001560_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_67 > 37) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001560_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001560_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_70 > 44) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_71 > 35) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001560_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_73 > 48) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_74 > 33) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_75 > 21) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001560_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_77 > 42) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_78 > 32) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001560_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_80 > 43) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001560_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001560_13 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_82 > 22) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001560_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_84 > 27) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001560_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001560_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_87 > 43) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001560_19 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_88 > 30) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001560_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_90 > 37) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001560_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_92 > 38) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_93 > 23) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001560_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001560_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001560_1 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_96 > 32) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_97 > 47) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001560_10 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_98 > 45) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_99 > 49) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001560_15) & 127;
    if (stage_v_100 > 20) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001560_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_102 > 31) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_103 > 46) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_104 > 23) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_105 > 35) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001560_15 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_106 > 30) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_107 > 40) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_108 > 23) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001560_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_110 > 24) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_111 > 44) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_112 > 34) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_113 > 34) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_114 > 41) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_116 > 26) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001560_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_118 > 40) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001560_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001560_3 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_120 > 26) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_121 > 28) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001560_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_123 > 50) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001560_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_125 > 41) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_126 > 42) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001560_3 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_127 > 21) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001560_15 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_128 > 24) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_129 > 26) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_130 > 22) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_131 > 32) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001560_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_133 > 28) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_135 > 24) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001560_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_137 > 27) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_138 > 41) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001560_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_140 > 27) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_141 > 49) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_142 > 32) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_143 > 26) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_144 > 38) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_145 > 48) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001560_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001560_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001560_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_149 > 45) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_150 > 42) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_151 > 37) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001560_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_153 > 22) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001560_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_155 > 38) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001560_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_157 > 20) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_158 > 25) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001560_13 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_159 > 27) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_160 > 22) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_161 > 21) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_162 > 44) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_163 > 47) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_164 > 48) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001560_2) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001560_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_167 > 44) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001560_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_169 > 45) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001560_15 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_170 > 28) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001560_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_172 > 20) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_173 > 37) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_174 > 20) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001560_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001560_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001560_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_178 > 33) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001560_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_180 > 48) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_181 > 24) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_182 > 28) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_183 > 35) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_184 > 40) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001560_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_186 > 40) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_188 > 20) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001560_21 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_189 > 39) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r001560_11 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_190 > 37) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_191 > 37) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_192 > 43) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_193 > 40) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_194 > 25) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001560_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_196 > 35) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_197 > 33) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_198 > 28) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_200 > 32) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_201 > 49) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001560_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001560_11 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_203 > 42) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_204 > 46) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_205 > 30) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_206 > 20) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_207 > 37) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001560_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_209 > 25) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_210 > 43) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001560_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_212 > 23) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_213 > 27) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_214 > 22) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001560_10) & 127;
    if (stage_v_215 > 24) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001560_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001560_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001560_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001560_14) & 127;
    if (stage_v_219 > 44) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001560_12) & 127;
    if (stage_v_220 > 23) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_221 > 49) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_222 > 41) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001560_17 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_223 > 40) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_224 > 29) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_225 > 46) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_226 > 47) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001560_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_229 > 28) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_230 > 48) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001560_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001560_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_233 > 42) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_189 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_234 > 34) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_235 > 38) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_236 > 29) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_237 > 31) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_238 > 43) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001560_5) & 127;
    if (stage_v_239 > 33) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001560_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001560_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001560_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001560_3) & 127;
    if (stage_v_243 > 46) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001560_10 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_244 > 20) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001560_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001560_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_247 > 38) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001560_17) & 127;
    if (stage_v_248 > 50) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001560_13) & 127;
    if (stage_v_249 > 43) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_234 ^ 0x2A) * 2 + pub_r001560_7) & 127;
    if (stage_v_250 > 42) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001560_4) & 127;
    if (stage_v_251 > 24) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001560_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001560_0) & 127;
    if (stage_v_253 > 28) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001560_8) & 127;
    if (stage_v_254 > 21) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001560_9) & 127;
    if (stage_v_255 > 42) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001560_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001560_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001560_16) & 127;
    if (stage_v_258 > 40) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001560_1) & 127;
    if (stage_v_259 > 20) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001560_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001560_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001560_11) & 127;
    if (stage_v_262 > 40) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001560_6) & 127;
    if (stage_v_263 > 48) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
