/*
 * Benchmark Program: R001830
 * Security Family: mixed_control_data
 * Generator Seed: 683013
 * High Inputs: 18 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001830_3013_0 {
    short iv;
    int nonce;
    int tag;
    unsigned char round_key;
    int flags;
    int buffer[3];
};

struct StreamBuffer_R001830_3013_1 {
    unsigned char head;
    int state;
    unsigned char capacity;
    int buffer[3];
};

struct MatrixBlock_R001830_3013_2 {
    unsigned char determinant;
    short dim;
    short trace;
    int stride;
    int density;
    int buffer[3];
};

struct AudioFrame_R001830_3013_3 {
    int peak;
    short sample_rate;
    unsigned char envelope;
    int buffer[3];
};

union RegisterBank_R001830_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001830_3013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_44 = (aux + st.buffer[1]) & 3;
    switch (offset_44) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_81 = 0;
    for (int k = 0; k < 2; k++) {
        margin_81 = (margin_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_81) & 127;
    }
    int threshold_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001830_3013_1(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_46 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_46 = (coefficient_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_46) & 127;
    }
    int checksum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001830_3013_2(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001830_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int checksum_17 = (aux + st.buffer[1]) & 3;
    switch (checksum_17) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_12 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_12 > 40) {
        acc = (acc + tally_12 * 2 + 5) & 127;
        aux ^= (tally_12 & 15);
    } else {
        acc = (acc - tally_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_74 = local_arr[aux % 3];
    acc = (acc + vector_74 * 2) & 127;
    int accumulator_64 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_64 = (accumulator_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_3(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_24 = (aux + st.buffer[1]) & 3;
    switch (index_reg_24) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_59 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_59 > 48) {
        acc = (acc + delta_59 * 2 + 5) & 127;
        aux ^= (delta_59 & 15);
    } else {
        acc = (acc - delta_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_72 = 0;
    for (int k = 0; k < 3; k++) {
        scale_72 = (scale_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_72) & 127;
    }
    int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_10) & 63;
    acc ^= aux;
    int metric_43 = (aux + st.buffer[1]) & 3;
    switch (metric_43) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_20 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_20 > 26) {
        acc = (acc + checksum_20 * 2 + 5) & 127;
        aux ^= (checksum_20 & 15);
    } else {
        acc = (acc - checksum_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_5(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_11 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_11 > 41) {
        acc = (acc + anchor_11 * 2 + 5) & 127;
        aux ^= (anchor_11 & 15);
    } else {
        acc = (acc - anchor_11 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int factor_71 = local_arr[aux % 3];
    acc = (acc + factor_71 * 2) & 127;
    int sample_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_86) & 63;
    acc ^= aux;
    int anchor_76 = (aux + st.buffer[1]) & 3;
    switch (anchor_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001830_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_91 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_91 = (quotient_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_91) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_34 = local_arr[aux % 3];
    acc = (acc + vector_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_70 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_70 = (coefficient_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_70) & 127;
    }
    int cursor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_30 > 36) {
        acc = (acc + cursor_30 * 2 + 5) & 127;
        aux ^= (cursor_30 & 15);
    } else {
        acc = (acc - cursor_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_83 = local_arr[aux % 3];
    acc = (acc + coefficient_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001830_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int scale_28 = (aux + st.buffer[1]) & 3;
    switch (scale_28) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_92) & 63;
    acc ^= aux;
    int index_reg_95 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_95 > 34) {
        acc = (acc + index_reg_95 * 2 + 5) & 127;
        aux ^= (index_reg_95 & 15);
    } else {
        acc = (acc - index_reg_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_10(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001830_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int stride_27 = 0;
    for (int k = 0; k < 3; k++) {
        stride_27 = (stride_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_27) & 127;
    }
    int weight_22 = (aux + st.buffer[1]) & 3;
    switch (weight_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_62 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_62 > 33) {
        acc = (acc + sample_62 * 2 + 5) & 127;
        aux ^= (sample_62 & 15);
    } else {
        acc = (acc - sample_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_11(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001830_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int parity_56 = local_arr[aux % 3];
    acc = (acc + parity_56 * 2) & 127;
    int cursor_17 = (aux + st.buffer[1]) & 3;
    switch (cursor_17) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_12(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_49) & 63;
    acc ^= aux;
    int tally_76 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_76 > 13) {
        acc = (acc + tally_76 * 2 + 5) & 127;
        aux ^= (tally_76 & 15);
    } else {
        acc = (acc - tally_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_71 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_71 > 11) {
        acc = (acc + pivot_71 * 2 + 5) & 127;
        aux ^= (pivot_71 & 15);
    } else {
        acc = (acc - pivot_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_35 = local_arr[aux % 3];
    acc = (acc + metric_35 * 2) & 127;
    int offset_80 = 0;
    for (int k = 0; k < 2; k++) {
        offset_80 = (offset_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_46 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_46 = (threshold_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_46) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int scale_16 = local_arr[aux % 3];
    acc = (acc + scale_16 * 2) & 127;
    int quotient_42 = (aux + st.buffer[1]) & 3;
    switch (quotient_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_68 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_68 > 28) {
        acc = (acc + vector_68 * 2 + 5) & 127;
        aux ^= (vector_68 & 15);
    } else {
        acc = (acc - vector_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_71 = local_arr[aux % 3];
    acc = (acc + delta_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_79 = (aux + st.buffer[1]) & 3;
    switch (tally_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_18(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_45 = (aux + st.buffer[1]) & 3;
    switch (parity_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_96 = local_arr[aux % 3];
    acc = (acc + anchor_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_19(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001830_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int segment_32 = local_arr[aux % 3];
    acc = (acc + segment_32 * 2) & 127;
    int cursor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001830_3013_20(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_85 = (aux + st.buffer[1]) & 3;
    switch (residue_85) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_61 = local_arr[aux % 3];
    acc = (acc + margin_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001830_3013_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001830_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_69 = 0;
    for (int k = 0; k < 3; k++) {
        metric_69 = (metric_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_69) & 127;
    }
    int damping_29 = (aux + st.buffer[1]) & 3;
    switch (damping_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_22(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001830_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_16) & 63;
    acc ^= aux;
    int quantum_73 = (aux + st.buffer[1]) & 3;
    switch (quantum_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_25 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_25 > 49) {
        acc = (acc + pivot_25 * 2 + 5) & 127;
        aux ^= (pivot_25 & 15);
    } else {
        acc = (acc - pivot_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001830_3013_23(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001830_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_88 = 0;
    for (int k = 0; k < 3; k++) {
        stride_88 = (stride_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_88) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001830_0;
    int sec_r001830_1;
    int sec_r001830_2;
    int sec_r001830_3;
    int sec_r001830_4;
    int sec_r001830_5;
    int sec_r001830_6;
    int sec_r001830_7;
    int sec_r001830_8;
    int sec_r001830_9;
    int sec_r001830_10;
    int sec_r001830_11;
    int sec_r001830_12;
    int sec_r001830_13;
    int sec_r001830_14;
    int sec_r001830_15;
    int sec_r001830_16;
    int sec_r001830_17;
    int pub_r001830_0;
    int pub_r001830_1;
    int pub_r001830_2;
    int pub_r001830_3;
    int pub_r001830_4;
    int pub_r001830_5;
    int pub_r001830_6;
    int pub_r001830_7;
    int pub_r001830_8;
    int pub_r001830_9;
    int pub_r001830_10;
    int pub_r001830_11;
    int pub_r001830_12;
    int pub_r001830_13;
    int pub_r001830_14;
    int pub_r001830_15;
    int pub_r001830_16;
    int pub_r001830_17;
    int pub_r001830_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001830_0 >= -100 && pub_r001830_0 <= 100);
    __CPROVER_assume(pub_r001830_1 >= -100 && pub_r001830_1 <= 100);
    __CPROVER_assume(pub_r001830_2 >= -100 && pub_r001830_2 <= 100);
    __CPROVER_assume(pub_r001830_3 >= -100 && pub_r001830_3 <= 100);
    __CPROVER_assume(pub_r001830_4 >= -100 && pub_r001830_4 <= 100);
    __CPROVER_assume(pub_r001830_5 >= -100 && pub_r001830_5 <= 100);
    __CPROVER_assume(pub_r001830_6 >= -100 && pub_r001830_6 <= 100);
    __CPROVER_assume(pub_r001830_7 >= -100 && pub_r001830_7 <= 100);
    __CPROVER_assume(pub_r001830_8 >= -100 && pub_r001830_8 <= 100);
    __CPROVER_assume(pub_r001830_9 >= -100 && pub_r001830_9 <= 100);
    __CPROVER_assume(pub_r001830_10 >= -100 && pub_r001830_10 <= 100);
    __CPROVER_assume(pub_r001830_11 >= -100 && pub_r001830_11 <= 100);
    __CPROVER_assume(pub_r001830_12 >= -100 && pub_r001830_12 <= 100);
    __CPROVER_assume(pub_r001830_13 >= -100 && pub_r001830_13 <= 100);
    __CPROVER_assume(pub_r001830_14 >= -100 && pub_r001830_14 <= 100);
    __CPROVER_assume(pub_r001830_15 >= -100 && pub_r001830_15 <= 100);
    __CPROVER_assume(pub_r001830_16 >= -100 && pub_r001830_16 <= 100);
    __CPROVER_assume(pub_r001830_17 >= -100 && pub_r001830_17 <= 100);
    __CPROVER_assume(pub_r001830_18 >= -100 && pub_r001830_18 <= 100);
    __CPROVER_assume(sec_r001830_0 >= 0 && sec_r001830_0 <= 255);
    __CPROVER_assume(sec_r001830_1 >= 0 && sec_r001830_1 <= 255);
    __CPROVER_assume(sec_r001830_2 >= 0 && sec_r001830_2 <= 255);
    __CPROVER_assume(sec_r001830_3 >= 0 && sec_r001830_3 <= 255);
    __CPROVER_assume(sec_r001830_4 >= 0 && sec_r001830_4 <= 255);
    __CPROVER_assume(sec_r001830_5 >= 0 && sec_r001830_5 <= 255);
    __CPROVER_assume(sec_r001830_6 >= 0 && sec_r001830_6 <= 255);
    __CPROVER_assume(sec_r001830_7 >= 0 && sec_r001830_7 <= 255);
    __CPROVER_assume(sec_r001830_8 >= 0 && sec_r001830_8 <= 255);
    __CPROVER_assume(sec_r001830_9 >= 0 && sec_r001830_9 <= 255);
    __CPROVER_assume(sec_r001830_10 >= 0 && sec_r001830_10 <= 255);
    __CPROVER_assume(sec_r001830_11 >= 0 && sec_r001830_11 <= 255);
    __CPROVER_assume(sec_r001830_12 >= 0 && sec_r001830_12 <= 255);
    __CPROVER_assume(sec_r001830_13 >= 0 && sec_r001830_13 <= 255);
    __CPROVER_assume(sec_r001830_14 >= 0 && sec_r001830_14 <= 255);
    __CPROVER_assume(sec_r001830_15 >= 0 && sec_r001830_15 <= 255);
    __CPROVER_assume(sec_r001830_16 >= 0 && sec_r001830_16 <= 255);
    __CPROVER_assume(sec_r001830_17 >= 0 && sec_r001830_17 <= 255);

    struct CipherContext_R001830_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001830_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001830_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001830_0 + 7) & 15;
    struct StreamBuffer_R001830_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001830_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001830_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001830_0 + 9) & 15;
    struct MatrixBlock_R001830_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001830_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001830_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001830_0 + 11) & 15;
    struct AudioFrame_R001830_3013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001830_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001830_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001830_0 + 13) & 15;

    union RegisterBank_R001830_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001830_3013_0(sec_r001830_0, sec_r001830_1, pub_r001830_2, pub_r001830_3, pub_r001830_4);
    int helper_flow_1 = fn_R001830_3013_1(sec_r001830_1, pub_r001830_2, pub_r001830_3);
    int helper_flow_2 = fn_R001830_3013_2(sec_r001830_2, sec_r001830_3);
    int helper_flow_3 = fn_R001830_3013_3(sec_r001830_3, sec_r001830_4, pub_r001830_5);
    int helper_flow_4 = fn_R001830_3013_4(sec_r001830_4, pub_r001830_5, pub_r001830_6, pub_r001830_7);
    int helper_flow_5 = fn_R001830_3013_5(sec_r001830_5, pub_r001830_6, pub_r001830_7);
    int helper_flow_6 = fn_R001830_3013_6(sec_r001830_6, pub_r001830_7, pub_r001830_8, pub_r001830_9, pub_r001830_10);
    int helper_flow_7 = fn_R001830_3013_7(sec_r001830_7, pub_r001830_8, pub_r001830_9, pub_r001830_10);
    int helper_flow_8 = fn_R001830_3013_8(sec_r001830_8, pub_r001830_9, pub_r001830_10, pub_r001830_11, pub_r001830_12);
    int helper_flow_9 = fn_R001830_3013_9(sec_r001830_9, pub_r001830_10, pub_r001830_11, pub_r001830_12);
    int helper_flow_10 = fn_R001830_3013_10(sec_r001830_10, pub_r001830_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_0 > 42) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_1 > 22) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001830_11 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_3 > 43) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001830_7 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_4 > 44) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001830_11 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_5 > 42) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001830_1 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001830_5 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001830_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_9 > 34) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_10 > 45) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_11 > 39) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001830_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_13 > 50) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001830_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001830_17 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_15 > 26) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001830_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001830_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001830_6 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_18 > 34) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001830_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001830_14 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_20 > 33) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001830_5 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_21 > 40) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001830_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001830_3 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_23 > 36) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_24 > 46) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_25 > 45) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001830_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001830_4 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_27 > 23) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_28 > 32) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001830_14 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_29 > 30) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_30 > 31) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_31 > 39) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_32 > 36) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_33 > 50) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001830_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_35 > 42) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001830_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_37 > 24) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001830_15 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_38 > 45) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001830_10 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_39 > 35) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001830_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_41 > 23) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_42 > 21) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001830_12 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001830_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001830_14 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_45 > 38) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_46 > 48) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_47 > 47) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_48 > 38) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001830_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001830_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001830_0 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_51 > 35) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001830_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001830_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001830_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_55 > 26) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_56 > 21) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001830_3 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_57 > 36) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001830_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_59 > 43) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_60 > 20) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001830_9 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_61 > 45) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_62 > 25) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_63 > 25) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_64 > 39) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_65 > 46) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001830_12 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_66 > 38) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_68 > 46) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_69 > 30) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001830_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_71 > 28) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_72 > 25) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_73 > 35) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_74 > 40) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001830_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_76 > 26) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_77 > 49) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_78 > 23) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_79 > 47) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_80 > 39) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_81 > 39) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_82 > 48) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001830_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001830_13 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_84 > 45) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001830_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_86 > 28) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_87 > 45) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_88 > 26) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_89 > 32) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_91 > 36) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_92 > 39) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_93 > 36) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001830_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_95 > 33) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001830_10 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_96 > 39) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_97 > 29) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_98 > 35) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_99 > 36) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001830_4 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_100 > 36) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001830_5 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_101 > 45) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_102 > 41) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001830_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_104 > 40) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_105 > 35) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001830_14 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_106 > 43) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_107 > 38) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_108 > 26) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001830_0 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_109 > 45) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_110 > 22) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001830_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_112 > 47) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001830_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_114 > 44) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001830_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001830_15 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_117 > 33) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_118 > 31) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_119 > 21) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_120 > 35) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001830_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_122 > 50) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001830_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001830_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_125 > 30) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001830_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_127 > 47) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001830_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_129 > 27) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001830_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001830_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_132 > 36) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_133 > 34) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_134 > 47) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001830_13 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_135 > 30) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001830_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001830_4 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_137 > 42) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_138 > 21) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_139 > 43) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_140 > 26) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001830_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_142 > 21) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r001830_10 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_143 > 31) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001830_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_145 > 22) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_146 > 24) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_147 > 21) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_148 > 38) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_149 > 25) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_150 > 20) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001830_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001830_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_153 > 37) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_154 > 24) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_155 > 44) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001830_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001830_0) & 127;
    if (stage_v_157 > 32) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_158 > 50) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_159 > 39) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001830_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_161 > 40) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001830_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001830_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_164 > 39) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001830_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_166 > 45) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001830_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_168 > 50) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001830_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_170 > 24) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001830_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_172 > 38) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001830_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_174 > 41) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_175 > 43) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_176 > 50) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_177 > 35) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001830_2) & 127;
    if (stage_v_178 > 31) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001830_16) & 127;
    if (stage_v_179 > 45) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_180 > 41) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001830_7) & 127;
    if (stage_v_181 > 47) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_182 > 37) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001830_1) & 127;
    if (stage_v_183 > 49) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001830_15 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_184 > 33) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001830_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001830_12) & 127;
    if (stage_v_186 > 37) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_187 > 33) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001830_9 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_188 > 20) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_189 > 42) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001830_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_166 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_191 > 40) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001830_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001830_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_194 > 30) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_195 > 28) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_196 > 40) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r001830_8 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_197 > 37) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001830_0 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_198 > 48) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001830_17) & 127;
    if (stage_v_199 > 44) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_200 > 26) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_201 > 44) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_202 > 29) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_203 > 38) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001830_14) & 127;
    if (stage_v_204 > 34) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001830_9) & 127;
    if (stage_v_205 > 50) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001830_18) & 127;
    if (stage_v_206 > 34) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_207 > 24) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001830_15 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_208 > 24) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_209 > 20) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_207 ^ 0x2A) * 2 + pub_r001830_6) & 127;
    if (stage_v_210 > 35) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_211 > 49) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001830_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001830_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_214 > 38) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001830_11) & 127;
    if (stage_v_216 > 22) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001830_4) & 127;
    if (stage_v_217 > 32) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_196 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_218 > 49) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_219 > 37) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001830_5) & 127;
    if (stage_v_220 > 41) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_217 ^ 0x2A) * 2 + pub_r001830_8) & 127;
    if (stage_v_221 > 50) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001830_13) & 127;
    if (stage_v_222 > 24) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001830_15) & 127;
    if (stage_v_223 > 29) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001830_3) & 127;
    if (stage_v_224 > 43) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001830_10) & 127;
    if (stage_v_225 > 44) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
