/*
 * Benchmark Program: R001308
 * Security Family: secret_dependent_loops
 * Generator Seed: 630813
 * High Inputs: 17 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001308_813_0 {
    int account_id;
    unsigned char balance;
    int auth_code;
    int rate;
    int status;
    int buffer[3];
};

struct StreamBuffer_R001308_813_1 {
    unsigned char head;
    int tail;
    int capacity;
    int buffer[3];
};

struct EventLog_R001308_813_2 {
    int code;
    short facility;
    int severity;
    int signature;
    int buffer[3];
};

union ColorPixel_R001308_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001308_813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001308_813_0(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_87 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_87 = (index_reg_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_87) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_24 = local_arr[aux % 3];
    acc = (acc + metric_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001308_813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_30 = 0;
    for (int k = 0; k < 3; k++) {
        mask_30 = (mask_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_30) & 127;
    }
    int window_57 = (st.buffer[0] * 3 + aux) & 63;
    if (window_57 > 27) {
        acc = (acc + window_57 * 2 + 5) & 127;
        aux ^= (window_57 & 15);
    } else {
        acc = (acc - window_57 + 11) & 127;
        aux += 3;
    }
    int parity_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001308_813_2(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_19 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_19 > 30) {
        acc = (acc + tally_19 * 2 + 5) & 127;
        aux ^= (tally_19 & 15);
    } else {
        acc = (acc - tally_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_94 = local_arr[aux % 3];
    acc = (acc + phase_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001308_813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int threshold_66 = local_arr[aux % 3];
    acc = (acc + threshold_66 * 2) & 127;
    int offset_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001308_813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_15 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_15 > 44) {
        acc = (acc + phase_15 * 2 + 5) & 127;
        aux ^= (phase_15 & 15);
    } else {
        acc = (acc - phase_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_73 = local_arr[aux % 3];
    acc = (acc + phase_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_93 = (aux + st.buffer[1]) & 3;
    switch (accumulator_93) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_5(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int index_reg_39 = local_arr[aux % 3];
    acc = (acc + index_reg_39 * 2) & 127;
    int index_reg_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001308_813_6(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int phase_80 = (aux + st.buffer[1]) & 3;
    switch (phase_80) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_47 = 0;
    for (int k = 0; k < 2; k++) {
        factor_47 = (factor_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_47) & 127;
    }
    int mask_47 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_47 > 22) {
        acc = (acc + mask_47 * 2 + 5) & 127;
        aux ^= (mask_47 & 15);
    } else {
        acc = (acc - mask_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_7(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_47 = 0;
    for (int k = 0; k < 2; k++) {
        stride_47 = (stride_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_47) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_86 = local_arr[aux % 3];
    acc = (acc + pivot_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_87 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_87 > 43) {
        acc = (acc + stride_87 * 2 + 5) & 127;
        aux ^= (stride_87 & 15);
    } else {
        acc = (acc - stride_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_48 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_48 > 27) {
        acc = (acc + phase_48 * 2 + 5) & 127;
        aux ^= (phase_48 & 15);
    } else {
        acc = (acc - phase_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_93 = local_arr[aux % 3];
    acc = (acc + phase_93 * 2) & 127;
    int bound_55 = (aux + st.buffer[1]) & 3;
    switch (bound_55) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_29 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_29 = (anchor_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_29) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_9(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_69 = 0;
    for (int k = 0; k < 2; k++) {
        vector_69 = (vector_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_69) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_36 = local_arr[aux % 3];
    acc = (acc + segment_36 * 2) & 127;
    int sample_29 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_29 > 11) {
        acc = (acc + sample_29 * 2 + 5) & 127;
        aux ^= (sample_29 & 15);
    } else {
        acc = (acc - sample_29 + 11) & 127;
        aux += 3;
    }
    int sample_50 = (aux + st.buffer[1]) & 3;
    switch (sample_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_10(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_98) & 63;
    acc ^= aux;
    int accumulator_72 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_72 = (accumulator_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_11(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_85 = (aux + st.buffer[1]) & 3;
    switch (mask_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_82) & 63;
    acc ^= aux;
    int cursor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_31 > 30) {
        acc = (acc + cursor_31 * 2 + 5) & 127;
        aux ^= (cursor_31 & 15);
    } else {
        acc = (acc - cursor_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_82 = 0;
    for (int k = 0; k < 2; k++) {
        tally_82 = (tally_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_82) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_86 = local_arr[aux % 3];
    acc = (acc + parity_86 * 2) & 127;
    int vector_57 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_57 > 44) {
        acc = (acc + vector_57 * 2 + 5) & 127;
        aux ^= (vector_57 & 15);
    } else {
        acc = (acc - vector_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_50 = (aux + st.buffer[1]) & 3;
    switch (vector_50) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_34) & 63;
    acc ^= aux;
    int offset_45 = 0;
    for (int k = 0; k < 2; k++) {
        offset_45 = (offset_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_14(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int threshold_41 = local_arr[aux % 3];
    acc = (acc + threshold_41 * 2) & 127;
    int pivot_42 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    int delta_93 = (aux + st.buffer[1]) & 3;
    switch (delta_93) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_53 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_53 > 15) {
        acc = (acc + cursor_53 * 2 + 5) & 127;
        aux ^= (cursor_53 & 15);
    } else {
        acc = (acc - cursor_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_28 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_28 > 36) {
        acc = (acc + offset_28 * 2 + 5) & 127;
        aux ^= (offset_28 & 15);
    } else {
        acc = (acc - offset_28 + 11) & 127;
        aux += 3;
    }
    int phase_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_87) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_50 = local_arr[aux % 3];
    acc = (acc + bound_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001308_813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int quotient_49 = local_arr[aux % 3];
    acc = (acc + quotient_49 * 2) & 127;
    int damping_14 = (aux + st.buffer[1]) & 3;
    switch (damping_14) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_69 = (aux + st.buffer[1]) & 3;
    switch (cursor_69) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001308_813_18(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_73 = (aux + st.buffer[1]) & 3;
    switch (quotient_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_50 = local_arr[aux % 3];
    acc = (acc + factor_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001308_813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int window_30 = local_arr[aux % 3];
    acc = (acc + window_30 * 2) & 127;
    int damping_38 = (aux + st.buffer[1]) & 3;
    switch (damping_38) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_49) & 63;
    acc ^= aux;
    int anchor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_19 > 36) {
        acc = (acc + anchor_19 * 2 + 5) & 127;
        aux ^= (anchor_19 & 15);
    } else {
        acc = (acc - anchor_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_20(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int bound_70 = local_arr[aux % 3];
    acc = (acc + bound_70 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_59 = 0;
    for (int k = 0; k < 2; k++) {
        bound_59 = (bound_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_70 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_70 > 48) {
        acc = (acc + segment_70 * 2 + 5) & 127;
        aux ^= (segment_70 & 15);
    } else {
        acc = (acc - segment_70 + 11) & 127;
        aux += 3;
    }
    int phase_93 = 0;
    for (int k = 0; k < 3; k++) {
        phase_93 = (phase_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001308_813_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_36 = (aux + st.buffer[1]) & 3;
    switch (checksum_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001308_813_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int damping_49 = 0;
    for (int k = 0; k < 3; k++) {
        damping_49 = (damping_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_49) & 127;
    }
    int stride_72 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_72 > 12) {
        acc = (acc + stride_72 * 2 + 5) & 127;
        aux ^= (stride_72 & 15);
    } else {
        acc = (acc - stride_72 + 11) & 127;
        aux += 3;
    }
    int delta_51 = (aux + st.buffer[1]) & 3;
    switch (delta_51) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001308_0;
    int sec_r001308_1;
    int sec_r001308_2;
    int sec_r001308_3;
    int sec_r001308_4;
    int sec_r001308_5;
    int sec_r001308_6;
    int sec_r001308_7;
    int sec_r001308_8;
    int sec_r001308_9;
    int sec_r001308_10;
    int sec_r001308_11;
    int sec_r001308_12;
    int sec_r001308_13;
    int sec_r001308_14;
    int sec_r001308_15;
    int sec_r001308_16;
    int pub_r001308_0;
    int pub_r001308_1;
    int pub_r001308_2;
    int pub_r001308_3;
    int pub_r001308_4;
    int pub_r001308_5;
    int pub_r001308_6;
    int pub_r001308_7;
    int pub_r001308_8;
    int pub_r001308_9;
    int pub_r001308_10;
    int pub_r001308_11;
    int pub_r001308_12;
    int pub_r001308_13;
    int pub_r001308_14;
    int pub_r001308_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001308_0 >= -100 && pub_r001308_0 <= 100);
    __CPROVER_assume(pub_r001308_1 >= -100 && pub_r001308_1 <= 100);
    __CPROVER_assume(pub_r001308_2 >= -100 && pub_r001308_2 <= 100);
    __CPROVER_assume(pub_r001308_3 >= -100 && pub_r001308_3 <= 100);
    __CPROVER_assume(pub_r001308_4 >= -100 && pub_r001308_4 <= 100);
    __CPROVER_assume(pub_r001308_5 >= -100 && pub_r001308_5 <= 100);
    __CPROVER_assume(pub_r001308_6 >= -100 && pub_r001308_6 <= 100);
    __CPROVER_assume(pub_r001308_7 >= -100 && pub_r001308_7 <= 100);
    __CPROVER_assume(pub_r001308_8 >= -100 && pub_r001308_8 <= 100);
    __CPROVER_assume(pub_r001308_9 >= -100 && pub_r001308_9 <= 100);
    __CPROVER_assume(pub_r001308_10 >= -100 && pub_r001308_10 <= 100);
    __CPROVER_assume(pub_r001308_11 >= -100 && pub_r001308_11 <= 100);
    __CPROVER_assume(pub_r001308_12 >= -100 && pub_r001308_12 <= 100);
    __CPROVER_assume(pub_r001308_13 >= -100 && pub_r001308_13 <= 100);
    __CPROVER_assume(pub_r001308_14 >= -100 && pub_r001308_14 <= 100);
    __CPROVER_assume(pub_r001308_15 >= -100 && pub_r001308_15 <= 100);
    __CPROVER_assume(sec_r001308_0 >= 0 && sec_r001308_0 <= 255);
    __CPROVER_assume(sec_r001308_1 >= 0 && sec_r001308_1 <= 255);
    __CPROVER_assume(sec_r001308_2 >= 0 && sec_r001308_2 <= 255);
    __CPROVER_assume(sec_r001308_3 >= 0 && sec_r001308_3 <= 255);
    __CPROVER_assume(sec_r001308_4 >= 0 && sec_r001308_4 <= 255);
    __CPROVER_assume(sec_r001308_5 >= 0 && sec_r001308_5 <= 255);
    __CPROVER_assume(sec_r001308_6 >= 0 && sec_r001308_6 <= 255);
    __CPROVER_assume(sec_r001308_7 >= 0 && sec_r001308_7 <= 255);
    __CPROVER_assume(sec_r001308_8 >= 0 && sec_r001308_8 <= 255);
    __CPROVER_assume(sec_r001308_9 >= 0 && sec_r001308_9 <= 255);
    __CPROVER_assume(sec_r001308_10 >= 0 && sec_r001308_10 <= 255);
    __CPROVER_assume(sec_r001308_11 >= 0 && sec_r001308_11 <= 255);
    __CPROVER_assume(sec_r001308_12 >= 0 && sec_r001308_12 <= 255);
    __CPROVER_assume(sec_r001308_13 >= 0 && sec_r001308_13 <= 255);
    __CPROVER_assume(sec_r001308_14 >= 0 && sec_r001308_14 <= 255);
    __CPROVER_assume(sec_r001308_15 >= 0 && sec_r001308_15 <= 255);
    __CPROVER_assume(sec_r001308_16 >= 0 && sec_r001308_16 <= 255);

    struct Transaction_R001308_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001308_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001308_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001308_0 + 7) & 15;
    struct StreamBuffer_R001308_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001308_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001308_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001308_0 + 9) & 15;
    struct EventLog_R001308_813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001308_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001308_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001308_0 + 11) & 15;

    union ColorPixel_R001308_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001308_813_0(sec_r001308_0, sec_r001308_1, pub_r001308_2);
    int helper_flow_1 = fn_R001308_813_1(sec_r001308_1, sec_r001308_2, pub_r001308_3, pub_r001308_4);
    int helper_flow_2 = fn_R001308_813_2(sec_r001308_2, pub_r001308_3, pub_r001308_4);
    int helper_flow_3 = fn_R001308_813_3(sec_r001308_3, pub_r001308_4, pub_r001308_5, pub_r001308_6, pub_r001308_7);
    int helper_flow_4 = fn_R001308_813_4(sec_r001308_4, pub_r001308_5, pub_r001308_6, pub_r001308_7);
    int helper_flow_5 = fn_R001308_813_5(sec_r001308_5, pub_r001308_6);
    int helper_flow_6 = fn_R001308_813_6(sec_r001308_6, pub_r001308_7, pub_r001308_8);
    int helper_flow_7 = fn_R001308_813_7(sec_r001308_7, sec_r001308_8);
    int helper_flow_8 = fn_R001308_813_8(sec_r001308_8, sec_r001308_9, pub_r001308_10, pub_r001308_11);
    int helper_flow_9 = fn_R001308_813_9(sec_r001308_9, sec_r001308_10, pub_r001308_11);
    int helper_flow_10 = fn_R001308_813_10(sec_r001308_10, sec_r001308_11, pub_r001308_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (sec_r001308_12 & 15)) & 63;
        if ((sec_r001308_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001308_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (sec_r001308_16 & 15)) & 63;
        if ((sec_r001308_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_4 = (stage_v_4 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_4 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_4 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001308_16 & 15)) & 63;
        if ((sec_r001308_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001308_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (sec_r001308_13 & 15)) & 63;
        if ((sec_r001308_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_8 = (stage_v_8 + it * 3 + (sec_r001308_5 & 15)) & 63;
        if ((sec_r001308_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_8 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_8 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001308_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001308_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (sec_r001308_7 & 15)) & 63;
        if ((sec_r001308_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001308_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001308_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (sec_r001308_4 & 15)) & 63;
        if ((sec_r001308_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001308_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001308_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (sec_r001308_11 & 15)) & 63;
        if ((sec_r001308_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_22 = (stage_v_22 + it * 3 + (sec_r001308_6 & 15)) & 63;
        if ((sec_r001308_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_22 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_22 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001308_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (sec_r001308_5 & 15)) & 63;
        if ((sec_r001308_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (sec_r001308_3 & 15)) & 63;
        if ((sec_r001308_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001308_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001308_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (sec_r001308_5 & 15)) & 63;
        if ((sec_r001308_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001308_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001308_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001308_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_34 = (stage_v_34 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_34 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_34 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001308_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001308_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (sec_r001308_4 & 15)) & 63;
        if ((sec_r001308_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001308_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001308_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (sec_r001308_1 & 15)) & 63;
        if ((sec_r001308_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001308_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001308_8 & 15)) & 63;
        if ((sec_r001308_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001308_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001308_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001308_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001308_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001308_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_52 = (stage_v_52 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_52 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_52 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (sec_r001308_11 & 15)) & 63;
        if ((sec_r001308_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (sec_r001308_2 & 15)) & 63;
        if ((sec_r001308_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001308_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001308_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001308_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_58 = (stage_v_58 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_58 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_58 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (sec_r001308_8 & 15)) & 63;
        if ((sec_r001308_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001308_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_63 = (stage_v_63 + it * 3 + (stage_v_52 & 15)) & 63;
        if ((stage_v_52 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_63 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_63 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001308_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001308_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001308_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_4 & 15)) & 63;
        if ((stage_v_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001308_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (sec_r001308_12 & 15)) & 63;
        if ((sec_r001308_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (stage_v_52 & 15)) & 63;
        if ((stage_v_52 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_74 = (stage_v_74 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_76 = (stage_v_76 + it * 3 + (sec_r001308_2 & 15)) & 63;
        if ((sec_r001308_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_76 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_76 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001308_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (stage_v_68 & 15)) & 63;
        if ((stage_v_68 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (stage_v_74 & 15)) & 63;
        if ((stage_v_74 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001308_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_82 = (stage_v_82 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_82 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_82 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001308_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001308_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001308_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001308_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (stage_v_68 & 15)) & 63;
        if ((stage_v_68 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (sec_r001308_8 & 15)) & 63;
        if ((sec_r001308_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_61 & 15)) & 63;
        if ((stage_v_61 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001308_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (stage_v_75 & 15)) & 63;
        if ((stage_v_75 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_96 = (stage_v_96 + it * 3 + (stage_v_75 & 15)) & 63;
        if ((stage_v_75 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_96 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_96 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001308_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001308_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001308_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001308_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_45 & 15)) & 63;
        if ((stage_v_45 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_106 = (stage_v_106 + it * 3 + (sec_r001308_7 & 15)) & 63;
        if ((sec_r001308_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_106 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_106 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001308_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_109 = (stage_v_109 + it * 3 + (stage_v_58 & 15)) & 63;
        if ((stage_v_58 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_109 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_109 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (sec_r001308_1 & 15)) & 63;
        if ((sec_r001308_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001308_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001308_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (sec_r001308_4 & 15)) & 63;
        if ((sec_r001308_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001308_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001308_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001308_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (stage_v_38 & 15)) & 63;
        if ((stage_v_38 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001308_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (stage_v_108 & 15)) & 63;
        if ((stage_v_108 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (sec_r001308_16 & 15)) & 63;
        if ((sec_r001308_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001308_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (stage_v_115 & 15)) & 63;
        if ((stage_v_115 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001308_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001308_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (stage_v_76 & 15)) & 63;
        if ((stage_v_76 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001308_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (sec_r001308_3 & 15)) & 63;
        if ((sec_r001308_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (sec_r001308_1 & 15)) & 63;
        if ((sec_r001308_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_130 & 15)) & 63;
        if ((stage_v_130 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_110 & 15)) & 63;
        if ((stage_v_110 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001308_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001308_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_130 & 15)) & 63;
        if ((stage_v_130 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_141 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_141 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (sec_r001308_15 & 15)) & 63;
        if ((sec_r001308_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_144 = (stage_v_144 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_144 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_144 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_145 = (stage_v_145 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_145 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_145 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001308_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001308_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_8 & 15)) & 63;
        if ((stage_v_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001308_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_152 = (stage_v_152 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_152 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_152 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001308_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001308_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001308_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001308_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_158 = (stage_v_158 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_158 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_158 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001308_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001308_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (sec_r001308_8 & 15)) & 63;
        if ((sec_r001308_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (sec_r001308_1 & 15)) & 63;
        if ((sec_r001308_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001308_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001308_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001308_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001308_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (stage_v_140 & 15)) & 63;
        if ((stage_v_140 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001308_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001308_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_170 = (stage_v_170 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_170 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_170 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_171 = (stage_v_171 + it * 3 + (stage_v_141 & 15)) & 63;
        if ((stage_v_141 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_171 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_171 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_103 & 15)) & 63;
        if ((stage_v_103 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001308_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (sec_r001308_9 & 15)) & 63;
        if ((sec_r001308_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_142 & 15)) & 63;
        if ((stage_v_142 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (sec_r001308_13 & 15)) & 63;
        if ((sec_r001308_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001308_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001308_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_101 & 15)) & 63;
        if ((stage_v_101 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (sec_r001308_9 & 15)) & 63;
        if ((sec_r001308_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_88 & 15)) & 63;
        if ((stage_v_88 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001308_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (sec_r001308_6 & 15)) & 63;
        if ((sec_r001308_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (sec_r001308_8 & 15)) & 63;
        if ((sec_r001308_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_158 & 15)) & 63;
        if ((stage_v_158 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001308_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_115 & 15)) & 63;
        if ((stage_v_115 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001308_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_75 & 15)) & 63;
        if ((stage_v_75 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_198 = (stage_v_198 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_198 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_198 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_200 = (stage_v_200 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_200 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_200 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001308_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_167 & 15)) & 63;
        if ((stage_v_167 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001308_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001308_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001308_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (sec_r001308_0 & 15)) & 63;
        if ((sec_r001308_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_207 = (stage_v_207 + it * 3 + (stage_v_124 & 15)) & 63;
        if ((stage_v_124 & 1) != 0) {
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
