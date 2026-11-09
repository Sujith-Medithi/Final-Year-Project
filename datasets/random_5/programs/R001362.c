/*
 * Benchmark Program: R001362
 * Security Family: direct_leakage
 * Generator Seed: 636213
 * High Inputs: 22 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001362_6213_0 {
    short state;
    unsigned char tail;
    int watermark;
    int capacity;
    int buffer[3];
};

struct Vector3D_R001362_6213_1 {
    int coord_y;
    int norm_sq;
    unsigned char coord_z;
    int buffer[3];
};

union ColorPixel_R001362_6213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001362_6213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001362_6213_0(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_67 = 0;
    for (int k = 0; k < 3; k++) {
        tally_67 = (tally_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001362_6213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int accumulator_21 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_21 = (accumulator_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_21) & 127;
    }
    int quotient_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_34 = local_arr[aux % 3];
    acc = (acc + mask_34 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001362_6213_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_83 = local_arr[aux % 3];
    acc = (acc + factor_83 * 2) & 127;
    int tracker_21 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_21 = (tracker_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_85 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_85 > 49) {
        acc = (acc + cursor_85 * 2 + 5) & 127;
        aux ^= (cursor_85 & 15);
    } else {
        acc = (acc - cursor_85 + 11) & 127;
        aux += 3;
    }
    int scale_79 = (aux + st.buffer[1]) & 3;
    switch (scale_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_41 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_41 = (quantum_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_4(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int pivot_36 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_36 > 38) {
        acc = (acc + pivot_36 * 2 + 5) & 127;
        aux ^= (pivot_36 & 15);
    } else {
        acc = (acc - pivot_36 + 11) & 127;
        aux += 3;
    }
    int index_reg_63 = (aux + st.buffer[1]) & 3;
    switch (index_reg_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001362_6213_5(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int mask_93 = local_arr[aux % 3];
    acc = (acc + mask_93 * 2) & 127;
    int bound_74 = 0;
    for (int k = 0; k < 2; k++) {
        bound_74 = (bound_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_6(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_38 = (aux + st.buffer[1]) & 3;
    switch (parity_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_36) & 63;
    acc ^= aux;
    int metric_84 = 0;
    for (int k = 0; k < 2; k++) {
        metric_84 = (metric_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_84) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_7(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int cursor_27 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_27 > 26) {
        acc = (acc + cursor_27 * 2 + 5) & 127;
        aux ^= (cursor_27 & 15);
    } else {
        acc = (acc - cursor_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_73 = local_arr[aux % 3];
    acc = (acc + parity_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001362_6213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int scale_70 = local_arr[aux % 3];
    acc = (acc + scale_70 * 2) & 127;
    int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001362_6213_9(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001362_6213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int delta_33 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_33 > 43) {
        acc = (acc + delta_33 * 2 + 5) & 127;
        aux ^= (delta_33 & 15);
    } else {
        acc = (acc - delta_33 + 11) & 127;
        aux += 3;
    }
    int phase_24 = 0;
    for (int k = 0; k < 2; k++) {
        phase_24 = (phase_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_24) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001362_6213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001362_6213_11(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001362_6213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int mask_65 = 0;
    for (int k = 0; k < 2; k++) {
        mask_65 = (mask_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_65) & 127;
    }
    int residue_52 = (aux + st.buffer[1]) & 3;
    switch (residue_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int stride_99 = (aux + st.buffer[1]) & 3;
    switch (stride_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_42 = local_arr[aux % 3];
    acc = (acc + window_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001362_6213_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int window_27 = local_arr[aux % 3];
    acc = (acc + window_27 * 2) & 127;
    int bound_38 = (aux + st.buffer[1]) & 3;
    switch (bound_38) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_27 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_27 > 16) {
        acc = (acc + mask_27 * 2 + 5) & 127;
        aux ^= (mask_27 & 15);
    } else {
        acc = (acc - mask_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int coefficient_77 = local_arr[aux % 3];
    acc = (acc + coefficient_77 * 2) & 127;
    int residue_26 = (aux + st.buffer[1]) & 3;
    switch (residue_26) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001362_6213_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_38 = (aux + st.buffer[1]) & 3;
    switch (margin_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_74 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_74 > 31) {
        acc = (acc + residue_74 * 2 + 5) & 127;
        aux ^= (residue_74 & 15);
    } else {
        acc = (acc - residue_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001362_6213_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001362_6213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_99 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_99 > 25) {
        acc = (acc + accumulator_99 * 2 + 5) & 127;
        aux ^= (accumulator_99 & 15);
    } else {
        acc = (acc - accumulator_99 + 11) & 127;
        aux += 3;
    }
    int mask_75 = (aux + st.buffer[1]) & 3;
    switch (mask_75) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001362_0;
    int sec_r001362_1;
    int sec_r001362_2;
    int sec_r001362_3;
    int sec_r001362_4;
    int sec_r001362_5;
    int sec_r001362_6;
    int sec_r001362_7;
    int sec_r001362_8;
    int sec_r001362_9;
    int sec_r001362_10;
    int sec_r001362_11;
    int sec_r001362_12;
    int sec_r001362_13;
    int sec_r001362_14;
    int sec_r001362_15;
    int sec_r001362_16;
    int sec_r001362_17;
    int sec_r001362_18;
    int sec_r001362_19;
    int sec_r001362_20;
    int sec_r001362_21;
    int pub_r001362_0;
    int pub_r001362_1;
    int pub_r001362_2;
    int pub_r001362_3;
    int pub_r001362_4;
    int pub_r001362_5;
    int pub_r001362_6;
    int pub_r001362_7;
    int pub_r001362_8;
    int pub_r001362_9;
    int pub_r001362_10;
    int pub_r001362_11;
    int pub_r001362_12;
    int pub_r001362_13;
    int pub_r001362_14;
    int pub_r001362_15;
    int pub_r001362_16;
    int pub_r001362_17;
    int pub_r001362_18;
    int pub_r001362_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001362_0 >= -100 && pub_r001362_0 <= 100);
    __CPROVER_assume(pub_r001362_1 >= -100 && pub_r001362_1 <= 100);
    __CPROVER_assume(pub_r001362_2 >= -100 && pub_r001362_2 <= 100);
    __CPROVER_assume(pub_r001362_3 >= -100 && pub_r001362_3 <= 100);
    __CPROVER_assume(pub_r001362_4 >= -100 && pub_r001362_4 <= 100);
    __CPROVER_assume(pub_r001362_5 >= -100 && pub_r001362_5 <= 100);
    __CPROVER_assume(pub_r001362_6 >= -100 && pub_r001362_6 <= 100);
    __CPROVER_assume(pub_r001362_7 >= -100 && pub_r001362_7 <= 100);
    __CPROVER_assume(pub_r001362_8 >= -100 && pub_r001362_8 <= 100);
    __CPROVER_assume(pub_r001362_9 >= -100 && pub_r001362_9 <= 100);
    __CPROVER_assume(pub_r001362_10 >= -100 && pub_r001362_10 <= 100);
    __CPROVER_assume(pub_r001362_11 >= -100 && pub_r001362_11 <= 100);
    __CPROVER_assume(pub_r001362_12 >= -100 && pub_r001362_12 <= 100);
    __CPROVER_assume(pub_r001362_13 >= -100 && pub_r001362_13 <= 100);
    __CPROVER_assume(pub_r001362_14 >= -100 && pub_r001362_14 <= 100);
    __CPROVER_assume(pub_r001362_15 >= -100 && pub_r001362_15 <= 100);
    __CPROVER_assume(pub_r001362_16 >= -100 && pub_r001362_16 <= 100);
    __CPROVER_assume(pub_r001362_17 >= -100 && pub_r001362_17 <= 100);
    __CPROVER_assume(pub_r001362_18 >= -100 && pub_r001362_18 <= 100);
    __CPROVER_assume(pub_r001362_19 >= -100 && pub_r001362_19 <= 100);
    __CPROVER_assume(sec_r001362_0 >= 0 && sec_r001362_0 <= 255);
    __CPROVER_assume(sec_r001362_1 >= 0 && sec_r001362_1 <= 255);
    __CPROVER_assume(sec_r001362_2 >= 0 && sec_r001362_2 <= 255);
    __CPROVER_assume(sec_r001362_3 >= 0 && sec_r001362_3 <= 255);
    __CPROVER_assume(sec_r001362_4 >= 0 && sec_r001362_4 <= 255);
    __CPROVER_assume(sec_r001362_5 >= 0 && sec_r001362_5 <= 255);
    __CPROVER_assume(sec_r001362_6 >= 0 && sec_r001362_6 <= 255);
    __CPROVER_assume(sec_r001362_7 >= 0 && sec_r001362_7 <= 255);
    __CPROVER_assume(sec_r001362_8 >= 0 && sec_r001362_8 <= 255);
    __CPROVER_assume(sec_r001362_9 >= 0 && sec_r001362_9 <= 255);
    __CPROVER_assume(sec_r001362_10 >= 0 && sec_r001362_10 <= 255);
    __CPROVER_assume(sec_r001362_11 >= 0 && sec_r001362_11 <= 255);
    __CPROVER_assume(sec_r001362_12 >= 0 && sec_r001362_12 <= 255);
    __CPROVER_assume(sec_r001362_13 >= 0 && sec_r001362_13 <= 255);
    __CPROVER_assume(sec_r001362_14 >= 0 && sec_r001362_14 <= 255);
    __CPROVER_assume(sec_r001362_15 >= 0 && sec_r001362_15 <= 255);
    __CPROVER_assume(sec_r001362_16 >= 0 && sec_r001362_16 <= 255);
    __CPROVER_assume(sec_r001362_17 >= 0 && sec_r001362_17 <= 255);
    __CPROVER_assume(sec_r001362_18 >= 0 && sec_r001362_18 <= 255);
    __CPROVER_assume(sec_r001362_19 >= 0 && sec_r001362_19 <= 255);
    __CPROVER_assume(sec_r001362_20 >= 0 && sec_r001362_20 <= 255);
    __CPROVER_assume(sec_r001362_21 >= 0 && sec_r001362_21 <= 255);

    struct StreamBuffer_R001362_6213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001362_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001362_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001362_0 + 7) & 15;
    struct Vector3D_R001362_6213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001362_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001362_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001362_0 + 9) & 15;

    union ColorPixel_R001362_6213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001362_6213_0(sec_r001362_0, sec_r001362_1, pub_r001362_2);
    int helper_flow_1 = fn_R001362_6213_1(sec_r001362_1, pub_r001362_2, pub_r001362_3, pub_r001362_4);
    int helper_flow_2 = fn_R001362_6213_2(sec_r001362_2, sec_r001362_3, pub_r001362_4, pub_r001362_5, pub_r001362_6);
    int helper_flow_3 = fn_R001362_6213_3(sec_r001362_3, sec_r001362_4, pub_r001362_5, pub_r001362_6);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001362_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001362_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001362_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_3 * 3) + pub_r001362_18 + 4) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001362_18 * 3) + pub_r001362_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001362_6 * 3) + pub_r001362_16 + 39) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001362_8 * 3) + pub_r001362_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001362_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001362_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001362_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001362_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001362_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001362_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001362_8 * 3) + pub_r001362_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001362_21 * 3) + pub_r001362_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14 * 2) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_5 * 3) + pub_r001362_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001362_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001362_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001362_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001362_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_4 * 3) + pub_r001362_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001362_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001362_19 * 3) + pub_r001362_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_4 * 3) + pub_r001362_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001362_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_2 * 3) + pub_r001362_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25 * 2) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001362_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001362_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001362_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001362_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001362_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001362_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001362_9 * 3) + pub_r001362_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001362_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001362_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_6 * 3) + pub_r001362_19 + 17) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_14 * 3) + pub_r001362_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001362_18 * 3) + pub_r001362_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37 * 2) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001362_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001362_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001362_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001362_2 * 3) + pub_r001362_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001362_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001362_7 * 3) + pub_r001362_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001362_17 * 3) + pub_r001362_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001362_3 * 3) + pub_r001362_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001362_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001362_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001362_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001362_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_36 * 3) + pub_r001362_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001362_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_43 * 3) + pub_r001362_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001362_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_35 * 3) + pub_r001362_0 + 41) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001362_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_5 * 3) + pub_r001362_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56 * 2) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001362_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001362_1 * 3) + pub_r001362_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001362_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001362_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001362_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001362_20 * 3) + pub_r001362_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_14 * 3) + pub_r001362_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001362_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001362_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001362_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_2 * 3) + pub_r001362_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67 * 2) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001362_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001362_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001362_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001362_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_36 * 3) + pub_r001362_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001362_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001362_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001362_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001362_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001362_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001362_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001362_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_52 * 3) + pub_r001362_19 + 40) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_2 * 3) + pub_r001362_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001362_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001362_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001362_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001362_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_1 * 3) + pub_r001362_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001362_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001362_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001362_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001362_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001362_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001362_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001362_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001362_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_20 * 3) + pub_r001362_19 + 30) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001362_21 * 3) + pub_r001362_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001362_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001362_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001362_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001362_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001362_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001362_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001362_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001362_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001362_13 * 3) + pub_r001362_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105 * 2) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001362_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001362_11 * 3) + pub_r001362_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_67 * 3) + pub_r001362_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001362_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_5 * 3) + pub_r001362_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_45 * 3) + pub_r001362_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001362_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_20 * 3) + pub_r001362_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001362_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001362_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001362_19 * 3) + pub_r001362_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001362_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001362_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_67 * 3) + pub_r001362_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001362_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001362_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001362_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001362_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001362_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001362_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_67 * 3) + pub_r001362_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126 * 2) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001362_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_32 * 3) + pub_r001362_4 + 39) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001362_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001362_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001362_19 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001362_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001362_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001362_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001362_4 * 3) + pub_r001362_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001362_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001362_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001362_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001362_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001362_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_54 * 3) + pub_r001362_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001362_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_37 * 3) + pub_r001362_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001362_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_67 * 3) + pub_r001362_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_105 * 3) + pub_r001362_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001362_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001362_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001362_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001362_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001362_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001362_2 * 3) + pub_r001362_12 + 42) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001362_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_63 * 3) + pub_r001362_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_36 * 3) + pub_r001362_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001362_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001362_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_145 * 3) + pub_r001362_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_36 * 3) + pub_r001362_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001362_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001362_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001362_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001362_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_50 * 3) + pub_r001362_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_22 * 3) + pub_r001362_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001362_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001362_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_141 * 3) + pub_r001362_17 + 43) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001362_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001362_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001362_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_45 * 3) + pub_r001362_19 + 31) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001362_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001362_2 * 3) + pub_r001362_18 + 42) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001362_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001362_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001362_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001362_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001362_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_37 * 3) + pub_r001362_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001362_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_146 * 3) + pub_r001362_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001362_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_50 * 3) + pub_r001362_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001362_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001362_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001362_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001362_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001362_15 * 3) + pub_r001362_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_13 * 3) + pub_r001362_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001362_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001362_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_116 * 3) + pub_r001362_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_116 * 3) + pub_r001362_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001362_2 * 3) + pub_r001362_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001362_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001362_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001362_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_56 * 3) + pub_r001362_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199 * 2) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001362_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_35 * 3) + pub_r001362_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001362_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001362_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_15 * 3) + pub_r001362_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001362_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001362_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001362_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_113 * 3) + pub_r001362_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001362_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001362_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001362_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001362_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001362_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001362_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001362_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_201 * 3) + pub_r001362_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001362_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001362_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001362_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001362_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_3 * 3) + pub_r001362_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001362_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_52 * 3) + pub_r001362_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001362_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_168 * 3) + pub_r001362_14 + 45) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225 * 2) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001362_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_80 * 3) + pub_r001362_18 + 34) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001362_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001362_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_4 * 3) + pub_r001362_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001362_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001362_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_168 * 3) + pub_r001362_2 + 45) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_184 * 3) + pub_r001362_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001362_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001362_21 * 3) + pub_r001362_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((helper_flow_0 * 3) + pub_r001362_18 + 45) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001362_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001362_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001362_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001362_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001362_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_41 * 3) + pub_r001362_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243 * 2) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((helper_flow_1 * 3) + pub_r001362_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001362_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001362_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001362_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001362_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_58 * 3) + pub_r001362_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249 * 2) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001362_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001362_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001362_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001362_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001362_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001362_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001362_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_25 * 3) + pub_r001362_18 + 27) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257 * 2) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001362_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001362_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_43 * 3) + pub_r001362_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001362_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001362_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001362_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_221 * 3) + pub_r001362_1 + 43) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001362_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001362_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001362_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001362_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_110 * 3) + pub_r001362_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_264 * 3) + pub_r001362_5 + 42) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001362_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001362_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001362_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_67 * 3) + pub_r001362_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001362_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r001362_21 * 3) + pub_r001362_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001362_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r001362_9 * 3) + pub_r001362_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001362_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001362_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001362_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001362_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001362_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001362_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001362_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001362_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001362_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001362_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001362_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001362_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_152 * 3) + pub_r001362_0 + 41) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001362_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001362_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_278 * 3) + pub_r001362_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001362_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_208 * 3) + pub_r001362_0 + 41) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001362_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001362_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001362_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001362_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001362_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001362_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001362_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_230 * 3) + pub_r001362_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r001362_21 * 3) + pub_r001362_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001362_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_180 * 3) + pub_r001362_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_107 * 3) + pub_r001362_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001362_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r001362_14 * 3) + pub_r001362_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_143 * 3) + pub_r001362_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001362_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001362_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001362_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001362_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001362_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001362_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_35 * 3) + pub_r001362_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001362_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_15 * 3) + pub_r001362_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_190 * 3) + pub_r001362_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001362_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_119 * 3) + pub_r001362_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_270 * 3) + pub_r001362_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001362_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001362_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001362_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_168 * 3) + pub_r001362_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001362_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001362_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_276 * 3) + pub_r001362_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r001362_3 * 3) + pub_r001362_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_193 * 3) + pub_r001362_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r001362_8 * 3) + pub_r001362_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_234 * 3) + pub_r001362_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001362_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001362_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001362_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001362_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001362_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001362_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_223 * 3) + pub_r001362_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001362_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001362_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((sec_r001362_9 * 3) + pub_r001362_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001362_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_305 * 3) + pub_r001362_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_95 * 3) + pub_r001362_18 + 38) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_190 * 3) + pub_r001362_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_143 * 3) + pub_r001362_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((sec_r001362_11 * 3) + pub_r001362_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001362_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001362_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_116 * 3) + pub_r001362_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_249 * 3) + pub_r001362_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001362_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001362_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_324 * 3) + pub_r001362_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001362_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001362_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_324 * 3) + pub_r001362_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001362_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((sec_r001362_3 * 3) + pub_r001362_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_195 * 3) + pub_r001362_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_107 * 3) + pub_r001362_0 + 38) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((sec_r001362_17 * 3) + pub_r001362_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001362_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001362_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((sec_r001362_20 * 3) + pub_r001362_18 + 27) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369 * 2) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001362_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001362_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_172 * 3) + pub_r001362_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001362_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001362_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_62 * 3) + pub_r001362_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001362_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001362_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001362_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_264 * 3) + pub_r001362_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_311 * 3) + pub_r001362_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_67 * 3) + pub_r001362_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_184 * 3) + pub_r001362_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_382) & 255;
    out_sink = (out_sink + stage_v_382 * 2) & 255;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_105 * 3) + pub_r001362_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001362_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001362_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001362_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001362_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001362_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001362_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001362_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001362_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001362_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_43 * 3) + pub_r001362_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_172 * 3) + pub_r001362_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_201 * 3) + pub_r001362_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001362_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001362_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_63 * 3) + pub_r001362_16 + 44) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_363 * 3) + pub_r001362_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_399) & 255;
    out_sink = (out_sink + stage_v_399 * 2) & 255;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001362_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001362_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_264 * 3) + pub_r001362_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001362_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_145 * 3) + pub_r001362_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_264 * 3) + pub_r001362_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001362_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001362_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001362_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001362_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((sec_r001362_0 * 3) + pub_r001362_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001362_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_348 * 3) + pub_r001362_16 + 38) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_380 * 3) + pub_r001362_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001362_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001362_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001362_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((helper_flow_1 * 3) + pub_r001362_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001362_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001362_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001362_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001362_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001362_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((sec_r001362_12 * 3) + pub_r001362_14 + 34) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_423 * 3) + pub_r001362_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001362_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001362_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_216 * 3) + pub_r001362_19 + 11) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001362_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_237 * 3) + pub_r001362_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_86 * 3) + pub_r001362_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_310 * 3) + pub_r001362_8 + 39) & 127;
    sec_accum = (sec_accum + stage_v_431) & 255;
    out_sink = (out_sink + stage_v_431 * 2) & 255;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001362_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001362_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001362_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001362_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((sec_r001362_14 * 3) + pub_r001362_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((sec_r001362_6 * 3) + pub_r001362_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_437) & 255;
    out_sink = (out_sink + stage_v_437 * 2) & 255;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_375 * 3) + pub_r001362_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_348 * 3) + pub_r001362_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001362_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001362_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001362_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001362_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((sec_r001362_3 * 3) + pub_r001362_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001362_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((helper_flow_0 * 3) + pub_r001362_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001362_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001362_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_308 * 3) + pub_r001362_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001362_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001362_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001362_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001362_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((sec_r001362_0 * 3) + pub_r001362_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_454) & 255;
    out_sink = (out_sink + stage_v_454 * 2) & 255;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001362_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001362_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001362_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001362_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001362_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_126 * 3) + pub_r001362_15 + 17) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001362_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001362_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((sec_r001362_2 * 3) + pub_r001362_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001362_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001362_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001362_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001362_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001362_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((helper_flow_1 * 3) + pub_r001362_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_469) & 255;
    out_sink = (out_sink + stage_v_469 * 2) & 255;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001362_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001362_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001362_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_141 * 3) + pub_r001362_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001362_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_379 * 3) + pub_r001362_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001362_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001362_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = ((stage_v_332 * 3) + pub_r001362_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_478) & 255;
    out_sink = (out_sink + stage_v_478 * 2) & 255;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001362_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_15 * 3) + pub_r001362_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_480) & 255;
    out_sink = (out_sink + stage_v_480 * 2) & 255;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001362_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001362_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001362_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001362_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = ((helper_flow_1 * 3) + pub_r001362_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_485) & 255;
    out_sink = (out_sink + stage_v_485 * 2) & 255;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001362_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001362_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001362_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001362_19 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001362_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = ((stage_v_383 * 3) + pub_r001362_18 + 35) & 127;
    sec_accum = (sec_accum + stage_v_491) & 255;
    out_sink = (out_sink + stage_v_491 * 2) & 255;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001362_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_44 * 3) + pub_r001362_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_493) & 255;
    out_sink = (out_sink + stage_v_493 * 2) & 255;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001362_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001362_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001362_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001362_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((stage_v_208 * 3) + pub_r001362_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_498) & 255;
    out_sink = (out_sink + stage_v_498 * 2) & 255;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001362_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = ((stage_v_230 * 3) + pub_r001362_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_500) & 255;
    out_sink = (out_sink + stage_v_500 * 2) & 255;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001362_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001362_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001362_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_358 * 3) + pub_r001362_6 + 36) & 127;
    sec_accum = (sec_accum + stage_v_504) & 255;
    out_sink = (out_sink + stage_v_504 * 2) & 255;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001362_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001362_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001362_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_37 * 3) + pub_r001362_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_508) & 255;
    out_sink = (out_sink + stage_v_508 * 2) & 255;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001362_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = ((stage_v_95 * 3) + pub_r001362_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_510) & 255;
    out_sink = (out_sink + stage_v_510 * 2) & 255;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001362_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = (pub_r001362_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_512) & 127;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001362_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = (pub_r001362_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_514) & 127;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001362_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = (pub_r001362_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_516) & 127;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001362_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = (pub_r001362_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_518) & 127;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001362_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001362_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = (pub_r001362_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_521) & 127;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = (pub_r001362_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_522) & 127;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = ((stage_v_383 * 3) + pub_r001362_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_523) & 255;
    out_sink = (out_sink + stage_v_523 * 2) & 255;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001362_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001362_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = ((stage_v_369 * 3) + pub_r001362_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_526) & 255;
    out_sink = (out_sink + stage_v_526 * 2) & 255;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = ((stage_v_364 * 3) + pub_r001362_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_527) & 255;
    out_sink = (out_sink + stage_v_527 * 2) & 255;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001362_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = ((stage_v_108 * 3) + pub_r001362_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_529) & 255;
    out_sink = (out_sink + stage_v_529 * 2) & 255;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001362_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = (pub_r001362_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_531) & 127;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = (pub_r001362_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_532) & 127;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = (pub_r001362_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_533) & 127;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = ((stage_v_349 * 3) + pub_r001362_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_534) & 255;
    out_sink = (out_sink + stage_v_534 * 2) & 255;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = (pub_r001362_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_535) & 127;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = ((stage_v_172 * 3) + pub_r001362_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_536) & 255;
    out_sink = (out_sink + stage_v_536 * 2) & 255;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = (pub_r001362_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_537) & 127;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = ((sec_r001362_7 * 3) + pub_r001362_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_538) & 255;
    out_sink = (out_sink + stage_v_538 * 2) & 255;

    /* Execution Pipeline Stage 539 */
    int stage_v_539 = (pub_r001362_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_539) & 127;

    /* Execution Pipeline Stage 540 */
    int stage_v_540 = (pub_r001362_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_540) & 127;

    /* Execution Pipeline Stage 541 */
    int stage_v_541 = (pub_r001362_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_541) & 127;

    /* Execution Pipeline Stage 542 */
    int stage_v_542 = (pub_r001362_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_542) & 127;

    /* Execution Pipeline Stage 543 */
    int stage_v_543 = (pub_r001362_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_543) & 127;

    /* Execution Pipeline Stage 544 */
    int stage_v_544 = (pub_r001362_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_544) & 127;

    /* Execution Pipeline Stage 545 */
    int stage_v_545 = (pub_r001362_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_545) & 127;

    /* Execution Pipeline Stage 546 */
    int stage_v_546 = ((stage_v_233 * 3) + pub_r001362_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_546) & 255;
    out_sink = (out_sink + stage_v_546 * 2) & 255;

    /* Execution Pipeline Stage 547 */
    int stage_v_547 = ((stage_v_145 * 3) + pub_r001362_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_547) & 255;
    out_sink = (out_sink + stage_v_547 * 2) & 255;

    /* Execution Pipeline Stage 548 */
    int stage_v_548 = (pub_r001362_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_548) & 127;

    /* Execution Pipeline Stage 549 */
    int stage_v_549 = ((stage_v_307 * 3) + pub_r001362_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_549) & 255;
    out_sink = (out_sink + stage_v_549 * 2) & 255;

    /* Execution Pipeline Stage 550 */
    int stage_v_550 = ((stage_v_395 * 3) + pub_r001362_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_550) & 255;
    out_sink = (out_sink + stage_v_550 * 2) & 255;

    /* Execution Pipeline Stage 551 */
    int stage_v_551 = (pub_r001362_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_551) & 127;

    /* Execution Pipeline Stage 552 */
    int stage_v_552 = (pub_r001362_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_552) & 127;

    /* Execution Pipeline Stage 553 */
    int stage_v_553 = (pub_r001362_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_553) & 127;

    /* Execution Pipeline Stage 554 */
    int stage_v_554 = (pub_r001362_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_554) & 127;

    /* Execution Pipeline Stage 555 */
    int stage_v_555 = ((stage_v_182 * 3) + pub_r001362_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_555) & 255;
    out_sink = (out_sink + stage_v_555 * 2) & 255;

    /* Execution Pipeline Stage 556 */
    int stage_v_556 = (pub_r001362_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_556) & 127;

    /* Execution Pipeline Stage 557 */
    int stage_v_557 = (pub_r001362_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_557) & 127;

    /* Execution Pipeline Stage 558 */
    int stage_v_558 = ((stage_v_243 * 3) + pub_r001362_19 + 6) & 127;
    sec_accum = (sec_accum + stage_v_558) & 255;
    out_sink = (out_sink + stage_v_558 * 2) & 255;

    /* Execution Pipeline Stage 559 */
    int stage_v_559 = ((stage_v_201 * 3) + pub_r001362_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_559) & 255;
    out_sink = (out_sink + stage_v_559 * 2) & 255;

    /* Execution Pipeline Stage 560 */
    int stage_v_560 = (pub_r001362_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_560) & 127;

    /* Execution Pipeline Stage 561 */
    int stage_v_561 = (pub_r001362_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_561) & 127;

    /* Execution Pipeline Stage 562 */
    int stage_v_562 = (pub_r001362_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_562) & 127;

    /* Execution Pipeline Stage 563 */
    int stage_v_563 = ((stage_v_491 * 3) + pub_r001362_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_563) & 255;
    out_sink = (out_sink + stage_v_563 * 2) & 255;

    /* Execution Pipeline Stage 564 */
    int stage_v_564 = ((stage_v_111 * 3) + pub_r001362_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_564) & 255;
    out_sink = (out_sink + stage_v_564 * 2) & 255;

    /* Execution Pipeline Stage 565 */
    int stage_v_565 = ((stage_v_334 * 3) + pub_r001362_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_565) & 255;
    out_sink = (out_sink + stage_v_565 * 2) & 255;

    /* Execution Pipeline Stage 566 */
    int stage_v_566 = (pub_r001362_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_566) & 127;

    /* Execution Pipeline Stage 567 */
    int stage_v_567 = (pub_r001362_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_567) & 127;

    /* Execution Pipeline Stage 568 */
    int stage_v_568 = ((stage_v_152 * 3) + pub_r001362_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_568) & 255;
    out_sink = (out_sink + stage_v_568 * 2) & 255;

    /* Execution Pipeline Stage 569 */
    int stage_v_569 = (pub_r001362_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_569) & 127;

    /* Execution Pipeline Stage 570 */
    int stage_v_570 = (pub_r001362_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_570) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
