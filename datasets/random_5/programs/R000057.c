/*
 * Benchmark Program: R000057
 * Security Family: nested_implicit_flow
 * Generator Seed: 505713
 * High Inputs: 24 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000057_5713_0 {
    int gain_db;
    unsigned char cutoff;
    unsigned char mode;
    int prev_out;
    unsigned char damping;
    unsigned char prev_in;
    int buffer[3];
};

struct CipherContext_R000057_5713_1 {
    unsigned char iv;
    int round_key;
    int flags;
    int buffer[3];
};

struct MatrixBlock_R000057_5713_2 {
    int dim;
    unsigned char determinant;
    short scale;
    int density;
    int trace;
    int buffer[3];
};

struct EventLog_R000057_5713_3 {
    int severity;
    unsigned char facility;
    short signature;
    int seq;
    int buffer[3];
};

union TelemetryField_R000057_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000057_5713_0(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000057_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_1(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000057_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int anchor_47 = local_arr[aux % 3];
    acc = (acc + anchor_47 * 2) & 127;
    int pivot_98 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_98 > 10) {
        acc = (acc + pivot_98 * 2 + 5) & 127;
        aux ^= (pivot_98 & 15);
    } else {
        acc = (acc - pivot_98 + 11) & 127;
        aux += 3;
    }
    int vector_35 = (aux + st.buffer[1]) & 3;
    switch (vector_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int threshold_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_31) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_29 = local_arr[aux % 3];
    acc = (acc + segment_29 * 2) & 127;
    int checksum_16 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_16 > 30) {
        acc = (acc + checksum_16 * 2 + 5) & 127;
        aux ^= (checksum_16 & 15);
    } else {
        acc = (acc - checksum_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_3(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_85) & 63;
    acc ^= aux;
    int delta_49 = (aux + st.buffer[1]) & 3;
    switch (delta_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000057_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_95 = (aux + st.buffer[1]) & 3;
    switch (segment_95) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_34 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_34 > 25) {
        acc = (acc + mask_34 * 2 + 5) & 127;
        aux ^= (mask_34 & 15);
    } else {
        acc = (acc - mask_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000057_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int offset_75 = local_arr[aux % 3];
    acc = (acc + offset_75 * 2) & 127;
    int offset_45 = (aux + st.buffer[1]) & 3;
    switch (offset_45) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_30 > 47) {
        acc = (acc + cursor_30 * 2 + 5) & 127;
        aux ^= (cursor_30 & 15);
    } else {
        acc = (acc - cursor_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000057_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int scale_25 = local_arr[aux % 3];
    acc = (acc + scale_25 * 2) & 127;
    int stride_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000057_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int residue_14 = local_arr[aux % 3];
    acc = (acc + residue_14 * 2) & 127;
    int delta_40 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_40 > 43) {
        acc = (acc + delta_40 * 2 + 5) & 127;
        aux ^= (delta_40 & 15);
    } else {
        acc = (acc - delta_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000057_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000057_5713_10(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000057_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_98 = local_arr[aux % 3];
    acc = (acc + pivot_98 * 2) & 127;
    int offset_41 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_41 > 11) {
        acc = (acc + offset_41 * 2 + 5) & 127;
        aux ^= (offset_41 & 15);
    } else {
        acc = (acc - offset_41 + 11) & 127;
        aux += 3;
    }
    int factor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_11(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000057_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_26 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_26 > 28) {
        acc = (acc + stride_26 * 2 + 5) & 127;
        aux ^= (stride_26 & 15);
    } else {
        acc = (acc - stride_26 + 11) & 127;
        aux += 3;
    }
    int tally_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_98 = local_arr[aux % 3];
    acc = (acc + factor_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000057_5713_12(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000057_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int checksum_95 = local_arr[aux % 3];
    acc = (acc + checksum_95 * 2) & 127;
    int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_38 = local_arr[aux % 3];
    acc = (acc + sample_38 * 2) & 127;
    int accumulator_18 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_18 > 48) {
        acc = (acc + accumulator_18 * 2 + 5) & 127;
        aux ^= (accumulator_18 & 15);
    } else {
        acc = (acc - accumulator_18 + 11) & 127;
        aux += 3;
    }
    int parity_70 = (aux + st.buffer[1]) & 3;
    switch (parity_70) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000057_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_18 = (aux + st.buffer[1]) & 3;
    switch (accumulator_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_58 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_58 > 11) {
        acc = (acc + anchor_58 * 2 + 5) & 127;
        aux ^= (anchor_58 & 15);
    } else {
        acc = (acc - anchor_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_15(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000057_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_70 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_70 > 12) {
        acc = (acc + tracker_70 * 2 + 5) & 127;
        aux ^= (tracker_70 & 15);
    } else {
        acc = (acc - tracker_70 + 11) & 127;
        aux += 3;
    }
    int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_63 = local_arr[aux % 3];
    acc = (acc + sample_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000057_5713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_45 = (aux + st.buffer[1]) & 3;
    switch (anchor_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_25 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_25 > 25) {
        acc = (acc + accumulator_25 * 2 + 5) & 127;
        aux ^= (accumulator_25 & 15);
    } else {
        acc = (acc - accumulator_25 + 11) & 127;
        aux += 3;
    }
    int segment_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000057_5713_17(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000057_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_47 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_47 > 45) {
        acc = (acc + damping_47 * 2 + 5) & 127;
        aux ^= (damping_47 & 15);
    } else {
        acc = (acc - damping_47 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_88 = local_arr[aux % 3];
    acc = (acc + index_reg_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000057_5713_18(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000057_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int window_42 = local_arr[aux % 3];
    acc = (acc + window_42 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_50 = (aux + st.buffer[1]) & 3;
    switch (segment_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000057_5713_19(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000057_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor_16 = (aux + st.buffer[1]) & 3;
    switch (cursor_16) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_89 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_89 > 37) {
        acc = (acc + metric_89 * 2 + 5) & 127;
        aux ^= (metric_89 & 15);
    } else {
        acc = (acc - metric_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000057_0;
    int sec_r000057_1;
    int sec_r000057_2;
    int sec_r000057_3;
    int sec_r000057_4;
    int sec_r000057_5;
    int sec_r000057_6;
    int sec_r000057_7;
    int sec_r000057_8;
    int sec_r000057_9;
    int sec_r000057_10;
    int sec_r000057_11;
    int sec_r000057_12;
    int sec_r000057_13;
    int sec_r000057_14;
    int sec_r000057_15;
    int sec_r000057_16;
    int sec_r000057_17;
    int sec_r000057_18;
    int sec_r000057_19;
    int sec_r000057_20;
    int sec_r000057_21;
    int sec_r000057_22;
    int sec_r000057_23;
    int pub_r000057_0;
    int pub_r000057_1;
    int pub_r000057_2;
    int pub_r000057_3;
    int pub_r000057_4;
    int pub_r000057_5;
    int pub_r000057_6;
    int pub_r000057_7;
    int pub_r000057_8;
    int pub_r000057_9;
    int pub_r000057_10;
    int pub_r000057_11;
    int pub_r000057_12;
    int pub_r000057_13;
    int pub_r000057_14;
    int pub_r000057_15;
    int pub_r000057_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000057_0 >= -100 && pub_r000057_0 <= 100);
    __CPROVER_assume(pub_r000057_1 >= -100 && pub_r000057_1 <= 100);
    __CPROVER_assume(pub_r000057_2 >= -100 && pub_r000057_2 <= 100);
    __CPROVER_assume(pub_r000057_3 >= -100 && pub_r000057_3 <= 100);
    __CPROVER_assume(pub_r000057_4 >= -100 && pub_r000057_4 <= 100);
    __CPROVER_assume(pub_r000057_5 >= -100 && pub_r000057_5 <= 100);
    __CPROVER_assume(pub_r000057_6 >= -100 && pub_r000057_6 <= 100);
    __CPROVER_assume(pub_r000057_7 >= -100 && pub_r000057_7 <= 100);
    __CPROVER_assume(pub_r000057_8 >= -100 && pub_r000057_8 <= 100);
    __CPROVER_assume(pub_r000057_9 >= -100 && pub_r000057_9 <= 100);
    __CPROVER_assume(pub_r000057_10 >= -100 && pub_r000057_10 <= 100);
    __CPROVER_assume(pub_r000057_11 >= -100 && pub_r000057_11 <= 100);
    __CPROVER_assume(pub_r000057_12 >= -100 && pub_r000057_12 <= 100);
    __CPROVER_assume(pub_r000057_13 >= -100 && pub_r000057_13 <= 100);
    __CPROVER_assume(pub_r000057_14 >= -100 && pub_r000057_14 <= 100);
    __CPROVER_assume(pub_r000057_15 >= -100 && pub_r000057_15 <= 100);
    __CPROVER_assume(pub_r000057_16 >= -100 && pub_r000057_16 <= 100);
    __CPROVER_assume(sec_r000057_0 >= 0 && sec_r000057_0 <= 255);
    __CPROVER_assume(sec_r000057_1 >= 0 && sec_r000057_1 <= 255);
    __CPROVER_assume(sec_r000057_2 >= 0 && sec_r000057_2 <= 255);
    __CPROVER_assume(sec_r000057_3 >= 0 && sec_r000057_3 <= 255);
    __CPROVER_assume(sec_r000057_4 >= 0 && sec_r000057_4 <= 255);
    __CPROVER_assume(sec_r000057_5 >= 0 && sec_r000057_5 <= 255);
    __CPROVER_assume(sec_r000057_6 >= 0 && sec_r000057_6 <= 255);
    __CPROVER_assume(sec_r000057_7 >= 0 && sec_r000057_7 <= 255);
    __CPROVER_assume(sec_r000057_8 >= 0 && sec_r000057_8 <= 255);
    __CPROVER_assume(sec_r000057_9 >= 0 && sec_r000057_9 <= 255);
    __CPROVER_assume(sec_r000057_10 >= 0 && sec_r000057_10 <= 255);
    __CPROVER_assume(sec_r000057_11 >= 0 && sec_r000057_11 <= 255);
    __CPROVER_assume(sec_r000057_12 >= 0 && sec_r000057_12 <= 255);
    __CPROVER_assume(sec_r000057_13 >= 0 && sec_r000057_13 <= 255);
    __CPROVER_assume(sec_r000057_14 >= 0 && sec_r000057_14 <= 255);
    __CPROVER_assume(sec_r000057_15 >= 0 && sec_r000057_15 <= 255);
    __CPROVER_assume(sec_r000057_16 >= 0 && sec_r000057_16 <= 255);
    __CPROVER_assume(sec_r000057_17 >= 0 && sec_r000057_17 <= 255);
    __CPROVER_assume(sec_r000057_18 >= 0 && sec_r000057_18 <= 255);
    __CPROVER_assume(sec_r000057_19 >= 0 && sec_r000057_19 <= 255);
    __CPROVER_assume(sec_r000057_20 >= 0 && sec_r000057_20 <= 255);
    __CPROVER_assume(sec_r000057_21 >= 0 && sec_r000057_21 <= 255);
    __CPROVER_assume(sec_r000057_22 >= 0 && sec_r000057_22 <= 255);
    __CPROVER_assume(sec_r000057_23 >= 0 && sec_r000057_23 <= 255);

    struct FilterState_R000057_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000057_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000057_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000057_0 + 7) & 15;
    struct CipherContext_R000057_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000057_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000057_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000057_0 + 9) & 15;
    struct MatrixBlock_R000057_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000057_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000057_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000057_0 + 11) & 15;
    struct EventLog_R000057_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000057_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000057_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000057_0 + 13) & 15;

    union TelemetryField_R000057_5713_0 u_var;
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
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 12) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 27) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 18) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 33) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 20) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 35) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 16) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 31) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 21) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 36) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
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
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 24) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 39) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 19) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 34) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 19) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 34) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 25) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 40) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 37) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 52) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 27) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 42) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000057_9 & 1) != 0) {
        if ((sec_r000057_21 & 2) != 0) {
            stage_v_75 = (pub_r000057_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000057_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000057_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000057_15 & 2) != 0) {
            stage_v_76 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000057_13 & 2) != 0) {
            stage_v_77 = (pub_r000057_4 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000057_4 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000057_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000057_14 & 2) != 0) {
            stage_v_78 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000057_2 & 1) != 0) {
        if ((sec_r000057_17 & 2) != 0) {
            stage_v_79 = (pub_r000057_5 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000057_5 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000057_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000057_14 & 2) != 0) {
            stage_v_80 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000057_16 & 2) != 0) {
            stage_v_81 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000057_17 & 2) != 0) {
            stage_v_82 = (pub_r000057_2 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000057_2 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000057_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_83 = (pub_r000057_6 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000057_6 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000057_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000057_3 & 2) != 0) {
            stage_v_84 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000057_19 & 2) != 0) {
            stage_v_85 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000057_15 & 2) != 0) {
            stage_v_86 = (pub_r000057_1 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000057_1 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000057_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_87 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000057_1 & 1) != 0) {
        if ((sec_r000057_10 & 2) != 0) {
            stage_v_88 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000057_11 & 1) != 0) {
        if ((sec_r000057_17 & 2) != 0) {
            stage_v_89 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000057_19 & 2) != 0) {
            stage_v_90 = (pub_r000057_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000057_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000057_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000057_16 & 1) != 0) {
        if ((sec_r000057_21 & 2) != 0) {
            stage_v_91 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000057_0 & 1) != 0) {
        if ((sec_r000057_3 & 2) != 0) {
            stage_v_92 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_93 = (pub_r000057_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000057_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000057_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000057_2 & 1) != 0) {
        if ((sec_r000057_23 & 2) != 0) {
            stage_v_94 = (pub_r000057_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000057_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000057_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000057_22 & 2) != 0) {
            stage_v_95 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000057_12 & 2) != 0) {
            stage_v_96 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000057_8 & 2) != 0) {
            stage_v_97 = (pub_r000057_11 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000057_11 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000057_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_98 = (pub_r000057_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000057_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000057_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000057_11 & 2) != 0) {
            stage_v_99 = (pub_r000057_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000057_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000057_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000057_11 & 2) != 0) {
            stage_v_100 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_101 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000057_6 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_102 = (pub_r000057_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000057_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000057_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_103 = (pub_r000057_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000057_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000057_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000057_2 & 1) != 0) {
        if ((sec_r000057_22 & 2) != 0) {
            stage_v_104 = (pub_r000057_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000057_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000057_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000057_23 & 1) != 0) {
        if ((sec_r000057_20 & 2) != 0) {
            stage_v_105 = (pub_r000057_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000057_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000057_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000057_14 & 2) != 0) {
            stage_v_106 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_107 = (pub_r000057_7 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000057_7 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000057_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000057_11 & 2) != 0) {
            stage_v_108 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_109 = (pub_r000057_10 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000057_10 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000057_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000057_18 & 1) != 0) {
        if ((sec_r000057_7 & 2) != 0) {
            stage_v_110 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000057_17 & 1) != 0) {
        if ((sec_r000057_2 & 2) != 0) {
            stage_v_111 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000057_2 & 2) != 0) {
            stage_v_112 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000057_19 & 2) != 0) {
            stage_v_113 = (pub_r000057_5 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000057_5 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000057_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000057_5 & 1) != 0) {
        if ((sec_r000057_5 & 2) != 0) {
            stage_v_114 = (pub_r000057_4 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000057_4 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000057_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000057_5 & 2) != 0) {
            stage_v_115 = (pub_r000057_1 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000057_1 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000057_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000057_10 & 2) != 0) {
            stage_v_116 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000057_13 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_117 = (pub_r000057_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000057_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000057_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_118 = (pub_r000057_11 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000057_11 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000057_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_119 = (pub_r000057_10 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000057_10 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000057_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000057_5 & 2) != 0) {
            stage_v_120 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000057_2 & 2) != 0) {
            stage_v_121 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000057_7 & 1) != 0) {
        if ((sec_r000057_21 & 2) != 0) {
            stage_v_122 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000057_7 & 2) != 0) {
            stage_v_123 = (pub_r000057_1 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000057_1 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000057_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000057_9 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_124 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_125 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000057_16 & 2) != 0) {
            stage_v_126 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_127 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_128 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000057_6 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_129 = (pub_r000057_4 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000057_4 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000057_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000057_10 & 2) != 0) {
            stage_v_130 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000057_22 & 2) != 0) {
            stage_v_131 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_132 = (pub_r000057_6 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000057_6 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000057_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000057_4 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_133 = (pub_r000057_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000057_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000057_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_134 = (pub_r000057_2 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000057_2 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000057_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000057_10 & 1) != 0) {
        if ((sec_r000057_23 & 2) != 0) {
            stage_v_135 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000057_1 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_136 = (pub_r000057_14 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000057_14 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000057_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000057_22 & 2) != 0) {
            stage_v_137 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000057_5 & 1) != 0) {
        if ((sec_r000057_4 & 2) != 0) {
            stage_v_138 = (pub_r000057_2 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000057_2 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000057_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000057_1 & 1) != 0) {
        if ((sec_r000057_20 & 2) != 0) {
            stage_v_139 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_140 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000057_15 & 2) != 0) {
            stage_v_141 = (pub_r000057_4 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000057_4 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000057_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000057_13 & 1) != 0) {
        if ((sec_r000057_19 & 2) != 0) {
            stage_v_142 = (pub_r000057_10 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000057_10 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000057_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000057_17 & 2) != 0) {
            stage_v_143 = (pub_r000057_11 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000057_11 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000057_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000057_4 & 2) != 0) {
            stage_v_144 = (pub_r000057_6 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000057_6 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000057_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000057_12 & 2) != 0) {
            stage_v_145 = (pub_r000057_4 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000057_4 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000057_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000057_20 & 1) != 0) {
        if ((sec_r000057_12 & 2) != 0) {
            stage_v_146 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000057_20 & 1) != 0) {
        if ((sec_r000057_11 & 2) != 0) {
            stage_v_147 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000057_3 & 2) != 0) {
            stage_v_148 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000057_18 & 2) != 0) {
            stage_v_149 = (pub_r000057_7 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000057_7 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000057_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000057_16 & 2) != 0) {
            stage_v_150 = (pub_r000057_3 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000057_3 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000057_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000057_0 & 2) != 0) {
            stage_v_151 = (pub_r000057_11 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000057_11 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000057_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000057_2 & 2) != 0) {
            stage_v_152 = (pub_r000057_11 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000057_11 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000057_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000057_21 & 2) != 0) {
            stage_v_153 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000057_15 & 1) != 0) {
        if ((sec_r000057_13 & 2) != 0) {
            stage_v_154 = (pub_r000057_15 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000057_15 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000057_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000057_11 & 2) != 0) {
            stage_v_155 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_156 = (pub_r000057_12 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000057_12 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000057_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000057_19 & 2) != 0) {
            stage_v_157 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000057_20 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_158 = (pub_r000057_9 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000057_9 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000057_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r000057_23 & 2) != 0) {
            stage_v_159 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000057_20 & 2) != 0) {
            stage_v_160 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000057_19 & 1) != 0) {
        if ((sec_r000057_12 & 2) != 0) {
            stage_v_161 = (pub_r000057_10 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000057_10 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000057_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_162 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000057_9 & 2) != 0) {
            stage_v_163 = (pub_r000057_0 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000057_0 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000057_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000057_7 & 2) != 0) {
            stage_v_164 = (pub_r000057_13 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000057_13 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000057_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_160 & 1) != 0) {
        if ((sec_r000057_1 & 2) != 0) {
            stage_v_165 = (pub_r000057_16 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000057_16 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000057_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000057_6 & 2) != 0) {
            stage_v_166 = (pub_r000057_1 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000057_1 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000057_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000057_15 & 1) != 0) {
        if ((sec_r000057_12 & 2) != 0) {
            stage_v_167 = (pub_r000057_12 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000057_12 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000057_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_165 & 1) != 0) {
        if ((sec_r000057_13 & 2) != 0) {
            stage_v_168 = (pub_r000057_8 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000057_8 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000057_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r000057_17 & 2) != 0) {
            stage_v_169 = (pub_r000057_5 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000057_5 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000057_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000057_5 & 2) != 0) {
            stage_v_170 = (pub_r000057_12 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000057_12 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000057_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
