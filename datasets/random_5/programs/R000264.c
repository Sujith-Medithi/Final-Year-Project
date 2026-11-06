/*
 * Benchmark Program: R000264
 * Security Family: arithmetic_flow
 * Generator Seed: 526413
 * High Inputs: 22 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000264_6413_0 {
    short gain;
    int channels;
    short rms;
    int envelope;
    int buffer[3];
};

struct FilterState_R000264_6413_1 {
    unsigned char damping;
    unsigned char cutoff;
    unsigned char gain_db;
    int buffer[3];
};

struct CipherContext_R000264_6413_2 {
    int tag;
    short counter;
    short nonce;
    unsigned char flags;
    int buffer[3];
};

struct MatrixBlock_R000264_6413_3 {
    int trace;
    unsigned char stride;
    int density;
    int dim;
    unsigned char scale;
    unsigned char determinant;
    int buffer[3];
};

union PacketPayload_R000264_6413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000264_6413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000264_6413_0(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_95 = (aux + st.buffer[1]) & 3;
    switch (segment_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_69 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_69 > 49) {
        acc = (acc + scale_69 * 2 + 5) & 127;
        aux ^= (scale_69 & 15);
    } else {
        acc = (acc - scale_69 + 11) & 127;
        aux += 3;
    }
    int phase_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000264_6413_1(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000264_6413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_97 = local_arr[aux % 3];
    acc = (acc + margin_97 * 2) & 127;
    int stride_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000264_6413_2(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_39) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_24 = local_arr[aux % 3];
    acc = (acc + weight_24 * 2) & 127;
    int quantum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_82 > 42) {
        acc = (acc + quantum_82 * 2 + 5) & 127;
        aux ^= (quantum_82 & 15);
    } else {
        acc = (acc - quantum_82 + 11) & 127;
        aux += 3;
    }
    int metric_66 = (aux + st.buffer[1]) & 3;
    switch (metric_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_3(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_62 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_62 > 16) {
        acc = (acc + tracker_62 * 2 + 5) & 127;
        aux ^= (tracker_62 & 15);
    } else {
        acc = (acc - tracker_62 + 11) & 127;
        aux += 3;
    }
    int parity_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_65 = local_arr[aux % 3];
    acc = (acc + tracker_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_4(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_24 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_24 > 24) {
        acc = (acc + phase_24 * 2 + 5) & 127;
        aux ^= (phase_24 & 15);
    } else {
        acc = (acc - phase_24 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_68 = local_arr[aux % 3];
    acc = (acc + residue_68 * 2) & 127;
    int margin_16 = (aux + st.buffer[1]) & 3;
    switch (margin_16) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_5(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int sample_44 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_44 > 46) {
        acc = (acc + sample_44 * 2 + 5) & 127;
        aux ^= (sample_44 & 15);
    } else {
        acc = (acc - sample_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_50 = (aux + st.buffer[1]) & 3;
    switch (index_reg_50) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_56 = local_arr[aux % 3];
    acc = (acc + factor_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000264_6413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_42 = local_arr[aux % 3];
    acc = (acc + cursor_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_7(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000264_6413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_65) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_62 = (aux + st.buffer[1]) & 3;
    switch (tracker_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_58 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_58 > 44) {
        acc = (acc + accumulator_58 * 2 + 5) & 127;
        aux ^= (accumulator_58 & 15);
    } else {
        acc = (acc - accumulator_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_9(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_83 = (aux + st.buffer[1]) & 3;
    switch (tracker_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_85 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_85 > 23) {
        acc = (acc + segment_85 * 2 + 5) & 127;
        aux ^= (segment_85 & 15);
    } else {
        acc = (acc - segment_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_44 = local_arr[aux % 3];
    acc = (acc + parity_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_10(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_51) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_11(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000264_6413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_47 = (aux + st.buffer[1]) & 3;
    switch (segment_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_67 = local_arr[aux % 3];
    acc = (acc + threshold_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_12(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_11 = (aux + st.buffer[1]) & 3;
    switch (mask_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000264_6413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_26) & 63;
    acc ^= aux;
    int index_reg_11 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_11 > 38) {
        acc = (acc + index_reg_11 * 2 + 5) & 127;
        aux ^= (index_reg_11 & 15);
    } else {
        acc = (acc - index_reg_11 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_65 = local_arr[aux % 3];
    acc = (acc + checksum_65 * 2) & 127;
    int cursor_97 = (aux + st.buffer[1]) & 3;
    switch (cursor_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_14(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_36 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_36 > 29) {
        acc = (acc + pivot_36 * 2 + 5) & 127;
        aux ^= (pivot_36 & 15);
    } else {
        acc = (acc - pivot_36 + 11) & 127;
        aux += 3;
    }
    int window_89 = (aux + st.buffer[1]) & 3;
    switch (window_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_15(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_35 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_35 > 45) {
        acc = (acc + threshold_35 * 2 + 5) & 127;
        aux ^= (threshold_35 & 15);
    } else {
        acc = (acc - threshold_35 + 11) & 127;
        aux += 3;
    }
    int anchor_62 = (aux + st.buffer[1]) & 3;
    switch (anchor_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_66 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_66 > 33) {
        acc = (acc + damping_66 * 2 + 5) & 127;
        aux ^= (damping_66 & 15);
    } else {
        acc = (acc - damping_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_97 = local_arr[aux % 3];
    acc = (acc + parity_97 * 2) & 127;
    int vector_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_38) & 63;
    acc ^= aux;
    int anchor_64 = (aux + st.buffer[1]) & 3;
    switch (anchor_64) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_17(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_31 = local_arr[aux % 3];
    acc = (acc + offset_31 * 2) & 127;
    int pivot_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_41) & 63;
    acc ^= aux;
    int tally_60 = (aux + st.buffer[1]) & 3;
    switch (tally_60) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_18(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000264_6413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_89 = (aux + st.buffer[1]) & 3;
    switch (phase_89) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_68 = local_arr[aux % 3];
    acc = (acc + coefficient_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_88 = local_arr[aux % 3];
    acc = (acc + coefficient_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_97) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000264_6413_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000264_6413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_78 = (aux + st.buffer[1]) & 3;
    switch (offset_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_59 = (st.buffer[0] * 3 + aux) & 63;
    if (window_59 > 26) {
        acc = (acc + window_59 * 2 + 5) & 127;
        aux ^= (window_59 & 15);
    } else {
        acc = (acc - window_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000264_6413_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000264_6413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int phase_61 = local_arr[aux % 3];
    acc = (acc + phase_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_47 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_47 > 19) {
        acc = (acc + anchor_47 * 2 + 5) & 127;
        aux ^= (anchor_47 & 15);
    } else {
        acc = (acc - anchor_47 + 11) & 127;
        aux += 3;
    }
    int tally_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000264_6413_23(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000264_6413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_76 = (aux + st.buffer[1]) & 3;
    switch (segment_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_27 = local_arr[aux % 3];
    acc = (acc + checksum_27 * 2) & 127;
    int anchor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_35 > 17) {
        acc = (acc + anchor_35 * 2 + 5) & 127;
        aux ^= (anchor_35 & 15);
    } else {
        acc = (acc - anchor_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000264_0;
    int sec_r000264_1;
    int sec_r000264_2;
    int sec_r000264_3;
    int sec_r000264_4;
    int sec_r000264_5;
    int sec_r000264_6;
    int sec_r000264_7;
    int sec_r000264_8;
    int sec_r000264_9;
    int sec_r000264_10;
    int sec_r000264_11;
    int sec_r000264_12;
    int sec_r000264_13;
    int sec_r000264_14;
    int sec_r000264_15;
    int sec_r000264_16;
    int sec_r000264_17;
    int sec_r000264_18;
    int sec_r000264_19;
    int sec_r000264_20;
    int sec_r000264_21;
    int pub_r000264_0;
    int pub_r000264_1;
    int pub_r000264_2;
    int pub_r000264_3;
    int pub_r000264_4;
    int pub_r000264_5;
    int pub_r000264_6;
    int pub_r000264_7;
    int pub_r000264_8;
    int pub_r000264_9;
    int pub_r000264_10;
    int pub_r000264_11;
    int pub_r000264_12;
    int pub_r000264_13;
    int pub_r000264_14;
    int pub_r000264_15;
    int pub_r000264_16;
    int pub_r000264_17;
    int pub_r000264_18;
    int pub_r000264_19;
    int pub_r000264_20;
    int pub_r000264_21;
    int pub_r000264_22;
    int pub_r000264_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000264_0 >= -100 && pub_r000264_0 <= 100);
    __CPROVER_assume(pub_r000264_1 >= -100 && pub_r000264_1 <= 100);
    __CPROVER_assume(pub_r000264_2 >= -100 && pub_r000264_2 <= 100);
    __CPROVER_assume(pub_r000264_3 >= -100 && pub_r000264_3 <= 100);
    __CPROVER_assume(pub_r000264_4 >= -100 && pub_r000264_4 <= 100);
    __CPROVER_assume(pub_r000264_5 >= -100 && pub_r000264_5 <= 100);
    __CPROVER_assume(pub_r000264_6 >= -100 && pub_r000264_6 <= 100);
    __CPROVER_assume(pub_r000264_7 >= -100 && pub_r000264_7 <= 100);
    __CPROVER_assume(pub_r000264_8 >= -100 && pub_r000264_8 <= 100);
    __CPROVER_assume(pub_r000264_9 >= -100 && pub_r000264_9 <= 100);
    __CPROVER_assume(pub_r000264_10 >= -100 && pub_r000264_10 <= 100);
    __CPROVER_assume(pub_r000264_11 >= -100 && pub_r000264_11 <= 100);
    __CPROVER_assume(pub_r000264_12 >= -100 && pub_r000264_12 <= 100);
    __CPROVER_assume(pub_r000264_13 >= -100 && pub_r000264_13 <= 100);
    __CPROVER_assume(pub_r000264_14 >= -100 && pub_r000264_14 <= 100);
    __CPROVER_assume(pub_r000264_15 >= -100 && pub_r000264_15 <= 100);
    __CPROVER_assume(pub_r000264_16 >= -100 && pub_r000264_16 <= 100);
    __CPROVER_assume(pub_r000264_17 >= -100 && pub_r000264_17 <= 100);
    __CPROVER_assume(pub_r000264_18 >= -100 && pub_r000264_18 <= 100);
    __CPROVER_assume(pub_r000264_19 >= -100 && pub_r000264_19 <= 100);
    __CPROVER_assume(pub_r000264_20 >= -100 && pub_r000264_20 <= 100);
    __CPROVER_assume(pub_r000264_21 >= -100 && pub_r000264_21 <= 100);
    __CPROVER_assume(pub_r000264_22 >= -100 && pub_r000264_22 <= 100);
    __CPROVER_assume(pub_r000264_23 >= -100 && pub_r000264_23 <= 100);
    __CPROVER_assume(sec_r000264_0 >= 0 && sec_r000264_0 <= 255);
    __CPROVER_assume(sec_r000264_1 >= 0 && sec_r000264_1 <= 255);
    __CPROVER_assume(sec_r000264_2 >= 0 && sec_r000264_2 <= 255);
    __CPROVER_assume(sec_r000264_3 >= 0 && sec_r000264_3 <= 255);
    __CPROVER_assume(sec_r000264_4 >= 0 && sec_r000264_4 <= 255);
    __CPROVER_assume(sec_r000264_5 >= 0 && sec_r000264_5 <= 255);
    __CPROVER_assume(sec_r000264_6 >= 0 && sec_r000264_6 <= 255);
    __CPROVER_assume(sec_r000264_7 >= 0 && sec_r000264_7 <= 255);
    __CPROVER_assume(sec_r000264_8 >= 0 && sec_r000264_8 <= 255);
    __CPROVER_assume(sec_r000264_9 >= 0 && sec_r000264_9 <= 255);
    __CPROVER_assume(sec_r000264_10 >= 0 && sec_r000264_10 <= 255);
    __CPROVER_assume(sec_r000264_11 >= 0 && sec_r000264_11 <= 255);
    __CPROVER_assume(sec_r000264_12 >= 0 && sec_r000264_12 <= 255);
    __CPROVER_assume(sec_r000264_13 >= 0 && sec_r000264_13 <= 255);
    __CPROVER_assume(sec_r000264_14 >= 0 && sec_r000264_14 <= 255);
    __CPROVER_assume(sec_r000264_15 >= 0 && sec_r000264_15 <= 255);
    __CPROVER_assume(sec_r000264_16 >= 0 && sec_r000264_16 <= 255);
    __CPROVER_assume(sec_r000264_17 >= 0 && sec_r000264_17 <= 255);
    __CPROVER_assume(sec_r000264_18 >= 0 && sec_r000264_18 <= 255);
    __CPROVER_assume(sec_r000264_19 >= 0 && sec_r000264_19 <= 255);
    __CPROVER_assume(sec_r000264_20 >= 0 && sec_r000264_20 <= 255);
    __CPROVER_assume(sec_r000264_21 >= 0 && sec_r000264_21 <= 255);

    struct AudioFrame_R000264_6413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000264_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000264_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000264_0 + 7) & 15;
    struct FilterState_R000264_6413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000264_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000264_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000264_0 + 9) & 15;
    struct CipherContext_R000264_6413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000264_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000264_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000264_0 + 11) & 15;
    struct MatrixBlock_R000264_6413_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000264_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000264_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000264_0 + 13) & 15;

    union PacketPayload_R000264_6413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 24) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 39) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 30) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 45) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 26) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 41) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 16) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 31) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 42) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 21) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 36) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 53) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 22) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 37) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 21) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 36) {
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
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_22 + 35) & 127;
    sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_58 * 3) + (sec_r000264_2 * 2) - pub_r000264_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_59 * 3) + (sec_r000264_19 * 2) - pub_r000264_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_59 * 3) + (sec_r000264_15 * 2) - pub_r000264_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_59 * 3) + (sec_r000264_17 * 2) - pub_r000264_13 + 16) & 127;
    sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000264_5 * 3) + (sec_r000264_5 * 2) - pub_r000264_21 + 8) & 127;
    sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_61 * 3) + (sec_r000264_18 * 2) - pub_r000264_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_61 * 3) + (sec_r000264_11 * 2) - pub_r000264_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_60 * 3) + (sec_r000264_3 * 2) - pub_r000264_19 + 6) & 127;
    sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_65 * 3) + (sec_r000264_2 * 2) - pub_r000264_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_63 * 3) + (sec_r000264_18 * 2) - pub_r000264_21 + 7) & 127;
    sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000264_16 * 3) + (sec_r000264_16 * 2) - pub_r000264_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_67 * 3) + (sec_r000264_15 * 2) - pub_r000264_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_70 * 3) + (sec_r000264_12 * 2) - pub_r000264_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_73 * 3) + (sec_r000264_15 * 2) - pub_r000264_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r000264_7 * 3) + (sec_r000264_7 * 2) - pub_r000264_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_69 * 3) + (sec_r000264_12 * 2) - pub_r000264_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_59 * 3) + (sec_r000264_11 * 2) - pub_r000264_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_68 * 3) + (sec_r000264_17 * 2) - pub_r000264_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000264_19 * 3) + (sec_r000264_19 * 2) - pub_r000264_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_80 * 3) + (sec_r000264_5 * 2) - pub_r000264_17 + 10) & 127;
    sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_59 * 3) + (sec_r000264_1 * 2) - pub_r000264_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_73 * 3) + (sec_r000264_15 * 2) - pub_r000264_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_81 * 3) + (sec_r000264_18 * 2) - pub_r000264_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_62 * 3) + (sec_r000264_4 * 2) - pub_r000264_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_61 * 3) + (sec_r000264_3 * 2) - pub_r000264_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000264_10 * 3) + (sec_r000264_10 * 2) - pub_r000264_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_82 * 3) + (sec_r000264_1 * 2) - pub_r000264_22 + 14) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000264_4 * 3) + (sec_r000264_4 * 2) - pub_r000264_19 + 6) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_87 * 3) + (sec_r000264_2 * 2) - pub_r000264_18 + 31) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000264_12 * 3) + (sec_r000264_12 * 2) - pub_r000264_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_63 * 3) + (sec_r000264_13 * 2) - pub_r000264_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_82 * 3) + (sec_r000264_4 * 2) - pub_r000264_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_61 * 3) + (sec_r000264_15 * 2) - pub_r000264_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_62 * 3) + (sec_r000264_4 * 2) - pub_r000264_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_21 + 21) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_85 * 3) + (sec_r000264_19 * 2) - pub_r000264_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000264_2 * 3) + (sec_r000264_2 * 2) - pub_r000264_22 + 5) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_75 * 3) + (sec_r000264_14 * 2) - pub_r000264_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_84 * 3) + (sec_r000264_20 * 2) - pub_r000264_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_86 * 3) + (sec_r000264_5 * 2) - pub_r000264_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_79 * 3) + (sec_r000264_12 * 2) - pub_r000264_18 + 12) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_105 * 3) + (sec_r000264_0 * 2) - pub_r000264_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_106 * 3) + (sec_r000264_8 * 2) - pub_r000264_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_89 * 3) + (sec_r000264_13 * 2) - pub_r000264_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_107 * 3) + (sec_r000264_2 * 2) - pub_r000264_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_95 * 3) + (sec_r000264_7 * 2) - pub_r000264_21 + 17) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_109 * 3) + (sec_r000264_17 * 2) - pub_r000264_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000264_6 * 3) + (sec_r000264_6 * 2) - pub_r000264_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_74 * 3) + (sec_r000264_18 * 2) - pub_r000264_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_108 * 3) + (sec_r000264_11 * 2) - pub_r000264_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_114 * 3) + (sec_r000264_0 * 2) - pub_r000264_20 + 21) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_63 * 3) + (sec_r000264_3 * 2) - pub_r000264_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_91 * 3) + (sec_r000264_17 * 2) - pub_r000264_18 + 24) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_118 * 3) + (sec_r000264_19 * 2) - pub_r000264_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_65 * 3) + (sec_r000264_3 * 2) - pub_r000264_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_107 * 3) + (sec_r000264_17 * 2) - pub_r000264_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000264_0 * 3) + (sec_r000264_0 * 2) - pub_r000264_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_120 * 3) + (sec_r000264_13 * 2) - pub_r000264_23 + 4) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_84 * 3) + (sec_r000264_14 * 2) - pub_r000264_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000264_3 * 3) + (sec_r000264_3 * 2) - pub_r000264_22 + 27) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_123 * 3) + (sec_r000264_17 * 2) - pub_r000264_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_112 * 3) + (sec_r000264_15 * 2) - pub_r000264_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_85 * 3) + (sec_r000264_0 * 2) - pub_r000264_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_82 * 3) + (sec_r000264_15 * 2) - pub_r000264_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000264_10 * 3) + (sec_r000264_10 * 2) - pub_r000264_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000264_19 * 3) + (sec_r000264_19 * 2) - pub_r000264_8 + 34) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_127 * 3) + (sec_r000264_17 * 2) - pub_r000264_21 + 20) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_82 * 3) + (sec_r000264_3 * 2) - pub_r000264_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_119 * 3) + (sec_r000264_8 * 2) - pub_r000264_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r000264_19 * 3) + (sec_r000264_19 * 2) - pub_r000264_21 + 25) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_108 * 3) + (sec_r000264_13 * 2) - pub_r000264_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_137 * 3) + (sec_r000264_7 * 2) - pub_r000264_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_96 * 3) + (sec_r000264_16 * 2) - pub_r000264_22 + 8) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_118 * 3) + (sec_r000264_4 * 2) - pub_r000264_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_113 * 3) + (sec_r000264_7 * 2) - pub_r000264_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000264_2 * 3) + (sec_r000264_2 * 2) - pub_r000264_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000264_5 * 3) + (sec_r000264_5 * 2) - pub_r000264_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_20 + 5) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000264_17 * 3) + (sec_r000264_17 * 2) - pub_r000264_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_79 * 3) + (sec_r000264_8 * 2) - pub_r000264_18 + 31) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_107 * 3) + (sec_r000264_12 * 2) - pub_r000264_22 + 36) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_140 * 3) + (sec_r000264_12 * 2) - pub_r000264_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_135 * 3) + (sec_r000264_10 * 2) - pub_r000264_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_95 * 3) + (sec_r000264_8 * 2) - pub_r000264_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_110 * 3) + (sec_r000264_18 * 2) - pub_r000264_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r000264_12 * 3) + (sec_r000264_12 * 2) - pub_r000264_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_137 * 3) + (sec_r000264_16 * 2) - pub_r000264_22 + 17) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_64 * 3) + (sec_r000264_4 * 2) - pub_r000264_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_136 * 3) + (sec_r000264_1 * 2) - pub_r000264_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_98 * 3) + (sec_r000264_0 * 2) - pub_r000264_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r000264_21 * 3) + (sec_r000264_21 * 2) - pub_r000264_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000264_10 * 3) + (sec_r000264_10 * 2) - pub_r000264_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_132 * 3) + (sec_r000264_6 * 2) - pub_r000264_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_68 * 3) + (sec_r000264_10 * 2) - pub_r000264_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_60 * 3) + (sec_r000264_10 * 2) - pub_r000264_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000264_17 * 3) + (sec_r000264_17 * 2) - pub_r000264_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_82 * 3) + (sec_r000264_16 * 2) - pub_r000264_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000264_17 * 3) + (sec_r000264_17 * 2) - pub_r000264_23 + 20) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_165 * 3) + (sec_r000264_16 * 2) - pub_r000264_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r000264_19 * 3) + (sec_r000264_19 * 2) - pub_r000264_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_161 * 3) + (sec_r000264_10 * 2) - pub_r000264_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000264_12 * 3) + (sec_r000264_12 * 2) - pub_r000264_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000264_12 * 3) + (sec_r000264_12 * 2) - pub_r000264_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000264_12 * 3) + (sec_r000264_12 * 2) - pub_r000264_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_94 * 3) + (sec_r000264_20 * 2) - pub_r000264_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r000264_8 * 3) + (sec_r000264_8 * 2) - pub_r000264_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000264_10 * 3) + (sec_r000264_10 * 2) - pub_r000264_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_133 * 3) + (sec_r000264_21 * 2) - pub_r000264_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_75 * 3) + (sec_r000264_15 * 2) - pub_r000264_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000264_18 * 3) + (sec_r000264_18 * 2) - pub_r000264_20 + 18) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_82 * 3) + (sec_r000264_1 * 2) - pub_r000264_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000264_3 * 3) + (sec_r000264_3 * 2) - pub_r000264_22 + 28) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_58 * 3) + (sec_r000264_14 * 2) - pub_r000264_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_66 * 3) + (sec_r000264_11 * 2) - pub_r000264_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_149 * 3) + (sec_r000264_5 * 2) - pub_r000264_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000264_16 * 3) + (sec_r000264_16 * 2) - pub_r000264_18 + 22) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_68 * 3) + (sec_r000264_2 * 2) - pub_r000264_19 + 23) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_177 * 3) + (sec_r000264_20 * 2) - pub_r000264_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_94 * 3) + (sec_r000264_21 * 2) - pub_r000264_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_160 * 3) + (sec_r000264_15 * 2) - pub_r000264_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r000264_0 * 3) + (sec_r000264_0 * 2) - pub_r000264_20 + 26) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_153 * 3) + (sec_r000264_21 * 2) - pub_r000264_22 + 33) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_160 * 3) + (sec_r000264_18 * 2) - pub_r000264_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_159 * 3) + (sec_r000264_9 * 2) - pub_r000264_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_94 * 3) + (sec_r000264_13 * 2) - pub_r000264_0 + 15) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_77 * 3) + (sec_r000264_14 * 2) - pub_r000264_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000264_8 * 3) + (sec_r000264_8 * 2) - pub_r000264_22 + 16) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r000264_16 * 3) + (sec_r000264_16 * 2) - pub_r000264_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_200 * 3) + (sec_r000264_0 * 2) - pub_r000264_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000264_9 * 3) + (sec_r000264_9 * 2) - pub_r000264_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_105 * 3) + (sec_r000264_17 * 2) - pub_r000264_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_124 * 3) + (sec_r000264_16 * 2) - pub_r000264_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_176 * 3) + (sec_r000264_4 * 2) - pub_r000264_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_163 * 3) + (sec_r000264_5 * 2) - pub_r000264_23 + 34) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_127 * 3) + (sec_r000264_10 * 2) - pub_r000264_21 + 28) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r000264_7 * 3) + (sec_r000264_7 * 2) - pub_r000264_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_206 * 3) + (sec_r000264_10 * 2) - pub_r000264_19 + 34) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r000264_10 * 3) + (sec_r000264_10 * 2) - pub_r000264_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_87 * 3) + (sec_r000264_20 * 2) - pub_r000264_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000264_8 * 3) + (sec_r000264_8 * 2) - pub_r000264_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r000264_2 * 3) + (sec_r000264_2 * 2) - pub_r000264_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_75 * 3) + (sec_r000264_2 * 2) - pub_r000264_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_114 * 3) + (sec_r000264_2 * 2) - pub_r000264_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r000264_19 * 3) + (sec_r000264_19 * 2) - pub_r000264_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r000264_20 * 3) + (sec_r000264_20 * 2) - pub_r000264_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r000264_8 * 3) + (sec_r000264_8 * 2) - pub_r000264_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_73 * 3) + (sec_r000264_6 * 2) - pub_r000264_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_149 * 3) + (sec_r000264_8 * 2) - pub_r000264_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_218 * 3) + (sec_r000264_11 * 2) - pub_r000264_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_201 * 3) + (sec_r000264_0 * 2) - pub_r000264_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r000264_20 * 3) + (sec_r000264_20 * 2) - pub_r000264_20 + 28) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_146 * 3) + (sec_r000264_13 * 2) - pub_r000264_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_101 * 3) + (sec_r000264_0 * 2) - pub_r000264_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_195 * 3) + (sec_r000264_14 * 2) - pub_r000264_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_222 * 3) + (sec_r000264_13 * 2) - pub_r000264_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_100 * 3) + (sec_r000264_16 * 2) - pub_r000264_23 + 6) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_80 * 3) + (sec_r000264_15 * 2) - pub_r000264_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r000264_2 * 3) + (sec_r000264_2 * 2) - pub_r000264_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000264_0 * 3) + (sec_r000264_0 * 2) - pub_r000264_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_198 * 3) + (sec_r000264_9 * 2) - pub_r000264_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_163 * 3) + (sec_r000264_21 * 2) - pub_r000264_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_193 * 3) + (sec_r000264_6 * 2) - pub_r000264_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_193 * 3) + (sec_r000264_16 * 2) - pub_r000264_1 + 12) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_202 * 3) + (sec_r000264_0 * 2) - pub_r000264_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_233 * 3) + (sec_r000264_7 * 2) - pub_r000264_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r000264_4 * 3) + (sec_r000264_4 * 2) - pub_r000264_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000264_6 * 3) + (sec_r000264_6 * 2) - pub_r000264_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_147 * 3) + (sec_r000264_11 * 2) - pub_r000264_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r000264_17 * 3) + (sec_r000264_17 * 2) - pub_r000264_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_146 * 3) + (sec_r000264_1 * 2) - pub_r000264_5 + 31) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((sec_r000264_11 * 3) + (sec_r000264_11 * 2) - pub_r000264_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_199 * 3) + (sec_r000264_5 * 2) - pub_r000264_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_197 * 3) + (sec_r000264_18 * 2) - pub_r000264_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_195 * 3) + (sec_r000264_1 * 2) - pub_r000264_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_179 * 3) + (sec_r000264_7 * 2) - pub_r000264_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_64 * 3) + (sec_r000264_9 * 2) - pub_r000264_22 + 12) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_93 * 3) + (sec_r000264_5 * 2) - pub_r000264_19 + 20) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_88 * 3) + (sec_r000264_12 * 2) - pub_r000264_6 + 33) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_92 * 3) + (sec_r000264_7 * 2) - pub_r000264_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_198 * 3) + (sec_r000264_3 * 2) - pub_r000264_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_145 * 3) + (sec_r000264_21 * 2) - pub_r000264_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r000264_16 * 3) + (sec_r000264_16 * 2) - pub_r000264_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_248 * 3) + (sec_r000264_13 * 2) - pub_r000264_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r000264_3 * 3) + (sec_r000264_3 * 2) - pub_r000264_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_165 * 3) + (sec_r000264_18 * 2) - pub_r000264_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_127 * 3) + (sec_r000264_11 * 2) - pub_r000264_18 + 32) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_154 * 3) + (sec_r000264_14 * 2) - pub_r000264_4 + 18) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_244 * 3) + (sec_r000264_20 * 2) - pub_r000264_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_151 * 3) + (sec_r000264_6 * 2) - pub_r000264_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r000264_15 * 3) + (sec_r000264_15 * 2) - pub_r000264_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((sec_r000264_9 * 3) + (sec_r000264_9 * 2) - pub_r000264_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((sec_r000264_9 * 3) + (sec_r000264_9 * 2) - pub_r000264_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_60 * 3) + (sec_r000264_17 * 2) - pub_r000264_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_116 * 3) + (sec_r000264_12 * 2) - pub_r000264_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_98 * 3) + (sec_r000264_0 * 2) - pub_r000264_22 + 5) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r000264_9 * 3) + (sec_r000264_9 * 2) - pub_r000264_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_159 * 3) + (sec_r000264_9 * 2) - pub_r000264_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_122 * 3) + (sec_r000264_19 * 2) - pub_r000264_18 + 4) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_179 * 3) + (sec_r000264_15 * 2) - pub_r000264_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_271 * 3) + (sec_r000264_11 * 2) - pub_r000264_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((sec_r000264_11 * 3) + (sec_r000264_11 * 2) - pub_r000264_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_167 * 3) + (sec_r000264_5 * 2) - pub_r000264_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r000264_3 * 3) + (sec_r000264_3 * 2) - pub_r000264_20 + 36) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r000264_4 * 3) + (sec_r000264_4 * 2) - pub_r000264_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_154 * 3) + (sec_r000264_4 * 2) - pub_r000264_20 + 12) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_243 * 3) + (sec_r000264_17 * 2) - pub_r000264_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_128 * 3) + (sec_r000264_9 * 2) - pub_r000264_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_102 * 3) + (sec_r000264_21 * 2) - pub_r000264_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((sec_r000264_13 * 3) + (sec_r000264_13 * 2) - pub_r000264_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000264_20 * 3) + (sec_r000264_20 * 2) - pub_r000264_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000264_7 * 3) + (sec_r000264_7 * 2) - pub_r000264_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r000264_16 * 3) + (sec_r000264_16 * 2) - pub_r000264_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r000264_20 * 3) + (sec_r000264_20 * 2) - pub_r000264_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r000264_6 * 3) + (sec_r000264_6 * 2) - pub_r000264_13 + 28) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_111 * 3) + (sec_r000264_2 * 2) - pub_r000264_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r000264_5 * 3) + (sec_r000264_5 * 2) - pub_r000264_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_202 * 3) + (sec_r000264_20 * 2) - pub_r000264_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r000264_1 * 3) + (sec_r000264_1 * 2) - pub_r000264_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_249 * 3) + (sec_r000264_13 * 2) - pub_r000264_22 + 30) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_296 * 3) + (sec_r000264_16 * 2) - pub_r000264_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((sec_r000264_0 * 3) + (sec_r000264_0 * 2) - pub_r000264_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_108 * 3) + (sec_r000264_20 * 2) - pub_r000264_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_153 * 3) + (sec_r000264_16 * 2) - pub_r000264_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_200 * 3) + (sec_r000264_0 * 2) - pub_r000264_20 + 12) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_72 * 3) + (sec_r000264_20 * 2) - pub_r000264_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_127 * 3) + (sec_r000264_2 * 2) - pub_r000264_20 + 24) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_162 * 3) + (sec_r000264_18 * 2) - pub_r000264_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_81 * 3) + (sec_r000264_11 * 2) - pub_r000264_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_137 * 3) + (sec_r000264_20 * 2) - pub_r000264_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_130 * 3) + (sec_r000264_9 * 2) - pub_r000264_20 + 37) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_279 * 3) + (sec_r000264_21 * 2) - pub_r000264_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
