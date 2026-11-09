/*
 * Benchmark Program: R001147
 * Security Family: nested_implicit_flow
 * Generator Seed: 614713
 * High Inputs: 21 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001147_4713_0 {
    short facility;
    int severity;
    int code;
    int seq;
    int signature;
    unsigned char timestamp;
    int buffer[3];
};

struct CipherContext_R001147_4713_1 {
    int nonce;
    int iv;
    int round_key;
    int counter;
    int flags;
    int buffer[3];
};

struct DeviceConfig_R001147_4713_2 {
    int baud_rate;
    short port;
    unsigned char parity;
    int stop_bits;
    int timeout;
    int buffer[3];
};

struct Transaction_R001147_4713_3 {
    int auth_code;
    short fee;
    int rate;
    short status;
    unsigned char account_id;
    unsigned char balance;
    int buffer[3];
};

union ColorPixel_R001147_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001147_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001147_4713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_33 = (aux + st.buffer[1]) & 3;
    switch (mask_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_24 = 0;
    for (int k = 0; k < 2; k++) {
        offset_24 = (offset_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_24) & 127;
    }
    int threshold_91 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_91 > 37) {
        acc = (acc + threshold_91 * 2 + 5) & 127;
        aux ^= (threshold_91 & 15);
    } else {
        acc = (acc - threshold_91 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int index_reg_29 = (aux + st.buffer[1]) & 3;
    switch (index_reg_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_87) & 63;
    acc ^= aux;
    int phase_93 = 0;
    for (int k = 0; k < 2; k++) {
        phase_93 = (phase_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int factor_42 = 0;
    for (int k = 0; k < 2; k++) {
        factor_42 = (factor_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_42) & 127;
    }
    int anchor_69 = (aux + st.buffer[1]) & 3;
    switch (anchor_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_18 > 44) {
        acc = (acc + factor_18 * 2 + 5) & 127;
        aux ^= (factor_18 & 15);
    } else {
        acc = (acc - factor_18 + 11) & 127;
        aux += 3;
    }
    int residue_67 = (aux + st.buffer[1]) & 3;
    switch (residue_67) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_55 = 0;
    for (int k = 0; k < 3; k++) {
        damping_55 = (damping_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_20 = (aux + st.buffer[1]) & 3;
    switch (metric_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_28 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_28 = (accumulator_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_5(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_34 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_34 > 28) {
        acc = (acc + offset_34 * 2 + 5) & 127;
        aux ^= (offset_34 & 15);
    } else {
        acc = (acc - offset_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int weight_76 = local_arr[aux % 3];
    acc = (acc + weight_76 * 2) & 127;
    int index_reg_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_50) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_7(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001147_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int window_93 = 0;
    for (int k = 0; k < 2; k++) {
        window_93 = (window_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_93) & 127;
    }
    int residue_28 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_28 > 12) {
        acc = (acc + residue_28 * 2 + 5) & 127;
        aux ^= (residue_28 & 15);
    } else {
        acc = (acc - residue_28 + 11) & 127;
        aux += 3;
    }
    int phase_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_48) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_19 = local_arr[aux % 3];
    acc = (acc + bound_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_8(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_25 = 0;
    for (int k = 0; k < 3; k++) {
        damping_25 = (damping_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_25) & 127;
    }
    int vector_64 = (aux + st.buffer[1]) & 3;
    switch (vector_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_35 = local_arr[aux % 3];
    acc = (acc + stride_35 * 2) & 127;
    int anchor_64 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_64 > 26) {
        acc = (acc + anchor_64 * 2 + 5) & 127;
        aux ^= (anchor_64 & 15);
    } else {
        acc = (acc - anchor_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_56 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_56 > 37) {
        acc = (acc + stride_56 * 2 + 5) & 127;
        aux ^= (stride_56 & 15);
    } else {
        acc = (acc - stride_56 + 11) & 127;
        aux += 3;
    }
    int window_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001147_4713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int metric_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_85) & 63;
    acc ^= aux;
    int damping_48 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_48 > 33) {
        acc = (acc + damping_48 * 2 + 5) & 127;
        aux ^= (damping_48 & 15);
    } else {
        acc = (acc - damping_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int pivot_34 = local_arr[aux % 3];
    acc = (acc + pivot_34 * 2) & 127;
    int margin_27 = 0;
    for (int k = 0; k < 2; k++) {
        margin_27 = (margin_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_27) & 127;
    }
    int cursor_36 = (aux + st.buffer[1]) & 3;
    switch (cursor_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_12(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int delta_46 = local_arr[aux % 3];
    acc = (acc + delta_46 * 2) & 127;
    int bound_45 = (aux + st.buffer[1]) & 3;
    switch (bound_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_84) & 63;
    acc ^= aux;
    int vector_55 = 0;
    for (int k = 0; k < 3; k++) {
        vector_55 = (vector_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_13(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int segment_53 = local_arr[aux % 3];
    acc = (acc + segment_53 * 2) & 127;
    int accumulator_97 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_97 = (accumulator_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_97) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int coefficient_94 = local_arr[aux % 3];
    acc = (acc + coefficient_94 * 2) & 127;
    int scale_58 = 0;
    for (int k = 0; k < 3; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001147_4713_15(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001147_4713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_48 = 0;
    for (int k = 0; k < 3; k++) {
        damping_48 = (damping_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_48) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_33 = local_arr[aux % 3];
    acc = (acc + checksum_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_17(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001147_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int metric_72 = 0;
    for (int k = 0; k < 2; k++) {
        metric_72 = (metric_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_72) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_36 = local_arr[aux % 3];
    acc = (acc + anchor_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int pivot_84 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_84 = (pivot_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_84) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_71 = (aux + st.buffer[1]) & 3;
    switch (margin_71) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001147_4713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int residue_32 = 0;
    for (int k = 0; k < 2; k++) {
        residue_32 = (residue_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_32) & 127;
    }
    int quantum_78 = (aux + st.buffer[1]) & 3;
    switch (quantum_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_86 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_86 > 24) {
        acc = (acc + segment_86 * 2 + 5) & 127;
        aux ^= (segment_86 & 15);
    } else {
        acc = (acc - segment_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001147_4713_20(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int threshold_67 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_67 = (threshold_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_67) & 127;
    }
    int damping_25 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_25 > 12) {
        acc = (acc + damping_25 * 2 + 5) & 127;
        aux ^= (damping_25 & 15);
    } else {
        acc = (acc - damping_25 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001147_0;
    int sec_r001147_1;
    int sec_r001147_2;
    int sec_r001147_3;
    int sec_r001147_4;
    int sec_r001147_5;
    int sec_r001147_6;
    int sec_r001147_7;
    int sec_r001147_8;
    int sec_r001147_9;
    int sec_r001147_10;
    int sec_r001147_11;
    int sec_r001147_12;
    int sec_r001147_13;
    int sec_r001147_14;
    int sec_r001147_15;
    int sec_r001147_16;
    int sec_r001147_17;
    int sec_r001147_18;
    int sec_r001147_19;
    int sec_r001147_20;
    int pub_r001147_0;
    int pub_r001147_1;
    int pub_r001147_2;
    int pub_r001147_3;
    int pub_r001147_4;
    int pub_r001147_5;
    int pub_r001147_6;
    int pub_r001147_7;
    int pub_r001147_8;
    int pub_r001147_9;
    int pub_r001147_10;
    int pub_r001147_11;
    int pub_r001147_12;
    int pub_r001147_13;
    int pub_r001147_14;
    int pub_r001147_15;
    int pub_r001147_16;
    int pub_r001147_17;
    int pub_r001147_18;
    int pub_r001147_19;
    int pub_r001147_20;
    int pub_r001147_21;
    int pub_r001147_22;
    int pub_r001147_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001147_0 >= -100 && pub_r001147_0 <= 100);
    __CPROVER_assume(pub_r001147_1 >= -100 && pub_r001147_1 <= 100);
    __CPROVER_assume(pub_r001147_2 >= -100 && pub_r001147_2 <= 100);
    __CPROVER_assume(pub_r001147_3 >= -100 && pub_r001147_3 <= 100);
    __CPROVER_assume(pub_r001147_4 >= -100 && pub_r001147_4 <= 100);
    __CPROVER_assume(pub_r001147_5 >= -100 && pub_r001147_5 <= 100);
    __CPROVER_assume(pub_r001147_6 >= -100 && pub_r001147_6 <= 100);
    __CPROVER_assume(pub_r001147_7 >= -100 && pub_r001147_7 <= 100);
    __CPROVER_assume(pub_r001147_8 >= -100 && pub_r001147_8 <= 100);
    __CPROVER_assume(pub_r001147_9 >= -100 && pub_r001147_9 <= 100);
    __CPROVER_assume(pub_r001147_10 >= -100 && pub_r001147_10 <= 100);
    __CPROVER_assume(pub_r001147_11 >= -100 && pub_r001147_11 <= 100);
    __CPROVER_assume(pub_r001147_12 >= -100 && pub_r001147_12 <= 100);
    __CPROVER_assume(pub_r001147_13 >= -100 && pub_r001147_13 <= 100);
    __CPROVER_assume(pub_r001147_14 >= -100 && pub_r001147_14 <= 100);
    __CPROVER_assume(pub_r001147_15 >= -100 && pub_r001147_15 <= 100);
    __CPROVER_assume(pub_r001147_16 >= -100 && pub_r001147_16 <= 100);
    __CPROVER_assume(pub_r001147_17 >= -100 && pub_r001147_17 <= 100);
    __CPROVER_assume(pub_r001147_18 >= -100 && pub_r001147_18 <= 100);
    __CPROVER_assume(pub_r001147_19 >= -100 && pub_r001147_19 <= 100);
    __CPROVER_assume(pub_r001147_20 >= -100 && pub_r001147_20 <= 100);
    __CPROVER_assume(pub_r001147_21 >= -100 && pub_r001147_21 <= 100);
    __CPROVER_assume(pub_r001147_22 >= -100 && pub_r001147_22 <= 100);
    __CPROVER_assume(pub_r001147_23 >= -100 && pub_r001147_23 <= 100);
    __CPROVER_assume(sec_r001147_0 >= 0 && sec_r001147_0 <= 255);
    __CPROVER_assume(sec_r001147_1 >= 0 && sec_r001147_1 <= 255);
    __CPROVER_assume(sec_r001147_2 >= 0 && sec_r001147_2 <= 255);
    __CPROVER_assume(sec_r001147_3 >= 0 && sec_r001147_3 <= 255);
    __CPROVER_assume(sec_r001147_4 >= 0 && sec_r001147_4 <= 255);
    __CPROVER_assume(sec_r001147_5 >= 0 && sec_r001147_5 <= 255);
    __CPROVER_assume(sec_r001147_6 >= 0 && sec_r001147_6 <= 255);
    __CPROVER_assume(sec_r001147_7 >= 0 && sec_r001147_7 <= 255);
    __CPROVER_assume(sec_r001147_8 >= 0 && sec_r001147_8 <= 255);
    __CPROVER_assume(sec_r001147_9 >= 0 && sec_r001147_9 <= 255);
    __CPROVER_assume(sec_r001147_10 >= 0 && sec_r001147_10 <= 255);
    __CPROVER_assume(sec_r001147_11 >= 0 && sec_r001147_11 <= 255);
    __CPROVER_assume(sec_r001147_12 >= 0 && sec_r001147_12 <= 255);
    __CPROVER_assume(sec_r001147_13 >= 0 && sec_r001147_13 <= 255);
    __CPROVER_assume(sec_r001147_14 >= 0 && sec_r001147_14 <= 255);
    __CPROVER_assume(sec_r001147_15 >= 0 && sec_r001147_15 <= 255);
    __CPROVER_assume(sec_r001147_16 >= 0 && sec_r001147_16 <= 255);
    __CPROVER_assume(sec_r001147_17 >= 0 && sec_r001147_17 <= 255);
    __CPROVER_assume(sec_r001147_18 >= 0 && sec_r001147_18 <= 255);
    __CPROVER_assume(sec_r001147_19 >= 0 && sec_r001147_19 <= 255);
    __CPROVER_assume(sec_r001147_20 >= 0 && sec_r001147_20 <= 255);

    struct EventLog_R001147_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001147_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001147_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001147_0 + 7) & 15;
    struct CipherContext_R001147_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001147_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001147_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001147_0 + 9) & 15;
    struct DeviceConfig_R001147_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001147_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001147_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001147_0 + 11) & 15;
    struct Transaction_R001147_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001147_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001147_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001147_0 + 13) & 15;

    union ColorPixel_R001147_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001147_4713_0(sec_r001147_0, sec_r001147_1, pub_r001147_2, pub_r001147_3);
    int helper_flow_1 = fn_R001147_4713_1(sec_r001147_1, sec_r001147_2, pub_r001147_3, pub_r001147_4, pub_r001147_5);
    int helper_flow_2 = fn_R001147_4713_2(sec_r001147_2, sec_r001147_3, pub_r001147_4, pub_r001147_5);
    int helper_flow_3 = fn_R001147_4713_3(sec_r001147_3, sec_r001147_4, pub_r001147_5, pub_r001147_6, pub_r001147_7);
    int helper_flow_4 = fn_R001147_4713_4(sec_r001147_4, pub_r001147_5, pub_r001147_6);
    int helper_flow_5 = fn_R001147_4713_5(sec_r001147_5, sec_r001147_6);
    int helper_flow_6 = fn_R001147_4713_6(sec_r001147_6, sec_r001147_7, pub_r001147_8, pub_r001147_9);
    int helper_flow_7 = fn_R001147_4713_7(sec_r001147_7, sec_r001147_8);
    int helper_flow_8 = fn_R001147_4713_8(sec_r001147_8, pub_r001147_9);
    int helper_flow_9 = fn_R001147_4713_9(sec_r001147_9, sec_r001147_10, pub_r001147_11, pub_r001147_12);
    int helper_flow_10 = fn_R001147_4713_10(sec_r001147_10, sec_r001147_11, pub_r001147_12, pub_r001147_13, pub_r001147_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001147_9 ^ pub_r001147_17) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001147_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001147_5 ^ pub_r001147_15) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001147_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001147_8 ^ pub_r001147_13) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001147_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001147_6 ^ pub_r001147_13) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001147_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (stage_v_1 ^ pub_r001147_19) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001147_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_9 ^ pub_r001147_21) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001147_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001147_17 ^ pub_r001147_15) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001147_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_4 ^ pub_r001147_3) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001147_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_2 ^ pub_r001147_7) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001147_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001147_7 ^ pub_r001147_23) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001147_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001147_14 ^ pub_r001147_9) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001147_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001147_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_9 ^ pub_r001147_10) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_9 ^ pub_r001147_1) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001147_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001147_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_4 ^ pub_r001147_21) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001147_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001147_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_5 ^ pub_r001147_2) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001147_17 ^ pub_r001147_3) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001147_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_20 ^ pub_r001147_12) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_2 ^ pub_r001147_20) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001147_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001147_5 ^ pub_r001147_0) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001147_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001147_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001147_18 ^ pub_r001147_19) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r001147_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001147_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001147_13 ^ pub_r001147_22) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001147_23 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001147_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001147_8 ^ pub_r001147_19) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001147_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001147_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_3 ^ pub_r001147_20) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_2 ^ pub_r001147_23) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001147_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001147_7 ^ pub_r001147_16) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_5 ^ pub_r001147_11) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001147_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001147_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001147_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001147_15 ^ pub_r001147_14) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_9 ^ pub_r001147_17) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001147_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001147_6 ^ pub_r001147_17) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_1 ^ pub_r001147_11) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001147_14 ^ pub_r001147_8) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_44 ^ pub_r001147_15) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001147_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001147_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_3 ^ pub_r001147_0) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001147_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001147_2 ^ pub_r001147_3) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001147_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_1 ^ pub_r001147_13) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001147_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_4 ^ pub_r001147_16) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001147_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_7 ^ pub_r001147_5) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_40 ^ pub_r001147_4) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_55 ^ pub_r001147_21) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_28 ^ pub_r001147_23) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001147_9 ^ pub_r001147_17) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001147_18 ^ pub_r001147_15) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001147_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001147_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001147_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_45 ^ pub_r001147_14) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_28 ^ pub_r001147_1) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001147_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001147_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_55 ^ pub_r001147_10) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_55 ^ pub_r001147_19) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (helper_flow_4 ^ pub_r001147_17) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001147_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_22 ^ pub_r001147_17) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001147_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_37 ^ pub_r001147_1) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001147_16 ^ pub_r001147_5) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001147_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001147_20 ^ pub_r001147_17) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_58 ^ pub_r001147_21) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r001147_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001147_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_8 ^ pub_r001147_2) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001147_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_49 ^ pub_r001147_12) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r001147_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001147_9 ^ pub_r001147_14) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r001147_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001147_6 ^ pub_r001147_6) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001147_3 ^ pub_r001147_8) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_11 ^ pub_r001147_5) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_14 ^ pub_r001147_0) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001147_1 ^ pub_r001147_11) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001147_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001147_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001147_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001147_18 ^ pub_r001147_2) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001147_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001147_9 ^ pub_r001147_20) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_83 ^ pub_r001147_14) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r001147_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001147_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_26 ^ pub_r001147_8) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001147_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001147_22 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_67 ^ pub_r001147_17) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_80 ^ pub_r001147_9) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_21 ^ pub_r001147_7) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r001147_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_1 ^ pub_r001147_6) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_68 ^ pub_r001147_5) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_1 ^ pub_r001147_2) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (helper_flow_6 ^ pub_r001147_18) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001147_16 ^ pub_r001147_16) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001147_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001147_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_9 ^ pub_r001147_9) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_97 ^ pub_r001147_0) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001147_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_74 ^ pub_r001147_15) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (sec_r001147_19 ^ pub_r001147_10) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001147_20 ^ pub_r001147_4) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_34 ^ pub_r001147_15) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001147_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_4 ^ pub_r001147_0) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_9 ^ pub_r001147_0) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_79 ^ pub_r001147_2) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001147_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_10 ^ pub_r001147_11) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001147_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001147_7 ^ pub_r001147_7) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r001147_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (helper_flow_6 ^ pub_r001147_23) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_72 ^ pub_r001147_16) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (helper_flow_10 ^ pub_r001147_14) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_85 ^ pub_r001147_18) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_2 ^ pub_r001147_21) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_115 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001147_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_5 ^ pub_r001147_2) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_72 ^ pub_r001147_0) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r001147_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001147_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_56 ^ pub_r001147_6) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001147_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_81 ^ pub_r001147_23) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_3 ^ pub_r001147_22) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001147_20 ^ pub_r001147_16) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001147_23 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (helper_flow_0 ^ pub_r001147_9) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_69 ^ pub_r001147_3) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001147_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_135 ^ pub_r001147_15) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001147_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001147_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001147_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_14 ^ pub_r001147_2) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (helper_flow_0 ^ pub_r001147_23) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_143 ^ pub_r001147_20) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_9 ^ pub_r001147_1) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001147_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001147_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_74 ^ pub_r001147_5) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_115 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_3 ^ pub_r001147_3) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001147_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001147_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001147_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_11 ^ pub_r001147_20) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_143 ^ pub_r001147_21) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_119 ^ pub_r001147_7) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001147_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_142 ^ pub_r001147_10) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_106 ^ pub_r001147_15) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r001147_16 ^ pub_r001147_8) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_155 ^ pub_r001147_20) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_75 ^ pub_r001147_8) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (helper_flow_3 ^ pub_r001147_9) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001147_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001147_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_117 ^ pub_r001147_21) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_153 ^ pub_r001147_4) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_57 ^ pub_r001147_4) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001147_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_80 ^ pub_r001147_0) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001147_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001147_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001147_10 ^ pub_r001147_20) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_162 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r001147_15 ^ pub_r001147_15) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_58 ^ pub_r001147_11) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (sec_r001147_19 ^ pub_r001147_17) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_138 ^ pub_r001147_15) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_135 ^ pub_r001147_0) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_166 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001147_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001147_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001147_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_103 ^ pub_r001147_16) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
