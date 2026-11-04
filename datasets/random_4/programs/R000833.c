/*
 * Benchmark Program: R000833
 * Family: secret_dependent_array
 * Generator Seed: 483313
 * High Inputs: 20 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000833_3313_0 {
    int capacity;
    short watermark;
    int checksum;
    int buffer[3];
};

struct CipherContext_R000833_3313_1 {
    unsigned char tag;
    int round_key;
    unsigned char nonce;
    int counter;
    int buffer[3];
};

struct EventLog_R000833_3313_2 {
    unsigned char facility;
    int severity;
    int code;
    unsigned char seq;
    int buffer[3];
};

struct AudioFrame_R000833_3313_3 {
    unsigned char sample_rate;
    int rms;
    short gain;
    short peak;
    int buffer[3];
};

union RegisterBank_R000833_3313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000833_3313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000833_3313_0(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tally_78 = (aux + st.buffer[1]) & 3;
    switch (tally_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000833_3313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_88 = 0;
    for (int k = 0; k < 3; k++) {
        segment_88 = (segment_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_88) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_36 = local_arr[aux % 3];
    acc = (acc + index_reg_36 * 2) & 127;
    int offset_58 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_58 > 40) {
        acc = (acc + offset_58 * 2 + 5) & 127;
        aux ^= (offset_58 & 15);
    } else {
        acc = (acc - offset_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_2(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000833_3313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int sample_82 = local_arr[aux % 3];
    acc = (acc + sample_82 * 2) & 127;
    int vector_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_3(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000833_3313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_72 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_72 > 13) {
        acc = (acc + delta_72 * 2 + 5) & 127;
        aux ^= (delta_72 & 15);
    } else {
        acc = (acc - delta_72 + 11) & 127;
        aux += 3;
    }
    int coefficient_53 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_53 = (coefficient_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_53) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_4(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int offset_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_70) & 63;
    acc ^= aux;
    int accumulator_91 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_91 > 29) {
        acc = (acc + accumulator_91 * 2 + 5) & 127;
        aux ^= (accumulator_91 & 15);
    } else {
        acc = (acc - accumulator_91 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_32 = local_arr[aux % 3];
    acc = (acc + stride_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000833_3313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_12 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_12 > 48) {
        acc = (acc + sample_12 * 2 + 5) & 127;
        aux ^= (sample_12 & 15);
    } else {
        acc = (acc - sample_12 + 11) & 127;
        aux += 3;
    }
    int vector_55 = 0;
    for (int k = 0; k < 3; k++) {
        vector_55 = (vector_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_6(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000833_3313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_65 = (aux + st.buffer[1]) & 3;
    switch (mask_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_80 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_80 > 37) {
        acc = (acc + coefficient_80 * 2 + 5) & 127;
        aux ^= (coefficient_80 & 15);
    } else {
        acc = (acc - coefficient_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000833_3313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_74 = 0;
    for (int k = 0; k < 2; k++) {
        mask_74 = (mask_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_74) & 127;
    }
    int offset_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_65) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_8(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int weight_11 = (aux + st.buffer[1]) & 3;
    switch (weight_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_36 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_36 > 15) {
        acc = (acc + vector_36 * 2 + 5) & 127;
        aux ^= (vector_36 & 15);
    } else {
        acc = (acc - vector_36 + 11) & 127;
        aux += 3;
    }
    int delta_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000833_3313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_84 = (aux + st.buffer[1]) & 3;
    switch (damping_84) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_44 = local_arr[aux % 3];
    acc = (acc + index_reg_44 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000833_3313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int window_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_80 = local_arr[aux % 3];
    acc = (acc + damping_80 * 2) & 127;
    int factor_28 = 0;
    for (int k = 0; k < 3; k++) {
        factor_28 = (factor_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quotient_86 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_86 = (quotient_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_86) & 127;
    }
    int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000833_3313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int threshold_54 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_54 > 37) {
        acc = (acc + threshold_54 * 2 + 5) & 127;
        aux ^= (threshold_54 & 15);
    } else {
        acc = (acc - threshold_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_81 = local_arr[aux % 3];
    acc = (acc + delta_81 * 2) & 127;
    int threshold_96 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_96 = (threshold_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_96) & 127;
    }
    int checksum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_13(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000833_3313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int threshold_65 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_65 > 10) {
        acc = (acc + threshold_65 * 2 + 5) & 127;
        aux ^= (threshold_65 & 15);
    } else {
        acc = (acc - threshold_65 + 11) & 127;
        aux += 3;
    }
    int weight_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_49 = (aux + st.buffer[1]) & 3;
    switch (factor_49) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000833_3313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int stride_41 = local_arr[aux % 3];
    acc = (acc + stride_41 * 2) & 127;
    int phase_79 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_79 > 35) {
        acc = (acc + phase_79 * 2 + 5) & 127;
        aux ^= (phase_79 & 15);
    } else {
        acc = (acc - phase_79 + 11) & 127;
        aux += 3;
    }
    int parity_89 = (aux + st.buffer[1]) & 3;
    switch (parity_89) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_15(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000833_3313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int pivot_87 = local_arr[aux % 3];
    acc = (acc + pivot_87 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_66 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_66 = (tracker_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_66) & 127;
    }
    int stride_64 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_64 > 20) {
        acc = (acc + stride_64 * 2 + 5) & 127;
        aux ^= (stride_64 & 15);
    } else {
        acc = (acc - stride_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000833_3313_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_67 = (aux + st.buffer[1]) & 3;
    switch (sample_67) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_29 = local_arr[aux % 3];
    acc = (acc + metric_29 * 2) & 127;
    int mask_64 = 0;
    for (int k = 0; k < 3; k++) {
        mask_64 = (mask_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_64) & 127;
    }
    int residue_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000833_3313_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000833_3313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_72 = (aux + st.buffer[1]) & 3;
    switch (metric_72) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_50 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_50 = (checksum_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_50) & 127;
    }
    int residue_62 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_62 > 15) {
        acc = (acc + residue_62 * 2 + 5) & 127;
        aux ^= (residue_62 & 15);
    } else {
        acc = (acc - residue_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000833_3313_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000833_3313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_39 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_39 > 12) {
        acc = (acc + margin_39 * 2 + 5) & 127;
        aux ^= (margin_39 & 15);
    } else {
        acc = (acc - margin_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_14 = local_arr[aux % 3];
    acc = (acc + weight_14 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000833_0;
    int sec_r000833_1;
    int sec_r000833_2;
    int sec_r000833_3;
    int sec_r000833_4;
    int sec_r000833_5;
    int sec_r000833_6;
    int sec_r000833_7;
    int sec_r000833_8;
    int sec_r000833_9;
    int sec_r000833_10;
    int sec_r000833_11;
    int sec_r000833_12;
    int sec_r000833_13;
    int sec_r000833_14;
    int sec_r000833_15;
    int sec_r000833_16;
    int sec_r000833_17;
    int sec_r000833_18;
    int sec_r000833_19;
    int pub_r000833_0;
    int pub_r000833_1;
    int pub_r000833_2;
    int pub_r000833_3;
    int pub_r000833_4;
    int pub_r000833_5;
    int pub_r000833_6;
    int pub_r000833_7;
    int pub_r000833_8;
    int pub_r000833_9;
    int pub_r000833_10;
    int pub_r000833_11;
    int pub_r000833_12;
    int pub_r000833_13;
    int pub_r000833_14;
    int pub_r000833_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000833_0 >= -100 && pub_r000833_0 <= 100);
    __CPROVER_assume(pub_r000833_1 >= -100 && pub_r000833_1 <= 100);
    __CPROVER_assume(pub_r000833_2 >= -100 && pub_r000833_2 <= 100);
    __CPROVER_assume(pub_r000833_3 >= -100 && pub_r000833_3 <= 100);
    __CPROVER_assume(pub_r000833_4 >= -100 && pub_r000833_4 <= 100);
    __CPROVER_assume(pub_r000833_5 >= -100 && pub_r000833_5 <= 100);
    __CPROVER_assume(pub_r000833_6 >= -100 && pub_r000833_6 <= 100);
    __CPROVER_assume(pub_r000833_7 >= -100 && pub_r000833_7 <= 100);
    __CPROVER_assume(pub_r000833_8 >= -100 && pub_r000833_8 <= 100);
    __CPROVER_assume(pub_r000833_9 >= -100 && pub_r000833_9 <= 100);
    __CPROVER_assume(pub_r000833_10 >= -100 && pub_r000833_10 <= 100);
    __CPROVER_assume(pub_r000833_11 >= -100 && pub_r000833_11 <= 100);
    __CPROVER_assume(pub_r000833_12 >= -100 && pub_r000833_12 <= 100);
    __CPROVER_assume(pub_r000833_13 >= -100 && pub_r000833_13 <= 100);
    __CPROVER_assume(pub_r000833_14 >= -100 && pub_r000833_14 <= 100);
    __CPROVER_assume(pub_r000833_15 >= -100 && pub_r000833_15 <= 100);
    __CPROVER_assume(sec_r000833_0 >= 0 && sec_r000833_0 <= 255);
    __CPROVER_assume(sec_r000833_1 >= 0 && sec_r000833_1 <= 255);
    __CPROVER_assume(sec_r000833_2 >= 0 && sec_r000833_2 <= 255);
    __CPROVER_assume(sec_r000833_3 >= 0 && sec_r000833_3 <= 255);
    __CPROVER_assume(sec_r000833_4 >= 0 && sec_r000833_4 <= 255);
    __CPROVER_assume(sec_r000833_5 >= 0 && sec_r000833_5 <= 255);
    __CPROVER_assume(sec_r000833_6 >= 0 && sec_r000833_6 <= 255);
    __CPROVER_assume(sec_r000833_7 >= 0 && sec_r000833_7 <= 255);
    __CPROVER_assume(sec_r000833_8 >= 0 && sec_r000833_8 <= 255);
    __CPROVER_assume(sec_r000833_9 >= 0 && sec_r000833_9 <= 255);
    __CPROVER_assume(sec_r000833_10 >= 0 && sec_r000833_10 <= 255);
    __CPROVER_assume(sec_r000833_11 >= 0 && sec_r000833_11 <= 255);
    __CPROVER_assume(sec_r000833_12 >= 0 && sec_r000833_12 <= 255);
    __CPROVER_assume(sec_r000833_13 >= 0 && sec_r000833_13 <= 255);
    __CPROVER_assume(sec_r000833_14 >= 0 && sec_r000833_14 <= 255);
    __CPROVER_assume(sec_r000833_15 >= 0 && sec_r000833_15 <= 255);
    __CPROVER_assume(sec_r000833_16 >= 0 && sec_r000833_16 <= 255);
    __CPROVER_assume(sec_r000833_17 >= 0 && sec_r000833_17 <= 255);
    __CPROVER_assume(sec_r000833_18 >= 0 && sec_r000833_18 <= 255);
    __CPROVER_assume(sec_r000833_19 >= 0 && sec_r000833_19 <= 255);

    struct StreamBuffer_R000833_3313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000833_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000833_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000833_0 + 7) & 15;
    struct CipherContext_R000833_3313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000833_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000833_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000833_0 + 9) & 15;
    struct EventLog_R000833_3313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000833_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000833_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000833_0 + 11) & 15;
    struct AudioFrame_R000833_3313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000833_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000833_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000833_0 + 13) & 15;

    union RegisterBank_R000833_3313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 36) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 51) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 34) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 49) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 10) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 25) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 25) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 40) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 37) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 52) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 37) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 52) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 16) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 31) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 28) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 43) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 35) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 33) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 48) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 24) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 39) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 31) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 46) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 28) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 43) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 11) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 26) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (out_sink > 100) ? (chk_sum & 31) : (92 & 31);
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= (stage_v_87 << 1) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_96 = (stage_v_96 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 40) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 55) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_0.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 23) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 38) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_101 = (stage_v_101 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_2.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_3.buffer[1] * 2 + 316) & 63;
    if (stage_v_103 > 23) {
        out_sink = (out_sink + stage_v_103 - 5) & 255;
        if (stage_v_103 > 38) {
            chk_sum ^= (stage_v_103 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_103 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 35) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 50) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_3.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 11) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 26) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_2.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_128 = (stage_v_128 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[0] ^ 134) & 3;
    switch (stage_v_131) {
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

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_2.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 24) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 39) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 143) & 15;
    int stage_v_142 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= stage_v_142;

    /* Execution Pipeline Stage 143 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_2.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 39) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 54) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_152 = (stage_v_152 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = table[1];
    table[1] = (table[2] + 307) & 63;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 17) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 32) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[0] ^ 160) & 3;
    switch (stage_v_157) {
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

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 21) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 36) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[0] ^ 164) & 3;
    switch (stage_v_161) {
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

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 169) & 15;
    int stage_v_168 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= stage_v_168;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_170 = (stage_v_170 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_3.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 36) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 51) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = table[2];
    table[2] = (table[3] + 349) & 63;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_177 = (stage_v_177 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 71, 26, 85, 51 };
    int s_idx = (sec_r000833_14 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
