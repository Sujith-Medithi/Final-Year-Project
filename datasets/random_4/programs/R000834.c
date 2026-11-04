/*
 * Benchmark Program: R000834
 * Family: secret_dependent_array
 * Generator Seed: 484413
 * High Inputs: 22 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000834_4413_0 {
    unsigned char tag;
    int flags;
    short counter;
    int buffer[3];
};

struct DeviceConfig_R000834_4413_1 {
    unsigned char port;
    short id;
    int stop_bits;
    int buffer[3];
};

struct StreamBuffer_R000834_4413_2 {
    int state;
    short head;
    short watermark;
    int tail;
    short capacity;
    int buffer[3];
};

union RegisterBank_R000834_4413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000834_4413_0(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_77 = (aux + st.buffer[1]) & 3;
    switch (segment_77) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_1(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_67 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_67 = (checksum_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_67) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_54 = local_arr[aux % 3];
    acc = (acc + bound_54 * 2) & 127;
    int factor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_35 > 37) {
        acc = (acc + factor_35 * 2 + 5) & 127;
        aux ^= (factor_35 & 15);
    } else {
        acc = (acc - factor_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int anchor_37 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_37 = (anchor_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_37) & 127;
    }
    int bound_95 = (aux + st.buffer[1]) & 3;
    switch (bound_95) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_3(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int cursor_10 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_10 = (cursor_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_10) & 127;
    }
    int sample_44 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_44 > 37) {
        acc = (acc + sample_44 * 2 + 5) & 127;
        aux ^= (sample_44 & 15);
    } else {
        acc = (acc - sample_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_81 = 0;
    for (int k = 0; k < 3; k++) {
        margin_81 = (margin_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_81) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_71 = local_arr[aux % 3];
    acc = (acc + bound_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int weight_48 = 0;
    for (int k = 0; k < 3; k++) {
        weight_48 = (weight_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_48) & 127;
    }
    int margin_17 = (aux + st.buffer[1]) & 3;
    switch (margin_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_95 = local_arr[aux % 3];
    acc = (acc + index_reg_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000834_4413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int delta_94 = 0;
    for (int k = 0; k < 3; k++) {
        delta_94 = (delta_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_94) & 127;
    }
    int quotient_36 = (aux + st.buffer[1]) & 3;
    switch (quotient_36) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_60 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_60 > 49) {
        acc = (acc + metric_60 * 2 + 5) & 127;
        aux ^= (metric_60 & 15);
    } else {
        acc = (acc - metric_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_7(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int segment_24 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_24 > 34) {
        acc = (acc + segment_24 * 2 + 5) & 127;
        aux ^= (segment_24 & 15);
    } else {
        acc = (acc - segment_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_38 = local_arr[aux % 3];
    acc = (acc + cursor_38 * 2) & 127;
    int checksum_58 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_58 = (checksum_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_8(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int parity_47 = local_arr[aux % 3];
    acc = (acc + parity_47 * 2) & 127;
    int accumulator_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_67) & 63;
    acc ^= aux;
    int residue_84 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_84 > 14) {
        acc = (acc + residue_84 * 2 + 5) & 127;
        aux ^= (residue_84 & 15);
    } else {
        acc = (acc - residue_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_9(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000834_4413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_43 = 0;
    for (int k = 0; k < 3; k++) {
        stride_43 = (stride_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_43) & 127;
    }
    int index_reg_12 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_12 > 16) {
        acc = (acc + index_reg_12 * 2 + 5) & 127;
        aux ^= (index_reg_12 & 15);
    } else {
        acc = (acc - index_reg_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int weight_37 = local_arr[aux % 3];
    acc = (acc + weight_37 * 2) & 127;
    int bound_61 = (aux + st.buffer[1]) & 3;
    switch (bound_61) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_11(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_37 = local_arr[aux % 3];
    acc = (acc + weight_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_12(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000834_4413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_16) & 63;
    acc ^= aux;
    int damping_38 = 0;
    for (int k = 0; k < 2; k++) {
        damping_38 = (damping_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_38) & 127;
    }
    int quotient_98 = (aux + st.buffer[1]) & 3;
    switch (quotient_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_16 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_16 > 26) {
        acc = (acc + vector_16 * 2 + 5) & 127;
        aux ^= (vector_16 & 15);
    } else {
        acc = (acc - vector_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000834_4413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_55 = (aux + st.buffer[1]) & 3;
    switch (anchor_55) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_82 = local_arr[aux % 3];
    acc = (acc + scale_82 * 2) & 127;
    int sample_40 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_40 > 41) {
        acc = (acc + sample_40 * 2 + 5) & 127;
        aux ^= (sample_40 & 15);
    } else {
        acc = (acc - sample_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000834_4413_14(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_35 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_35 = (anchor_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_35) & 127;
    }
    int stride_59 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_59 > 34) {
        acc = (acc + stride_59 * 2 + 5) & 127;
        aux ^= (stride_59 & 15);
    } else {
        acc = (acc - stride_59 + 11) & 127;
        aux += 3;
    }
    int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000834_4413_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000834_4413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int offset_82 = (aux + st.buffer[1]) & 3;
    switch (offset_82) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_88 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_88 = (accumulator_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_88) & 127;
    }
    int cursor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000834_4413_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000834_4413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000834_4413_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000834_4413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int metric_67 = local_arr[aux % 3];
    acc = (acc + metric_67 * 2) & 127;
    int weight_29 = (aux + st.buffer[1]) & 3;
    switch (weight_29) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_25 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_25 = (checksum_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_25) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000834_0;
    int sec_r000834_1;
    int sec_r000834_2;
    int sec_r000834_3;
    int sec_r000834_4;
    int sec_r000834_5;
    int sec_r000834_6;
    int sec_r000834_7;
    int sec_r000834_8;
    int sec_r000834_9;
    int sec_r000834_10;
    int sec_r000834_11;
    int sec_r000834_12;
    int sec_r000834_13;
    int sec_r000834_14;
    int sec_r000834_15;
    int sec_r000834_16;
    int sec_r000834_17;
    int sec_r000834_18;
    int sec_r000834_19;
    int sec_r000834_20;
    int sec_r000834_21;
    int pub_r000834_0;
    int pub_r000834_1;
    int pub_r000834_2;
    int pub_r000834_3;
    int pub_r000834_4;
    int pub_r000834_5;
    int pub_r000834_6;
    int pub_r000834_7;
    int pub_r000834_8;
    int pub_r000834_9;
    int pub_r000834_10;
    int pub_r000834_11;
    int pub_r000834_12;
    int pub_r000834_13;
    int pub_r000834_14;
    int pub_r000834_15;
    int pub_r000834_16;
    int pub_r000834_17;
    int pub_r000834_18;
    int pub_r000834_19;
    int pub_r000834_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000834_0 >= -100 && pub_r000834_0 <= 100);
    __CPROVER_assume(pub_r000834_1 >= -100 && pub_r000834_1 <= 100);
    __CPROVER_assume(pub_r000834_2 >= -100 && pub_r000834_2 <= 100);
    __CPROVER_assume(pub_r000834_3 >= -100 && pub_r000834_3 <= 100);
    __CPROVER_assume(pub_r000834_4 >= -100 && pub_r000834_4 <= 100);
    __CPROVER_assume(pub_r000834_5 >= -100 && pub_r000834_5 <= 100);
    __CPROVER_assume(pub_r000834_6 >= -100 && pub_r000834_6 <= 100);
    __CPROVER_assume(pub_r000834_7 >= -100 && pub_r000834_7 <= 100);
    __CPROVER_assume(pub_r000834_8 >= -100 && pub_r000834_8 <= 100);
    __CPROVER_assume(pub_r000834_9 >= -100 && pub_r000834_9 <= 100);
    __CPROVER_assume(pub_r000834_10 >= -100 && pub_r000834_10 <= 100);
    __CPROVER_assume(pub_r000834_11 >= -100 && pub_r000834_11 <= 100);
    __CPROVER_assume(pub_r000834_12 >= -100 && pub_r000834_12 <= 100);
    __CPROVER_assume(pub_r000834_13 >= -100 && pub_r000834_13 <= 100);
    __CPROVER_assume(pub_r000834_14 >= -100 && pub_r000834_14 <= 100);
    __CPROVER_assume(pub_r000834_15 >= -100 && pub_r000834_15 <= 100);
    __CPROVER_assume(pub_r000834_16 >= -100 && pub_r000834_16 <= 100);
    __CPROVER_assume(pub_r000834_17 >= -100 && pub_r000834_17 <= 100);
    __CPROVER_assume(pub_r000834_18 >= -100 && pub_r000834_18 <= 100);
    __CPROVER_assume(pub_r000834_19 >= -100 && pub_r000834_19 <= 100);
    __CPROVER_assume(pub_r000834_20 >= -100 && pub_r000834_20 <= 100);
    __CPROVER_assume(sec_r000834_0 >= 0 && sec_r000834_0 <= 255);
    __CPROVER_assume(sec_r000834_1 >= 0 && sec_r000834_1 <= 255);
    __CPROVER_assume(sec_r000834_2 >= 0 && sec_r000834_2 <= 255);
    __CPROVER_assume(sec_r000834_3 >= 0 && sec_r000834_3 <= 255);
    __CPROVER_assume(sec_r000834_4 >= 0 && sec_r000834_4 <= 255);
    __CPROVER_assume(sec_r000834_5 >= 0 && sec_r000834_5 <= 255);
    __CPROVER_assume(sec_r000834_6 >= 0 && sec_r000834_6 <= 255);
    __CPROVER_assume(sec_r000834_7 >= 0 && sec_r000834_7 <= 255);
    __CPROVER_assume(sec_r000834_8 >= 0 && sec_r000834_8 <= 255);
    __CPROVER_assume(sec_r000834_9 >= 0 && sec_r000834_9 <= 255);
    __CPROVER_assume(sec_r000834_10 >= 0 && sec_r000834_10 <= 255);
    __CPROVER_assume(sec_r000834_11 >= 0 && sec_r000834_11 <= 255);
    __CPROVER_assume(sec_r000834_12 >= 0 && sec_r000834_12 <= 255);
    __CPROVER_assume(sec_r000834_13 >= 0 && sec_r000834_13 <= 255);
    __CPROVER_assume(sec_r000834_14 >= 0 && sec_r000834_14 <= 255);
    __CPROVER_assume(sec_r000834_15 >= 0 && sec_r000834_15 <= 255);
    __CPROVER_assume(sec_r000834_16 >= 0 && sec_r000834_16 <= 255);
    __CPROVER_assume(sec_r000834_17 >= 0 && sec_r000834_17 <= 255);
    __CPROVER_assume(sec_r000834_18 >= 0 && sec_r000834_18 <= 255);
    __CPROVER_assume(sec_r000834_19 >= 0 && sec_r000834_19 <= 255);
    __CPROVER_assume(sec_r000834_20 >= 0 && sec_r000834_20 <= 255);
    __CPROVER_assume(sec_r000834_21 >= 0 && sec_r000834_21 <= 255);

    struct CipherContext_R000834_4413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000834_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000834_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000834_0 + 7) & 15;
    struct DeviceConfig_R000834_4413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000834_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000834_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000834_0 + 9) & 15;
    struct StreamBuffer_R000834_4413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000834_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000834_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000834_0 + 11) & 15;

    union RegisterBank_R000834_4413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 36) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 22) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 37) {
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
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 13) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 28) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 18) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 33) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 11) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 26) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 29) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 44) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

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
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 36) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 51) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 16) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 31) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 28) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 43) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 19) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 34) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 48) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 17) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 32) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_91 = (stage_v_91 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_96 = (stage_v_96 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (out_sink > 100) ? (chk_sum & 31) : (107 & 31);
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= (stage_v_102 << 1) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[0] ^ 110) & 3;
    switch (stage_v_107) {
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

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_1.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 20) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 35) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 27) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 42) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 12) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 27) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 10) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 25) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 143) & 15;
    int stage_v_142 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= stage_v_142;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 18) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 33) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_2.buffer[2] * 2 + 490) & 63;
    if (stage_v_161 > 38) {
        out_sink = (out_sink + stage_v_161 - 5) & 255;
        if (stage_v_161 > 53) {
            chk_sum ^= (stage_v_161 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_161 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] ^ 168) & 3;
    switch (stage_v_165) {
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

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (st_var_2.buffer[0] ^ 170) & 3;
    switch (stage_v_167) {
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

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_2.buffer[0] ^ 176) & 3;
    switch (stage_v_173) {
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

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_0.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 36) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 51) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (out_sink > 100) ? (chk_sum & 31) : (183 & 31);
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= (stage_v_178 << 1) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 12) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 27) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_2.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (st_var_2.buffer[0] ^ 188) & 3;
    switch (stage_v_185) {
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

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] * 2 + 565) & 63;
    if (stage_v_186 > 21) {
        out_sink = (out_sink + stage_v_186 - 5) & 255;
        if (stage_v_186 > 36) {
            chk_sum ^= (stage_v_186 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_186 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (out_sink > 100) ? (chk_sum & 31) : (192 & 31);
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= (stage_v_187 << 1) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = table[1];
    table[1] = (table[2] + 379) & 63;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_2.buffer[2] * 2 + 580) & 63;
    if (stage_v_191 > 25) {
        out_sink = (out_sink + stage_v_191 - 5) & 255;
        if (stage_v_191 > 40) {
            chk_sum ^= (stage_v_191 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_191 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (out_sink > 100) ? (chk_sum & 31) : (198 & 31);
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= (stage_v_193 << 1) & 127;

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
    int stage_v_196 = table[0];
    table[0] = (table[1] + 393) & 63;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (st_var_2.buffer[2] * 2 + 598) & 63;
    if (stage_v_197 > 22) {
        out_sink = (out_sink + stage_v_197 - 5) & 255;
        if (stage_v_197 > 37) {
            chk_sum ^= (stage_v_197 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_197 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_198 = (stage_v_198 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_198) & 127;
    }
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 200) & 15;
    int stage_v_199 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= stage_v_199;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (out_sink > 100) ? (chk_sum & 31) : (205 & 31);
    out_sink = (out_sink + stage_v_200) & 255;
    chk_sum ^= (stage_v_200 << 1) & 127;

    /* Execution Pipeline Stage 201 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 202) & 15;
    int stage_v_201 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    chk_sum ^= stage_v_201;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = table[2];
    table[2] = (table[3] + 405) & 63;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (st_var_2.buffer[0] ^ 206) & 3;
    switch (stage_v_203) {
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

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_204 = (stage_v_204 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_204) & 127;
    }
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
    int stage_v_207 = table[3];
    table[3] = (table[0] + 415) & 63;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (st_var_1.buffer[0] ^ 211) & 3;
    switch (stage_v_208) {
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

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (st_var_2.buffer[0] ^ 212) & 3;
    switch (stage_v_209) {
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

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_210 = (stage_v_210 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_210) & 127;
    }
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (st_var_1.buffer[0] ^ 214) & 3;
    switch (stage_v_211) {
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

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (st_var_0.buffer[0] ^ 216) & 3;
    switch (stage_v_213) {
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

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = table[2];
    table[2] = (table[3] + 429) & 63;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_215 = (stage_v_215 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_215) & 127;
    }
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = table[0];
    table[0] = (table[1] + 433) & 63;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 218 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 219) & 15;
    int stage_v_218 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_218) & 255;
    chk_sum ^= stage_v_218;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (st_var_1.buffer[0] ^ 223) & 3;
    switch (stage_v_220) {
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

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (st_var_2.buffer[0] ^ 224) & 3;
    switch (stage_v_221) {
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

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (st_var_1.buffer[1] * 2 + 676) & 63;
    if (stage_v_223 > 30) {
        out_sink = (out_sink + stage_v_223 - 5) & 255;
        if (stage_v_223 > 45) {
            chk_sum ^= (stage_v_223 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_223 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 50, 98, 27, 86 };
    int s_idx = (sec_r000834_11 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
