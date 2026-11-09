/*
 * Benchmark Program: R001220
 * Security Family: mixed_control_data
 * Generator Seed: 622013
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001220_2013_0 {
    short trace;
    short scale;
    short stride;
    unsigned char dim;
    int buffer[3];
};

struct FilterState_R001220_2013_1 {
    short prev_out;
    int gain_db;
    int damping;
    int mode;
    short cutoff;
    int buffer[3];
};

union PacketPayload_R001220_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001220_2013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001220_2013_0(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int anchor_99 = local_arr[aux % 3];
    acc = (acc + anchor_99 * 2) & 127;
    int offset_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_72) & 63;
    acc ^= aux;
    int window_54 = (st.buffer[0] * 3 + aux) & 63;
    if (window_54 > 20) {
        acc = (acc + window_54 * 2 + 5) & 127;
        aux ^= (window_54 & 15);
    } else {
        acc = (acc - window_54 + 11) & 127;
        aux += 3;
    }
    int metric_27 = (aux + st.buffer[1]) & 3;
    switch (metric_27) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int coefficient_25 = (aux + st.buffer[1]) & 3;
    switch (coefficient_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_17 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_17 = (anchor_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_17) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_72 = local_arr[aux % 3];
    acc = (acc + scale_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_57 = (aux + st.buffer[1]) & 3;
    switch (vector_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_67 = local_arr[aux % 3];
    acc = (acc + index_reg_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_4(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int tracker_11 = local_arr[aux % 3];
    acc = (acc + tracker_11 * 2) & 127;
    int stride_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_84) & 63;
    acc ^= aux;
    int cursor_36 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_36 = (cursor_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_36) & 127;
    }
    int delta_59 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_59 > 16) {
        acc = (acc + delta_59 * 2 + 5) & 127;
        aux ^= (delta_59 & 15);
    } else {
        acc = (acc - delta_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_42 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_42 > 27) {
        acc = (acc + weight_42 * 2 + 5) & 127;
        aux ^= (weight_42 & 15);
    } else {
        acc = (acc - weight_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_6(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_47 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_47 > 12) {
        acc = (acc + scale_47 * 2 + 5) & 127;
        aux ^= (scale_47 & 15);
    } else {
        acc = (acc - scale_47 + 11) & 127;
        aux += 3;
    }
    int factor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_89) & 63;
    acc ^= aux;
    int mask_41 = 0;
    for (int k = 0; k < 3; k++) {
        mask_41 = (mask_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_41) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_42 = local_arr[aux % 3];
    acc = (acc + segment_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_7(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_58 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_58 > 34) {
        acc = (acc + mask_58 * 2 + 5) & 127;
        aux ^= (mask_58 & 15);
    } else {
        acc = (acc - mask_58 + 11) & 127;
        aux += 3;
    }
    int parity_52 = (aux + st.buffer[1]) & 3;
    switch (parity_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_45) & 63;
    acc ^= aux;
    int factor_94 = 0;
    for (int k = 0; k < 3; k++) {
        factor_94 = (factor_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_8(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_84) & 63;
    acc ^= aux;
    int anchor_63 = (aux + st.buffer[1]) & 3;
    switch (anchor_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_18 = (aux + st.buffer[1]) & 3;
    switch (tally_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_70 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_70 = (threshold_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_70) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_85 = local_arr[aux % 3];
    acc = (acc + mask_85 * 2) & 127;
    int threshold_74 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_74 > 22) {
        acc = (acc + threshold_74 * 2 + 5) & 127;
        aux ^= (threshold_74 & 15);
    } else {
        acc = (acc - threshold_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_10(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_12) & 63;
    acc ^= aux;
    int damping_91 = 0;
    for (int k = 0; k < 3; k++) {
        damping_91 = (damping_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_91) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_88 = 0;
    for (int k = 0; k < 3; k++) {
        metric_88 = (metric_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_88) & 127;
    }
    int margin_56 = (aux + st.buffer[1]) & 3;
    switch (margin_56) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_12(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_99 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_99 > 18) {
        acc = (acc + stride_99 * 2 + 5) & 127;
        aux ^= (stride_99 & 15);
    } else {
        acc = (acc - stride_99 + 11) & 127;
        aux += 3;
    }
    int tracker_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_63) & 63;
    acc ^= aux;
    int tracker_40 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_40 = (tracker_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_94 = local_arr[aux % 3];
    acc = (acc + pivot_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_97 = 0;
    for (int k = 0; k < 3; k++) {
        phase_97 = (phase_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_97) & 127;
    }
    int threshold_32 = (aux + st.buffer[1]) & 3;
    switch (threshold_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int scale_54 = local_arr[aux % 3];
    acc = (acc + scale_54 * 2) & 127;
    int mask_67 = 0;
    for (int k = 0; k < 2; k++) {
        mask_67 = (mask_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_67) & 127;
    }
    int coefficient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_32) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001220_2013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_67 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_67 > 45) {
        acc = (acc + coefficient_67 * 2 + 5) & 127;
        aux ^= (coefficient_67 & 15);
    } else {
        acc = (acc - coefficient_67 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_14 = 0;
    for (int k = 0; k < 2; k++) {
        delta_14 = (delta_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_16(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001220_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_12 = 0;
    for (int k = 0; k < 2; k++) {
        parity_12 = (parity_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001220_2013_17(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int checksum_75 = local_arr[aux % 3];
    acc = (acc + checksum_75 * 2) & 127;
    int bound_87 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_87 > 34) {
        acc = (acc + bound_87 * 2 + 5) & 127;
        aux ^= (bound_87 & 15);
    } else {
        acc = (acc - bound_87 + 11) & 127;
        aux += 3;
    }
    int phase_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001220_2013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001220_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_99 = (aux + st.buffer[1]) & 3;
    switch (accumulator_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001220_0;
    int sec_r001220_1;
    int sec_r001220_2;
    int sec_r001220_3;
    int sec_r001220_4;
    int sec_r001220_5;
    int sec_r001220_6;
    int sec_r001220_7;
    int sec_r001220_8;
    int sec_r001220_9;
    int sec_r001220_10;
    int sec_r001220_11;
    int sec_r001220_12;
    int sec_r001220_13;
    int sec_r001220_14;
    int sec_r001220_15;
    int sec_r001220_16;
    int sec_r001220_17;
    int sec_r001220_18;
    int pub_r001220_0;
    int pub_r001220_1;
    int pub_r001220_2;
    int pub_r001220_3;
    int pub_r001220_4;
    int pub_r001220_5;
    int pub_r001220_6;
    int pub_r001220_7;
    int pub_r001220_8;
    int pub_r001220_9;
    int pub_r001220_10;
    int pub_r001220_11;
    int pub_r001220_12;
    int pub_r001220_13;
    int pub_r001220_14;
    int pub_r001220_15;
    int pub_r001220_16;
    int pub_r001220_17;
    int pub_r001220_18;
    int pub_r001220_19;
    int pub_r001220_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001220_0 >= -100 && pub_r001220_0 <= 100);
    __CPROVER_assume(pub_r001220_1 >= -100 && pub_r001220_1 <= 100);
    __CPROVER_assume(pub_r001220_2 >= -100 && pub_r001220_2 <= 100);
    __CPROVER_assume(pub_r001220_3 >= -100 && pub_r001220_3 <= 100);
    __CPROVER_assume(pub_r001220_4 >= -100 && pub_r001220_4 <= 100);
    __CPROVER_assume(pub_r001220_5 >= -100 && pub_r001220_5 <= 100);
    __CPROVER_assume(pub_r001220_6 >= -100 && pub_r001220_6 <= 100);
    __CPROVER_assume(pub_r001220_7 >= -100 && pub_r001220_7 <= 100);
    __CPROVER_assume(pub_r001220_8 >= -100 && pub_r001220_8 <= 100);
    __CPROVER_assume(pub_r001220_9 >= -100 && pub_r001220_9 <= 100);
    __CPROVER_assume(pub_r001220_10 >= -100 && pub_r001220_10 <= 100);
    __CPROVER_assume(pub_r001220_11 >= -100 && pub_r001220_11 <= 100);
    __CPROVER_assume(pub_r001220_12 >= -100 && pub_r001220_12 <= 100);
    __CPROVER_assume(pub_r001220_13 >= -100 && pub_r001220_13 <= 100);
    __CPROVER_assume(pub_r001220_14 >= -100 && pub_r001220_14 <= 100);
    __CPROVER_assume(pub_r001220_15 >= -100 && pub_r001220_15 <= 100);
    __CPROVER_assume(pub_r001220_16 >= -100 && pub_r001220_16 <= 100);
    __CPROVER_assume(pub_r001220_17 >= -100 && pub_r001220_17 <= 100);
    __CPROVER_assume(pub_r001220_18 >= -100 && pub_r001220_18 <= 100);
    __CPROVER_assume(pub_r001220_19 >= -100 && pub_r001220_19 <= 100);
    __CPROVER_assume(pub_r001220_20 >= -100 && pub_r001220_20 <= 100);
    __CPROVER_assume(sec_r001220_0 >= 0 && sec_r001220_0 <= 255);
    __CPROVER_assume(sec_r001220_1 >= 0 && sec_r001220_1 <= 255);
    __CPROVER_assume(sec_r001220_2 >= 0 && sec_r001220_2 <= 255);
    __CPROVER_assume(sec_r001220_3 >= 0 && sec_r001220_3 <= 255);
    __CPROVER_assume(sec_r001220_4 >= 0 && sec_r001220_4 <= 255);
    __CPROVER_assume(sec_r001220_5 >= 0 && sec_r001220_5 <= 255);
    __CPROVER_assume(sec_r001220_6 >= 0 && sec_r001220_6 <= 255);
    __CPROVER_assume(sec_r001220_7 >= 0 && sec_r001220_7 <= 255);
    __CPROVER_assume(sec_r001220_8 >= 0 && sec_r001220_8 <= 255);
    __CPROVER_assume(sec_r001220_9 >= 0 && sec_r001220_9 <= 255);
    __CPROVER_assume(sec_r001220_10 >= 0 && sec_r001220_10 <= 255);
    __CPROVER_assume(sec_r001220_11 >= 0 && sec_r001220_11 <= 255);
    __CPROVER_assume(sec_r001220_12 >= 0 && sec_r001220_12 <= 255);
    __CPROVER_assume(sec_r001220_13 >= 0 && sec_r001220_13 <= 255);
    __CPROVER_assume(sec_r001220_14 >= 0 && sec_r001220_14 <= 255);
    __CPROVER_assume(sec_r001220_15 >= 0 && sec_r001220_15 <= 255);
    __CPROVER_assume(sec_r001220_16 >= 0 && sec_r001220_16 <= 255);
    __CPROVER_assume(sec_r001220_17 >= 0 && sec_r001220_17 <= 255);
    __CPROVER_assume(sec_r001220_18 >= 0 && sec_r001220_18 <= 255);

    struct MatrixBlock_R001220_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001220_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001220_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001220_0 + 7) & 15;
    struct FilterState_R001220_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001220_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001220_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001220_0 + 9) & 15;

    union PacketPayload_R001220_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001220_2013_0(sec_r001220_0, sec_r001220_1, pub_r001220_2);
    int helper_flow_1 = fn_R001220_2013_1(sec_r001220_1, pub_r001220_2, pub_r001220_3, pub_r001220_4);
    int helper_flow_2 = fn_R001220_2013_2(sec_r001220_2, sec_r001220_3, pub_r001220_4, pub_r001220_5, pub_r001220_6);
    int helper_flow_3 = fn_R001220_2013_3(sec_r001220_3, sec_r001220_4, pub_r001220_5, pub_r001220_6, pub_r001220_7);
    int helper_flow_4 = fn_R001220_2013_4(sec_r001220_4, sec_r001220_5, pub_r001220_6);
    int helper_flow_5 = fn_R001220_2013_5(sec_r001220_5, sec_r001220_6, pub_r001220_7, pub_r001220_8, pub_r001220_9);
    int helper_flow_6 = fn_R001220_2013_6(sec_r001220_6, sec_r001220_7);
    int helper_flow_7 = fn_R001220_2013_7(sec_r001220_7, sec_r001220_8, pub_r001220_9);
    int helper_flow_8 = fn_R001220_2013_8(sec_r001220_8, pub_r001220_9);
    int helper_flow_9 = fn_R001220_2013_9(sec_r001220_9, sec_r001220_10, pub_r001220_11, pub_r001220_12, pub_r001220_13);
    int helper_flow_10 = fn_R001220_2013_10(sec_r001220_10, sec_r001220_11, pub_r001220_12);
    int helper_flow_11 = fn_R001220_2013_11(sec_r001220_11, pub_r001220_12, pub_r001220_13, pub_r001220_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_0 > 43) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001220_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_2 > 21) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001220_10 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_3 > 26) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001220_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001220_20 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_6 > 46) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001220_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_8 > 38) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001220_4 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_9 > 47) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_10 > 26) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_11 > 32) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_12 > 36) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_13 > 43) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_14 > 44) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001220_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001220_4 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_16 > 35) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001220_2 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_17 > 37) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001220_0 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_18 > 30) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001220_5 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_19 > 23) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_20 > 25) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_21 > 33) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_22 > 25) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_23 > 41) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001220_0) & 127;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001220_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_26 > 41) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001220_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_28 > 48) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001220_11 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_29 > 36) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_30 > 31) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_31 > 46) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001220_12 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_32 > 23) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001220_4) & 127;
    if (stage_v_33 > 44) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_34 > 32) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_35 > 35) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_36 > 20) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_37 > 37) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_38 > 33) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001220_10 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_39 > 29) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001220_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001220_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_42 > 25) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_43 > 45) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_44 > 23) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001220_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_46 > 40) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_47 > 29) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001220_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001220_6 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_49 > 30) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001220_0) & 127;
    if (stage_v_50 > 33) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001220_17 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_51 > 32) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_52 > 50) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_53 > 38) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_54 > 38) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001220_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_56 > 42) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_57 > 35) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001220_11 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_58 > 38) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001220_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_60 > 38) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001220_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001220_10 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_62 > 30) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_63 > 45) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001220_4 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_64 > 23) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_65 > 34) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001220_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_67 > 44) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_68 > 47) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_69 > 32) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001220_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001220_0 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_71 > 35) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_72 > 33) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001220_7 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_73 > 25) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_74 > 32) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001220_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_76 > 45) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_78 > 41) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_79 > 49) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_80 > 30) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001220_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001220_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001220_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_84 > 45) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_85 > 21) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001220_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_88 > 39) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001220_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_90 > 38) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_91 > 36) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001220_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_93 > 40) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_94 > 32) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001220_2 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_95 > 25) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_96 > 36) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_97 > 30) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_98 > 29) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_99 > 29) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_100 > 49) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_101 > 21) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001220_10 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_102 > 46) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001220_2 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_103 > 24) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_104 > 26) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001220_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_106 > 32) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_107 > 44) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001220_14 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_109 > 47) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_110 > 31) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_111 > 36) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_112 > 38) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_113 > 23) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001220_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001220_18 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001220_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001220_12 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_117 > 23) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_118 > 35) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_119 > 34) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001220_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_121 > 26) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_122 > 23) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_123 > 46) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_124 > 50) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_125 > 49) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_126 > 43) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_127 > 35) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_128 > 27) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_129 > 49) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_130 > 28) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_131 > 30) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_132 > 48) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_133 > 36) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001220_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001220_18 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_135 > 41) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_136 > 33) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001220_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_138 > 26) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_139 > 21) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001220_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_141 > 35) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_142 > 37) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_143 > 41) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_144 > 23) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001220_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_146 > 40) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r001220_7 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_147 > 50) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_148 > 36) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001220_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_150 > 41) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_151 > 29) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001220_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_153 > 45) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_154 > 41) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_155 > 35) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001220_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_157 > 26) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001220_4) & 127;
    if (stage_v_158 > 44) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_159 > 27) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001220_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001220_3) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_163 > 34) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_164 > 35) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_165 > 43) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001220_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_167 > 21) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001220_12 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_168 > 49) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001220_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001220_15 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_170 > 45) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001220_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_172 > 29) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_173 > 39) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_174 > 35) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_175 > 25) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001220_4 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_176 > 25) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001220_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_178 > 22) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001220_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_180 > 32) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_181 > 25) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_182 > 26) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001220_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001220_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_185 > 39) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_186 > 45) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_187 > 47) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001220_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001220_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_190 > 50) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_191 > 44) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r001220_1 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_192 > 30) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_193 > 37) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_194 > 32) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_195 > 21) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_196 > 28) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001220_4) & 127;
    if (stage_v_197 > 34) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001220_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_199 > 45) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001220_5 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_200 > 37) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001220_18 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_201 > 48) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_202 > 46) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001220_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_204 > 32) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_205 > 37) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_206 > 22) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001220_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001220_2) & 127;
    if (stage_v_208 > 48) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001220_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_210 > 46) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_211 > 28) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001220_9) & 127;
    if (stage_v_212 > 28) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001220_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_214 > 40) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_215 > 44) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001220_7) & 127;
    if (stage_v_216 > 39) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001220_11) & 127;
    if (stage_v_217 > 34) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001220_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_215 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_219 > 29) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001220_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_221 > 30) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001220_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_223 > 26) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_195 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_224 > 44) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001220_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_226 > 21) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_227 > 23) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_228 > 23) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001220_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_230 > 38) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001220_9 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_231 > 28) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_232 > 50) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001220_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001220_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_235 > 21) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_208 ^ 0x2A) * 2 + pub_r001220_4) & 127;
    if (stage_v_236 > 48) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r001220_13 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_237 > 38) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_238 > 33) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001220_18) & 127;
    if (stage_v_239 > 23) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001220_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_186 ^ 0x2A) * 2 + pub_r001220_13) & 127;
    if (stage_v_241 > 33) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001220_5 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_242 > 28) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_243 > 50) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_244 > 23) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_245 > 23) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001220_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_247 > 25) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((sec_r001220_18 ^ 0x2A) * 2 + pub_r001220_14) & 127;
    if (stage_v_248 > 48) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001220_12) & 127;
    if (stage_v_249 > 20) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001220_20) & 127;
    if (stage_v_250 > 32) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r001220_14 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_251 > 35) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001220_8) & 127;
    if (stage_v_252 > 20) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001220_5 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_253 > 31) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001220_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_255 > 43) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001220_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001220_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001220_17) & 127;
    if (stage_v_258 > 27) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001220_15) & 127;
    if (stage_v_259 > 37) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001220_1) & 127;
    if (stage_v_260 > 47) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001220_19) & 127;
    if (stage_v_261 > 36) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001220_16) & 127;
    if (stage_v_262 > 34) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_214 ^ 0x2A) * 2 + pub_r001220_5) & 127;
    if (stage_v_263 > 41) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_249 ^ 0x2A) * 2 + pub_r001220_6) & 127;
    if (stage_v_264 > 44) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r001220_17 ^ 0x2A) * 2 + pub_r001220_10) & 127;
    if (stage_v_265 > 31) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_265) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
