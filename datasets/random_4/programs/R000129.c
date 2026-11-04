/*
 * Benchmark Program: R000129
 * Family: direct_leakage
 * Generator Seed: 412913
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000129_2913_0 {
    int threshold;
    short calib;
    short status;
    int reading;
    int buffer[3];
};

struct DeviceConfig_R000129_2913_1 {
    int id;
    short parity;
    unsigned char stop_bits;
    int timeout;
    int port;
    int buffer[3];
};

struct CipherContext_R000129_2913_2 {
    unsigned char nonce;
    unsigned char tag;
    int iv;
    int buffer[3];
};

union TelemetryField_R000129_2913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000129_2913_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000129_2913_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int damping_51 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_51 > 49) {
        acc = (acc + damping_51 * 2 + 5) & 127;
        aux ^= (damping_51 & 15);
    } else {
        acc = (acc - damping_51 + 11) & 127;
        aux += 3;
    }
    int checksum_72 = (aux + st.buffer[1]) & 3;
    switch (checksum_72) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_1(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int bound_28 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_28 > 21) {
        acc = (acc + bound_28 * 2 + 5) & 127;
        aux ^= (bound_28 & 15);
    } else {
        acc = (acc - bound_28 + 11) & 127;
        aux += 3;
    }
    int tally_22 = (aux + st.buffer[1]) & 3;
    switch (tally_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_81 = local_arr[aux % 3];
    acc = (acc + metric_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_59 = (aux + st.buffer[1]) & 3;
    switch (mask_59) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000129_2913_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_17 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_17 > 40) {
        acc = (acc + coefficient_17 * 2 + 5) & 127;
        aux ^= (coefficient_17 & 15);
    } else {
        acc = (acc - coefficient_17 + 11) & 127;
        aux += 3;
    }
    int quotient_34 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_34 = (quotient_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_34) & 127;
    }
    int bound_22 = (aux + st.buffer[1]) & 3;
    switch (bound_22) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_52) & 63;
    acc ^= aux;
    int factor_97 = (aux + st.buffer[1]) & 3;
    switch (factor_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_16 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_16 > 25) {
        acc = (acc + stride_16 * 2 + 5) & 127;
        aux ^= (stride_16 & 15);
    } else {
        acc = (acc - stride_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_10 = (aux + st.buffer[1]) & 3;
    switch (tracker_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_18) & 63;
    acc ^= aux;
    int scale_55 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_55 > 30) {
        acc = (acc + scale_55 * 2 + 5) & 127;
        aux ^= (scale_55 & 15);
    } else {
        acc = (acc - scale_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int cursor_99 = local_arr[aux % 3];
    acc = (acc + cursor_99 * 2) & 127;
    int weight_78 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_78 > 25) {
        acc = (acc + weight_78 * 2 + 5) & 127;
        aux ^= (weight_78 & 15);
    } else {
        acc = (acc - weight_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_7(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_77 = (aux + st.buffer[1]) & 3;
    switch (segment_77) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_40 = local_arr[aux % 3];
    acc = (acc + scale_40 * 2) & 127;
    int parity_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_39) & 63;
    acc ^= aux;
    int quotient_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_87 > 36) {
        acc = (acc + quotient_87 * 2 + 5) & 127;
        aux ^= (quotient_87 & 15);
    } else {
        acc = (acc - quotient_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_8(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_66 = 0;
    for (int k = 0; k < 2; k++) {
        damping_66 = (damping_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_66) & 127;
    }
    int parity_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_26) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_19 = local_arr[aux % 3];
    acc = (acc + factor_19 * 2) & 127;
    int cursor_33 = (aux + st.buffer[1]) & 3;
    switch (cursor_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int sample_77 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_77 > 50) {
        acc = (acc + sample_77 * 2 + 5) & 127;
        aux ^= (sample_77 & 15);
    } else {
        acc = (acc - sample_77 + 11) & 127;
        aux += 3;
    }
    int weight_30 = 0;
    for (int k = 0; k < 3; k++) {
        weight_30 = (weight_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_30) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_50 = local_arr[aux % 3];
    acc = (acc + accumulator_50 * 2) & 127;
    int mask_32 = (aux + st.buffer[1]) & 3;
    switch (mask_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int stride_51 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_51 > 30) {
        acc = (acc + stride_51 * 2 + 5) & 127;
        aux ^= (stride_51 & 15);
    } else {
        acc = (acc - stride_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_49 = local_arr[aux % 3];
    acc = (acc + quotient_49 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_75 = (aux + st.buffer[1]) & 3;
    switch (mask_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_61 = local_arr[aux % 3];
    acc = (acc + tally_61 * 2) & 127;
    int delta_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_10) & 63;
    acc ^= aux;
    int margin_98 = 0;
    for (int k = 0; k < 2; k++) {
        margin_98 = (margin_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_98) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_72 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_72 > 20) {
        acc = (acc + tally_72 * 2 + 5) & 127;
        aux ^= (tally_72 & 15);
    } else {
        acc = (acc - tally_72 + 11) & 127;
        aux += 3;
    }
    int margin_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_94 = local_arr[aux % 3];
    acc = (acc + factor_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int anchor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_42) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_44 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_44 > 34) {
        acc = (acc + checksum_44 * 2 + 5) & 127;
        aux ^= (checksum_44 & 15);
    } else {
        acc = (acc - checksum_44 + 11) & 127;
        aux += 3;
    }
    int anchor_57 = (aux + st.buffer[1]) & 3;
    switch (anchor_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_14(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quantum_32 = (aux + st.buffer[1]) & 3;
    switch (quantum_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_40 = local_arr[aux % 3];
    acc = (acc + quotient_40 * 2) & 127;
    int phase_60 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_60 > 34) {
        acc = (acc + phase_60 * 2 + 5) & 127;
        aux ^= (phase_60 & 15);
    } else {
        acc = (acc - phase_60 + 11) & 127;
        aux += 3;
    }
    int stride_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000129_2913_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000129_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_27 = 0;
    for (int k = 0; k < 2; k++) {
        scale_27 = (scale_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_27) & 127;
    }
    int damping_63 = (aux + st.buffer[1]) & 3;
    switch (damping_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_90 = local_arr[aux % 3];
    acc = (acc + damping_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_16(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int window_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_71 = 0;
    for (int k = 0; k < 3; k++) {
        residue_71 = (residue_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_71) & 127;
    }
    int pivot_55 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_55 > 44) {
        acc = (acc + pivot_55 * 2 + 5) & 127;
        aux ^= (pivot_55 & 15);
    } else {
        acc = (acc - pivot_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int damping_31 = 0;
    for (int k = 0; k < 3; k++) {
        damping_31 = (damping_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_31) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000129_2913_18(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_85) & 63;
    acc ^= aux;
    int tally_78 = (aux + st.buffer[1]) & 3;
    switch (tally_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_78 = local_arr[aux % 3];
    acc = (acc + residue_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000129_2913_19(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000129_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tally_18 = 0;
    for (int k = 0; k < 2; k++) {
        tally_18 = (tally_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_18) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_36 = local_arr[aux % 3];
    acc = (acc + margin_36 * 2) & 127;
    int pivot_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_32) & 63;
    acc ^= aux;
    int pivot_55 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_55 > 24) {
        acc = (acc + pivot_55 * 2 + 5) & 127;
        aux ^= (pivot_55 & 15);
    } else {
        acc = (acc - pivot_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000129_2913_20(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000129_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_91 = (aux + st.buffer[1]) & 3;
    switch (accumulator_91) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000129_0;
    int sec_r000129_1;
    int sec_r000129_2;
    int sec_r000129_3;
    int sec_r000129_4;
    int sec_r000129_5;
    int sec_r000129_6;
    int sec_r000129_7;
    int sec_r000129_8;
    int sec_r000129_9;
    int sec_r000129_10;
    int sec_r000129_11;
    int sec_r000129_12;
    int sec_r000129_13;
    int sec_r000129_14;
    int sec_r000129_15;
    int sec_r000129_16;
    int sec_r000129_17;
    int sec_r000129_18;
    int sec_r000129_19;
    int sec_r000129_20;
    int sec_r000129_21;
    int pub_r000129_0;
    int pub_r000129_1;
    int pub_r000129_2;
    int pub_r000129_3;
    int pub_r000129_4;
    int pub_r000129_5;
    int pub_r000129_6;
    int pub_r000129_7;
    int pub_r000129_8;
    int pub_r000129_9;
    int pub_r000129_10;
    int pub_r000129_11;
    int pub_r000129_12;
    int pub_r000129_13;
    int pub_r000129_14;
    int pub_r000129_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000129_0 >= -100 && pub_r000129_0 <= 100);
    __CPROVER_assume(pub_r000129_1 >= -100 && pub_r000129_1 <= 100);
    __CPROVER_assume(pub_r000129_2 >= -100 && pub_r000129_2 <= 100);
    __CPROVER_assume(pub_r000129_3 >= -100 && pub_r000129_3 <= 100);
    __CPROVER_assume(pub_r000129_4 >= -100 && pub_r000129_4 <= 100);
    __CPROVER_assume(pub_r000129_5 >= -100 && pub_r000129_5 <= 100);
    __CPROVER_assume(pub_r000129_6 >= -100 && pub_r000129_6 <= 100);
    __CPROVER_assume(pub_r000129_7 >= -100 && pub_r000129_7 <= 100);
    __CPROVER_assume(pub_r000129_8 >= -100 && pub_r000129_8 <= 100);
    __CPROVER_assume(pub_r000129_9 >= -100 && pub_r000129_9 <= 100);
    __CPROVER_assume(pub_r000129_10 >= -100 && pub_r000129_10 <= 100);
    __CPROVER_assume(pub_r000129_11 >= -100 && pub_r000129_11 <= 100);
    __CPROVER_assume(pub_r000129_12 >= -100 && pub_r000129_12 <= 100);
    __CPROVER_assume(pub_r000129_13 >= -100 && pub_r000129_13 <= 100);
    __CPROVER_assume(pub_r000129_14 >= -100 && pub_r000129_14 <= 100);
    __CPROVER_assume(pub_r000129_15 >= -100 && pub_r000129_15 <= 100);
    __CPROVER_assume(sec_r000129_0 >= 0 && sec_r000129_0 <= 255);
    __CPROVER_assume(sec_r000129_1 >= 0 && sec_r000129_1 <= 255);
    __CPROVER_assume(sec_r000129_2 >= 0 && sec_r000129_2 <= 255);
    __CPROVER_assume(sec_r000129_3 >= 0 && sec_r000129_3 <= 255);
    __CPROVER_assume(sec_r000129_4 >= 0 && sec_r000129_4 <= 255);
    __CPROVER_assume(sec_r000129_5 >= 0 && sec_r000129_5 <= 255);
    __CPROVER_assume(sec_r000129_6 >= 0 && sec_r000129_6 <= 255);
    __CPROVER_assume(sec_r000129_7 >= 0 && sec_r000129_7 <= 255);
    __CPROVER_assume(sec_r000129_8 >= 0 && sec_r000129_8 <= 255);
    __CPROVER_assume(sec_r000129_9 >= 0 && sec_r000129_9 <= 255);
    __CPROVER_assume(sec_r000129_10 >= 0 && sec_r000129_10 <= 255);
    __CPROVER_assume(sec_r000129_11 >= 0 && sec_r000129_11 <= 255);
    __CPROVER_assume(sec_r000129_12 >= 0 && sec_r000129_12 <= 255);
    __CPROVER_assume(sec_r000129_13 >= 0 && sec_r000129_13 <= 255);
    __CPROVER_assume(sec_r000129_14 >= 0 && sec_r000129_14 <= 255);
    __CPROVER_assume(sec_r000129_15 >= 0 && sec_r000129_15 <= 255);
    __CPROVER_assume(sec_r000129_16 >= 0 && sec_r000129_16 <= 255);
    __CPROVER_assume(sec_r000129_17 >= 0 && sec_r000129_17 <= 255);
    __CPROVER_assume(sec_r000129_18 >= 0 && sec_r000129_18 <= 255);
    __CPROVER_assume(sec_r000129_19 >= 0 && sec_r000129_19 <= 255);
    __CPROVER_assume(sec_r000129_20 >= 0 && sec_r000129_20 <= 255);
    __CPROVER_assume(sec_r000129_21 >= 0 && sec_r000129_21 <= 255);

    struct SensorNode_R000129_2913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000129_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000129_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000129_0 + 7) & 15;
    struct DeviceConfig_R000129_2913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000129_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000129_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000129_0 + 9) & 15;
    struct CipherContext_R000129_2913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000129_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000129_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000129_0 + 11) & 15;

    union TelemetryField_R000129_2913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 35) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 50) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
        case 0:
            out_sink = (out_sink + 9) & 255;
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 27) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 42) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 28) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 43) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
        case 0:
            out_sink = (out_sink + 3) & 255;
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 32) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 47) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
        case 0:
            out_sink = (out_sink + 3) & 255;
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
        case 0:
            out_sink = (out_sink + 9) & 255;
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 31) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 46) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
        case 0:
            out_sink = (out_sink + 5) & 255;
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 30) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 45) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 18) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 33) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 22) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 37) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 16) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 31) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 34) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 49) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
        case 0:
            out_sink = (out_sink + 2) & 255;
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 25) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 40) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 51) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = table[2];
    table[2] = (table[3] + 157) & 63;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
        case 0:
            out_sink = (out_sink + 3) & 255;
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 35) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 50) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_2.buffer[2] * 2 + 283) & 63;
    if (stage_v_92 > 33) {
        out_sink = (out_sink + stage_v_92 - 5) & 255;
        if (stage_v_92 > 48) {
            chk_sum ^= (stage_v_92 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_92 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 93 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 44) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 33) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 48) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_2.buffer[2] * 2 + 310) & 63;
    if (stage_v_101 > 28) {
        out_sink = (out_sink + stage_v_101 - 5) & 255;
        if (stage_v_101 > 43) {
            chk_sum ^= (stage_v_101 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_101 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 102 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 103) & 15;
    int stage_v_102 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= stage_v_102;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
        case 0:
            out_sink = (out_sink + 2) & 255;
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_106 = (stage_v_106 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (out_sink > 100) ? (chk_sum & 31) : (112 & 31);
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= (stage_v_107 << 1) & 127;

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (out_sink > 100) ? (chk_sum & 31) : (114 & 31);
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= (stage_v_109 << 1) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
        case 0:
            out_sink = (out_sink + 3) & 255;
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 23) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 38) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 35) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 50) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
        case 0:
            out_sink = (out_sink + 5) & 255;
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[2] * 2 + 391) & 63;
    if (stage_v_128 > 14) {
        out_sink = (out_sink + stage_v_128 - 5) & 255;
        if (stage_v_128 > 29) {
            chk_sum ^= (stage_v_128 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_128 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 21) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 36) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_1.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
        case 0:
            out_sink = (out_sink + 5) & 255;
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 27) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 42) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 11) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 26) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 141) & 15;
    int stage_v_140 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= stage_v_140;

    /* Execution Pipeline Stage 141 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
        case 0:
            out_sink = (out_sink + 5) & 255;
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

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 14) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 29) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Security Information Flow: Family = direct_leakage */
    out_sink += ((sec_r000129_7 * 2) + (sec_r000129_2 * 2)) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
