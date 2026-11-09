/*
 * Benchmark Program: R001272
 * Security Family: direct_leakage
 * Generator Seed: 627213
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001272_7213_0 {
    unsigned char id;
    int timeout;
    int port;
    unsigned char stop_bits;
    int buffer[3];
};

struct Transaction_R001272_7213_1 {
    int fee;
    int status;
    short balance;
    int buffer[3];
};

union PacketPayload_R001272_7213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001272_7213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001272_7213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_20 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_20 > 41) {
        acc = (acc + delta_20 * 2 + 5) & 127;
        aux ^= (delta_20 & 15);
    } else {
        acc = (acc - delta_20 + 11) & 127;
        aux += 3;
    }
    int bound_18 = 0;
    for (int k = 0; k < 3; k++) {
        bound_18 = (bound_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_18) & 127;
    }
    int anchor_41 = (aux + st.buffer[1]) & 3;
    switch (anchor_41) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001272_7213_1(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001272_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tracker_20 = local_arr[aux % 3];
    acc = (acc + tracker_20 * 2) & 127;
    int bound_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001272_7213_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_32 > 23) {
        acc = (acc + quantum_32 * 2 + 5) & 127;
        aux ^= (quantum_32 & 15);
    } else {
        acc = (acc - quantum_32 + 11) & 127;
        aux += 3;
    }
    int parity_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001272_7213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001272_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_65 = (aux + st.buffer[1]) & 3;
    switch (coefficient_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_29 = 0;
    for (int k = 0; k < 3; k++) {
        segment_29 = (segment_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_29) & 127;
    }
    int threshold_18 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_18 > 17) {
        acc = (acc + threshold_18 * 2 + 5) & 127;
        aux ^= (threshold_18 & 15);
    } else {
        acc = (acc - threshold_18 + 11) & 127;
        aux += 3;
    }
    int factor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001272_7213_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_23 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_23 > 28) {
        acc = (acc + parity_23 * 2 + 5) & 127;
        aux ^= (parity_23 & 15);
    } else {
        acc = (acc - parity_23 + 11) & 127;
        aux += 3;
    }
    int anchor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_82) & 63;
    acc ^= aux;
    int damping_36 = (aux + st.buffer[1]) & 3;
    switch (damping_36) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_98 = local_arr[aux % 3];
    acc = (acc + checksum_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_5(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001272_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int offset_80 = 0;
    for (int k = 0; k < 2; k++) {
        offset_80 = (offset_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_80) & 127;
    }
    int offset_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001272_7213_6(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001272_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int stride_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_72) & 63;
    acc ^= aux;
    int parity_57 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_57 > 24) {
        acc = (acc + parity_57 * 2 + 5) & 127;
        aux ^= (parity_57 & 15);
    } else {
        acc = (acc - parity_57 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_81 = local_arr[aux % 3];
    acc = (acc + offset_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_7(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_73) & 63;
    acc ^= aux;
    int cursor_40 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_40 = (cursor_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_40) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_32 = local_arr[aux % 3];
    acc = (acc + tally_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_16 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_16 > 45) {
        acc = (acc + damping_16 * 2 + 5) & 127;
        aux ^= (damping_16 & 15);
    } else {
        acc = (acc - damping_16 + 11) & 127;
        aux += 3;
    }
    int segment_85 = 0;
    for (int k = 0; k < 2; k++) {
        segment_85 = (segment_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_85) & 127;
    }
    int pivot_86 = (aux + st.buffer[1]) & 3;
    switch (pivot_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_74 = local_arr[aux % 3];
    acc = (acc + pivot_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_10(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_92 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_92 > 46) {
        acc = (acc + tally_92 * 2 + 5) & 127;
        aux ^= (tally_92 & 15);
    } else {
        acc = (acc - tally_92 + 11) & 127;
        aux += 3;
    }
    int window_17 = 0;
    for (int k = 0; k < 3; k++) {
        window_17 = (window_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_17) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_46 = 0;
    for (int k = 0; k < 3; k++) {
        phase_46 = (phase_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_46) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_27 = local_arr[aux % 3];
    acc = (acc + margin_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_12(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_22 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_22 > 37) {
        acc = (acc + quotient_22 * 2 + 5) & 127;
        aux ^= (quotient_22 & 15);
    } else {
        acc = (acc - quotient_22 + 11) & 127;
        aux += 3;
    }
    int quotient_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_77 = local_arr[aux % 3];
    acc = (acc + accumulator_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_13(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001272_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int threshold_29 = local_arr[aux % 3];
    acc = (acc + threshold_29 * 2) & 127;
    int weight_86 = 0;
    for (int k = 0; k < 2; k++) {
        weight_86 = (weight_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_86) & 127;
    }
    int window_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001272_7213_14(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int coefficient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_84) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001272_7213_15(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001272_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_47 = 0;
    for (int k = 0; k < 3; k++) {
        scale_47 = (scale_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_47) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_12 = local_arr[aux % 3];
    acc = (acc + metric_12 * 2) & 127;
    int anchor_91 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_91 > 19) {
        acc = (acc + anchor_91 * 2 + 5) & 127;
        aux ^= (anchor_91 & 15);
    } else {
        acc = (acc - anchor_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001272_0;
    int sec_r001272_1;
    int sec_r001272_2;
    int sec_r001272_3;
    int sec_r001272_4;
    int sec_r001272_5;
    int sec_r001272_6;
    int sec_r001272_7;
    int sec_r001272_8;
    int sec_r001272_9;
    int sec_r001272_10;
    int sec_r001272_11;
    int sec_r001272_12;
    int sec_r001272_13;
    int sec_r001272_14;
    int sec_r001272_15;
    int sec_r001272_16;
    int sec_r001272_17;
    int sec_r001272_18;
    int pub_r001272_0;
    int pub_r001272_1;
    int pub_r001272_2;
    int pub_r001272_3;
    int pub_r001272_4;
    int pub_r001272_5;
    int pub_r001272_6;
    int pub_r001272_7;
    int pub_r001272_8;
    int pub_r001272_9;
    int pub_r001272_10;
    int pub_r001272_11;
    int pub_r001272_12;
    int pub_r001272_13;
    int pub_r001272_14;
    int pub_r001272_15;
    int pub_r001272_16;
    int pub_r001272_17;
    int pub_r001272_18;
    int pub_r001272_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001272_0 >= -100 && pub_r001272_0 <= 100);
    __CPROVER_assume(pub_r001272_1 >= -100 && pub_r001272_1 <= 100);
    __CPROVER_assume(pub_r001272_2 >= -100 && pub_r001272_2 <= 100);
    __CPROVER_assume(pub_r001272_3 >= -100 && pub_r001272_3 <= 100);
    __CPROVER_assume(pub_r001272_4 >= -100 && pub_r001272_4 <= 100);
    __CPROVER_assume(pub_r001272_5 >= -100 && pub_r001272_5 <= 100);
    __CPROVER_assume(pub_r001272_6 >= -100 && pub_r001272_6 <= 100);
    __CPROVER_assume(pub_r001272_7 >= -100 && pub_r001272_7 <= 100);
    __CPROVER_assume(pub_r001272_8 >= -100 && pub_r001272_8 <= 100);
    __CPROVER_assume(pub_r001272_9 >= -100 && pub_r001272_9 <= 100);
    __CPROVER_assume(pub_r001272_10 >= -100 && pub_r001272_10 <= 100);
    __CPROVER_assume(pub_r001272_11 >= -100 && pub_r001272_11 <= 100);
    __CPROVER_assume(pub_r001272_12 >= -100 && pub_r001272_12 <= 100);
    __CPROVER_assume(pub_r001272_13 >= -100 && pub_r001272_13 <= 100);
    __CPROVER_assume(pub_r001272_14 >= -100 && pub_r001272_14 <= 100);
    __CPROVER_assume(pub_r001272_15 >= -100 && pub_r001272_15 <= 100);
    __CPROVER_assume(pub_r001272_16 >= -100 && pub_r001272_16 <= 100);
    __CPROVER_assume(pub_r001272_17 >= -100 && pub_r001272_17 <= 100);
    __CPROVER_assume(pub_r001272_18 >= -100 && pub_r001272_18 <= 100);
    __CPROVER_assume(pub_r001272_19 >= -100 && pub_r001272_19 <= 100);
    __CPROVER_assume(sec_r001272_0 >= 0 && sec_r001272_0 <= 255);
    __CPROVER_assume(sec_r001272_1 >= 0 && sec_r001272_1 <= 255);
    __CPROVER_assume(sec_r001272_2 >= 0 && sec_r001272_2 <= 255);
    __CPROVER_assume(sec_r001272_3 >= 0 && sec_r001272_3 <= 255);
    __CPROVER_assume(sec_r001272_4 >= 0 && sec_r001272_4 <= 255);
    __CPROVER_assume(sec_r001272_5 >= 0 && sec_r001272_5 <= 255);
    __CPROVER_assume(sec_r001272_6 >= 0 && sec_r001272_6 <= 255);
    __CPROVER_assume(sec_r001272_7 >= 0 && sec_r001272_7 <= 255);
    __CPROVER_assume(sec_r001272_8 >= 0 && sec_r001272_8 <= 255);
    __CPROVER_assume(sec_r001272_9 >= 0 && sec_r001272_9 <= 255);
    __CPROVER_assume(sec_r001272_10 >= 0 && sec_r001272_10 <= 255);
    __CPROVER_assume(sec_r001272_11 >= 0 && sec_r001272_11 <= 255);
    __CPROVER_assume(sec_r001272_12 >= 0 && sec_r001272_12 <= 255);
    __CPROVER_assume(sec_r001272_13 >= 0 && sec_r001272_13 <= 255);
    __CPROVER_assume(sec_r001272_14 >= 0 && sec_r001272_14 <= 255);
    __CPROVER_assume(sec_r001272_15 >= 0 && sec_r001272_15 <= 255);
    __CPROVER_assume(sec_r001272_16 >= 0 && sec_r001272_16 <= 255);
    __CPROVER_assume(sec_r001272_17 >= 0 && sec_r001272_17 <= 255);
    __CPROVER_assume(sec_r001272_18 >= 0 && sec_r001272_18 <= 255);

    struct DeviceConfig_R001272_7213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001272_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001272_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001272_0 + 7) & 15;
    struct Transaction_R001272_7213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001272_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001272_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001272_0 + 9) & 15;

    union PacketPayload_R001272_7213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001272_7213_0(sec_r001272_0, pub_r001272_1, pub_r001272_2, pub_r001272_3);
    int helper_flow_1 = fn_R001272_7213_1(sec_r001272_1, pub_r001272_2);
    int helper_flow_2 = fn_R001272_7213_2(sec_r001272_2, pub_r001272_3, pub_r001272_4, pub_r001272_5, pub_r001272_6);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001272_9 * 3) + pub_r001272_19 + 40) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001272_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001272_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001272_14 * 3) + pub_r001272_9 + 45) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001272_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001272_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001272_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001272_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001272_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001272_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001272_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001272_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001272_14 * 3) + pub_r001272_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001272_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_12 * 3) + pub_r001272_18 + 41) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14 * 2) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001272_11 * 3) + pub_r001272_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001272_17 * 3) + pub_r001272_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_15 * 3) + pub_r001272_18 + 13) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001272_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001272_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_1 * 3) + pub_r001272_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001272_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001272_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001272_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001272_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001272_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_0 * 3) + pub_r001272_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001272_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001272_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_0 * 3) + pub_r001272_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001272_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001272_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001272_11 * 3) + pub_r001272_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001272_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001272_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001272_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001272_6 * 3) + pub_r001272_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001272_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001272_4 * 3) + pub_r001272_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001272_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001272_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001272_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001272_15 * 3) + pub_r001272_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42 * 2) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001272_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001272_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001272_5 * 3) + pub_r001272_13 + 16) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001272_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001272_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001272_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001272_11 * 3) + pub_r001272_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001272_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_0 * 3) + pub_r001272_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001272_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001272_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001272_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001272_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001272_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_45 * 3) + pub_r001272_19 + 17) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_26 * 3) + pub_r001272_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001272_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001272_12 * 3) + pub_r001272_5 + 31) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_16 * 3) + pub_r001272_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001272_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001272_9 * 3) + pub_r001272_19 + 30) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001272_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001272_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001272_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001272_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001272_0 * 3) + pub_r001272_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_29 * 3) + pub_r001272_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001272_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001272_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001272_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001272_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001272_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001272_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001272_16 * 3) + pub_r001272_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76 * 2) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_26 * 3) + pub_r001272_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001272_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001272_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001272_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001272_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001272_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001272_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_36 * 3) + pub_r001272_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001272_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001272_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001272_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_38 * 3) + pub_r001272_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001272_12 * 3) + pub_r001272_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001272_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001272_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001272_16 * 3) + pub_r001272_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_36 * 3) + pub_r001272_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001272_0 * 3) + pub_r001272_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001272_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001272_8 * 3) + pub_r001272_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001272_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001272_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001272_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001272_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001272_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001272_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001272_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001272_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001272_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001272_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001272_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001272_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_51 * 3) + pub_r001272_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001272_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001272_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_0 * 3) + pub_r001272_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001272_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_63 * 3) + pub_r001272_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001272_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_92 * 3) + pub_r001272_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001272_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001272_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001272_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_12 * 3) + pub_r001272_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_116 * 3) + pub_r001272_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_76 * 3) + pub_r001272_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001272_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001272_3 * 3) + pub_r001272_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_20 * 3) + pub_r001272_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001272_18 * 3) + pub_r001272_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126 * 2) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001272_13 * 3) + pub_r001272_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001272_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001272_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001272_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001272_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001272_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_125 * 3) + pub_r001272_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001272_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001272_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001272_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001272_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001272_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_127 * 3) + pub_r001272_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001272_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001272_3 * 3) + pub_r001272_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001272_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_58 * 3) + pub_r001272_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001272_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001272_10 * 3) + pub_r001272_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001272_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001272_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001272_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001272_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001272_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_16 * 3) + pub_r001272_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001272_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001272_9 * 3) + pub_r001272_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153 * 2) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001272_15 * 3) + pub_r001272_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001272_7 * 3) + pub_r001272_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_15 * 3) + pub_r001272_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156 * 2) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001272_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001272_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_0 * 3) + pub_r001272_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001272_12 * 3) + pub_r001272_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001272_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001272_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_112 * 3) + pub_r001272_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001272_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_16 * 3) + pub_r001272_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001272_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001272_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001272_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001272_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001272_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r001272_4 * 3) + pub_r001272_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001272_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001272_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001272_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001272_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_143 * 3) + pub_r001272_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_122 * 3) + pub_r001272_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((helper_flow_1 * 3) + pub_r001272_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001272_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001272_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001272_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001272_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_2 * 3) + pub_r001272_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001272_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001272_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001272_9 * 3) + pub_r001272_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_177 * 3) + pub_r001272_2 + 40) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001272_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_125 * 3) + pub_r001272_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001272_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001272_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001272_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001272_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001272_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_120 * 3) + pub_r001272_14 + 43) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001272_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r001272_10 * 3) + pub_r001272_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001272_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001272_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001272_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001272_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001272_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001272_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001272_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001272_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_153 * 3) + pub_r001272_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001272_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001272_10 * 3) + pub_r001272_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001272_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_76 * 3) + pub_r001272_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001272_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_68 * 3) + pub_r001272_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001272_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001272_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_195 * 3) + pub_r001272_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001272_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001272_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001272_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001272_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001272_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001272_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001272_11 * 3) + pub_r001272_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001272_2 * 3) + pub_r001272_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001272_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001272_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001272_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001272_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_145 * 3) + pub_r001272_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228 * 2) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001272_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001272_14 * 3) + pub_r001272_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001272_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001272_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_14 * 3) + pub_r001272_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001272_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_165 * 3) + pub_r001272_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001272_14 * 3) + pub_r001272_18 + 5) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001272_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001272_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_151 * 3) + pub_r001272_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_60 * 3) + pub_r001272_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001272_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001272_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001272_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001272_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001272_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001272_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001272_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001272_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001272_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001272_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001272_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_165 * 3) + pub_r001272_16 + 44) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252 * 2) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001272_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_96 * 3) + pub_r001272_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001272_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001272_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001272_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_183 * 3) + pub_r001272_15 + 35) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258 * 2) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_154 * 3) + pub_r001272_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001272_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_114 * 3) + pub_r001272_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001272_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001272_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_69 * 3) + pub_r001272_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001272_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_42 * 3) + pub_r001272_0 + 44) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_133 * 3) + pub_r001272_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001272_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((helper_flow_2 * 3) + pub_r001272_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_269 * 3) + pub_r001272_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001272_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001272_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_223 * 3) + pub_r001272_16 + 30) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r001272_14 * 3) + pub_r001272_5 + 22) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_153 * 3) + pub_r001272_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_96 * 3) + pub_r001272_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001272_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001272_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_178 * 3) + pub_r001272_1 + 41) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001272_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001272_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001272_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001272_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001272_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001272_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r001272_4 * 3) + pub_r001272_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001272_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001272_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001272_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001272_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001272_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001272_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_16 * 3) + pub_r001272_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001272_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001272_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001272_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001272_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_92 * 3) + pub_r001272_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298 * 2) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001272_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001272_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001272_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001272_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_121 * 3) + pub_r001272_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_276 * 3) + pub_r001272_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001272_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001272_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001272_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_133 * 3) + pub_r001272_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001272_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_133 * 3) + pub_r001272_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_233 * 3) + pub_r001272_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001272_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r001272_0 * 3) + pub_r001272_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001272_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_178 * 3) + pub_r001272_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001272_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001272_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001272_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_121 * 3) + pub_r001272_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001272_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_298 * 3) + pub_r001272_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_3 * 3) + pub_r001272_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001272_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((sec_r001272_18 * 3) + pub_r001272_19 + 41) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001272_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001272_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001272_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_313 * 3) + pub_r001272_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001272_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_112 * 3) + pub_r001272_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001272_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r001272_8 * 3) + pub_r001272_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001272_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_177 * 3) + pub_r001272_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001272_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_15 * 3) + pub_r001272_17 + 6) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001272_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_259 * 3) + pub_r001272_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_116 * 3) + pub_r001272_19 + 25) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_178 * 3) + pub_r001272_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_324 * 3) + pub_r001272_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_89 * 3) + pub_r001272_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001272_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_186 * 3) + pub_r001272_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344 * 2) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_45 * 3) + pub_r001272_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_88 * 3) + pub_r001272_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_178 * 3) + pub_r001272_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001272_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((helper_flow_2 * 3) + pub_r001272_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001272_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((sec_r001272_16 * 3) + pub_r001272_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001272_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001272_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001272_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001272_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001272_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_195 * 3) + pub_r001272_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_89 * 3) + pub_r001272_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001272_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001272_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001272_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001272_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001272_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001272_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_264 * 3) + pub_r001272_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_210 * 3) + pub_r001272_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_324 * 3) + pub_r001272_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001272_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001272_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_16 * 3) + pub_r001272_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001272_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001272_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001272_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001272_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001272_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_197 * 3) + pub_r001272_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001272_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001272_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001272_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001272_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001272_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_58 * 3) + pub_r001272_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_382) & 255;
    out_sink = (out_sink + stage_v_382 * 2) & 255;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_114 * 3) + pub_r001272_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001272_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_346 * 3) + pub_r001272_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001272_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001272_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001272_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001272_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001272_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_233 * 3) + pub_r001272_19 + 13) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((sec_r001272_18 * 3) + pub_r001272_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_187 * 3) + pub_r001272_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_254 * 3) + pub_r001272_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_322 * 3) + pub_r001272_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_391 * 3) + pub_r001272_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_275 * 3) + pub_r001272_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_14 * 3) + pub_r001272_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001272_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001272_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001272_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001272_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001272_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001272_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001272_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001272_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001272_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001272_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001272_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001272_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001272_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_114 * 3) + pub_r001272_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001272_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((helper_flow_0 * 3) + pub_r001272_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001272_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((sec_r001272_18 * 3) + pub_r001272_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001272_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((sec_r001272_12 * 3) + pub_r001272_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_418) & 255;
    out_sink = (out_sink + stage_v_418 * 2) & 255;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001272_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_332 * 3) + pub_r001272_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_14 * 3) + pub_r001272_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((sec_r001272_3 * 3) + pub_r001272_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_321 * 3) + pub_r001272_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001272_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001272_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_0 * 3) + pub_r001272_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_273 * 3) + pub_r001272_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001272_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001272_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001272_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001272_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001272_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001272_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_176 * 3) + pub_r001272_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001272_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001272_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001272_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_171 * 3) + pub_r001272_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001272_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001272_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001272_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_308 * 3) + pub_r001272_14 + 40) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001272_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_421 * 3) + pub_r001272_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001272_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001272_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_210 * 3) + pub_r001272_19 + 39) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001272_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001272_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_385 * 3) + pub_r001272_9 + 45) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_151 * 3) + pub_r001272_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001272_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001272_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001272_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001272_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001272_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
