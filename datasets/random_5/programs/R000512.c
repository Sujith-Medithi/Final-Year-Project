/*
 * Benchmark Program: R000512
 * Security Family: direct_leakage
 * Generator Seed: 551213
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000512_1213_0 {
    unsigned char parity;
    int timeout;
    int stop_bits;
    int buffer[3];
};

struct CipherContext_R000512_1213_1 {
    int counter;
    unsigned char tag;
    short round_key;
    int nonce;
    short flags;
    int buffer[3];
};

struct EventLog_R000512_1213_2 {
    int seq;
    int facility;
    unsigned char signature;
    int timestamp;
    unsigned char severity;
    int buffer[3];
};

union ColorPixel_R000512_1213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000512_1213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_93) & 63;
    acc ^= aux;
    int threshold_67 = (aux + st.buffer[1]) & 3;
    switch (threshold_67) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_91 = local_arr[aux % 3];
    acc = (acc + margin_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int damping_95 = (aux + st.buffer[1]) & 3;
    switch (damping_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_41 = local_arr[aux % 3];
    acc = (acc + delta_41 * 2) & 127;
    int phase_66 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_66 > 21) {
        acc = (acc + phase_66 * 2 + 5) & 127;
        aux ^= (phase_66 & 15);
    } else {
        acc = (acc - phase_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000512_1213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int scale_28 = local_arr[aux % 3];
    acc = (acc + scale_28 * 2) & 127;
    int cursor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_79 = (aux + st.buffer[1]) & 3;
    switch (anchor_79) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_43 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_43 > 44) {
        acc = (acc + segment_43 * 2 + 5) & 127;
        aux ^= (segment_43 & 15);
    } else {
        acc = (acc - segment_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_65 = local_arr[aux % 3];
    acc = (acc + offset_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_6(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_16 = local_arr[aux % 3];
    acc = (acc + vector_16 * 2) & 127;
    int vector_24 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_24 > 49) {
        acc = (acc + vector_24 * 2 + 5) & 127;
        aux ^= (vector_24 & 15);
    } else {
        acc = (acc - vector_24 + 11) & 127;
        aux += 3;
    }
    int sample_73 = (aux + st.buffer[1]) & 3;
    switch (sample_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_7(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_52 = local_arr[aux % 3];
    acc = (acc + damping_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000512_1213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_25) & 63;
    acc ^= aux;
    int stride_48 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_48 > 40) {
        acc = (acc + stride_48 * 2 + 5) & 127;
        aux ^= (stride_48 & 15);
    } else {
        acc = (acc - stride_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_50 = local_arr[aux % 3];
    acc = (acc + quotient_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_9(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int weight_47 = (aux + st.buffer[1]) & 3;
    switch (weight_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_83 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_83 > 19) {
        acc = (acc + stride_83 * 2 + 5) & 127;
        aux ^= (stride_83 & 15);
    } else {
        acc = (acc - stride_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_10(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int quantum_74 = local_arr[aux % 3];
    acc = (acc + quantum_74 * 2) & 127;
    int delta_20 = (aux + st.buffer[1]) & 3;
    switch (delta_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_11(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int threshold_46 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_46 > 40) {
        acc = (acc + threshold_46 * 2 + 5) & 127;
        aux ^= (threshold_46 & 15);
    } else {
        acc = (acc - threshold_46 + 11) & 127;
        aux += 3;
    }
    int stride_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_18 = local_arr[aux % 3];
    acc = (acc + margin_18 * 2) & 127;
    int checksum_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_13(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_87 = (aux + st.buffer[1]) & 3;
    switch (mask_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_14(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_14 = (aux + st.buffer[1]) & 3;
    switch (weight_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_72 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_72 > 39) {
        acc = (acc + accumulator_72 * 2 + 5) & 127;
        aux ^= (accumulator_72 & 15);
    } else {
        acc = (acc - accumulator_72 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000512_1213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int parity_55 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_55 > 32) {
        acc = (acc + parity_55 * 2 + 5) & 127;
        aux ^= (parity_55 & 15);
    } else {
        acc = (acc - parity_55 + 11) & 127;
        aux += 3;
    }
    int index_reg_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_60) & 63;
    acc ^= aux;
    int quotient_65 = (aux + st.buffer[1]) & 3;
    switch (quotient_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000512_1213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_22) & 63;
    acc ^= aux;
    int residue_79 = (aux + st.buffer[1]) & 3;
    switch (residue_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_17(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int scale_43 = local_arr[aux % 3];
    acc = (acc + scale_43 * 2) & 127;
    int damping_95 = (aux + st.buffer[1]) & 3;
    switch (damping_95) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000512_1213_18(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int parity_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_18 = local_arr[aux % 3];
    acc = (acc + checksum_18 * 2) & 127;
    int stride_49 = (aux + st.buffer[1]) & 3;
    switch (stride_49) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_19(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000512_1213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_93 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_93 > 43) {
        acc = (acc + coefficient_93 * 2 + 5) & 127;
        aux ^= (coefficient_93 & 15);
    } else {
        acc = (acc - coefficient_93 + 11) & 127;
        aux += 3;
    }
    int bound_18 = (aux + st.buffer[1]) & 3;
    switch (bound_18) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000512_1213_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000512_1213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int margin_45 = (aux + st.buffer[1]) & 3;
    switch (margin_45) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_37 = local_arr[aux % 3];
    acc = (acc + segment_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000512_1213_21(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000512_1213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int factor_45 = local_arr[aux % 3];
    acc = (acc + factor_45 * 2) & 127;
    int damping_26 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_26 > 32) {
        acc = (acc + damping_26 * 2 + 5) & 127;
        aux ^= (damping_26 & 15);
    } else {
        acc = (acc - damping_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000512_0;
    int sec_r000512_1;
    int sec_r000512_2;
    int sec_r000512_3;
    int sec_r000512_4;
    int sec_r000512_5;
    int sec_r000512_6;
    int sec_r000512_7;
    int sec_r000512_8;
    int sec_r000512_9;
    int sec_r000512_10;
    int sec_r000512_11;
    int sec_r000512_12;
    int sec_r000512_13;
    int sec_r000512_14;
    int sec_r000512_15;
    int pub_r000512_0;
    int pub_r000512_1;
    int pub_r000512_2;
    int pub_r000512_3;
    int pub_r000512_4;
    int pub_r000512_5;
    int pub_r000512_6;
    int pub_r000512_7;
    int pub_r000512_8;
    int pub_r000512_9;
    int pub_r000512_10;
    int pub_r000512_11;
    int pub_r000512_12;
    int pub_r000512_13;
    int pub_r000512_14;
    int pub_r000512_15;
    int pub_r000512_16;
    int pub_r000512_17;
    int pub_r000512_18;
    int pub_r000512_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000512_0 >= -100 && pub_r000512_0 <= 100);
    __CPROVER_assume(pub_r000512_1 >= -100 && pub_r000512_1 <= 100);
    __CPROVER_assume(pub_r000512_2 >= -100 && pub_r000512_2 <= 100);
    __CPROVER_assume(pub_r000512_3 >= -100 && pub_r000512_3 <= 100);
    __CPROVER_assume(pub_r000512_4 >= -100 && pub_r000512_4 <= 100);
    __CPROVER_assume(pub_r000512_5 >= -100 && pub_r000512_5 <= 100);
    __CPROVER_assume(pub_r000512_6 >= -100 && pub_r000512_6 <= 100);
    __CPROVER_assume(pub_r000512_7 >= -100 && pub_r000512_7 <= 100);
    __CPROVER_assume(pub_r000512_8 >= -100 && pub_r000512_8 <= 100);
    __CPROVER_assume(pub_r000512_9 >= -100 && pub_r000512_9 <= 100);
    __CPROVER_assume(pub_r000512_10 >= -100 && pub_r000512_10 <= 100);
    __CPROVER_assume(pub_r000512_11 >= -100 && pub_r000512_11 <= 100);
    __CPROVER_assume(pub_r000512_12 >= -100 && pub_r000512_12 <= 100);
    __CPROVER_assume(pub_r000512_13 >= -100 && pub_r000512_13 <= 100);
    __CPROVER_assume(pub_r000512_14 >= -100 && pub_r000512_14 <= 100);
    __CPROVER_assume(pub_r000512_15 >= -100 && pub_r000512_15 <= 100);
    __CPROVER_assume(pub_r000512_16 >= -100 && pub_r000512_16 <= 100);
    __CPROVER_assume(pub_r000512_17 >= -100 && pub_r000512_17 <= 100);
    __CPROVER_assume(pub_r000512_18 >= -100 && pub_r000512_18 <= 100);
    __CPROVER_assume(pub_r000512_19 >= -100 && pub_r000512_19 <= 100);
    __CPROVER_assume(sec_r000512_0 >= 0 && sec_r000512_0 <= 255);
    __CPROVER_assume(sec_r000512_1 >= 0 && sec_r000512_1 <= 255);
    __CPROVER_assume(sec_r000512_2 >= 0 && sec_r000512_2 <= 255);
    __CPROVER_assume(sec_r000512_3 >= 0 && sec_r000512_3 <= 255);
    __CPROVER_assume(sec_r000512_4 >= 0 && sec_r000512_4 <= 255);
    __CPROVER_assume(sec_r000512_5 >= 0 && sec_r000512_5 <= 255);
    __CPROVER_assume(sec_r000512_6 >= 0 && sec_r000512_6 <= 255);
    __CPROVER_assume(sec_r000512_7 >= 0 && sec_r000512_7 <= 255);
    __CPROVER_assume(sec_r000512_8 >= 0 && sec_r000512_8 <= 255);
    __CPROVER_assume(sec_r000512_9 >= 0 && sec_r000512_9 <= 255);
    __CPROVER_assume(sec_r000512_10 >= 0 && sec_r000512_10 <= 255);
    __CPROVER_assume(sec_r000512_11 >= 0 && sec_r000512_11 <= 255);
    __CPROVER_assume(sec_r000512_12 >= 0 && sec_r000512_12 <= 255);
    __CPROVER_assume(sec_r000512_13 >= 0 && sec_r000512_13 <= 255);
    __CPROVER_assume(sec_r000512_14 >= 0 && sec_r000512_14 <= 255);
    __CPROVER_assume(sec_r000512_15 >= 0 && sec_r000512_15 <= 255);

    struct DeviceConfig_R000512_1213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000512_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000512_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000512_0 + 7) & 15;
    struct CipherContext_R000512_1213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000512_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000512_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000512_0 + 9) & 15;
    struct EventLog_R000512_1213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000512_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000512_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000512_0 + 11) & 15;

    union ColorPixel_R000512_1213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 24) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 39) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 31) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 46) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 18) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 33) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r000512_15 + pub_r000512_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_29 + pub_r000512_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_30 + pub_r000512_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r000512_7 + pub_r000512_5 + 26) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_30 + pub_r000512_19 + 4) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_32 + pub_r000512_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_31 + pub_r000512_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_30 + pub_r000512_18 + 41) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_29 + pub_r000512_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_35 + pub_r000512_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r000512_7 + pub_r000512_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_35 + pub_r000512_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r000512_6 + pub_r000512_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_41 + pub_r000512_2 + 47) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r000512_11 + pub_r000512_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_39 + pub_r000512_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r000512_15 + pub_r000512_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r000512_2 + pub_r000512_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_42 + pub_r000512_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_29 + pub_r000512_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_35 + pub_r000512_15 + 35) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r000512_3 + pub_r000512_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_44 + pub_r000512_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_39 + pub_r000512_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_40 + pub_r000512_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r000512_10 + pub_r000512_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r000512_12 + pub_r000512_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r000512_8 + pub_r000512_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r000512_1 + pub_r000512_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_49 + pub_r000512_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_31 + pub_r000512_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_59 + pub_r000512_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_42 + pub_r000512_7 + 47) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r000512_13 + pub_r000512_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r000512_12 + pub_r000512_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_29 + pub_r000512_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_34 + pub_r000512_1 + 40) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r000512_12 + pub_r000512_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_52 + pub_r000512_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_48 + pub_r000512_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_30 + pub_r000512_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r000512_10 + pub_r000512_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r000512_14 + pub_r000512_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_53 + pub_r000512_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r000512_7 + pub_r000512_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_59 + pub_r000512_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r000512_10 + pub_r000512_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_69 + pub_r000512_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_36 + pub_r000512_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r000512_13 + pub_r000512_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_37 + pub_r000512_19 + 42) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_34 + pub_r000512_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r000512_0 + pub_r000512_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r000512_5 + pub_r000512_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_65 + pub_r000512_19 + 14) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_52 + pub_r000512_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_36 + pub_r000512_10 + 49) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_51 + pub_r000512_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_56 + pub_r000512_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_62 + pub_r000512_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_44 + pub_r000512_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r000512_7 + pub_r000512_3 + 45) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_70 + pub_r000512_8 + 48) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r000512_0 + pub_r000512_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r000512_0 + pub_r000512_11 + 46) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r000512_6 + pub_r000512_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r000512_2 + pub_r000512_19 + 40) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r000512_4 + pub_r000512_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r000512_14 + pub_r000512_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_77 + pub_r000512_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_94 + pub_r000512_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_74 + pub_r000512_2 + 48) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_32 + pub_r000512_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r000512_9 + pub_r000512_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r000512_15 + pub_r000512_4 + 27) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_73 + pub_r000512_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_95 + pub_r000512_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_75 + pub_r000512_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_67 + pub_r000512_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r000512_6 + pub_r000512_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r000512_11 + pub_r000512_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_39 + pub_r000512_18 + 12) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r000512_7 + pub_r000512_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r000512_0 + pub_r000512_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_93 + pub_r000512_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_46 + pub_r000512_14 + 48) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_59 + pub_r000512_9 + 48) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_103 + pub_r000512_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_101 + pub_r000512_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_56 + pub_r000512_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_103 + pub_r000512_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_41 + pub_r000512_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_40 + pub_r000512_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_59 + pub_r000512_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_48 + pub_r000512_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_41 + pub_r000512_11 + 48) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r000512_10 + pub_r000512_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_116 + pub_r000512_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r000512_12 + pub_r000512_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r000512_4 + pub_r000512_8 + 49) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r000512_7 + pub_r000512_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_58 + pub_r000512_1 + 49) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_58 + pub_r000512_8 + 49) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_63 + pub_r000512_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_76 + pub_r000512_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_73 + pub_r000512_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_94 + pub_r000512_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_126 + pub_r000512_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_33 + pub_r000512_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r000512_11 + pub_r000512_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r000512_3 + pub_r000512_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r000512_3 + pub_r000512_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_107 + pub_r000512_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r000512_14 + pub_r000512_2 + 48) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r000512_5 + pub_r000512_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r000512_7 + pub_r000512_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r000512_3 + pub_r000512_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_81 + pub_r000512_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_64 + pub_r000512_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_103 + pub_r000512_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_93 + pub_r000512_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_121 + pub_r000512_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_143 + pub_r000512_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r000512_6 + pub_r000512_2 + 43) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_76 + pub_r000512_7 + 48) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r000512_0 + pub_r000512_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_135 + pub_r000512_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r000512_1 + pub_r000512_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_124 + pub_r000512_0 + 4) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_108 + pub_r000512_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r000512_5 + pub_r000512_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r000512_14 + pub_r000512_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_67 + pub_r000512_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_154 + pub_r000512_10 + 24) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_131 + pub_r000512_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r000512_2 + pub_r000512_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_92 + pub_r000512_6 + 45) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_85 + pub_r000512_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r000512_5 + pub_r000512_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_126 + pub_r000512_12 + 46) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_125 + pub_r000512_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_158 + pub_r000512_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_74 + pub_r000512_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_159 + pub_r000512_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_169 + pub_r000512_19 + 45) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r000512_13 + pub_r000512_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_110 + pub_r000512_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_97 + pub_r000512_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_98 + pub_r000512_12 + 9) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_131 + pub_r000512_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_43 + pub_r000512_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_56 + pub_r000512_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_107 + pub_r000512_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_163 + pub_r000512_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_156 + pub_r000512_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_120 + pub_r000512_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r000512_0 + pub_r000512_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_132 + pub_r000512_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_44 + pub_r000512_17 + 24) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_179 + pub_r000512_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_79 + pub_r000512_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_69 + pub_r000512_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_115 + pub_r000512_4 + 21) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_191 + pub_r000512_3 + 47) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_42 + pub_r000512_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_190 + pub_r000512_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r000512_3 + pub_r000512_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r000512_11 + pub_r000512_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r000512_15 + pub_r000512_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_75 + pub_r000512_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_154 + pub_r000512_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r000512_2 + pub_r000512_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r000512_14 + pub_r000512_10 + 46) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_179 + pub_r000512_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_62 + pub_r000512_7 + 47) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r000512_12 + pub_r000512_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_123 + pub_r000512_18 + 40) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r000512_9 + pub_r000512_10 + 24) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r000512_11 + pub_r000512_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_152 + pub_r000512_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_183 + pub_r000512_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_38 + pub_r000512_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (sec_r000512_15 + pub_r000512_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_185 + pub_r000512_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_127 + pub_r000512_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r000512_6 + pub_r000512_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_43 + pub_r000512_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (sec_r000512_14 + pub_r000512_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_116 + pub_r000512_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (sec_r000512_13 + pub_r000512_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_190 + pub_r000512_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r000512_3 + pub_r000512_1 + 36) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_37 + pub_r000512_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_169 + pub_r000512_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_216 + pub_r000512_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_85 + pub_r000512_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_121 + pub_r000512_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_32 + pub_r000512_3 + 49) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_82 + pub_r000512_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_103 + pub_r000512_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (sec_r000512_5 + pub_r000512_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (sec_r000512_15 + pub_r000512_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_218 + pub_r000512_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (sec_r000512_12 + pub_r000512_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_211 + pub_r000512_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_106 + pub_r000512_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_60 + pub_r000512_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (sec_r000512_8 + pub_r000512_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (sec_r000512_11 + pub_r000512_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (sec_r000512_14 + pub_r000512_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_199 + pub_r000512_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_220 + pub_r000512_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (sec_r000512_4 + pub_r000512_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_107 + pub_r000512_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (sec_r000512_1 + pub_r000512_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_190 + pub_r000512_2 + 47) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_63 + pub_r000512_14 + 3) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_150 + pub_r000512_6 + 48) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (sec_r000512_5 + pub_r000512_1 + 47) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_115 + pub_r000512_4 + 27) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_104 + pub_r000512_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (sec_r000512_9 + pub_r000512_16 + 47) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (sec_r000512_12 + pub_r000512_19 + 20) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (sec_r000512_9 + pub_r000512_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_44 + pub_r000512_16 + 49) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_183 + pub_r000512_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r000512_12 + pub_r000512_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_252 + pub_r000512_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_239 + pub_r000512_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_153 + pub_r000512_19 + 4) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_229 + pub_r000512_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_168 + pub_r000512_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_246 + pub_r000512_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_209 + pub_r000512_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_214 + pub_r000512_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (sec_r000512_5 + pub_r000512_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (sec_r000512_15 + pub_r000512_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (stage_v_146 + pub_r000512_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (stage_v_249 + pub_r000512_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (sec_r000512_4 + pub_r000512_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (sec_r000512_9 + pub_r000512_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (stage_v_196 + pub_r000512_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (sec_r000512_7 + pub_r000512_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (sec_r000512_0 + pub_r000512_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (stage_v_112 + pub_r000512_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (stage_v_162 + pub_r000512_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (sec_r000512_0 + pub_r000512_18 + 9) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (stage_v_210 + pub_r000512_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (stage_v_149 + pub_r000512_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (stage_v_250 + pub_r000512_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (stage_v_192 + pub_r000512_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (stage_v_64 + pub_r000512_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (sec_r000512_15 + pub_r000512_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (sec_r000512_6 + pub_r000512_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (sec_r000512_11 + pub_r000512_17 + 49) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (sec_r000512_4 + pub_r000512_19 + 35) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (stage_v_107 + pub_r000512_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (sec_r000512_10 + pub_r000512_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (stage_v_253 + pub_r000512_14 + 31) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (stage_v_97 + pub_r000512_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (sec_r000512_10 + pub_r000512_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (stage_v_250 + pub_r000512_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (stage_v_257 + pub_r000512_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (sec_r000512_5 + pub_r000512_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (sec_r000512_2 + pub_r000512_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (sec_r000512_2 + pub_r000512_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (stage_v_216 + pub_r000512_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (stage_v_211 + pub_r000512_6 + 49) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (stage_v_66 + pub_r000512_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (stage_v_39 + pub_r000512_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (sec_r000512_10 + pub_r000512_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (sec_r000512_9 + pub_r000512_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (stage_v_38 + pub_r000512_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (sec_r000512_14 + pub_r000512_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (stage_v_300 + pub_r000512_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (sec_r000512_1 + pub_r000512_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (sec_r000512_5 + pub_r000512_11 + 48) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (sec_r000512_15 + pub_r000512_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (stage_v_44 + pub_r000512_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (stage_v_81 + pub_r000512_16 + 42) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (sec_r000512_3 + pub_r000512_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (sec_r000512_3 + pub_r000512_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (stage_v_195 + pub_r000512_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (stage_v_112 + pub_r000512_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (stage_v_180 + pub_r000512_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (stage_v_277 + pub_r000512_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (stage_v_147 + pub_r000512_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (sec_r000512_2 + pub_r000512_18 + 13) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (sec_r000512_13 + pub_r000512_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (stage_v_117 + pub_r000512_3 + 40) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (stage_v_38 + pub_r000512_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (stage_v_199 + pub_r000512_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (sec_r000512_0 + pub_r000512_16 + 46) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (stage_v_35 + pub_r000512_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (sec_r000512_3 + pub_r000512_10 + 40) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (stage_v_177 + pub_r000512_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (sec_r000512_5 + pub_r000512_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (stage_v_125 + pub_r000512_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (stage_v_54 + pub_r000512_8 + 48) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (sec_r000512_4 + pub_r000512_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (sec_r000512_13 + pub_r000512_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (stage_v_43 + pub_r000512_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (stage_v_330 + pub_r000512_3 + 46) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (stage_v_302 + pub_r000512_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (sec_r000512_11 + pub_r000512_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (stage_v_65 + pub_r000512_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (sec_r000512_2 + pub_r000512_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (sec_r000512_0 + pub_r000512_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (sec_r000512_9 + pub_r000512_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (sec_r000512_12 + pub_r000512_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (sec_r000512_10 + pub_r000512_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (stage_v_41 + pub_r000512_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (stage_v_77 + pub_r000512_15 + 17) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (stage_v_132 + pub_r000512_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (stage_v_171 + pub_r000512_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (stage_v_32 + pub_r000512_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (sec_r000512_4 + pub_r000512_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (sec_r000512_0 + pub_r000512_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (stage_v_65 + pub_r000512_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (sec_r000512_1 + pub_r000512_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (stage_v_73 + pub_r000512_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (sec_r000512_15 + pub_r000512_2 + 47) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (sec_r000512_12 + pub_r000512_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (sec_r000512_0 + pub_r000512_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (stage_v_336 + pub_r000512_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (sec_r000512_7 + pub_r000512_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (stage_v_100 + pub_r000512_19 + 34) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (sec_r000512_10 + pub_r000512_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (sec_r000512_4 + pub_r000512_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (stage_v_158 + pub_r000512_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (stage_v_190 + pub_r000512_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (stage_v_259 + pub_r000512_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (stage_v_51 + pub_r000512_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (sec_r000512_14 + pub_r000512_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (stage_v_273 + pub_r000512_16 + 46) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (stage_v_192 + pub_r000512_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (sec_r000512_5 + pub_r000512_5 + 49) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (stage_v_150 + pub_r000512_15 + 46) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
