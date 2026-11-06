/*
 * Benchmark Program: R000818
 * Security Family: secret_dependent_loops
 * Generator Seed: 581813
 * High Inputs: 21 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000818_1813_0 {
    unsigned char account_id;
    int rate;
    short auth_code;
    short status;
    unsigned char fee;
    int buffer[3];
};

struct Vector3D_R000818_1813_1 {
    int norm_sq;
    short coord_x;
    int coord_y;
    unsigned char heading;
    int pitch;
    short coord_z;
    int buffer[3];
};

struct CipherContext_R000818_1813_2 {
    int flags;
    short tag;
    int iv;
    unsigned char round_key;
    int buffer[3];
};

struct SensorNode_R000818_1813_3 {
    int reading;
    int offset;
    short gain;
    int calib;
    int threshold;
    unsigned char status;
    int buffer[3];
};

union ColorPixel_R000818_1813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000818_1813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000818_1813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_26) & 63;
    acc ^= aux;
    int parity_92 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_92 > 39) {
        acc = (acc + parity_92 * 2 + 5) & 127;
        aux ^= (parity_92 & 15);
    } else {
        acc = (acc - parity_92 + 11) & 127;
        aux += 3;
    }
    int checksum_93 = (aux + st.buffer[1]) & 3;
    switch (checksum_93) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_1(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int phase_56 = (aux + st.buffer[1]) & 3;
    switch (phase_56) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_91 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_91 > 39) {
        acc = (acc + accumulator_91 * 2 + 5) & 127;
        aux ^= (accumulator_91 & 15);
    } else {
        acc = (acc - accumulator_91 + 11) & 127;
        aux += 3;
    }
    int cursor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000818_1813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_28 = (aux + st.buffer[1]) & 3;
    switch (accumulator_28) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_63 = local_arr[aux % 3];
    acc = (acc + anchor_63 * 2) & 127;
    int checksum_50 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_50 > 42) {
        acc = (acc + checksum_50 * 2 + 5) & 127;
        aux ^= (checksum_50 & 15);
    } else {
        acc = (acc - checksum_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_3(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_44 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_44 > 49) {
        acc = (acc + accumulator_44 * 2 + 5) & 127;
        aux ^= (accumulator_44 & 15);
    } else {
        acc = (acc - accumulator_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int anchor_50 = local_arr[aux % 3];
    acc = (acc + anchor_50 * 2) & 127;
    int coefficient_36 = (aux + st.buffer[1]) & 3;
    switch (coefficient_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_40 = (aux + st.buffer[1]) & 3;
    switch (tracker_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_69 > 31) {
        acc = (acc + cursor_69 * 2 + 5) & 127;
        aux ^= (cursor_69 & 15);
    } else {
        acc = (acc - cursor_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int pivot_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_71 = local_arr[aux % 3];
    acc = (acc + window_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000818_1813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_15 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_15 > 10) {
        acc = (acc + tally_15 * 2 + 5) & 127;
        aux ^= (tally_15 & 15);
    } else {
        acc = (acc - tally_15 + 11) & 127;
        aux += 3;
    }
    int weight_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_98 = local_arr[aux % 3];
    acc = (acc + stride_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int mask_55 = local_arr[aux % 3];
    acc = (acc + mask_55 * 2) & 127;
    int sample_39 = (aux + st.buffer[1]) & 3;
    switch (sample_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_9(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_23 = (aux + st.buffer[1]) & 3;
    switch (quotient_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_75 = local_arr[aux % 3];
    acc = (acc + segment_75 * 2) & 127;
    int threshold_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000818_1813_10(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_66) & 63;
    acc ^= aux;
    int offset_68 = (aux + st.buffer[1]) & 3;
    switch (offset_68) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_23 = local_arr[aux % 3];
    acc = (acc + segment_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_96 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_96 > 12) {
        acc = (acc + mask_96 * 2 + 5) & 127;
        aux ^= (mask_96 & 15);
    } else {
        acc = (acc - mask_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int coefficient_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_43) & 63;
    acc ^= aux;
    int quotient_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_95 > 32) {
        acc = (acc + quotient_95 * 2 + 5) & 127;
        aux ^= (quotient_95 & 15);
    } else {
        acc = (acc - quotient_95 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_24 = (aux + st.buffer[1]) & 3;
    switch (index_reg_24) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int delta_64 = local_arr[aux % 3];
    acc = (acc + delta_64 * 2) & 127;
    int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_49) & 63;
    acc ^= aux;
    int quantum_28 = (aux + st.buffer[1]) & 3;
    switch (quantum_28) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_88 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_88 > 47) {
        acc = (acc + stride_88 * 2 + 5) & 127;
        aux ^= (stride_88 & 15);
    } else {
        acc = (acc - stride_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_14(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int window_80 = (st.buffer[0] * 3 + aux) & 63;
    if (window_80 > 11) {
        acc = (acc + window_80 * 2 + 5) & 127;
        aux ^= (window_80 & 15);
    } else {
        acc = (acc - window_80 + 11) & 127;
        aux += 3;
    }
    int index_reg_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000818_1813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_25 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_25 > 18) {
        acc = (acc + tally_25 * 2 + 5) & 127;
        aux ^= (tally_25 & 15);
    } else {
        acc = (acc - tally_25 + 11) & 127;
        aux += 3;
    }
    int parity_98 = (aux + st.buffer[1]) & 3;
    switch (parity_98) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_16(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_64 = local_arr[aux % 3];
    acc = (acc + residue_64 * 2) & 127;
    int accumulator_47 = (aux + st.buffer[1]) & 3;
    switch (accumulator_47) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_17(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_57 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_57 > 29) {
        acc = (acc + residue_57 * 2 + 5) & 127;
        aux ^= (residue_57 & 15);
    } else {
        acc = (acc - residue_57 + 11) & 127;
        aux += 3;
    }
    int anchor_47 = (aux + st.buffer[1]) & 3;
    switch (anchor_47) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_18(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int parity_41 = local_arr[aux % 3];
    acc = (acc + parity_41 * 2) & 127;
    int vector_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_10) & 63;
    acc ^= aux;
    int window_42 = (aux + st.buffer[1]) & 3;
    switch (window_42) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000818_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_18 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_18 > 25) {
        acc = (acc + scale_18 * 2 + 5) & 127;
        aux ^= (scale_18 & 15);
    } else {
        acc = (acc - scale_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_80 = (aux + st.buffer[1]) & 3;
    switch (vector_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000818_1813_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int pivot_70 = (aux + st.buffer[1]) & 3;
    switch (pivot_70) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_49 = local_arr[aux % 3];
    acc = (acc + mask_49 * 2) & 127;
    int offset_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000818_1813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000818_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int mask_73 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_73 > 36) {
        acc = (acc + mask_73 * 2 + 5) & 127;
        aux ^= (mask_73 & 15);
    } else {
        acc = (acc - mask_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_63 = local_arr[aux % 3];
    acc = (acc + weight_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000818_1813_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000818_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int stride_76 = local_arr[aux % 3];
    acc = (acc + stride_76 * 2) & 127;
    int window_51 = (st.buffer[0] * 3 + aux) & 63;
    if (window_51 > 34) {
        acc = (acc + window_51 * 2 + 5) & 127;
        aux ^= (window_51 & 15);
    } else {
        acc = (acc - window_51 + 11) & 127;
        aux += 3;
    }
    int quotient_18 = (aux + st.buffer[1]) & 3;
    switch (quotient_18) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000818_0;
    int sec_r000818_1;
    int sec_r000818_2;
    int sec_r000818_3;
    int sec_r000818_4;
    int sec_r000818_5;
    int sec_r000818_6;
    int sec_r000818_7;
    int sec_r000818_8;
    int sec_r000818_9;
    int sec_r000818_10;
    int sec_r000818_11;
    int sec_r000818_12;
    int sec_r000818_13;
    int sec_r000818_14;
    int sec_r000818_15;
    int sec_r000818_16;
    int sec_r000818_17;
    int sec_r000818_18;
    int sec_r000818_19;
    int sec_r000818_20;
    int pub_r000818_0;
    int pub_r000818_1;
    int pub_r000818_2;
    int pub_r000818_3;
    int pub_r000818_4;
    int pub_r000818_5;
    int pub_r000818_6;
    int pub_r000818_7;
    int pub_r000818_8;
    int pub_r000818_9;
    int pub_r000818_10;
    int pub_r000818_11;
    int pub_r000818_12;
    int pub_r000818_13;
    int pub_r000818_14;
    int pub_r000818_15;
    int pub_r000818_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000818_0 >= -100 && pub_r000818_0 <= 100);
    __CPROVER_assume(pub_r000818_1 >= -100 && pub_r000818_1 <= 100);
    __CPROVER_assume(pub_r000818_2 >= -100 && pub_r000818_2 <= 100);
    __CPROVER_assume(pub_r000818_3 >= -100 && pub_r000818_3 <= 100);
    __CPROVER_assume(pub_r000818_4 >= -100 && pub_r000818_4 <= 100);
    __CPROVER_assume(pub_r000818_5 >= -100 && pub_r000818_5 <= 100);
    __CPROVER_assume(pub_r000818_6 >= -100 && pub_r000818_6 <= 100);
    __CPROVER_assume(pub_r000818_7 >= -100 && pub_r000818_7 <= 100);
    __CPROVER_assume(pub_r000818_8 >= -100 && pub_r000818_8 <= 100);
    __CPROVER_assume(pub_r000818_9 >= -100 && pub_r000818_9 <= 100);
    __CPROVER_assume(pub_r000818_10 >= -100 && pub_r000818_10 <= 100);
    __CPROVER_assume(pub_r000818_11 >= -100 && pub_r000818_11 <= 100);
    __CPROVER_assume(pub_r000818_12 >= -100 && pub_r000818_12 <= 100);
    __CPROVER_assume(pub_r000818_13 >= -100 && pub_r000818_13 <= 100);
    __CPROVER_assume(pub_r000818_14 >= -100 && pub_r000818_14 <= 100);
    __CPROVER_assume(pub_r000818_15 >= -100 && pub_r000818_15 <= 100);
    __CPROVER_assume(pub_r000818_16 >= -100 && pub_r000818_16 <= 100);
    __CPROVER_assume(sec_r000818_0 >= 0 && sec_r000818_0 <= 255);
    __CPROVER_assume(sec_r000818_1 >= 0 && sec_r000818_1 <= 255);
    __CPROVER_assume(sec_r000818_2 >= 0 && sec_r000818_2 <= 255);
    __CPROVER_assume(sec_r000818_3 >= 0 && sec_r000818_3 <= 255);
    __CPROVER_assume(sec_r000818_4 >= 0 && sec_r000818_4 <= 255);
    __CPROVER_assume(sec_r000818_5 >= 0 && sec_r000818_5 <= 255);
    __CPROVER_assume(sec_r000818_6 >= 0 && sec_r000818_6 <= 255);
    __CPROVER_assume(sec_r000818_7 >= 0 && sec_r000818_7 <= 255);
    __CPROVER_assume(sec_r000818_8 >= 0 && sec_r000818_8 <= 255);
    __CPROVER_assume(sec_r000818_9 >= 0 && sec_r000818_9 <= 255);
    __CPROVER_assume(sec_r000818_10 >= 0 && sec_r000818_10 <= 255);
    __CPROVER_assume(sec_r000818_11 >= 0 && sec_r000818_11 <= 255);
    __CPROVER_assume(sec_r000818_12 >= 0 && sec_r000818_12 <= 255);
    __CPROVER_assume(sec_r000818_13 >= 0 && sec_r000818_13 <= 255);
    __CPROVER_assume(sec_r000818_14 >= 0 && sec_r000818_14 <= 255);
    __CPROVER_assume(sec_r000818_15 >= 0 && sec_r000818_15 <= 255);
    __CPROVER_assume(sec_r000818_16 >= 0 && sec_r000818_16 <= 255);
    __CPROVER_assume(sec_r000818_17 >= 0 && sec_r000818_17 <= 255);
    __CPROVER_assume(sec_r000818_18 >= 0 && sec_r000818_18 <= 255);
    __CPROVER_assume(sec_r000818_19 >= 0 && sec_r000818_19 <= 255);
    __CPROVER_assume(sec_r000818_20 >= 0 && sec_r000818_20 <= 255);

    struct Transaction_R000818_1813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000818_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000818_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000818_0 + 7) & 15;
    struct Vector3D_R000818_1813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000818_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000818_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000818_0 + 9) & 15;
    struct CipherContext_R000818_1813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000818_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000818_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000818_0 + 11) & 15;
    struct SensorNode_R000818_1813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000818_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000818_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000818_0 + 13) & 15;

    union ColorPixel_R000818_1813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 34) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 49) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 14) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 29) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 40) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 55) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

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
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
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
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 40) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 55) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 24) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 39) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 21) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 36) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 13) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 28) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_20 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000818_12) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_6 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000818_16) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000818_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000818_8) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000818_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000818_13) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000818_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_15 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000818_1) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000818_8) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_12 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000818_4) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000818_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_20 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000818_14) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000818_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000818_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000818_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000818_7) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000818_6) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000818_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000818_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000818_2) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000818_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000818_11) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_3 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000818_14) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000818_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_7 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000818_0) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000818_13) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000818_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000818_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000818_11) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000818_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000818_15) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000818_1) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000818_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_13 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000818_13) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000818_7) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_2 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000818_0) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000818_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000818_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000818_1) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000818_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000818_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000818_2) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000818_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_10 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_2 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000818_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000818_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_13 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000818_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_5 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000818_0) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000818_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_10 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000818_8) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000818_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000818_16) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000818_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_18 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000818_14) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000818_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_11 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000818_1) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000818_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000818_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000818_11) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000818_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000818_14) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000818_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_18 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000818_15) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000818_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000818_13) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000818_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000818_11) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000818_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_18 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000818_12) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000818_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_3 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000818_4) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000818_15) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000818_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_10 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000818_8) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000818_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000818_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000818_12) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000818_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000818_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000818_1) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000818_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000818_4) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000818_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000818_0) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000818_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000818_6) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000818_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000818_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000818_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000818_7) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000818_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000818_3) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000818_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000818_5) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000818_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000818_4) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000818_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_12 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000818_2) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000818_15) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000818_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000818_10) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000818_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000818_3 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000818_9) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000818_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
