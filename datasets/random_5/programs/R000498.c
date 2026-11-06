/*
 * Benchmark Program: R000498
 * Security Family: secret_dependent_loops
 * Generator Seed: 549813
 * High Inputs: 24 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000498_9813_0 {
    short state;
    int head;
    int watermark;
    int buffer[3];
};

struct MatrixBlock_R000498_9813_1 {
    short dim;
    short trace;
    short stride;
    int buffer[3];
};

union RegisterBank_R000498_9813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000498_9813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000498_9813_0(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_96) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_27 = local_arr[aux % 3];
    acc = (acc + threshold_27 * 2) & 127;
    int bound_59 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_59 > 41) {
        acc = (acc + bound_59 * 2 + 5) & 127;
        aux ^= (bound_59 & 15);
    } else {
        acc = (acc - bound_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_1(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int parity_39 = local_arr[aux % 3];
    acc = (acc + parity_39 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_93) & 63;
    acc ^= aux;
    int vector_62 = (aux + st.buffer[1]) & 3;
    switch (vector_62) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_25 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_25 > 28) {
        acc = (acc + factor_25 * 2 + 5) & 127;
        aux ^= (factor_25 & 15);
    } else {
        acc = (acc - factor_25 + 11) & 127;
        aux += 3;
    }
    int tally_89 = (aux + st.buffer[1]) & 3;
    switch (tally_89) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_3(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_60) & 63;
    acc ^= aux;
    int parity_46 = (aux + st.buffer[1]) & 3;
    switch (parity_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_4(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_51 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_51 > 35) {
        acc = (acc + index_reg_51 * 2 + 5) & 127;
        aux ^= (index_reg_51 & 15);
    } else {
        acc = (acc - index_reg_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_43 = local_arr[aux % 3];
    acc = (acc + window_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_5(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int anchor_43 = local_arr[aux % 3];
    acc = (acc + anchor_43 * 2) & 127;
    int weight_88 = (aux + st.buffer[1]) & 3;
    switch (weight_88) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_75) & 63;
    acc ^= aux;
    int bound_34 = (aux + st.buffer[1]) & 3;
    switch (bound_34) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_75 > 34) {
        acc = (acc + factor_75 * 2 + 5) & 127;
        aux ^= (factor_75 & 15);
    } else {
        acc = (acc - factor_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int bound_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_83) & 63;
    acc ^= aux;
    int phase_65 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_65 > 22) {
        acc = (acc + phase_65 * 2 + 5) & 127;
        aux ^= (phase_65 & 15);
    } else {
        acc = (acc - phase_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_8(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int tracker_43 = local_arr[aux % 3];
    acc = (acc + tracker_43 * 2) & 127;
    int pivot_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_9(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_88 = (aux + st.buffer[1]) & 3;
    switch (tally_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_92 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_92 > 11) {
        acc = (acc + residue_92 * 2 + 5) & 127;
        aux ^= (residue_92 & 15);
    } else {
        acc = (acc - residue_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_10(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int scale_54 = local_arr[aux % 3];
    acc = (acc + scale_54 * 2) & 127;
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 20) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_11(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_85 = (aux + st.buffer[1]) & 3;
    switch (parity_85) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_76 = local_arr[aux % 3];
    acc = (acc + vector_76 * 2) & 127;
    int delta_36 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_36 > 12) {
        acc = (acc + delta_36 * 2 + 5) & 127;
        aux ^= (delta_36 & 15);
    } else {
        acc = (acc - delta_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_12(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_70 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_70 > 46) {
        acc = (acc + factor_70 * 2 + 5) & 127;
        aux ^= (factor_70 & 15);
    } else {
        acc = (acc - factor_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_88 = local_arr[aux % 3];
    acc = (acc + segment_88 * 2) & 127;
    int quotient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int residue_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_41) & 63;
    acc ^= aux;
    int factor_64 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_64 > 47) {
        acc = (acc + factor_64 * 2 + 5) & 127;
        aux ^= (factor_64 & 15);
    } else {
        acc = (acc - factor_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_98 = local_arr[aux % 3];
    acc = (acc + stride_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_86 = (aux + st.buffer[1]) & 3;
    switch (damping_86) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_99 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_99 > 46) {
        acc = (acc + threshold_99 * 2 + 5) & 127;
        aux ^= (threshold_99 & 15);
    } else {
        acc = (acc - threshold_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_96) & 63;
    acc ^= aux;
    int damping_21 = (aux + st.buffer[1]) & 3;
    switch (damping_21) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000498_9813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_63 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_63 > 12) {
        acc = (acc + scale_63 * 2 + 5) & 127;
        aux ^= (scale_63 & 15);
    } else {
        acc = (acc - scale_63 + 11) & 127;
        aux += 3;
    }
    int damping_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_46) & 63;
    acc ^= aux;
    int index_reg_14 = (aux + st.buffer[1]) & 3;
    switch (index_reg_14) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_39 = local_arr[aux % 3];
    acc = (acc + parity_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_10 = (aux + st.buffer[1]) & 3;
    switch (residue_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_19 = local_arr[aux % 3];
    acc = (acc + weight_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_18(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 22) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_40 = local_arr[aux % 3];
    acc = (acc + metric_40 * 2) & 127;
    int sample_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_88 = local_arr[aux % 3];
    acc = (acc + quotient_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_21(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_22 = (aux + st.buffer[1]) & 3;
    switch (quantum_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_25 = local_arr[aux % 3];
    acc = (acc + window_25 * 2) & 127;
    int quotient_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000498_9813_22(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000498_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_48) & 63;
    acc ^= aux;
    int offset_89 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_89 > 21) {
        acc = (acc + offset_89 * 2 + 5) & 127;
        aux ^= (offset_89 & 15);
    } else {
        acc = (acc - offset_89 + 11) & 127;
        aux += 3;
    }
    int tally_38 = (aux + st.buffer[1]) & 3;
    switch (tally_38) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_43 = local_arr[aux % 3];
    acc = (acc + window_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000498_9813_23(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000498_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int coefficient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_34 > 32) {
        acc = (acc + coefficient_34 * 2 + 5) & 127;
        aux ^= (coefficient_34 & 15);
    } else {
        acc = (acc - coefficient_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_70 = (aux + st.buffer[1]) & 3;
    switch (bound_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_69 = local_arr[aux % 3];
    acc = (acc + quotient_69 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000498_0;
    int sec_r000498_1;
    int sec_r000498_2;
    int sec_r000498_3;
    int sec_r000498_4;
    int sec_r000498_5;
    int sec_r000498_6;
    int sec_r000498_7;
    int sec_r000498_8;
    int sec_r000498_9;
    int sec_r000498_10;
    int sec_r000498_11;
    int sec_r000498_12;
    int sec_r000498_13;
    int sec_r000498_14;
    int sec_r000498_15;
    int sec_r000498_16;
    int sec_r000498_17;
    int sec_r000498_18;
    int sec_r000498_19;
    int sec_r000498_20;
    int sec_r000498_21;
    int sec_r000498_22;
    int sec_r000498_23;
    int pub_r000498_0;
    int pub_r000498_1;
    int pub_r000498_2;
    int pub_r000498_3;
    int pub_r000498_4;
    int pub_r000498_5;
    int pub_r000498_6;
    int pub_r000498_7;
    int pub_r000498_8;
    int pub_r000498_9;
    int pub_r000498_10;
    int pub_r000498_11;
    int pub_r000498_12;
    int pub_r000498_13;
    int pub_r000498_14;
    int pub_r000498_15;
    int pub_r000498_16;
    int pub_r000498_17;
    int pub_r000498_18;
    int pub_r000498_19;
    int pub_r000498_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000498_0 >= -100 && pub_r000498_0 <= 100);
    __CPROVER_assume(pub_r000498_1 >= -100 && pub_r000498_1 <= 100);
    __CPROVER_assume(pub_r000498_2 >= -100 && pub_r000498_2 <= 100);
    __CPROVER_assume(pub_r000498_3 >= -100 && pub_r000498_3 <= 100);
    __CPROVER_assume(pub_r000498_4 >= -100 && pub_r000498_4 <= 100);
    __CPROVER_assume(pub_r000498_5 >= -100 && pub_r000498_5 <= 100);
    __CPROVER_assume(pub_r000498_6 >= -100 && pub_r000498_6 <= 100);
    __CPROVER_assume(pub_r000498_7 >= -100 && pub_r000498_7 <= 100);
    __CPROVER_assume(pub_r000498_8 >= -100 && pub_r000498_8 <= 100);
    __CPROVER_assume(pub_r000498_9 >= -100 && pub_r000498_9 <= 100);
    __CPROVER_assume(pub_r000498_10 >= -100 && pub_r000498_10 <= 100);
    __CPROVER_assume(pub_r000498_11 >= -100 && pub_r000498_11 <= 100);
    __CPROVER_assume(pub_r000498_12 >= -100 && pub_r000498_12 <= 100);
    __CPROVER_assume(pub_r000498_13 >= -100 && pub_r000498_13 <= 100);
    __CPROVER_assume(pub_r000498_14 >= -100 && pub_r000498_14 <= 100);
    __CPROVER_assume(pub_r000498_15 >= -100 && pub_r000498_15 <= 100);
    __CPROVER_assume(pub_r000498_16 >= -100 && pub_r000498_16 <= 100);
    __CPROVER_assume(pub_r000498_17 >= -100 && pub_r000498_17 <= 100);
    __CPROVER_assume(pub_r000498_18 >= -100 && pub_r000498_18 <= 100);
    __CPROVER_assume(pub_r000498_19 >= -100 && pub_r000498_19 <= 100);
    __CPROVER_assume(pub_r000498_20 >= -100 && pub_r000498_20 <= 100);
    __CPROVER_assume(sec_r000498_0 >= 0 && sec_r000498_0 <= 255);
    __CPROVER_assume(sec_r000498_1 >= 0 && sec_r000498_1 <= 255);
    __CPROVER_assume(sec_r000498_2 >= 0 && sec_r000498_2 <= 255);
    __CPROVER_assume(sec_r000498_3 >= 0 && sec_r000498_3 <= 255);
    __CPROVER_assume(sec_r000498_4 >= 0 && sec_r000498_4 <= 255);
    __CPROVER_assume(sec_r000498_5 >= 0 && sec_r000498_5 <= 255);
    __CPROVER_assume(sec_r000498_6 >= 0 && sec_r000498_6 <= 255);
    __CPROVER_assume(sec_r000498_7 >= 0 && sec_r000498_7 <= 255);
    __CPROVER_assume(sec_r000498_8 >= 0 && sec_r000498_8 <= 255);
    __CPROVER_assume(sec_r000498_9 >= 0 && sec_r000498_9 <= 255);
    __CPROVER_assume(sec_r000498_10 >= 0 && sec_r000498_10 <= 255);
    __CPROVER_assume(sec_r000498_11 >= 0 && sec_r000498_11 <= 255);
    __CPROVER_assume(sec_r000498_12 >= 0 && sec_r000498_12 <= 255);
    __CPROVER_assume(sec_r000498_13 >= 0 && sec_r000498_13 <= 255);
    __CPROVER_assume(sec_r000498_14 >= 0 && sec_r000498_14 <= 255);
    __CPROVER_assume(sec_r000498_15 >= 0 && sec_r000498_15 <= 255);
    __CPROVER_assume(sec_r000498_16 >= 0 && sec_r000498_16 <= 255);
    __CPROVER_assume(sec_r000498_17 >= 0 && sec_r000498_17 <= 255);
    __CPROVER_assume(sec_r000498_18 >= 0 && sec_r000498_18 <= 255);
    __CPROVER_assume(sec_r000498_19 >= 0 && sec_r000498_19 <= 255);
    __CPROVER_assume(sec_r000498_20 >= 0 && sec_r000498_20 <= 255);
    __CPROVER_assume(sec_r000498_21 >= 0 && sec_r000498_21 <= 255);
    __CPROVER_assume(sec_r000498_22 >= 0 && sec_r000498_22 <= 255);
    __CPROVER_assume(sec_r000498_23 >= 0 && sec_r000498_23 <= 255);

    struct StreamBuffer_R000498_9813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000498_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000498_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000498_0 + 7) & 15;
    struct MatrixBlock_R000498_9813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000498_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000498_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000498_0 + 9) & 15;

    union RegisterBank_R000498_9813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 11) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 26) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 39) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 54) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 35) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 50) {
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 14) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 29) {
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
    if (stage_v_16 > 36) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 51) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 19) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 34) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
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
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 33) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 48) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 32) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 47) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 27) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 42) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

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
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 28) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 43) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 22) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 37) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 18) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 33) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 13) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 28) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 16) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 31) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 35) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 50) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[2] * 2 + 220) & 63;
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
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 11) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 26) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 44) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 31) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 46) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 10) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 25) {
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
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
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
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 24) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 39) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 12) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 27) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_11 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000498_14) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000498_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_10 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000498_15) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000498_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000498_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000498_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000498_2) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000498_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_18 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000498_1) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000498_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000498_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_17 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000498_10) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000498_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000498_4) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000498_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_9 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000498_0) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000498_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000498_15) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000498_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_7 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000498_11) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000498_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000498_11) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000498_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000498_10) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000498_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_2 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000498_15) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000498_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000498_5) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000498_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000498_17) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000498_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000498_6) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000498_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000498_18) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000498_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000498_17) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000498_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000498_4) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000498_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000498_8) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000498_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000498_19) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000498_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000498_2) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000498_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000498_8) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000498_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_4 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000498_15) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000498_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_22 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000498_7) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000498_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000498_13) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000498_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000498_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_12 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000498_11) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000498_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_5 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000498_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_16 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000498_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000498_17) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000498_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000498_15) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000498_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_1 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000498_11) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000498_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000498_8) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000498_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_8 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000498_8) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000498_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000498_4) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000498_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000498_14) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000498_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000498_0) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000498_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_14 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000498_10) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000498_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000498_19) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000498_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_7 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000498_1) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000498_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000498_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_1 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000498_17) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000498_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_16 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000498_14) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000498_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_9 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000498_3) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000498_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_19 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000498_2) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000498_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000498_14 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000498_17) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000498_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
