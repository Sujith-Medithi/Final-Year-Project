/*
 * Benchmark Program: R001346
 * Security Family: implicit_flow
 * Generator Seed: 634613
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001346_4613_0 {
    unsigned char round_key;
    int nonce;
    unsigned char counter;
    int buffer[3];
};

struct AudioFrame_R001346_4613_1 {
    unsigned char envelope;
    short channels;
    short sample_rate;
    unsigned char peak;
    short rms;
    int buffer[3];
};

union RegisterBank_R001346_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001346_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001346_4613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_94 = (aux + st.buffer[1]) & 3;
    switch (phase_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001346_4613_1(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int residue_74 = local_arr[aux % 3];
    acc = (acc + residue_74 * 2) & 127;
    int mask_26 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_26 > 37) {
        acc = (acc + mask_26 * 2 + 5) & 127;
        aux ^= (mask_26 & 15);
    } else {
        acc = (acc - mask_26 + 11) & 127;
        aux += 3;
    }
    int cursor_71 = (aux + st.buffer[1]) & 3;
    switch (cursor_71) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_2(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_89 = (aux + st.buffer[1]) & 3;
    switch (quotient_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_50 = 0;
    for (int k = 0; k < 3; k++) {
        factor_50 = (factor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_50) & 127;
    }
    int cursor_46 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_46 > 42) {
        acc = (acc + cursor_46 * 2 + 5) & 127;
        aux ^= (cursor_46 & 15);
    } else {
        acc = (acc - cursor_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_45 = local_arr[aux % 3];
    acc = (acc + vector_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_15 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_15 = (anchor_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_15) & 127;
    }
    int accumulator_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_31) & 63;
    acc ^= aux;
    int residue_46 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_46 > 36) {
        acc = (acc + residue_46 * 2 + 5) & 127;
        aux ^= (residue_46 & 15);
    } else {
        acc = (acc - residue_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_4(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_14) & 63;
    acc ^= aux;
    int offset_53 = 0;
    for (int k = 0; k < 3; k++) {
        offset_53 = (offset_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_53) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_44 = local_arr[aux % 3];
    acc = (acc + pivot_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_5(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_23) & 63;
    acc ^= aux;
    int tally_87 = (aux + st.buffer[1]) & 3;
    switch (tally_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_41 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_41 > 43) {
        acc = (acc + tally_41 * 2 + 5) & 127;
        aux ^= (tally_41 & 15);
    } else {
        acc = (acc - tally_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_6(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int parity_24 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_24 > 48) {
        acc = (acc + parity_24 * 2 + 5) & 127;
        aux ^= (parity_24 & 15);
    } else {
        acc = (acc - parity_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001346_4613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_79 > 37) {
        acc = (acc + checksum_79 * 2 + 5) & 127;
        aux ^= (checksum_79 & 15);
    } else {
        acc = (acc - checksum_79 + 11) & 127;
        aux += 3;
    }
    int vector_24 = 0;
    for (int k = 0; k < 3; k++) {
        vector_24 = (vector_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_24) & 127;
    }
    int cursor_68 = (aux + st.buffer[1]) & 3;
    switch (cursor_68) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_11 = local_arr[aux % 3];
    acc = (acc + parity_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_8(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_51 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_51 > 33) {
        acc = (acc + metric_51 * 2 + 5) & 127;
        aux ^= (metric_51 & 15);
    } else {
        acc = (acc - metric_51 + 11) & 127;
        aux += 3;
    }
    int segment_95 = 0;
    for (int k = 0; k < 2; k++) {
        segment_95 = (segment_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_95) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_48 = local_arr[aux % 3];
    acc = (acc + scale_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_9(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_11) & 63;
    acc ^= aux;
    int threshold_80 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_80 > 27) {
        acc = (acc + threshold_80 * 2 + 5) & 127;
        aux ^= (threshold_80 & 15);
    } else {
        acc = (acc - threshold_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_10(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int weight_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_32) & 63;
    acc ^= aux;
    int factor_82 = (aux + st.buffer[1]) & 3;
    switch (factor_82) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_61 = 0;
    for (int k = 0; k < 3; k++) {
        segment_61 = (segment_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_61) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_42) & 63;
    acc ^= aux;
    int margin_30 = (aux + st.buffer[1]) & 3;
    switch (margin_30) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_34 = 0;
    for (int k = 0; k < 2; k++) {
        stride_34 = (stride_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_45 = (aux + st.buffer[1]) & 3;
    switch (quotient_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_60) & 63;
    acc ^= aux;
    int phase_50 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_50 > 47) {
        acc = (acc + phase_50 * 2 + 5) & 127;
        aux ^= (phase_50 & 15);
    } else {
        acc = (acc - phase_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int residue_37 = (aux + st.buffer[1]) & 3;
    switch (residue_37) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_61 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_61 > 37) {
        acc = (acc + vector_61 * 2 + 5) & 127;
        aux ^= (vector_61 & 15);
    } else {
        acc = (acc - vector_61 + 11) & 127;
        aux += 3;
    }
    int index_reg_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001346_4613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_54 = (aux + st.buffer[1]) & 3;
    switch (vector_54) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_15 = local_arr[aux % 3];
    acc = (acc + parity_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_16(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int offset_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_95) & 63;
    acc ^= aux;
    int tracker_51 = (aux + st.buffer[1]) & 3;
    switch (tracker_51) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_10 = local_arr[aux % 3];
    acc = (acc + segment_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int accumulator_56 = (aux + st.buffer[1]) & 3;
    switch (accumulator_56) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_67 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_67 = (tracker_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_18(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_82 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_82 = (pivot_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_82) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_80 = local_arr[aux % 3];
    acc = (acc + pivot_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001346_4613_19(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int phase_13 = local_arr[aux % 3];
    acc = (acc + phase_13 * 2) & 127;
    int stride_58 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_58 > 18) {
        acc = (acc + stride_58 * 2 + 5) & 127;
        aux ^= (stride_58 & 15);
    } else {
        acc = (acc - stride_58 + 11) & 127;
        aux += 3;
    }
    int phase_81 = 0;
    for (int k = 0; k < 3; k++) {
        phase_81 = (phase_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_81) & 127;
    }
    int tally_33 = (aux + st.buffer[1]) & 3;
    switch (tally_33) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_19 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_19 = (tracker_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_19) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_21(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_46 = local_arr[aux % 3];
    acc = (acc + sample_46 * 2) & 127;
    int factor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_32 > 44) {
        acc = (acc + factor_32 * 2 + 5) & 127;
        aux ^= (factor_32 & 15);
    } else {
        acc = (acc - factor_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001346_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_20 = (aux + st.buffer[1]) & 3;
    switch (stride_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_57 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_57 > 46) {
        acc = (acc + residue_57 * 2 + 5) & 127;
        aux ^= (residue_57 & 15);
    } else {
        acc = (acc - residue_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001346_4613_23(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001346_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_33) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_13 = local_arr[aux % 3];
    acc = (acc + threshold_13 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001346_0;
    int sec_r001346_1;
    int sec_r001346_2;
    int sec_r001346_3;
    int sec_r001346_4;
    int sec_r001346_5;
    int sec_r001346_6;
    int sec_r001346_7;
    int sec_r001346_8;
    int sec_r001346_9;
    int sec_r001346_10;
    int sec_r001346_11;
    int sec_r001346_12;
    int sec_r001346_13;
    int sec_r001346_14;
    int sec_r001346_15;
    int sec_r001346_16;
    int sec_r001346_17;
    int sec_r001346_18;
    int pub_r001346_0;
    int pub_r001346_1;
    int pub_r001346_2;
    int pub_r001346_3;
    int pub_r001346_4;
    int pub_r001346_5;
    int pub_r001346_6;
    int pub_r001346_7;
    int pub_r001346_8;
    int pub_r001346_9;
    int pub_r001346_10;
    int pub_r001346_11;
    int pub_r001346_12;
    int pub_r001346_13;
    int pub_r001346_14;
    int pub_r001346_15;
    int pub_r001346_16;
    int pub_r001346_17;
    int pub_r001346_18;
    int pub_r001346_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001346_0 >= -100 && pub_r001346_0 <= 100);
    __CPROVER_assume(pub_r001346_1 >= -100 && pub_r001346_1 <= 100);
    __CPROVER_assume(pub_r001346_2 >= -100 && pub_r001346_2 <= 100);
    __CPROVER_assume(pub_r001346_3 >= -100 && pub_r001346_3 <= 100);
    __CPROVER_assume(pub_r001346_4 >= -100 && pub_r001346_4 <= 100);
    __CPROVER_assume(pub_r001346_5 >= -100 && pub_r001346_5 <= 100);
    __CPROVER_assume(pub_r001346_6 >= -100 && pub_r001346_6 <= 100);
    __CPROVER_assume(pub_r001346_7 >= -100 && pub_r001346_7 <= 100);
    __CPROVER_assume(pub_r001346_8 >= -100 && pub_r001346_8 <= 100);
    __CPROVER_assume(pub_r001346_9 >= -100 && pub_r001346_9 <= 100);
    __CPROVER_assume(pub_r001346_10 >= -100 && pub_r001346_10 <= 100);
    __CPROVER_assume(pub_r001346_11 >= -100 && pub_r001346_11 <= 100);
    __CPROVER_assume(pub_r001346_12 >= -100 && pub_r001346_12 <= 100);
    __CPROVER_assume(pub_r001346_13 >= -100 && pub_r001346_13 <= 100);
    __CPROVER_assume(pub_r001346_14 >= -100 && pub_r001346_14 <= 100);
    __CPROVER_assume(pub_r001346_15 >= -100 && pub_r001346_15 <= 100);
    __CPROVER_assume(pub_r001346_16 >= -100 && pub_r001346_16 <= 100);
    __CPROVER_assume(pub_r001346_17 >= -100 && pub_r001346_17 <= 100);
    __CPROVER_assume(pub_r001346_18 >= -100 && pub_r001346_18 <= 100);
    __CPROVER_assume(pub_r001346_19 >= -100 && pub_r001346_19 <= 100);
    __CPROVER_assume(sec_r001346_0 >= 0 && sec_r001346_0 <= 255);
    __CPROVER_assume(sec_r001346_1 >= 0 && sec_r001346_1 <= 255);
    __CPROVER_assume(sec_r001346_2 >= 0 && sec_r001346_2 <= 255);
    __CPROVER_assume(sec_r001346_3 >= 0 && sec_r001346_3 <= 255);
    __CPROVER_assume(sec_r001346_4 >= 0 && sec_r001346_4 <= 255);
    __CPROVER_assume(sec_r001346_5 >= 0 && sec_r001346_5 <= 255);
    __CPROVER_assume(sec_r001346_6 >= 0 && sec_r001346_6 <= 255);
    __CPROVER_assume(sec_r001346_7 >= 0 && sec_r001346_7 <= 255);
    __CPROVER_assume(sec_r001346_8 >= 0 && sec_r001346_8 <= 255);
    __CPROVER_assume(sec_r001346_9 >= 0 && sec_r001346_9 <= 255);
    __CPROVER_assume(sec_r001346_10 >= 0 && sec_r001346_10 <= 255);
    __CPROVER_assume(sec_r001346_11 >= 0 && sec_r001346_11 <= 255);
    __CPROVER_assume(sec_r001346_12 >= 0 && sec_r001346_12 <= 255);
    __CPROVER_assume(sec_r001346_13 >= 0 && sec_r001346_13 <= 255);
    __CPROVER_assume(sec_r001346_14 >= 0 && sec_r001346_14 <= 255);
    __CPROVER_assume(sec_r001346_15 >= 0 && sec_r001346_15 <= 255);
    __CPROVER_assume(sec_r001346_16 >= 0 && sec_r001346_16 <= 255);
    __CPROVER_assume(sec_r001346_17 >= 0 && sec_r001346_17 <= 255);
    __CPROVER_assume(sec_r001346_18 >= 0 && sec_r001346_18 <= 255);

    struct CipherContext_R001346_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001346_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001346_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001346_0 + 7) & 15;
    struct AudioFrame_R001346_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001346_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001346_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001346_0 + 9) & 15;

    union RegisterBank_R001346_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001346_4613_0(sec_r001346_0, pub_r001346_1, pub_r001346_2, pub_r001346_3, pub_r001346_4);
    int helper_flow_1 = fn_R001346_4613_1(sec_r001346_1, sec_r001346_2, pub_r001346_3);
    int helper_flow_2 = fn_R001346_4613_2(sec_r001346_2, pub_r001346_3);
    int helper_flow_3 = fn_R001346_4613_3(sec_r001346_3, sec_r001346_4, pub_r001346_5, pub_r001346_6, pub_r001346_7);
    int helper_flow_4 = fn_R001346_4613_4(sec_r001346_4, sec_r001346_5);
    int helper_flow_5 = fn_R001346_4613_5(sec_r001346_5, sec_r001346_6);
    int helper_flow_6 = fn_R001346_4613_6(sec_r001346_6, pub_r001346_7);
    int helper_flow_7 = fn_R001346_4613_7(sec_r001346_7, pub_r001346_8, pub_r001346_9, pub_r001346_10);
    int helper_flow_8 = fn_R001346_4613_8(sec_r001346_8, pub_r001346_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_3 + pub_r001346_18 * 2 + 5) & 127;
    if (stage_v_0 > 23) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001346_18 + pub_r001346_0 * 2 + 8) & 127;
    if (stage_v_1 > 27) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001346_7 + pub_r001346_0 * 2 + 11) & 127;
    if (stage_v_2 > 50) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001346_1 + pub_r001346_16 * 2 + 14) & 127;
    if (stage_v_3 > 32) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001346_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001346_15 + pub_r001346_1 * 2 + 20) & 127;
    if (stage_v_5 > 30) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001346_1 + pub_r001346_13 * 2 + 23) & 127;
    if (stage_v_6 > 48) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_3 + pub_r001346_7 * 2 + 26) & 127;
    if (stage_v_7 > 47) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001346_8 + pub_r001346_1 * 2 + 29) & 127;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_8 + pub_r001346_10 * 2 + 32) & 127;
    if (stage_v_9 > 21) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001346_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001346_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (stage_v_2 + pub_r001346_6 * 2 + 41) & 127;
    if (stage_v_12 > 30) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001346_7 + pub_r001346_1 * 2 + 44) & 127;
    if (stage_v_13 > 17) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_0 + pub_r001346_6 * 2 + 47) & 127;
    if (stage_v_14 > 51) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001346_7 + pub_r001346_11 * 2 + 50) & 127;
    if (stage_v_15 > 15) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001346_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001346_5 + pub_r001346_4 * 2 + 56) & 127;
    if (stage_v_17 > 27) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001346_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001346_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001346_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_8 + pub_r001346_2 * 2 + 68) & 127;
    if (stage_v_21 > 31) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001346_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001346_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001346_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_5 + pub_r001346_19 * 2 + 80) & 127;
    if (stage_v_25 > 45) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001346_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_1 + pub_r001346_12 * 2 + 86) & 127;
    if (stage_v_27 > 40) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_0 + pub_r001346_19 * 2 + 89) & 127;
    if (stage_v_28 > 50) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_3 + pub_r001346_9 * 2 + 92) & 127;
    if (stage_v_29 > 16) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_1 + pub_r001346_9 * 2 + 95) & 127;
    if (stage_v_30 > 42) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001346_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001346_9 + pub_r001346_11 * 2 + 101) & 127;
    if (stage_v_32 > 27) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001346_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001346_16 + pub_r001346_12 * 2 + 107) & 127;
    if (stage_v_34 > 15) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_7 + pub_r001346_13 * 2 + 110) & 127;
    if (stage_v_35 > 50) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_21 + pub_r001346_16 * 2 + 113) & 127;
    if (stage_v_36 > 28) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001346_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001346_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001346_17 + pub_r001346_11 * 2 + 122) & 127;
    if (stage_v_39 > 27) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001346_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001346_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_8 + pub_r001346_9 * 2 + 131) & 127;
    if (stage_v_42 > 51) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001346_5 + pub_r001346_10 * 2 + 134) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_21 + pub_r001346_4 * 2 + 137) & 127;
    if (stage_v_44 > 18) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001346_2 + pub_r001346_3 * 2 + 140) & 127;
    if (stage_v_45 > 51) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_34 + pub_r001346_3 * 2 + 143) & 127;
    if (stage_v_46 > 58) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001346_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_9 + pub_r001346_3 * 2 + 149) & 127;
    if (stage_v_48 > 42) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001346_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001346_6 + pub_r001346_4 * 2 + 155) & 127;
    if (stage_v_50 > 41) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_14 + pub_r001346_1 * 2 + 158) & 127;
    if (stage_v_51 > 17) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001346_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_28 + pub_r001346_2 * 2 + 164) & 127;
    if (stage_v_53 > 51) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001346_2 + pub_r001346_13 * 2 + 167) & 127;
    if (stage_v_54 > 60) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001346_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001346_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001346_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001346_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001346_8 + pub_r001346_8 * 2 + 182) & 127;
    if (stage_v_59 > 20) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_15 + pub_r001346_2 * 2 + 185) & 127;
    if (stage_v_60 > 27) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001346_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001346_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001346_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001346_4 + pub_r001346_5 * 2 + 197) & 127;
    if (stage_v_64 > 52) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001346_16 + pub_r001346_5 * 2 + 200) & 127;
    if (stage_v_65 > 28) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001346_10 + pub_r001346_12 * 2 + 203) & 127;
    if (stage_v_66 > 45) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001346_15 + pub_r001346_19 * 2 + 206) & 127;
    if (stage_v_67 > 36) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_28 + pub_r001346_7 * 2 + 209) & 127;
    if (stage_v_68 > 45) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_51 + pub_r001346_8 * 2 + 212) & 127;
    if (stage_v_69 > 41) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001346_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001346_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_15 + pub_r001346_2 * 2 + 221) & 127;
    if (stage_v_72 > 29) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001346_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001346_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_28 + pub_r001346_2 * 2 + 230) & 127;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (helper_flow_4 + pub_r001346_10 * 2 + 233) & 127;
    if (stage_v_76 > 50) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_75 + pub_r001346_8 * 2 + 236) & 127;
    if (stage_v_77 > 38) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_25 + pub_r001346_18 * 2 + 239) & 127;
    if (stage_v_78 > 49) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001346_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001346_0 + pub_r001346_11 * 2 + 245) & 127;
    if (stage_v_80 > 42) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_39 + pub_r001346_0 * 2 + 248) & 127;
    if (stage_v_81 > 44) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001346_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001346_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001346_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001346_5 + pub_r001346_13 * 2 + 260) & 127;
    if (stage_v_85 > 54) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_76 + pub_r001346_13 * 2 + 263) & 127;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001346_17 + pub_r001346_7 * 2 + 266) & 127;
    if (stage_v_87 > 16) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_48 + pub_r001346_2 * 2 + 269) & 127;
    if (stage_v_88 > 47) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_46 + pub_r001346_19 * 2 + 272) & 127;
    if (stage_v_89 > 40) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_2 + pub_r001346_7 * 2 + 275) & 127;
    if (stage_v_90 > 34) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_6 + pub_r001346_11 * 2 + 278) & 127;
    if (stage_v_91 > 47) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_1 + pub_r001346_6 * 2 + 281) & 127;
    if (stage_v_92 > 15) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001346_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_44 + pub_r001346_18 * 2 + 287) & 127;
    if (stage_v_94 > 32) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_4 + pub_r001346_18 * 2 + 290) & 127;
    if (stage_v_95 > 49) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_76 + pub_r001346_5 * 2 + 293) & 127;
    if (stage_v_96 > 54) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001346_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001346_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001346_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (helper_flow_4 + pub_r001346_5 * 2 + 305) & 127;
    if (stage_v_100 > 42) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001346_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_25 + pub_r001346_5 * 2 + 311) & 127;
    if (stage_v_102 > 43) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001346_9 + pub_r001346_15 * 2 + 314) & 127;
    if (stage_v_103 > 19) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_5 + pub_r001346_3 * 2 + 317) & 127;
    if (stage_v_104 > 42) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_39 + pub_r001346_0 * 2 + 320) & 127;
    if (stage_v_105 > 43) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_1 + pub_r001346_6 * 2 + 323) & 127;
    if (stage_v_106 > 56) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_59 + pub_r001346_5 * 2 + 326) & 127;
    if (stage_v_107 > 57) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001346_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_46 + pub_r001346_12 * 2 + 332) & 127;
    if (stage_v_109 > 37) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001346_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_28 + pub_r001346_1 * 2 + 338) & 127;
    if (stage_v_111 > 23) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001346_11 + pub_r001346_3 * 2 + 341) & 127;
    if (stage_v_112 > 29) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_25 + pub_r001346_6 * 2 + 344) & 127;
    if (stage_v_113 > 35) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_102 + pub_r001346_19 * 2 + 347) & 127;
    if (stage_v_114 > 56) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001346_18 + pub_r001346_8 * 2 + 350) & 127;
    if (stage_v_115 > 36) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001346_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_4 + pub_r001346_7 * 2 + 356) & 127;
    if (stage_v_117 > 52) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_54 + pub_r001346_5 * 2 + 359) & 127;
    if (stage_v_118 > 57) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001346_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001346_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001346_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001346_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001346_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001346_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_8 + pub_r001346_15 * 2 + 380) & 127;
    if (stage_v_125 > 30) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001346_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001346_15 + pub_r001346_3 * 2 + 386) & 127;
    if (stage_v_127 > 38) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001346_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001346_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (helper_flow_2 + pub_r001346_5 * 2 + 395) & 127;
    if (stage_v_130 > 28) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_95 + pub_r001346_5 * 2 + 398) & 127;
    if (stage_v_131 > 34) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_9 + pub_r001346_11 * 2 + 401) & 127;
    if (stage_v_132 > 25) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001346_8 + pub_r001346_13 * 2 + 404) & 127;
    if (stage_v_133 > 17) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_118 + pub_r001346_4 * 2 + 407) & 127;
    if (stage_v_134 > 24) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001346_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001346_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_2 + pub_r001346_9 * 2 + 416) & 127;
    if (stage_v_137 > 41) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001346_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001346_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001346_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001346_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_105 + pub_r001346_17 * 2 + 431) & 127;
    if (stage_v_142 > 36) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_102 + pub_r001346_3 * 2 + 434) & 127;
    if (stage_v_143 > 42) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001346_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_89 + pub_r001346_18 * 2 + 440) & 127;
    if (stage_v_145 > 26) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_53 + pub_r001346_2 * 2 + 443) & 127;
    if (stage_v_146 > 55) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001346_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001346_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_76 + pub_r001346_2 * 2 + 452) & 127;
    if (stage_v_149 > 34) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_112 + pub_r001346_19 * 2 + 455) & 127;
    if (stage_v_150 > 37) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001346_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_68 + pub_r001346_7 * 2 + 461) & 127;
    if (stage_v_152 > 16) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_7 + pub_r001346_11 * 2 + 464) & 127;
    if (stage_v_153 > 26) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_54 + pub_r001346_1 * 2 + 467) & 127;
    if (stage_v_154 > 56) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001346_8 + pub_r001346_9 * 2 + 470) & 127;
    if (stage_v_155 > 40) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001346_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001346_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_65 + pub_r001346_12 * 2 + 479) & 127;
    if (stage_v_158 > 41) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_42 + pub_r001346_12 * 2 + 482) & 127;
    if (stage_v_159 > 24) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001346_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_142 + pub_r001346_17 * 2 + 488) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_0 + pub_r001346_11 * 2 + 491) & 127;
    if (stage_v_162 > 31) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_137 + pub_r001346_1 * 2 + 494) & 127;
    if (stage_v_163 > 15) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_59 + pub_r001346_19 * 2 + 497) & 127;
    if (stage_v_164 > 23) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_137 + pub_r001346_1 * 2 + 500) & 127;
    if (stage_v_165 > 16) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001346_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001346_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_0 + pub_r001346_11 * 2 + 509) & 127;
    if (stage_v_168 > 58) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_6 + pub_r001346_18 * 2 + 512) & 127;
    if (stage_v_169 > 24) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001346_18 + pub_r001346_11 * 2 + 515) & 127;
    if (stage_v_170 > 50) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001346_3 + pub_r001346_14 * 2 + 518) & 127;
    if (stage_v_171 > 47) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_158 + pub_r001346_12 * 2 + 521) & 127;
    if (stage_v_172 > 55) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001346_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (helper_flow_0 + pub_r001346_19 * 2 + 527) & 127;
    if (stage_v_174 > 46) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001346_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (sec_r001346_16 + pub_r001346_7 * 2 + 533) & 127;
    if (stage_v_176 > 52) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (helper_flow_8 + pub_r001346_8 * 2 + 536) & 127;
    if (stage_v_177 > 27) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_107 + pub_r001346_1 * 2 + 539) & 127;
    if (stage_v_178 > 45) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001346_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001346_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_169 + pub_r001346_13 * 2 + 548) & 127;
    if (stage_v_181 > 52) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_32 + pub_r001346_8 * 2 + 551) & 127;
    if (stage_v_182 > 49) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_8 + pub_r001346_9 * 2 + 554) & 127;
    if (stage_v_183 > 36) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_2 + pub_r001346_1 * 2 + 557) & 127;
    if (stage_v_184 > 22) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001346_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_146 + pub_r001346_2 * 2 + 563) & 127;
    if (stage_v_186 > 17) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_168 + pub_r001346_0 * 2 + 566) & 127;
    if (stage_v_187 > 56) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_80 + pub_r001346_7 * 2 + 569) & 127;
    if (stage_v_188 > 44) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_94 + pub_r001346_8 * 2 + 572) & 127;
    if (stage_v_189 > 51) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_186 + pub_r001346_16 * 2 + 575) & 127;
    if (stage_v_190 > 37) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_127 + pub_r001346_2 * 2 + 578) & 127;
    if (stage_v_191 > 59) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_2 + pub_r001346_2 * 2 + 581) & 127;
    if (stage_v_192 > 53) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001346_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_6 + pub_r001346_17 * 2 + 587) & 127;
    if (stage_v_194 > 20) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_17 + pub_r001346_10 * 2 + 590) & 127;
    if (stage_v_195 > 38) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_77 + pub_r001346_0 * 2 + 593) & 127;
    if (stage_v_196 > 58) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r001346_11 + pub_r001346_4 * 2 + 596) & 127;
    if (stage_v_197 > 42) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_111 + pub_r001346_7 * 2 + 599) & 127;
    if (stage_v_198 > 30) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_50 + pub_r001346_8 * 2 + 602) & 127;
    if (stage_v_199 > 18) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_48 + pub_r001346_18 * 2 + 605) & 127;
    if (stage_v_200 > 33) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001346_10 + pub_r001346_9 * 2 + 608) & 127;
    if (stage_v_201 > 48) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_186 + pub_r001346_10 * 2 + 611) & 127;
    if (stage_v_202 > 43) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_132 + pub_r001346_15 * 2 + 614) & 127;
    if (stage_v_203 > 42) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_43 + pub_r001346_18 * 2 + 617) & 127;
    if (stage_v_204 > 35) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (helper_flow_6 + pub_r001346_3 * 2 + 620) & 127;
    if (stage_v_205 > 32) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_118 + pub_r001346_17 * 2 + 623) & 127;
    if (stage_v_206 > 30) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_45 + pub_r001346_12 * 2 + 626) & 127;
    if (stage_v_207 > 24) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_200 + pub_r001346_15 * 2 + 629) & 127;
    if (stage_v_208 > 46) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_43 + pub_r001346_3 * 2 + 632) & 127;
    if (stage_v_209 > 39) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001346_10 + pub_r001346_6 * 2 + 635) & 127;
    if (stage_v_210 > 15) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001346_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_81 + pub_r001346_13 * 2 + 641) & 127;
    if (stage_v_212 > 58) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (sec_r001346_10 + pub_r001346_1 * 2 + 644) & 127;
    if (stage_v_213 > 30) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_50 + pub_r001346_4 * 2 + 647) & 127;
    if (stage_v_214 > 43) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001346_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_168 + pub_r001346_0 * 2 + 653) & 127;
    if (stage_v_216 > 29) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_103 + pub_r001346_11 * 2 + 656) & 127;
    if (stage_v_217 > 28) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001346_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001346_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r001346_7 + pub_r001346_4 * 2 + 665) & 127;
    if (stage_v_220 > 30) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001346_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_216 + pub_r001346_14 * 2 + 671) & 127;
    if (stage_v_222 > 53) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_132 + pub_r001346_18 * 2 + 674) & 127;
    if (stage_v_223 > 48) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_29 + pub_r001346_6 * 2 + 677) & 127;
    if (stage_v_224 > 48) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_111 + pub_r001346_17 * 2 + 680) & 127;
    if (stage_v_225 > 50) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_94 + pub_r001346_5 * 2 + 683) & 127;
    if (stage_v_226 > 44) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001346_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_59 + pub_r001346_9 * 2 + 689) & 127;
    if (stage_v_228 > 28) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_168 + pub_r001346_15 * 2 + 692) & 127;
    if (stage_v_229 > 46) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_150 + pub_r001346_1 * 2 + 695) & 127;
    if (stage_v_230 > 47) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_213 + pub_r001346_10 * 2 + 698) & 127;
    if (stage_v_231 > 21) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001346_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001346_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_36 + pub_r001346_6 * 2 + 707) & 127;
    if (stage_v_234 > 30) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (helper_flow_0 + pub_r001346_7 * 2 + 710) & 127;
    if (stage_v_235 > 27) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_224 + pub_r001346_4 * 2 + 713) & 127;
    if (stage_v_236 > 30) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
