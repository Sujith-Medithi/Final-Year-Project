/*
 * Benchmark Program: R001720
 * Security Family: mixed_control_data
 * Generator Seed: 672013
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001720_2013_0 {
    int density;
    int stride;
    int scale;
    unsigned char determinant;
    unsigned char trace;
    int dim;
    int buffer[3];
};

struct StreamBuffer_R001720_2013_1 {
    short watermark;
    unsigned char head;
    int checksum;
    int buffer[3];
};

struct Transaction_R001720_2013_2 {
    int rate;
    int status;
    int account_id;
    int buffer[3];
};

struct AudioFrame_R001720_2013_3 {
    unsigned char rms;
    unsigned char peak;
    short gain;
    short envelope;
    int channels;
    int sample_rate;
    int buffer[3];
};

union TelemetryField_R001720_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001720_2013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001720_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_97 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_97 = (quotient_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001720_2013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_15 = (aux + st.buffer[1]) & 3;
    switch (bound_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_12 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_12 > 10) {
        acc = (acc + factor_12 * 2 + 5) & 127;
        aux ^= (factor_12 & 15);
    } else {
        acc = (acc - factor_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_2(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001720_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_75) & 63;
    acc ^= aux;
    int factor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_82 > 37) {
        acc = (acc + factor_82 * 2 + 5) & 127;
        aux ^= (factor_82 & 15);
    } else {
        acc = (acc - factor_82 + 11) & 127;
        aux += 3;
    }
    int window_68 = 0;
    for (int k = 0; k < 3; k++) {
        window_68 = (window_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_68) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_31 = local_arr[aux % 3];
    acc = (acc + residue_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int quantum_44 = local_arr[aux % 3];
    acc = (acc + quantum_44 * 2) & 127;
    int metric_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001720_2013_4(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001720_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_80 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_80 > 49) {
        acc = (acc + mask_80 * 2 + 5) & 127;
        aux ^= (mask_80 & 15);
    } else {
        acc = (acc - mask_80 + 11) & 127;
        aux += 3;
    }
    int tracker_12 = (aux + st.buffer[1]) & 3;
    switch (tracker_12) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_78 = local_arr[aux % 3];
    acc = (acc + factor_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001720_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int offset_29 = (aux + st.buffer[1]) & 3;
    switch (offset_29) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_21 = local_arr[aux % 3];
    acc = (acc + factor_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_6(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001720_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_80 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_80 > 38) {
        acc = (acc + index_reg_80 * 2 + 5) & 127;
        aux ^= (index_reg_80 & 15);
    } else {
        acc = (acc - index_reg_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_77 = local_arr[aux % 3];
    acc = (acc + scale_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_75 = (aux + st.buffer[1]) & 3;
    switch (parity_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_43 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_43 > 16) {
        acc = (acc + pivot_43 * 2 + 5) & 127;
        aux ^= (pivot_43 & 15);
    } else {
        acc = (acc - pivot_43 + 11) & 127;
        aux += 3;
    }
    int tracker_17 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_17 = (tracker_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_17) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_69 = local_arr[aux % 3];
    acc = (acc + threshold_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001720_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int window_80 = 0;
    for (int k = 0; k < 3; k++) {
        window_80 = (window_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_80) & 127;
    }
    int factor_67 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_67 > 36) {
        acc = (acc + factor_67 * 2 + 5) & 127;
        aux ^= (factor_67 & 15);
    } else {
        acc = (acc - factor_67 + 11) & 127;
        aux += 3;
    }
    int phase_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_11) & 63;
    acc ^= aux;
    int segment_36 = (aux + st.buffer[1]) & 3;
    switch (segment_36) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_9(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_76 = 0;
    for (int k = 0; k < 2; k++) {
        bound_76 = (bound_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_76) & 127;
    }
    int stride_76 = (aux + st.buffer[1]) & 3;
    switch (stride_76) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_50 = local_arr[aux % 3];
    acc = (acc + checksum_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_10(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int offset_16 = local_arr[aux % 3];
    acc = (acc + offset_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_88 = 0;
    for (int k = 0; k < 2; k++) {
        margin_88 = (margin_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_88) & 127;
    }
    int anchor_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001720_2013_11(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001720_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int offset_14 = local_arr[aux % 3];
    acc = (acc + offset_14 * 2) & 127;
    int checksum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_32 > 12) {
        acc = (acc + checksum_32 * 2 + 5) & 127;
        aux ^= (checksum_32 & 15);
    } else {
        acc = (acc - checksum_32 + 11) & 127;
        aux += 3;
    }
    int stride_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001720_2013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001720_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int segment_66 = (aux + st.buffer[1]) & 3;
    switch (segment_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_36 = local_arr[aux % 3];
    acc = (acc + margin_36 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_13 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_13 > 38) {
        acc = (acc + cursor_13 * 2 + 5) & 127;
        aux ^= (cursor_13 & 15);
    } else {
        acc = (acc - cursor_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_13(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001720_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_69 = 0;
    for (int k = 0; k < 2; k++) {
        sample_69 = (sample_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_69) & 127;
    }
    int parity_13 = (aux + st.buffer[1]) & 3;
    switch (parity_13) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001720_2013_14(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001720_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_92 = (aux + st.buffer[1]) & 3;
    switch (mask_92) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_15(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001720_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_15 = local_arr[aux % 3];
    acc = (acc + delta_15 * 2) & 127;
    int quotient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_98 > 23) {
        acc = (acc + quotient_98 * 2 + 5) & 127;
        aux ^= (quotient_98 & 15);
    } else {
        acc = (acc - quotient_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_16(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001720_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int stride_12 = local_arr[aux % 3];
    acc = (acc + stride_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_99 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_99 > 24) {
        acc = (acc + segment_99 * 2 + 5) & 127;
        aux ^= (segment_99 & 15);
    } else {
        acc = (acc - segment_99 + 11) & 127;
        aux += 3;
    }
    int factor_32 = 0;
    for (int k = 0; k < 3; k++) {
        factor_32 = (factor_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_32) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_17(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001720_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int threshold_68 = local_arr[aux % 3];
    acc = (acc + threshold_68 * 2) & 127;
    int margin_97 = (aux + st.buffer[1]) & 3;
    switch (margin_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_72 = 0;
    for (int k = 0; k < 3; k++) {
        offset_72 = (offset_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001720_2013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001720_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int bound_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_44 = local_arr[aux % 3];
    acc = (acc + quotient_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_19(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001720_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_88 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_88 > 23) {
        acc = (acc + tracker_88 * 2 + 5) & 127;
        aux ^= (tracker_88 & 15);
    } else {
        acc = (acc - tracker_88 + 11) & 127;
        aux += 3;
    }
    int coefficient_22 = (aux + st.buffer[1]) & 3;
    switch (coefficient_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001720_2013_20(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001720_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_86 = 0;
    for (int k = 0; k < 2; k++) {
        bound_86 = (bound_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_86) & 127;
    }
    int parity_84 = (aux + st.buffer[1]) & 3;
    switch (parity_84) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_24 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_24 > 12) {
        acc = (acc + delta_24 * 2 + 5) & 127;
        aux ^= (delta_24 & 15);
    } else {
        acc = (acc - delta_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001720_0;
    int sec_r001720_1;
    int sec_r001720_2;
    int sec_r001720_3;
    int sec_r001720_4;
    int sec_r001720_5;
    int sec_r001720_6;
    int sec_r001720_7;
    int sec_r001720_8;
    int sec_r001720_9;
    int sec_r001720_10;
    int sec_r001720_11;
    int sec_r001720_12;
    int sec_r001720_13;
    int sec_r001720_14;
    int sec_r001720_15;
    int sec_r001720_16;
    int sec_r001720_17;
    int sec_r001720_18;
    int sec_r001720_19;
    int sec_r001720_20;
    int sec_r001720_21;
    int sec_r001720_22;
    int sec_r001720_23;
    int pub_r001720_0;
    int pub_r001720_1;
    int pub_r001720_2;
    int pub_r001720_3;
    int pub_r001720_4;
    int pub_r001720_5;
    int pub_r001720_6;
    int pub_r001720_7;
    int pub_r001720_8;
    int pub_r001720_9;
    int pub_r001720_10;
    int pub_r001720_11;
    int pub_r001720_12;
    int pub_r001720_13;
    int pub_r001720_14;
    int pub_r001720_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001720_0 >= -100 && pub_r001720_0 <= 100);
    __CPROVER_assume(pub_r001720_1 >= -100 && pub_r001720_1 <= 100);
    __CPROVER_assume(pub_r001720_2 >= -100 && pub_r001720_2 <= 100);
    __CPROVER_assume(pub_r001720_3 >= -100 && pub_r001720_3 <= 100);
    __CPROVER_assume(pub_r001720_4 >= -100 && pub_r001720_4 <= 100);
    __CPROVER_assume(pub_r001720_5 >= -100 && pub_r001720_5 <= 100);
    __CPROVER_assume(pub_r001720_6 >= -100 && pub_r001720_6 <= 100);
    __CPROVER_assume(pub_r001720_7 >= -100 && pub_r001720_7 <= 100);
    __CPROVER_assume(pub_r001720_8 >= -100 && pub_r001720_8 <= 100);
    __CPROVER_assume(pub_r001720_9 >= -100 && pub_r001720_9 <= 100);
    __CPROVER_assume(pub_r001720_10 >= -100 && pub_r001720_10 <= 100);
    __CPROVER_assume(pub_r001720_11 >= -100 && pub_r001720_11 <= 100);
    __CPROVER_assume(pub_r001720_12 >= -100 && pub_r001720_12 <= 100);
    __CPROVER_assume(pub_r001720_13 >= -100 && pub_r001720_13 <= 100);
    __CPROVER_assume(pub_r001720_14 >= -100 && pub_r001720_14 <= 100);
    __CPROVER_assume(pub_r001720_15 >= -100 && pub_r001720_15 <= 100);
    __CPROVER_assume(sec_r001720_0 >= 0 && sec_r001720_0 <= 255);
    __CPROVER_assume(sec_r001720_1 >= 0 && sec_r001720_1 <= 255);
    __CPROVER_assume(sec_r001720_2 >= 0 && sec_r001720_2 <= 255);
    __CPROVER_assume(sec_r001720_3 >= 0 && sec_r001720_3 <= 255);
    __CPROVER_assume(sec_r001720_4 >= 0 && sec_r001720_4 <= 255);
    __CPROVER_assume(sec_r001720_5 >= 0 && sec_r001720_5 <= 255);
    __CPROVER_assume(sec_r001720_6 >= 0 && sec_r001720_6 <= 255);
    __CPROVER_assume(sec_r001720_7 >= 0 && sec_r001720_7 <= 255);
    __CPROVER_assume(sec_r001720_8 >= 0 && sec_r001720_8 <= 255);
    __CPROVER_assume(sec_r001720_9 >= 0 && sec_r001720_9 <= 255);
    __CPROVER_assume(sec_r001720_10 >= 0 && sec_r001720_10 <= 255);
    __CPROVER_assume(sec_r001720_11 >= 0 && sec_r001720_11 <= 255);
    __CPROVER_assume(sec_r001720_12 >= 0 && sec_r001720_12 <= 255);
    __CPROVER_assume(sec_r001720_13 >= 0 && sec_r001720_13 <= 255);
    __CPROVER_assume(sec_r001720_14 >= 0 && sec_r001720_14 <= 255);
    __CPROVER_assume(sec_r001720_15 >= 0 && sec_r001720_15 <= 255);
    __CPROVER_assume(sec_r001720_16 >= 0 && sec_r001720_16 <= 255);
    __CPROVER_assume(sec_r001720_17 >= 0 && sec_r001720_17 <= 255);
    __CPROVER_assume(sec_r001720_18 >= 0 && sec_r001720_18 <= 255);
    __CPROVER_assume(sec_r001720_19 >= 0 && sec_r001720_19 <= 255);
    __CPROVER_assume(sec_r001720_20 >= 0 && sec_r001720_20 <= 255);
    __CPROVER_assume(sec_r001720_21 >= 0 && sec_r001720_21 <= 255);
    __CPROVER_assume(sec_r001720_22 >= 0 && sec_r001720_22 <= 255);
    __CPROVER_assume(sec_r001720_23 >= 0 && sec_r001720_23 <= 255);

    struct MatrixBlock_R001720_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001720_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001720_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001720_0 + 7) & 15;
    struct StreamBuffer_R001720_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001720_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001720_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001720_0 + 9) & 15;
    struct Transaction_R001720_2013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001720_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001720_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001720_0 + 11) & 15;
    struct AudioFrame_R001720_2013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001720_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001720_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001720_0 + 13) & 15;

    union TelemetryField_R001720_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001720_2013_0(sec_r001720_0, sec_r001720_1, pub_r001720_2, pub_r001720_3, pub_r001720_4);
    int helper_flow_1 = fn_R001720_2013_1(sec_r001720_1, sec_r001720_2, pub_r001720_3, pub_r001720_4, pub_r001720_5);
    int helper_flow_2 = fn_R001720_2013_2(sec_r001720_2, pub_r001720_3);
    int helper_flow_3 = fn_R001720_2013_3(sec_r001720_3, sec_r001720_4, pub_r001720_5, pub_r001720_6, pub_r001720_7);
    int helper_flow_4 = fn_R001720_2013_4(sec_r001720_4, sec_r001720_5);
    int helper_flow_5 = fn_R001720_2013_5(sec_r001720_5, sec_r001720_6, pub_r001720_7, pub_r001720_8, pub_r001720_9);
    int helper_flow_6 = fn_R001720_2013_6(sec_r001720_6, pub_r001720_7, pub_r001720_8);
    int helper_flow_7 = fn_R001720_2013_7(sec_r001720_7, sec_r001720_8, pub_r001720_9, pub_r001720_10, pub_r001720_11);
    int helper_flow_8 = fn_R001720_2013_8(sec_r001720_8, pub_r001720_9, pub_r001720_10, pub_r001720_11, pub_r001720_12);
    int helper_flow_9 = fn_R001720_2013_9(sec_r001720_9, pub_r001720_10, pub_r001720_11);
    int helper_flow_10 = fn_R001720_2013_10(sec_r001720_10, sec_r001720_11, pub_r001720_12);
    int helper_flow_11 = fn_R001720_2013_11(sec_r001720_11, pub_r001720_12, pub_r001720_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001720_5 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_0 > 28) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001720_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_2 > 34) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_3 > 47) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001720_17 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001720_10 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_5 > 27) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_6 > 37) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_7 > 21) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001720_18 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_8 > 36) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001720_21 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_9 > 33) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001720_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_11 > 42) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_12 > 24) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001720_20 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_13 > 34) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001720_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001720_17 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_15 > 43) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001720_21 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_16 > 42) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_17 > 35) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_18 > 34) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_19 > 48) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_20 > 22) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_21 > 37) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001720_22 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_22 > 49) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_23 > 41) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_24 > 38) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001720_5 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_25 > 37) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001720_7 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_26 > 28) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_27 > 23) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_28 > 48) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_29 > 42) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_30 > 20) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_31 > 46) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_32 > 45) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_33 > 46) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_34 > 50) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001720_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001720_14 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_36 > 35) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_37 > 33) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001720_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_40 > 24) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_41 > 36) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001720_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001720_7 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_43 > 41) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_44 > 29) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001720_6 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_45 > 23) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_46 > 42) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001720_3 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_47 > 20) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_48 > 38) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_49 > 21) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_50 > 49) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001720_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001720_6 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_52 > 26) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_53 > 41) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_54 > 35) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_55 > 24) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_56 > 34) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_57 > 30) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001720_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_59 > 50) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_60 > 22) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_61 > 50) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001720_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_63 > 30) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_64 > 32) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_65 > 33) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001720_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_67 > 34) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001720_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_70 > 42) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001720_9 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_71 > 24) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001720_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001720_16 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_73 > 34) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001720_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_75 > 33) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_76 > 42) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001720_13 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_77 > 43) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001720_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_79 > 42) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_80 > 22) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001720_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_82 > 44) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001720_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_84 > 33) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001720_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_86 > 46) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_87 > 21) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001720_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_89 > 30) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_90 > 47) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_91 > 26) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_92 > 28) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_93 > 23) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001720_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_95 > 44) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_96 > 38) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_97 > 25) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_98 > 41) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_99 > 50) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001720_16 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_100 > 45) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001720_6 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_101 > 49) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_102 > 44) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_104 > 24) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001720_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_106 > 46) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001720_17 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_107 > 20) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_108 > 42) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_109 > 23) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001720_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_111 > 28) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_112 > 38) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_113 > 22) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_114 > 27) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_115 > 48) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_116 > 38) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001720_13 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_117 > 27) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001720_10 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_118 > 42) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_119 > 41) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001720_13 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_120 > 25) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_121 > 49) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_122 > 48) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_123 > 20) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001720_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001720_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_126 > 48) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001720_9) & 127;
    if (stage_v_127 > 21) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001720_22 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_128 > 29) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001720_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001720_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_131 > 49) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_132 > 25) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_133 > 29) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_134 > 33) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_135 > 20) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_136 > 28) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001720_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001720_2) & 127;
    if (stage_v_138 > 20) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_139 > 30) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_140 > 42) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_141 > 41) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_142 > 26) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r001720_18 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_143 > 26) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_144 > 28) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001720_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_146 > 36) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001720_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001720_18 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_148 > 33) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001720_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_150 > 44) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_151 > 50) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_152 > 45) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_153 > 21) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001720_3 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_154 > 47) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_155 > 36) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001720_1) & 127;
    if (stage_v_156 > 50) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001720_13) & 127;
    if (stage_v_157 > 20) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_158 > 27) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_159 > 24) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001720_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001720_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_162 > 45) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_163 > 29) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_164 > 32) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001720_15) & 127;
    if (stage_v_165 > 39) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001720_5) & 127;
    if (stage_v_167 > 25) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001720_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_169 > 24) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_170 > 50) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001720_8) & 127;
    if (stage_v_171 > 35) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001720_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_173 > 23) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001720_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_175 > 26) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_176 > 34) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_177 > 21) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001720_3) & 127;
    if (stage_v_178 > 22) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001720_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001720_17 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_180 > 49) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001720_12) & 127;
    if (stage_v_181 > 34) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_182 > 32) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_183 > 29) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001720_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_185 > 45) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001720_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_187 > 48) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_188 > 41) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_189 > 39) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001720_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001720_11) & 127;
    if (stage_v_191 > 36) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001720_4) & 127;
    if (stage_v_192 > 38) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_193 > 40) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_194 > 42) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_195 > 25) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001720_7) & 127;
    if (stage_v_196 > 33) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001720_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001720_6) & 127;
    if (stage_v_198 > 35) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001720_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001720_3 ^ 0x2A) * 2 + pub_r001720_0) & 127;
    if (stage_v_200 > 33) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001720_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001720_10) & 127;
    if (stage_v_202 > 39) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001720_14) & 127;
    if (stage_v_203 > 42) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
