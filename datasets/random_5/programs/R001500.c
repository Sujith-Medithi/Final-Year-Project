/*
 * Benchmark Program: R001500
 * Security Family: mixed_control_data
 * Generator Seed: 650013
 * High Inputs: 21 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001500_13_0 {
    int cutoff;
    short prev_out;
    short gain_db;
    int prev_in;
    unsigned char mode;
    int buffer[3];
};

struct CipherContext_R001500_13_1 {
    int flags;
    int iv;
    short round_key;
    short tag;
    int buffer[3];
};

struct DeviceConfig_R001500_13_2 {
    short id;
    unsigned char stop_bits;
    int parity;
    int baud_rate;
    int buffer[3];
};

union TelemetryField_R001500_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001500_13_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001500_13_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_28) & 63;
    acc ^= aux;
    int quotient_46 = (aux + st.buffer[1]) & 3;
    switch (quotient_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_1(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001500_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_45 = 0;
    for (int k = 0; k < 3; k++) {
        margin_45 = (margin_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_45) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_51 = local_arr[aux % 3];
    acc = (acc + tracker_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001500_13_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_49) & 63;
    acc ^= aux;
    int phase_62 = (aux + st.buffer[1]) & 3;
    switch (phase_62) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_3(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_27 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_27 > 21) {
        acc = (acc + quantum_27 * 2 + 5) & 127;
        aux ^= (quantum_27 & 15);
    } else {
        acc = (acc - quantum_27 + 11) & 127;
        aux += 3;
    }
    int metric_76 = 0;
    for (int k = 0; k < 2; k++) {
        metric_76 = (metric_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_76) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_59 = local_arr[aux % 3];
    acc = (acc + tracker_59 * 2) & 127;
    int mask_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001500_13_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_63) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_62 = local_arr[aux % 3];
    acc = (acc + cursor_62 * 2) & 127;
    int quotient_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_94 > 43) {
        acc = (acc + quotient_94 * 2 + 5) & 127;
        aux ^= (quotient_94 & 15);
    } else {
        acc = (acc - quotient_94 + 11) & 127;
        aux += 3;
    }
    int segment_67 = (aux + st.buffer[1]) & 3;
    switch (segment_67) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_5(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_66) & 63;
    acc ^= aux;
    int metric_73 = (aux + st.buffer[1]) & 3;
    switch (metric_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_6(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_77 = (aux + st.buffer[1]) & 3;
    switch (quantum_77) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_38 = local_arr[aux % 3];
    acc = (acc + weight_38 * 2) & 127;
    int parity_27 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_27 > 14) {
        acc = (acc + parity_27 * 2 + 5) & 127;
        aux ^= (parity_27 & 15);
    } else {
        acc = (acc - parity_27 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001500_13_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_83 = (aux + st.buffer[1]) & 3;
    switch (threshold_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_50 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_50 = (threshold_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_50) & 127;
    }
    int quantum_81 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_81 > 30) {
        acc = (acc + quantum_81 * 2 + 5) & 127;
        aux ^= (quantum_81 & 15);
    } else {
        acc = (acc - quantum_81 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001500_13_8(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_47 = local_arr[aux % 3];
    acc = (acc + index_reg_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001500_13_9(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001500_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int phase_23 = (aux + st.buffer[1]) & 3;
    switch (phase_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_70) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_78 = local_arr[aux % 3];
    acc = (acc + checksum_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001500_13_10(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_20) & 63;
    acc ^= aux;
    int phase_36 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_36 > 50) {
        acc = (acc + phase_36 * 2 + 5) & 127;
        aux ^= (phase_36 & 15);
    } else {
        acc = (acc - phase_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_46 = local_arr[aux % 3];
    acc = (acc + window_46 * 2) & 127;
    int offset_98 = (aux + st.buffer[1]) & 3;
    switch (offset_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001500_13_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int checksum_25 = local_arr[aux % 3];
    acc = (acc + checksum_25 * 2) & 127;
    int accumulator_65 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_65 = (accumulator_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_65) & 127;
    }
    int scale_69 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_69 > 41) {
        acc = (acc + scale_69 * 2 + 5) & 127;
        aux ^= (scale_69 & 15);
    } else {
        acc = (acc - scale_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001500_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_85) & 63;
    acc ^= aux;
    int margin_58 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_58 > 41) {
        acc = (acc + margin_58 * 2 + 5) & 127;
        aux ^= (margin_58 & 15);
    } else {
        acc = (acc - margin_58 + 11) & 127;
        aux += 3;
    }
    int segment_10 = (aux + st.buffer[1]) & 3;
    switch (segment_10) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001500_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int tally_97 = local_arr[aux % 3];
    acc = (acc + tally_97 * 2) & 127;
    int delta_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_93 = 0;
    for (int k = 0; k < 3; k++) {
        residue_93 = (residue_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_16(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int anchor_45 = local_arr[aux % 3];
    acc = (acc + anchor_45 * 2) & 127;
    int parity_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_94) & 63;
    acc ^= aux;
    int mask_42 = 0;
    for (int k = 0; k < 2; k++) {
        mask_42 = (mask_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_42) & 127;
    }
    int scale_58 = (aux + st.buffer[1]) & 3;
    switch (scale_58) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001500_13_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001500_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tally_96 = 0;
    for (int k = 0; k < 2; k++) {
        tally_96 = (tally_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_96) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_53 = local_arr[aux % 3];
    acc = (acc + window_53 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001500_0;
    int sec_r001500_1;
    int sec_r001500_2;
    int sec_r001500_3;
    int sec_r001500_4;
    int sec_r001500_5;
    int sec_r001500_6;
    int sec_r001500_7;
    int sec_r001500_8;
    int sec_r001500_9;
    int sec_r001500_10;
    int sec_r001500_11;
    int sec_r001500_12;
    int sec_r001500_13;
    int sec_r001500_14;
    int sec_r001500_15;
    int sec_r001500_16;
    int sec_r001500_17;
    int sec_r001500_18;
    int sec_r001500_19;
    int sec_r001500_20;
    int pub_r001500_0;
    int pub_r001500_1;
    int pub_r001500_2;
    int pub_r001500_3;
    int pub_r001500_4;
    int pub_r001500_5;
    int pub_r001500_6;
    int pub_r001500_7;
    int pub_r001500_8;
    int pub_r001500_9;
    int pub_r001500_10;
    int pub_r001500_11;
    int pub_r001500_12;
    int pub_r001500_13;
    int pub_r001500_14;
    int pub_r001500_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001500_0 >= -100 && pub_r001500_0 <= 100);
    __CPROVER_assume(pub_r001500_1 >= -100 && pub_r001500_1 <= 100);
    __CPROVER_assume(pub_r001500_2 >= -100 && pub_r001500_2 <= 100);
    __CPROVER_assume(pub_r001500_3 >= -100 && pub_r001500_3 <= 100);
    __CPROVER_assume(pub_r001500_4 >= -100 && pub_r001500_4 <= 100);
    __CPROVER_assume(pub_r001500_5 >= -100 && pub_r001500_5 <= 100);
    __CPROVER_assume(pub_r001500_6 >= -100 && pub_r001500_6 <= 100);
    __CPROVER_assume(pub_r001500_7 >= -100 && pub_r001500_7 <= 100);
    __CPROVER_assume(pub_r001500_8 >= -100 && pub_r001500_8 <= 100);
    __CPROVER_assume(pub_r001500_9 >= -100 && pub_r001500_9 <= 100);
    __CPROVER_assume(pub_r001500_10 >= -100 && pub_r001500_10 <= 100);
    __CPROVER_assume(pub_r001500_11 >= -100 && pub_r001500_11 <= 100);
    __CPROVER_assume(pub_r001500_12 >= -100 && pub_r001500_12 <= 100);
    __CPROVER_assume(pub_r001500_13 >= -100 && pub_r001500_13 <= 100);
    __CPROVER_assume(pub_r001500_14 >= -100 && pub_r001500_14 <= 100);
    __CPROVER_assume(pub_r001500_15 >= -100 && pub_r001500_15 <= 100);
    __CPROVER_assume(sec_r001500_0 >= 0 && sec_r001500_0 <= 255);
    __CPROVER_assume(sec_r001500_1 >= 0 && sec_r001500_1 <= 255);
    __CPROVER_assume(sec_r001500_2 >= 0 && sec_r001500_2 <= 255);
    __CPROVER_assume(sec_r001500_3 >= 0 && sec_r001500_3 <= 255);
    __CPROVER_assume(sec_r001500_4 >= 0 && sec_r001500_4 <= 255);
    __CPROVER_assume(sec_r001500_5 >= 0 && sec_r001500_5 <= 255);
    __CPROVER_assume(sec_r001500_6 >= 0 && sec_r001500_6 <= 255);
    __CPROVER_assume(sec_r001500_7 >= 0 && sec_r001500_7 <= 255);
    __CPROVER_assume(sec_r001500_8 >= 0 && sec_r001500_8 <= 255);
    __CPROVER_assume(sec_r001500_9 >= 0 && sec_r001500_9 <= 255);
    __CPROVER_assume(sec_r001500_10 >= 0 && sec_r001500_10 <= 255);
    __CPROVER_assume(sec_r001500_11 >= 0 && sec_r001500_11 <= 255);
    __CPROVER_assume(sec_r001500_12 >= 0 && sec_r001500_12 <= 255);
    __CPROVER_assume(sec_r001500_13 >= 0 && sec_r001500_13 <= 255);
    __CPROVER_assume(sec_r001500_14 >= 0 && sec_r001500_14 <= 255);
    __CPROVER_assume(sec_r001500_15 >= 0 && sec_r001500_15 <= 255);
    __CPROVER_assume(sec_r001500_16 >= 0 && sec_r001500_16 <= 255);
    __CPROVER_assume(sec_r001500_17 >= 0 && sec_r001500_17 <= 255);
    __CPROVER_assume(sec_r001500_18 >= 0 && sec_r001500_18 <= 255);
    __CPROVER_assume(sec_r001500_19 >= 0 && sec_r001500_19 <= 255);
    __CPROVER_assume(sec_r001500_20 >= 0 && sec_r001500_20 <= 255);

    struct FilterState_R001500_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001500_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001500_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001500_0 + 7) & 15;
    struct CipherContext_R001500_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001500_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001500_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001500_0 + 9) & 15;
    struct DeviceConfig_R001500_13_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001500_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001500_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001500_0 + 11) & 15;

    union TelemetryField_R001500_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001500_13_0(sec_r001500_0, sec_r001500_1, pub_r001500_2, pub_r001500_3);
    int helper_flow_1 = fn_R001500_13_1(sec_r001500_1, sec_r001500_2, pub_r001500_3);
    int helper_flow_2 = fn_R001500_13_2(sec_r001500_2, pub_r001500_3, pub_r001500_4, pub_r001500_5);
    int helper_flow_3 = fn_R001500_13_3(sec_r001500_3, sec_r001500_4);
    int helper_flow_4 = fn_R001500_13_4(sec_r001500_4, pub_r001500_5, pub_r001500_6, pub_r001500_7, pub_r001500_8);
    int helper_flow_5 = fn_R001500_13_5(sec_r001500_5, sec_r001500_6);
    int helper_flow_6 = fn_R001500_13_6(sec_r001500_6, pub_r001500_7, pub_r001500_8);
    int helper_flow_7 = fn_R001500_13_7(sec_r001500_7, sec_r001500_8, pub_r001500_9, pub_r001500_10);
    int helper_flow_8 = fn_R001500_13_8(sec_r001500_8, pub_r001500_9);
    int helper_flow_9 = fn_R001500_13_9(sec_r001500_9, sec_r001500_10);
    int helper_flow_10 = fn_R001500_13_10(sec_r001500_10, sec_r001500_11, pub_r001500_12);
    int helper_flow_11 = fn_R001500_13_11(sec_r001500_11, pub_r001500_12, pub_r001500_13, pub_r001500_14, pub_r001500_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001500_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_1 > 44) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001500_9 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_2 > 25) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001500_11 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001500_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_5 > 25) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001500_17 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_6 > 25) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001500_4 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_7 > 36) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_8 > 28) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001500_16 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_9 > 24) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001500_10 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_10 > 22) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001500_3 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_11 > 25) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_12 > 21) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001500_10 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_13 > 43) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001500_14 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_14 > 42) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_15 > 34) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001500_2 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_16 > 44) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001500_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_18 > 33) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001500_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001500_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001500_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_22 > 25) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_23 > 41) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001500_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001500_10 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_25 > 35) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001500_16 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_26 > 43) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001500_7 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_27 > 33) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001500_10 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_28 > 43) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_29 > 25) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_30 > 46) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001500_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001500_7 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_32 > 44) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001500_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001500_1 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_34 > 25) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001500_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_36 > 43) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_37 > 25) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001500_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_39 > 30) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_40 > 34) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_41 > 44) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_42 > 47) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001500_2 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_43 > 45) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001500_10 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_44 > 38) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_45 > 43) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_46 > 24) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_47 > 42) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_48 > 48) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_49 > 30) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_50 > 48) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_51 > 31) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001500_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_53 > 37) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001500_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001500_7 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_55 > 27) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_56 > 47) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_57 > 26) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_58 > 44) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001500_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_60 > 41) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_63 > 42) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_64 > 39) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_65 > 31) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_66 > 34) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001500_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_68 > 41) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_70 > 20) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_72 > 20) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_73 > 39) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001500_18 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_74 > 23) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_75 > 44) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001500_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_77 > 33) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001500_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_79 > 41) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_80 > 31) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001500_1 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_81 > 21) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_82 > 31) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001500_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_85 > 48) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001500_7 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001500_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001500_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_89 > 42) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_90 > 31) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001500_11 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_91 > 20) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001500_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001500_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_94 > 46) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_95 > 41) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_96 > 25) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001500_8 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_97 > 32) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001500_5 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_98 > 44) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_99 > 38) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001500_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_101 > 36) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_102 > 28) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_104 > 20) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001500_9 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_105 > 31) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_107 > 29) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001500_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_109 > 20) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001500_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001500_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_112 > 48) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_113 > 26) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_114 > 28) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001500_14 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_115 > 44) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_116 > 37) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_117 > 46) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001500_8 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_118 > 39) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001500_8 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_119 > 37) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_120 > 28) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_121 > 40) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_122 > 41) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001500_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_124 > 31) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001500_0 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_125 > 29) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001500_9 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_126 > 33) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_127 > 27) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_128 > 23) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_129 > 49) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001500_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001500_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001500_18 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_132 > 47) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001500_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_134 > 32) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_135 > 20) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001500_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_137 > 27) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_138 > 44) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001500_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001500_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_141 > 36) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_142 > 41) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_143 > 46) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001500_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_145 > 39) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_146 > 44) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001500_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_148 > 41) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_149 > 30) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_150 > 25) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_151 > 28) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001500_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_153 > 26) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001500_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_155 > 31) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_156 > 29) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_157 > 32) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_158 > 41) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_159 > 48) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_160 > 30) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_161 > 37) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_162 > 43) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_163 > 22) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_164 > 20) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_165 > 25) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001500_8 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_166 > 26) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001500_0 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_167 > 33) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001500_3 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_168 > 29) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001500_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001500_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_171 > 24) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_172 > 35) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_173 > 46) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_174 > 24) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001500_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_176 > 35) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_177 > 39) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001500_5 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_179 > 49) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_180 > 42) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_181 > 40) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001500_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001500_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_184 > 24) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_185 > 20) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001500_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_187 > 21) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_188 > 41) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_189 > 39) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_190 > 23) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001500_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_192 > 40) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001500_0) & 127;
    if (stage_v_193 > 30) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_194 > 23) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001500_12) & 127;
    if (stage_v_195 > 43) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_196 > 33) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001500_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001500_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_199 > 39) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001500_4 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_200 > 21) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_201 > 28) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_202 > 29) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001500_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_205 > 36) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_206 > 45) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_207 > 35) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001500_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r001500_14 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_209 > 40) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_210 > 47) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001500_20 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_211 > 24) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001500_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001500_2 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_213 > 36) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_214 > 29) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_216 > 39) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001500_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001500_14) & 127;
    if (stage_v_218 > 42) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_219 > 45) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_216 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_220 > 20) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_221 > 44) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001500_13) & 127;
    if (stage_v_222 > 42) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001500_3) & 127;
    if (stage_v_223 > 37) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001500_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_225 > 48) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_226 > 48) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_227 > 38) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_219 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_228 > 21) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001500_7) & 127;
    if (stage_v_229 > 26) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_230 > 23) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_231 > 42) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_232 > 23) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r001500_15 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_233 > 24) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001500_6) & 127;
    if (stage_v_234 > 35) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_235 > 31) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001500_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001500_2) & 127;
    if (stage_v_237 > 48) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001500_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_239 > 26) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_220 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_240 > 25) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001500_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001500_9) & 127;
    if (stage_v_242 > 20) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_189 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_243 > 33) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001500_15) & 127;
    if (stage_v_244 > 38) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_245 > 28) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001500_5) & 127;
    if (stage_v_246 > 23) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001500_11) & 127;
    if (stage_v_247 > 28) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001500_10) & 127;
    if (stage_v_248 > 25) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001500_1) & 127;
    if (stage_v_249 > 48) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001500_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001500_4) & 127;
    if (stage_v_251 > 32) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001500_8) & 127;
    if (stage_v_252 > 26) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
