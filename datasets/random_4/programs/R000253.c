/*
 * Benchmark Program: R000253
 * Family: multi_step_explicit
 * Generator Seed: 425313
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000253_5313_0 {
    int determinant;
    int dim;
    int trace;
    int buffer[3];
};

struct Transaction_R000253_5313_1 {
    int status;
    int account_id;
    int balance;
    unsigned char rate;
    int buffer[3];
};

struct AudioFrame_R000253_5313_2 {
    unsigned char sample_rate;
    short channels;
    short rms;
    unsigned char envelope;
    short gain;
    int peak;
    int buffer[3];
};

union RegisterBank_R000253_5313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000253_5313_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_32 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_32 > 44) {
        acc = (acc + delta_32 * 2 + 5) & 127;
        aux ^= (delta_32 & 15);
    } else {
        acc = (acc - delta_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_13 = local_arr[aux % 3];
    acc = (acc + cursor_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000253_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int pivot_47 = local_arr[aux % 3];
    acc = (acc + pivot_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_16 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_16 = (quotient_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_16) & 127;
    }
    int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000253_5313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_19 = (aux + st.buffer[1]) & 3;
    switch (margin_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000253_5313_3(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_12 = 0;
    for (int k = 0; k < 3; k++) {
        scale_12 = (scale_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000253_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_69 = local_arr[aux % 3];
    acc = (acc + window_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_99 > 48) {
        acc = (acc + anchor_99 * 2 + 5) & 127;
        aux ^= (anchor_99 & 15);
    } else {
        acc = (acc - anchor_99 + 11) & 127;
        aux += 3;
    }
    int coefficient_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_43) & 63;
    acc ^= aux;
    int metric_87 = (aux + st.buffer[1]) & 3;
    switch (metric_87) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_29) & 63;
    acc ^= aux;
    int damping_81 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_81 > 45) {
        acc = (acc + damping_81 * 2 + 5) & 127;
        aux ^= (damping_81 & 15);
    } else {
        acc = (acc - damping_81 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_91 = local_arr[aux % 3];
    acc = (acc + coefficient_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_71 = 0;
    for (int k = 0; k < 2; k++) {
        factor_71 = (factor_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_71) & 127;
    }
    int checksum_38 = (aux + st.buffer[1]) & 3;
    switch (checksum_38) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000253_5313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int factor_31 = local_arr[aux % 3];
    acc = (acc + factor_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_32) & 63;
    acc ^= aux;
    int tally_27 = 0;
    for (int k = 0; k < 2; k++) {
        tally_27 = (tally_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_9(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_39 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_39 > 19) {
        acc = (acc + parity_39 * 2 + 5) & 127;
        aux ^= (parity_39 & 15);
    } else {
        acc = (acc - parity_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_10(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000253_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_58 = (aux + st.buffer[1]) & 3;
    switch (tracker_58) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_11(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int segment_95 = local_arr[aux % 3];
    acc = (acc + segment_95 * 2) & 127;
    int offset_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_97) & 63;
    acc ^= aux;
    int parity_22 = (aux + st.buffer[1]) & 3;
    switch (parity_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_12(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_47 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_47 > 50) {
        acc = (acc + bound_47 * 2 + 5) & 127;
        aux ^= (bound_47 & 15);
    } else {
        acc = (acc - bound_47 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_82 = local_arr[aux % 3];
    acc = (acc + damping_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_13(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_85 = 0;
    for (int k = 0; k < 2; k++) {
        stride_85 = (stride_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_85) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_69 = local_arr[aux % 3];
    acc = (acc + tally_69 * 2) & 127;
    int threshold_55 = (aux + st.buffer[1]) & 3;
    switch (threshold_55) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_14(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int stride_61 = local_arr[aux % 3];
    acc = (acc + stride_61 * 2) & 127;
    int window_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int stride_72 = local_arr[aux % 3];
    acc = (acc + stride_72 * 2) & 127;
    int index_reg_72 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_72 = (index_reg_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_72) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_88 = (aux + st.buffer[1]) & 3;
    switch (coefficient_88) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_16(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_50 = (st.buffer[0] * 3 + aux) & 63;
    if (window_50 > 13) {
        acc = (acc + window_50 * 2 + 5) & 127;
        aux ^= (window_50 & 15);
    } else {
        acc = (acc - window_50 + 11) & 127;
        aux += 3;
    }
    int vector_43 = 0;
    for (int k = 0; k < 3; k++) {
        vector_43 = (vector_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_17(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_69 = (aux + st.buffer[1]) & 3;
    switch (phase_69) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_49) & 63;
    acc ^= aux;
    int anchor_57 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_57 = (anchor_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000253_5313_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000253_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_84 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_84 = (accumulator_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_84) & 127;
    }
    int offset_44 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_44 > 34) {
        acc = (acc + offset_44 * 2 + 5) & 127;
        aux ^= (offset_44 & 15);
    } else {
        acc = (acc - offset_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_12 = local_arr[aux % 3];
    acc = (acc + index_reg_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000253_5313_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000253_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int bound_42 = local_arr[aux % 3];
    acc = (acc + bound_42 * 2) & 127;
    int factor_88 = (aux + st.buffer[1]) & 3;
    switch (factor_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_16 = 0;
    for (int k = 0; k < 3; k++) {
        parity_16 = (parity_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_16) & 127;
    }
    int weight_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000253_5313_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000253_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int segment_61 = local_arr[aux % 3];
    acc = (acc + segment_61 * 2) & 127;
    int weight_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_45) & 63;
    acc ^= aux;
    int vector_97 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_97 > 50) {
        acc = (acc + vector_97 * 2 + 5) & 127;
        aux ^= (vector_97 & 15);
    } else {
        acc = (acc - vector_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000253_0;
    int sec_r000253_1;
    int sec_r000253_2;
    int sec_r000253_3;
    int sec_r000253_4;
    int sec_r000253_5;
    int sec_r000253_6;
    int sec_r000253_7;
    int sec_r000253_8;
    int sec_r000253_9;
    int sec_r000253_10;
    int sec_r000253_11;
    int sec_r000253_12;
    int sec_r000253_13;
    int sec_r000253_14;
    int sec_r000253_15;
    int sec_r000253_16;
    int sec_r000253_17;
    int sec_r000253_18;
    int sec_r000253_19;
    int sec_r000253_20;
    int sec_r000253_21;
    int pub_r000253_0;
    int pub_r000253_1;
    int pub_r000253_2;
    int pub_r000253_3;
    int pub_r000253_4;
    int pub_r000253_5;
    int pub_r000253_6;
    int pub_r000253_7;
    int pub_r000253_8;
    int pub_r000253_9;
    int pub_r000253_10;
    int pub_r000253_11;
    int pub_r000253_12;
    int pub_r000253_13;
    int pub_r000253_14;
    int pub_r000253_15;
    int pub_r000253_16;
    int pub_r000253_17;
    int pub_r000253_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000253_0 >= -100 && pub_r000253_0 <= 100);
    __CPROVER_assume(pub_r000253_1 >= -100 && pub_r000253_1 <= 100);
    __CPROVER_assume(pub_r000253_2 >= -100 && pub_r000253_2 <= 100);
    __CPROVER_assume(pub_r000253_3 >= -100 && pub_r000253_3 <= 100);
    __CPROVER_assume(pub_r000253_4 >= -100 && pub_r000253_4 <= 100);
    __CPROVER_assume(pub_r000253_5 >= -100 && pub_r000253_5 <= 100);
    __CPROVER_assume(pub_r000253_6 >= -100 && pub_r000253_6 <= 100);
    __CPROVER_assume(pub_r000253_7 >= -100 && pub_r000253_7 <= 100);
    __CPROVER_assume(pub_r000253_8 >= -100 && pub_r000253_8 <= 100);
    __CPROVER_assume(pub_r000253_9 >= -100 && pub_r000253_9 <= 100);
    __CPROVER_assume(pub_r000253_10 >= -100 && pub_r000253_10 <= 100);
    __CPROVER_assume(pub_r000253_11 >= -100 && pub_r000253_11 <= 100);
    __CPROVER_assume(pub_r000253_12 >= -100 && pub_r000253_12 <= 100);
    __CPROVER_assume(pub_r000253_13 >= -100 && pub_r000253_13 <= 100);
    __CPROVER_assume(pub_r000253_14 >= -100 && pub_r000253_14 <= 100);
    __CPROVER_assume(pub_r000253_15 >= -100 && pub_r000253_15 <= 100);
    __CPROVER_assume(pub_r000253_16 >= -100 && pub_r000253_16 <= 100);
    __CPROVER_assume(pub_r000253_17 >= -100 && pub_r000253_17 <= 100);
    __CPROVER_assume(pub_r000253_18 >= -100 && pub_r000253_18 <= 100);
    __CPROVER_assume(sec_r000253_0 >= 0 && sec_r000253_0 <= 255);
    __CPROVER_assume(sec_r000253_1 >= 0 && sec_r000253_1 <= 255);
    __CPROVER_assume(sec_r000253_2 >= 0 && sec_r000253_2 <= 255);
    __CPROVER_assume(sec_r000253_3 >= 0 && sec_r000253_3 <= 255);
    __CPROVER_assume(sec_r000253_4 >= 0 && sec_r000253_4 <= 255);
    __CPROVER_assume(sec_r000253_5 >= 0 && sec_r000253_5 <= 255);
    __CPROVER_assume(sec_r000253_6 >= 0 && sec_r000253_6 <= 255);
    __CPROVER_assume(sec_r000253_7 >= 0 && sec_r000253_7 <= 255);
    __CPROVER_assume(sec_r000253_8 >= 0 && sec_r000253_8 <= 255);
    __CPROVER_assume(sec_r000253_9 >= 0 && sec_r000253_9 <= 255);
    __CPROVER_assume(sec_r000253_10 >= 0 && sec_r000253_10 <= 255);
    __CPROVER_assume(sec_r000253_11 >= 0 && sec_r000253_11 <= 255);
    __CPROVER_assume(sec_r000253_12 >= 0 && sec_r000253_12 <= 255);
    __CPROVER_assume(sec_r000253_13 >= 0 && sec_r000253_13 <= 255);
    __CPROVER_assume(sec_r000253_14 >= 0 && sec_r000253_14 <= 255);
    __CPROVER_assume(sec_r000253_15 >= 0 && sec_r000253_15 <= 255);
    __CPROVER_assume(sec_r000253_16 >= 0 && sec_r000253_16 <= 255);
    __CPROVER_assume(sec_r000253_17 >= 0 && sec_r000253_17 <= 255);
    __CPROVER_assume(sec_r000253_18 >= 0 && sec_r000253_18 <= 255);
    __CPROVER_assume(sec_r000253_19 >= 0 && sec_r000253_19 <= 255);
    __CPROVER_assume(sec_r000253_20 >= 0 && sec_r000253_20 <= 255);
    __CPROVER_assume(sec_r000253_21 >= 0 && sec_r000253_21 <= 255);

    struct MatrixBlock_R000253_5313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000253_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000253_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000253_0 + 7) & 15;
    struct Transaction_R000253_5313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000253_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000253_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000253_0 + 9) & 15;
    struct AudioFrame_R000253_5313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000253_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000253_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000253_0 + 11) & 15;

    union RegisterBank_R000253_5313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 10) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 25) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

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
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 26) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 41) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 27) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 42) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 20) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 35) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 12) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 27) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 10) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 25) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 31) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 46) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 38) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 53) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 23) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 38) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 23) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 38) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 28) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 43) {
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

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 17) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 32) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 35) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 50) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 29) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 44) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 28) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 43) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 35) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 50) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 30) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 45) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_101 = (stage_v_101 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 15) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 30) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 40) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 55) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 16) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 31) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 11) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 26) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[0] ^ 118) & 3;
    switch (stage_v_115) {
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

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_2.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 30) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 45) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 36) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 51) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 126 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 127) & 15;
    int stage_v_126 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= stage_v_126;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (out_sink > 100) ? (chk_sum & 31) : (132 & 31);
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= (stage_v_127 << 1) & 127;

    /* Execution Pipeline Stage 128 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (out_sink > 100) ? (chk_sum & 31) : (139 & 31);
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= (stage_v_134 << 1) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 27) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 42) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 25) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 40) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[1] * 2 + 442) & 63;
    if (stage_v_145 > 34) {
        out_sink = (out_sink + stage_v_145 - 5) & 255;
        if (stage_v_145 > 49) {
            chk_sum ^= (stage_v_145 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_145 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 36) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 51) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 20) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 35) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_2.buffer[2] * 2 + 472) & 63;
    if (stage_v_155 > 37) {
        out_sink = (out_sink + stage_v_155 - 5) & 255;
        if (stage_v_155 > 52) {
            chk_sum ^= (stage_v_155 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_155 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 37) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 52) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_163 = (stage_v_163 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = table[1];
    table[1] = (table[2] + 331) & 63;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_1.buffer[0] ^ 169) & 3;
    switch (stage_v_166) {
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

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 34) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 49) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_0.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 29) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 44) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (out_sink > 100) ? (chk_sum & 31) : (183 & 31);
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= (stage_v_178 << 1) & 127;

    /* Execution Pipeline Stage 179 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Security Information Flow: Family = multi_step_explicit */
    int m_step_0 = (sec_r000253_1 + pub_r000253_6 + 10) & 127;
    int m_step_1 = (m_step_0 + pub_r000253_17 + 18) & 127;
    int m_step_2 = (m_step_1 + pub_r000253_5 + 17) & 127;
    int m_step_3 = (m_step_2 + pub_r000253_13 + 16) & 127;
    out_sink = (out_sink + m_step_3) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
