/*
 * Benchmark Program: R001372
 * Security Family: direct_leakage
 * Generator Seed: 637213
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001372_7213_0 {
    short nonce;
    int tag;
    unsigned char flags;
    short round_key;
    int buffer[3];
};

struct Transaction_R001372_7213_1 {
    unsigned char account_id;
    int auth_code;
    int balance;
    int buffer[3];
};

struct DeviceConfig_R001372_7213_2 {
    unsigned char timeout;
    short id;
    int port;
    int buffer[3];
};

union PacketPayload_R001372_7213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001372_7213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001372_7213_0(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_16 = (aux + st.buffer[1]) & 3;
    switch (bound_16) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_66 = 0;
    for (int k = 0; k < 2; k++) {
        residue_66 = (residue_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_66) & 127;
    }
    int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001372_7213_1(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_37) & 63;
    acc ^= aux;
    int window_82 = (st.buffer[0] * 3 + aux) & 63;
    if (window_82 > 12) {
        acc = (acc + window_82 * 2 + 5) & 127;
        aux ^= (window_82 & 15);
    } else {
        acc = (acc - window_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_2(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int threshold_78 = local_arr[aux % 3];
    acc = (acc + threshold_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_78 = (aux + st.buffer[1]) & 3;
    switch (offset_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_92 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_92 > 41) {
        acc = (acc + checksum_92 * 2 + 5) & 127;
        aux ^= (checksum_92 & 15);
    } else {
        acc = (acc - checksum_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int parity_34 = local_arr[aux % 3];
    acc = (acc + parity_34 * 2) & 127;
    int quotient_40 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_40 = (quotient_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_42 = local_arr[aux % 3];
    acc = (acc + anchor_42 * 2) & 127;
    int tracker_52 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_52 = (tracker_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_5(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int quotient_17 = local_arr[aux % 3];
    acc = (acc + quotient_17 * 2) & 127;
    int residue_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001372_7213_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001372_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int metric_72 = local_arr[aux % 3];
    acc = (acc + metric_72 * 2) & 127;
    int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_45 = 0;
    for (int k = 0; k < 2; k++) {
        weight_45 = (weight_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_7(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int window_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_39 = local_arr[aux % 3];
    acc = (acc + coefficient_39 * 2) & 127;
    int metric_90 = (aux + st.buffer[1]) & 3;
    switch (metric_90) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_68 = 0;
    for (int k = 0; k < 2; k++) {
        vector_68 = (vector_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_68) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_8(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001372_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_23 = local_arr[aux % 3];
    acc = (acc + delta_23 * 2) & 127;
    int cursor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001372_7213_9(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int cursor_31 = (aux + st.buffer[1]) & 3;
    switch (cursor_31) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_53 = local_arr[aux % 3];
    acc = (acc + scale_53 * 2) & 127;
    int scale_33 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_33 > 27) {
        acc = (acc + scale_33 * 2 + 5) & 127;
        aux ^= (scale_33 & 15);
    } else {
        acc = (acc - scale_33 + 11) & 127;
        aux += 3;
    }
    int parity_62 = 0;
    for (int k = 0; k < 3; k++) {
        parity_62 = (parity_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_43 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_43 > 43) {
        acc = (acc + damping_43 * 2 + 5) & 127;
        aux ^= (damping_43 & 15);
    } else {
        acc = (acc - damping_43 + 11) & 127;
        aux += 3;
    }
    int margin_86 = (aux + st.buffer[1]) & 3;
    switch (margin_86) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_52 = local_arr[aux % 3];
    acc = (acc + scale_52 * 2) & 127;
    int anchor_82 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_82 = (anchor_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quantum_35 = (aux + st.buffer[1]) & 3;
    switch (quantum_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_62 = 0;
    for (int k = 0; k < 2; k++) {
        parity_62 = (parity_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_62) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int margin_31 = local_arr[aux % 3];
    acc = (acc + margin_31 * 2) & 127;
    int cursor_76 = (aux + st.buffer[1]) & 3;
    switch (cursor_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int stride_13 = local_arr[aux % 3];
    acc = (acc + stride_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_14(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001372_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int weight_89 = local_arr[aux % 3];
    acc = (acc + weight_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001372_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_41 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_41 = (coefficient_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_41) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_59 = local_arr[aux % 3];
    acc = (acc + offset_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_92 = (aux + st.buffer[1]) & 3;
    switch (anchor_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_82) & 63;
    acc ^= aux;
    int pivot_87 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_87 = (pivot_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_87) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_17(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int metric_30 = local_arr[aux % 3];
    acc = (acc + metric_30 * 2) & 127;
    int tracker_60 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_60 = (tracker_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_60) & 127;
    }
    int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001372_7213_18(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001372_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int residue_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_23) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_69 = local_arr[aux % 3];
    acc = (acc + threshold_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001372_7213_19(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_84 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_84 > 39) {
        acc = (acc + delta_84 * 2 + 5) & 127;
        aux ^= (delta_84 & 15);
    } else {
        acc = (acc - delta_84 + 11) & 127;
        aux += 3;
    }
    int factor_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_71) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_20 = (aux + st.buffer[1]) & 3;
    switch (delta_20) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001372_7213_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001372_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_75) & 63;
    acc ^= aux;
    int threshold_88 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_88 > 20) {
        acc = (acc + threshold_88 * 2 + 5) & 127;
        aux ^= (threshold_88 & 15);
    } else {
        acc = (acc - threshold_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_15 = local_arr[aux % 3];
    acc = (acc + quantum_15 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001372_0;
    int sec_r001372_1;
    int sec_r001372_2;
    int sec_r001372_3;
    int sec_r001372_4;
    int sec_r001372_5;
    int sec_r001372_6;
    int sec_r001372_7;
    int sec_r001372_8;
    int sec_r001372_9;
    int sec_r001372_10;
    int sec_r001372_11;
    int sec_r001372_12;
    int sec_r001372_13;
    int sec_r001372_14;
    int sec_r001372_15;
    int pub_r001372_0;
    int pub_r001372_1;
    int pub_r001372_2;
    int pub_r001372_3;
    int pub_r001372_4;
    int pub_r001372_5;
    int pub_r001372_6;
    int pub_r001372_7;
    int pub_r001372_8;
    int pub_r001372_9;
    int pub_r001372_10;
    int pub_r001372_11;
    int pub_r001372_12;
    int pub_r001372_13;
    int pub_r001372_14;
    int pub_r001372_15;
    int pub_r001372_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001372_0 >= -100 && pub_r001372_0 <= 100);
    __CPROVER_assume(pub_r001372_1 >= -100 && pub_r001372_1 <= 100);
    __CPROVER_assume(pub_r001372_2 >= -100 && pub_r001372_2 <= 100);
    __CPROVER_assume(pub_r001372_3 >= -100 && pub_r001372_3 <= 100);
    __CPROVER_assume(pub_r001372_4 >= -100 && pub_r001372_4 <= 100);
    __CPROVER_assume(pub_r001372_5 >= -100 && pub_r001372_5 <= 100);
    __CPROVER_assume(pub_r001372_6 >= -100 && pub_r001372_6 <= 100);
    __CPROVER_assume(pub_r001372_7 >= -100 && pub_r001372_7 <= 100);
    __CPROVER_assume(pub_r001372_8 >= -100 && pub_r001372_8 <= 100);
    __CPROVER_assume(pub_r001372_9 >= -100 && pub_r001372_9 <= 100);
    __CPROVER_assume(pub_r001372_10 >= -100 && pub_r001372_10 <= 100);
    __CPROVER_assume(pub_r001372_11 >= -100 && pub_r001372_11 <= 100);
    __CPROVER_assume(pub_r001372_12 >= -100 && pub_r001372_12 <= 100);
    __CPROVER_assume(pub_r001372_13 >= -100 && pub_r001372_13 <= 100);
    __CPROVER_assume(pub_r001372_14 >= -100 && pub_r001372_14 <= 100);
    __CPROVER_assume(pub_r001372_15 >= -100 && pub_r001372_15 <= 100);
    __CPROVER_assume(pub_r001372_16 >= -100 && pub_r001372_16 <= 100);
    __CPROVER_assume(sec_r001372_0 >= 0 && sec_r001372_0 <= 255);
    __CPROVER_assume(sec_r001372_1 >= 0 && sec_r001372_1 <= 255);
    __CPROVER_assume(sec_r001372_2 >= 0 && sec_r001372_2 <= 255);
    __CPROVER_assume(sec_r001372_3 >= 0 && sec_r001372_3 <= 255);
    __CPROVER_assume(sec_r001372_4 >= 0 && sec_r001372_4 <= 255);
    __CPROVER_assume(sec_r001372_5 >= 0 && sec_r001372_5 <= 255);
    __CPROVER_assume(sec_r001372_6 >= 0 && sec_r001372_6 <= 255);
    __CPROVER_assume(sec_r001372_7 >= 0 && sec_r001372_7 <= 255);
    __CPROVER_assume(sec_r001372_8 >= 0 && sec_r001372_8 <= 255);
    __CPROVER_assume(sec_r001372_9 >= 0 && sec_r001372_9 <= 255);
    __CPROVER_assume(sec_r001372_10 >= 0 && sec_r001372_10 <= 255);
    __CPROVER_assume(sec_r001372_11 >= 0 && sec_r001372_11 <= 255);
    __CPROVER_assume(sec_r001372_12 >= 0 && sec_r001372_12 <= 255);
    __CPROVER_assume(sec_r001372_13 >= 0 && sec_r001372_13 <= 255);
    __CPROVER_assume(sec_r001372_14 >= 0 && sec_r001372_14 <= 255);
    __CPROVER_assume(sec_r001372_15 >= 0 && sec_r001372_15 <= 255);

    struct CipherContext_R001372_7213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001372_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001372_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001372_0 + 7) & 15;
    struct Transaction_R001372_7213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001372_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001372_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001372_0 + 9) & 15;
    struct DeviceConfig_R001372_7213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001372_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001372_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001372_0 + 11) & 15;

    union PacketPayload_R001372_7213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001372_7213_0(sec_r001372_0, sec_r001372_1, pub_r001372_2);
    int helper_flow_1 = fn_R001372_7213_1(sec_r001372_1, sec_r001372_2);
    int helper_flow_2 = fn_R001372_7213_2(sec_r001372_2, pub_r001372_3);
    int helper_flow_3 = fn_R001372_7213_3(sec_r001372_3, sec_r001372_4, pub_r001372_5, pub_r001372_6, pub_r001372_7);
    int helper_flow_4 = fn_R001372_7213_4(sec_r001372_4, sec_r001372_5, pub_r001372_6, pub_r001372_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001372_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001372_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001372_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001372_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001372_2 * 3) + pub_r001372_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001372_1 * 3) + pub_r001372_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001372_6 * 3) + pub_r001372_5 + 31) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001372_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_2 * 3) + pub_r001372_3 + 45) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001372_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_6 * 3) + pub_r001372_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001372_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001372_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001372_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001372_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_10 * 3) + pub_r001372_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001372_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001372_9 * 3) + pub_r001372_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001372_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001372_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001372_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001372_3 * 3) + pub_r001372_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001372_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001372_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001372_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001372_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001372_2 * 3) + pub_r001372_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_0 * 3) + pub_r001372_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001372_6 * 3) + pub_r001372_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001372_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001372_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001372_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_3 * 3) + pub_r001372_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_10 * 3) + pub_r001372_11 + 42) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001372_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001372_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001372_8 * 3) + pub_r001372_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001372_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001372_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001372_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001372_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001372_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_15 * 3) + pub_r001372_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42 * 2) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001372_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001372_6 * 3) + pub_r001372_5 + 26) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001372_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001372_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001372_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_8 * 3) + pub_r001372_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001372_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001372_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001372_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001372_1 * 3) + pub_r001372_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001372_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001372_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001372_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001372_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001372_0 * 3) + pub_r001372_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001372_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001372_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001372_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001372_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_21 * 3) + pub_r001372_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001372_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001372_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001372_1 * 3) + pub_r001372_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_8 * 3) + pub_r001372_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001372_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001372_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001372_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001372_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001372_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_15 * 3) + pub_r001372_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001372_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001372_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001372_11 * 3) + pub_r001372_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001372_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001372_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001372_8 * 3) + pub_r001372_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001372_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001372_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001372_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001372_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001372_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001372_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001372_14 * 3) + pub_r001372_16 + 4) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001372_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001372_4 * 3) + pub_r001372_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001372_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_17 * 3) + pub_r001372_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001372_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001372_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001372_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001372_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001372_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001372_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001372_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001372_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_36 * 3) + pub_r001372_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_26 * 3) + pub_r001372_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001372_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001372_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001372_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001372_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001372_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001372_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001372_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001372_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001372_5 * 3) + pub_r001372_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001372_13 * 3) + pub_r001372_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001372_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001372_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001372_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001372_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001372_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001372_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((helper_flow_2 * 3) + pub_r001372_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_99 * 3) + pub_r001372_8 + 40) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_78 * 3) + pub_r001372_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_27 * 3) + pub_r001372_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001372_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001372_1 * 3) + pub_r001372_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001372_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001372_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_65 * 3) + pub_r001372_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001372_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001372_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001372_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_52 * 3) + pub_r001372_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001372_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001372_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001372_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_117 * 3) + pub_r001372_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001372_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001372_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_87 * 3) + pub_r001372_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001372_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001372_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001372_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001372_1 * 3) + pub_r001372_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001372_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001372_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001372_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001372_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001372_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_109 * 3) + pub_r001372_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001372_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001372_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_26 * 3) + pub_r001372_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001372_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001372_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001372_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001372_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001372_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001372_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001372_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001372_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001372_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_36 * 3) + pub_r001372_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001372_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001372_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_33 * 3) + pub_r001372_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_85 * 3) + pub_r001372_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001372_0 * 3) + pub_r001372_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001372_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_87 * 3) + pub_r001372_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_132 * 3) + pub_r001372_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001372_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_42 * 3) + pub_r001372_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001372_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_165 * 3) + pub_r001372_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_166 * 3) + pub_r001372_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_121 * 3) + pub_r001372_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001372_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001372_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001372_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001372_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001372_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001372_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_148 * 3) + pub_r001372_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_98 * 3) + pub_r001372_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001372_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_117 * 3) + pub_r001372_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_65 * 3) + pub_r001372_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001372_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001372_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001372_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_89 * 3) + pub_r001372_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001372_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001372_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_1 * 3) + pub_r001372_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r001372_11 * 3) + pub_r001372_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_124 * 3) + pub_r001372_10 + 12) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192 * 2) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001372_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001372_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001372_4 * 3) + pub_r001372_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001372_10 * 3) + pub_r001372_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_17 * 3) + pub_r001372_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001372_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001372_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_99 * 3) + pub_r001372_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001372_8 * 3) + pub_r001372_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_85 * 3) + pub_r001372_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001372_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001372_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_124 * 3) + pub_r001372_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001372_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_170 * 3) + pub_r001372_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_27 * 3) + pub_r001372_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_139 * 3) + pub_r001372_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209 * 2) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_21 * 3) + pub_r001372_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001372_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r001372_11 * 3) + pub_r001372_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001372_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001372_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_132 * 3) + pub_r001372_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_121 * 3) + pub_r001372_1 + 43) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001372_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001372_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001372_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001372_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r001372_10 * 3) + pub_r001372_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001372_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001372_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_36 * 3) + pub_r001372_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001372_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001372_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001372_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001372_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001372_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001372_1 * 3) + pub_r001372_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001372_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r001372_7 * 3) + pub_r001372_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001372_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001372_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_132 * 3) + pub_r001372_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001372_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_200 * 3) + pub_r001372_10 + 12) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001372_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_180 * 3) + pub_r001372_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001372_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001372_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001372_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_135 * 3) + pub_r001372_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243 * 2) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_221 * 3) + pub_r001372_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_98 * 3) + pub_r001372_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245 * 2) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_78 * 3) + pub_r001372_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_27 * 3) + pub_r001372_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001372_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001372_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001372_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001372_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001372_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001372_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_52 * 3) + pub_r001372_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001372_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001372_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001372_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001372_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_33 * 3) + pub_r001372_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_163 * 3) + pub_r001372_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001372_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r001372_0 * 3) + pub_r001372_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_180 * 3) + pub_r001372_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001372_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001372_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_162 * 3) + pub_r001372_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_224 * 3) + pub_r001372_13 + 41) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001372_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001372_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001372_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_254 * 3) + pub_r001372_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_135 * 3) + pub_r001372_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272 * 2) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001372_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001372_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001372_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_195 * 3) + pub_r001372_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001372_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001372_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_66 * 3) + pub_r001372_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_224 * 3) + pub_r001372_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001372_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_117 * 3) + pub_r001372_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001372_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((sec_r001372_8 * 3) + pub_r001372_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_98 * 3) + pub_r001372_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001372_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001372_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_201 * 3) + pub_r001372_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_243 * 3) + pub_r001372_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001372_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_183 * 3) + pub_r001372_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001372_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_36 * 3) + pub_r001372_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001372_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_158 * 3) + pub_r001372_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001372_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001372_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001372_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001372_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_279 * 3) + pub_r001372_5 + 22) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_288 * 3) + pub_r001372_7 + 40) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001372_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_163 * 3) + pub_r001372_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_254 * 3) + pub_r001372_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_303 * 3) + pub_r001372_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001372_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r001372_0 * 3) + pub_r001372_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001372_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001372_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_21 * 3) + pub_r001372_0 + 5) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_27 * 3) + pub_r001372_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_119 * 3) + pub_r001372_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001372_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_260 * 3) + pub_r001372_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_183 * 3) + pub_r001372_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r001372_6 * 3) + pub_r001372_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_263 * 3) + pub_r001372_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_311 * 3) + pub_r001372_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001372_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001372_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_280 * 3) + pub_r001372_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001372_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001372_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001372_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_108 * 3) + pub_r001372_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001372_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r001372_0 * 3) + pub_r001372_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001372_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001372_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001372_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001372_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001372_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001372_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_168 * 3) + pub_r001372_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001372_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001372_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001372_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001372_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001372_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_291 * 3) + pub_r001372_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r001372_1 * 3) + pub_r001372_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001372_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001372_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001372_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_87 * 3) + pub_r001372_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001372_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001372_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001372_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_284 * 3) + pub_r001372_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_207 * 3) + pub_r001372_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_33 * 3) + pub_r001372_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001372_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_304 * 3) + pub_r001372_4 + 25) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001372_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001372_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001372_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001372_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_32 * 3) + pub_r001372_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001372_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001372_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001372_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_295 * 3) + pub_r001372_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362 * 2) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_216 * 3) + pub_r001372_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001372_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001372_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_5 * 3) + pub_r001372_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_230 * 3) + pub_r001372_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001372_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001372_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_8 * 3) + pub_r001372_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_363 * 3) + pub_r001372_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001372_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_118 * 3) + pub_r001372_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_363 * 3) + pub_r001372_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_289 * 3) + pub_r001372_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001372_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001372_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_162 * 3) + pub_r001372_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001372_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001372_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001372_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_280 * 3) + pub_r001372_16 + 38) & 127;
    sec_accum = (sec_accum + stage_v_382) & 255;
    out_sink = (out_sink + stage_v_382 * 2) & 255;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_280 * 3) + pub_r001372_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001372_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_27 * 3) + pub_r001372_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_267 * 3) + pub_r001372_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_271 * 3) + pub_r001372_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_387) & 255;
    out_sink = (out_sink + stage_v_387 * 2) & 255;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001372_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_168 * 3) + pub_r001372_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_321 * 3) + pub_r001372_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001372_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001372_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001372_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001372_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001372_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001372_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001372_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001372_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001372_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001372_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_128 * 3) + pub_r001372_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_316 * 3) + pub_r001372_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_293 * 3) + pub_r001372_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001372_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001372_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001372_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((helper_flow_2 * 3) + pub_r001372_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001372_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001372_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001372_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001372_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001372_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001372_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001372_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_200 * 3) + pub_r001372_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_32 * 3) + pub_r001372_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001372_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001372_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_341 * 3) + pub_r001372_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001372_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001372_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_239 * 3) + pub_r001372_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001372_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001372_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_366 * 3) + pub_r001372_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_235 * 3) + pub_r001372_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001372_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001372_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((helper_flow_4 * 3) + pub_r001372_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((sec_r001372_11 * 3) + pub_r001372_15 + 32) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001372_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001372_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001372_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_116 * 3) + pub_r001372_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001372_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001372_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001372_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_284 * 3) + pub_r001372_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001372_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001372_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001372_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001372_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001372_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001372_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_373 * 3) + pub_r001372_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_445) & 255;
    out_sink = (out_sink + stage_v_445 * 2) & 255;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001372_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001372_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001372_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001372_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_210 * 3) + pub_r001372_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001372_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001372_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001372_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001372_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001372_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((helper_flow_3 * 3) + pub_r001372_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001372_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001372_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001372_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001372_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_196 * 3) + pub_r001372_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_139 * 3) + pub_r001372_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_462) & 255;
    out_sink = (out_sink + stage_v_462 * 2) & 255;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001372_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_224 * 3) + pub_r001372_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001372_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001372_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001372_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001372_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001372_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001372_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((sec_r001372_8 * 3) + pub_r001372_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_78 * 3) + pub_r001372_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001372_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_28 * 3) + pub_r001372_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_284 * 3) + pub_r001372_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = ((stage_v_401 * 3) + pub_r001372_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_476) & 255;
    out_sink = (out_sink + stage_v_476 * 2) & 255;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_17 * 3) + pub_r001372_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_477) & 255;
    out_sink = (out_sink + stage_v_477 * 2) & 255;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001372_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_42 * 3) + pub_r001372_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_479) & 255;
    out_sink = (out_sink + stage_v_479 * 2) & 255;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001372_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001372_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_237 * 3) + pub_r001372_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_482) & 255;
    out_sink = (out_sink + stage_v_482 * 2) & 255;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001372_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001372_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001372_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001372_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((sec_r001372_5 * 3) + pub_r001372_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_487) & 255;
    out_sink = (out_sink + stage_v_487 * 2) & 255;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001372_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001372_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001372_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001372_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001372_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_293 * 3) + pub_r001372_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_493) & 255;
    out_sink = (out_sink + stage_v_493 * 2) & 255;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001372_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((stage_v_247 * 3) + pub_r001372_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_495) & 255;
    out_sink = (out_sink + stage_v_495 * 2) & 255;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001372_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001372_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((stage_v_284 * 3) + pub_r001372_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_498) & 255;
    out_sink = (out_sink + stage_v_498 * 2) & 255;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001372_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001372_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001372_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001372_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001372_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001372_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001372_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001372_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001372_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_145 * 3) + pub_r001372_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_508) & 255;
    out_sink = (out_sink + stage_v_508 * 2) & 255;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001372_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001372_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001372_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = ((stage_v_259 * 3) + pub_r001372_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_512) & 255;
    out_sink = (out_sink + stage_v_512 * 2) & 255;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = ((stage_v_362 * 3) + pub_r001372_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_513) & 255;
    out_sink = (out_sink + stage_v_513 * 2) & 255;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_182 * 3) + pub_r001372_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001372_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = ((stage_v_6 * 3) + pub_r001372_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_516) & 255;
    out_sink = (out_sink + stage_v_516 * 2) & 255;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001372_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = (pub_r001372_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_518) & 127;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = ((stage_v_165 * 3) + pub_r001372_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_519) & 255;
    out_sink = (out_sink + stage_v_519 * 2) & 255;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001372_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
