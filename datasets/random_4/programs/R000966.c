/*
 * Benchmark Program: R000966
 * Family: mixed_control_data
 * Generator Seed: 496613
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000966_6613_0 {
    int tag;
    int round_key;
    int iv;
    int flags;
    int buffer[3];
};

struct DeviceConfig_R000966_6613_1 {
    int timeout;
    unsigned char id;
    int baud_rate;
    int buffer[3];
};

union PacketPayload_R000966_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000966_6613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000966_6613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int checksum_65 = (aux + st.buffer[1]) & 3;
    switch (checksum_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_63 = local_arr[aux % 3];
    acc = (acc + sample_63 * 2) & 127;
    int sample_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000966_6613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quotient_53 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_53 = (quotient_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_53) & 127;
    }
    int vector_94 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_94 > 47) {
        acc = (acc + vector_94 * 2 + 5) & 127;
        aux ^= (vector_94 & 15);
    } else {
        acc = (acc - vector_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int factor_20 = local_arr[aux % 3];
    acc = (acc + factor_20 * 2) & 127;
    int scale_15 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_15 > 13) {
        acc = (acc + scale_15 * 2 + 5) & 127;
        aux ^= (scale_15 & 15);
    } else {
        acc = (acc - scale_15 + 11) & 127;
        aux += 3;
    }
    int vector_20 = (aux + st.buffer[1]) & 3;
    switch (vector_20) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int sample_96 = local_arr[aux % 3];
    acc = (acc + sample_96 * 2) & 127;
    int phase_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000966_6613_4(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_82) & 63;
    acc ^= aux;
    int accumulator_72 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_72 > 38) {
        acc = (acc + accumulator_72 * 2 + 5) & 127;
        aux ^= (accumulator_72 & 15);
    } else {
        acc = (acc - accumulator_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_5(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 31) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    int vector_88 = (aux + st.buffer[1]) & 3;
    switch (vector_88) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_6(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_29 = (aux + st.buffer[1]) & 3;
    switch (pivot_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_26) & 63;
    acc ^= aux;
    int pivot_89 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_89 > 28) {
        acc = (acc + pivot_89 * 2 + 5) & 127;
        aux ^= (pivot_89 & 15);
    } else {
        acc = (acc - pivot_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_7(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_18 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_18 > 45) {
        acc = (acc + coefficient_18 * 2 + 5) & 127;
        aux ^= (coefficient_18 & 15);
    } else {
        acc = (acc - coefficient_18 + 11) & 127;
        aux += 3;
    }
    int segment_19 = (aux + st.buffer[1]) & 3;
    switch (segment_19) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int vector_72 = local_arr[aux % 3];
    acc = (acc + vector_72 * 2) & 127;
    int mask_89 = (aux + st.buffer[1]) & 3;
    switch (mask_89) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_93 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_93 = (index_reg_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_66 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_66 > 34) {
        acc = (acc + checksum_66 * 2 + 5) & 127;
        aux ^= (checksum_66 & 15);
    } else {
        acc = (acc - checksum_66 + 11) & 127;
        aux += 3;
    }
    int quantum_29 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_29 = (quantum_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_29) & 127;
    }
    int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000966_6613_10(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int residue_59 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_59 > 13) {
        acc = (acc + residue_59 * 2 + 5) & 127;
        aux ^= (residue_59 & 15);
    } else {
        acc = (acc - residue_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_96 = local_arr[aux % 3];
    acc = (acc + parity_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_11(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_35 = (aux + st.buffer[1]) & 3;
    switch (threshold_35) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_65 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_65 = (pivot_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_12(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_31) & 63;
    acc ^= aux;
    int window_76 = 0;
    for (int k = 0; k < 3; k++) {
        window_76 = (window_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_96 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_96 > 26) {
        acc = (acc + quantum_96 * 2 + 5) & 127;
        aux ^= (quantum_96 & 15);
    } else {
        acc = (acc - quantum_96 + 11) & 127;
        aux += 3;
    }
    int checksum_34 = (aux + st.buffer[1]) & 3;
    switch (checksum_34) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_92 = 0;
    for (int k = 0; k < 2; k++) {
        parity_92 = (parity_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_92) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_29 = local_arr[aux % 3];
    acc = (acc + damping_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_14(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_97 > 50) {
        acc = (acc + quotient_97 * 2 + 5) & 127;
        aux ^= (quotient_97 & 15);
    } else {
        acc = (acc - quotient_97 + 11) & 127;
        aux += 3;
    }
    int coefficient_80 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_80 = (coefficient_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_80) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_21 = local_arr[aux % 3];
    acc = (acc + sample_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_15(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_35 = (aux + st.buffer[1]) & 3;
    switch (segment_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_37 = local_arr[aux % 3];
    acc = (acc + margin_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_16(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int tally_26 = local_arr[aux % 3];
    acc = (acc + tally_26 * 2) & 127;
    int margin_87 = 0;
    for (int k = 0; k < 3; k++) {
        margin_87 = (margin_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_17(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_54 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_54 > 31) {
        acc = (acc + segment_54 * 2 + 5) & 127;
        aux ^= (segment_54 & 15);
    } else {
        acc = (acc - segment_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_52 = local_arr[aux % 3];
    acc = (acc + delta_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_18(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tracker_70 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_70 = (tracker_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_70) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_96 = local_arr[aux % 3];
    acc = (acc + phase_96 * 2) & 127;
    int quantum_92 = (aux + st.buffer[1]) & 3;
    switch (quantum_92) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int segment_74 = (aux + st.buffer[1]) & 3;
    switch (segment_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000966_6613_20(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int cursor_17 = local_arr[aux % 3];
    acc = (acc + cursor_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int threshold_59 = local_arr[aux % 3];
    acc = (acc + threshold_59 * 2) & 127;
    int stride_89 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_89 > 37) {
        acc = (acc + stride_89 * 2 + 5) & 127;
        aux ^= (stride_89 & 15);
    } else {
        acc = (acc - stride_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000966_6613_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int accumulator_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_24) & 63;
    acc ^= aux;
    int offset_26 = (aux + st.buffer[1]) & 3;
    switch (offset_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_64 = 0;
    for (int k = 0; k < 2; k++) {
        sample_64 = (sample_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_64) & 127;
    }
    int residue_99 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_99 > 25) {
        acc = (acc + residue_99 * 2 + 5) & 127;
        aux ^= (residue_99 & 15);
    } else {
        acc = (acc - residue_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000966_6613_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000966_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int cursor_77 = local_arr[aux % 3];
    acc = (acc + cursor_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000966_6613_24(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000966_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_14 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_14 > 15) {
        acc = (acc + weight_14 * 2 + 5) & 127;
        aux ^= (weight_14 & 15);
    } else {
        acc = (acc - weight_14 + 11) & 127;
        aux += 3;
    }
    int stride_65 = (aux + st.buffer[1]) & 3;
    switch (stride_65) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000966_0;
    int sec_r000966_1;
    int sec_r000966_2;
    int sec_r000966_3;
    int sec_r000966_4;
    int sec_r000966_5;
    int sec_r000966_6;
    int sec_r000966_7;
    int sec_r000966_8;
    int sec_r000966_9;
    int sec_r000966_10;
    int sec_r000966_11;
    int sec_r000966_12;
    int sec_r000966_13;
    int sec_r000966_14;
    int sec_r000966_15;
    int pub_r000966_0;
    int pub_r000966_1;
    int pub_r000966_2;
    int pub_r000966_3;
    int pub_r000966_4;
    int pub_r000966_5;
    int pub_r000966_6;
    int pub_r000966_7;
    int pub_r000966_8;
    int pub_r000966_9;
    int pub_r000966_10;
    int pub_r000966_11;
    int pub_r000966_12;
    int pub_r000966_13;
    int pub_r000966_14;
    int pub_r000966_15;
    int pub_r000966_16;
    int pub_r000966_17;
    int pub_r000966_18;
    int pub_r000966_19;
    int pub_r000966_20;
    int pub_r000966_21;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000966_0 >= -100 && pub_r000966_0 <= 100);
    __CPROVER_assume(pub_r000966_1 >= -100 && pub_r000966_1 <= 100);
    __CPROVER_assume(pub_r000966_2 >= -100 && pub_r000966_2 <= 100);
    __CPROVER_assume(pub_r000966_3 >= -100 && pub_r000966_3 <= 100);
    __CPROVER_assume(pub_r000966_4 >= -100 && pub_r000966_4 <= 100);
    __CPROVER_assume(pub_r000966_5 >= -100 && pub_r000966_5 <= 100);
    __CPROVER_assume(pub_r000966_6 >= -100 && pub_r000966_6 <= 100);
    __CPROVER_assume(pub_r000966_7 >= -100 && pub_r000966_7 <= 100);
    __CPROVER_assume(pub_r000966_8 >= -100 && pub_r000966_8 <= 100);
    __CPROVER_assume(pub_r000966_9 >= -100 && pub_r000966_9 <= 100);
    __CPROVER_assume(pub_r000966_10 >= -100 && pub_r000966_10 <= 100);
    __CPROVER_assume(pub_r000966_11 >= -100 && pub_r000966_11 <= 100);
    __CPROVER_assume(pub_r000966_12 >= -100 && pub_r000966_12 <= 100);
    __CPROVER_assume(pub_r000966_13 >= -100 && pub_r000966_13 <= 100);
    __CPROVER_assume(pub_r000966_14 >= -100 && pub_r000966_14 <= 100);
    __CPROVER_assume(pub_r000966_15 >= -100 && pub_r000966_15 <= 100);
    __CPROVER_assume(pub_r000966_16 >= -100 && pub_r000966_16 <= 100);
    __CPROVER_assume(pub_r000966_17 >= -100 && pub_r000966_17 <= 100);
    __CPROVER_assume(pub_r000966_18 >= -100 && pub_r000966_18 <= 100);
    __CPROVER_assume(pub_r000966_19 >= -100 && pub_r000966_19 <= 100);
    __CPROVER_assume(pub_r000966_20 >= -100 && pub_r000966_20 <= 100);
    __CPROVER_assume(pub_r000966_21 >= -100 && pub_r000966_21 <= 100);
    __CPROVER_assume(sec_r000966_0 >= 0 && sec_r000966_0 <= 255);
    __CPROVER_assume(sec_r000966_1 >= 0 && sec_r000966_1 <= 255);
    __CPROVER_assume(sec_r000966_2 >= 0 && sec_r000966_2 <= 255);
    __CPROVER_assume(sec_r000966_3 >= 0 && sec_r000966_3 <= 255);
    __CPROVER_assume(sec_r000966_4 >= 0 && sec_r000966_4 <= 255);
    __CPROVER_assume(sec_r000966_5 >= 0 && sec_r000966_5 <= 255);
    __CPROVER_assume(sec_r000966_6 >= 0 && sec_r000966_6 <= 255);
    __CPROVER_assume(sec_r000966_7 >= 0 && sec_r000966_7 <= 255);
    __CPROVER_assume(sec_r000966_8 >= 0 && sec_r000966_8 <= 255);
    __CPROVER_assume(sec_r000966_9 >= 0 && sec_r000966_9 <= 255);
    __CPROVER_assume(sec_r000966_10 >= 0 && sec_r000966_10 <= 255);
    __CPROVER_assume(sec_r000966_11 >= 0 && sec_r000966_11 <= 255);
    __CPROVER_assume(sec_r000966_12 >= 0 && sec_r000966_12 <= 255);
    __CPROVER_assume(sec_r000966_13 >= 0 && sec_r000966_13 <= 255);
    __CPROVER_assume(sec_r000966_14 >= 0 && sec_r000966_14 <= 255);
    __CPROVER_assume(sec_r000966_15 >= 0 && sec_r000966_15 <= 255);

    struct CipherContext_R000966_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000966_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000966_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000966_0 + 7) & 15;
    struct DeviceConfig_R000966_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000966_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000966_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000966_0 + 9) & 15;

    union PacketPayload_R000966_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 17) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 32) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 28) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 43) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 14) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 29) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 10) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 25) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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
    int stage_v_24 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
        case 0:
            out_sink = (out_sink + 4) & 255;
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 11) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 26) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 29) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 44) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 40) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 55) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 28) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 43) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 13) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 28) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 17) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 32) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 10) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 25) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 40) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 55) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 24) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 39) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 46) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
        case 0:
            out_sink = (out_sink + 4) & 255;
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 27) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 42) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
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

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (out_sink > 100) ? (chk_sum & 31) : (100 & 31);
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= (stage_v_95 << 1) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 19) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 34) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (out_sink > 100) ? (chk_sum & 31) : (109 & 31);
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= (stage_v_104 << 1) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[0] ^ 112) & 3;
    switch (stage_v_109) {
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

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_0.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = table[2];
    table[2] = (table[3] + 237) & 63;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 27) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 42) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
        case 0:
            out_sink = (out_sink + 4) & 255;
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (out_sink > 100) ? (chk_sum & 31) : (128 & 31);
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= (stage_v_123 << 1) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_128 = (stage_v_128 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 17) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 32) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[0] ^ 137) & 3;
    switch (stage_v_134) {
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

    /* Execution Pipeline Stage 135 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 55) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = table[2];
    table[2] = (table[3] + 285) & 63;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_0.buffer[2] * 2 + 445) & 63;
    if (stage_v_146 > 34) {
        out_sink = (out_sink + stage_v_146 - 5) & 255;
        if (stage_v_146 > 49) {
            chk_sum ^= (stage_v_146 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_146 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 36) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 51) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 25) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 40) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = table[3];
    table[3] = (table[0] + 319) & 63;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 161) & 15;
    int stage_v_160 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= stage_v_160;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[0] ^ 164) & 3;
    switch (stage_v_161) {
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

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000966_10 ^ 0x55) & 63;
    if (m_var > 15) {
        out_sink += (m_var * 2 + pub_r000966_4) & 127;
    } else {
        out_sink -= (m_var + 9) & 31;
    }
    out_sink ^= (sec_r000966_12 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
