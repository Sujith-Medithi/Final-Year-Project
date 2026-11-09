/*
 * Benchmark Program: R001627
 * Security Family: nested_implicit_flow
 * Generator Seed: 662713
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001627_2713_0 {
    short threshold;
    unsigned char offset;
    int status;
    short gain;
    unsigned char reading;
    short calib;
    int buffer[3];
};

struct CipherContext_R001627_2713_1 {
    int counter;
    int tag;
    short flags;
    int round_key;
    int buffer[3];
};

struct DeviceConfig_R001627_2713_2 {
    short port;
    int baud_rate;
    short id;
    int buffer[3];
};

union PacketPayload_R001627_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001627_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001627_2713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_77 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_77 > 22) {
        acc = (acc + margin_77 * 2 + 5) & 127;
        aux ^= (margin_77 & 15);
    } else {
        acc = (acc - margin_77 + 11) & 127;
        aux += 3;
    }
    int quantum_53 = (aux + st.buffer[1]) & 3;
    switch (quantum_53) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_1(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_43 = local_arr[aux % 3];
    acc = (acc + cursor_43 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_45 = (aux + st.buffer[1]) & 3;
    switch (phase_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_3(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_97) & 63;
    acc ^= aux;
    int anchor_17 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_17 > 13) {
        acc = (acc + anchor_17 * 2 + 5) & 127;
        aux ^= (anchor_17 & 15);
    } else {
        acc = (acc - anchor_17 + 11) & 127;
        aux += 3;
    }
    int index_reg_69 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_69 = (index_reg_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_69) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_15 = local_arr[aux % 3];
    acc = (acc + quantum_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_27 = 0;
    for (int k = 0; k < 3; k++) {
        mask_27 = (mask_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_27) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001627_2713_5(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001627_2713_6(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_87 = 0;
    for (int k = 0; k < 2; k++) {
        mask_87 = (mask_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_87) & 127;
    }
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 45) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    int parity_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001627_2713_7(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_91 = (aux + st.buffer[1]) & 3;
    switch (mask_91) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_43 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_43 = (cursor_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_43) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001627_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_25 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_25 = (index_reg_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_42 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_42 > 34) {
        acc = (acc + segment_42 * 2 + 5) & 127;
        aux ^= (segment_42 & 15);
    } else {
        acc = (acc - segment_42 + 11) & 127;
        aux += 3;
    }
    int phase_57 = (aux + st.buffer[1]) & 3;
    switch (phase_57) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int tracker_95 = local_arr[aux % 3];
    acc = (acc + tracker_95 * 2) & 127;
    int margin_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_21) & 63;
    acc ^= aux;
    int sample_40 = (aux + st.buffer[1]) & 3;
    switch (sample_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_67 = 0;
    for (int k = 0; k < 2; k++) {
        offset_67 = (offset_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_61) & 63;
    acc ^= aux;
    int factor_95 = (aux + st.buffer[1]) & 3;
    switch (factor_95) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_11(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_22) & 63;
    acc ^= aux;
    int cursor_76 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_76 = (cursor_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_76) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_14 = local_arr[aux % 3];
    acc = (acc + weight_14 * 2) & 127;
    int offset_73 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_73 > 15) {
        acc = (acc + offset_73 * 2 + 5) & 127;
        aux ^= (offset_73 & 15);
    } else {
        acc = (acc - offset_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_12(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_44 = (aux + st.buffer[1]) & 3;
    switch (damping_44) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_94 = (st.buffer[0] * 3 + aux) & 63;
    if (window_94 > 22) {
        acc = (acc + window_94 * 2 + 5) & 127;
        aux ^= (window_94 & 15);
    } else {
        acc = (acc - window_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int mask_65 = (aux + st.buffer[1]) & 3;
    switch (mask_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_33 = local_arr[aux % 3];
    acc = (acc + residue_33 * 2) & 127;
    int factor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_56 > 49) {
        acc = (acc + factor_56 * 2 + 5) & 127;
        aux ^= (factor_56 & 15);
    } else {
        acc = (acc - factor_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_14(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int factor_21 = local_arr[aux % 3];
    acc = (acc + factor_21 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001627_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int bound_58 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_58 > 32) {
        acc = (acc + bound_58 * 2 + 5) & 127;
        aux ^= (bound_58 & 15);
    } else {
        acc = (acc - bound_58 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_88 = local_arr[aux % 3];
    acc = (acc + margin_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_16(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int coefficient_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_17) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_99 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_99 = (threshold_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_99) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_95 = local_arr[aux % 3];
    acc = (acc + weight_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_17(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor_79 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_79 = (cursor_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_79) & 127;
    }
    int weight_88 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_88 > 13) {
        acc = (acc + weight_88 * 2 + 5) & 127;
        aux ^= (weight_88 & 15);
    } else {
        acc = (acc - weight_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_18 = local_arr[aux % 3];
    acc = (acc + vector_18 * 2) & 127;
    int quantum_10 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_10 = (quantum_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_19(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tally_10 = (aux + st.buffer[1]) & 3;
    switch (tally_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_57 = local_arr[aux % 3];
    acc = (acc + scale_57 * 2) & 127;
    int cursor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_35 > 37) {
        acc = (acc + cursor_35 * 2 + 5) & 127;
        aux ^= (cursor_35 & 15);
    } else {
        acc = (acc - cursor_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_27 = local_arr[aux % 3];
    acc = (acc + cursor_27 * 2) & 127;
    int parity_91 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_91 > 41) {
        acc = (acc + parity_91 * 2 + 5) & 127;
        aux ^= (parity_91 & 15);
    } else {
        acc = (acc - parity_91 + 11) & 127;
        aux += 3;
    }
    int metric_13 = 0;
    for (int k = 0; k < 2; k++) {
        metric_13 = (metric_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001627_2713_21(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_96 = 0;
    for (int k = 0; k < 3; k++) {
        parity_96 = (parity_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_96) & 127;
    }
    int metric_78 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_78 > 49) {
        acc = (acc + metric_78 * 2 + 5) & 127;
        aux ^= (metric_78 & 15);
    } else {
        acc = (acc - metric_78 + 11) & 127;
        aux += 3;
    }
    int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_13) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001627_2713_22(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_70 = 0;
    for (int k = 0; k < 3; k++) {
        mask_70 = (mask_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_70) & 127;
    }
    int delta_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_73) & 63;
    acc ^= aux;
    int factor_99 = (aux + st.buffer[1]) & 3;
    switch (factor_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001627_0;
    int sec_r001627_1;
    int sec_r001627_2;
    int sec_r001627_3;
    int sec_r001627_4;
    int sec_r001627_5;
    int sec_r001627_6;
    int sec_r001627_7;
    int sec_r001627_8;
    int sec_r001627_9;
    int sec_r001627_10;
    int sec_r001627_11;
    int sec_r001627_12;
    int sec_r001627_13;
    int sec_r001627_14;
    int sec_r001627_15;
    int sec_r001627_16;
    int sec_r001627_17;
    int sec_r001627_18;
    int sec_r001627_19;
    int sec_r001627_20;
    int sec_r001627_21;
    int sec_r001627_22;
    int pub_r001627_0;
    int pub_r001627_1;
    int pub_r001627_2;
    int pub_r001627_3;
    int pub_r001627_4;
    int pub_r001627_5;
    int pub_r001627_6;
    int pub_r001627_7;
    int pub_r001627_8;
    int pub_r001627_9;
    int pub_r001627_10;
    int pub_r001627_11;
    int pub_r001627_12;
    int pub_r001627_13;
    int pub_r001627_14;
    int pub_r001627_15;
    int pub_r001627_16;
    int pub_r001627_17;
    int pub_r001627_18;
    int pub_r001627_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001627_0 >= -100 && pub_r001627_0 <= 100);
    __CPROVER_assume(pub_r001627_1 >= -100 && pub_r001627_1 <= 100);
    __CPROVER_assume(pub_r001627_2 >= -100 && pub_r001627_2 <= 100);
    __CPROVER_assume(pub_r001627_3 >= -100 && pub_r001627_3 <= 100);
    __CPROVER_assume(pub_r001627_4 >= -100 && pub_r001627_4 <= 100);
    __CPROVER_assume(pub_r001627_5 >= -100 && pub_r001627_5 <= 100);
    __CPROVER_assume(pub_r001627_6 >= -100 && pub_r001627_6 <= 100);
    __CPROVER_assume(pub_r001627_7 >= -100 && pub_r001627_7 <= 100);
    __CPROVER_assume(pub_r001627_8 >= -100 && pub_r001627_8 <= 100);
    __CPROVER_assume(pub_r001627_9 >= -100 && pub_r001627_9 <= 100);
    __CPROVER_assume(pub_r001627_10 >= -100 && pub_r001627_10 <= 100);
    __CPROVER_assume(pub_r001627_11 >= -100 && pub_r001627_11 <= 100);
    __CPROVER_assume(pub_r001627_12 >= -100 && pub_r001627_12 <= 100);
    __CPROVER_assume(pub_r001627_13 >= -100 && pub_r001627_13 <= 100);
    __CPROVER_assume(pub_r001627_14 >= -100 && pub_r001627_14 <= 100);
    __CPROVER_assume(pub_r001627_15 >= -100 && pub_r001627_15 <= 100);
    __CPROVER_assume(pub_r001627_16 >= -100 && pub_r001627_16 <= 100);
    __CPROVER_assume(pub_r001627_17 >= -100 && pub_r001627_17 <= 100);
    __CPROVER_assume(pub_r001627_18 >= -100 && pub_r001627_18 <= 100);
    __CPROVER_assume(pub_r001627_19 >= -100 && pub_r001627_19 <= 100);
    __CPROVER_assume(sec_r001627_0 >= 0 && sec_r001627_0 <= 255);
    __CPROVER_assume(sec_r001627_1 >= 0 && sec_r001627_1 <= 255);
    __CPROVER_assume(sec_r001627_2 >= 0 && sec_r001627_2 <= 255);
    __CPROVER_assume(sec_r001627_3 >= 0 && sec_r001627_3 <= 255);
    __CPROVER_assume(sec_r001627_4 >= 0 && sec_r001627_4 <= 255);
    __CPROVER_assume(sec_r001627_5 >= 0 && sec_r001627_5 <= 255);
    __CPROVER_assume(sec_r001627_6 >= 0 && sec_r001627_6 <= 255);
    __CPROVER_assume(sec_r001627_7 >= 0 && sec_r001627_7 <= 255);
    __CPROVER_assume(sec_r001627_8 >= 0 && sec_r001627_8 <= 255);
    __CPROVER_assume(sec_r001627_9 >= 0 && sec_r001627_9 <= 255);
    __CPROVER_assume(sec_r001627_10 >= 0 && sec_r001627_10 <= 255);
    __CPROVER_assume(sec_r001627_11 >= 0 && sec_r001627_11 <= 255);
    __CPROVER_assume(sec_r001627_12 >= 0 && sec_r001627_12 <= 255);
    __CPROVER_assume(sec_r001627_13 >= 0 && sec_r001627_13 <= 255);
    __CPROVER_assume(sec_r001627_14 >= 0 && sec_r001627_14 <= 255);
    __CPROVER_assume(sec_r001627_15 >= 0 && sec_r001627_15 <= 255);
    __CPROVER_assume(sec_r001627_16 >= 0 && sec_r001627_16 <= 255);
    __CPROVER_assume(sec_r001627_17 >= 0 && sec_r001627_17 <= 255);
    __CPROVER_assume(sec_r001627_18 >= 0 && sec_r001627_18 <= 255);
    __CPROVER_assume(sec_r001627_19 >= 0 && sec_r001627_19 <= 255);
    __CPROVER_assume(sec_r001627_20 >= 0 && sec_r001627_20 <= 255);
    __CPROVER_assume(sec_r001627_21 >= 0 && sec_r001627_21 <= 255);
    __CPROVER_assume(sec_r001627_22 >= 0 && sec_r001627_22 <= 255);

    struct SensorNode_R001627_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001627_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001627_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001627_0 + 7) & 15;
    struct CipherContext_R001627_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001627_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001627_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001627_0 + 9) & 15;
    struct DeviceConfig_R001627_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001627_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001627_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001627_0 + 11) & 15;

    union PacketPayload_R001627_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001627_2713_0(sec_r001627_0, sec_r001627_1, pub_r001627_2, pub_r001627_3, pub_r001627_4);
    int helper_flow_1 = fn_R001627_2713_1(sec_r001627_1, pub_r001627_2, pub_r001627_3);
    int helper_flow_2 = fn_R001627_2713_2(sec_r001627_2, pub_r001627_3, pub_r001627_4, pub_r001627_5, pub_r001627_6);
    int helper_flow_3 = fn_R001627_2713_3(sec_r001627_3, pub_r001627_4);
    int helper_flow_4 = fn_R001627_2713_4(sec_r001627_4, pub_r001627_5, pub_r001627_6, pub_r001627_7);
    int helper_flow_5 = fn_R001627_2713_5(sec_r001627_5, pub_r001627_6, pub_r001627_7);
    int helper_flow_6 = fn_R001627_2713_6(sec_r001627_6, pub_r001627_7, pub_r001627_8);
    int helper_flow_7 = fn_R001627_2713_7(sec_r001627_7, pub_r001627_8, pub_r001627_9);
    int helper_flow_8 = fn_R001627_2713_8(sec_r001627_8, sec_r001627_9, pub_r001627_10, pub_r001627_11, pub_r001627_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001627_12 ^ pub_r001627_18) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001627_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001627_14 ^ pub_r001627_2) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001627_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001627_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001627_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_5 ^ pub_r001627_14) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001627_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001627_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_5 ^ pub_r001627_18) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001627_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001627_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001627_19 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001627_2 ^ pub_r001627_1) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001627_15 ^ pub_r001627_11) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_1 ^ pub_r001627_10) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001627_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001627_9 ^ pub_r001627_15) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001627_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001627_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001627_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_12 ^ pub_r001627_0) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_1 ^ pub_r001627_10) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001627_11 ^ pub_r001627_0) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001627_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_6 ^ pub_r001627_16) & 63;
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
    int stage_v_21 = (stage_v_7 ^ pub_r001627_4) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001627_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001627_10 ^ pub_r001627_15) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_14 ^ pub_r001627_2) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001627_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_22 ^ pub_r001627_7) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001627_19 ^ pub_r001627_7) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001627_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001627_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_1 ^ pub_r001627_4) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001627_3 ^ pub_r001627_7) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001627_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001627_22 ^ pub_r001627_3) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001627_21 ^ pub_r001627_0) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_3 ^ pub_r001627_0) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001627_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001627_14 ^ pub_r001627_8) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_30 ^ pub_r001627_10) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001627_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_30 ^ pub_r001627_19) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001627_2 ^ pub_r001627_10) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001627_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001627_13 ^ pub_r001627_3) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_7 ^ pub_r001627_1) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r001627_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (helper_flow_7 ^ pub_r001627_8) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_35 ^ pub_r001627_15) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001627_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_21 ^ pub_r001627_6) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001627_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_8 ^ pub_r001627_2) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001627_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001627_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001627_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_29 ^ pub_r001627_1) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_25 ^ pub_r001627_1) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_12 ^ pub_r001627_18) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001627_9 ^ pub_r001627_8) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001627_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001627_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001627_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001627_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_6 ^ pub_r001627_6) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001627_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001627_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001627_10 ^ pub_r001627_9) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001627_4 ^ pub_r001627_12) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001627_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001627_1 ^ pub_r001627_19) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001627_3 ^ pub_r001627_9) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_32 ^ pub_r001627_9) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_35 ^ pub_r001627_16) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001627_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001627_5 ^ pub_r001627_9) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001627_14 ^ pub_r001627_11) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_3 ^ pub_r001627_19) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_14 ^ pub_r001627_13) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001627_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001627_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001627_5 ^ pub_r001627_10) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_26 ^ pub_r001627_11) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_71 ^ pub_r001627_4) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_31 ^ pub_r001627_16) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_66 ^ pub_r001627_19) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_74 ^ pub_r001627_11) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001627_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001627_0 ^ pub_r001627_9) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_37 ^ pub_r001627_6) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001627_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001627_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001627_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_73 ^ pub_r001627_3) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001627_18 ^ pub_r001627_4) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r001627_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_2 ^ pub_r001627_18) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_20 ^ pub_r001627_2) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001627_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001627_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001627_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_18 ^ pub_r001627_11) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_5 ^ pub_r001627_4) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r001627_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_41 ^ pub_r001627_0) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_19 ^ pub_r001627_15) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001627_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_71 ^ pub_r001627_5) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_35 ^ pub_r001627_8) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_1 ^ pub_r001627_4) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r001627_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_62 ^ pub_r001627_4) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_60 ^ pub_r001627_14) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_37 ^ pub_r001627_8) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r001627_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_64 ^ pub_r001627_7) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001627_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_72 ^ pub_r001627_13) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001627_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_13 ^ pub_r001627_9) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001627_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_65 ^ pub_r001627_6) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_97 ^ pub_r001627_7) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_72 ^ pub_r001627_14) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_92 ^ pub_r001627_17) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001627_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_58 ^ pub_r001627_10) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001627_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_40 ^ pub_r001627_1) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_74 ^ pub_r001627_9) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_66 ^ pub_r001627_10) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_17 ^ pub_r001627_15) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001627_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_74 ^ pub_r001627_12) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_93 ^ pub_r001627_11) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001627_10 ^ pub_r001627_7) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_60 ^ pub_r001627_14) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_32 ^ pub_r001627_8) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001627_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_17 ^ pub_r001627_0) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001627_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001627_12 ^ pub_r001627_12) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_120 ^ pub_r001627_12) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r001627_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_95 ^ pub_r001627_6) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_22 ^ pub_r001627_13) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r001627_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_125 ^ pub_r001627_2) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001627_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (helper_flow_3 ^ pub_r001627_15) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_26 ^ pub_r001627_1) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_118 ^ pub_r001627_18) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_66 ^ pub_r001627_4) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001627_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001627_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_108 ^ pub_r001627_19) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001627_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_66 ^ pub_r001627_1) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001627_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_138 ^ pub_r001627_7) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_70 ^ pub_r001627_11) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_78 ^ pub_r001627_19) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r001627_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001627_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001627_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_1 ^ pub_r001627_9) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001627_0 ^ pub_r001627_0) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_20 ^ pub_r001627_19) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001627_18 ^ pub_r001627_11) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r001627_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_12 ^ pub_r001627_1) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001627_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001627_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_5 ^ pub_r001627_10) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001627_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_90 ^ pub_r001627_14) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001627_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001627_8 ^ pub_r001627_6) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r001627_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001627_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001627_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_21 ^ pub_r001627_7) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001627_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001627_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_73 ^ pub_r001627_16) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_1 ^ pub_r001627_13) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_90 ^ pub_r001627_8) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001627_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001627_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_110 ^ pub_r001627_0) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001627_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001627_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_37 ^ pub_r001627_4) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001627_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001627_0 ^ pub_r001627_19) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((sec_r001627_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001627_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_65 ^ pub_r001627_16) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001627_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_30 ^ pub_r001627_16) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_155 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001627_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001627_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001627_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_36 ^ pub_r001627_4) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_137 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_83 ^ pub_r001627_10) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_132 ^ pub_r001627_13) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001627_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_19 ^ pub_r001627_2) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001627_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_112 ^ pub_r001627_0) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_175 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_77 ^ pub_r001627_0) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_17 ^ pub_r001627_14) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001627_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_173 ^ pub_r001627_6) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_189 ^ pub_r001627_17) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_62 ^ pub_r001627_12) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_189 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_117 ^ pub_r001627_5) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_140 ^ pub_r001627_11) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001627_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_92 ^ pub_r001627_14) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001627_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_190 ^ pub_r001627_14) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
