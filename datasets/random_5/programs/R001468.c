/*
 * Benchmark Program: R001468
 * Security Family: secret_dependent_loops
 * Generator Seed: 646813
 * High Inputs: 22 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001468_6813_0 {
    int damping;
    short mode;
    int prev_out;
    int gain_db;
    int cutoff;
    int prev_in;
    int buffer[3];
};

struct Transaction_R001468_6813_1 {
    int fee;
    short balance;
    int account_id;
    unsigned char auth_code;
    int status;
    int rate;
    int buffer[3];
};

struct StreamBuffer_R001468_6813_2 {
    int capacity;
    int tail;
    int watermark;
    unsigned char state;
    unsigned char checksum;
    int buffer[3];
};

struct Vector3D_R001468_6813_3 {
    int coord_y;
    int norm_sq;
    int pitch;
    int heading;
    int buffer[3];
};

union ColorPixel_R001468_6813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001468_6813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001468_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int coefficient_18 = local_arr[aux % 3];
    acc = (acc + coefficient_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001468_6813_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001468_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int damping_60 = local_arr[aux % 3];
    acc = (acc + damping_60 * 2) & 127;
    int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_84) & 63;
    acc ^= aux;
    int pivot_14 = (aux + st.buffer[1]) & 3;
    switch (pivot_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_2(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_32 = (aux + st.buffer[1]) & 3;
    switch (factor_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_42 = local_arr[aux % 3];
    acc = (acc + phase_42 * 2) & 127;
    int tracker_64 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_64 = (tracker_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_3(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tally_85 = (aux + st.buffer[1]) & 3;
    switch (tally_85) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_26 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_26 > 23) {
        acc = (acc + cursor_26 * 2 + 5) & 127;
        aux ^= (cursor_26 & 15);
    } else {
        acc = (acc - cursor_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int segment_54 = (aux + st.buffer[1]) & 3;
    switch (segment_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_69 > 47) {
        acc = (acc + anchor_69 * 2 + 5) & 127;
        aux ^= (anchor_69 & 15);
    } else {
        acc = (acc - anchor_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_5(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_31 = local_arr[aux % 3];
    acc = (acc + mask_31 * 2) & 127;
    int stride_18 = (aux + st.buffer[1]) & 3;
    switch (stride_18) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001468_6813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int coefficient_31 = (aux + st.buffer[1]) & 3;
    switch (coefficient_31) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_85 = local_arr[aux % 3];
    acc = (acc + metric_85 * 2) & 127;
    int accumulator_31 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_31 > 42) {
        acc = (acc + accumulator_31 * 2 + 5) & 127;
        aux ^= (accumulator_31 & 15);
    } else {
        acc = (acc - accumulator_31 + 11) & 127;
        aux += 3;
    }
    int index_reg_98 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_98 = (index_reg_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_98) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001468_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_41 = local_arr[aux % 3];
    acc = (acc + metric_41 * 2) & 127;
    int sample_63 = 0;
    for (int k = 0; k < 2; k++) {
        sample_63 = (sample_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_63) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_90) & 63;
    acc ^= aux;
    int anchor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_31 > 23) {
        acc = (acc + anchor_31 * 2 + 5) & 127;
        aux ^= (anchor_31 & 15);
    } else {
        acc = (acc - anchor_31 + 11) & 127;
        aux += 3;
    }
    int offset_58 = 0;
    for (int k = 0; k < 2; k++) {
        offset_58 = (offset_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001468_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int damping_76 = local_arr[aux % 3];
    acc = (acc + damping_76 * 2) & 127;
    int offset_92 = 0;
    for (int k = 0; k < 3; k++) {
        offset_92 = (offset_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_92) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_10(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001468_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_70 = 0;
    for (int k = 0; k < 3; k++) {
        factor_70 = (factor_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_70) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_54 = local_arr[aux % 3];
    acc = (acc + vector_54 * 2) & 127;
    int coefficient_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_57) & 63;
    acc ^= aux;
    int residue_65 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_65 > 33) {
        acc = (acc + residue_65 * 2 + 5) & 127;
        aux ^= (residue_65 & 15);
    } else {
        acc = (acc - residue_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_11(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001468_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int pivot_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_32) & 63;
    acc ^= aux;
    int pivot_80 = (aux + st.buffer[1]) & 3;
    switch (pivot_80) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_80 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_80 > 20) {
        acc = (acc + checksum_80 * 2 + 5) & 127;
        aux ^= (checksum_80 & 15);
    } else {
        acc = (acc - checksum_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_55 = 0;
    for (int k = 0; k < 2; k++) {
        metric_55 = (metric_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_13(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int segment_53 = local_arr[aux % 3];
    acc = (acc + segment_53 * 2) & 127;
    int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_16) & 63;
    acc ^= aux;
    int segment_31 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_31 > 33) {
        acc = (acc + segment_31 * 2 + 5) & 127;
        aux ^= (segment_31 & 15);
    } else {
        acc = (acc - segment_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001468_6813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int stride_88 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_88 > 38) {
        acc = (acc + stride_88 * 2 + 5) & 127;
        aux ^= (stride_88 & 15);
    } else {
        acc = (acc - stride_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_57 = 0;
    for (int k = 0; k < 3; k++) {
        phase_57 = (phase_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_57) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_50 = local_arr[aux % 3];
    acc = (acc + damping_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001468_6813_15(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001468_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_84 = 0;
    for (int k = 0; k < 3; k++) {
        window_84 = (window_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_84) & 127;
    }
    int metric_68 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_68 > 38) {
        acc = (acc + metric_68 * 2 + 5) & 127;
        aux ^= (metric_68 & 15);
    } else {
        acc = (acc - metric_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001468_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_45 = (aux + st.buffer[1]) & 3;
    switch (threshold_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_44 = local_arr[aux % 3];
    acc = (acc + threshold_44 * 2) & 127;
    int phase_21 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_21 > 44) {
        acc = (acc + phase_21 * 2 + 5) & 127;
        aux ^= (phase_21 & 15);
    } else {
        acc = (acc - phase_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001468_6813_17(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001468_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_35 = (aux + st.buffer[1]) & 3;
    switch (mask_35) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_84 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_84 = (quantum_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_84) & 127;
    }
    int offset_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001468_0;
    int sec_r001468_1;
    int sec_r001468_2;
    int sec_r001468_3;
    int sec_r001468_4;
    int sec_r001468_5;
    int sec_r001468_6;
    int sec_r001468_7;
    int sec_r001468_8;
    int sec_r001468_9;
    int sec_r001468_10;
    int sec_r001468_11;
    int sec_r001468_12;
    int sec_r001468_13;
    int sec_r001468_14;
    int sec_r001468_15;
    int sec_r001468_16;
    int sec_r001468_17;
    int sec_r001468_18;
    int sec_r001468_19;
    int sec_r001468_20;
    int sec_r001468_21;
    int pub_r001468_0;
    int pub_r001468_1;
    int pub_r001468_2;
    int pub_r001468_3;
    int pub_r001468_4;
    int pub_r001468_5;
    int pub_r001468_6;
    int pub_r001468_7;
    int pub_r001468_8;
    int pub_r001468_9;
    int pub_r001468_10;
    int pub_r001468_11;
    int pub_r001468_12;
    int pub_r001468_13;
    int pub_r001468_14;
    int pub_r001468_15;
    int pub_r001468_16;
    int pub_r001468_17;
    int pub_r001468_18;
    int pub_r001468_19;
    int pub_r001468_20;
    int pub_r001468_21;
    int pub_r001468_22;
    int pub_r001468_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001468_0 >= -100 && pub_r001468_0 <= 100);
    __CPROVER_assume(pub_r001468_1 >= -100 && pub_r001468_1 <= 100);
    __CPROVER_assume(pub_r001468_2 >= -100 && pub_r001468_2 <= 100);
    __CPROVER_assume(pub_r001468_3 >= -100 && pub_r001468_3 <= 100);
    __CPROVER_assume(pub_r001468_4 >= -100 && pub_r001468_4 <= 100);
    __CPROVER_assume(pub_r001468_5 >= -100 && pub_r001468_5 <= 100);
    __CPROVER_assume(pub_r001468_6 >= -100 && pub_r001468_6 <= 100);
    __CPROVER_assume(pub_r001468_7 >= -100 && pub_r001468_7 <= 100);
    __CPROVER_assume(pub_r001468_8 >= -100 && pub_r001468_8 <= 100);
    __CPROVER_assume(pub_r001468_9 >= -100 && pub_r001468_9 <= 100);
    __CPROVER_assume(pub_r001468_10 >= -100 && pub_r001468_10 <= 100);
    __CPROVER_assume(pub_r001468_11 >= -100 && pub_r001468_11 <= 100);
    __CPROVER_assume(pub_r001468_12 >= -100 && pub_r001468_12 <= 100);
    __CPROVER_assume(pub_r001468_13 >= -100 && pub_r001468_13 <= 100);
    __CPROVER_assume(pub_r001468_14 >= -100 && pub_r001468_14 <= 100);
    __CPROVER_assume(pub_r001468_15 >= -100 && pub_r001468_15 <= 100);
    __CPROVER_assume(pub_r001468_16 >= -100 && pub_r001468_16 <= 100);
    __CPROVER_assume(pub_r001468_17 >= -100 && pub_r001468_17 <= 100);
    __CPROVER_assume(pub_r001468_18 >= -100 && pub_r001468_18 <= 100);
    __CPROVER_assume(pub_r001468_19 >= -100 && pub_r001468_19 <= 100);
    __CPROVER_assume(pub_r001468_20 >= -100 && pub_r001468_20 <= 100);
    __CPROVER_assume(pub_r001468_21 >= -100 && pub_r001468_21 <= 100);
    __CPROVER_assume(pub_r001468_22 >= -100 && pub_r001468_22 <= 100);
    __CPROVER_assume(pub_r001468_23 >= -100 && pub_r001468_23 <= 100);
    __CPROVER_assume(sec_r001468_0 >= 0 && sec_r001468_0 <= 255);
    __CPROVER_assume(sec_r001468_1 >= 0 && sec_r001468_1 <= 255);
    __CPROVER_assume(sec_r001468_2 >= 0 && sec_r001468_2 <= 255);
    __CPROVER_assume(sec_r001468_3 >= 0 && sec_r001468_3 <= 255);
    __CPROVER_assume(sec_r001468_4 >= 0 && sec_r001468_4 <= 255);
    __CPROVER_assume(sec_r001468_5 >= 0 && sec_r001468_5 <= 255);
    __CPROVER_assume(sec_r001468_6 >= 0 && sec_r001468_6 <= 255);
    __CPROVER_assume(sec_r001468_7 >= 0 && sec_r001468_7 <= 255);
    __CPROVER_assume(sec_r001468_8 >= 0 && sec_r001468_8 <= 255);
    __CPROVER_assume(sec_r001468_9 >= 0 && sec_r001468_9 <= 255);
    __CPROVER_assume(sec_r001468_10 >= 0 && sec_r001468_10 <= 255);
    __CPROVER_assume(sec_r001468_11 >= 0 && sec_r001468_11 <= 255);
    __CPROVER_assume(sec_r001468_12 >= 0 && sec_r001468_12 <= 255);
    __CPROVER_assume(sec_r001468_13 >= 0 && sec_r001468_13 <= 255);
    __CPROVER_assume(sec_r001468_14 >= 0 && sec_r001468_14 <= 255);
    __CPROVER_assume(sec_r001468_15 >= 0 && sec_r001468_15 <= 255);
    __CPROVER_assume(sec_r001468_16 >= 0 && sec_r001468_16 <= 255);
    __CPROVER_assume(sec_r001468_17 >= 0 && sec_r001468_17 <= 255);
    __CPROVER_assume(sec_r001468_18 >= 0 && sec_r001468_18 <= 255);
    __CPROVER_assume(sec_r001468_19 >= 0 && sec_r001468_19 <= 255);
    __CPROVER_assume(sec_r001468_20 >= 0 && sec_r001468_20 <= 255);
    __CPROVER_assume(sec_r001468_21 >= 0 && sec_r001468_21 <= 255);

    struct FilterState_R001468_6813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001468_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001468_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001468_0 + 7) & 15;
    struct Transaction_R001468_6813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001468_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001468_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001468_0 + 9) & 15;
    struct StreamBuffer_R001468_6813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001468_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001468_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001468_0 + 11) & 15;
    struct Vector3D_R001468_6813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001468_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001468_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001468_0 + 13) & 15;

    union ColorPixel_R001468_6813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001468_6813_0(sec_r001468_0, sec_r001468_1, pub_r001468_2, pub_r001468_3, pub_r001468_4);
    int helper_flow_1 = fn_R001468_6813_1(sec_r001468_1, pub_r001468_2, pub_r001468_3);
    int helper_flow_2 = fn_R001468_6813_2(sec_r001468_2, pub_r001468_3, pub_r001468_4);
    int helper_flow_3 = fn_R001468_6813_3(sec_r001468_3, sec_r001468_4);
    int helper_flow_4 = fn_R001468_6813_4(sec_r001468_4, sec_r001468_5, pub_r001468_6, pub_r001468_7, pub_r001468_8);
    int helper_flow_5 = fn_R001468_6813_5(sec_r001468_5, pub_r001468_6);
    int helper_flow_6 = fn_R001468_6813_6(sec_r001468_6, pub_r001468_7, pub_r001468_8, pub_r001468_9, pub_r001468_10);
    int helper_flow_7 = fn_R001468_6813_7(sec_r001468_7, pub_r001468_8, pub_r001468_9, pub_r001468_10, pub_r001468_11);
    int helper_flow_8 = fn_R001468_6813_8(sec_r001468_8, sec_r001468_9, pub_r001468_10, pub_r001468_11);
    int helper_flow_9 = fn_R001468_6813_9(sec_r001468_9, sec_r001468_10, pub_r001468_11, pub_r001468_12, pub_r001468_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (sec_r001468_7 & 15)) & 63;
        if ((sec_r001468_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001468_3 & 15)) & 63;
        if ((sec_r001468_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001468_1 & 15)) & 63;
        if ((sec_r001468_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001468_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_4 = (stage_v_4 + it * 3 + (sec_r001468_15 & 15)) & 63;
        if ((sec_r001468_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_4 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_4 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001468_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (sec_r001468_10 & 15)) & 63;
        if ((sec_r001468_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001468_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (sec_r001468_1 & 15)) & 63;
        if ((sec_r001468_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (sec_r001468_13 & 15)) & 63;
        if ((sec_r001468_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (sec_r001468_5 & 15)) & 63;
        if ((sec_r001468_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001468_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001468_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001468_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (sec_r001468_17 & 15)) & 63;
        if ((sec_r001468_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001468_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001468_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001468_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001468_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (sec_r001468_15 & 15)) & 63;
        if ((sec_r001468_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (stage_v_29 & 15)) & 63;
        if ((stage_v_29 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_33 = (stage_v_33 + it * 3 + (sec_r001468_21 & 15)) & 63;
        if ((sec_r001468_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_33 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_33 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001468_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001468_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (sec_r001468_1 & 15)) & 63;
        if ((sec_r001468_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001468_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001468_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001468_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (sec_r001468_11 & 15)) & 63;
        if ((sec_r001468_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001468_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (sec_r001468_2 & 15)) & 63;
        if ((sec_r001468_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001468_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (stage_v_4 & 15)) & 63;
        if ((stage_v_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001468_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001468_21 & 15)) & 63;
        if ((sec_r001468_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (sec_r001468_20 & 15)) & 63;
        if ((sec_r001468_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_50 = (stage_v_50 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_50 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_50 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (stage_v_9 & 15)) & 63;
        if ((stage_v_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_52 = (stage_v_52 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_52 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_52 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001468_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001468_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (sec_r001468_20 & 15)) & 63;
        if ((sec_r001468_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_62 = (stage_v_62 + it * 3 + (sec_r001468_5 & 15)) & 63;
        if ((sec_r001468_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_62 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_62 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_63 = (stage_v_63 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_63 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_63 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (stage_v_52 & 15)) & 63;
        if ((stage_v_52 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001468_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001468_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001468_23 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001468_22 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (sec_r001468_1 & 15)) & 63;
        if ((sec_r001468_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (sec_r001468_18 & 15)) & 63;
        if ((sec_r001468_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001468_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001468_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001468_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001468_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001468_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001468_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (stage_v_71 & 15)) & 63;
        if ((stage_v_71 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (sec_r001468_2 & 15)) & 63;
        if ((sec_r001468_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_86 = (stage_v_86 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_86 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_86 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001468_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001468_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001468_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001468_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001468_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (sec_r001468_16 & 15)) & 63;
        if ((sec_r001468_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_96 = (stage_v_96 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_96 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_96 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001468_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_102 = (stage_v_102 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_102 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_102 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_95 & 15)) & 63;
        if ((stage_v_95 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001468_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_106 = (stage_v_106 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_106 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_106 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (sec_r001468_8 & 15)) & 63;
        if ((sec_r001468_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001468_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001468_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (sec_r001468_2 & 15)) & 63;
        if ((sec_r001468_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001468_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_113 = (stage_v_113 + it * 3 + (stage_v_80 & 15)) & 63;
        if ((stage_v_80 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_113 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_113 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (sec_r001468_17 & 15)) & 63;
        if ((sec_r001468_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001468_23 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (sec_r001468_17 & 15)) & 63;
        if ((sec_r001468_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001468_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (stage_v_118 & 15)) & 63;
        if ((stage_v_118 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_123 = (stage_v_123 + it * 3 + (stage_v_96 & 15)) & 63;
        if ((stage_v_96 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_123 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_123 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (sec_r001468_12 & 15)) & 63;
        if ((sec_r001468_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001468_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001468_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (sec_r001468_12 & 15)) & 63;
        if ((sec_r001468_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (sec_r001468_19 & 15)) & 63;
        if ((sec_r001468_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001468_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_136 = (stage_v_136 + it * 3 + (stage_v_111 & 15)) & 63;
        if ((stage_v_111 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_136 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_136 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (sec_r001468_21 & 15)) & 63;
        if ((sec_r001468_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_104 & 15)) & 63;
        if ((stage_v_104 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (stage_v_135 & 15)) & 63;
        if ((stage_v_135 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_141 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_141 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001468_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001468_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_145 = (stage_v_145 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_145 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_145 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001468_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (stage_v_139 & 15)) & 63;
        if ((stage_v_139 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001468_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_126 & 15)) & 63;
        if ((stage_v_126 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001468_20 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001468_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001468_21 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (sec_r001468_17 & 15)) & 63;
        if ((sec_r001468_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001468_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_159 = (stage_v_159 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_159 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_159 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (sec_r001468_14 & 15)) & 63;
        if ((sec_r001468_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_116 & 15)) & 63;
        if ((stage_v_116 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_96 & 15)) & 63;
        if ((stage_v_96 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001468_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001468_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (sec_r001468_15 & 15)) & 63;
        if ((sec_r001468_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001468_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_170 = (stage_v_170 + it * 3 + (sec_r001468_4 & 15)) & 63;
        if ((sec_r001468_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_170 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_170 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001468_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001468_23 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001468_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001468_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (stage_v_134 & 15)) & 63;
        if ((stage_v_134 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (stage_v_119 & 15)) & 63;
        if ((stage_v_119 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_127 & 15)) & 63;
        if ((stage_v_127 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_29 & 15)) & 63;
        if ((stage_v_29 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_160 & 15)) & 63;
        if ((stage_v_160 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (stage_v_50 & 15)) & 63;
        if ((stage_v_50 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001468_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_139 & 15)) & 63;
        if ((stage_v_139 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001468_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001468_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_194 = (stage_v_194 + it * 3 + (stage_v_138 & 15)) & 63;
        if ((stage_v_138 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_194 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_194 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001468_22 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001468_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_198 = (stage_v_198 + it * 3 + (stage_v_189 & 15)) & 63;
        if ((stage_v_189 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_198 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_198 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (stage_v_125 & 15)) & 63;
        if ((stage_v_125 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001468_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001468_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001468_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_203 = (stage_v_203 + it * 3 + (stage_v_102 & 15)) & 63;
        if ((stage_v_102 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_203 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_203 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001468_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_207 = (stage_v_207 + it * 3 + (stage_v_190 & 15)) & 63;
        if ((stage_v_190 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_207 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_207 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
