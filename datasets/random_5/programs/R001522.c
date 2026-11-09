/*
 * Benchmark Program: R001522
 * Security Family: direct_leakage
 * Generator Seed: 652213
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001522_2213_0 {
    short offset;
    int gain;
    int status;
    int threshold;
    int reading;
    int calib;
    int buffer[3];
};

struct MatrixBlock_R001522_2213_1 {
    short trace;
    unsigned char density;
    int dim;
    int scale;
    short determinant;
    short stride;
    int buffer[3];
};

struct FilterState_R001522_2213_2 {
    short prev_in;
    int cutoff;
    unsigned char damping;
    int buffer[3];
};

union PacketPayload_R001522_2213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001522_2213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001522_2213_0(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001522_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int threshold_73 = local_arr[aux % 3];
    acc = (acc + threshold_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_33 = (aux + st.buffer[1]) & 3;
    switch (metric_33) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_52 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_52 = (threshold_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_1(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_96 = 0;
    for (int k = 0; k < 2; k++) {
        bound_96 = (bound_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_96) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_56 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_56 > 33) {
        acc = (acc + delta_56 * 2 + 5) & 127;
        aux ^= (delta_56 & 15);
    } else {
        acc = (acc - delta_56 + 11) & 127;
        aux += 3;
    }
    int tally_96 = (aux + st.buffer[1]) & 3;
    switch (tally_96) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_2(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001522_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_69 = local_arr[aux % 3];
    acc = (acc + tracker_69 * 2) & 127;
    int damping_11 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_11 > 25) {
        acc = (acc + damping_11 * 2 + 5) & 127;
        aux ^= (damping_11 & 15);
    } else {
        acc = (acc - damping_11 + 11) & 127;
        aux += 3;
    }
    int damping_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001522_2213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001522_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int quantum_38 = local_arr[aux % 3];
    acc = (acc + quantum_38 * 2) & 127;
    int quotient_41 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_41 = (quotient_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001522_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int offset_94 = local_arr[aux % 3];
    acc = (acc + offset_94 * 2) & 127;
    int segment_35 = 0;
    for (int k = 0; k < 2; k++) {
        segment_35 = (segment_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_35) & 127;
    }
    int delta_38 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_38 > 38) {
        acc = (acc + delta_38 * 2 + 5) & 127;
        aux ^= (delta_38 & 15);
    } else {
        acc = (acc - delta_38 + 11) & 127;
        aux += 3;
    }
    int margin_19 = (aux + st.buffer[1]) & 3;
    switch (margin_19) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_79 = 0;
    for (int k = 0; k < 3; k++) {
        segment_79 = (segment_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_79) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001522_2213_6(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_56 = (aux + st.buffer[1]) & 3;
    switch (scale_56) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_17 = local_arr[aux % 3];
    acc = (acc + mask_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001522_2213_7(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001522_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    int accumulator_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001522_2213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001522_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_39 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_39 > 43) {
        acc = (acc + tracker_39 * 2 + 5) & 127;
        aux ^= (tracker_39 & 15);
    } else {
        acc = (acc - tracker_39 + 11) & 127;
        aux += 3;
    }
    int mask_37 = (aux + st.buffer[1]) & 3;
    switch (mask_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_82 = local_arr[aux % 3];
    acc = (acc + tally_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001522_2213_9(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int phase_41 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_41 > 30) {
        acc = (acc + phase_41 * 2 + 5) & 127;
        aux ^= (phase_41 & 15);
    } else {
        acc = (acc - phase_41 + 11) & 127;
        aux += 3;
    }
    int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001522_2213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001522_2213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int residue_92 = local_arr[aux % 3];
    acc = (acc + residue_92 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001522_2213_11(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001522_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_96 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_96 > 29) {
        acc = (acc + margin_96 * 2 + 5) & 127;
        aux ^= (margin_96 & 15);
    } else {
        acc = (acc - margin_96 + 11) & 127;
        aux += 3;
    }
    int stride_55 = (aux + st.buffer[1]) & 3;
    switch (stride_55) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_67 = local_arr[aux % 3];
    acc = (acc + residue_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001522_2213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_75 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_75 > 48) {
        acc = (acc + pivot_75 * 2 + 5) & 127;
        aux ^= (pivot_75 & 15);
    } else {
        acc = (acc - pivot_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_33 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_33 > 18) {
        acc = (acc + quotient_33 * 2 + 5) & 127;
        aux ^= (quotient_33 & 15);
    } else {
        acc = (acc - quotient_33 + 11) & 127;
        aux += 3;
    }
    int factor_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_98) & 63;
    acc ^= aux;
    int metric_10 = (aux + st.buffer[1]) & 3;
    switch (metric_10) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_11 = 0;
    for (int k = 0; k < 3; k++) {
        mask_11 = (mask_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001522_2213_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001522_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_90 = (aux + st.buffer[1]) & 3;
    switch (cursor_90) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_80) & 63;
    acc ^= aux;
    int cursor_99 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_99 = (cursor_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_99) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001522_0;
    int sec_r001522_1;
    int sec_r001522_2;
    int sec_r001522_3;
    int sec_r001522_4;
    int sec_r001522_5;
    int sec_r001522_6;
    int sec_r001522_7;
    int sec_r001522_8;
    int sec_r001522_9;
    int sec_r001522_10;
    int sec_r001522_11;
    int sec_r001522_12;
    int sec_r001522_13;
    int sec_r001522_14;
    int sec_r001522_15;
    int sec_r001522_16;
    int sec_r001522_17;
    int sec_r001522_18;
    int pub_r001522_0;
    int pub_r001522_1;
    int pub_r001522_2;
    int pub_r001522_3;
    int pub_r001522_4;
    int pub_r001522_5;
    int pub_r001522_6;
    int pub_r001522_7;
    int pub_r001522_8;
    int pub_r001522_9;
    int pub_r001522_10;
    int pub_r001522_11;
    int pub_r001522_12;
    int pub_r001522_13;
    int pub_r001522_14;
    int pub_r001522_15;
    int pub_r001522_16;
    int pub_r001522_17;
    int pub_r001522_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001522_0 >= -100 && pub_r001522_0 <= 100);
    __CPROVER_assume(pub_r001522_1 >= -100 && pub_r001522_1 <= 100);
    __CPROVER_assume(pub_r001522_2 >= -100 && pub_r001522_2 <= 100);
    __CPROVER_assume(pub_r001522_3 >= -100 && pub_r001522_3 <= 100);
    __CPROVER_assume(pub_r001522_4 >= -100 && pub_r001522_4 <= 100);
    __CPROVER_assume(pub_r001522_5 >= -100 && pub_r001522_5 <= 100);
    __CPROVER_assume(pub_r001522_6 >= -100 && pub_r001522_6 <= 100);
    __CPROVER_assume(pub_r001522_7 >= -100 && pub_r001522_7 <= 100);
    __CPROVER_assume(pub_r001522_8 >= -100 && pub_r001522_8 <= 100);
    __CPROVER_assume(pub_r001522_9 >= -100 && pub_r001522_9 <= 100);
    __CPROVER_assume(pub_r001522_10 >= -100 && pub_r001522_10 <= 100);
    __CPROVER_assume(pub_r001522_11 >= -100 && pub_r001522_11 <= 100);
    __CPROVER_assume(pub_r001522_12 >= -100 && pub_r001522_12 <= 100);
    __CPROVER_assume(pub_r001522_13 >= -100 && pub_r001522_13 <= 100);
    __CPROVER_assume(pub_r001522_14 >= -100 && pub_r001522_14 <= 100);
    __CPROVER_assume(pub_r001522_15 >= -100 && pub_r001522_15 <= 100);
    __CPROVER_assume(pub_r001522_16 >= -100 && pub_r001522_16 <= 100);
    __CPROVER_assume(pub_r001522_17 >= -100 && pub_r001522_17 <= 100);
    __CPROVER_assume(pub_r001522_18 >= -100 && pub_r001522_18 <= 100);
    __CPROVER_assume(sec_r001522_0 >= 0 && sec_r001522_0 <= 255);
    __CPROVER_assume(sec_r001522_1 >= 0 && sec_r001522_1 <= 255);
    __CPROVER_assume(sec_r001522_2 >= 0 && sec_r001522_2 <= 255);
    __CPROVER_assume(sec_r001522_3 >= 0 && sec_r001522_3 <= 255);
    __CPROVER_assume(sec_r001522_4 >= 0 && sec_r001522_4 <= 255);
    __CPROVER_assume(sec_r001522_5 >= 0 && sec_r001522_5 <= 255);
    __CPROVER_assume(sec_r001522_6 >= 0 && sec_r001522_6 <= 255);
    __CPROVER_assume(sec_r001522_7 >= 0 && sec_r001522_7 <= 255);
    __CPROVER_assume(sec_r001522_8 >= 0 && sec_r001522_8 <= 255);
    __CPROVER_assume(sec_r001522_9 >= 0 && sec_r001522_9 <= 255);
    __CPROVER_assume(sec_r001522_10 >= 0 && sec_r001522_10 <= 255);
    __CPROVER_assume(sec_r001522_11 >= 0 && sec_r001522_11 <= 255);
    __CPROVER_assume(sec_r001522_12 >= 0 && sec_r001522_12 <= 255);
    __CPROVER_assume(sec_r001522_13 >= 0 && sec_r001522_13 <= 255);
    __CPROVER_assume(sec_r001522_14 >= 0 && sec_r001522_14 <= 255);
    __CPROVER_assume(sec_r001522_15 >= 0 && sec_r001522_15 <= 255);
    __CPROVER_assume(sec_r001522_16 >= 0 && sec_r001522_16 <= 255);
    __CPROVER_assume(sec_r001522_17 >= 0 && sec_r001522_17 <= 255);
    __CPROVER_assume(sec_r001522_18 >= 0 && sec_r001522_18 <= 255);

    struct SensorNode_R001522_2213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001522_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001522_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001522_0 + 7) & 15;
    struct MatrixBlock_R001522_2213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001522_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001522_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001522_0 + 9) & 15;
    struct FilterState_R001522_2213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001522_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001522_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001522_0 + 11) & 15;

    union PacketPayload_R001522_2213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001522_2213_0(sec_r001522_0, sec_r001522_1, pub_r001522_2);
    int helper_flow_1 = fn_R001522_2213_1(sec_r001522_1, pub_r001522_2);
    int helper_flow_2 = fn_R001522_2213_2(sec_r001522_2, pub_r001522_3, pub_r001522_4);
    int helper_flow_3 = fn_R001522_2213_3(sec_r001522_3, sec_r001522_4, pub_r001522_5, pub_r001522_6, pub_r001522_7);
    int helper_flow_4 = fn_R001522_2213_4(sec_r001522_4, pub_r001522_5, pub_r001522_6, pub_r001522_7, pub_r001522_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001522_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001522_18 * 3) + pub_r001522_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001522_11 * 3) + pub_r001522_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001522_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001522_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001522_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001522_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001522_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_0 * 3) + pub_r001522_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001522_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001522_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001522_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001522_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001522_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001522_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001522_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001522_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001522_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001522_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001522_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001522_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_0 * 3) + pub_r001522_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001522_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001522_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001522_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001522_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001522_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001522_4 * 3) + pub_r001522_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_8 * 3) + pub_r001522_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001522_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001522_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001522_2 * 3) + pub_r001522_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001522_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001522_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001522_2 * 3) + pub_r001522_18 + 39) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_3 * 3) + pub_r001522_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001522_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001522_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001522_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_8 * 3) + pub_r001522_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001522_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001522_13 * 3) + pub_r001522_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001522_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001522_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001522_5 * 3) + pub_r001522_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001522_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_8 * 3) + pub_r001522_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001522_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001522_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001522_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001522_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001522_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001522_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001522_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001522_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001522_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001522_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001522_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001522_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001522_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001522_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001522_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001522_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001522_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001522_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001522_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001522_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001522_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_2 * 3) + pub_r001522_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001522_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001522_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001522_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001522_17 * 3) + pub_r001522_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001522_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001522_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001522_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001522_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001522_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001522_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_72 * 3) + pub_r001522_18 + 43) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001522_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001522_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_1 * 3) + pub_r001522_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_0 * 3) + pub_r001522_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001522_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001522_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001522_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001522_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_27 * 3) + pub_r001522_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001522_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_68 * 3) + pub_r001522_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_41 * 3) + pub_r001522_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001522_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_28 * 3) + pub_r001522_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001522_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001522_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_41 * 3) + pub_r001522_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_93 * 3) + pub_r001522_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001522_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001522_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001522_6 * 3) + pub_r001522_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001522_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001522_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001522_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((helper_flow_1 * 3) + pub_r001522_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001522_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001522_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001522_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001522_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_93 * 3) + pub_r001522_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001522_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001522_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_104 * 3) + pub_r001522_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001522_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001522_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001522_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001522_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001522_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001522_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001522_5 * 3) + pub_r001522_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001522_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001522_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001522_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001522_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001522_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001522_3 * 3) + pub_r001522_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001522_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001522_9 * 3) + pub_r001522_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_21 * 3) + pub_r001522_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_112 * 3) + pub_r001522_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_100 * 3) + pub_r001522_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001522_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_119 * 3) + pub_r001522_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001522_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001522_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001522_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001522_11 * 3) + pub_r001522_17 + 7) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001522_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001522_1 * 3) + pub_r001522_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((helper_flow_0 * 3) + pub_r001522_17 + 8) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_46 * 3) + pub_r001522_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001522_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001522_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001522_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001522_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001522_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001522_13 * 3) + pub_r001522_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001522_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_104 * 3) + pub_r001522_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001522_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((helper_flow_1 * 3) + pub_r001522_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_97 * 3) + pub_r001522_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001522_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001522_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001522_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001522_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001522_18 * 3) + pub_r001522_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156 * 2) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_1 * 3) + pub_r001522_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001522_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001522_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001522_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001522_2 * 3) + pub_r001522_16 + 42) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001522_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001522_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001522_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_100 * 3) + pub_r001522_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001522_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001522_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001522_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001522_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_129 * 3) + pub_r001522_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001522_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_68 * 3) + pub_r001522_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_170 * 3) + pub_r001522_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001522_17 * 3) + pub_r001522_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001522_17 * 3) + pub_r001522_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001522_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001522_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001522_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001522_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001522_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001522_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001522_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001522_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001522_9 * 3) + pub_r001522_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001522_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_139 * 3) + pub_r001522_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001522_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_119 * 3) + pub_r001522_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_90 * 3) + pub_r001522_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_174 * 3) + pub_r001522_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_21 * 3) + pub_r001522_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001522_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001522_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r001522_2 * 3) + pub_r001522_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001522_1 * 3) + pub_r001522_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001522_2 * 3) + pub_r001522_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001522_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001522_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_170 * 3) + pub_r001522_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199 * 2) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001522_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_128 * 3) + pub_r001522_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_35 * 3) + pub_r001522_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001522_1 * 3) + pub_r001522_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001522_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_128 * 3) + pub_r001522_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_170 * 3) + pub_r001522_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001522_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_21 * 3) + pub_r001522_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001522_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001522_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_165 * 3) + pub_r001522_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001522_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001522_14 * 3) + pub_r001522_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001522_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001522_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_161 * 3) + pub_r001522_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001522_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_188 * 3) + pub_r001522_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r001522_1 * 3) + pub_r001522_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001522_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r001522_10 * 3) + pub_r001522_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001522_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001522_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001522_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_151 * 3) + pub_r001522_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225 * 2) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001522_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_109 * 3) + pub_r001522_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_27 * 3) + pub_r001522_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228 * 2) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_41 * 3) + pub_r001522_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001522_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001522_3 * 3) + pub_r001522_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001522_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_21 * 3) + pub_r001522_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_229 * 3) + pub_r001522_18 + 18) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_1 * 3) + pub_r001522_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001522_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001522_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r001522_3 * 3) + pub_r001522_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238 * 2) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001522_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001522_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001522_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001522_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001522_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001522_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_140 * 3) + pub_r001522_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245 * 2) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_127 * 3) + pub_r001522_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_194 * 3) + pub_r001522_13 + 41) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001522_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001522_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001522_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_35 * 3) + pub_r001522_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001522_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001522_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r001522_11 * 3) + pub_r001522_8 + 44) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001522_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001522_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001522_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001522_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001522_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001522_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001522_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001522_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001522_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001522_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_175 * 3) + pub_r001522_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001522_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_235 * 3) + pub_r001522_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001522_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_265 * 3) + pub_r001522_5 + 31) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001522_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_174 * 3) + pub_r001522_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001522_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((helper_flow_0 * 3) + pub_r001522_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001522_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_39 * 3) + pub_r001522_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001522_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001522_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001522_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001522_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_206 * 3) + pub_r001522_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_203 * 3) + pub_r001522_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281 * 2) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001522_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001522_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001522_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001522_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001522_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001522_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001522_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001522_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001522_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001522_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001522_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001522_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001522_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((helper_flow_3 * 3) + pub_r001522_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001522_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_151 * 3) + pub_r001522_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297 * 2) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001522_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001522_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001522_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001522_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001522_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_136 * 3) + pub_r001522_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001522_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001522_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001522_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001522_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001522_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_31 * 3) + pub_r001522_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_97 * 3) + pub_r001522_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001522_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_157 * 3) + pub_r001522_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001522_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_273 * 3) + pub_r001522_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001522_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_218 * 3) + pub_r001522_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001522_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001522_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_104 * 3) + pub_r001522_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001522_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001522_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001522_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001522_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001522_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001522_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_235 * 3) + pub_r001522_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001522_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001522_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001522_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_195 * 3) + pub_r001522_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_150 * 3) + pub_r001522_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001522_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001522_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001522_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001522_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001522_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001522_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((sec_r001522_5 * 3) + pub_r001522_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001522_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((helper_flow_4 * 3) + pub_r001522_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001522_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r001522_6 * 3) + pub_r001522_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001522_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001522_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001522_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001522_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_229 * 3) + pub_r001522_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001522_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001522_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_1 * 3) + pub_r001522_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001522_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_206 * 3) + pub_r001522_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001522_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001522_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_205 * 3) + pub_r001522_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001522_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_342 * 3) + pub_r001522_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001522_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001522_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001522_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001522_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001522_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001522_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_139 * 3) + pub_r001522_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001522_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_196 * 3) + pub_r001522_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001522_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_310 * 3) + pub_r001522_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001522_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_247 * 3) + pub_r001522_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_340 * 3) + pub_r001522_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001522_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((sec_r001522_4 * 3) + pub_r001522_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_280 * 3) + pub_r001522_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001522_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001522_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001522_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_229 * 3) + pub_r001522_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001522_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001522_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001522_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001522_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001522_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((sec_r001522_11 * 3) + pub_r001522_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001522_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001522_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001522_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001522_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_130 * 3) + pub_r001522_17 + 6) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_254 * 3) + pub_r001522_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001522_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001522_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001522_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((sec_r001522_13 * 3) + pub_r001522_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001522_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001522_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((sec_r001522_16 * 3) + pub_r001522_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001522_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001522_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001522_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001522_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((helper_flow_3 * 3) + pub_r001522_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001522_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001522_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001522_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_148 * 3) + pub_r001522_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001522_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((sec_r001522_12 * 3) + pub_r001522_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_408) & 255;
    out_sink = (out_sink + stage_v_408 * 2) & 255;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001522_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_21 * 3) + pub_r001522_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_90 * 3) + pub_r001522_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001522_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_1 * 3) + pub_r001522_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_130 * 3) + pub_r001522_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001522_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_331 * 3) + pub_r001522_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001522_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((sec_r001522_12 * 3) + pub_r001522_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_418) & 255;
    out_sink = (out_sink + stage_v_418 * 2) & 255;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001522_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001522_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_189 * 3) + pub_r001522_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001522_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001522_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001522_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_374 * 3) + pub_r001522_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_186 * 3) + pub_r001522_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001522_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001522_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001522_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((sec_r001522_12 * 3) + pub_r001522_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001522_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_125 * 3) + pub_r001522_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_148 * 3) + pub_r001522_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001522_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_8 * 3) + pub_r001522_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_435) & 255;
    out_sink = (out_sink + stage_v_435 * 2) & 255;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001522_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001522_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_8 * 3) + pub_r001522_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_208 * 3) + pub_r001522_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_82 * 3) + pub_r001522_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_96 * 3) + pub_r001522_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001522_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001522_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_189 * 3) + pub_r001522_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001522_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001522_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001522_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001522_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((sec_r001522_9 * 3) + pub_r001522_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((sec_r001522_12 * 3) + pub_r001522_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_132 * 3) + pub_r001522_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001522_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001522_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001522_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001522_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_319 * 3) + pub_r001522_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001522_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001522_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_355 * 3) + pub_r001522_18 + 27) & 127;
    sec_accum = (sec_accum + stage_v_459) & 255;
    out_sink = (out_sink + stage_v_459 * 2) & 255;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_247 * 3) + pub_r001522_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_350 * 3) + pub_r001522_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001522_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001522_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001522_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_129 * 3) + pub_r001522_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_465) & 255;
    out_sink = (out_sink + stage_v_465 * 2) & 255;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001522_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001522_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001522_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001522_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((sec_r001522_2 * 3) + pub_r001522_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_470) & 255;
    out_sink = (out_sink + stage_v_470 * 2) & 255;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001522_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001522_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_206 * 3) + pub_r001522_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_319 * 3) + pub_r001522_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001522_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001522_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_459 * 3) + pub_r001522_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_477) & 255;
    out_sink = (out_sink + stage_v_477 * 2) & 255;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001522_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_46 * 3) + pub_r001522_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_479) & 255;
    out_sink = (out_sink + stage_v_479 * 2) & 255;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_479 * 3) + pub_r001522_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_480) & 255;
    out_sink = (out_sink + stage_v_480 * 2) & 255;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001522_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001522_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001522_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((sec_r001522_11 * 3) + pub_r001522_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_484) & 255;
    out_sink = (out_sink + stage_v_484 * 2) & 255;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001522_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001522_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_136 * 3) + pub_r001522_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_487) & 255;
    out_sink = (out_sink + stage_v_487 * 2) & 255;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_233 * 3) + pub_r001522_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_488) & 255;
    out_sink = (out_sink + stage_v_488 * 2) & 255;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001522_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = ((sec_r001522_9 * 3) + pub_r001522_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_490) & 255;
    out_sink = (out_sink + stage_v_490 * 2) & 255;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = ((stage_v_319 * 3) + pub_r001522_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_491) & 255;
    out_sink = (out_sink + stage_v_491 * 2) & 255;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001522_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001522_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_211 * 3) + pub_r001522_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_494) & 255;
    out_sink = (out_sink + stage_v_494 * 2) & 255;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001522_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001522_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001522_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001522_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((stage_v_140 * 3) + pub_r001522_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_499) & 255;
    out_sink = (out_sink + stage_v_499 * 2) & 255;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001522_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((stage_v_340 * 3) + pub_r001522_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_501) & 255;
    out_sink = (out_sink + stage_v_501 * 2) & 255;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001522_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001522_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001522_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001522_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001522_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001522_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001522_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001522_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = ((stage_v_151 * 3) + pub_r001522_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_510) & 255;
    out_sink = (out_sink + stage_v_510 * 2) & 255;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001522_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = (pub_r001522_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_512) & 127;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = ((sec_r001522_7 * 3) + pub_r001522_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_513) & 255;
    out_sink = (out_sink + stage_v_513 * 2) & 255;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_225 * 3) + pub_r001522_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001522_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = ((stage_v_90 * 3) + pub_r001522_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_516) & 255;
    out_sink = (out_sink + stage_v_516 * 2) & 255;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = ((sec_r001522_4 * 3) + pub_r001522_2 + 13) & 127;
    sec_accum = (sec_accum + stage_v_517) & 255;
    out_sink = (out_sink + stage_v_517 * 2) & 255;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = ((stage_v_342 * 3) + pub_r001522_8 + 40) & 127;
    sec_accum = (sec_accum + stage_v_518) & 255;
    out_sink = (out_sink + stage_v_518 * 2) & 255;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001522_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001522_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = ((stage_v_444 * 3) + pub_r001522_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_521) & 255;
    out_sink = (out_sink + stage_v_521 * 2) & 255;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = ((stage_v_310 * 3) + pub_r001522_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_522) & 255;
    out_sink = (out_sink + stage_v_522 * 2) & 255;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = (pub_r001522_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_523) & 127;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001522_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001522_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = (pub_r001522_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_526) & 127;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = (pub_r001522_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_527) & 127;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001522_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = (pub_r001522_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_529) & 127;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001522_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = (pub_r001522_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_531) & 127;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = ((stage_v_295 * 3) + pub_r001522_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_532) & 255;
    out_sink = (out_sink + stage_v_532 * 2) & 255;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = (pub_r001522_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_533) & 127;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = (pub_r001522_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_534) & 127;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = ((stage_v_202 * 3) + pub_r001522_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_535) & 255;
    out_sink = (out_sink + stage_v_535 * 2) & 255;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = (pub_r001522_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_536) & 127;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = ((stage_v_340 * 3) + pub_r001522_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_537) & 255;
    out_sink = (out_sink + stage_v_537 * 2) & 255;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = (pub_r001522_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_538) & 127;

    /* Execution Pipeline Stage 539 */
    int stage_v_539 = (pub_r001522_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_539) & 127;

    /* Execution Pipeline Stage 540 */
    int stage_v_540 = (pub_r001522_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_540) & 127;

    /* Execution Pipeline Stage 541 */
    int stage_v_541 = (pub_r001522_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_541) & 127;

    /* Execution Pipeline Stage 542 */
    int stage_v_542 = (pub_r001522_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_542) & 127;

    /* Execution Pipeline Stage 543 */
    int stage_v_543 = (pub_r001522_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_543) & 127;

    /* Execution Pipeline Stage 544 */
    int stage_v_544 = (pub_r001522_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_544) & 127;

    /* Execution Pipeline Stage 545 */
    int stage_v_545 = (pub_r001522_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_545) & 127;

    /* Execution Pipeline Stage 546 */
    int stage_v_546 = ((stage_v_196 * 3) + pub_r001522_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_546) & 255;
    out_sink = (out_sink + stage_v_546 * 2) & 255;

    /* Execution Pipeline Stage 547 */
    int stage_v_547 = (pub_r001522_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_547) & 127;

    /* Execution Pipeline Stage 548 */
    int stage_v_548 = (pub_r001522_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_548) & 127;

    /* Execution Pipeline Stage 549 */
    int stage_v_549 = (pub_r001522_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_549) & 127;

    /* Execution Pipeline Stage 550 */
    int stage_v_550 = ((stage_v_173 * 3) + pub_r001522_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_550) & 255;
    out_sink = (out_sink + stage_v_550 * 2) & 255;

    /* Execution Pipeline Stage 551 */
    int stage_v_551 = ((stage_v_184 * 3) + pub_r001522_14 + 34) & 127;
    sec_accum = (sec_accum + stage_v_551) & 255;
    out_sink = (out_sink + stage_v_551 * 2) & 255;

    /* Execution Pipeline Stage 552 */
    int stage_v_552 = (pub_r001522_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_552) & 127;

    /* Execution Pipeline Stage 553 */
    int stage_v_553 = (pub_r001522_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_553) & 127;

    /* Execution Pipeline Stage 554 */
    int stage_v_554 = ((stage_v_136 * 3) + pub_r001522_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_554) & 255;
    out_sink = (out_sink + stage_v_554 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
