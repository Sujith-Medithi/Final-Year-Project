/*
 * Benchmark Program: R001240
 * Security Family: mixed_control_data
 * Generator Seed: 624013
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001240_4013_0 {
    int round_key;
    int nonce;
    unsigned char iv;
    int tag;
    int buffer[3];
};

struct Transaction_R001240_4013_1 {
    int auth_code;
    int fee;
    unsigned char rate;
    short balance;
    int account_id;
    int buffer[3];
};

struct AudioFrame_R001240_4013_2 {
    short channels;
    int sample_rate;
    int gain;
    int buffer[3];
};

union ColorPixel_R001240_4013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001240_4013_0(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_53 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_53 > 38) {
        acc = (acc + residue_53 * 2 + 5) & 127;
        aux ^= (residue_53 & 15);
    } else {
        acc = (acc - residue_53 + 11) & 127;
        aux += 3;
    }
    int mask_80 = 0;
    for (int k = 0; k < 3; k++) {
        mask_80 = (mask_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int damping_69 = local_arr[aux % 3];
    acc = (acc + damping_69 * 2) & 127;
    int anchor_94 = (aux + st.buffer[1]) & 3;
    switch (anchor_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_55 = (aux + st.buffer[1]) & 3;
    switch (quantum_55) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_15) & 63;
    acc ^= aux;
    int checksum_42 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_42 > 21) {
        acc = (acc + checksum_42 * 2 + 5) & 127;
        aux ^= (checksum_42 & 15);
    } else {
        acc = (acc - checksum_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_41 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_41 = (coefficient_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_41) & 127;
    }
    int vector_98 = (aux + st.buffer[1]) & 3;
    switch (vector_98) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int margin_70 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_70 > 25) {
        acc = (acc + margin_70 * 2 + 5) & 127;
        aux ^= (margin_70 & 15);
    } else {
        acc = (acc - margin_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_19 = local_arr[aux % 3];
    acc = (acc + damping_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_86 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_86 = (cursor_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_86) & 127;
    }
    int threshold_30 = (aux + st.buffer[1]) & 3;
    switch (threshold_30) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_60 = local_arr[aux % 3];
    acc = (acc + pivot_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_6(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int checksum_81 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_81 > 16) {
        acc = (acc + checksum_81 * 2 + 5) & 127;
        aux ^= (checksum_81 & 15);
    } else {
        acc = (acc - checksum_81 + 11) & 127;
        aux += 3;
    }
    int checksum_19 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_19 = (checksum_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_19) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_7(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int stride_27 = local_arr[aux % 3];
    acc = (acc + stride_27 * 2) & 127;
    int quantum_12 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_12 = (quantum_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_12) & 127;
    }
    int phase_58 = (aux + st.buffer[1]) & 3;
    switch (phase_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_8(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_63 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_63 > 13) {
        acc = (acc + vector_63 * 2 + 5) & 127;
        aux ^= (vector_63 & 15);
    } else {
        acc = (acc - vector_63 + 11) & 127;
        aux += 3;
    }
    int sample_53 = 0;
    for (int k = 0; k < 3; k++) {
        sample_53 = (sample_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_53) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_9(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int cursor_64 = local_arr[aux % 3];
    acc = (acc + cursor_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_40 = 0;
    for (int k = 0; k < 2; k++) {
        residue_40 = (residue_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_40) & 127;
    }
    int coefficient_95 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_95 > 21) {
        acc = (acc + coefficient_95 * 2 + 5) & 127;
        aux ^= (coefficient_95 & 15);
    } else {
        acc = (acc - coefficient_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_10(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int scale_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_87 = local_arr[aux % 3];
    acc = (acc + metric_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_26 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_26 > 34) {
        acc = (acc + segment_26 * 2 + 5) & 127;
        aux ^= (segment_26 & 15);
    } else {
        acc = (acc - segment_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_94 = local_arr[aux % 3];
    acc = (acc + delta_94 * 2) & 127;
    int pivot_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_20) & 63;
    acc ^= aux;
    int scale_91 = (aux + st.buffer[1]) & 3;
    switch (scale_91) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_33 = (aux + st.buffer[1]) & 3;
    switch (anchor_33) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_22) & 63;
    acc ^= aux;
    int quotient_88 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_88 > 29) {
        acc = (acc + quotient_88 * 2 + 5) & 127;
        aux ^= (quotient_88 & 15);
    } else {
        acc = (acc - quotient_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_81 = 0;
    for (int k = 0; k < 2; k++) {
        residue_81 = (residue_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_81) & 127;
    }
    int cursor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_32) & 63;
    acc ^= aux;
    int quotient_31 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_31 > 14) {
        acc = (acc + quotient_31 * 2 + 5) & 127;
        aux ^= (quotient_31 & 15);
    } else {
        acc = (acc - quotient_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_40 = 0;
    for (int k = 0; k < 3; k++) {
        stride_40 = (stride_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_40) & 127;
    }
    int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_15(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_13 = (aux + st.buffer[1]) & 3;
    switch (index_reg_13) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_40 = local_arr[aux % 3];
    acc = (acc + tally_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001240_4013_16(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001240_4013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_83 = 0;
    for (int k = 0; k < 2; k++) {
        mask_83 = (mask_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_83) & 127;
    }
    int tracker_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_18) & 63;
    acc ^= aux;
    int quantum_72 = (aux + st.buffer[1]) & 3;
    switch (quantum_72) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int pivot_74 = local_arr[aux % 3];
    acc = (acc + pivot_74 * 2) & 127;
    int coefficient_95 = (aux + st.buffer[1]) & 3;
    switch (coefficient_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_92 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_92 = (threshold_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_92) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_71 = local_arr[aux % 3];
    acc = (acc + offset_71 * 2) & 127;
    int mask_10 = (aux + st.buffer[1]) & 3;
    switch (mask_10) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_97 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_97 > 19) {
        acc = (acc + damping_97 * 2 + 5) & 127;
        aux ^= (damping_97 & 15);
    } else {
        acc = (acc - damping_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_19(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int pivot_12 = local_arr[aux % 3];
    acc = (acc + pivot_12 * 2) & 127;
    int cursor_58 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_58 > 14) {
        acc = (acc + cursor_58 * 2 + 5) & 127;
        aux ^= (cursor_58 & 15);
    } else {
        acc = (acc - cursor_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int metric_41 = (aux + st.buffer[1]) & 3;
    switch (metric_41) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_11 = 0;
    for (int k = 0; k < 2; k++) {
        damping_11 = (damping_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001240_4013_21(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001240_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_33 = (aux + st.buffer[1]) & 3;
    switch (window_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001240_4013_22(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001240_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int pivot_56 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_56 > 46) {
        acc = (acc + pivot_56 * 2 + 5) & 127;
        aux ^= (pivot_56 & 15);
    } else {
        acc = (acc - pivot_56 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_35 = local_arr[aux % 3];
    acc = (acc + sample_35 * 2) & 127;
    int pivot_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_26) & 63;
    acc ^= aux;
    int sample_29 = 0;
    for (int k = 0; k < 2; k++) {
        sample_29 = (sample_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_29) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001240_0;
    int sec_r001240_1;
    int sec_r001240_2;
    int sec_r001240_3;
    int sec_r001240_4;
    int sec_r001240_5;
    int sec_r001240_6;
    int sec_r001240_7;
    int sec_r001240_8;
    int sec_r001240_9;
    int sec_r001240_10;
    int sec_r001240_11;
    int sec_r001240_12;
    int sec_r001240_13;
    int sec_r001240_14;
    int sec_r001240_15;
    int sec_r001240_16;
    int sec_r001240_17;
    int sec_r001240_18;
    int sec_r001240_19;
    int sec_r001240_20;
    int sec_r001240_21;
    int sec_r001240_22;
    int sec_r001240_23;
    int pub_r001240_0;
    int pub_r001240_1;
    int pub_r001240_2;
    int pub_r001240_3;
    int pub_r001240_4;
    int pub_r001240_5;
    int pub_r001240_6;
    int pub_r001240_7;
    int pub_r001240_8;
    int pub_r001240_9;
    int pub_r001240_10;
    int pub_r001240_11;
    int pub_r001240_12;
    int pub_r001240_13;
    int pub_r001240_14;
    int pub_r001240_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001240_0 >= -100 && pub_r001240_0 <= 100);
    __CPROVER_assume(pub_r001240_1 >= -100 && pub_r001240_1 <= 100);
    __CPROVER_assume(pub_r001240_2 >= -100 && pub_r001240_2 <= 100);
    __CPROVER_assume(pub_r001240_3 >= -100 && pub_r001240_3 <= 100);
    __CPROVER_assume(pub_r001240_4 >= -100 && pub_r001240_4 <= 100);
    __CPROVER_assume(pub_r001240_5 >= -100 && pub_r001240_5 <= 100);
    __CPROVER_assume(pub_r001240_6 >= -100 && pub_r001240_6 <= 100);
    __CPROVER_assume(pub_r001240_7 >= -100 && pub_r001240_7 <= 100);
    __CPROVER_assume(pub_r001240_8 >= -100 && pub_r001240_8 <= 100);
    __CPROVER_assume(pub_r001240_9 >= -100 && pub_r001240_9 <= 100);
    __CPROVER_assume(pub_r001240_10 >= -100 && pub_r001240_10 <= 100);
    __CPROVER_assume(pub_r001240_11 >= -100 && pub_r001240_11 <= 100);
    __CPROVER_assume(pub_r001240_12 >= -100 && pub_r001240_12 <= 100);
    __CPROVER_assume(pub_r001240_13 >= -100 && pub_r001240_13 <= 100);
    __CPROVER_assume(pub_r001240_14 >= -100 && pub_r001240_14 <= 100);
    __CPROVER_assume(pub_r001240_15 >= -100 && pub_r001240_15 <= 100);
    __CPROVER_assume(sec_r001240_0 >= 0 && sec_r001240_0 <= 255);
    __CPROVER_assume(sec_r001240_1 >= 0 && sec_r001240_1 <= 255);
    __CPROVER_assume(sec_r001240_2 >= 0 && sec_r001240_2 <= 255);
    __CPROVER_assume(sec_r001240_3 >= 0 && sec_r001240_3 <= 255);
    __CPROVER_assume(sec_r001240_4 >= 0 && sec_r001240_4 <= 255);
    __CPROVER_assume(sec_r001240_5 >= 0 && sec_r001240_5 <= 255);
    __CPROVER_assume(sec_r001240_6 >= 0 && sec_r001240_6 <= 255);
    __CPROVER_assume(sec_r001240_7 >= 0 && sec_r001240_7 <= 255);
    __CPROVER_assume(sec_r001240_8 >= 0 && sec_r001240_8 <= 255);
    __CPROVER_assume(sec_r001240_9 >= 0 && sec_r001240_9 <= 255);
    __CPROVER_assume(sec_r001240_10 >= 0 && sec_r001240_10 <= 255);
    __CPROVER_assume(sec_r001240_11 >= 0 && sec_r001240_11 <= 255);
    __CPROVER_assume(sec_r001240_12 >= 0 && sec_r001240_12 <= 255);
    __CPROVER_assume(sec_r001240_13 >= 0 && sec_r001240_13 <= 255);
    __CPROVER_assume(sec_r001240_14 >= 0 && sec_r001240_14 <= 255);
    __CPROVER_assume(sec_r001240_15 >= 0 && sec_r001240_15 <= 255);
    __CPROVER_assume(sec_r001240_16 >= 0 && sec_r001240_16 <= 255);
    __CPROVER_assume(sec_r001240_17 >= 0 && sec_r001240_17 <= 255);
    __CPROVER_assume(sec_r001240_18 >= 0 && sec_r001240_18 <= 255);
    __CPROVER_assume(sec_r001240_19 >= 0 && sec_r001240_19 <= 255);
    __CPROVER_assume(sec_r001240_20 >= 0 && sec_r001240_20 <= 255);
    __CPROVER_assume(sec_r001240_21 >= 0 && sec_r001240_21 <= 255);
    __CPROVER_assume(sec_r001240_22 >= 0 && sec_r001240_22 <= 255);
    __CPROVER_assume(sec_r001240_23 >= 0 && sec_r001240_23 <= 255);

    struct CipherContext_R001240_4013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001240_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001240_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001240_0 + 7) & 15;
    struct Transaction_R001240_4013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001240_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001240_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001240_0 + 9) & 15;
    struct AudioFrame_R001240_4013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001240_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001240_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001240_0 + 11) & 15;

    union ColorPixel_R001240_4013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001240_4013_0(sec_r001240_0, pub_r001240_1);
    int helper_flow_1 = fn_R001240_4013_1(sec_r001240_1, sec_r001240_2, pub_r001240_3, pub_r001240_4, pub_r001240_5);
    int helper_flow_2 = fn_R001240_4013_2(sec_r001240_2, pub_r001240_3, pub_r001240_4, pub_r001240_5);
    int helper_flow_3 = fn_R001240_4013_3(sec_r001240_3, pub_r001240_4, pub_r001240_5, pub_r001240_6);
    int helper_flow_4 = fn_R001240_4013_4(sec_r001240_4, sec_r001240_5, pub_r001240_6, pub_r001240_7, pub_r001240_8);
    int helper_flow_5 = fn_R001240_4013_5(sec_r001240_5, sec_r001240_6, pub_r001240_7, pub_r001240_8);
    int helper_flow_6 = fn_R001240_4013_6(sec_r001240_6, sec_r001240_7);
    int helper_flow_7 = fn_R001240_4013_7(sec_r001240_7, sec_r001240_8);
    int helper_flow_8 = fn_R001240_4013_8(sec_r001240_8, sec_r001240_9, pub_r001240_10);
    int helper_flow_9 = fn_R001240_4013_9(sec_r001240_9, sec_r001240_10);
    int helper_flow_10 = fn_R001240_4013_10(sec_r001240_10, pub_r001240_11, pub_r001240_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001240_16 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_0 > 27) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001240_4 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_1 > 24) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001240_1 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_2 > 46) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001240_13 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_3 > 47) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001240_10 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_4 > 39) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001240_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001240_12 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_6 > 41) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001240_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001240_15 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_8 > 36) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001240_0 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_9 > 22) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001240_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_11 > 24) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_12 > 39) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001240_15 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_13 > 45) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001240_14 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_15 > 32) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001240_12 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_16 > 39) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001240_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_18 > 30) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_19 > 22) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001240_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001240_6 ^ 0x2A) * 2 + pub_r001240_0) & 127;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001240_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001240_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001240_14 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_24 > 30) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001240_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001240_1 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_26 > 30) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_27 > 38) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_28 > 36) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001240_2 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_29 > 38) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_30 > 46) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001240_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_32 > 24) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_33 > 22) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_34 > 41) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001240_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001240_1 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_36 > 47) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001240_6 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_37 > 43) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_38 > 50) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001240_18 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_39 > 43) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001240_15 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_40 > 33) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_41 > 22) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001240_17 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_42 > 20) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001240_0) & 127;
    if (stage_v_43 > 45) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001240_9 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_44 > 48) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001240_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001240_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001240_6 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_47 > 24) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001240_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001240_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001240_9 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_50 > 47) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001240_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001240_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_53 > 20) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_54 > 23) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_55 > 28) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_56 > 40) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001240_0 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_57 > 42) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_58 > 28) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_59 > 35) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_60 > 35) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_61 > 48) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001240_0 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_62 > 40) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_63 > 27) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_64 > 40) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001240_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001240_5 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_66 > 27) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001240_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_68 > 22) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001240_8 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001240_10 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_70 > 30) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_71 > 26) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_72 > 20) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_73 > 44) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_74 > 21) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001240_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001240_4 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_76 > 47) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001240_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_78 > 48) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_79 > 40) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_80 > 31) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_81 > 41) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001240_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_83 > 45) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001240_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001240_8 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_85 > 50) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001240_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_87 > 46) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_88 > 24) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_89 > 35) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001240_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_91 > 40) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_92 > 49) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001240_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001240_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_95 > 43) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001240_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_97 > 35) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001240_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001240_7 ^ 0x2A) * 2 + pub_r001240_0) & 127;
    if (stage_v_99 > 28) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001240_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001240_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001240_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_103 > 49) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_104 > 22) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_105 > 44) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_106 > 50) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_107 > 26) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_108 > 29) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001240_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_110 > 44) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001240_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_112 > 46) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_113 > 33) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_114 > 29) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001240_3 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_115 > 41) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_116 > 40) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_117 > 30) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001240_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001240_4 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_119 > 29) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_120 > 50) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_121 > 32) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_122 > 23) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_123 > 41) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001240_8 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_124 > 30) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001240_18 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_125 > 43) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001240_2 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_126 > 23) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001240_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001240_7 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_128 > 21) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001240_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_130 > 32) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_131 > 34) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001240_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_133 > 28) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001240_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_136 > 33) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_137 > 22) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_138 > 35) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_139 > 30) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001240_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_141 > 28) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_142 > 21) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001240_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_145 > 37) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_146 > 21) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001240_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_148 > 50) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_149 > 23) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_150 > 49) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_151 > 39) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_152 > 48) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001240_5 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_153 > 32) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_154 > 50) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001240_9 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_155 > 22) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001240_15 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_156 > 45) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_157 > 45) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_158 > 45) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001240_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_160 > 39) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_161 > 35) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_163 > 30) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001240_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001240_16 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_165 > 32) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001240_10 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_166 > 37) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_167 > 24) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_168 > 45) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_169 > 26) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_170 > 39) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r001240_7 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_171 > 24) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001240_22 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_172 > 41) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_173 > 20) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001240_8 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_174 > 22) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_175 > 25) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_176 > 32) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_177 > 49) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_178 > 36) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001240_17 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_179 > 33) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001240_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_181 > 21) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001240_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_183 > 48) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_184 > 46) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_185 > 40) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001240_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_187 > 35) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_188 > 23) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_189 > 29) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_190 > 44) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001240_3) & 127;
    if (stage_v_191 > 46) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_192 > 42) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001240_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_194 > 50) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001240_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_196 > 49) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_197 > 45) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_198 > 41) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001240_2) & 127;
    if (stage_v_199 > 37) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001240_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001240_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_202 > 47) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_203 > 48) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_202 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_204 > 25) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((sec_r001240_3 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_205 > 36) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001240_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001240_15 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_207 > 44) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001240_4) & 127;
    if (stage_v_208 > 33) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_209 > 28) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_210 > 37) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001240_8 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_211 > 50) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_171 ^ 0x2A) * 2 + pub_r001240_8) & 127;
    if (stage_v_212 > 47) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_213 > 24) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001240_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_216 > 33) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001240_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_196 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_218 > 34) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001240_11) & 127;
    if (stage_v_219 > 43) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001240_0) & 127;
    if (stage_v_220 > 38) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_221 > 33) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_219 ^ 0x2A) * 2 + pub_r001240_9) & 127;
    if (stage_v_222 > 24) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_223 > 39) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001240_12) & 127;
    if (stage_v_224 > 48) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001240_10) & 127;
    if (stage_v_225 > 22) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_208 ^ 0x2A) * 2 + pub_r001240_13) & 127;
    if (stage_v_226 > 30) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001240_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001240_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_213 ^ 0x2A) * 2 + pub_r001240_14) & 127;
    if (stage_v_229 > 33) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001240_15) & 127;
    if (stage_v_230 > 33) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_231 > 36) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001240_5) & 127;
    if (stage_v_232 > 40) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_210 ^ 0x2A) * 2 + pub_r001240_1) & 127;
    if (stage_v_233 > 50) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001240_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r001240_1 ^ 0x2A) * 2 + pub_r001240_6) & 127;
    if (stage_v_235 > 22) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_208 ^ 0x2A) * 2 + pub_r001240_7) & 127;
    if (stage_v_236 > 46) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
