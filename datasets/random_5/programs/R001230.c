/*
 * Benchmark Program: R001230
 * Security Family: mixed_control_data
 * Generator Seed: 623013
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001230_3013_0 {
    unsigned char counter;
    int nonce;
    unsigned char round_key;
    unsigned char tag;
    int buffer[3];
};

struct Transaction_R001230_3013_1 {
    int fee;
    int account_id;
    short balance;
    int buffer[3];
};

struct EventLog_R001230_3013_2 {
    unsigned char timestamp;
    short severity;
    int signature;
    unsigned char code;
    unsigned char seq;
    int facility;
    int buffer[3];
};

struct MatrixBlock_R001230_3013_3 {
    short dim;
    short stride;
    int determinant;
    short trace;
    short scale;
    int density;
    int buffer[3];
};

union PacketPayload_R001230_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001230_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001230_3013_0(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001230_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_46 = 0;
    for (int k = 0; k < 3; k++) {
        segment_46 = (segment_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_46) & 127;
    }
    int weight_96 = (aux + st.buffer[1]) & 3;
    switch (weight_96) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_63 = local_arr[aux % 3];
    acc = (acc + threshold_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001230_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int checksum_66 = local_arr[aux % 3];
    acc = (acc + checksum_66 * 2) & 127;
    int weight_29 = 0;
    for (int k = 0; k < 3; k++) {
        weight_29 = (weight_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_29) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001230_3013_2(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001230_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_20) & 63;
    acc ^= aux;
    int damping_47 = (aux + st.buffer[1]) & 3;
    switch (damping_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_20 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_20 > 18) {
        acc = (acc + damping_20 * 2 + 5) & 127;
        aux ^= (damping_20 & 15);
    } else {
        acc = (acc - damping_20 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_3(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001230_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_93 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_93 > 22) {
        acc = (acc + mask_93 * 2 + 5) & 127;
        aux ^= (mask_93 & 15);
    } else {
        acc = (acc - mask_93 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_50 = local_arr[aux % 3];
    acc = (acc + vector_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_4(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001230_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_12) & 63;
    acc ^= aux;
    int scale_76 = 0;
    for (int k = 0; k < 2; k++) {
        scale_76 = (scale_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001230_3013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001230_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_35 = 0;
    for (int k = 0; k < 2; k++) {
        delta_35 = (delta_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_35) & 127;
    }
    int window_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_6(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001230_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_38 > 42) {
        acc = (acc + quantum_38 * 2 + 5) & 127;
        aux ^= (quantum_38 & 15);
    } else {
        acc = (acc - quantum_38 + 11) & 127;
        aux += 3;
    }
    int sample_74 = (aux + st.buffer[1]) & 3;
    switch (sample_74) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001230_3013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001230_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int residue_77 = (aux + st.buffer[1]) & 3;
    switch (residue_77) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_56) & 63;
    acc ^= aux;
    int index_reg_78 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_78 = (index_reg_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_8(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001230_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_70 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_70 > 36) {
        acc = (acc + metric_70 * 2 + 5) & 127;
        aux ^= (metric_70 & 15);
    } else {
        acc = (acc - metric_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001230_3013_9(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001230_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_32 = (aux + st.buffer[1]) & 3;
    switch (offset_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_10(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001230_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_80) & 63;
    acc ^= aux;
    int delta_62 = (aux + st.buffer[1]) & 3;
    switch (delta_62) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001230_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quotient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_54) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_34 = local_arr[aux % 3];
    acc = (acc + stride_34 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001230_3013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001230_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_41) & 63;
    acc ^= aux;
    int window_44 = (aux + st.buffer[1]) & 3;
    switch (window_44) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_19 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_19 > 44) {
        acc = (acc + quotient_19 * 2 + 5) & 127;
        aux ^= (quotient_19 & 15);
    } else {
        acc = (acc - quotient_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001230_3013_13(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001230_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_39 = (aux + st.buffer[1]) & 3;
    switch (metric_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_43 = (st.buffer[0] * 3 + aux) & 63;
    if (window_43 > 18) {
        acc = (acc + window_43 * 2 + 5) & 127;
        aux ^= (window_43 & 15);
    } else {
        acc = (acc - window_43 + 11) & 127;
        aux += 3;
    }
    int parity_56 = 0;
    for (int k = 0; k < 2; k++) {
        parity_56 = (parity_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_56) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001230_0;
    int sec_r001230_1;
    int sec_r001230_2;
    int sec_r001230_3;
    int sec_r001230_4;
    int sec_r001230_5;
    int sec_r001230_6;
    int sec_r001230_7;
    int sec_r001230_8;
    int sec_r001230_9;
    int sec_r001230_10;
    int sec_r001230_11;
    int sec_r001230_12;
    int sec_r001230_13;
    int sec_r001230_14;
    int sec_r001230_15;
    int sec_r001230_16;
    int sec_r001230_17;
    int sec_r001230_18;
    int pub_r001230_0;
    int pub_r001230_1;
    int pub_r001230_2;
    int pub_r001230_3;
    int pub_r001230_4;
    int pub_r001230_5;
    int pub_r001230_6;
    int pub_r001230_7;
    int pub_r001230_8;
    int pub_r001230_9;
    int pub_r001230_10;
    int pub_r001230_11;
    int pub_r001230_12;
    int pub_r001230_13;
    int pub_r001230_14;
    int pub_r001230_15;
    int pub_r001230_16;
    int pub_r001230_17;
    int pub_r001230_18;
    int pub_r001230_19;
    int pub_r001230_20;
    int pub_r001230_21;
    int pub_r001230_22;
    int pub_r001230_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001230_0 >= -100 && pub_r001230_0 <= 100);
    __CPROVER_assume(pub_r001230_1 >= -100 && pub_r001230_1 <= 100);
    __CPROVER_assume(pub_r001230_2 >= -100 && pub_r001230_2 <= 100);
    __CPROVER_assume(pub_r001230_3 >= -100 && pub_r001230_3 <= 100);
    __CPROVER_assume(pub_r001230_4 >= -100 && pub_r001230_4 <= 100);
    __CPROVER_assume(pub_r001230_5 >= -100 && pub_r001230_5 <= 100);
    __CPROVER_assume(pub_r001230_6 >= -100 && pub_r001230_6 <= 100);
    __CPROVER_assume(pub_r001230_7 >= -100 && pub_r001230_7 <= 100);
    __CPROVER_assume(pub_r001230_8 >= -100 && pub_r001230_8 <= 100);
    __CPROVER_assume(pub_r001230_9 >= -100 && pub_r001230_9 <= 100);
    __CPROVER_assume(pub_r001230_10 >= -100 && pub_r001230_10 <= 100);
    __CPROVER_assume(pub_r001230_11 >= -100 && pub_r001230_11 <= 100);
    __CPROVER_assume(pub_r001230_12 >= -100 && pub_r001230_12 <= 100);
    __CPROVER_assume(pub_r001230_13 >= -100 && pub_r001230_13 <= 100);
    __CPROVER_assume(pub_r001230_14 >= -100 && pub_r001230_14 <= 100);
    __CPROVER_assume(pub_r001230_15 >= -100 && pub_r001230_15 <= 100);
    __CPROVER_assume(pub_r001230_16 >= -100 && pub_r001230_16 <= 100);
    __CPROVER_assume(pub_r001230_17 >= -100 && pub_r001230_17 <= 100);
    __CPROVER_assume(pub_r001230_18 >= -100 && pub_r001230_18 <= 100);
    __CPROVER_assume(pub_r001230_19 >= -100 && pub_r001230_19 <= 100);
    __CPROVER_assume(pub_r001230_20 >= -100 && pub_r001230_20 <= 100);
    __CPROVER_assume(pub_r001230_21 >= -100 && pub_r001230_21 <= 100);
    __CPROVER_assume(pub_r001230_22 >= -100 && pub_r001230_22 <= 100);
    __CPROVER_assume(pub_r001230_23 >= -100 && pub_r001230_23 <= 100);
    __CPROVER_assume(sec_r001230_0 >= 0 && sec_r001230_0 <= 255);
    __CPROVER_assume(sec_r001230_1 >= 0 && sec_r001230_1 <= 255);
    __CPROVER_assume(sec_r001230_2 >= 0 && sec_r001230_2 <= 255);
    __CPROVER_assume(sec_r001230_3 >= 0 && sec_r001230_3 <= 255);
    __CPROVER_assume(sec_r001230_4 >= 0 && sec_r001230_4 <= 255);
    __CPROVER_assume(sec_r001230_5 >= 0 && sec_r001230_5 <= 255);
    __CPROVER_assume(sec_r001230_6 >= 0 && sec_r001230_6 <= 255);
    __CPROVER_assume(sec_r001230_7 >= 0 && sec_r001230_7 <= 255);
    __CPROVER_assume(sec_r001230_8 >= 0 && sec_r001230_8 <= 255);
    __CPROVER_assume(sec_r001230_9 >= 0 && sec_r001230_9 <= 255);
    __CPROVER_assume(sec_r001230_10 >= 0 && sec_r001230_10 <= 255);
    __CPROVER_assume(sec_r001230_11 >= 0 && sec_r001230_11 <= 255);
    __CPROVER_assume(sec_r001230_12 >= 0 && sec_r001230_12 <= 255);
    __CPROVER_assume(sec_r001230_13 >= 0 && sec_r001230_13 <= 255);
    __CPROVER_assume(sec_r001230_14 >= 0 && sec_r001230_14 <= 255);
    __CPROVER_assume(sec_r001230_15 >= 0 && sec_r001230_15 <= 255);
    __CPROVER_assume(sec_r001230_16 >= 0 && sec_r001230_16 <= 255);
    __CPROVER_assume(sec_r001230_17 >= 0 && sec_r001230_17 <= 255);
    __CPROVER_assume(sec_r001230_18 >= 0 && sec_r001230_18 <= 255);

    struct CipherContext_R001230_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001230_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001230_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001230_0 + 7) & 15;
    struct Transaction_R001230_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001230_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001230_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001230_0 + 9) & 15;
    struct EventLog_R001230_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001230_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001230_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001230_0 + 11) & 15;
    struct MatrixBlock_R001230_3013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001230_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001230_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001230_0 + 13) & 15;

    union PacketPayload_R001230_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001230_3013_0(sec_r001230_0, pub_r001230_1);
    int helper_flow_1 = fn_R001230_3013_1(sec_r001230_1, pub_r001230_2, pub_r001230_3, pub_r001230_4, pub_r001230_5);
    int helper_flow_2 = fn_R001230_3013_2(sec_r001230_2, sec_r001230_3);
    int helper_flow_3 = fn_R001230_3013_3(sec_r001230_3, sec_r001230_4);
    int helper_flow_4 = fn_R001230_3013_4(sec_r001230_4, sec_r001230_5);
    int helper_flow_5 = fn_R001230_3013_5(sec_r001230_5, pub_r001230_6, pub_r001230_7, pub_r001230_8, pub_r001230_9);
    int helper_flow_6 = fn_R001230_3013_6(sec_r001230_6, sec_r001230_7);
    int helper_flow_7 = fn_R001230_3013_7(sec_r001230_7, sec_r001230_8, pub_r001230_9, pub_r001230_10);
    int helper_flow_8 = fn_R001230_3013_8(sec_r001230_8, sec_r001230_9);
    int helper_flow_9 = fn_R001230_3013_9(sec_r001230_9, sec_r001230_10, pub_r001230_11);
    int helper_flow_10 = fn_R001230_3013_10(sec_r001230_10, pub_r001230_11);
    int helper_flow_11 = fn_R001230_3013_11(sec_r001230_11, sec_r001230_12, pub_r001230_13, pub_r001230_14, pub_r001230_15);
    int helper_flow_12 = fn_R001230_3013_12(sec_r001230_12, sec_r001230_13, pub_r001230_14, pub_r001230_15);
    int helper_flow_13 = fn_R001230_3013_13(sec_r001230_13, pub_r001230_14, pub_r001230_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001230_6 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_0 > 22) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001230_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001230_10 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_2 > 34) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_3 > 28) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_4 > 27) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001230_7 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001230_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_8 > 44) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_9 > 50) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_10 > 33) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001230_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_12 > 20) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_13 > 22) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001230_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_15 > 50) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_16 > 49) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_17 > 38) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_18 > 21) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001230_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_20 > 48) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_21 > 27) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001230_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_23 > 25) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_24 > 48) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_25 > 20) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001230_2 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_26 > 27) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001230_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001230_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001230_16 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_29 > 34) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001230_18 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_30 > 43) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001230_10 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_31 > 25) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001230_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001230_19) & 127;
    if (stage_v_33 > 29) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001230_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001230_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_37 > 50) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_38 > 30) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001230_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_40 > 20) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_41 > 23) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_42 > 20) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001230_15 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_43 > 36) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_44 > 22) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_45 > 22) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001230_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_48 > 24) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_49 > 32) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001230_3 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_50 > 36) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001230_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001230_3 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_52 > 37) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_53 > 35) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001230_10 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_54 > 33) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_55 > 42) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_56 > 39) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001230_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_59 > 27) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001230_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_61 > 32) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_62 > 20) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001230_6 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_63 > 49) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001230_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_65 > 26) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_66 > 27) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_67 > 22) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_68 > 50) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001230_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001230_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_71 > 27) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001230_14 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_72 > 35) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_73 > 50) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001230_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_75 > 23) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_76 > 23) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001230_17 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_77 > 29) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001230_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_79 > 36) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001230_3 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_80 > 46) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_81 > 24) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_82 > 38) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_83 > 41) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_84 > 50) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001230_2 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_85 > 29) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_87 > 50) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001230_8 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_88 > 37) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001230_8 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_89 > 43) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_90 > 37) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_91 > 46) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_92 > 30) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_93 > 38) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_94 > 39) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001230_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_96 > 32) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001230_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001230_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001230_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_100 > 43) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001230_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001230_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_103 > 29) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001230_10 ^ 0x2A) * 2 + pub_r001230_19) & 127;
    if (stage_v_104 > 38) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_105 > 49) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001230_6 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_107 > 47) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001230_13 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_108 > 39) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_109 > 42) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001230_15 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_110 > 45) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_111 > 44) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001230_13 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_112 > 35) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_113 > 33) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_114 > 47) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_115 > 42) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_116 > 46) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001230_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001230_14 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_118 > 32) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001230_22 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_120 > 27) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001230_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_122 > 30) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_123 > 35) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_124 > 31) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001230_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_126 > 31) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001230_3 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_127 > 48) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001230_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_129 > 21) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001230_17 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_130 > 40) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001230_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001230_8 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_132 > 40) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_133 > 50) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_134 > 36) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_135 > 28) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_136 > 47) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_137 > 33) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001230_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_139 > 23) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001230_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_141 > 47) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_142 > 30) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_143 > 35) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001230_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001230_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_146 > 31) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001230_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_149 > 21) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_150 > 45) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_151 > 42) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_152 > 25) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_153 > 38) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_154 > 39) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_155 > 28) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001230_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_157 > 24) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_158 > 41) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001230_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001230_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001230_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_162 > 26) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_163 > 28) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_164 > 47) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001230_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_166 > 47) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_167 > 37) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001230_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001230_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_170 > 28) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001230_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_172 > 40) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_173 > 22) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_174 > 36) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_175 > 20) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001230_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_177 > 42) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_178 > 46) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001230_20 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_180 > 50) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001230_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_182 > 49) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_183 > 20) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001230_10) & 127;
    if (stage_v_184 > 47) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001230_18 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_185 > 25) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_186 > 24) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_187 > 31) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_188 > 50) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_189 > 24) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_190 > 49) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001230_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_192 > 33) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_193 > 39) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001230_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_195 > 46) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001230_2 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_196 > 39) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_197 > 39) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_198 > 43) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001230_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_200 > 30) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_201 > 38) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001230_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001230_10 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_204 > 32) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_197 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_205 > 28) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_206 > 38) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001230_16 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_207 > 43) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001230_23 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001230_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001230_15 ^ 0x2A) * 2 + pub_r001230_5) & 127;
    if (stage_v_210 > 22) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_211 > 45) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_212 > 30) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_213 > 25) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001230_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001230_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001230_16) & 127;
    if (stage_v_216 > 41) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001230_4 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_217 > 22) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001230_19) & 127;
    if (stage_v_218 > 39) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_219 > 43) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_220 > 27) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_221 > 33) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_195 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_222 > 47) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001230_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001230_23) & 127;
    if (stage_v_224 > 31) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_225 > 27) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001230_8 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_226 > 35) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_220 ^ 0x2A) * 2 + pub_r001230_6) & 127;
    if (stage_v_227 > 26) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001230_14) & 127;
    if (stage_v_228 > 26) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001230_18 ^ 0x2A) * 2 + pub_r001230_9) & 127;
    if (stage_v_229 > 23) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_230 > 34) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001230_12) & 127;
    if (stage_v_231 > 37) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_206 ^ 0x2A) * 2 + pub_r001230_15) & 127;
    if (stage_v_232 > 37) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001230_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_234 > 47) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001230_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001230_7) & 127;
    if (stage_v_236 > 26) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001230_4) & 127;
    if (stage_v_237 > 41) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_238 > 37) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_218 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_239 > 50) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_240 > 20) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001230_19) & 127;
    if (stage_v_241 > 48) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_205 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_242 > 50) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001230_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_244 > 49) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_236 ^ 0x2A) * 2 + pub_r001230_21) & 127;
    if (stage_v_245 > 50) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001230_3) & 127;
    if (stage_v_246 > 47) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001230_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001230_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_249 > 25) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_250 > 22) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001230_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001230_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_253 > 33) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001230_0) & 127;
    if (stage_v_254 > 47) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001230_1) & 127;
    if (stage_v_255 > 40) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001230_17) & 127;
    if (stage_v_256 > 39) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001230_20) & 127;
    if (stage_v_257 > 29) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_256 ^ 0x2A) * 2 + pub_r001230_22) & 127;
    if (stage_v_258 > 45) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_259 > 41) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001230_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001230_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_255 ^ 0x2A) * 2 + pub_r001230_19) & 127;
    if (stage_v_262 > 20) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001230_13) & 127;
    if (stage_v_263 > 37) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_264 > 34) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001230_23 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001230_18) & 127;
    if (stage_v_266 > 47) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001230_8) & 127;
    if (stage_v_267 > 40) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001230_11) & 127;
    if (stage_v_268 > 27) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_250 ^ 0x2A) * 2 + pub_r001230_2) & 127;
    if (stage_v_269 > 44) {
        out_sink = (out_sink + stage_v_269 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_269 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_269) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
