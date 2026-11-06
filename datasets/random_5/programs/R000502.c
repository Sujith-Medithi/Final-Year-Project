/*
 * Benchmark Program: R000502
 * Security Family: direct_leakage
 * Generator Seed: 550213
 * High Inputs: 20 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000502_213_0 {
    int prev_in;
    short damping;
    int cutoff;
    short mode;
    short prev_out;
    int buffer[3];
};

struct CipherContext_R000502_213_1 {
    unsigned char tag;
    unsigned char iv;
    short counter;
    int round_key;
    int buffer[3];
};

struct EventLog_R000502_213_2 {
    unsigned char code;
    int facility;
    int seq;
    short signature;
    unsigned char timestamp;
    int buffer[3];
};

struct MatrixBlock_R000502_213_3 {
    int dim;
    int stride;
    int determinant;
    short scale;
    int density;
    int buffer[3];
};

union RegisterBank_R000502_213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000502_213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000502_213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 15) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    int vector_64 = (aux + st.buffer[1]) & 3;
    switch (vector_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_1(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_87 = (aux + st.buffer[1]) & 3;
    switch (phase_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_99 = local_arr[aux % 3];
    acc = (acc + vector_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_94) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_81 = local_arr[aux % 3];
    acc = (acc + segment_81 * 2) & 127;
    int segment_11 = (aux + st.buffer[1]) & 3;
    switch (segment_11) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_48 = (aux + st.buffer[1]) & 3;
    switch (pivot_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_82 = local_arr[aux % 3];
    acc = (acc + factor_82 * 2) & 127;
    int residue_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000502_213_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quantum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_89) & 63;
    acc ^= aux;
    int pivot_44 = (aux + st.buffer[1]) & 3;
    switch (pivot_44) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_89 = local_arr[aux % 3];
    acc = (acc + anchor_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_5(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000502_213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int scale_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_64 = local_arr[aux % 3];
    acc = (acc + sample_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_6(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000502_213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int phase_26 = (aux + st.buffer[1]) & 3;
    switch (phase_26) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_59) & 63;
    acc ^= aux;
    int quantum_52 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_52 > 48) {
        acc = (acc + quantum_52 * 2 + 5) & 127;
        aux ^= (quantum_52 & 15);
    } else {
        acc = (acc - quantum_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_7(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_40) & 63;
    acc ^= aux;
    int factor_18 = (aux + st.buffer[1]) & 3;
    switch (factor_18) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_8(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000502_213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int accumulator_59 = local_arr[aux % 3];
    acc = (acc + accumulator_59 * 2) & 127;
    int vector_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_24) & 63;
    acc ^= aux;
    int cursor_91 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_91 > 24) {
        acc = (acc + cursor_91 * 2 + 5) & 127;
        aux ^= (cursor_91 & 15);
    } else {
        acc = (acc - cursor_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_27 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_27 > 29) {
        acc = (acc + tally_27 * 2 + 5) & 127;
        aux ^= (tally_27 & 15);
    } else {
        acc = (acc - tally_27 + 11) & 127;
        aux += 3;
    }
    int metric_73 = (aux + st.buffer[1]) & 3;
    switch (metric_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_58) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000502_213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int threshold_45 = local_arr[aux % 3];
    acc = (acc + threshold_45 * 2) & 127;
    int mask_65 = (aux + st.buffer[1]) & 3;
    switch (mask_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_48 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_48 > 36) {
        acc = (acc + mask_48 * 2 + 5) & 127;
        aux ^= (mask_48 & 15);
    } else {
        acc = (acc - mask_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int pivot_16 = local_arr[aux % 3];
    acc = (acc + pivot_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_88 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_88 > 42) {
        acc = (acc + checksum_88 * 2 + 5) & 127;
        aux ^= (checksum_88 & 15);
    } else {
        acc = (acc - checksum_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int factor_10 = local_arr[aux % 3];
    acc = (acc + factor_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_82 > 45) {
        acc = (acc + cursor_82 * 2 + 5) & 127;
        aux ^= (cursor_82 & 15);
    } else {
        acc = (acc - cursor_82 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_17 = local_arr[aux % 3];
    acc = (acc + weight_17 * 2) & 127;
    int metric_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000502_213_14(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000502_213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int factor_95 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_95 > 36) {
        acc = (acc + factor_95 * 2 + 5) & 127;
        aux ^= (factor_95 & 15);
    } else {
        acc = (acc - factor_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_36 = local_arr[aux % 3];
    acc = (acc + checksum_36 * 2) & 127;
    int index_reg_98 = (aux + st.buffer[1]) & 3;
    switch (index_reg_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000502_213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int coefficient_22 = local_arr[aux % 3];
    acc = (acc + coefficient_22 * 2) & 127;
    int mask_75 = (aux + st.buffer[1]) & 3;
    switch (mask_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_16(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000502_213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_91 = local_arr[aux % 3];
    acc = (acc + residue_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_65 = local_arr[aux % 3];
    acc = (acc + index_reg_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_18(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_48 = local_arr[aux % 3];
    acc = (acc + phase_48 * 2) & 127;
    int index_reg_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000502_213_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_32 = (st.buffer[0] * 3 + aux) & 63;
    if (window_32 > 41) {
        acc = (acc + window_32 * 2 + 5) & 127;
        aux ^= (window_32 & 15);
    } else {
        acc = (acc - window_32 + 11) & 127;
        aux += 3;
    }
    int vector_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_40 = local_arr[aux % 3];
    acc = (acc + delta_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_20(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000502_213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_97) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_59 = local_arr[aux % 3];
    acc = (acc + delta_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000502_213_21(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000502_213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_14 = local_arr[aux % 3];
    acc = (acc + margin_14 * 2) & 127;
    int quotient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_34 > 22) {
        acc = (acc + quotient_34 * 2 + 5) & 127;
        aux ^= (quotient_34 & 15);
    } else {
        acc = (acc - quotient_34 + 11) & 127;
        aux += 3;
    }
    int cursor_51 = (aux + st.buffer[1]) & 3;
    switch (cursor_51) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000502_213_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000502_213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_97) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_80 = local_arr[aux % 3];
    acc = (acc + weight_80 * 2) & 127;
    int anchor_49 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_49 > 34) {
        acc = (acc + anchor_49 * 2 + 5) & 127;
        aux ^= (anchor_49 & 15);
    } else {
        acc = (acc - anchor_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000502_0;
    int sec_r000502_1;
    int sec_r000502_2;
    int sec_r000502_3;
    int sec_r000502_4;
    int sec_r000502_5;
    int sec_r000502_6;
    int sec_r000502_7;
    int sec_r000502_8;
    int sec_r000502_9;
    int sec_r000502_10;
    int sec_r000502_11;
    int sec_r000502_12;
    int sec_r000502_13;
    int sec_r000502_14;
    int sec_r000502_15;
    int sec_r000502_16;
    int sec_r000502_17;
    int sec_r000502_18;
    int sec_r000502_19;
    int pub_r000502_0;
    int pub_r000502_1;
    int pub_r000502_2;
    int pub_r000502_3;
    int pub_r000502_4;
    int pub_r000502_5;
    int pub_r000502_6;
    int pub_r000502_7;
    int pub_r000502_8;
    int pub_r000502_9;
    int pub_r000502_10;
    int pub_r000502_11;
    int pub_r000502_12;
    int pub_r000502_13;
    int pub_r000502_14;
    int pub_r000502_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000502_0 >= -100 && pub_r000502_0 <= 100);
    __CPROVER_assume(pub_r000502_1 >= -100 && pub_r000502_1 <= 100);
    __CPROVER_assume(pub_r000502_2 >= -100 && pub_r000502_2 <= 100);
    __CPROVER_assume(pub_r000502_3 >= -100 && pub_r000502_3 <= 100);
    __CPROVER_assume(pub_r000502_4 >= -100 && pub_r000502_4 <= 100);
    __CPROVER_assume(pub_r000502_5 >= -100 && pub_r000502_5 <= 100);
    __CPROVER_assume(pub_r000502_6 >= -100 && pub_r000502_6 <= 100);
    __CPROVER_assume(pub_r000502_7 >= -100 && pub_r000502_7 <= 100);
    __CPROVER_assume(pub_r000502_8 >= -100 && pub_r000502_8 <= 100);
    __CPROVER_assume(pub_r000502_9 >= -100 && pub_r000502_9 <= 100);
    __CPROVER_assume(pub_r000502_10 >= -100 && pub_r000502_10 <= 100);
    __CPROVER_assume(pub_r000502_11 >= -100 && pub_r000502_11 <= 100);
    __CPROVER_assume(pub_r000502_12 >= -100 && pub_r000502_12 <= 100);
    __CPROVER_assume(pub_r000502_13 >= -100 && pub_r000502_13 <= 100);
    __CPROVER_assume(pub_r000502_14 >= -100 && pub_r000502_14 <= 100);
    __CPROVER_assume(pub_r000502_15 >= -100 && pub_r000502_15 <= 100);
    __CPROVER_assume(sec_r000502_0 >= 0 && sec_r000502_0 <= 255);
    __CPROVER_assume(sec_r000502_1 >= 0 && sec_r000502_1 <= 255);
    __CPROVER_assume(sec_r000502_2 >= 0 && sec_r000502_2 <= 255);
    __CPROVER_assume(sec_r000502_3 >= 0 && sec_r000502_3 <= 255);
    __CPROVER_assume(sec_r000502_4 >= 0 && sec_r000502_4 <= 255);
    __CPROVER_assume(sec_r000502_5 >= 0 && sec_r000502_5 <= 255);
    __CPROVER_assume(sec_r000502_6 >= 0 && sec_r000502_6 <= 255);
    __CPROVER_assume(sec_r000502_7 >= 0 && sec_r000502_7 <= 255);
    __CPROVER_assume(sec_r000502_8 >= 0 && sec_r000502_8 <= 255);
    __CPROVER_assume(sec_r000502_9 >= 0 && sec_r000502_9 <= 255);
    __CPROVER_assume(sec_r000502_10 >= 0 && sec_r000502_10 <= 255);
    __CPROVER_assume(sec_r000502_11 >= 0 && sec_r000502_11 <= 255);
    __CPROVER_assume(sec_r000502_12 >= 0 && sec_r000502_12 <= 255);
    __CPROVER_assume(sec_r000502_13 >= 0 && sec_r000502_13 <= 255);
    __CPROVER_assume(sec_r000502_14 >= 0 && sec_r000502_14 <= 255);
    __CPROVER_assume(sec_r000502_15 >= 0 && sec_r000502_15 <= 255);
    __CPROVER_assume(sec_r000502_16 >= 0 && sec_r000502_16 <= 255);
    __CPROVER_assume(sec_r000502_17 >= 0 && sec_r000502_17 <= 255);
    __CPROVER_assume(sec_r000502_18 >= 0 && sec_r000502_18 <= 255);
    __CPROVER_assume(sec_r000502_19 >= 0 && sec_r000502_19 <= 255);

    struct FilterState_R000502_213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000502_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000502_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000502_0 + 7) & 15;
    struct CipherContext_R000502_213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000502_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000502_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000502_0 + 9) & 15;
    struct EventLog_R000502_213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000502_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000502_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000502_0 + 11) & 15;
    struct MatrixBlock_R000502_213_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000502_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000502_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000502_0 + 13) & 15;

    union RegisterBank_R000502_213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 27) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 42) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 42) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 26) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 41) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 14) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 29) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 12) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 27) {
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
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 33) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 48) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 28) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 43) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 40) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 17) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 32) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 21) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 36) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 21) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 36) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 32) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 47) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r000502_5 + pub_r000502_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r000502_11 + pub_r000502_5 + 46) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_36 + pub_r000502_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r000502_17 + pub_r000502_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_37 + pub_r000502_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r000502_1 + pub_r000502_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r000502_10 + pub_r000502_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_37 + pub_r000502_3 + 49) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_40 + pub_r000502_7 + 38) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_41 + pub_r000502_12 + 46) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_37 + pub_r000502_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_37 + pub_r000502_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_38 + pub_r000502_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r000502_1 + pub_r000502_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_40 + pub_r000502_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r000502_2 + pub_r000502_4 + 49) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_50 + pub_r000502_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_48 + pub_r000502_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r000502_1 + pub_r000502_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_42 + pub_r000502_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_39 + pub_r000502_1 + 36) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r000502_17 + pub_r000502_9 + 46) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r000502_7 + pub_r000502_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_43 + pub_r000502_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_51 + pub_r000502_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_59 + pub_r000502_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r000502_2 + pub_r000502_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r000502_6 + pub_r000502_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_39 + pub_r000502_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_57 + pub_r000502_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r000502_4 + pub_r000502_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_44 + pub_r000502_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r000502_0 + pub_r000502_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r000502_10 + pub_r000502_3 + 49) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_51 + pub_r000502_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r000502_4 + pub_r000502_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r000502_10 + pub_r000502_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r000502_0 + pub_r000502_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_63 + pub_r000502_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r000502_5 + pub_r000502_10 + 48) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_46 + pub_r000502_15 + 49) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r000502_7 + pub_r000502_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_36 + pub_r000502_12 + 48) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_78 + pub_r000502_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r000502_11 + pub_r000502_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r000502_6 + pub_r000502_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r000502_11 + pub_r000502_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_67 + pub_r000502_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_69 + pub_r000502_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_80 + pub_r000502_4 + 13) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r000502_9 + pub_r000502_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r000502_10 + pub_r000502_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_41 + pub_r000502_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_72 + pub_r000502_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r000502_1 + pub_r000502_1 + 48) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_70 + pub_r000502_6 + 48) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_55 + pub_r000502_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_56 + pub_r000502_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_62 + pub_r000502_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_69 + pub_r000502_0 + 38) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r000502_15 + pub_r000502_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_74 + pub_r000502_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_87 + pub_r000502_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_96 + pub_r000502_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_93 + pub_r000502_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_89 + pub_r000502_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r000502_15 + pub_r000502_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_59 + pub_r000502_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r000502_11 + pub_r000502_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_59 + pub_r000502_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_61 + pub_r000502_13 + 47) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_106 + pub_r000502_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_66 + pub_r000502_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_55 + pub_r000502_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_70 + pub_r000502_15 + 48) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_68 + pub_r000502_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_81 + pub_r000502_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_88 + pub_r000502_15 + 33) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r000502_19 + pub_r000502_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_75 + pub_r000502_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_106 + pub_r000502_10 + 47) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_116 + pub_r000502_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r000502_1 + pub_r000502_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r000502_5 + pub_r000502_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r000502_11 + pub_r000502_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_37 + pub_r000502_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r000502_7 + pub_r000502_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_96 + pub_r000502_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r000502_5 + pub_r000502_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r000502_15 + pub_r000502_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_62 + pub_r000502_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r000502_16 + pub_r000502_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_81 + pub_r000502_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_53 + pub_r000502_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r000502_3 + pub_r000502_10 + 47) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_103 + pub_r000502_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_131 + pub_r000502_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_81 + pub_r000502_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r000502_15 + pub_r000502_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_70 + pub_r000502_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r000502_13 + pub_r000502_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_38 + pub_r000502_5 + 4) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r000502_9 + pub_r000502_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_79 + pub_r000502_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_103 + pub_r000502_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_48 + pub_r000502_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_83 + pub_r000502_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r000502_2 + pub_r000502_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r000502_14 + pub_r000502_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_83 + pub_r000502_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r000502_0 + pub_r000502_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r000502_11 + pub_r000502_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_136 + pub_r000502_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_94 + pub_r000502_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_145 + pub_r000502_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_100 + pub_r000502_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_97 + pub_r000502_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_75 + pub_r000502_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_68 + pub_r000502_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r000502_5 + pub_r000502_2 + 40) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_107 + pub_r000502_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_60 + pub_r000502_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_46 + pub_r000502_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_138 + pub_r000502_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_153 + pub_r000502_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r000502_7 + pub_r000502_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_111 + pub_r000502_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_145 + pub_r000502_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_163 + pub_r000502_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r000502_15 + pub_r000502_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_50 + pub_r000502_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_82 + pub_r000502_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (sec_r000502_8 + pub_r000502_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r000502_2 + pub_r000502_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r000502_17 + pub_r000502_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_48 + pub_r000502_4 + 49) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r000502_0 + pub_r000502_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_164 + pub_r000502_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r000502_0 + pub_r000502_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_61 + pub_r000502_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_154 + pub_r000502_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r000502_7 + pub_r000502_13 + 47) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r000502_18 + pub_r000502_11 + 42) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (sec_r000502_7 + pub_r000502_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_162 + pub_r000502_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_103 + pub_r000502_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_123 + pub_r000502_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_93 + pub_r000502_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_80 + pub_r000502_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r000502_0 + pub_r000502_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_96 + pub_r000502_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r000502_3 + pub_r000502_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_56 + pub_r000502_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_183 + pub_r000502_14 + 34) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_66 + pub_r000502_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_63 + pub_r000502_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r000502_17 + pub_r000502_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_100 + pub_r000502_15 + 49) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (sec_r000502_19 + pub_r000502_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_178 + pub_r000502_15 + 12) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r000502_12 + pub_r000502_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_74 + pub_r000502_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (sec_r000502_11 + pub_r000502_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_107 + pub_r000502_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_184 + pub_r000502_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r000502_11 + pub_r000502_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_143 + pub_r000502_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_114 + pub_r000502_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r000502_3 + pub_r000502_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_75 + pub_r000502_6 + 33) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r000502_0 + pub_r000502_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r000502_13 + pub_r000502_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_61 + pub_r000502_8 + 49) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_58 + pub_r000502_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_77 + pub_r000502_0 + 47) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_144 + pub_r000502_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_41 + pub_r000502_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_42 + pub_r000502_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_58 + pub_r000502_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r000502_5 + pub_r000502_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (sec_r000502_4 + pub_r000502_6 + 46) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_41 + pub_r000502_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_79 + pub_r000502_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_214 + pub_r000502_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_59 + pub_r000502_6 + 36) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_191 + pub_r000502_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_169 + pub_r000502_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_161 + pub_r000502_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (sec_r000502_19 + pub_r000502_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_201 + pub_r000502_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (sec_r000502_0 + pub_r000502_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_90 + pub_r000502_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_144 + pub_r000502_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_216 + pub_r000502_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_151 + pub_r000502_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (sec_r000502_16 + pub_r000502_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (sec_r000502_15 + pub_r000502_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (sec_r000502_15 + pub_r000502_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (sec_r000502_15 + pub_r000502_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_126 + pub_r000502_14 + 46) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (sec_r000502_9 + pub_r000502_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_109 + pub_r000502_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_77 + pub_r000502_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_128 + pub_r000502_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_65 + pub_r000502_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_36 + pub_r000502_4 + 5) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_222 + pub_r000502_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_225 + pub_r000502_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_72 + pub_r000502_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (sec_r000502_18 + pub_r000502_2 + 27) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_226 + pub_r000502_12 + 48) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_150 + pub_r000502_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (sec_r000502_7 + pub_r000502_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (sec_r000502_0 + pub_r000502_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (sec_r000502_6 + pub_r000502_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (sec_r000502_7 + pub_r000502_8 + 46) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_123 + pub_r000502_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (sec_r000502_1 + pub_r000502_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_172 + pub_r000502_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r000502_7 + pub_r000502_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_73 + pub_r000502_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_79 + pub_r000502_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_69 + pub_r000502_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_89 + pub_r000502_9 + 26) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_80 + pub_r000502_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (sec_r000502_16 + pub_r000502_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_61 + pub_r000502_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (sec_r000502_10 + pub_r000502_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (stage_v_181 + pub_r000502_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (sec_r000502_5 + pub_r000502_13 + 28) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (sec_r000502_9 + pub_r000502_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (stage_v_42 + pub_r000502_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_255 + pub_r000502_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (stage_v_267 + pub_r000502_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (stage_v_218 + pub_r000502_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (stage_v_152 + pub_r000502_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (stage_v_207 + pub_r000502_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (stage_v_76 + pub_r000502_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (stage_v_176 + pub_r000502_5 + 42) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (stage_v_42 + pub_r000502_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (stage_v_180 + pub_r000502_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (stage_v_105 + pub_r000502_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (stage_v_78 + pub_r000502_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (sec_r000502_14 + pub_r000502_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (sec_r000502_4 + pub_r000502_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (stage_v_149 + pub_r000502_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (stage_v_276 + pub_r000502_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (stage_v_204 + pub_r000502_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (sec_r000502_1 + pub_r000502_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (stage_v_157 + pub_r000502_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (stage_v_71 + pub_r000502_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (sec_r000502_2 + pub_r000502_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (stage_v_71 + pub_r000502_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (sec_r000502_11 + pub_r000502_8 + 21) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (sec_r000502_16 + pub_r000502_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (stage_v_210 + pub_r000502_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (stage_v_69 + pub_r000502_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (stage_v_95 + pub_r000502_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (stage_v_235 + pub_r000502_10 + 9) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (sec_r000502_10 + pub_r000502_2 + 48) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (sec_r000502_5 + pub_r000502_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (sec_r000502_14 + pub_r000502_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (stage_v_227 + pub_r000502_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (stage_v_96 + pub_r000502_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (stage_v_143 + pub_r000502_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (stage_v_159 + pub_r000502_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (stage_v_159 + pub_r000502_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (sec_r000502_15 + pub_r000502_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (stage_v_107 + pub_r000502_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (stage_v_116 + pub_r000502_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (sec_r000502_16 + pub_r000502_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (stage_v_126 + pub_r000502_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (sec_r000502_14 + pub_r000502_4 + 18) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (stage_v_292 + pub_r000502_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (stage_v_64 + pub_r000502_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (sec_r000502_12 + pub_r000502_3 + 47) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (sec_r000502_10 + pub_r000502_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (sec_r000502_0 + pub_r000502_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (sec_r000502_0 + pub_r000502_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (sec_r000502_11 + pub_r000502_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (stage_v_212 + pub_r000502_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (sec_r000502_4 + pub_r000502_8 + 40) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (stage_v_135 + pub_r000502_0 + 48) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (stage_v_215 + pub_r000502_4 + 5) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (sec_r000502_8 + pub_r000502_7 + 12) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (stage_v_119 + pub_r000502_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (stage_v_232 + pub_r000502_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (stage_v_239 + pub_r000502_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (stage_v_259 + pub_r000502_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (stage_v_133 + pub_r000502_14 + 49) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (stage_v_310 + pub_r000502_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (stage_v_142 + pub_r000502_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (sec_r000502_17 + pub_r000502_2 + 48) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (stage_v_121 + pub_r000502_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (stage_v_167 + pub_r000502_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (sec_r000502_13 + pub_r000502_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (stage_v_108 + pub_r000502_1 + 43) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (sec_r000502_2 + pub_r000502_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (stage_v_78 + pub_r000502_6 + 45) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (stage_v_153 + pub_r000502_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (stage_v_134 + pub_r000502_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (sec_r000502_1 + pub_r000502_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (sec_r000502_12 + pub_r000502_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (stage_v_267 + pub_r000502_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (stage_v_61 + pub_r000502_10 + 46) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (sec_r000502_3 + pub_r000502_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (stage_v_288 + pub_r000502_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (stage_v_185 + pub_r000502_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (stage_v_286 + pub_r000502_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (stage_v_95 + pub_r000502_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (stage_v_283 + pub_r000502_5 + 24) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (stage_v_50 + pub_r000502_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (stage_v_111 + pub_r000502_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (stage_v_315 + pub_r000502_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
