/*
 * Benchmark Program: R000967
 * Security Family: nested_implicit_flow
 * Generator Seed: 596713
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000967_6713_0 {
    short code;
    int timestamp;
    unsigned char severity;
    int seq;
    int buffer[3];
};

struct Transaction_R000967_6713_1 {
    int fee;
    int account_id;
    int rate;
    int buffer[3];
};

struct StreamBuffer_R000967_6713_2 {
    short tail;
    int state;
    unsigned char watermark;
    short checksum;
    int buffer[3];
};

struct MatrixBlock_R000967_6713_3 {
    int stride;
    int dim;
    unsigned char trace;
    int density;
    int scale;
    int buffer[3];
};

union TelemetryField_R000967_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000967_6713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000967_6713_0(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_91 = (aux + st.buffer[1]) & 3;
    switch (segment_91) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_30 = local_arr[aux % 3];
    acc = (acc + mask_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000967_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int tracker_21 = local_arr[aux % 3];
    acc = (acc + tracker_21 * 2) & 127;
    int pivot_69 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_69 > 19) {
        acc = (acc + pivot_69 * 2 + 5) & 127;
        aux ^= (pivot_69 & 15);
    } else {
        acc = (acc - pivot_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_33 = (aux + st.buffer[1]) & 3;
    switch (factor_33) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000967_6713_2(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int stride_17 = local_arr[aux % 3];
    acc = (acc + stride_17 * 2) & 127;
    int delta_40 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_40 > 31) {
        acc = (acc + delta_40 * 2 + 5) & 127;
        aux ^= (delta_40 & 15);
    } else {
        acc = (acc - delta_40 + 11) & 127;
        aux += 3;
    }
    int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_3(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_69 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_69 > 21) {
        acc = (acc + residue_69 * 2 + 5) & 127;
        aux ^= (residue_69 & 15);
    } else {
        acc = (acc - residue_69 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_63 = local_arr[aux % 3];
    acc = (acc + index_reg_63 * 2) & 127;
    int accumulator_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_4(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000967_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int threshold_33 = (aux + st.buffer[1]) & 3;
    switch (threshold_33) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_16 = local_arr[aux % 3];
    acc = (acc + pivot_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_92 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_92 > 33) {
        acc = (acc + quantum_92 * 2 + 5) & 127;
        aux ^= (quantum_92 & 15);
    } else {
        acc = (acc - quantum_92 + 11) & 127;
        aux += 3;
    }
    int phase_51 = (aux + st.buffer[1]) & 3;
    switch (phase_51) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_88 = local_arr[aux % 3];
    acc = (acc + checksum_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_6(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int segment_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_17) & 63;
    acc ^= aux;
    int segment_31 = (aux + st.buffer[1]) & 3;
    switch (segment_31) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000967_6713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_65 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_65 > 44) {
        acc = (acc + margin_65 * 2 + 5) & 127;
        aux ^= (margin_65 & 15);
    } else {
        acc = (acc - margin_65 + 11) & 127;
        aux += 3;
    }
    int checksum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000967_6713_8(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_13 = (aux + st.buffer[1]) & 3;
    switch (threshold_13) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_46) & 63;
    acc ^= aux;
    int delta_51 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_51 > 24) {
        acc = (acc + delta_51 * 2 + 5) & 127;
        aux ^= (delta_51 & 15);
    } else {
        acc = (acc - delta_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_9(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int sample_58 = local_arr[aux % 3];
    acc = (acc + sample_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_84 = (aux + st.buffer[1]) & 3;
    switch (threshold_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000967_6713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_25 = (aux + st.buffer[1]) & 3;
    switch (parity_25) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_41 = local_arr[aux % 3];
    acc = (acc + checksum_41 * 2) & 127;
    int bound_61 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_61 > 49) {
        acc = (acc + bound_61 * 2 + 5) & 127;
        aux ^= (bound_61 & 15);
    } else {
        acc = (acc - bound_61 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_85 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_85 > 22) {
        acc = (acc + mask_85 * 2 + 5) & 127;
        aux ^= (mask_85 & 15);
    } else {
        acc = (acc - mask_85 + 11) & 127;
        aux += 3;
    }
    int checksum_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000967_6713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_99) & 63;
    acc ^= aux;
    int parity_44 = (aux + st.buffer[1]) & 3;
    switch (parity_44) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_82 = local_arr[aux % 3];
    acc = (acc + factor_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_13(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000967_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_54 = local_arr[aux % 3];
    acc = (acc + accumulator_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000967_6713_14(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_86 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_86 > 13) {
        acc = (acc + weight_86 * 2 + 5) & 127;
        aux ^= (weight_86 & 15);
    } else {
        acc = (acc - weight_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_65 = local_arr[aux % 3];
    acc = (acc + mask_65 * 2) & 127;
    int tally_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000967_0;
    int sec_r000967_1;
    int sec_r000967_2;
    int sec_r000967_3;
    int sec_r000967_4;
    int sec_r000967_5;
    int sec_r000967_6;
    int sec_r000967_7;
    int sec_r000967_8;
    int sec_r000967_9;
    int sec_r000967_10;
    int sec_r000967_11;
    int sec_r000967_12;
    int sec_r000967_13;
    int sec_r000967_14;
    int sec_r000967_15;
    int sec_r000967_16;
    int sec_r000967_17;
    int sec_r000967_18;
    int sec_r000967_19;
    int sec_r000967_20;
    int sec_r000967_21;
    int pub_r000967_0;
    int pub_r000967_1;
    int pub_r000967_2;
    int pub_r000967_3;
    int pub_r000967_4;
    int pub_r000967_5;
    int pub_r000967_6;
    int pub_r000967_7;
    int pub_r000967_8;
    int pub_r000967_9;
    int pub_r000967_10;
    int pub_r000967_11;
    int pub_r000967_12;
    int pub_r000967_13;
    int pub_r000967_14;
    int pub_r000967_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000967_0 >= -100 && pub_r000967_0 <= 100);
    __CPROVER_assume(pub_r000967_1 >= -100 && pub_r000967_1 <= 100);
    __CPROVER_assume(pub_r000967_2 >= -100 && pub_r000967_2 <= 100);
    __CPROVER_assume(pub_r000967_3 >= -100 && pub_r000967_3 <= 100);
    __CPROVER_assume(pub_r000967_4 >= -100 && pub_r000967_4 <= 100);
    __CPROVER_assume(pub_r000967_5 >= -100 && pub_r000967_5 <= 100);
    __CPROVER_assume(pub_r000967_6 >= -100 && pub_r000967_6 <= 100);
    __CPROVER_assume(pub_r000967_7 >= -100 && pub_r000967_7 <= 100);
    __CPROVER_assume(pub_r000967_8 >= -100 && pub_r000967_8 <= 100);
    __CPROVER_assume(pub_r000967_9 >= -100 && pub_r000967_9 <= 100);
    __CPROVER_assume(pub_r000967_10 >= -100 && pub_r000967_10 <= 100);
    __CPROVER_assume(pub_r000967_11 >= -100 && pub_r000967_11 <= 100);
    __CPROVER_assume(pub_r000967_12 >= -100 && pub_r000967_12 <= 100);
    __CPROVER_assume(pub_r000967_13 >= -100 && pub_r000967_13 <= 100);
    __CPROVER_assume(pub_r000967_14 >= -100 && pub_r000967_14 <= 100);
    __CPROVER_assume(pub_r000967_15 >= -100 && pub_r000967_15 <= 100);
    __CPROVER_assume(sec_r000967_0 >= 0 && sec_r000967_0 <= 255);
    __CPROVER_assume(sec_r000967_1 >= 0 && sec_r000967_1 <= 255);
    __CPROVER_assume(sec_r000967_2 >= 0 && sec_r000967_2 <= 255);
    __CPROVER_assume(sec_r000967_3 >= 0 && sec_r000967_3 <= 255);
    __CPROVER_assume(sec_r000967_4 >= 0 && sec_r000967_4 <= 255);
    __CPROVER_assume(sec_r000967_5 >= 0 && sec_r000967_5 <= 255);
    __CPROVER_assume(sec_r000967_6 >= 0 && sec_r000967_6 <= 255);
    __CPROVER_assume(sec_r000967_7 >= 0 && sec_r000967_7 <= 255);
    __CPROVER_assume(sec_r000967_8 >= 0 && sec_r000967_8 <= 255);
    __CPROVER_assume(sec_r000967_9 >= 0 && sec_r000967_9 <= 255);
    __CPROVER_assume(sec_r000967_10 >= 0 && sec_r000967_10 <= 255);
    __CPROVER_assume(sec_r000967_11 >= 0 && sec_r000967_11 <= 255);
    __CPROVER_assume(sec_r000967_12 >= 0 && sec_r000967_12 <= 255);
    __CPROVER_assume(sec_r000967_13 >= 0 && sec_r000967_13 <= 255);
    __CPROVER_assume(sec_r000967_14 >= 0 && sec_r000967_14 <= 255);
    __CPROVER_assume(sec_r000967_15 >= 0 && sec_r000967_15 <= 255);
    __CPROVER_assume(sec_r000967_16 >= 0 && sec_r000967_16 <= 255);
    __CPROVER_assume(sec_r000967_17 >= 0 && sec_r000967_17 <= 255);
    __CPROVER_assume(sec_r000967_18 >= 0 && sec_r000967_18 <= 255);
    __CPROVER_assume(sec_r000967_19 >= 0 && sec_r000967_19 <= 255);
    __CPROVER_assume(sec_r000967_20 >= 0 && sec_r000967_20 <= 255);
    __CPROVER_assume(sec_r000967_21 >= 0 && sec_r000967_21 <= 255);

    struct EventLog_R000967_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000967_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000967_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000967_0 + 7) & 15;
    struct Transaction_R000967_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000967_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000967_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000967_0 + 9) & 15;
    struct StreamBuffer_R000967_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000967_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000967_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000967_0 + 11) & 15;
    struct MatrixBlock_R000967_6713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000967_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000967_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000967_0 + 13) & 15;

    union TelemetryField_R000967_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 35) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 50) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 17) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 32) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 24) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 39) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 32) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 47) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 37) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 10) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 25) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 37) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 52) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 31) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 46) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 21) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 36) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

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
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 33) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 48) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 28) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 43) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 28) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 43) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 35) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 50) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000967_20 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_56 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000967_7 & 2) != 0) {
            stage_v_57 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000967_19 & 2) != 0) {
            stage_v_58 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000967_8 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_59 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000967_21 & 2) != 0) {
            stage_v_60 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000967_2 & 1) != 0) {
        if ((sec_r000967_1 & 2) != 0) {
            stage_v_61 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000967_16 & 2) != 0) {
            stage_v_62 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000967_7 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_63 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_64 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_19 & 2) != 0) {
            stage_v_65 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_66 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_67 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_68 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000967_6 & 2) != 0) {
            stage_v_69 = (pub_r000967_8 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000967_8 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000967_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_70 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000967_13 & 1) != 0) {
        if ((sec_r000967_9 & 2) != 0) {
            stage_v_71 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000967_15 & 2) != 0) {
            stage_v_72 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000967_16 & 1) != 0) {
        if ((sec_r000967_0 & 2) != 0) {
            stage_v_73 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000967_6 & 1) != 0) {
        if ((sec_r000967_21 & 2) != 0) {
            stage_v_74 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000967_12 & 1) != 0) {
        if ((sec_r000967_6 & 2) != 0) {
            stage_v_75 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000967_21 & 2) != 0) {
            stage_v_76 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_77 = (pub_r000967_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000967_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000967_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000967_4 & 2) != 0) {
            stage_v_78 = (pub_r000967_7 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000967_7 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000967_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_79 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000967_19 & 2) != 0) {
            stage_v_80 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000967_0 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_81 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000967_9 & 1) != 0) {
        if ((sec_r000967_16 & 2) != 0) {
            stage_v_82 = (pub_r000967_15 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000967_15 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000967_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000967_2 & 1) != 0) {
        if ((sec_r000967_12 & 2) != 0) {
            stage_v_83 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_1 & 2) != 0) {
            stage_v_84 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000967_5 & 1) != 0) {
        if ((sec_r000967_7 & 2) != 0) {
            stage_v_85 = (pub_r000967_7 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000967_7 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000967_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000967_19 & 1) != 0) {
        if ((sec_r000967_18 & 2) != 0) {
            stage_v_86 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_87 = (pub_r000967_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000967_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000967_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_88 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000967_7 & 1) != 0) {
        if ((sec_r000967_2 & 2) != 0) {
            stage_v_89 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_90 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000967_14 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_91 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000967_13 & 1) != 0) {
        if ((sec_r000967_16 & 2) != 0) {
            stage_v_92 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000967_20 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_93 = (pub_r000967_4 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000967_4 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000967_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000967_9 & 2) != 0) {
            stage_v_94 = (pub_r000967_0 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000967_0 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000967_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000967_21 & 1) != 0) {
        if ((sec_r000967_16 & 2) != 0) {
            stage_v_95 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000967_9 & 2) != 0) {
            stage_v_96 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000967_15 & 2) != 0) {
            stage_v_97 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_98 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_99 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000967_1 & 2) != 0) {
            stage_v_100 = (pub_r000967_14 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000967_14 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000967_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000967_12 & 2) != 0) {
            stage_v_101 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_102 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000967_12 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_103 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000967_21 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_104 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_105 = (pub_r000967_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000967_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000967_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000967_19 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_106 = (pub_r000967_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000967_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000967_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000967_21 & 2) != 0) {
            stage_v_107 = (pub_r000967_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000967_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000967_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_108 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_109 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_110 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_111 = (pub_r000967_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000967_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000967_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000967_0 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_112 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000967_19 & 1) != 0) {
        if ((sec_r000967_2 & 2) != 0) {
            stage_v_113 = (pub_r000967_8 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000967_8 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000967_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_114 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_115 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_116 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_117 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_118 = (pub_r000967_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000967_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000967_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000967_17 & 1) != 0) {
        if ((sec_r000967_4 & 2) != 0) {
            stage_v_119 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000967_2 & 2) != 0) {
            stage_v_120 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000967_8 & 1) != 0) {
        if ((sec_r000967_6 & 2) != 0) {
            stage_v_121 = (pub_r000967_15 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000967_15 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000967_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_122 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000967_19 & 2) != 0) {
            stage_v_123 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000967_17 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_124 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000967_2 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_125 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000967_15 & 1) != 0) {
        if ((sec_r000967_12 & 2) != 0) {
            stage_v_126 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000967_18 & 2) != 0) {
            stage_v_127 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000967_11 & 2) != 0) {
            stage_v_128 = (pub_r000967_12 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000967_12 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000967_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000967_18 & 2) != 0) {
            stage_v_129 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000967_17 & 1) != 0) {
        if ((sec_r000967_6 & 2) != 0) {
            stage_v_130 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000967_9 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_131 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000967_17 & 1) != 0) {
        if ((sec_r000967_2 & 2) != 0) {
            stage_v_132 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000967_10 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_133 = (pub_r000967_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000967_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000967_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000967_15 & 2) != 0) {
            stage_v_134 = (pub_r000967_8 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000967_8 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000967_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000967_13 & 1) != 0) {
        if ((sec_r000967_9 & 2) != 0) {
            stage_v_135 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_136 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_137 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000967_13 & 2) != 0) {
            stage_v_138 = (pub_r000967_14 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000967_14 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000967_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_139 = (pub_r000967_15 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000967_15 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000967_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_140 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000967_2 & 2) != 0) {
            stage_v_141 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000967_8 & 2) != 0) {
            stage_v_142 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000967_1 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_143 = (pub_r000967_10 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000967_10 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000967_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000967_0 & 1) != 0) {
        if ((sec_r000967_1 & 2) != 0) {
            stage_v_144 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000967_0 & 2) != 0) {
            stage_v_145 = (pub_r000967_3 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000967_3 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000967_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000967_17 & 2) != 0) {
            stage_v_146 = (pub_r000967_4 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000967_4 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000967_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_147 = (pub_r000967_8 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000967_8 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000967_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000967_21 & 1) != 0) {
        if ((sec_r000967_10 & 2) != 0) {
            stage_v_148 = (pub_r000967_2 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000967_2 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000967_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000967_20 & 2) != 0) {
            stage_v_149 = (pub_r000967_11 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000967_11 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000967_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000967_16 & 2) != 0) {
            stage_v_150 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000967_3 & 2) != 0) {
            stage_v_151 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000967_8 & 2) != 0) {
            stage_v_152 = (pub_r000967_6 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000967_6 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000967_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000967_19 & 2) != 0) {
            stage_v_153 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000967_18 & 1) != 0) {
        if ((sec_r000967_1 & 2) != 0) {
            stage_v_154 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000967_20 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_155 = (pub_r000967_9 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000967_9 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000967_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000967_21 & 1) != 0) {
        if ((sec_r000967_5 & 2) != 0) {
            stage_v_156 = (pub_r000967_5 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000967_5 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000967_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000967_14 & 2) != 0) {
            stage_v_157 = (pub_r000967_15 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000967_15 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000967_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000967_0 & 2) != 0) {
            stage_v_158 = (pub_r000967_13 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000967_13 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000967_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
