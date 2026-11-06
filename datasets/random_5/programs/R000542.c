/*
 * Benchmark Program: R000542
 * Security Family: direct_leakage
 * Generator Seed: 554213
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000542_4213_0 {
    int checksum;
    unsigned char state;
    int head;
    int capacity;
    short tail;
    int buffer[3];
};

struct Transaction_R000542_4213_1 {
    int auth_code;
    int balance;
    short rate;
    int buffer[3];
};

union RegisterBank_R000542_4213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000542_4213_0(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tracker_46 = (aux + st.buffer[1]) & 3;
    switch (tracker_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000542_4213_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_84) & 63;
    acc ^= aux;
    int factor_79 = (aux + st.buffer[1]) & 3;
    switch (factor_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_2(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int damping_68 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_68 > 31) {
        acc = (acc + damping_68 * 2 + 5) & 127;
        aux ^= (damping_68 & 15);
    } else {
        acc = (acc - damping_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_32 = local_arr[aux % 3];
    acc = (acc + damping_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int damping_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_49) & 63;
    acc ^= aux;
    int threshold_45 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_45 > 19) {
        acc = (acc + threshold_45 * 2 + 5) & 127;
        aux ^= (threshold_45 & 15);
    } else {
        acc = (acc - threshold_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_86 = (aux + st.buffer[1]) & 3;
    switch (checksum_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_35 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_35 > 39) {
        acc = (acc + mask_35 * 2 + 5) & 127;
        aux ^= (mask_35 & 15);
    } else {
        acc = (acc - mask_35 + 11) & 127;
        aux += 3;
    }
    int residue_36 = (aux + st.buffer[1]) & 3;
    switch (residue_36) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_5(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_41 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_41 > 41) {
        acc = (acc + checksum_41 * 2 + 5) & 127;
        aux ^= (checksum_41 & 15);
    } else {
        acc = (acc - checksum_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_6(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_22 = (aux + st.buffer[1]) & 3;
    switch (phase_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_56) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_7(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int parity_38 = (aux + st.buffer[1]) & 3;
    switch (parity_38) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_29 = (st.buffer[0] * 3 + aux) & 63;
    if (window_29 > 40) {
        acc = (acc + window_29 * 2 + 5) & 127;
        aux ^= (window_29 & 15);
    } else {
        acc = (acc - window_29 + 11) & 127;
        aux += 3;
    }
    int index_reg_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000542_4213_8(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_77 = local_arr[aux % 3];
    acc = (acc + delta_77 * 2) & 127;
    int segment_33 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_33 > 23) {
        acc = (acc + segment_33 * 2 + 5) & 127;
        aux ^= (segment_33 & 15);
    } else {
        acc = (acc - segment_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int anchor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_88) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_74 = local_arr[aux % 3];
    acc = (acc + quantum_74 * 2) & 127;
    int segment_27 = (aux + st.buffer[1]) & 3;
    switch (segment_27) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_31 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_31 > 11) {
        acc = (acc + index_reg_31 * 2 + 5) & 127;
        aux ^= (index_reg_31 & 15);
    } else {
        acc = (acc - index_reg_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_19 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_19 > 13) {
        acc = (acc + accumulator_19 * 2 + 5) & 127;
        aux ^= (accumulator_19 & 15);
    } else {
        acc = (acc - accumulator_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_55 = local_arr[aux % 3];
    acc = (acc + scale_55 * 2) & 127;
    int accumulator_26 = (aux + st.buffer[1]) & 3;
    switch (accumulator_26) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_11(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int coefficient_40 = local_arr[aux % 3];
    acc = (acc + coefficient_40 * 2) & 127;
    int delta_16 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_16 > 38) {
        acc = (acc + delta_16 * 2 + 5) & 127;
        aux ^= (delta_16 & 15);
    } else {
        acc = (acc - delta_16 + 11) & 127;
        aux += 3;
    }
    int sample_48 = (aux + st.buffer[1]) & 3;
    switch (sample_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_12(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int window_86 = local_arr[aux % 3];
    acc = (acc + window_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_66) & 63;
    acc ^= aux;
    int vector_72 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_72 > 16) {
        acc = (acc + vector_72 * 2 + 5) & 127;
        aux ^= (vector_72 & 15);
    } else {
        acc = (acc - vector_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_13(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_86 = local_arr[aux % 3];
    acc = (acc + factor_86 * 2) & 127;
    int factor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_11) & 63;
    acc ^= aux;
    int bound_68 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_68 > 38) {
        acc = (acc + bound_68 * 2 + 5) & 127;
        aux ^= (bound_68 & 15);
    } else {
        acc = (acc - bound_68 + 11) & 127;
        aux += 3;
    }
    int index_reg_39 = (aux + st.buffer[1]) & 3;
    switch (index_reg_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int checksum_17 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_17 > 12) {
        acc = (acc + checksum_17 * 2 + 5) & 127;
        aux ^= (checksum_17 & 15);
    } else {
        acc = (acc - checksum_17 + 11) & 127;
        aux += 3;
    }
    int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000542_4213_15(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_89 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_89 > 29) {
        acc = (acc + index_reg_89 * 2 + 5) & 127;
        aux ^= (index_reg_89 & 15);
    } else {
        acc = (acc - index_reg_89 + 11) & 127;
        aux += 3;
    }
    int quantum_36 = (aux + st.buffer[1]) & 3;
    switch (quantum_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_62 = local_arr[aux % 3];
    acc = (acc + vector_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_50 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_50 > 41) {
        acc = (acc + delta_50 * 2 + 5) & 127;
        aux ^= (delta_50 & 15);
    } else {
        acc = (acc - delta_50 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_86 = local_arr[aux % 3];
    acc = (acc + sample_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_17(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int bound_83 = (aux + st.buffer[1]) & 3;
    switch (bound_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_85 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_85 > 13) {
        acc = (acc + pivot_85 * 2 + 5) & 127;
        aux ^= (pivot_85 & 15);
    } else {
        acc = (acc - pivot_85 + 11) & 127;
        aux += 3;
    }
    int stride_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000542_4213_18(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int damping_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_14) & 63;
    acc ^= aux;
    int anchor_45 = (aux + st.buffer[1]) & 3;
    switch (anchor_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_98 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_98 > 13) {
        acc = (acc + margin_98 * 2 + 5) & 127;
        aux ^= (margin_98 & 15);
    } else {
        acc = (acc - margin_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000542_4213_19(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_73 = local_arr[aux % 3];
    acc = (acc + cursor_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000542_4213_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int segment_47 = (aux + st.buffer[1]) & 3;
    switch (segment_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_46 = (st.buffer[0] * 3 + aux) & 63;
    if (window_46 > 50) {
        acc = (acc + window_46 * 2 + 5) & 127;
        aux ^= (window_46 & 15);
    } else {
        acc = (acc - window_46 + 11) & 127;
        aux += 3;
    }
    int quantum_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000542_0;
    int sec_r000542_1;
    int sec_r000542_2;
    int sec_r000542_3;
    int sec_r000542_4;
    int sec_r000542_5;
    int sec_r000542_6;
    int sec_r000542_7;
    int sec_r000542_8;
    int sec_r000542_9;
    int sec_r000542_10;
    int sec_r000542_11;
    int sec_r000542_12;
    int sec_r000542_13;
    int sec_r000542_14;
    int sec_r000542_15;
    int pub_r000542_0;
    int pub_r000542_1;
    int pub_r000542_2;
    int pub_r000542_3;
    int pub_r000542_4;
    int pub_r000542_5;
    int pub_r000542_6;
    int pub_r000542_7;
    int pub_r000542_8;
    int pub_r000542_9;
    int pub_r000542_10;
    int pub_r000542_11;
    int pub_r000542_12;
    int pub_r000542_13;
    int pub_r000542_14;
    int pub_r000542_15;
    int pub_r000542_16;
    int pub_r000542_17;
    int pub_r000542_18;
    int pub_r000542_19;
    int pub_r000542_20;
    int pub_r000542_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000542_0 >= -100 && pub_r000542_0 <= 100);
    __CPROVER_assume(pub_r000542_1 >= -100 && pub_r000542_1 <= 100);
    __CPROVER_assume(pub_r000542_2 >= -100 && pub_r000542_2 <= 100);
    __CPROVER_assume(pub_r000542_3 >= -100 && pub_r000542_3 <= 100);
    __CPROVER_assume(pub_r000542_4 >= -100 && pub_r000542_4 <= 100);
    __CPROVER_assume(pub_r000542_5 >= -100 && pub_r000542_5 <= 100);
    __CPROVER_assume(pub_r000542_6 >= -100 && pub_r000542_6 <= 100);
    __CPROVER_assume(pub_r000542_7 >= -100 && pub_r000542_7 <= 100);
    __CPROVER_assume(pub_r000542_8 >= -100 && pub_r000542_8 <= 100);
    __CPROVER_assume(pub_r000542_9 >= -100 && pub_r000542_9 <= 100);
    __CPROVER_assume(pub_r000542_10 >= -100 && pub_r000542_10 <= 100);
    __CPROVER_assume(pub_r000542_11 >= -100 && pub_r000542_11 <= 100);
    __CPROVER_assume(pub_r000542_12 >= -100 && pub_r000542_12 <= 100);
    __CPROVER_assume(pub_r000542_13 >= -100 && pub_r000542_13 <= 100);
    __CPROVER_assume(pub_r000542_14 >= -100 && pub_r000542_14 <= 100);
    __CPROVER_assume(pub_r000542_15 >= -100 && pub_r000542_15 <= 100);
    __CPROVER_assume(pub_r000542_16 >= -100 && pub_r000542_16 <= 100);
    __CPROVER_assume(pub_r000542_17 >= -100 && pub_r000542_17 <= 100);
    __CPROVER_assume(pub_r000542_18 >= -100 && pub_r000542_18 <= 100);
    __CPROVER_assume(pub_r000542_19 >= -100 && pub_r000542_19 <= 100);
    __CPROVER_assume(pub_r000542_20 >= -100 && pub_r000542_20 <= 100);
    __CPROVER_assume(pub_r000542_21 >= -100 && pub_r000542_21 <= 100);
    __CPROVER_assume(sec_r000542_0 >= 0 && sec_r000542_0 <= 255);
    __CPROVER_assume(sec_r000542_1 >= 0 && sec_r000542_1 <= 255);
    __CPROVER_assume(sec_r000542_2 >= 0 && sec_r000542_2 <= 255);
    __CPROVER_assume(sec_r000542_3 >= 0 && sec_r000542_3 <= 255);
    __CPROVER_assume(sec_r000542_4 >= 0 && sec_r000542_4 <= 255);
    __CPROVER_assume(sec_r000542_5 >= 0 && sec_r000542_5 <= 255);
    __CPROVER_assume(sec_r000542_6 >= 0 && sec_r000542_6 <= 255);
    __CPROVER_assume(sec_r000542_7 >= 0 && sec_r000542_7 <= 255);
    __CPROVER_assume(sec_r000542_8 >= 0 && sec_r000542_8 <= 255);
    __CPROVER_assume(sec_r000542_9 >= 0 && sec_r000542_9 <= 255);
    __CPROVER_assume(sec_r000542_10 >= 0 && sec_r000542_10 <= 255);
    __CPROVER_assume(sec_r000542_11 >= 0 && sec_r000542_11 <= 255);
    __CPROVER_assume(sec_r000542_12 >= 0 && sec_r000542_12 <= 255);
    __CPROVER_assume(sec_r000542_13 >= 0 && sec_r000542_13 <= 255);
    __CPROVER_assume(sec_r000542_14 >= 0 && sec_r000542_14 <= 255);
    __CPROVER_assume(sec_r000542_15 >= 0 && sec_r000542_15 <= 255);

    struct StreamBuffer_R000542_4213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000542_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000542_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000542_0 + 7) & 15;
    struct Transaction_R000542_4213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000542_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000542_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000542_0 + 9) & 15;

    union RegisterBank_R000542_4213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

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
    int stage_v_4 = (sec_r000542_13 + pub_r000542_5 + 42) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_4 + pub_r000542_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (stage_v_5 + pub_r000542_2 + 43) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_6 + pub_r000542_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_6 + pub_r000542_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_4 + pub_r000542_7 + 46) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_8 + pub_r000542_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_7 + pub_r000542_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r000542_10 + pub_r000542_16 + 46) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_9 + pub_r000542_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_12 + pub_r000542_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r000542_8 + pub_r000542_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r000542_8 + pub_r000542_19 + 20) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_8 + pub_r000542_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r000542_11 + pub_r000542_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r000542_15 + pub_r000542_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r000542_2 + pub_r000542_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_11 + pub_r000542_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_4 + pub_r000542_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_8 + pub_r000542_6 + 38) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_7 + pub_r000542_17 + 46) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r000542_12 + pub_r000542_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_19 + pub_r000542_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_13 + pub_r000542_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_23 + pub_r000542_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r000542_8 + pub_r000542_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_20 + pub_r000542_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r000542_10 + pub_r000542_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_9 + pub_r000542_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_5 + pub_r000542_19 + 43) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_22 + pub_r000542_1 + 40) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_34 + pub_r000542_3 + 42) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_11 + pub_r000542_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_8 + pub_r000542_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r000542_10 + pub_r000542_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_31 + pub_r000542_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_17 + pub_r000542_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_9 + pub_r000542_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_18 + pub_r000542_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_37 + pub_r000542_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r000542_14 + pub_r000542_17 + 47) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r000542_8 + pub_r000542_19 + 30) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_38 + pub_r000542_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_46 + pub_r000542_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_27 + pub_r000542_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r000542_12 + pub_r000542_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r000542_8 + pub_r000542_11 + 46) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r000542_7 + pub_r000542_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_11 + pub_r000542_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_39 + pub_r000542_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_11 + pub_r000542_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_42 + pub_r000542_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r000542_2 + pub_r000542_18 + 5) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_32 + pub_r000542_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_25 + pub_r000542_18 + 7) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r000542_7 + pub_r000542_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r000542_8 + pub_r000542_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_15 + pub_r000542_17 + 7) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_29 + pub_r000542_18 + 39) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_60 + pub_r000542_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_48 + pub_r000542_18 + 46) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_25 + pub_r000542_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_41 + pub_r000542_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_21 + pub_r000542_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r000542_13 + pub_r000542_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r000542_1 + pub_r000542_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_26 + pub_r000542_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_36 + pub_r000542_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r000542_11 + pub_r000542_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_61 + pub_r000542_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_16 + pub_r000542_8 + 34) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r000542_4 + pub_r000542_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_20 + pub_r000542_13 + 49) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_66 + pub_r000542_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_36 + pub_r000542_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_71 + pub_r000542_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_11 + pub_r000542_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_30 + pub_r000542_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_79 + pub_r000542_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_51 + pub_r000542_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r000542_14 + pub_r000542_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r000542_1 + pub_r000542_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_24 + pub_r000542_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r000542_12 + pub_r000542_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_25 + pub_r000542_19 + 35) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r000542_14 + pub_r000542_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r000542_4 + pub_r000542_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_64 + pub_r000542_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_31 + pub_r000542_21 + 10) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r000542_6 + pub_r000542_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r000542_13 + pub_r000542_9 + 49) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_31 + pub_r000542_3 + 47) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_95 + pub_r000542_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_25 + pub_r000542_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_43 + pub_r000542_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_90 + pub_r000542_0 + 39) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_79 + pub_r000542_21 + 21) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r000542_1 + pub_r000542_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r000542_9 + pub_r000542_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_13 + pub_r000542_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_103 + pub_r000542_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r000542_12 + pub_r000542_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_31 + pub_r000542_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_54 + pub_r000542_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r000542_5 + pub_r000542_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r000542_14 + pub_r000542_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_14 + pub_r000542_15 + 47) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_18 + pub_r000542_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_21 + pub_r000542_16 + 39) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r000542_12 + pub_r000542_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_61 + pub_r000542_15 + 48) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_8 + pub_r000542_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_50 + pub_r000542_19 + 15) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (sec_r000542_0 + pub_r000542_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r000542_10 + pub_r000542_18 + 32) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_20 + pub_r000542_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_44 + pub_r000542_19 + 11) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_11 + pub_r000542_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_97 + pub_r000542_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_45 + pub_r000542_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_106 + pub_r000542_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r000542_11 + pub_r000542_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_58 + pub_r000542_21 + 43) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r000542_15 + pub_r000542_11 + 41) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_28 + pub_r000542_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r000542_2 + pub_r000542_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_38 + pub_r000542_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_78 + pub_r000542_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_116 + pub_r000542_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_39 + pub_r000542_2 + 46) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_55 + pub_r000542_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_81 + pub_r000542_15 + 48) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_52 + pub_r000542_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_62 + pub_r000542_18 + 39) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_73 + pub_r000542_18 + 46) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_16 + pub_r000542_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_7 + pub_r000542_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_69 + pub_r000542_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_22 + pub_r000542_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_49 + pub_r000542_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r000542_8 + pub_r000542_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r000542_13 + pub_r000542_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_110 + pub_r000542_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_146 + pub_r000542_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_13 + pub_r000542_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_5 + pub_r000542_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r000542_12 + pub_r000542_0 + 46) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r000542_14 + pub_r000542_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_119 + pub_r000542_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_105 + pub_r000542_20 + 24) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_58 + pub_r000542_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_84 + pub_r000542_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r000542_14 + pub_r000542_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_19 + pub_r000542_18 + 38) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r000542_11 + pub_r000542_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_44 + pub_r000542_21 + 31) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r000542_1 + pub_r000542_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r000542_1 + pub_r000542_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_143 + pub_r000542_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_12 + pub_r000542_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r000542_5 + pub_r000542_18 + 31) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_29 + pub_r000542_5 + 40) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_87 + pub_r000542_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_63 + pub_r000542_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (sec_r000542_5 + pub_r000542_15 + 40) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_132 + pub_r000542_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_133 + pub_r000542_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_49 + pub_r000542_21 + 6) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_70 + pub_r000542_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_45 + pub_r000542_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r000542_5 + pub_r000542_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_64 + pub_r000542_0 + 4) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_149 + pub_r000542_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r000542_4 + pub_r000542_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_67 + pub_r000542_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_47 + pub_r000542_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_176 + pub_r000542_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_8 + pub_r000542_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r000542_15 + pub_r000542_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_54 + pub_r000542_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_24 + pub_r000542_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_128 + pub_r000542_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_16 + pub_r000542_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_16 + pub_r000542_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_55 + pub_r000542_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r000542_6 + pub_r000542_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (sec_r000542_0 + pub_r000542_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_146 + pub_r000542_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r000542_6 + pub_r000542_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (sec_r000542_12 + pub_r000542_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (sec_r000542_11 + pub_r000542_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r000542_2 + pub_r000542_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r000542_15 + pub_r000542_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r000542_5 + pub_r000542_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_101 + pub_r000542_17 + 46) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_24 + pub_r000542_20 + 30) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_105 + pub_r000542_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_38 + pub_r000542_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r000542_13 + pub_r000542_19 + 48) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (sec_r000542_4 + pub_r000542_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r000542_9 + pub_r000542_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_133 + pub_r000542_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_22 + pub_r000542_5 + 48) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r000542_0 + pub_r000542_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (sec_r000542_6 + pub_r000542_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_146 + pub_r000542_1 + 49) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_52 + pub_r000542_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (sec_r000542_8 + pub_r000542_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_169 + pub_r000542_4 + 48) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_192 + pub_r000542_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r000542_0 + pub_r000542_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_203 + pub_r000542_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_66 + pub_r000542_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r000542_15 + pub_r000542_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_113 + pub_r000542_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (sec_r000542_1 + pub_r000542_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r000542_9 + pub_r000542_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_213 + pub_r000542_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_56 + pub_r000542_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_60 + pub_r000542_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_156 + pub_r000542_5 + 48) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_191 + pub_r000542_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_37 + pub_r000542_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_111 + pub_r000542_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_155 + pub_r000542_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_132 + pub_r000542_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_128 + pub_r000542_20 + 46) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (sec_r000542_3 + pub_r000542_20 + 35) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (sec_r000542_15 + pub_r000542_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_68 + pub_r000542_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_10 + pub_r000542_19 + 9) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r000542_13 + pub_r000542_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (sec_r000542_4 + pub_r000542_6 + 49) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_153 + pub_r000542_10 + 43) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_145 + pub_r000542_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_56 + pub_r000542_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_129 + pub_r000542_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (sec_r000542_14 + pub_r000542_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_205 + pub_r000542_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (sec_r000542_3 + pub_r000542_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (sec_r000542_2 + pub_r000542_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_198 + pub_r000542_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_65 + pub_r000542_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_14 + pub_r000542_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_44 + pub_r000542_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_158 + pub_r000542_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_179 + pub_r000542_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_67 + pub_r000542_9 + 49) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_181 + pub_r000542_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_136 + pub_r000542_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_21 + pub_r000542_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r000542_15 + pub_r000542_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (sec_r000542_12 + pub_r000542_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_183 + pub_r000542_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_205 + pub_r000542_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_163 + pub_r000542_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (sec_r000542_5 + pub_r000542_2 + 47) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (sec_r000542_3 + pub_r000542_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (sec_r000542_14 + pub_r000542_21 + 40) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_121 + pub_r000542_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (stage_v_88 + pub_r000542_21 + 34) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_87 + pub_r000542_18 + 32) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (sec_r000542_6 + pub_r000542_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (sec_r000542_2 + pub_r000542_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_249 + pub_r000542_20 + 22) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (stage_v_73 + pub_r000542_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (sec_r000542_13 + pub_r000542_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (sec_r000542_13 + pub_r000542_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (stage_v_77 + pub_r000542_20 + 33) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (sec_r000542_3 + pub_r000542_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (sec_r000542_15 + pub_r000542_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (stage_v_222 + pub_r000542_2 + 27) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (stage_v_9 + pub_r000542_20 + 37) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (stage_v_75 + pub_r000542_20 + 48) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (sec_r000542_8 + pub_r000542_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (stage_v_10 + pub_r000542_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (stage_v_14 + pub_r000542_21 + 33) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (stage_v_208 + pub_r000542_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (sec_r000542_2 + pub_r000542_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (stage_v_228 + pub_r000542_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (sec_r000542_9 + pub_r000542_10 + 48) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (stage_v_108 + pub_r000542_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (sec_r000542_4 + pub_r000542_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (stage_v_144 + pub_r000542_8 + 21) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (sec_r000542_4 + pub_r000542_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (stage_v_39 + pub_r000542_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (stage_v_54 + pub_r000542_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (stage_v_10 + pub_r000542_21 + 16) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (stage_v_6 + pub_r000542_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (stage_v_227 + pub_r000542_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (sec_r000542_12 + pub_r000542_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (sec_r000542_11 + pub_r000542_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (stage_v_262 + pub_r000542_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (stage_v_16 + pub_r000542_21 + 39) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (stage_v_151 + pub_r000542_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (stage_v_282 + pub_r000542_0 + 4) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (sec_r000542_15 + pub_r000542_10 + 16) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (stage_v_27 + pub_r000542_20 + 46) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (stage_v_132 + pub_r000542_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (stage_v_248 + pub_r000542_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (stage_v_259 + pub_r000542_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (stage_v_71 + pub_r000542_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (sec_r000542_0 + pub_r000542_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (stage_v_250 + pub_r000542_18 + 49) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (stage_v_110 + pub_r000542_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (stage_v_41 + pub_r000542_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (stage_v_86 + pub_r000542_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (stage_v_69 + pub_r000542_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (stage_v_275 + pub_r000542_14 + 49) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (stage_v_106 + pub_r000542_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (stage_v_99 + pub_r000542_20 + 45) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (sec_r000542_3 + pub_r000542_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (stage_v_297 + pub_r000542_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (stage_v_75 + pub_r000542_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (stage_v_268 + pub_r000542_19 + 42) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (sec_r000542_0 + pub_r000542_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (stage_v_26 + pub_r000542_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (sec_r000542_1 + pub_r000542_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (stage_v_29 + pub_r000542_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (stage_v_42 + pub_r000542_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (stage_v_153 + pub_r000542_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (stage_v_50 + pub_r000542_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (stage_v_212 + pub_r000542_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (stage_v_107 + pub_r000542_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (stage_v_213 + pub_r000542_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (stage_v_20 + pub_r000542_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (stage_v_30 + pub_r000542_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (sec_r000542_12 + pub_r000542_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (stage_v_112 + pub_r000542_3 + 45) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (stage_v_20 + pub_r000542_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (sec_r000542_4 + pub_r000542_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (stage_v_225 + pub_r000542_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (stage_v_145 + pub_r000542_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (stage_v_226 + pub_r000542_21 + 33) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (sec_r000542_3 + pub_r000542_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (sec_r000542_6 + pub_r000542_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (stage_v_127 + pub_r000542_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (stage_v_317 + pub_r000542_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (stage_v_203 + pub_r000542_1 + 41) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (sec_r000542_5 + pub_r000542_15 + 35) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (sec_r000542_15 + pub_r000542_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (stage_v_33 + pub_r000542_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (sec_r000542_9 + pub_r000542_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (stage_v_248 + pub_r000542_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (stage_v_19 + pub_r000542_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (stage_v_76 + pub_r000542_20 + 28) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (stage_v_144 + pub_r000542_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (stage_v_136 + pub_r000542_19 + 49) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (sec_r000542_13 + pub_r000542_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (stage_v_50 + pub_r000542_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (sec_r000542_15 + pub_r000542_17 + 7) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (stage_v_104 + pub_r000542_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (sec_r000542_11 + pub_r000542_16 + 47) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (stage_v_39 + pub_r000542_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (stage_v_54 + pub_r000542_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (stage_v_329 + pub_r000542_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (sec_r000542_6 + pub_r000542_14 + 48) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (stage_v_138 + pub_r000542_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (stage_v_313 + pub_r000542_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (stage_v_120 + pub_r000542_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (stage_v_162 + pub_r000542_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (sec_r000542_3 + pub_r000542_6 + 38) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (stage_v_158 + pub_r000542_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (sec_r000542_6 + pub_r000542_18 + 35) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (stage_v_318 + pub_r000542_12 + 20) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (stage_v_7 + pub_r000542_0 + 44) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (sec_r000542_5 + pub_r000542_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (stage_v_64 + pub_r000542_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (sec_r000542_0 + pub_r000542_20 + 42) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (sec_r000542_0 + pub_r000542_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (sec_r000542_3 + pub_r000542_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (stage_v_280 + pub_r000542_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (stage_v_320 + pub_r000542_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (stage_v_366 + pub_r000542_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (stage_v_155 + pub_r000542_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (stage_v_328 + pub_r000542_7 + 16) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (sec_r000542_15 + pub_r000542_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
