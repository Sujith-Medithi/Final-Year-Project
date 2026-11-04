/*
 * Benchmark Program: R000711
 * Family: secret_dependent_loops
 * Generator Seed: 471113
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000711_1113_0 {
    short status;
    int reading;
    int threshold;
    int buffer[3];
};

struct StreamBuffer_R000711_1113_1 {
    short capacity;
    unsigned char head;
    int checksum;
    int watermark;
    unsigned char state;
    int tail;
    int buffer[3];
};

union ColorPixel_R000711_1113_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000711_1113_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000711_1113_0(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_74 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_74 > 39) {
        acc = (acc + bound_74 * 2 + 5) & 127;
        aux ^= (bound_74 & 15);
    } else {
        acc = (acc - bound_74 + 11) & 127;
        aux += 3;
    }
    int phase_77 = (aux + st.buffer[1]) & 3;
    switch (phase_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_88 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_88 = (pivot_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000711_1113_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_50 = 0;
    for (int k = 0; k < 2; k++) {
        mask_50 = (mask_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_50) & 127;
    }
    int window_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000711_1113_2(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int threshold_90 = (aux + st.buffer[1]) & 3;
    switch (threshold_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_74 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_74 > 43) {
        acc = (acc + scale_74 * 2 + 5) & 127;
        aux ^= (scale_74 & 15);
    } else {
        acc = (acc - scale_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_3(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_71) & 63;
    acc ^= aux;
    int segment_49 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_49 > 46) {
        acc = (acc + segment_49 * 2 + 5) & 127;
        aux ^= (segment_49 & 15);
    } else {
        acc = (acc - segment_49 + 11) & 127;
        aux += 3;
    }
    int phase_36 = (aux + st.buffer[1]) & 3;
    switch (phase_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int tracker_77 = local_arr[aux % 3];
    acc = (acc + tracker_77 * 2) & 127;
    int phase_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_44 = (aux + st.buffer[1]) & 3;
    switch (index_reg_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_5(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_72 = (aux + st.buffer[1]) & 3;
    switch (mask_72) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_81 = 0;
    for (int k = 0; k < 3; k++) {
        weight_81 = (weight_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_81) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int parity_53 = (aux + st.buffer[1]) & 3;
    switch (parity_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_40 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_40 > 21) {
        acc = (acc + damping_40 * 2 + 5) & 127;
        aux ^= (damping_40 & 15);
    } else {
        acc = (acc - damping_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_20) & 63;
    acc ^= aux;
    int vector_41 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_41 > 15) {
        acc = (acc + vector_41 * 2 + 5) & 127;
        aux ^= (vector_41 & 15);
    } else {
        acc = (acc - vector_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_10 = local_arr[aux % 3];
    acc = (acc + quotient_10 * 2) & 127;
    int sample_48 = 0;
    for (int k = 0; k < 3; k++) {
        sample_48 = (sample_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_8(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_66 = 0;
    for (int k = 0; k < 2; k++) {
        window_66 = (window_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_66) & 127;
    }
    int bound_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_11) & 63;
    acc ^= aux;
    int margin_97 = (aux + st.buffer[1]) & 3;
    switch (margin_97) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_9(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int pivot_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_20 = local_arr[aux % 3];
    acc = (acc + tracker_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_13 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_13 > 12) {
        acc = (acc + tracker_13 * 2 + 5) & 127;
        aux ^= (tracker_13 & 15);
    } else {
        acc = (acc - tracker_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int metric_98 = local_arr[aux % 3];
    acc = (acc + metric_98 * 2) & 127;
    int damping_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_70 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_70 > 22) {
        acc = (acc + delta_70 * 2 + 5) & 127;
        aux ^= (delta_70 & 15);
    } else {
        acc = (acc - delta_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000711_1113_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000711_1113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_68 = (aux + st.buffer[1]) & 3;
    switch (quotient_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000711_1113_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int delta_90 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_90 > 24) {
        acc = (acc + delta_90 * 2 + 5) & 127;
        aux ^= (delta_90 & 15);
    } else {
        acc = (acc - delta_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000711_1113_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_97 = (aux + st.buffer[1]) & 3;
    switch (anchor_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_72) & 63;
    acc ^= aux;
    int mask_35 = 0;
    for (int k = 0; k < 3; k++) {
        mask_35 = (mask_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_35) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_11 = local_arr[aux % 3];
    acc = (acc + sample_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000711_1113_14(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000711_1113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_17) & 63;
    acc ^= aux;
    int cursor_23 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_23 = (cursor_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_23) & 127;
    }
    int delta_12 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_12 > 32) {
        acc = (acc + delta_12 * 2 + 5) & 127;
        aux ^= (delta_12 & 15);
    } else {
        acc = (acc - delta_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000711_0;
    int sec_r000711_1;
    int sec_r000711_2;
    int sec_r000711_3;
    int sec_r000711_4;
    int sec_r000711_5;
    int sec_r000711_6;
    int sec_r000711_7;
    int sec_r000711_8;
    int sec_r000711_9;
    int sec_r000711_10;
    int sec_r000711_11;
    int sec_r000711_12;
    int sec_r000711_13;
    int sec_r000711_14;
    int sec_r000711_15;
    int pub_r000711_0;
    int pub_r000711_1;
    int pub_r000711_2;
    int pub_r000711_3;
    int pub_r000711_4;
    int pub_r000711_5;
    int pub_r000711_6;
    int pub_r000711_7;
    int pub_r000711_8;
    int pub_r000711_9;
    int pub_r000711_10;
    int pub_r000711_11;
    int pub_r000711_12;
    int pub_r000711_13;
    int pub_r000711_14;
    int pub_r000711_15;
    int pub_r000711_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000711_0 >= -100 && pub_r000711_0 <= 100);
    __CPROVER_assume(pub_r000711_1 >= -100 && pub_r000711_1 <= 100);
    __CPROVER_assume(pub_r000711_2 >= -100 && pub_r000711_2 <= 100);
    __CPROVER_assume(pub_r000711_3 >= -100 && pub_r000711_3 <= 100);
    __CPROVER_assume(pub_r000711_4 >= -100 && pub_r000711_4 <= 100);
    __CPROVER_assume(pub_r000711_5 >= -100 && pub_r000711_5 <= 100);
    __CPROVER_assume(pub_r000711_6 >= -100 && pub_r000711_6 <= 100);
    __CPROVER_assume(pub_r000711_7 >= -100 && pub_r000711_7 <= 100);
    __CPROVER_assume(pub_r000711_8 >= -100 && pub_r000711_8 <= 100);
    __CPROVER_assume(pub_r000711_9 >= -100 && pub_r000711_9 <= 100);
    __CPROVER_assume(pub_r000711_10 >= -100 && pub_r000711_10 <= 100);
    __CPROVER_assume(pub_r000711_11 >= -100 && pub_r000711_11 <= 100);
    __CPROVER_assume(pub_r000711_12 >= -100 && pub_r000711_12 <= 100);
    __CPROVER_assume(pub_r000711_13 >= -100 && pub_r000711_13 <= 100);
    __CPROVER_assume(pub_r000711_14 >= -100 && pub_r000711_14 <= 100);
    __CPROVER_assume(pub_r000711_15 >= -100 && pub_r000711_15 <= 100);
    __CPROVER_assume(pub_r000711_16 >= -100 && pub_r000711_16 <= 100);
    __CPROVER_assume(sec_r000711_0 >= 0 && sec_r000711_0 <= 255);
    __CPROVER_assume(sec_r000711_1 >= 0 && sec_r000711_1 <= 255);
    __CPROVER_assume(sec_r000711_2 >= 0 && sec_r000711_2 <= 255);
    __CPROVER_assume(sec_r000711_3 >= 0 && sec_r000711_3 <= 255);
    __CPROVER_assume(sec_r000711_4 >= 0 && sec_r000711_4 <= 255);
    __CPROVER_assume(sec_r000711_5 >= 0 && sec_r000711_5 <= 255);
    __CPROVER_assume(sec_r000711_6 >= 0 && sec_r000711_6 <= 255);
    __CPROVER_assume(sec_r000711_7 >= 0 && sec_r000711_7 <= 255);
    __CPROVER_assume(sec_r000711_8 >= 0 && sec_r000711_8 <= 255);
    __CPROVER_assume(sec_r000711_9 >= 0 && sec_r000711_9 <= 255);
    __CPROVER_assume(sec_r000711_10 >= 0 && sec_r000711_10 <= 255);
    __CPROVER_assume(sec_r000711_11 >= 0 && sec_r000711_11 <= 255);
    __CPROVER_assume(sec_r000711_12 >= 0 && sec_r000711_12 <= 255);
    __CPROVER_assume(sec_r000711_13 >= 0 && sec_r000711_13 <= 255);
    __CPROVER_assume(sec_r000711_14 >= 0 && sec_r000711_14 <= 255);
    __CPROVER_assume(sec_r000711_15 >= 0 && sec_r000711_15 <= 255);

    struct SensorNode_R000711_1113_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000711_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000711_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000711_0 + 7) & 15;
    struct StreamBuffer_R000711_1113_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000711_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000711_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000711_0 + 9) & 15;

    union ColorPixel_R000711_1113_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 16) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 31) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
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
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 37) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 52) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 53) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 40) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 55) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
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
    int stage_v_51 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 36) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 51) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 35) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 50) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 18) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 33) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = table[2];
    table[2] = (table[3] + 157) & 63;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 22) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 37) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 31) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 46) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = table[0];
    table[0] = (table[1] + 193) & 63;
    out_sink = (out_sink + stage_v_96) & 255;

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
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_108 = (stage_v_108 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 16) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 31) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] * 2 + 358) & 63;
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
    int stage_v_118 = (st_var_0.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 18) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 33) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = table[0];
    table[0] = (table[1] + 241) & 63;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_122 = (stage_v_122 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 39) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 54) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 127) & 15;
    int stage_v_126 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= stage_v_126;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 26) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 41) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 130) & 15;
    int stage_v_129 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= stage_v_129;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_1.buffer[0] ^ 134) & 3;
    switch (stage_v_131) {
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

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] ^ 135) & 3;
    switch (stage_v_132) {
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

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 20) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 35) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_136 = (stage_v_136 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] * 2 + 421) & 63;
    if (stage_v_138 > 22) {
        out_sink = (out_sink + stage_v_138 - 5) & 255;
        if (stage_v_138 > 37) {
            chk_sum ^= (stage_v_138 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_138 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_0.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 14) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 29) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[1] * 2 + 460) & 63;
    if (stage_v_151 > 14) {
        out_sink = (out_sink + stage_v_151 - 5) & 255;
        if (stage_v_151 > 29) {
            chk_sum ^= (stage_v_151 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_151 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_152 = (stage_v_152 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 30) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 45) {
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
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_0.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 14) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 29) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_1.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_165 = (stage_v_165 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_0.buffer[0] ^ 169) & 3;
    switch (stage_v_166) {
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

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_0.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
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

    /* Execution Pipeline Stage 171 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_0.buffer[0] ^ 175) & 3;
    switch (stage_v_172) {
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

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_0.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 20) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 35) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 52) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_180 = (stage_v_180 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_180) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_0.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Execution Pipeline Stage 183 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 184) & 15;
    int stage_v_183 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= stage_v_183;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (out_sink > 100) ? (chk_sum & 31) : (190 & 31);
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= (stage_v_185 << 1) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = table[3];
    table[3] = (table[0] + 375) & 63;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 189) & 15;
    int stage_v_188 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    chk_sum ^= stage_v_188;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_1.buffer[0] * 2 + 574) & 63;
    if (stage_v_189 > 36) {
        out_sink = (out_sink + stage_v_189 - 5) & 255;
        if (stage_v_189 > 51) {
            chk_sum ^= (stage_v_189 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_189 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_192 = (stage_v_192 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_192) & 127;
    }
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = table[1];
    table[1] = (table[2] + 387) & 63;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 195) & 15;
    int stage_v_194 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    chk_sum ^= stage_v_194;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Security Information Flow: Family = secret_dependent_loops */
    int l_bound_0 = (sec_r000711_6 & 1) + 1;
    for (int it = 0; it < l_bound_0; it++) {
        out_sink += (it * 3 + 6);
    }
    int l_bound_1 = (sec_r000711_0 & 1) + 1;
    for (int it = 0; it < l_bound_1; it++) {
        out_sink += (it * 3 + 5);
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
