/*
 * Benchmark Program: R001250
 * Security Family: mixed_control_data
 * Generator Seed: 625013
 * High Inputs: 17 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001250_5013_0 {
    int timestamp;
    int code;
    unsigned char seq;
    unsigned char facility;
    int severity;
    short signature;
    int buffer[3];
};

struct MatrixBlock_R001250_5013_1 {
    short scale;
    int density;
    short trace;
    int stride;
    short dim;
    int determinant;
    int buffer[3];
};

union PacketPayload_R001250_5013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001250_5013_0(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tracker_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_41) & 63;
    acc ^= aux;
    int metric_15 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_15 > 12) {
        acc = (acc + metric_15 * 2 + 5) & 127;
        aux ^= (metric_15 & 15);
    } else {
        acc = (acc - metric_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_1(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_20 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_20 = (cursor_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_20) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_96 = local_arr[aux % 3];
    acc = (acc + metric_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001250_5013_2(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int margin_61 = 0;
    for (int k = 0; k < 3; k++) {
        margin_61 = (margin_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_61) & 127;
    }
    int sample_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_31) & 63;
    acc ^= aux;
    int residue_19 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_19 > 43) {
        acc = (acc + residue_19 * 2 + 5) & 127;
        aux ^= (residue_19 & 15);
    } else {
        acc = (acc - residue_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_3(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_89 = (aux + st.buffer[1]) & 3;
    switch (tracker_89) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_11 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_11 > 17) {
        acc = (acc + parity_11 * 2 + 5) & 127;
        aux ^= (parity_11 & 15);
    } else {
        acc = (acc - parity_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_4(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_94 = 0;
    for (int k = 0; k < 2; k++) {
        tally_94 = (tally_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_94) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_78 = local_arr[aux % 3];
    acc = (acc + metric_78 * 2) & 127;
    int bound_46 = (aux + st.buffer[1]) & 3;
    switch (bound_46) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_5(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_17) & 63;
    acc ^= aux;
    int factor_58 = 0;
    for (int k = 0; k < 2; k++) {
        factor_58 = (factor_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_6(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_31 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_31 > 25) {
        acc = (acc + checksum_31 * 2 + 5) & 127;
        aux ^= (checksum_31 & 15);
    } else {
        acc = (acc - checksum_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_44 = local_arr[aux % 3];
    acc = (acc + stride_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001250_5013_7(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_84) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_56 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_56 > 46) {
        acc = (acc + residue_56 * 2 + 5) & 127;
        aux ^= (residue_56 & 15);
    } else {
        acc = (acc - residue_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quantum_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_97) & 63;
    acc ^= aux;
    int residue_45 = 0;
    for (int k = 0; k < 3; k++) {
        residue_45 = (residue_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_45) & 127;
    }
    int parity_77 = (aux + st.buffer[1]) & 3;
    switch (parity_77) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_16 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_16 > 20) {
        acc = (acc + sample_16 * 2 + 5) & 127;
        aux ^= (sample_16 & 15);
    } else {
        acc = (acc - sample_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_65 = local_arr[aux % 3];
    acc = (acc + cursor_65 * 2) & 127;
    int accumulator_87 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_87 > 35) {
        acc = (acc + accumulator_87 * 2 + 5) & 127;
        aux ^= (accumulator_87 & 15);
    } else {
        acc = (acc - accumulator_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int factor_62 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_62 > 32) {
        acc = (acc + factor_62 * 2 + 5) & 127;
        aux ^= (factor_62 & 15);
    } else {
        acc = (acc - factor_62 + 11) & 127;
        aux += 3;
    }
    int margin_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_41 = local_arr[aux % 3];
    acc = (acc + checksum_41 * 2) & 127;
    int vector_57 = (aux + st.buffer[1]) & 3;
    switch (vector_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_11(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int accumulator_83 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_83 = (accumulator_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001250_5013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_59 = (aux + st.buffer[1]) & 3;
    switch (pivot_59) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_43 = local_arr[aux % 3];
    acc = (acc + accumulator_43 * 2) & 127;
    int tally_48 = 0;
    for (int k = 0; k < 3; k++) {
        tally_48 = (tally_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_13(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int scale_35 = local_arr[aux % 3];
    acc = (acc + scale_35 * 2) & 127;
    int delta_97 = 0;
    for (int k = 0; k < 2; k++) {
        delta_97 = (delta_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_97) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001250_5013_14(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001250_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int parity_68 = local_arr[aux % 3];
    acc = (acc + parity_68 * 2) & 127;
    int cursor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_31) & 63;
    acc ^= aux;
    int segment_52 = 0;
    for (int k = 0; k < 2; k++) {
        segment_52 = (segment_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_52) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001250_5013_15(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001250_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_22 = (aux + st.buffer[1]) & 3;
    switch (segment_22) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_86 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_86 > 32) {
        acc = (acc + stride_86 * 2 + 5) & 127;
        aux ^= (stride_86 & 15);
    } else {
        acc = (acc - stride_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001250_0;
    int sec_r001250_1;
    int sec_r001250_2;
    int sec_r001250_3;
    int sec_r001250_4;
    int sec_r001250_5;
    int sec_r001250_6;
    int sec_r001250_7;
    int sec_r001250_8;
    int sec_r001250_9;
    int sec_r001250_10;
    int sec_r001250_11;
    int sec_r001250_12;
    int sec_r001250_13;
    int sec_r001250_14;
    int sec_r001250_15;
    int sec_r001250_16;
    int pub_r001250_0;
    int pub_r001250_1;
    int pub_r001250_2;
    int pub_r001250_3;
    int pub_r001250_4;
    int pub_r001250_5;
    int pub_r001250_6;
    int pub_r001250_7;
    int pub_r001250_8;
    int pub_r001250_9;
    int pub_r001250_10;
    int pub_r001250_11;
    int pub_r001250_12;
    int pub_r001250_13;
    int pub_r001250_14;
    int pub_r001250_15;
    int pub_r001250_16;
    int pub_r001250_17;
    int pub_r001250_18;
    int pub_r001250_19;
    int pub_r001250_20;
    int pub_r001250_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001250_0 >= -100 && pub_r001250_0 <= 100);
    __CPROVER_assume(pub_r001250_1 >= -100 && pub_r001250_1 <= 100);
    __CPROVER_assume(pub_r001250_2 >= -100 && pub_r001250_2 <= 100);
    __CPROVER_assume(pub_r001250_3 >= -100 && pub_r001250_3 <= 100);
    __CPROVER_assume(pub_r001250_4 >= -100 && pub_r001250_4 <= 100);
    __CPROVER_assume(pub_r001250_5 >= -100 && pub_r001250_5 <= 100);
    __CPROVER_assume(pub_r001250_6 >= -100 && pub_r001250_6 <= 100);
    __CPROVER_assume(pub_r001250_7 >= -100 && pub_r001250_7 <= 100);
    __CPROVER_assume(pub_r001250_8 >= -100 && pub_r001250_8 <= 100);
    __CPROVER_assume(pub_r001250_9 >= -100 && pub_r001250_9 <= 100);
    __CPROVER_assume(pub_r001250_10 >= -100 && pub_r001250_10 <= 100);
    __CPROVER_assume(pub_r001250_11 >= -100 && pub_r001250_11 <= 100);
    __CPROVER_assume(pub_r001250_12 >= -100 && pub_r001250_12 <= 100);
    __CPROVER_assume(pub_r001250_13 >= -100 && pub_r001250_13 <= 100);
    __CPROVER_assume(pub_r001250_14 >= -100 && pub_r001250_14 <= 100);
    __CPROVER_assume(pub_r001250_15 >= -100 && pub_r001250_15 <= 100);
    __CPROVER_assume(pub_r001250_16 >= -100 && pub_r001250_16 <= 100);
    __CPROVER_assume(pub_r001250_17 >= -100 && pub_r001250_17 <= 100);
    __CPROVER_assume(pub_r001250_18 >= -100 && pub_r001250_18 <= 100);
    __CPROVER_assume(pub_r001250_19 >= -100 && pub_r001250_19 <= 100);
    __CPROVER_assume(pub_r001250_20 >= -100 && pub_r001250_20 <= 100);
    __CPROVER_assume(pub_r001250_21 >= -100 && pub_r001250_21 <= 100);
    __CPROVER_assume(sec_r001250_0 >= 0 && sec_r001250_0 <= 255);
    __CPROVER_assume(sec_r001250_1 >= 0 && sec_r001250_1 <= 255);
    __CPROVER_assume(sec_r001250_2 >= 0 && sec_r001250_2 <= 255);
    __CPROVER_assume(sec_r001250_3 >= 0 && sec_r001250_3 <= 255);
    __CPROVER_assume(sec_r001250_4 >= 0 && sec_r001250_4 <= 255);
    __CPROVER_assume(sec_r001250_5 >= 0 && sec_r001250_5 <= 255);
    __CPROVER_assume(sec_r001250_6 >= 0 && sec_r001250_6 <= 255);
    __CPROVER_assume(sec_r001250_7 >= 0 && sec_r001250_7 <= 255);
    __CPROVER_assume(sec_r001250_8 >= 0 && sec_r001250_8 <= 255);
    __CPROVER_assume(sec_r001250_9 >= 0 && sec_r001250_9 <= 255);
    __CPROVER_assume(sec_r001250_10 >= 0 && sec_r001250_10 <= 255);
    __CPROVER_assume(sec_r001250_11 >= 0 && sec_r001250_11 <= 255);
    __CPROVER_assume(sec_r001250_12 >= 0 && sec_r001250_12 <= 255);
    __CPROVER_assume(sec_r001250_13 >= 0 && sec_r001250_13 <= 255);
    __CPROVER_assume(sec_r001250_14 >= 0 && sec_r001250_14 <= 255);
    __CPROVER_assume(sec_r001250_15 >= 0 && sec_r001250_15 <= 255);
    __CPROVER_assume(sec_r001250_16 >= 0 && sec_r001250_16 <= 255);

    struct EventLog_R001250_5013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001250_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001250_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001250_0 + 7) & 15;
    struct MatrixBlock_R001250_5013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001250_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001250_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001250_0 + 9) & 15;

    union PacketPayload_R001250_5013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001250_5013_0(sec_r001250_0, pub_r001250_1, pub_r001250_2);
    int helper_flow_1 = fn_R001250_5013_1(sec_r001250_1, sec_r001250_2, pub_r001250_3);
    int helper_flow_2 = fn_R001250_5013_2(sec_r001250_2, pub_r001250_3, pub_r001250_4);
    int helper_flow_3 = fn_R001250_5013_3(sec_r001250_3, pub_r001250_4, pub_r001250_5);
    int helper_flow_4 = fn_R001250_5013_4(sec_r001250_4, sec_r001250_5, pub_r001250_6);
    int helper_flow_5 = fn_R001250_5013_5(sec_r001250_5, pub_r001250_6);
    int helper_flow_6 = fn_R001250_5013_6(sec_r001250_6, pub_r001250_7, pub_r001250_8);
    int helper_flow_7 = fn_R001250_5013_7(sec_r001250_7, sec_r001250_8, pub_r001250_9);
    int helper_flow_8 = fn_R001250_5013_8(sec_r001250_8, pub_r001250_9, pub_r001250_10, pub_r001250_11);
    int helper_flow_9 = fn_R001250_5013_9(sec_r001250_9, pub_r001250_10, pub_r001250_11, pub_r001250_12, pub_r001250_13);
    int helper_flow_10 = fn_R001250_5013_10(sec_r001250_10, sec_r001250_11, pub_r001250_12, pub_r001250_13);
    int helper_flow_11 = fn_R001250_5013_11(sec_r001250_11, pub_r001250_12, pub_r001250_13);
    int helper_flow_12 = fn_R001250_5013_12(sec_r001250_12, sec_r001250_13, pub_r001250_14, pub_r001250_15, pub_r001250_16);
    int helper_flow_13 = fn_R001250_5013_13(sec_r001250_13, pub_r001250_14, pub_r001250_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_0 > 23) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001250_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001250_6 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_2 > 37) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001250_2 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_3 > 40) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_4 > 27) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_5 > 32) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_6 > 43) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001250_12) & 127;
    if (stage_v_7 > 24) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001250_1 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_8 > 25) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001250_15 ^ 0x2A) * 2 + pub_r001250_16) & 127;
    if (stage_v_9 > 43) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_10 > 26) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001250_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001250_2 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_12 > 49) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_13 > 28) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_14 > 26) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001250_5 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_15 > 22) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_16 > 26) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001250_12 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_17 > 36) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001250_20) & 127;
    if (stage_v_18 > 45) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_19 > 36) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001250_0 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_20 > 50) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001250_10 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_21 > 40) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_22 > 31) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001250_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001250_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001250_6 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_25 > 21) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_26 > 44) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_27 > 27) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001250_7 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_28 > 47) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001250_13) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001250_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_31 > 43) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001250_14 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_32 > 50) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_33 > 33) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_34 > 22) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001250_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_37 > 21) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_38 > 43) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001250_9 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_39 > 41) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_40 > 30) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001250_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_42 > 43) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001250_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_44 > 28) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_45 > 45) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_46 > 42) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001250_7 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_47 > 26) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001250_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001250_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001250_4) & 127;
    if (stage_v_50 > 36) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_51 > 35) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_52 > 26) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_53 > 26) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001250_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_55 > 33) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_56 > 48) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_57 > 20) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001250_21 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_59 > 27) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001250_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001250_16 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_61 > 24) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001250_4) & 127;
    if (stage_v_62 > 42) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001250_3 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_63 > 45) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001250_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001250_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_66 > 50) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_67 > 21) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001250_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001250_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001250_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001250_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_73 > 32) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001250_13) & 127;
    if (stage_v_74 > 40) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001250_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_77 > 30) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001250_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_79 > 36) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_80 > 22) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_81 > 32) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_82 > 22) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001250_14 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_83 > 41) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001250_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001250_13 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_85 > 27) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001250_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_87 > 36) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001250_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_89 > 25) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001250_6) & 127;
    if (stage_v_90 > 46) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_91 > 26) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_92 > 36) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_93 > 47) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001250_15 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_94 > 48) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001250_6 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_95 > 31) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_96 > 31) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_97 > 40) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001250_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001250_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_100 > 21) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_101 > 23) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_102 > 20) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_103 > 24) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_104 > 31) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001250_12) & 127;
    if (stage_v_105 > 43) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_106 > 27) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001250_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_108 > 22) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_109 > 48) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001250_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001250_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001250_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_113 > 29) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_114 > 21) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_115 > 39) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001250_11 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_116 > 46) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001250_15 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_117 > 37) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_118 > 26) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_119 > 35) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_120 > 27) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001250_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_122 > 50) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_123 > 31) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_124 > 20) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001250_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001250_9 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_126 > 31) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_127 > 33) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001250_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001250_12) & 127;
    if (stage_v_129 > 25) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001250_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_131 > 28) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001250_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001250_16) & 127;
    if (stage_v_133 > 48) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_134 > 32) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001250_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_136 > 42) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_137 > 44) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_138 > 46) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_139 > 25) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001250_6) & 127;
    if (stage_v_140 > 38) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_141 > 32) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_142 > 40) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_143 > 44) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_144 > 24) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001250_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_146 > 41) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_147 > 43) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_148 > 26) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_149 > 21) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_150 > 32) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001250_13 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_151 > 46) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_152 > 20) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_153 > 25) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_154 > 20) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001250_17) & 127;
    if (stage_v_155 > 41) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001250_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001250_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001250_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001250_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_160 > 31) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_162 > 50) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_163 > 38) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001250_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001250_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_166 > 20) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001250_12) & 127;
    if (stage_v_167 > 47) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001250_2) & 127;
    if (stage_v_168 > 28) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_169 > 44) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001250_4) & 127;
    if (stage_v_170 > 46) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001250_4) & 127;
    if (stage_v_171 > 29) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001250_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001250_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_174 > 49) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001250_6) & 127;
    if (stage_v_175 > 32) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_176 > 41) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001250_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001250_2 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_179 > 20) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_180 > 21) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001250_4 ^ 0x2A) * 2 + pub_r001250_10) & 127;
    if (stage_v_181 > 27) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001250_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001250_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_184 > 31) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_185 > 20) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001250_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_187 > 31) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_188 > 38) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_189 > 29) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001250_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_191 > 30) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001250_20) & 127;
    if (stage_v_192 > 42) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_193 > 44) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001250_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_195 > 33) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001250_21 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001250_9) & 127;
    if (stage_v_197 > 45) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_198 > 21) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_199 > 26) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001250_7) & 127;
    if (stage_v_200 > 21) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001250_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_171 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_202 > 36) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001250_1 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_204 > 39) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001250_1) & 127;
    if (stage_v_205 > 40) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001250_18) & 127;
    if (stage_v_206 > 45) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_207 > 20) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001250_13) & 127;
    if (stage_v_208 > 43) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r001250_5 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_209 > 41) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001250_15) & 127;
    if (stage_v_210 > 44) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001250_7 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_211 > 26) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_212 > 45) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001250_8) & 127;
    if (stage_v_213 > 44) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_195 ^ 0x2A) * 2 + pub_r001250_14) & 127;
    if (stage_v_214 > 47) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001250_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001250_6) & 127;
    if (stage_v_216 > 23) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001250_13) & 127;
    if (stage_v_217 > 25) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001250_10 ^ 0x2A) * 2 + pub_r001250_6) & 127;
    if (stage_v_218 > 41) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001250_19) & 127;
    if (stage_v_219 > 20) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001250_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001250_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001250_3) & 127;
    if (stage_v_222 > 39) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001250_5) & 127;
    if (stage_v_223 > 30) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_224 > 40) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001250_20) & 127;
    if (stage_v_225 > 38) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001250_0) & 127;
    if (stage_v_226 > 41) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001250_20) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001250_21) & 127;
    if (stage_v_228 > 29) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001250_11) & 127;
    if (stage_v_229 > 49) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001250_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
