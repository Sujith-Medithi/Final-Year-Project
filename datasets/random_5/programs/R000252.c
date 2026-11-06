/*
 * Benchmark Program: R000252
 * Security Family: direct_leakage
 * Generator Seed: 525213
 * High Inputs: 20 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000252_5213_0 {
    short coord_x;
    short pitch;
    int coord_z;
    unsigned char heading;
    int norm_sq;
    int buffer[3];
};

struct StreamBuffer_R000252_5213_1 {
    unsigned char watermark;
    unsigned char capacity;
    int tail;
    int state;
    int buffer[3];
};

struct MatrixBlock_R000252_5213_2 {
    int scale;
    int dim;
    short trace;
    int buffer[3];
};

union ColorPixel_R000252_5213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000252_5213_0(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_87 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_87 > 24) {
        acc = (acc + coefficient_87 * 2 + 5) & 127;
        aux ^= (coefficient_87 & 15);
    } else {
        acc = (acc - coefficient_87 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_96 = local_arr[aux % 3];
    acc = (acc + quotient_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_1(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_21 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_21 > 12) {
        acc = (acc + quantum_21 * 2 + 5) & 127;
        aux ^= (quantum_21 & 15);
    } else {
        acc = (acc - quantum_21 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int segment_49 = local_arr[aux % 3];
    acc = (acc + segment_49 * 2) & 127;
    int factor_36 = (aux + st.buffer[1]) & 3;
    switch (factor_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000252_5213_3(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int checksum_96 = local_arr[aux % 3];
    acc = (acc + checksum_96 * 2) & 127;
    int segment_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_93) & 63;
    acc ^= aux;
    int anchor_71 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_71 > 43) {
        acc = (acc + anchor_71 * 2 + 5) & 127;
        aux ^= (anchor_71 & 15);
    } else {
        acc = (acc - anchor_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_4(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_61 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_61 > 27) {
        acc = (acc + quantum_61 * 2 + 5) & 127;
        aux ^= (quantum_61 & 15);
    } else {
        acc = (acc - quantum_61 + 11) & 127;
        aux += 3;
    }
    int coefficient_72 = (aux + st.buffer[1]) & 3;
    switch (coefficient_72) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_19 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_19 > 41) {
        acc = (acc + weight_19 * 2 + 5) & 127;
        aux ^= (weight_19 & 15);
    } else {
        acc = (acc - weight_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_54 = (aux + st.buffer[1]) & 3;
    switch (pivot_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_22 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_22 > 25) {
        acc = (acc + delta_22 * 2 + 5) & 127;
        aux ^= (delta_22 & 15);
    } else {
        acc = (acc - delta_22 + 11) & 127;
        aux += 3;
    }
    int checksum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_11) & 63;
    acc ^= aux;
    int checksum_25 = (aux + st.buffer[1]) & 3;
    switch (checksum_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_25) & 63;
    acc ^= aux;
    int offset_65 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_65 > 28) {
        acc = (acc + offset_65 * 2 + 5) & 127;
        aux ^= (offset_65 & 15);
    } else {
        acc = (acc - offset_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_9(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_38) & 63;
    acc ^= aux;
    int sample_35 = (aux + st.buffer[1]) & 3;
    switch (sample_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_10(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_11(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int index_reg_39 = local_arr[aux % 3];
    acc = (acc + index_reg_39 * 2) & 127;
    int quotient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_12(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_75) & 63;
    acc ^= aux;
    int vector_26 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_26 > 47) {
        acc = (acc + vector_26 * 2 + 5) & 127;
        aux ^= (vector_26 & 15);
    } else {
        acc = (acc - vector_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_13(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_65 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_65 > 28) {
        acc = (acc + accumulator_65 * 2 + 5) & 127;
        aux ^= (accumulator_65 & 15);
    } else {
        acc = (acc - accumulator_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_14(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_63 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_63 > 38) {
        acc = (acc + delta_63 * 2 + 5) & 127;
        aux ^= (delta_63 & 15);
    } else {
        acc = (acc - delta_63 + 11) & 127;
        aux += 3;
    }
    int tracker_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_20 = local_arr[aux % 3];
    acc = (acc + index_reg_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_15(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int accumulator_20 = (aux + st.buffer[1]) & 3;
    switch (accumulator_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_79 = local_arr[aux % 3];
    acc = (acc + quantum_79 * 2) & 127;
    int tally_65 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_65 > 48) {
        acc = (acc + tally_65 * 2 + 5) & 127;
        aux ^= (tally_65 & 15);
    } else {
        acc = (acc - tally_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_16(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_46 = local_arr[aux % 3];
    acc = (acc + residue_46 * 2) & 127;
    int weight_32 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_32 > 17) {
        acc = (acc + weight_32 * 2 + 5) & 127;
        aux ^= (weight_32 & 15);
    } else {
        acc = (acc - weight_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000252_5213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int index_reg_28 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_28 > 29) {
        acc = (acc + index_reg_28 * 2 + 5) & 127;
        aux ^= (index_reg_28 & 15);
    } else {
        acc = (acc - index_reg_28 + 11) & 127;
        aux += 3;
    }
    int sample_83 = (aux + st.buffer[1]) & 3;
    switch (sample_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_53 = local_arr[aux % 3];
    acc = (acc + tracker_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int tally_98 = local_arr[aux % 3];
    acc = (acc + tally_98 * 2) & 127;
    int sample_88 = (aux + st.buffer[1]) & 3;
    switch (sample_88) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000252_5213_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_35 = (aux + st.buffer[1]) & 3;
    switch (bound_35) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int cursor_75 = local_arr[aux % 3];
    acc = (acc + cursor_75 * 2) & 127;
    int residue_50 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_50 > 35) {
        acc = (acc + residue_50 * 2 + 5) & 127;
        aux ^= (residue_50 & 15);
    } else {
        acc = (acc - residue_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_21(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000252_5213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int accumulator_76 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_76 > 31) {
        acc = (acc + accumulator_76 * 2 + 5) & 127;
        aux ^= (accumulator_76 & 15);
    } else {
        acc = (acc - accumulator_76 + 11) & 127;
        aux += 3;
    }
    int mask_21 = (aux + st.buffer[1]) & 3;
    switch (mask_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000252_5213_22(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000252_5213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_59 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_59 > 49) {
        acc = (acc + bound_59 * 2 + 5) & 127;
        aux ^= (bound_59 & 15);
    } else {
        acc = (acc - bound_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_52 = local_arr[aux % 3];
    acc = (acc + quotient_52 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000252_0;
    int sec_r000252_1;
    int sec_r000252_2;
    int sec_r000252_3;
    int sec_r000252_4;
    int sec_r000252_5;
    int sec_r000252_6;
    int sec_r000252_7;
    int sec_r000252_8;
    int sec_r000252_9;
    int sec_r000252_10;
    int sec_r000252_11;
    int sec_r000252_12;
    int sec_r000252_13;
    int sec_r000252_14;
    int sec_r000252_15;
    int sec_r000252_16;
    int sec_r000252_17;
    int sec_r000252_18;
    int sec_r000252_19;
    int pub_r000252_0;
    int pub_r000252_1;
    int pub_r000252_2;
    int pub_r000252_3;
    int pub_r000252_4;
    int pub_r000252_5;
    int pub_r000252_6;
    int pub_r000252_7;
    int pub_r000252_8;
    int pub_r000252_9;
    int pub_r000252_10;
    int pub_r000252_11;
    int pub_r000252_12;
    int pub_r000252_13;
    int pub_r000252_14;
    int pub_r000252_15;
    int pub_r000252_16;
    int pub_r000252_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000252_0 >= -100 && pub_r000252_0 <= 100);
    __CPROVER_assume(pub_r000252_1 >= -100 && pub_r000252_1 <= 100);
    __CPROVER_assume(pub_r000252_2 >= -100 && pub_r000252_2 <= 100);
    __CPROVER_assume(pub_r000252_3 >= -100 && pub_r000252_3 <= 100);
    __CPROVER_assume(pub_r000252_4 >= -100 && pub_r000252_4 <= 100);
    __CPROVER_assume(pub_r000252_5 >= -100 && pub_r000252_5 <= 100);
    __CPROVER_assume(pub_r000252_6 >= -100 && pub_r000252_6 <= 100);
    __CPROVER_assume(pub_r000252_7 >= -100 && pub_r000252_7 <= 100);
    __CPROVER_assume(pub_r000252_8 >= -100 && pub_r000252_8 <= 100);
    __CPROVER_assume(pub_r000252_9 >= -100 && pub_r000252_9 <= 100);
    __CPROVER_assume(pub_r000252_10 >= -100 && pub_r000252_10 <= 100);
    __CPROVER_assume(pub_r000252_11 >= -100 && pub_r000252_11 <= 100);
    __CPROVER_assume(pub_r000252_12 >= -100 && pub_r000252_12 <= 100);
    __CPROVER_assume(pub_r000252_13 >= -100 && pub_r000252_13 <= 100);
    __CPROVER_assume(pub_r000252_14 >= -100 && pub_r000252_14 <= 100);
    __CPROVER_assume(pub_r000252_15 >= -100 && pub_r000252_15 <= 100);
    __CPROVER_assume(pub_r000252_16 >= -100 && pub_r000252_16 <= 100);
    __CPROVER_assume(pub_r000252_17 >= -100 && pub_r000252_17 <= 100);
    __CPROVER_assume(sec_r000252_0 >= 0 && sec_r000252_0 <= 255);
    __CPROVER_assume(sec_r000252_1 >= 0 && sec_r000252_1 <= 255);
    __CPROVER_assume(sec_r000252_2 >= 0 && sec_r000252_2 <= 255);
    __CPROVER_assume(sec_r000252_3 >= 0 && sec_r000252_3 <= 255);
    __CPROVER_assume(sec_r000252_4 >= 0 && sec_r000252_4 <= 255);
    __CPROVER_assume(sec_r000252_5 >= 0 && sec_r000252_5 <= 255);
    __CPROVER_assume(sec_r000252_6 >= 0 && sec_r000252_6 <= 255);
    __CPROVER_assume(sec_r000252_7 >= 0 && sec_r000252_7 <= 255);
    __CPROVER_assume(sec_r000252_8 >= 0 && sec_r000252_8 <= 255);
    __CPROVER_assume(sec_r000252_9 >= 0 && sec_r000252_9 <= 255);
    __CPROVER_assume(sec_r000252_10 >= 0 && sec_r000252_10 <= 255);
    __CPROVER_assume(sec_r000252_11 >= 0 && sec_r000252_11 <= 255);
    __CPROVER_assume(sec_r000252_12 >= 0 && sec_r000252_12 <= 255);
    __CPROVER_assume(sec_r000252_13 >= 0 && sec_r000252_13 <= 255);
    __CPROVER_assume(sec_r000252_14 >= 0 && sec_r000252_14 <= 255);
    __CPROVER_assume(sec_r000252_15 >= 0 && sec_r000252_15 <= 255);
    __CPROVER_assume(sec_r000252_16 >= 0 && sec_r000252_16 <= 255);
    __CPROVER_assume(sec_r000252_17 >= 0 && sec_r000252_17 <= 255);
    __CPROVER_assume(sec_r000252_18 >= 0 && sec_r000252_18 <= 255);
    __CPROVER_assume(sec_r000252_19 >= 0 && sec_r000252_19 <= 255);

    struct Vector3D_R000252_5213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000252_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000252_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000252_0 + 7) & 15;
    struct StreamBuffer_R000252_5213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000252_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000252_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000252_0 + 9) & 15;
    struct MatrixBlock_R000252_5213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000252_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000252_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000252_0 + 11) & 15;

    union ColorPixel_R000252_5213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 36) {
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
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 39) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 54) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 18) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 33) {
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
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 22) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 37) {
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
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 25) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 40) {
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
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 38) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 53) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 14) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 29) {
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
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

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
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 12) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 27) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 32) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 47) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 29) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 44) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 24) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 39) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 37) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 52) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 25) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 40) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 38) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 53) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r000252_11 + pub_r000252_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_75 + pub_r000252_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r000252_12 + pub_r000252_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_75 + pub_r000252_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r000252_12 + pub_r000252_0 + 40) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r000252_12 + pub_r000252_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r000252_1 + pub_r000252_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_75 + pub_r000252_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_82 + pub_r000252_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_76 + pub_r000252_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r000252_9 + pub_r000252_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_78 + pub_r000252_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_79 + pub_r000252_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r000252_18 + pub_r000252_17 + 48) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_88 + pub_r000252_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r000252_6 + pub_r000252_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r000252_6 + pub_r000252_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_83 + pub_r000252_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_90 + pub_r000252_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_81 + pub_r000252_2 + 13) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r000252_12 + pub_r000252_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_94 + pub_r000252_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_79 + pub_r000252_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_79 + pub_r000252_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_86 + pub_r000252_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_83 + pub_r000252_14 + 47) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r000252_2 + pub_r000252_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_89 + pub_r000252_3 + 47) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r000252_14 + pub_r000252_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_96 + pub_r000252_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r000252_1 + pub_r000252_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (sec_r000252_3 + pub_r000252_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_98 + pub_r000252_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r000252_18 + pub_r000252_15 + 44) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_97 + pub_r000252_1 + 48) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (sec_r000252_12 + pub_r000252_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r000252_9 + pub_r000252_12 + 45) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_89 + pub_r000252_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r000252_12 + pub_r000252_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r000252_14 + pub_r000252_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r000252_15 + pub_r000252_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r000252_5 + pub_r000252_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_115 + pub_r000252_4 + 46) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_99 + pub_r000252_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_108 + pub_r000252_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_76 + pub_r000252_2 + 10) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_103 + pub_r000252_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_105 + pub_r000252_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r000252_18 + pub_r000252_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_115 + pub_r000252_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_102 + pub_r000252_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_125 + pub_r000252_10 + 47) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r000252_2 + pub_r000252_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_87 + pub_r000252_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r000252_18 + pub_r000252_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_103 + pub_r000252_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r000252_13 + pub_r000252_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_86 + pub_r000252_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_81 + pub_r000252_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_110 + pub_r000252_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r000252_16 + pub_r000252_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_104 + pub_r000252_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_120 + pub_r000252_15 + 17) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_87 + pub_r000252_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_88 + pub_r000252_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r000252_3 + pub_r000252_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_132 + pub_r000252_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_116 + pub_r000252_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r000252_7 + pub_r000252_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r000252_0 + pub_r000252_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_101 + pub_r000252_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_75 + pub_r000252_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_92 + pub_r000252_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_101 + pub_r000252_17 + 43) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r000252_7 + pub_r000252_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_141 + pub_r000252_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r000252_17 + pub_r000252_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_88 + pub_r000252_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_149 + pub_r000252_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r000252_3 + pub_r000252_9 + 46) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r000252_16 + pub_r000252_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r000252_15 + pub_r000252_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_89 + pub_r000252_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r000252_11 + pub_r000252_5 + 47) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r000252_0 + pub_r000252_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_142 + pub_r000252_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_87 + pub_r000252_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_97 + pub_r000252_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_83 + pub_r000252_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_92 + pub_r000252_9 + 46) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_134 + pub_r000252_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_92 + pub_r000252_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r000252_16 + pub_r000252_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_110 + pub_r000252_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_153 + pub_r000252_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_160 + pub_r000252_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_128 + pub_r000252_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_127 + pub_r000252_0 + 47) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_125 + pub_r000252_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_99 + pub_r000252_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_100 + pub_r000252_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_171 + pub_r000252_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_100 + pub_r000252_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r000252_9 + pub_r000252_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_96 + pub_r000252_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r000252_10 + pub_r000252_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (sec_r000252_18 + pub_r000252_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_162 + pub_r000252_6 + 49) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (sec_r000252_9 + pub_r000252_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_99 + pub_r000252_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r000252_17 + pub_r000252_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r000252_11 + pub_r000252_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r000252_10 + pub_r000252_17 + 25) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (sec_r000252_17 + pub_r000252_5 + 12) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_166 + pub_r000252_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_132 + pub_r000252_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_79 + pub_r000252_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r000252_12 + pub_r000252_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_110 + pub_r000252_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_184 + pub_r000252_5 + 47) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r000252_15 + pub_r000252_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r000252_1 + pub_r000252_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_190 + pub_r000252_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_150 + pub_r000252_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_99 + pub_r000252_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r000252_17 + pub_r000252_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r000252_10 + pub_r000252_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_194 + pub_r000252_14 + 48) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_88 + pub_r000252_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r000252_5 + pub_r000252_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (sec_r000252_15 + pub_r000252_6 + 48) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r000252_1 + pub_r000252_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r000252_15 + pub_r000252_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_162 + pub_r000252_11 + 42) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_169 + pub_r000252_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_139 + pub_r000252_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_79 + pub_r000252_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_78 + pub_r000252_13 + 49) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_184 + pub_r000252_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r000252_17 + pub_r000252_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r000252_14 + pub_r000252_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_188 + pub_r000252_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_183 + pub_r000252_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (sec_r000252_17 + pub_r000252_7 + 32) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (sec_r000252_3 + pub_r000252_10 + 46) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r000252_4 + pub_r000252_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_187 + pub_r000252_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (sec_r000252_2 + pub_r000252_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (sec_r000252_5 + pub_r000252_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_79 + pub_r000252_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_145 + pub_r000252_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_133 + pub_r000252_5 + 49) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r000252_12 + pub_r000252_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_192 + pub_r000252_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (sec_r000252_5 + pub_r000252_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_113 + pub_r000252_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_207 + pub_r000252_10 + 43) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_162 + pub_r000252_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_76 + pub_r000252_2 + 46) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_124 + pub_r000252_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r000252_13 + pub_r000252_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (sec_r000252_0 + pub_r000252_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (sec_r000252_7 + pub_r000252_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_106 + pub_r000252_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_134 + pub_r000252_8 + 44) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (sec_r000252_1 + pub_r000252_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (sec_r000252_4 + pub_r000252_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_156 + pub_r000252_12 + 48) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (sec_r000252_12 + pub_r000252_13 + 49) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_215 + pub_r000252_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_142 + pub_r000252_3 + 40) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_79 + pub_r000252_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (sec_r000252_0 + pub_r000252_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (sec_r000252_11 + pub_r000252_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (sec_r000252_3 + pub_r000252_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (sec_r000252_6 + pub_r000252_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_235 + pub_r000252_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (sec_r000252_13 + pub_r000252_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (sec_r000252_4 + pub_r000252_7 + 46) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_152 + pub_r000252_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r000252_0 + pub_r000252_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_120 + pub_r000252_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (sec_r000252_2 + pub_r000252_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (sec_r000252_0 + pub_r000252_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_208 + pub_r000252_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_128 + pub_r000252_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (sec_r000252_12 + pub_r000252_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_213 + pub_r000252_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (sec_r000252_5 + pub_r000252_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (stage_v_102 + pub_r000252_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_242 + pub_r000252_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (sec_r000252_15 + pub_r000252_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (sec_r000252_19 + pub_r000252_5 + 47) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_142 + pub_r000252_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (stage_v_100 + pub_r000252_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (stage_v_162 + pub_r000252_16 + 7) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (sec_r000252_1 + pub_r000252_7 + 27) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (stage_v_213 + pub_r000252_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (sec_r000252_12 + pub_r000252_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (stage_v_76 + pub_r000252_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (stage_v_225 + pub_r000252_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (stage_v_180 + pub_r000252_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (stage_v_88 + pub_r000252_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (stage_v_173 + pub_r000252_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (stage_v_223 + pub_r000252_10 + 12) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (stage_v_267 + pub_r000252_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (stage_v_108 + pub_r000252_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (stage_v_220 + pub_r000252_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (sec_r000252_7 + pub_r000252_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (stage_v_155 + pub_r000252_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (stage_v_83 + pub_r000252_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (stage_v_167 + pub_r000252_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (sec_r000252_13 + pub_r000252_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (stage_v_265 + pub_r000252_3 + 42) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (stage_v_215 + pub_r000252_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (stage_v_138 + pub_r000252_2 + 41) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (stage_v_198 + pub_r000252_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (stage_v_179 + pub_r000252_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (sec_r000252_3 + pub_r000252_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (stage_v_100 + pub_r000252_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (stage_v_108 + pub_r000252_11 + 49) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (sec_r000252_9 + pub_r000252_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (sec_r000252_5 + pub_r000252_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (sec_r000252_6 + pub_r000252_17 + 35) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (sec_r000252_10 + pub_r000252_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (sec_r000252_3 + pub_r000252_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (stage_v_170 + pub_r000252_7 + 48) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (sec_r000252_5 + pub_r000252_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (stage_v_99 + pub_r000252_6 + 47) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (stage_v_237 + pub_r000252_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (stage_v_266 + pub_r000252_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (sec_r000252_8 + pub_r000252_17 + 28) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (sec_r000252_6 + pub_r000252_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (stage_v_153 + pub_r000252_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (stage_v_135 + pub_r000252_16 + 7) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (sec_r000252_9 + pub_r000252_2 + 46) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (stage_v_272 + pub_r000252_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (stage_v_300 + pub_r000252_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (sec_r000252_18 + pub_r000252_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (sec_r000252_4 + pub_r000252_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (stage_v_267 + pub_r000252_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (sec_r000252_13 + pub_r000252_15 + 26) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (sec_r000252_18 + pub_r000252_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (stage_v_242 + pub_r000252_13 + 49) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (stage_v_98 + pub_r000252_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (stage_v_162 + pub_r000252_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (stage_v_235 + pub_r000252_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (stage_v_176 + pub_r000252_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (stage_v_99 + pub_r000252_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (stage_v_307 + pub_r000252_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (sec_r000252_10 + pub_r000252_7 + 47) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (stage_v_79 + pub_r000252_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (stage_v_113 + pub_r000252_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
