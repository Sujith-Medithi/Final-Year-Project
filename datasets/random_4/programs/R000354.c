/*
 * Benchmark Program: R000354
 * Family: arithmetic_flow
 * Generator Seed: 435413
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000354_5413_0 {
    int peak;
    int channels;
    unsigned char gain;
    int sample_rate;
    short envelope;
    int buffer[3];
};

struct CipherContext_R000354_5413_1 {
    int tag;
    short counter;
    int flags;
    int nonce;
    int iv;
    unsigned char round_key;
    int buffer[3];
};

struct MatrixBlock_R000354_5413_2 {
    int dim;
    short density;
    int stride;
    short determinant;
    int buffer[3];
};

struct FilterState_R000354_5413_3 {
    int damping;
    unsigned char prev_in;
    int gain_db;
    int cutoff;
    unsigned char mode;
    unsigned char prev_out;
    int buffer[3];
};

union ColorPixel_R000354_5413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000354_5413_0(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int index_reg_71 = local_arr[aux % 3];
    acc = (acc + index_reg_71 * 2) & 127;
    int phase_18 = (aux + st.buffer[1]) & 3;
    switch (phase_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_36) & 63;
    acc ^= aux;
    int quantum_69 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_69 = (quantum_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_1(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_32 = (aux + st.buffer[1]) & 3;
    switch (bound_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_95 > 31) {
        acc = (acc + quotient_95 * 2 + 5) & 127;
        aux ^= (quotient_95 & 15);
    } else {
        acc = (acc - quotient_95 + 11) & 127;
        aux += 3;
    }
    int coefficient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000354_5413_2(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_21 = (aux + st.buffer[1]) & 3;
    switch (mask_21) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_88 = local_arr[aux % 3];
    acc = (acc + segment_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000354_5413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000354_5413_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_16 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_16 > 45) {
        acc = (acc + parity_16 * 2 + 5) & 127;
        aux ^= (parity_16 & 15);
    } else {
        acc = (acc - parity_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_97 = local_arr[aux % 3];
    acc = (acc + quantum_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000354_5413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_16 = (aux + st.buffer[1]) & 3;
    switch (bound_16) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_48 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_48 = (quotient_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int damping_21 = 0;
    for (int k = 0; k < 3; k++) {
        damping_21 = (damping_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_21) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_10 = local_arr[aux % 3];
    acc = (acc + scale_10 * 2) & 127;
    int damping_85 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_85 > 18) {
        acc = (acc + damping_85 * 2 + 5) & 127;
        aux ^= (damping_85 & 15);
    } else {
        acc = (acc - damping_85 + 11) & 127;
        aux += 3;
    }
    int metric_73 = (aux + st.buffer[1]) & 3;
    switch (metric_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int metric_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_20) & 63;
    acc ^= aux;
    int checksum_86 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_86 = (checksum_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_86) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_43 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_43 > 39) {
        acc = (acc + offset_43 * 2 + 5) & 127;
        aux ^= (offset_43 & 15);
    } else {
        acc = (acc - offset_43 + 11) & 127;
        aux += 3;
    }
    int window_50 = (aux + st.buffer[1]) & 3;
    switch (window_50) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_97 = 0;
    for (int k = 0; k < 3; k++) {
        phase_97 = (phase_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_97) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_9(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_97) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_97 = local_arr[aux % 3];
    acc = (acc + mask_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_10(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000354_5413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int coefficient_46 = local_arr[aux % 3];
    acc = (acc + coefficient_46 * 2) & 127;
    int anchor_54 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_54 = (anchor_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_11(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_80) & 63;
    acc ^= aux;
    int residue_93 = (aux + st.buffer[1]) & 3;
    switch (residue_93) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_12(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_54 = local_arr[aux % 3];
    acc = (acc + checksum_54 * 2) & 127;
    int window_61 = 0;
    for (int k = 0; k < 2; k++) {
        window_61 = (window_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int offset_92 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_92 > 46) {
        acc = (acc + offset_92 * 2 + 5) & 127;
        aux ^= (offset_92 & 15);
    } else {
        acc = (acc - offset_92 + 11) & 127;
        aux += 3;
    }
    int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000354_5413_14(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int metric_98 = local_arr[aux % 3];
    acc = (acc + metric_98 * 2) & 127;
    int factor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_97 > 14) {
        acc = (acc + factor_97 * 2 + 5) & 127;
        aux ^= (factor_97 & 15);
    } else {
        acc = (acc - factor_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_25 = local_arr[aux % 3];
    acc = (acc + sample_25 * 2) & 127;
    int phase_27 = (aux + st.buffer[1]) & 3;
    switch (phase_27) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_16(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int damping_23 = local_arr[aux % 3];
    acc = (acc + damping_23 * 2) & 127;
    int segment_86 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_86 > 29) {
        acc = (acc + segment_86 * 2 + 5) & 127;
        aux ^= (segment_86 & 15);
    } else {
        acc = (acc - segment_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_17(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int scale_98 = local_arr[aux % 3];
    acc = (acc + scale_98 * 2) & 127;
    int mask_78 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_78 > 14) {
        acc = (acc + mask_78 * 2 + 5) & 127;
        aux ^= (mask_78 & 15);
    } else {
        acc = (acc - mask_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int margin_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_18 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_18 > 44) {
        acc = (acc + coefficient_18 * 2 + 5) & 127;
        aux ^= (coefficient_18 & 15);
    } else {
        acc = (acc - coefficient_18 + 11) & 127;
        aux += 3;
    }
    int segment_26 = (aux + st.buffer[1]) & 3;
    switch (segment_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_25 = (aux + st.buffer[1]) & 3;
    switch (threshold_25) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_45 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_45 > 30) {
        acc = (acc + metric_45 * 2 + 5) & 127;
        aux ^= (metric_45 & 15);
    } else {
        acc = (acc - metric_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000354_5413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_40 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_40 = (cursor_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_40) & 127;
    }
    int quantum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_63) & 63;
    acc ^= aux;
    int scale_25 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_25 > 30) {
        acc = (acc + scale_25 * 2 + 5) & 127;
        aux ^= (scale_25 & 15);
    } else {
        acc = (acc - scale_25 + 11) & 127;
        aux += 3;
    }
    int residue_83 = (aux + st.buffer[1]) & 3;
    switch (residue_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000354_5413_21(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000354_5413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_97 = (st.buffer[0] * 3 + aux) & 63;
    if (window_97 > 48) {
        acc = (acc + window_97 * 2 + 5) & 127;
        aux ^= (window_97 & 15);
    } else {
        acc = (acc - window_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_79 = 0;
    for (int k = 0; k < 3; k++) {
        window_79 = (window_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_79) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_29 = local_arr[aux % 3];
    acc = (acc + pivot_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_22(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000354_5413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_68 = (aux + st.buffer[1]) & 3;
    switch (tally_68) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_31 = local_arr[aux % 3];
    acc = (acc + anchor_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000354_5413_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000354_5413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int vector_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_27) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_44 = local_arr[aux % 3];
    acc = (acc + phase_44 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000354_0;
    int sec_r000354_1;
    int sec_r000354_2;
    int sec_r000354_3;
    int sec_r000354_4;
    int sec_r000354_5;
    int sec_r000354_6;
    int sec_r000354_7;
    int sec_r000354_8;
    int sec_r000354_9;
    int sec_r000354_10;
    int sec_r000354_11;
    int sec_r000354_12;
    int sec_r000354_13;
    int sec_r000354_14;
    int sec_r000354_15;
    int sec_r000354_16;
    int pub_r000354_0;
    int pub_r000354_1;
    int pub_r000354_2;
    int pub_r000354_3;
    int pub_r000354_4;
    int pub_r000354_5;
    int pub_r000354_6;
    int pub_r000354_7;
    int pub_r000354_8;
    int pub_r000354_9;
    int pub_r000354_10;
    int pub_r000354_11;
    int pub_r000354_12;
    int pub_r000354_13;
    int pub_r000354_14;
    int pub_r000354_15;
    int pub_r000354_16;
    int pub_r000354_17;
    int pub_r000354_18;
    int pub_r000354_19;
    int pub_r000354_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000354_0 >= -100 && pub_r000354_0 <= 100);
    __CPROVER_assume(pub_r000354_1 >= -100 && pub_r000354_1 <= 100);
    __CPROVER_assume(pub_r000354_2 >= -100 && pub_r000354_2 <= 100);
    __CPROVER_assume(pub_r000354_3 >= -100 && pub_r000354_3 <= 100);
    __CPROVER_assume(pub_r000354_4 >= -100 && pub_r000354_4 <= 100);
    __CPROVER_assume(pub_r000354_5 >= -100 && pub_r000354_5 <= 100);
    __CPROVER_assume(pub_r000354_6 >= -100 && pub_r000354_6 <= 100);
    __CPROVER_assume(pub_r000354_7 >= -100 && pub_r000354_7 <= 100);
    __CPROVER_assume(pub_r000354_8 >= -100 && pub_r000354_8 <= 100);
    __CPROVER_assume(pub_r000354_9 >= -100 && pub_r000354_9 <= 100);
    __CPROVER_assume(pub_r000354_10 >= -100 && pub_r000354_10 <= 100);
    __CPROVER_assume(pub_r000354_11 >= -100 && pub_r000354_11 <= 100);
    __CPROVER_assume(pub_r000354_12 >= -100 && pub_r000354_12 <= 100);
    __CPROVER_assume(pub_r000354_13 >= -100 && pub_r000354_13 <= 100);
    __CPROVER_assume(pub_r000354_14 >= -100 && pub_r000354_14 <= 100);
    __CPROVER_assume(pub_r000354_15 >= -100 && pub_r000354_15 <= 100);
    __CPROVER_assume(pub_r000354_16 >= -100 && pub_r000354_16 <= 100);
    __CPROVER_assume(pub_r000354_17 >= -100 && pub_r000354_17 <= 100);
    __CPROVER_assume(pub_r000354_18 >= -100 && pub_r000354_18 <= 100);
    __CPROVER_assume(pub_r000354_19 >= -100 && pub_r000354_19 <= 100);
    __CPROVER_assume(pub_r000354_20 >= -100 && pub_r000354_20 <= 100);
    __CPROVER_assume(sec_r000354_0 >= 0 && sec_r000354_0 <= 255);
    __CPROVER_assume(sec_r000354_1 >= 0 && sec_r000354_1 <= 255);
    __CPROVER_assume(sec_r000354_2 >= 0 && sec_r000354_2 <= 255);
    __CPROVER_assume(sec_r000354_3 >= 0 && sec_r000354_3 <= 255);
    __CPROVER_assume(sec_r000354_4 >= 0 && sec_r000354_4 <= 255);
    __CPROVER_assume(sec_r000354_5 >= 0 && sec_r000354_5 <= 255);
    __CPROVER_assume(sec_r000354_6 >= 0 && sec_r000354_6 <= 255);
    __CPROVER_assume(sec_r000354_7 >= 0 && sec_r000354_7 <= 255);
    __CPROVER_assume(sec_r000354_8 >= 0 && sec_r000354_8 <= 255);
    __CPROVER_assume(sec_r000354_9 >= 0 && sec_r000354_9 <= 255);
    __CPROVER_assume(sec_r000354_10 >= 0 && sec_r000354_10 <= 255);
    __CPROVER_assume(sec_r000354_11 >= 0 && sec_r000354_11 <= 255);
    __CPROVER_assume(sec_r000354_12 >= 0 && sec_r000354_12 <= 255);
    __CPROVER_assume(sec_r000354_13 >= 0 && sec_r000354_13 <= 255);
    __CPROVER_assume(sec_r000354_14 >= 0 && sec_r000354_14 <= 255);
    __CPROVER_assume(sec_r000354_15 >= 0 && sec_r000354_15 <= 255);
    __CPROVER_assume(sec_r000354_16 >= 0 && sec_r000354_16 <= 255);

    struct AudioFrame_R000354_5413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000354_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000354_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000354_0 + 7) & 15;
    struct CipherContext_R000354_5413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000354_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000354_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000354_0 + 9) & 15;
    struct MatrixBlock_R000354_5413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000354_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000354_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000354_0 + 11) & 15;
    struct FilterState_R000354_5413_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000354_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000354_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000354_0 + 13) & 15;

    union ColorPixel_R000354_5413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 11) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 26) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 36) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 51) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 34) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 49) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 16) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 31) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 32) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 47) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 38) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 53) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

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
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 18) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 33) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 24) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 39) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 39) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 54) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 19) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 34) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 15) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 30) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 10) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 25) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 12) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 27) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
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
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_2.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 24) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 39) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 46) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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
    int stage_v_92 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 33) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 48) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 44) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_3.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 22) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 37) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
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

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_2.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 12) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 27) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_2.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 34) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 49) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 38) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 53) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_3.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 17) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 32) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 23) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 38) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 36) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 51) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_3.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 26) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 41) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[0] ^ 134) & 3;
    switch (stage_v_131) {
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

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 28) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 43) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_3.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 21) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 36) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 143) & 15;
    int stage_v_142 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= stage_v_142;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_2.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_3.buffer[1] * 2 + 460) & 63;
    if (stage_v_151 > 21) {
        out_sink = (out_sink + stage_v_151 - 5) & 255;
        if (stage_v_151 > 36) {
            chk_sum ^= (stage_v_151 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_151 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_3.buffer[0] ^ 158) & 3;
    switch (stage_v_155) {
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

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 31) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 46) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = table[1];
    table[1] = (table[2] + 315) & 63;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[0] ^ 164) & 3;
    switch (stage_v_161) {
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

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 40) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 55) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000354_4 * 3 + pub_r000354_17) & 127;
    int arith_v_1 = (arith_v_0 ^ (sec_r000354_7 * 2)) & 127;
    int arith_v_2 = (arith_v_1 + (sec_r000354_6 * 2)) & 127;
    int arith_v_3 = (arith_v_2 ^ (sec_r000354_8 * 2)) & 127;
    out_sink += arith_v_3 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
