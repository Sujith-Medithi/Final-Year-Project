/*
 * Benchmark Program: R000535
 * Family: implicit_flow
 * Generator Seed: 453513
 * High Inputs: 21 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000535_3513_0 {
    short baud_rate;
    unsigned char port;
    unsigned char stop_bits;
    short id;
    int buffer[3];
};

struct SensorNode_R000535_3513_1 {
    int reading;
    unsigned char status;
    unsigned char threshold;
    short offset;
    short gain;
    int buffer[3];
};

struct CipherContext_R000535_3513_2 {
    int counter;
    int nonce;
    int flags;
    int buffer[3];
};

union RegisterBank_R000535_3513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000535_3513_0(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int sample_46 = 0;
    for (int k = 0; k < 2; k++) {
        sample_46 = (sample_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_46) & 127;
    }
    int factor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_87 = local_arr[aux % 3];
    acc = (acc + anchor_87 * 2) & 127;
    int damping_11 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_11 > 44) {
        acc = (acc + damping_11 * 2 + 5) & 127;
        aux ^= (damping_11 & 15);
    } else {
        acc = (acc - damping_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_26 = (aux + st.buffer[1]) & 3;
    switch (delta_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_22 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_22 > 17) {
        acc = (acc + stride_22 * 2 + 5) & 127;
        aux ^= (stride_22 & 15);
    } else {
        acc = (acc - stride_22 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_2(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int pivot_66 = local_arr[aux % 3];
    acc = (acc + pivot_66 * 2) & 127;
    int cursor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_48) & 63;
    acc ^= aux;
    int factor_23 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_23 > 33) {
        acc = (acc + factor_23 * 2 + 5) & 127;
        aux ^= (factor_23 & 15);
    } else {
        acc = (acc - factor_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_87) & 63;
    acc ^= aux;
    int residue_14 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_14 > 45) {
        acc = (acc + residue_14 * 2 + 5) & 127;
        aux ^= (residue_14 & 15);
    } else {
        acc = (acc - residue_14 + 11) & 127;
        aux += 3;
    }
    int scale_75 = (aux + st.buffer[1]) & 3;
    switch (scale_75) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_4(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_33 > 17) {
        acc = (acc + anchor_33 * 2 + 5) & 127;
        aux ^= (anchor_33 & 15);
    } else {
        acc = (acc - anchor_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_65 = (aux + st.buffer[1]) & 3;
    switch (sample_65) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_54 = local_arr[aux % 3];
    acc = (acc + checksum_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_5(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_77 > 28) {
        acc = (acc + cursor_77 * 2 + 5) & 127;
        aux ^= (cursor_77 & 15);
    } else {
        acc = (acc - cursor_77 + 11) & 127;
        aux += 3;
    }
    int threshold_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_52) & 63;
    acc ^= aux;
    int residue_14 = 0;
    for (int k = 0; k < 3; k++) {
        residue_14 = (residue_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_14) & 127;
    }
    int mask_73 = (aux + st.buffer[1]) & 3;
    switch (mask_73) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_6(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_72 = local_arr[aux % 3];
    acc = (acc + phase_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_7(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_92 = (aux + st.buffer[1]) & 3;
    switch (mask_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_85 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_85 > 32) {
        acc = (acc + delta_85 * 2 + 5) & 127;
        aux ^= (delta_85 & 15);
    } else {
        acc = (acc - delta_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_64 = (aux + st.buffer[1]) & 3;
    switch (stride_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_70) & 63;
    acc ^= aux;
    int index_reg_40 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_40 = (index_reg_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int anchor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_33 > 50) {
        acc = (acc + anchor_33 * 2 + 5) & 127;
        aux ^= (anchor_33 & 15);
    } else {
        acc = (acc - anchor_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_10(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_97 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_97 = (coefficient_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_97) & 127;
    }
    int threshold_72 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_72 > 21) {
        acc = (acc + threshold_72 * 2 + 5) & 127;
        aux ^= (threshold_72 & 15);
    } else {
        acc = (acc - threshold_72 + 11) & 127;
        aux += 3;
    }
    int pivot_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_11(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int residue_24 = local_arr[aux % 3];
    acc = (acc + residue_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_12(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    int quantum_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_75 > 30) {
        acc = (acc + quantum_75 * 2 + 5) & 127;
        aux ^= (quantum_75 & 15);
    } else {
        acc = (acc - quantum_75 + 11) & 127;
        aux += 3;
    }
    int offset_35 = (aux + st.buffer[1]) & 3;
    switch (offset_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_77 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_77 > 21) {
        acc = (acc + tracker_77 * 2 + 5) & 127;
        aux ^= (tracker_77 & 15);
    } else {
        acc = (acc - tracker_77 + 11) & 127;
        aux += 3;
    }
    int scale_28 = 0;
    for (int k = 0; k < 2; k++) {
        scale_28 = (scale_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_14(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_83) & 63;
    acc ^= aux;
    int scale_80 = 0;
    for (int k = 0; k < 2; k++) {
        scale_80 = (scale_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_80) & 127;
    }
    int pivot_29 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_29 > 43) {
        acc = (acc + pivot_29 * 2 + 5) & 127;
        aux ^= (pivot_29 & 15);
    } else {
        acc = (acc - pivot_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_57 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_57 = (quantum_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_57) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_16(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_45 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_45 > 15) {
        acc = (acc + residue_45 * 2 + 5) & 127;
        aux ^= (residue_45 & 15);
    } else {
        acc = (acc - residue_45 + 11) & 127;
        aux += 3;
    }
    int accumulator_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_48) & 63;
    acc ^= aux;
    int quotient_37 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_37 = (quotient_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_37) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_17(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tally_42 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_42 > 35) {
        acc = (acc + tally_42 * 2 + 5) & 127;
        aux ^= (tally_42 & 15);
    } else {
        acc = (acc - tally_42 + 11) & 127;
        aux += 3;
    }
    int segment_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_18(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_45 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_45 > 45) {
        acc = (acc + weight_45 * 2 + 5) & 127;
        aux ^= (weight_45 & 15);
    } else {
        acc = (acc - weight_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_83 = 0;
    for (int k = 0; k < 3; k++) {
        margin_83 = (margin_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_83) & 127;
    }
    int checksum_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_29 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_29 > 50) {
        acc = (acc + quotient_29 * 2 + 5) & 127;
        aux ^= (quotient_29 & 15);
    } else {
        acc = (acc - quotient_29 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_73 = local_arr[aux % 3];
    acc = (acc + quantum_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_20(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_84 = (aux + st.buffer[1]) & 3;
    switch (scale_84) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_79) & 63;
    acc ^= aux;
    int segment_38 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_38 > 12) {
        acc = (acc + segment_38 * 2 + 5) & 127;
        aux ^= (segment_38 & 15);
    } else {
        acc = (acc - segment_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_21(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_64 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_64 = (checksum_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_64) & 127;
    }
    int sample_23 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_23 > 11) {
        acc = (acc + sample_23 * 2 + 5) & 127;
        aux ^= (sample_23 & 15);
    } else {
        acc = (acc - sample_23 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_98 = local_arr[aux % 3];
    acc = (acc + checksum_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_22(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_21 = 0;
    for (int k = 0; k < 2; k++) {
        bound_21 = (bound_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_21) & 127;
    }
    int window_65 = (st.buffer[0] * 3 + aux) & 63;
    if (window_65 > 39) {
        acc = (acc + window_65 * 2 + 5) & 127;
        aux ^= (window_65 & 15);
    } else {
        acc = (acc - window_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int delta_98 = local_arr[aux % 3];
    acc = (acc + delta_98 * 2) & 127;
    int index_reg_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_24(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_74 = (aux + st.buffer[1]) & 3;
    switch (quotient_74) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_88 = local_arr[aux % 3];
    acc = (acc + phase_88 * 2) & 127;
    int metric_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_61) & 63;
    acc ^= aux;
    int offset_24 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_24 > 42) {
        acc = (acc + offset_24 * 2 + 5) & 127;
        aux ^= (offset_24 & 15);
    } else {
        acc = (acc - offset_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_25(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_66) & 63;
    acc ^= aux;
    int bound_99 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_99 > 40) {
        acc = (acc + bound_99 * 2 + 5) & 127;
        aux ^= (bound_99 & 15);
    } else {
        acc = (acc - bound_99 + 11) & 127;
        aux += 3;
    }
    int segment_91 = 0;
    for (int k = 0; k < 2; k++) {
        segment_91 = (segment_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_91) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_76 = local_arr[aux % 3];
    acc = (acc + accumulator_76 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000535_0;
    int sec_r000535_1;
    int sec_r000535_2;
    int sec_r000535_3;
    int sec_r000535_4;
    int sec_r000535_5;
    int sec_r000535_6;
    int sec_r000535_7;
    int sec_r000535_8;
    int sec_r000535_9;
    int sec_r000535_10;
    int sec_r000535_11;
    int sec_r000535_12;
    int sec_r000535_13;
    int sec_r000535_14;
    int sec_r000535_15;
    int sec_r000535_16;
    int sec_r000535_17;
    int sec_r000535_18;
    int sec_r000535_19;
    int sec_r000535_20;
    int pub_r000535_0;
    int pub_r000535_1;
    int pub_r000535_2;
    int pub_r000535_3;
    int pub_r000535_4;
    int pub_r000535_5;
    int pub_r000535_6;
    int pub_r000535_7;
    int pub_r000535_8;
    int pub_r000535_9;
    int pub_r000535_10;
    int pub_r000535_11;
    int pub_r000535_12;
    int pub_r000535_13;
    int pub_r000535_14;
    int pub_r000535_15;
    int pub_r000535_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000535_0 >= -100 && pub_r000535_0 <= 100);
    __CPROVER_assume(pub_r000535_1 >= -100 && pub_r000535_1 <= 100);
    __CPROVER_assume(pub_r000535_2 >= -100 && pub_r000535_2 <= 100);
    __CPROVER_assume(pub_r000535_3 >= -100 && pub_r000535_3 <= 100);
    __CPROVER_assume(pub_r000535_4 >= -100 && pub_r000535_4 <= 100);
    __CPROVER_assume(pub_r000535_5 >= -100 && pub_r000535_5 <= 100);
    __CPROVER_assume(pub_r000535_6 >= -100 && pub_r000535_6 <= 100);
    __CPROVER_assume(pub_r000535_7 >= -100 && pub_r000535_7 <= 100);
    __CPROVER_assume(pub_r000535_8 >= -100 && pub_r000535_8 <= 100);
    __CPROVER_assume(pub_r000535_9 >= -100 && pub_r000535_9 <= 100);
    __CPROVER_assume(pub_r000535_10 >= -100 && pub_r000535_10 <= 100);
    __CPROVER_assume(pub_r000535_11 >= -100 && pub_r000535_11 <= 100);
    __CPROVER_assume(pub_r000535_12 >= -100 && pub_r000535_12 <= 100);
    __CPROVER_assume(pub_r000535_13 >= -100 && pub_r000535_13 <= 100);
    __CPROVER_assume(pub_r000535_14 >= -100 && pub_r000535_14 <= 100);
    __CPROVER_assume(pub_r000535_15 >= -100 && pub_r000535_15 <= 100);
    __CPROVER_assume(pub_r000535_16 >= -100 && pub_r000535_16 <= 100);
    __CPROVER_assume(sec_r000535_0 >= 0 && sec_r000535_0 <= 255);
    __CPROVER_assume(sec_r000535_1 >= 0 && sec_r000535_1 <= 255);
    __CPROVER_assume(sec_r000535_2 >= 0 && sec_r000535_2 <= 255);
    __CPROVER_assume(sec_r000535_3 >= 0 && sec_r000535_3 <= 255);
    __CPROVER_assume(sec_r000535_4 >= 0 && sec_r000535_4 <= 255);
    __CPROVER_assume(sec_r000535_5 >= 0 && sec_r000535_5 <= 255);
    __CPROVER_assume(sec_r000535_6 >= 0 && sec_r000535_6 <= 255);
    __CPROVER_assume(sec_r000535_7 >= 0 && sec_r000535_7 <= 255);
    __CPROVER_assume(sec_r000535_8 >= 0 && sec_r000535_8 <= 255);
    __CPROVER_assume(sec_r000535_9 >= 0 && sec_r000535_9 <= 255);
    __CPROVER_assume(sec_r000535_10 >= 0 && sec_r000535_10 <= 255);
    __CPROVER_assume(sec_r000535_11 >= 0 && sec_r000535_11 <= 255);
    __CPROVER_assume(sec_r000535_12 >= 0 && sec_r000535_12 <= 255);
    __CPROVER_assume(sec_r000535_13 >= 0 && sec_r000535_13 <= 255);
    __CPROVER_assume(sec_r000535_14 >= 0 && sec_r000535_14 <= 255);
    __CPROVER_assume(sec_r000535_15 >= 0 && sec_r000535_15 <= 255);
    __CPROVER_assume(sec_r000535_16 >= 0 && sec_r000535_16 <= 255);
    __CPROVER_assume(sec_r000535_17 >= 0 && sec_r000535_17 <= 255);
    __CPROVER_assume(sec_r000535_18 >= 0 && sec_r000535_18 <= 255);
    __CPROVER_assume(sec_r000535_19 >= 0 && sec_r000535_19 <= 255);
    __CPROVER_assume(sec_r000535_20 >= 0 && sec_r000535_20 <= 255);

    struct DeviceConfig_R000535_3513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000535_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000535_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000535_0 + 7) & 15;
    struct SensorNode_R000535_3513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000535_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000535_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000535_0 + 9) & 15;
    struct CipherContext_R000535_3513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000535_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000535_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000535_0 + 11) & 15;

    union RegisterBank_R000535_3513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 40) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 55) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 28) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 43) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 40) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 55) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 22) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 37) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

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
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 31) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 46) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 15) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 30) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 22) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 37) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 25) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 40) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 28) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 43) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 53) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 39) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_96 = (stage_v_96 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 18) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 33) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (out_sink > 100) ? (chk_sum & 31) : (109 & 31);
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= (stage_v_104 << 1) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 34) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 49) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_110 = (stage_v_110 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_2.buffer[2] * 2 + 355) & 63;
    if (stage_v_116 > 18) {
        out_sink = (out_sink + stage_v_116 - 5) & 255;
        if (stage_v_116 > 33) {
            chk_sum ^= (stage_v_116 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_116 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 16) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 31) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 16) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 31) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] * 2 + 385) & 63;
    if (stage_v_126 > 33) {
        out_sink = (out_sink + stage_v_126 - 5) & 255;
        if (stage_v_126 > 48) {
            chk_sum ^= (stage_v_126 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_126 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (out_sink > 100) ? (chk_sum & 31) : (133 & 31);
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= (stage_v_128 << 1) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 134) & 15;
    int stage_v_133 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= stage_v_133;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 31) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 46) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_141 = (stage_v_141 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 35) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 50) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Security Information Flow: Family = implicit_flow */
    if ((sec_r000535_1 & 63) > 32) {
        out_sink += 59;
    } else {
        out_sink -= 18;
    }
    if ((sec_r000535_8 & 63) > 20) {
        out_sink += 16;
    } else {
        out_sink -= 62;
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
