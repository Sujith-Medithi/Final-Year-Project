/*
 * Benchmark Program: R001246
 * Security Family: implicit_flow
 * Generator Seed: 624613
 * High Inputs: 23 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001246_4613_0 {
    int timestamp;
    unsigned char facility;
    short code;
    int signature;
    int seq;
    int buffer[3];
};

struct FilterState_R001246_4613_1 {
    unsigned char prev_in;
    unsigned char gain_db;
    int mode;
    short prev_out;
    int damping;
    int cutoff;
    int buffer[3];
};

struct Transaction_R001246_4613_2 {
    int status;
    int fee;
    unsigned char account_id;
    int auth_code;
    unsigned char balance;
    int buffer[3];
};

union PacketPayload_R001246_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001246_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001246_4613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_62 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_62 > 25) {
        acc = (acc + index_reg_62 * 2 + 5) & 127;
        aux ^= (index_reg_62 & 15);
    } else {
        acc = (acc - index_reg_62 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_52 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_52 = (quotient_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_1(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_86 = (aux + st.buffer[1]) & 3;
    switch (damping_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_67 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_67 = (accumulator_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_67) & 127;
    }
    int accumulator_89 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_89 > 45) {
        acc = (acc + accumulator_89 * 2 + 5) & 127;
        aux ^= (accumulator_89 & 15);
    } else {
        acc = (acc - accumulator_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_73 = local_arr[aux % 3];
    acc = (acc + quotient_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_2(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_23 = 0;
    for (int k = 0; k < 2; k++) {
        mask_23 = (mask_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_23) & 127;
    }
    int margin_64 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_64 > 15) {
        acc = (acc + margin_64 * 2 + 5) & 127;
        aux ^= (margin_64 & 15);
    } else {
        acc = (acc - margin_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int cursor_42 = local_arr[aux % 3];
    acc = (acc + cursor_42 * 2) & 127;
    int tracker_70 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_70 = (tracker_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_70) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001246_4613_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_43 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_43 > 33) {
        acc = (acc + vector_43 * 2 + 5) & 127;
        aux ^= (vector_43 & 15);
    } else {
        acc = (acc - vector_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_45 = local_arr[aux % 3];
    acc = (acc + quantum_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int index_reg_31 = local_arr[aux % 3];
    acc = (acc + index_reg_31 * 2) & 127;
    int phase_27 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_27 > 25) {
        acc = (acc + phase_27 * 2 + 5) & 127;
        aux ^= (phase_27 & 15);
    } else {
        acc = (acc - phase_27 + 11) & 127;
        aux += 3;
    }
    int metric_31 = 0;
    for (int k = 0; k < 3; k++) {
        metric_31 = (metric_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_23) & 63;
    acc ^= aux;
    int accumulator_49 = (aux + st.buffer[1]) & 3;
    switch (accumulator_49) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int threshold_67 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_67 = (threshold_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_67) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_8(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int checksum_98 = (aux + st.buffer[1]) & 3;
    switch (checksum_98) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_34 = 0;
    for (int k = 0; k < 3; k++) {
        stride_34 = (stride_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int phase_60 = (aux + st.buffer[1]) & 3;
    switch (phase_60) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_12 = local_arr[aux % 3];
    acc = (acc + tracker_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001246_4613_10(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int index_reg_61 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_61 > 49) {
        acc = (acc + index_reg_61 * 2 + 5) & 127;
        aux ^= (index_reg_61 & 15);
    } else {
        acc = (acc - index_reg_61 + 11) & 127;
        aux += 3;
    }
    int margin_10 = 0;
    for (int k = 0; k < 2; k++) {
        margin_10 = (margin_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_11(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_54 = (aux + st.buffer[1]) & 3;
    switch (stride_54) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_16 = local_arr[aux % 3];
    acc = (acc + factor_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_12(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int weight_72 = local_arr[aux % 3];
    acc = (acc + weight_72 * 2) & 127;
    int mask_46 = (aux + st.buffer[1]) & 3;
    switch (mask_46) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_13(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_55 = local_arr[aux % 3];
    acc = (acc + window_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_73 = local_arr[aux % 3];
    acc = (acc + coefficient_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_15(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int weight_15 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_15 > 16) {
        acc = (acc + weight_15 * 2 + 5) & 127;
        aux ^= (weight_15 & 15);
    } else {
        acc = (acc - weight_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_18 = local_arr[aux % 3];
    acc = (acc + parity_18 * 2) & 127;
    int tally_38 = (aux + st.buffer[1]) & 3;
    switch (tally_38) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_16(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001246_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int factor_52 = local_arr[aux % 3];
    acc = (acc + factor_52 * 2) & 127;
    int delta_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_86) & 63;
    acc ^= aux;
    int pivot_19 = (aux + st.buffer[1]) & 3;
    switch (pivot_19) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_44 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_44 > 49) {
        acc = (acc + anchor_44 * 2 + 5) & 127;
        aux ^= (anchor_44 & 15);
    } else {
        acc = (acc - anchor_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_60 = 0;
    for (int k = 0; k < 3; k++) {
        factor_60 = (factor_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_60) & 127;
    }
    int quantum_75 = (aux + st.buffer[1]) & 3;
    switch (quantum_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_33 = local_arr[aux % 3];
    acc = (acc + damping_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_18(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int margin_16 = local_arr[aux % 3];
    acc = (acc + margin_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_77 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_77 = (anchor_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_77) & 127;
    }
    int pivot_17 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_17 > 38) {
        acc = (acc + pivot_17 * 2 + 5) & 127;
        aux ^= (pivot_17 & 15);
    } else {
        acc = (acc - pivot_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001246_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_10 > 20) {
        acc = (acc + cursor_10 * 2 + 5) & 127;
        aux ^= (cursor_10 & 15);
    } else {
        acc = (acc - cursor_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001246_4613_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 40) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001246_4613_21(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001246_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int accumulator_79 = local_arr[aux % 3];
    acc = (acc + accumulator_79 * 2) & 127;
    int delta_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_74) & 63;
    acc ^= aux;
    int bound_66 = (aux + st.buffer[1]) & 3;
    switch (bound_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001246_0;
    int sec_r001246_1;
    int sec_r001246_2;
    int sec_r001246_3;
    int sec_r001246_4;
    int sec_r001246_5;
    int sec_r001246_6;
    int sec_r001246_7;
    int sec_r001246_8;
    int sec_r001246_9;
    int sec_r001246_10;
    int sec_r001246_11;
    int sec_r001246_12;
    int sec_r001246_13;
    int sec_r001246_14;
    int sec_r001246_15;
    int sec_r001246_16;
    int sec_r001246_17;
    int sec_r001246_18;
    int sec_r001246_19;
    int sec_r001246_20;
    int sec_r001246_21;
    int sec_r001246_22;
    int pub_r001246_0;
    int pub_r001246_1;
    int pub_r001246_2;
    int pub_r001246_3;
    int pub_r001246_4;
    int pub_r001246_5;
    int pub_r001246_6;
    int pub_r001246_7;
    int pub_r001246_8;
    int pub_r001246_9;
    int pub_r001246_10;
    int pub_r001246_11;
    int pub_r001246_12;
    int pub_r001246_13;
    int pub_r001246_14;
    int pub_r001246_15;
    int pub_r001246_16;
    int pub_r001246_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001246_0 >= -100 && pub_r001246_0 <= 100);
    __CPROVER_assume(pub_r001246_1 >= -100 && pub_r001246_1 <= 100);
    __CPROVER_assume(pub_r001246_2 >= -100 && pub_r001246_2 <= 100);
    __CPROVER_assume(pub_r001246_3 >= -100 && pub_r001246_3 <= 100);
    __CPROVER_assume(pub_r001246_4 >= -100 && pub_r001246_4 <= 100);
    __CPROVER_assume(pub_r001246_5 >= -100 && pub_r001246_5 <= 100);
    __CPROVER_assume(pub_r001246_6 >= -100 && pub_r001246_6 <= 100);
    __CPROVER_assume(pub_r001246_7 >= -100 && pub_r001246_7 <= 100);
    __CPROVER_assume(pub_r001246_8 >= -100 && pub_r001246_8 <= 100);
    __CPROVER_assume(pub_r001246_9 >= -100 && pub_r001246_9 <= 100);
    __CPROVER_assume(pub_r001246_10 >= -100 && pub_r001246_10 <= 100);
    __CPROVER_assume(pub_r001246_11 >= -100 && pub_r001246_11 <= 100);
    __CPROVER_assume(pub_r001246_12 >= -100 && pub_r001246_12 <= 100);
    __CPROVER_assume(pub_r001246_13 >= -100 && pub_r001246_13 <= 100);
    __CPROVER_assume(pub_r001246_14 >= -100 && pub_r001246_14 <= 100);
    __CPROVER_assume(pub_r001246_15 >= -100 && pub_r001246_15 <= 100);
    __CPROVER_assume(pub_r001246_16 >= -100 && pub_r001246_16 <= 100);
    __CPROVER_assume(pub_r001246_17 >= -100 && pub_r001246_17 <= 100);
    __CPROVER_assume(sec_r001246_0 >= 0 && sec_r001246_0 <= 255);
    __CPROVER_assume(sec_r001246_1 >= 0 && sec_r001246_1 <= 255);
    __CPROVER_assume(sec_r001246_2 >= 0 && sec_r001246_2 <= 255);
    __CPROVER_assume(sec_r001246_3 >= 0 && sec_r001246_3 <= 255);
    __CPROVER_assume(sec_r001246_4 >= 0 && sec_r001246_4 <= 255);
    __CPROVER_assume(sec_r001246_5 >= 0 && sec_r001246_5 <= 255);
    __CPROVER_assume(sec_r001246_6 >= 0 && sec_r001246_6 <= 255);
    __CPROVER_assume(sec_r001246_7 >= 0 && sec_r001246_7 <= 255);
    __CPROVER_assume(sec_r001246_8 >= 0 && sec_r001246_8 <= 255);
    __CPROVER_assume(sec_r001246_9 >= 0 && sec_r001246_9 <= 255);
    __CPROVER_assume(sec_r001246_10 >= 0 && sec_r001246_10 <= 255);
    __CPROVER_assume(sec_r001246_11 >= 0 && sec_r001246_11 <= 255);
    __CPROVER_assume(sec_r001246_12 >= 0 && sec_r001246_12 <= 255);
    __CPROVER_assume(sec_r001246_13 >= 0 && sec_r001246_13 <= 255);
    __CPROVER_assume(sec_r001246_14 >= 0 && sec_r001246_14 <= 255);
    __CPROVER_assume(sec_r001246_15 >= 0 && sec_r001246_15 <= 255);
    __CPROVER_assume(sec_r001246_16 >= 0 && sec_r001246_16 <= 255);
    __CPROVER_assume(sec_r001246_17 >= 0 && sec_r001246_17 <= 255);
    __CPROVER_assume(sec_r001246_18 >= 0 && sec_r001246_18 <= 255);
    __CPROVER_assume(sec_r001246_19 >= 0 && sec_r001246_19 <= 255);
    __CPROVER_assume(sec_r001246_20 >= 0 && sec_r001246_20 <= 255);
    __CPROVER_assume(sec_r001246_21 >= 0 && sec_r001246_21 <= 255);
    __CPROVER_assume(sec_r001246_22 >= 0 && sec_r001246_22 <= 255);

    struct EventLog_R001246_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001246_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001246_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001246_0 + 7) & 15;
    struct FilterState_R001246_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001246_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001246_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001246_0 + 9) & 15;
    struct Transaction_R001246_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001246_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001246_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001246_0 + 11) & 15;

    union PacketPayload_R001246_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001246_4613_0(sec_r001246_0, sec_r001246_1, pub_r001246_2, pub_r001246_3);
    int helper_flow_1 = fn_R001246_4613_1(sec_r001246_1, sec_r001246_2);
    int helper_flow_2 = fn_R001246_4613_2(sec_r001246_2, sec_r001246_3, pub_r001246_4);
    int helper_flow_3 = fn_R001246_4613_3(sec_r001246_3, sec_r001246_4, pub_r001246_5, pub_r001246_6);
    int helper_flow_4 = fn_R001246_4613_4(sec_r001246_4, sec_r001246_5, pub_r001246_6);
    int helper_flow_5 = fn_R001246_4613_5(sec_r001246_5, pub_r001246_6, pub_r001246_7, pub_r001246_8, pub_r001246_9);
    int helper_flow_6 = fn_R001246_4613_6(sec_r001246_6, pub_r001246_7, pub_r001246_8, pub_r001246_9, pub_r001246_10);
    int helper_flow_7 = fn_R001246_4613_7(sec_r001246_7, pub_r001246_8, pub_r001246_9, pub_r001246_10);
    int helper_flow_8 = fn_R001246_4613_8(sec_r001246_8, pub_r001246_9, pub_r001246_10);
    int helper_flow_9 = fn_R001246_4613_9(sec_r001246_9, sec_r001246_10);
    int helper_flow_10 = fn_R001246_4613_10(sec_r001246_10, pub_r001246_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001246_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001246_22 + pub_r001246_17 * 2 + 8) & 127;
    if (stage_v_1 > 50) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001246_19 + pub_r001246_12 * 2 + 11) & 127;
    if (stage_v_2 > 45) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_8 + pub_r001246_0 * 2 + 14) & 127;
    if (stage_v_3 > 55) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001246_22 + pub_r001246_13 * 2 + 17) & 127;
    if (stage_v_4 > 56) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_10 + pub_r001246_1 * 2 + 20) & 127;
    if (stage_v_5 > 49) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001246_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001246_20 + pub_r001246_7 * 2 + 26) & 127;
    if (stage_v_7 > 19) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001246_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_10 + pub_r001246_17 * 2 + 32) & 127;
    if (stage_v_9 > 21) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001246_8 + pub_r001246_4 * 2 + 35) & 127;
    if (stage_v_10 > 57) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001246_9 + pub_r001246_5 * 2 + 38) & 127;
    if (stage_v_11 > 16) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001246_14 + pub_r001246_0 * 2 + 41) & 127;
    if (stage_v_12 > 52) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001246_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001246_22 + pub_r001246_14 * 2 + 47) & 127;
    if (stage_v_14 > 44) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001246_17 + pub_r001246_12 * 2 + 50) & 127;
    if (stage_v_15 > 53) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_15 + pub_r001246_14 * 2 + 53) & 127;
    if (stage_v_16 > 25) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001246_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_10 + pub_r001246_8 * 2 + 59) & 127;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001246_20 + pub_r001246_17 * 2 + 62) & 127;
    if (stage_v_19 > 21) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001246_0 + pub_r001246_0 * 2 + 65) & 127;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_10 + pub_r001246_2 * 2 + 68) & 127;
    if (stage_v_21 > 23) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_7 + pub_r001246_13 * 2 + 71) & 127;
    if (stage_v_22 > 24) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001246_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001246_3 + pub_r001246_5 * 2 + 77) & 127;
    if (stage_v_24 > 55) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001246_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001246_20 + pub_r001246_11 * 2 + 83) & 127;
    if (stage_v_26 > 46) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_4 + pub_r001246_6 * 2 + 86) & 127;
    if (stage_v_27 > 27) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001246_20 + pub_r001246_1 * 2 + 89) & 127;
    if (stage_v_28 > 42) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001246_3 + pub_r001246_3 * 2 + 92) & 127;
    if (stage_v_29 > 26) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_20 + pub_r001246_16 * 2 + 95) & 127;
    if (stage_v_30 > 37) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_24 + pub_r001246_6 * 2 + 98) & 127;
    if (stage_v_31 > 30) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001246_9 + pub_r001246_13 * 2 + 101) & 127;
    if (stage_v_32 > 47) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001246_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001246_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001246_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001246_3 + pub_r001246_4 * 2 + 113) & 127;
    if (stage_v_36 > 26) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001246_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001246_2 + pub_r001246_14 * 2 + 119) & 127;
    if (stage_v_38 > 56) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001246_19 + pub_r001246_0 * 2 + 122) & 127;
    if (stage_v_39 > 27) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_1 + pub_r001246_16 * 2 + 125) & 127;
    if (stage_v_40 > 49) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (helper_flow_3 + pub_r001246_17 * 2 + 128) & 127;
    if (stage_v_41 > 26) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001246_5 + pub_r001246_0 * 2 + 131) & 127;
    if (stage_v_42 > 21) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001246_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001246_4 + pub_r001246_11 * 2 + 137) & 127;
    if (stage_v_44 > 46) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001246_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001246_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_39 + pub_r001246_17 * 2 + 146) & 127;
    if (stage_v_47 > 57) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_10 + pub_r001246_13 * 2 + 149) & 127;
    if (stage_v_48 > 60) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001246_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_16 + pub_r001246_7 * 2 + 155) & 127;
    if (stage_v_50 > 18) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_7 + pub_r001246_8 * 2 + 158) & 127;
    if (stage_v_51 > 50) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001246_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001246_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001246_21 + pub_r001246_10 * 2 + 167) & 127;
    if (stage_v_54 > 31) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_29 + pub_r001246_3 * 2 + 170) & 127;
    if (stage_v_55 > 42) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_21 + pub_r001246_3 * 2 + 173) & 127;
    if (stage_v_56 > 19) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001246_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001246_11 + pub_r001246_4 * 2 + 179) & 127;
    if (stage_v_58 > 54) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001246_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001246_0 + pub_r001246_4 * 2 + 185) & 127;
    if (stage_v_60 > 33) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (helper_flow_10 + pub_r001246_4 * 2 + 188) & 127;
    if (stage_v_61 > 27) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_47 + pub_r001246_5 * 2 + 191) & 127;
    if (stage_v_62 > 29) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_44 + pub_r001246_13 * 2 + 194) & 127;
    if (stage_v_63 > 40) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_36 + pub_r001246_13 * 2 + 197) & 127;
    if (stage_v_64 > 32) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001246_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_12 + pub_r001246_4 * 2 + 203) & 127;
    if (stage_v_66 > 41) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001246_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001246_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001246_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_41 + pub_r001246_12 * 2 + 215) & 127;
    if (stage_v_70 > 44) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001246_13 + pub_r001246_9 * 2 + 218) & 127;
    if (stage_v_71 > 50) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001246_11 + pub_r001246_7 * 2 + 221) & 127;
    if (stage_v_72 > 55) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_5 + pub_r001246_3 * 2 + 224) & 127;
    if (stage_v_73 > 23) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_21 + pub_r001246_9 * 2 + 227) & 127;
    if (stage_v_74 > 30) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_72 + pub_r001246_1 * 2 + 230) & 127;
    if (stage_v_75 > 48) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_20 + pub_r001246_5 * 2 + 233) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_5 + pub_r001246_7 * 2 + 236) & 127;
    if (stage_v_77 > 40) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_15 + pub_r001246_3 * 2 + 239) & 127;
    if (stage_v_78 > 46) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001246_11 + pub_r001246_15 * 2 + 242) & 127;
    if (stage_v_79 > 33) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001246_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001246_22 + pub_r001246_7 * 2 + 248) & 127;
    if (stage_v_81 > 35) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001246_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001246_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001246_4 + pub_r001246_0 * 2 + 257) & 127;
    if (stage_v_84 > 34) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001246_22 + pub_r001246_4 * 2 + 260) & 127;
    if (stage_v_85 > 54) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_47 + pub_r001246_0 * 2 + 263) & 127;
    if (stage_v_86 > 20) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001246_13 + pub_r001246_7 * 2 + 266) & 127;
    if (stage_v_87 > 55) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001246_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001246_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001246_18 + pub_r001246_0 * 2 + 275) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_29 + pub_r001246_9 * 2 + 278) & 127;
    if (stage_v_91 > 19) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_90 + pub_r001246_3 * 2 + 281) & 127;
    if (stage_v_92 > 21) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_7 + pub_r001246_16 * 2 + 284) & 127;
    if (stage_v_93 > 31) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001246_0 + pub_r001246_9 * 2 + 287) & 127;
    if (stage_v_94 > 45) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_48 + pub_r001246_1 * 2 + 290) & 127;
    if (stage_v_95 > 52) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001246_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_54 + pub_r001246_9 * 2 + 296) & 127;
    if (stage_v_97 > 44) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_1 + pub_r001246_6 * 2 + 299) & 127;
    if (stage_v_98 > 40) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001246_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001246_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001246_6 + pub_r001246_1 * 2 + 308) & 127;
    if (stage_v_101 > 55) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001246_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_64 + pub_r001246_11 * 2 + 314) & 127;
    if (stage_v_103 > 22) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001246_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_60 + pub_r001246_4 * 2 + 320) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001246_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001246_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_75 + pub_r001246_13 * 2 + 329) & 127;
    if (stage_v_108 > 34) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001246_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001246_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001246_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001246_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_81 + pub_r001246_2 * 2 + 344) & 127;
    if (stage_v_113 > 59) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001246_13 + pub_r001246_3 * 2 + 347) & 127;
    if (stage_v_114 > 48) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_73 + pub_r001246_1 * 2 + 350) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_72 + pub_r001246_8 * 2 + 353) & 127;
    if (stage_v_116 > 57) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (sec_r001246_0 + pub_r001246_9 * 2 + 356) & 127;
    if (stage_v_117 > 52) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_115 + pub_r001246_8 * 2 + 359) & 127;
    if (stage_v_118 > 39) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_41 + pub_r001246_5 * 2 + 362) & 127;
    if (stage_v_119 > 19) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001246_8 + pub_r001246_11 * 2 + 365) & 127;
    if (stage_v_120 > 41) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_115 + pub_r001246_0 * 2 + 368) & 127;
    if (stage_v_121 > 30) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_28 + pub_r001246_5 * 2 + 371) & 127;
    if (stage_v_122 > 40) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_113 + pub_r001246_8 * 2 + 374) & 127;
    if (stage_v_123 > 30) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_2 + pub_r001246_12 * 2 + 377) & 127;
    if (stage_v_124 > 60) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001246_8 + pub_r001246_0 * 2 + 380) & 127;
    if (stage_v_125 > 57) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_50 + pub_r001246_5 * 2 + 383) & 127;
    if (stage_v_126 > 46) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_61 + pub_r001246_1 * 2 + 386) & 127;
    if (stage_v_127 > 22) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_70 + pub_r001246_2 * 2 + 389) & 127;
    if (stage_v_128 > 46) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_61 + pub_r001246_8 * 2 + 392) & 127;
    if (stage_v_129 > 49) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_54 + pub_r001246_14 * 2 + 395) & 127;
    if (stage_v_130 > 36) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001246_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_101 + pub_r001246_10 * 2 + 401) & 127;
    if (stage_v_132 > 35) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001246_21 + pub_r001246_9 * 2 + 404) & 127;
    if (stage_v_133 > 28) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_63 + pub_r001246_16 * 2 + 407) & 127;
    if (stage_v_134 > 41) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001246_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_124 + pub_r001246_16 * 2 + 413) & 127;
    if (stage_v_136 > 38) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001246_10 + pub_r001246_13 * 2 + 416) & 127;
    if (stage_v_137 > 46) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001246_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (helper_flow_6 + pub_r001246_0 * 2 + 422) & 127;
    if (stage_v_139 > 23) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_29 + pub_r001246_8 * 2 + 425) & 127;
    if (stage_v_140 > 46) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001246_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001246_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_117 + pub_r001246_4 * 2 + 434) & 127;
    if (stage_v_143 > 18) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001246_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_73 + pub_r001246_2 * 2 + 440) & 127;
    if (stage_v_145 > 43) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (helper_flow_2 + pub_r001246_0 * 2 + 443) & 127;
    if (stage_v_146 > 32) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_70 + pub_r001246_11 * 2 + 446) & 127;
    if (stage_v_147 > 17) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_98 + pub_r001246_7 * 2 + 449) & 127;
    if (stage_v_148 > 19) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_79 + pub_r001246_14 * 2 + 452) & 127;
    if (stage_v_149 > 45) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_98 + pub_r001246_8 * 2 + 455) & 127;
    if (stage_v_150 > 27) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001246_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_14 + pub_r001246_16 * 2 + 461) & 127;
    if (stage_v_152 > 23) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (sec_r001246_4 + pub_r001246_6 * 2 + 464) & 127;
    if (stage_v_153 > 27) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_10 + pub_r001246_1 * 2 + 467) & 127;
    if (stage_v_154 > 38) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001246_0 + pub_r001246_0 * 2 + 470) & 127;
    if (stage_v_155 > 21) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_26 + pub_r001246_7 * 2 + 473) & 127;
    if (stage_v_156 > 34) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (helper_flow_5 + pub_r001246_11 * 2 + 476) & 127;
    if (stage_v_157 > 36) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001246_6 + pub_r001246_0 * 2 + 479) & 127;
    if (stage_v_158 > 39) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001246_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001246_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_15 + pub_r001246_1 * 2 + 488) & 127;
    if (stage_v_161 > 40) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001246_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001246_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_38 + pub_r001246_4 * 2 + 497) & 127;
    if (stage_v_164 > 40) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (helper_flow_7 + pub_r001246_9 * 2 + 500) & 127;
    if (stage_v_165 > 60) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001246_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001246_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001246_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001246_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_155 + pub_r001246_17 * 2 + 515) & 127;
    if (stage_v_170 > 22) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_66 + pub_r001246_14 * 2 + 518) & 127;
    if (stage_v_171 > 23) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001246_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001246_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_36 + pub_r001246_0 * 2 + 527) & 127;
    if (stage_v_174 > 37) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_154 + pub_r001246_4 * 2 + 530) & 127;
    if (stage_v_175 > 54) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001246_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001246_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (helper_flow_6 + pub_r001246_17 * 2 + 539) & 127;
    if (stage_v_178 > 30) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_36 + pub_r001246_12 * 2 + 542) & 127;
    if (stage_v_179 > 17) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_103 + pub_r001246_16 * 2 + 545) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (helper_flow_2 + pub_r001246_16 * 2 + 548) & 127;
    if (stage_v_181 > 20) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001246_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_39 + pub_r001246_5 * 2 + 554) & 127;
    if (stage_v_183 > 18) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001246_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001246_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_156 + pub_r001246_11 * 2 + 563) & 127;
    if (stage_v_186 > 32) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001246_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (helper_flow_0 + pub_r001246_16 * 2 + 569) & 127;
    if (stage_v_188 > 41) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001246_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_10 + pub_r001246_17 * 2 + 575) & 127;
    if (stage_v_190 > 44) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001246_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001246_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (sec_r001246_22 + pub_r001246_14 * 2 + 584) & 127;
    if (stage_v_193 > 55) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_3 + pub_r001246_4 * 2 + 587) & 127;
    if (stage_v_194 > 21) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001246_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001246_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_116 + pub_r001246_9 * 2 + 596) & 127;
    if (stage_v_197 > 40) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_105 + pub_r001246_1 * 2 + 599) & 127;
    if (stage_v_198 > 43) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_108 + pub_r001246_13 * 2 + 602) & 127;
    if (stage_v_199 > 25) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001246_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001246_0 + pub_r001246_3 * 2 + 608) & 127;
    if (stage_v_201 > 49) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001246_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001246_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_105 + pub_r001246_17 * 2 + 617) & 127;
    if (stage_v_204 > 39) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_15 + pub_r001246_4 * 2 + 620) & 127;
    if (stage_v_205 > 34) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r001246_18 + pub_r001246_7 * 2 + 623) & 127;
    if (stage_v_206 > 28) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001246_7 + pub_r001246_15 * 2 + 626) & 127;
    if (stage_v_207 > 60) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_133 + pub_r001246_9 * 2 + 629) & 127;
    if (stage_v_208 > 52) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_5 + pub_r001246_9 * 2 + 632) & 127;
    if (stage_v_209 > 44) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001246_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_32 + pub_r001246_12 * 2 + 638) & 127;
    if (stage_v_211 > 17) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001246_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_137 + pub_r001246_7 * 2 + 644) & 127;
    if (stage_v_213 > 47) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_16 + pub_r001246_0 * 2 + 647) & 127;
    if (stage_v_214 > 42) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (helper_flow_0 + pub_r001246_16 * 2 + 650) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_11 + pub_r001246_10 * 2 + 653) & 127;
    if (stage_v_216 > 27) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
