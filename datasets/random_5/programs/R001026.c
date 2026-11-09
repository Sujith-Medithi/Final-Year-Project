/*
 * Benchmark Program: R001026
 * Security Family: implicit_flow
 * Generator Seed: 602613
 * High Inputs: 18 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001026_2613_0 {
    int fee;
    unsigned char account_id;
    unsigned char rate;
    short auth_code;
    int balance;
    int buffer[3];
};

struct StreamBuffer_R001026_2613_1 {
    unsigned char state;
    int head;
    int watermark;
    int buffer[3];
};

struct Vector3D_R001026_2613_2 {
    int pitch;
    int coord_y;
    unsigned char coord_x;
    unsigned char norm_sq;
    int buffer[3];
};

union ColorPixel_R001026_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001026_2613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001026_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tracker_60 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_60 > 30) {
        acc = (acc + tracker_60 * 2 + 5) & 127;
        aux ^= (tracker_60 & 15);
    } else {
        acc = (acc - tracker_60 + 11) & 127;
        aux += 3;
    }
    int checksum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_89) & 63;
    acc ^= aux;
    int cursor_55 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_55 = (cursor_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_55) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_1(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_92 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_92 > 47) {
        acc = (acc + pivot_92 * 2 + 5) & 127;
        aux ^= (pivot_92 & 15);
    } else {
        acc = (acc - pivot_92 + 11) & 127;
        aux += 3;
    }
    int factor_13 = 0;
    for (int k = 0; k < 2; k++) {
        factor_13 = (factor_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_33 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_33 = (coefficient_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_33) & 127;
    }
    int metric_85 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_85 > 22) {
        acc = (acc + metric_85 * 2 + 5) & 127;
        aux ^= (metric_85 & 15);
    } else {
        acc = (acc - metric_85 + 11) & 127;
        aux += 3;
    }
    int segment_46 = (aux + st.buffer[1]) & 3;
    switch (segment_46) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_3(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_31) & 63;
    acc ^= aux;
    int quantum_99 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_99 > 12) {
        acc = (acc + quantum_99 * 2 + 5) & 127;
        aux ^= (quantum_99 & 15);
    } else {
        acc = (acc - quantum_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int phase_54 = (aux + st.buffer[1]) & 3;
    switch (phase_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_27 = local_arr[aux % 3];
    acc = (acc + damping_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_5(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_17) & 63;
    acc ^= aux;
    int residue_79 = (aux + st.buffer[1]) & 3;
    switch (residue_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_47 = local_arr[aux % 3];
    acc = (acc + checksum_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_6(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_41 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_41 = (quantum_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_41) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_84 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_84 > 11) {
        acc = (acc + coefficient_84 * 2 + 5) & 127;
        aux ^= (coefficient_84 & 15);
    } else {
        acc = (acc - coefficient_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_33) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_21 = 0;
    for (int k = 0; k < 3; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    int residue_92 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_92 > 49) {
        acc = (acc + residue_92 * 2 + 5) & 127;
        aux ^= (residue_92 & 15);
    } else {
        acc = (acc - residue_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_8(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int tracker_78 = local_arr[aux % 3];
    acc = (acc + tracker_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int metric_27 = 0;
    for (int k = 0; k < 3; k++) {
        metric_27 = (metric_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_27) & 127;
    }
    int damping_66 = (aux + st.buffer[1]) & 3;
    switch (damping_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_25 = local_arr[aux % 3];
    acc = (acc + index_reg_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int mask_14 = (aux + st.buffer[1]) & 3;
    switch (mask_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_34 = local_arr[aux % 3];
    acc = (acc + quotient_34 * 2) & 127;
    int phase_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001026_2613_12(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001026_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_25 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_25 > 20) {
        acc = (acc + mask_25 * 2 + 5) & 127;
        aux ^= (mask_25 & 15);
    } else {
        acc = (acc - mask_25 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_90 = local_arr[aux % 3];
    acc = (acc + accumulator_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001026_2613_13(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int window_16 = local_arr[aux % 3];
    acc = (acc + window_16 * 2) & 127;
    int cursor_47 = (aux + st.buffer[1]) & 3;
    switch (cursor_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_29 > 23) {
        acc = (acc + factor_29 * 2 + 5) & 127;
        aux ^= (factor_29 & 15);
    } else {
        acc = (acc - factor_29 + 11) & 127;
        aux += 3;
    }
    int threshold_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001026_2613_14(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001026_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_86 = 0;
    for (int k = 0; k < 3; k++) {
        window_86 = (window_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_86) & 127;
    }
    int residue_72 = (aux + st.buffer[1]) & 3;
    switch (residue_72) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001026_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_60 = 0;
    for (int k = 0; k < 3; k++) {
        damping_60 = (damping_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_60) & 127;
    }
    int sample_29 = (aux + st.buffer[1]) & 3;
    switch (sample_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001026_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_80) & 63;
    acc ^= aux;
    int cursor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_77 > 13) {
        acc = (acc + cursor_77 * 2 + 5) & 127;
        aux ^= (cursor_77 & 15);
    } else {
        acc = (acc - cursor_77 + 11) & 127;
        aux += 3;
    }
    int scale_58 = 0;
    for (int k = 0; k < 2; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001026_2613_17(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001026_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int delta_25 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_25 > 28) {
        acc = (acc + delta_25 * 2 + 5) & 127;
        aux ^= (delta_25 & 15);
    } else {
        acc = (acc - delta_25 + 11) & 127;
        aux += 3;
    }
    int checksum_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_60 = local_arr[aux % 3];
    acc = (acc + index_reg_60 * 2) & 127;
    int tracker_37 = (aux + st.buffer[1]) & 3;
    switch (tracker_37) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001026_0;
    int sec_r001026_1;
    int sec_r001026_2;
    int sec_r001026_3;
    int sec_r001026_4;
    int sec_r001026_5;
    int sec_r001026_6;
    int sec_r001026_7;
    int sec_r001026_8;
    int sec_r001026_9;
    int sec_r001026_10;
    int sec_r001026_11;
    int sec_r001026_12;
    int sec_r001026_13;
    int sec_r001026_14;
    int sec_r001026_15;
    int sec_r001026_16;
    int sec_r001026_17;
    int pub_r001026_0;
    int pub_r001026_1;
    int pub_r001026_2;
    int pub_r001026_3;
    int pub_r001026_4;
    int pub_r001026_5;
    int pub_r001026_6;
    int pub_r001026_7;
    int pub_r001026_8;
    int pub_r001026_9;
    int pub_r001026_10;
    int pub_r001026_11;
    int pub_r001026_12;
    int pub_r001026_13;
    int pub_r001026_14;
    int pub_r001026_15;
    int pub_r001026_16;
    int pub_r001026_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001026_0 >= -100 && pub_r001026_0 <= 100);
    __CPROVER_assume(pub_r001026_1 >= -100 && pub_r001026_1 <= 100);
    __CPROVER_assume(pub_r001026_2 >= -100 && pub_r001026_2 <= 100);
    __CPROVER_assume(pub_r001026_3 >= -100 && pub_r001026_3 <= 100);
    __CPROVER_assume(pub_r001026_4 >= -100 && pub_r001026_4 <= 100);
    __CPROVER_assume(pub_r001026_5 >= -100 && pub_r001026_5 <= 100);
    __CPROVER_assume(pub_r001026_6 >= -100 && pub_r001026_6 <= 100);
    __CPROVER_assume(pub_r001026_7 >= -100 && pub_r001026_7 <= 100);
    __CPROVER_assume(pub_r001026_8 >= -100 && pub_r001026_8 <= 100);
    __CPROVER_assume(pub_r001026_9 >= -100 && pub_r001026_9 <= 100);
    __CPROVER_assume(pub_r001026_10 >= -100 && pub_r001026_10 <= 100);
    __CPROVER_assume(pub_r001026_11 >= -100 && pub_r001026_11 <= 100);
    __CPROVER_assume(pub_r001026_12 >= -100 && pub_r001026_12 <= 100);
    __CPROVER_assume(pub_r001026_13 >= -100 && pub_r001026_13 <= 100);
    __CPROVER_assume(pub_r001026_14 >= -100 && pub_r001026_14 <= 100);
    __CPROVER_assume(pub_r001026_15 >= -100 && pub_r001026_15 <= 100);
    __CPROVER_assume(pub_r001026_16 >= -100 && pub_r001026_16 <= 100);
    __CPROVER_assume(pub_r001026_17 >= -100 && pub_r001026_17 <= 100);
    __CPROVER_assume(sec_r001026_0 >= 0 && sec_r001026_0 <= 255);
    __CPROVER_assume(sec_r001026_1 >= 0 && sec_r001026_1 <= 255);
    __CPROVER_assume(sec_r001026_2 >= 0 && sec_r001026_2 <= 255);
    __CPROVER_assume(sec_r001026_3 >= 0 && sec_r001026_3 <= 255);
    __CPROVER_assume(sec_r001026_4 >= 0 && sec_r001026_4 <= 255);
    __CPROVER_assume(sec_r001026_5 >= 0 && sec_r001026_5 <= 255);
    __CPROVER_assume(sec_r001026_6 >= 0 && sec_r001026_6 <= 255);
    __CPROVER_assume(sec_r001026_7 >= 0 && sec_r001026_7 <= 255);
    __CPROVER_assume(sec_r001026_8 >= 0 && sec_r001026_8 <= 255);
    __CPROVER_assume(sec_r001026_9 >= 0 && sec_r001026_9 <= 255);
    __CPROVER_assume(sec_r001026_10 >= 0 && sec_r001026_10 <= 255);
    __CPROVER_assume(sec_r001026_11 >= 0 && sec_r001026_11 <= 255);
    __CPROVER_assume(sec_r001026_12 >= 0 && sec_r001026_12 <= 255);
    __CPROVER_assume(sec_r001026_13 >= 0 && sec_r001026_13 <= 255);
    __CPROVER_assume(sec_r001026_14 >= 0 && sec_r001026_14 <= 255);
    __CPROVER_assume(sec_r001026_15 >= 0 && sec_r001026_15 <= 255);
    __CPROVER_assume(sec_r001026_16 >= 0 && sec_r001026_16 <= 255);
    __CPROVER_assume(sec_r001026_17 >= 0 && sec_r001026_17 <= 255);

    struct Transaction_R001026_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001026_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001026_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001026_0 + 7) & 15;
    struct StreamBuffer_R001026_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001026_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001026_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001026_0 + 9) & 15;
    struct Vector3D_R001026_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001026_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001026_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001026_0 + 11) & 15;

    union ColorPixel_R001026_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001026_2613_0(sec_r001026_0, pub_r001026_1, pub_r001026_2, pub_r001026_3);
    int helper_flow_1 = fn_R001026_2613_1(sec_r001026_1, sec_r001026_2);
    int helper_flow_2 = fn_R001026_2613_2(sec_r001026_2, pub_r001026_3, pub_r001026_4, pub_r001026_5, pub_r001026_6);
    int helper_flow_3 = fn_R001026_2613_3(sec_r001026_3, sec_r001026_4);
    int helper_flow_4 = fn_R001026_2613_4(sec_r001026_4, pub_r001026_5, pub_r001026_6, pub_r001026_7, pub_r001026_8);
    int helper_flow_5 = fn_R001026_2613_5(sec_r001026_5, sec_r001026_6, pub_r001026_7);
    int helper_flow_6 = fn_R001026_2613_6(sec_r001026_6, sec_r001026_7, pub_r001026_8);
    int helper_flow_7 = fn_R001026_2613_7(sec_r001026_7, pub_r001026_8, pub_r001026_9, pub_r001026_10, pub_r001026_11);
    int helper_flow_8 = fn_R001026_2613_8(sec_r001026_8, pub_r001026_9);
    int helper_flow_9 = fn_R001026_2613_9(sec_r001026_9, pub_r001026_10, pub_r001026_11, pub_r001026_12);
    int helper_flow_10 = fn_R001026_2613_10(sec_r001026_10, pub_r001026_11, pub_r001026_12, pub_r001026_13, pub_r001026_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001026_6 + pub_r001026_1 * 2 + 5) & 127;
    if (stage_v_0 > 16) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001026_8 + pub_r001026_13 * 2 + 8) & 127;
    if (stage_v_1 > 35) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001026_6 + pub_r001026_13 * 2 + 11) & 127;
    if (stage_v_2 > 19) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001026_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_1 + pub_r001026_10 * 2 + 17) & 127;
    if (stage_v_4 > 33) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_1 + pub_r001026_2 * 2 + 20) & 127;
    if (stage_v_5 > 46) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001026_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_4 + pub_r001026_17 * 2 + 26) & 127;
    if (stage_v_7 > 44) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_5 + pub_r001026_10 * 2 + 29) & 127;
    if (stage_v_8 > 46) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001026_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001026_13 + pub_r001026_5 * 2 + 35) & 127;
    if (stage_v_10 > 15) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001026_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001026_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001026_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001026_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001026_8 + pub_r001026_2 * 2 + 50) & 127;
    if (stage_v_15 > 29) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001026_3 + pub_r001026_12 * 2 + 53) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001026_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_4 + pub_r001026_7 * 2 + 59) & 127;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_1 + pub_r001026_5 * 2 + 62) & 127;
    if (stage_v_19 > 20) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_7 + pub_r001026_3 * 2 + 65) & 127;
    if (stage_v_20 > 42) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001026_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001026_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001026_11 + pub_r001026_3 * 2 + 74) & 127;
    if (stage_v_23 > 39) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001026_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_8 + pub_r001026_0 * 2 + 80) & 127;
    if (stage_v_25 > 22) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001026_0 + pub_r001026_11 * 2 + 83) & 127;
    if (stage_v_26 > 30) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_19 + pub_r001026_14 * 2 + 86) & 127;
    if (stage_v_27 > 60) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001026_12 + pub_r001026_16 * 2 + 89) & 127;
    if (stage_v_28 > 56) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_7 + pub_r001026_15 * 2 + 92) & 127;
    if (stage_v_29 > 52) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_5 + pub_r001026_2 * 2 + 95) & 127;
    if (stage_v_30 > 18) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001026_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001026_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_29 + pub_r001026_14 * 2 + 104) & 127;
    if (stage_v_33 > 37) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001026_13 + pub_r001026_2 * 2 + 107) & 127;
    if (stage_v_34 > 55) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_19 + pub_r001026_7 * 2 + 110) & 127;
    if (stage_v_35 > 34) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001026_5 + pub_r001026_11 * 2 + 113) & 127;
    if (stage_v_36 > 39) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_34 + pub_r001026_11 * 2 + 116) & 127;
    if (stage_v_37 > 39) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001026_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_5 + pub_r001026_11 * 2 + 122) & 127;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_1 + pub_r001026_6 * 2 + 125) & 127;
    if (stage_v_40 > 47) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001026_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001026_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_9 + pub_r001026_15 * 2 + 134) & 127;
    if (stage_v_43 > 37) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001026_6 + pub_r001026_8 * 2 + 137) & 127;
    if (stage_v_44 > 53) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_10 + pub_r001026_17 * 2 + 140) & 127;
    if (stage_v_45 > 33) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_35 + pub_r001026_15 * 2 + 143) & 127;
    if (stage_v_46 > 29) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001026_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001026_16 + pub_r001026_5 * 2 + 149) & 127;
    if (stage_v_48 > 31) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_5 + pub_r001026_0 * 2 + 152) & 127;
    if (stage_v_49 > 22) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_36 + pub_r001026_9 * 2 + 155) & 127;
    if (stage_v_50 > 30) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001026_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001026_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_5 + pub_r001026_12 * 2 + 164) & 127;
    if (stage_v_53 > 24) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_30 + pub_r001026_4 * 2 + 167) & 127;
    if (stage_v_54 > 20) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_30 + pub_r001026_5 * 2 + 170) & 127;
    if (stage_v_55 > 32) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001026_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001026_8 + pub_r001026_17 * 2 + 176) & 127;
    if (stage_v_57 > 16) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001026_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_53 + pub_r001026_11 * 2 + 182) & 127;
    if (stage_v_59 > 54) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_46 + pub_r001026_12 * 2 + 185) & 127;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (helper_flow_5 + pub_r001026_5 * 2 + 188) & 127;
    if (stage_v_61 > 37) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_5 + pub_r001026_14 * 2 + 191) & 127;
    if (stage_v_62 > 56) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_0 + pub_r001026_8 * 2 + 194) & 127;
    if (stage_v_63 > 26) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_50 + pub_r001026_7 * 2 + 197) & 127;
    if (stage_v_64 > 46) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_15 + pub_r001026_3 * 2 + 200) & 127;
    if (stage_v_65 > 40) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_27 + pub_r001026_3 * 2 + 203) & 127;
    if (stage_v_66 > 21) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001026_6 + pub_r001026_0 * 2 + 206) & 127;
    if (stage_v_67 > 28) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_43 + pub_r001026_10 * 2 + 209) & 127;
    if (stage_v_68 > 25) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001026_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_57 + pub_r001026_8 * 2 + 215) & 127;
    if (stage_v_70 > 60) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001026_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_8 + pub_r001026_0 * 2 + 221) & 127;
    if (stage_v_72 > 46) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001026_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001026_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001026_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_34 + pub_r001026_16 * 2 + 233) & 127;
    if (stage_v_76 > 48) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_20 + pub_r001026_7 * 2 + 236) & 127;
    if (stage_v_77 > 20) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_37 + pub_r001026_2 * 2 + 239) & 127;
    if (stage_v_78 > 27) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001026_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001026_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001026_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001026_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_7 + pub_r001026_0 * 2 + 254) & 127;
    if (stage_v_83 > 59) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_68 + pub_r001026_14 * 2 + 257) & 127;
    if (stage_v_84 > 51) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_33 + pub_r001026_1 * 2 + 260) & 127;
    if (stage_v_85 > 47) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001026_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001026_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_23 + pub_r001026_2 * 2 + 269) & 127;
    if (stage_v_88 > 42) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (helper_flow_10 + pub_r001026_12 * 2 + 272) & 127;
    if (stage_v_89 > 32) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_55 + pub_r001026_3 * 2 + 275) & 127;
    if (stage_v_90 > 17) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_76 + pub_r001026_7 * 2 + 278) & 127;
    if (stage_v_91 > 32) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_19 + pub_r001026_10 * 2 + 281) & 127;
    if (stage_v_92 > 36) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001026_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_8 + pub_r001026_5 * 2 + 287) & 127;
    if (stage_v_94 > 31) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001026_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001026_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_70 + pub_r001026_0 * 2 + 296) & 127;
    if (stage_v_97 > 42) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001026_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_50 + pub_r001026_7 * 2 + 302) & 127;
    if (stage_v_99 > 43) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001026_16 + pub_r001026_1 * 2 + 305) & 127;
    if (stage_v_100 > 30) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001026_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001026_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001026_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_29 + pub_r001026_13 * 2 + 317) & 127;
    if (stage_v_104 > 25) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_68 + pub_r001026_15 * 2 + 320) & 127;
    if (stage_v_105 > 41) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001026_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_3 + pub_r001026_3 * 2 + 326) & 127;
    if (stage_v_107 > 50) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001026_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001026_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_91 + pub_r001026_6 * 2 + 335) & 127;
    if (stage_v_110 > 18) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_70 + pub_r001026_16 * 2 + 338) & 127;
    if (stage_v_111 > 51) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_49 + pub_r001026_2 * 2 + 341) & 127;
    if (stage_v_112 > 53) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001026_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_45 + pub_r001026_15 * 2 + 347) & 127;
    if (stage_v_114 > 35) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001026_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_4 + pub_r001026_15 * 2 + 353) & 127;
    if (stage_v_116 > 27) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001026_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001026_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_61 + pub_r001026_9 * 2 + 362) & 127;
    if (stage_v_119 > 28) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001026_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001026_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_36 + pub_r001026_10 * 2 + 371) & 127;
    if (stage_v_122 > 25) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_60 + pub_r001026_6 * 2 + 374) & 127;
    if (stage_v_123 > 31) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_70 + pub_r001026_7 * 2 + 377) & 127;
    if (stage_v_124 > 17) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001026_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (helper_flow_0 + pub_r001026_4 * 2 + 383) & 127;
    if (stage_v_126 > 29) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_30 + pub_r001026_13 * 2 + 386) & 127;
    if (stage_v_127 > 50) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001026_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001026_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001026_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_37 + pub_r001026_8 * 2 + 398) & 127;
    if (stage_v_131 > 19) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001026_0 + pub_r001026_12 * 2 + 401) & 127;
    if (stage_v_132 > 51) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_126 + pub_r001026_2 * 2 + 404) & 127;
    if (stage_v_133 > 39) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_15 + pub_r001026_9 * 2 + 407) & 127;
    if (stage_v_134 > 32) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001026_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_65 + pub_r001026_7 * 2 + 413) & 127;
    if (stage_v_136 > 51) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001026_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001026_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001026_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_50 + pub_r001026_8 * 2 + 425) & 127;
    if (stage_v_140 > 45) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_105 + pub_r001026_9 * 2 + 428) & 127;
    if (stage_v_141 > 28) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_85 + pub_r001026_17 * 2 + 431) & 127;
    if (stage_v_142 > 52) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_62 + pub_r001026_11 * 2 + 434) & 127;
    if (stage_v_143 > 47) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_29 + pub_r001026_1 * 2 + 437) & 127;
    if (stage_v_144 > 34) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001026_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_10 + pub_r001026_12 * 2 + 443) & 127;
    if (stage_v_146 > 25) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_140 + pub_r001026_4 * 2 + 446) & 127;
    if (stage_v_147 > 32) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001026_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_16 + pub_r001026_2 * 2 + 452) & 127;
    if (stage_v_149 > 44) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r001026_3 + pub_r001026_0 * 2 + 455) & 127;
    if (stage_v_150 > 31) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001026_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_142 + pub_r001026_14 * 2 + 461) & 127;
    if (stage_v_152 > 34) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_144 + pub_r001026_7 * 2 + 464) & 127;
    if (stage_v_153 > 56) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_44 + pub_r001026_10 * 2 + 467) & 127;
    if (stage_v_154 > 59) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001026_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001026_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001026_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_131 + pub_r001026_5 * 2 + 479) & 127;
    if (stage_v_158 > 56) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001026_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001026_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_111 + pub_r001026_1 * 2 + 488) & 127;
    if (stage_v_161 > 16) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001026_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001026_13 + pub_r001026_3 * 2 + 494) & 127;
    if (stage_v_163 > 25) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_85 + pub_r001026_17 * 2 + 497) & 127;
    if (stage_v_164 > 28) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001026_10 + pub_r001026_17 * 2 + 500) & 127;
    if (stage_v_165 > 56) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001026_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_36 + pub_r001026_12 * 2 + 506) & 127;
    if (stage_v_167 > 50) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001026_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_37 + pub_r001026_2 * 2 + 512) & 127;
    if (stage_v_169 > 41) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_28 + pub_r001026_9 * 2 + 515) & 127;
    if (stage_v_170 > 60) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_68 + pub_r001026_17 * 2 + 518) & 127;
    if (stage_v_171 > 59) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_77 + pub_r001026_0 * 2 + 521) & 127;
    if (stage_v_172 > 19) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001026_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (helper_flow_4 + pub_r001026_1 * 2 + 527) & 127;
    if (stage_v_174 > 44) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001026_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_60 + pub_r001026_15 * 2 + 533) & 127;
    if (stage_v_176 > 48) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001026_16 + pub_r001026_9 * 2 + 536) & 127;
    if (stage_v_177 > 26) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_122 + pub_r001026_7 * 2 + 539) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_50 + pub_r001026_16 * 2 + 542) & 127;
    if (stage_v_179 > 37) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001026_4 + pub_r001026_16 * 2 + 545) & 127;
    if (stage_v_180 > 60) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_132 + pub_r001026_6 * 2 + 548) & 127;
    if (stage_v_181 > 27) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_39 + pub_r001026_6 * 2 + 551) & 127;
    if (stage_v_182 > 20) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_158 + pub_r001026_0 * 2 + 554) & 127;
    if (stage_v_183 > 49) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001026_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001026_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_104 + pub_r001026_17 * 2 + 563) & 127;
    if (stage_v_186 > 60) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_1 + pub_r001026_11 * 2 + 566) & 127;
    if (stage_v_187 > 31) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_127 + pub_r001026_17 * 2 + 569) & 127;
    if (stage_v_188 > 41) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_28 + pub_r001026_0 * 2 + 572) & 127;
    if (stage_v_189 > 41) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_126 + pub_r001026_14 * 2 + 575) & 127;
    if (stage_v_190 > 20) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001026_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_60 + pub_r001026_2 * 2 + 581) & 127;
    if (stage_v_192 > 18) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_78 + pub_r001026_3 * 2 + 584) & 127;
    if (stage_v_193 > 53) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001026_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (helper_flow_7 + pub_r001026_14 * 2 + 590) & 127;
    if (stage_v_195 > 57) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001026_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_18 + pub_r001026_5 * 2 + 596) & 127;
    if (stage_v_197 > 22) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001026_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_45 + pub_r001026_13 * 2 + 602) & 127;
    if (stage_v_199 > 23) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001026_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001026_0 + pub_r001026_13 * 2 + 608) & 127;
    if (stage_v_201 > 38) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_170 + pub_r001026_10 * 2 + 611) & 127;
    if (stage_v_202 > 43) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001026_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_85 + pub_r001026_1 * 2 + 617) & 127;
    if (stage_v_204 > 42) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001026_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_8 + pub_r001026_14 * 2 + 623) & 127;
    if (stage_v_206 > 36) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001026_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_158 + pub_r001026_16 * 2 + 629) & 127;
    if (stage_v_208 > 18) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001026_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_7 + pub_r001026_10 * 2 + 635) & 127;
    if (stage_v_210 > 25) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_44 + pub_r001026_3 * 2 + 638) & 127;
    if (stage_v_211 > 34) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001026_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (helper_flow_7 + pub_r001026_11 * 2 + 644) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_105 + pub_r001026_6 * 2 + 647) & 127;
    if (stage_v_214 > 21) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (helper_flow_6 + pub_r001026_15 * 2 + 650) & 127;
    if (stage_v_215 > 31) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001026_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_144 + pub_r001026_0 * 2 + 656) & 127;
    if (stage_v_217 > 31) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001026_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (sec_r001026_13 + pub_r001026_10 * 2 + 662) & 127;
    if (stage_v_219 > 59) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_170 + pub_r001026_3 * 2 + 665) & 127;
    if (stage_v_220 > 57) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001026_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001026_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (sec_r001026_6 + pub_r001026_0 * 2 + 674) & 127;
    if (stage_v_223 > 27) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_66 + pub_r001026_4 * 2 + 677) & 127;
    if (stage_v_224 > 54) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001026_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_63 + pub_r001026_4 * 2 + 683) & 127;
    if (stage_v_226 > 36) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r001026_6 + pub_r001026_2 * 2 + 686) & 127;
    if (stage_v_227 > 44) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001026_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_131 + pub_r001026_16 * 2 + 692) & 127;
    if (stage_v_229 > 45) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_63 + pub_r001026_15 * 2 + 695) & 127;
    if (stage_v_230 > 26) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_66 + pub_r001026_17 * 2 + 698) & 127;
    if (stage_v_231 > 41) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (helper_flow_9 + pub_r001026_8 * 2 + 701) & 127;
    if (stage_v_232 > 33) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_172 + pub_r001026_7 * 2 + 704) & 127;
    if (stage_v_233 > 32) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_158 + pub_r001026_8 * 2 + 707) & 127;
    if (stage_v_234 > 19) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_167 + pub_r001026_13 * 2 + 710) & 127;
    if (stage_v_235 > 29) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001026_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_144 + pub_r001026_4 * 2 + 716) & 127;
    if (stage_v_237 > 45) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_44 + pub_r001026_14 * 2 + 719) & 127;
    if (stage_v_238 > 20) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_62 + pub_r001026_1 * 2 + 722) & 127;
    if (stage_v_239 > 15) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001026_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_90 + pub_r001026_3 * 2 + 728) & 127;
    if (stage_v_241 > 37) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_39 + pub_r001026_6 * 2 + 731) & 127;
    if (stage_v_242 > 57) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_55 + pub_r001026_5 * 2 + 734) & 127;
    if (stage_v_243 > 57) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_45 + pub_r001026_9 * 2 + 737) & 127;
    if (stage_v_244 > 32) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_7 + pub_r001026_0 * 2 + 740) & 127;
    if (stage_v_245 > 50) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_229 + pub_r001026_4 * 2 + 743) & 127;
    if (stage_v_246 > 42) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_114 + pub_r001026_14 * 2 + 746) & 127;
    if (stage_v_247 > 50) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_55 + pub_r001026_13 * 2 + 749) & 127;
    if (stage_v_248 > 30) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001026_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001026_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001026_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_1 + pub_r001026_14 * 2 + 761) & 127;
    if (stage_v_252 > 22) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_224 + pub_r001026_6 * 2 + 764) & 127;
    if (stage_v_253 > 35) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_112 + pub_r001026_10 * 2 + 767) & 127;
    if (stage_v_254 > 40) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_134 + pub_r001026_0 * 2 + 770) & 127;
    if (stage_v_255 > 56) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_64 + pub_r001026_7 * 2 + 773) & 127;
    if (stage_v_256 > 28) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001026_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_176 + pub_r001026_15 * 2 + 779) & 127;
    if (stage_v_258 > 31) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
        sec_accum ^= (stage_v_258 & 31);
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_163 + pub_r001026_17 * 2 + 782) & 127;
    if (stage_v_259 > 32) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
        sec_accum ^= (stage_v_259 & 31);
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_116 + pub_r001026_12 * 2 + 785) & 127;
    if (stage_v_260 > 24) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
        sec_accum ^= (stage_v_260 & 31);
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_111 + pub_r001026_14 * 2 + 788) & 127;
    if (stage_v_261 > 34) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
        sec_accum ^= (stage_v_261 & 31);
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (sec_r001026_0 + pub_r001026_1 * 2 + 791) & 127;
    if (stage_v_262 > 55) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
        sec_accum ^= (stage_v_262 & 31);
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001026_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001026_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_67 + pub_r001026_16 * 2 + 800) & 127;
    if (stage_v_265 > 34) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
        sec_accum ^= (stage_v_265 & 31);
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (stage_v_7 + pub_r001026_4 * 2 + 803) & 127;
    if (stage_v_266 > 41) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
        sec_accum ^= (stage_v_266 & 31);
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
