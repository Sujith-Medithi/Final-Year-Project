/*
 * Benchmark Program: R000477
 * Security Family: nested_implicit_flow
 * Generator Seed: 547713
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000477_7713_0 {
    short auth_code;
    int balance;
    short fee;
    int account_id;
    unsigned char status;
    int rate;
    int buffer[3];
};

struct FilterState_R000477_7713_1 {
    int mode;
    short prev_out;
    unsigned char prev_in;
    unsigned char damping;
    int cutoff;
    short gain_db;
    int buffer[3];
};

struct SensorNode_R000477_7713_2 {
    int offset;
    int calib;
    int reading;
    int gain;
    int status;
    int buffer[3];
};

struct EventLog_R000477_7713_3 {
    int seq;
    short timestamp;
    int code;
    short severity;
    short signature;
    int buffer[3];
};

union ColorPixel_R000477_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000477_7713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000477_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int mask_32 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_32 > 42) {
        acc = (acc + mask_32 * 2 + 5) & 127;
        aux ^= (mask_32 & 15);
    } else {
        acc = (acc - mask_32 + 11) & 127;
        aux += 3;
    }
    int offset_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_63) & 63;
    acc ^= aux;
    int delta_78 = (aux + st.buffer[1]) & 3;
    switch (delta_78) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_87 = local_arr[aux % 3];
    acc = (acc + tally_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_1(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000477_7713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_3(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000477_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_38) & 63;
    acc ^= aux;
    int quotient_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_94 > 31) {
        acc = (acc + quotient_94 * 2 + 5) & 127;
        aux ^= (quotient_94 & 15);
    } else {
        acc = (acc - quotient_94 + 11) & 127;
        aux += 3;
    }
    int threshold_87 = (aux + st.buffer[1]) & 3;
    switch (threshold_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_4(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000477_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_32 = (aux + st.buffer[1]) & 3;
    switch (pivot_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_5(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_31) & 63;
    acc ^= aux;
    int anchor_52 = (aux + st.buffer[1]) & 3;
    switch (anchor_52) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_6(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_82 > 31) {
        acc = (acc + checksum_82 * 2 + 5) & 127;
        aux ^= (checksum_82 & 15);
    } else {
        acc = (acc - checksum_82 + 11) & 127;
        aux += 3;
    }
    int bound_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_85) & 63;
    acc ^= aux;
    int phase_91 = (aux + st.buffer[1]) & 3;
    switch (phase_91) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000477_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_17 = local_arr[aux % 3];
    acc = (acc + offset_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_78 = (aux + st.buffer[1]) & 3;
    switch (window_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_91 = local_arr[aux % 3];
    acc = (acc + accumulator_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_83 = local_arr[aux % 3];
    acc = (acc + cursor_83 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_10(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int segment_60 = local_arr[aux % 3];
    acc = (acc + segment_60 * 2) & 127;
    int threshold_81 = (aux + st.buffer[1]) & 3;
    switch (threshold_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_49 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_49 > 46) {
        acc = (acc + coefficient_49 * 2 + 5) & 127;
        aux ^= (coefficient_49 & 15);
    } else {
        acc = (acc - coefficient_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_11(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000477_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int weight_17 = local_arr[aux % 3];
    acc = (acc + weight_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int delta_80 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_80 > 37) {
        acc = (acc + delta_80 * 2 + 5) & 127;
        aux ^= (delta_80 & 15);
    } else {
        acc = (acc - delta_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_59 = local_arr[aux % 3];
    acc = (acc + delta_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_34) & 63;
    acc ^= aux;
    int weight_80 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_80 > 13) {
        acc = (acc + weight_80 * 2 + 5) & 127;
        aux ^= (weight_80 & 15);
    } else {
        acc = (acc - weight_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_14(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_86 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_86 > 22) {
        acc = (acc + pivot_86 * 2 + 5) & 127;
        aux ^= (pivot_86 & 15);
    } else {
        acc = (acc - pivot_86 + 11) & 127;
        aux += 3;
    }
    int factor_31 = (aux + st.buffer[1]) & 3;
    switch (factor_31) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_39 = local_arr[aux % 3];
    acc = (acc + quotient_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000477_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_26 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_26 > 13) {
        acc = (acc + damping_26 * 2 + 5) & 127;
        aux ^= (damping_26 & 15);
    } else {
        acc = (acc - damping_26 + 11) & 127;
        aux += 3;
    }
    int cursor_36 = (aux + st.buffer[1]) & 3;
    switch (cursor_36) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000477_7713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_10) & 63;
    acc ^= aux;
    int anchor_96 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_96 > 11) {
        acc = (acc + anchor_96 * 2 + 5) & 127;
        aux ^= (anchor_96 & 15);
    } else {
        acc = (acc - anchor_96 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_78 = local_arr[aux % 3];
    acc = (acc + accumulator_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000477_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int index_reg_82 = (aux + st.buffer[1]) & 3;
    switch (index_reg_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_40 = local_arr[aux % 3];
    acc = (acc + cursor_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_18(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int vector_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_68) & 63;
    acc ^= aux;
    int bound_73 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_73 > 15) {
        acc = (acc + bound_73 * 2 + 5) & 127;
        aux ^= (bound_73 & 15);
    } else {
        acc = (acc - bound_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000477_7713_19(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_94 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_94 > 25) {
        acc = (acc + index_reg_94 * 2 + 5) & 127;
        aux ^= (index_reg_94 & 15);
    } else {
        acc = (acc - index_reg_94 + 11) & 127;
        aux += 3;
    }
    int quotient_86 = (aux + st.buffer[1]) & 3;
    switch (quotient_86) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_20(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000477_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_88) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_26 = local_arr[aux % 3];
    acc = (acc + checksum_26 * 2) & 127;
    int quantum_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_55 > 29) {
        acc = (acc + quantum_55 * 2 + 5) & 127;
        aux ^= (quantum_55 & 15);
    } else {
        acc = (acc - quantum_55 + 11) & 127;
        aux += 3;
    }
    int margin_48 = (aux + st.buffer[1]) & 3;
    switch (margin_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_21(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000477_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_71 = local_arr[aux % 3];
    acc = (acc + anchor_71 * 2) & 127;
    int window_44 = (st.buffer[0] * 3 + aux) & 63;
    if (window_44 > 32) {
        acc = (acc + window_44 * 2 + 5) & 127;
        aux ^= (window_44 & 15);
    } else {
        acc = (acc - window_44 + 11) & 127;
        aux += 3;
    }
    int stride_86 = (aux + st.buffer[1]) & 3;
    switch (stride_86) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000477_7713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000477_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int delta_36 = (aux + st.buffer[1]) & 3;
    switch (delta_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000477_0;
    int sec_r000477_1;
    int sec_r000477_2;
    int sec_r000477_3;
    int sec_r000477_4;
    int sec_r000477_5;
    int sec_r000477_6;
    int sec_r000477_7;
    int sec_r000477_8;
    int sec_r000477_9;
    int sec_r000477_10;
    int sec_r000477_11;
    int sec_r000477_12;
    int sec_r000477_13;
    int sec_r000477_14;
    int sec_r000477_15;
    int sec_r000477_16;
    int sec_r000477_17;
    int sec_r000477_18;
    int sec_r000477_19;
    int sec_r000477_20;
    int pub_r000477_0;
    int pub_r000477_1;
    int pub_r000477_2;
    int pub_r000477_3;
    int pub_r000477_4;
    int pub_r000477_5;
    int pub_r000477_6;
    int pub_r000477_7;
    int pub_r000477_8;
    int pub_r000477_9;
    int pub_r000477_10;
    int pub_r000477_11;
    int pub_r000477_12;
    int pub_r000477_13;
    int pub_r000477_14;
    int pub_r000477_15;
    int pub_r000477_16;
    int pub_r000477_17;
    int pub_r000477_18;
    int pub_r000477_19;
    int pub_r000477_20;
    int pub_r000477_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000477_0 >= -100 && pub_r000477_0 <= 100);
    __CPROVER_assume(pub_r000477_1 >= -100 && pub_r000477_1 <= 100);
    __CPROVER_assume(pub_r000477_2 >= -100 && pub_r000477_2 <= 100);
    __CPROVER_assume(pub_r000477_3 >= -100 && pub_r000477_3 <= 100);
    __CPROVER_assume(pub_r000477_4 >= -100 && pub_r000477_4 <= 100);
    __CPROVER_assume(pub_r000477_5 >= -100 && pub_r000477_5 <= 100);
    __CPROVER_assume(pub_r000477_6 >= -100 && pub_r000477_6 <= 100);
    __CPROVER_assume(pub_r000477_7 >= -100 && pub_r000477_7 <= 100);
    __CPROVER_assume(pub_r000477_8 >= -100 && pub_r000477_8 <= 100);
    __CPROVER_assume(pub_r000477_9 >= -100 && pub_r000477_9 <= 100);
    __CPROVER_assume(pub_r000477_10 >= -100 && pub_r000477_10 <= 100);
    __CPROVER_assume(pub_r000477_11 >= -100 && pub_r000477_11 <= 100);
    __CPROVER_assume(pub_r000477_12 >= -100 && pub_r000477_12 <= 100);
    __CPROVER_assume(pub_r000477_13 >= -100 && pub_r000477_13 <= 100);
    __CPROVER_assume(pub_r000477_14 >= -100 && pub_r000477_14 <= 100);
    __CPROVER_assume(pub_r000477_15 >= -100 && pub_r000477_15 <= 100);
    __CPROVER_assume(pub_r000477_16 >= -100 && pub_r000477_16 <= 100);
    __CPROVER_assume(pub_r000477_17 >= -100 && pub_r000477_17 <= 100);
    __CPROVER_assume(pub_r000477_18 >= -100 && pub_r000477_18 <= 100);
    __CPROVER_assume(pub_r000477_19 >= -100 && pub_r000477_19 <= 100);
    __CPROVER_assume(pub_r000477_20 >= -100 && pub_r000477_20 <= 100);
    __CPROVER_assume(pub_r000477_21 >= -100 && pub_r000477_21 <= 100);
    __CPROVER_assume(sec_r000477_0 >= 0 && sec_r000477_0 <= 255);
    __CPROVER_assume(sec_r000477_1 >= 0 && sec_r000477_1 <= 255);
    __CPROVER_assume(sec_r000477_2 >= 0 && sec_r000477_2 <= 255);
    __CPROVER_assume(sec_r000477_3 >= 0 && sec_r000477_3 <= 255);
    __CPROVER_assume(sec_r000477_4 >= 0 && sec_r000477_4 <= 255);
    __CPROVER_assume(sec_r000477_5 >= 0 && sec_r000477_5 <= 255);
    __CPROVER_assume(sec_r000477_6 >= 0 && sec_r000477_6 <= 255);
    __CPROVER_assume(sec_r000477_7 >= 0 && sec_r000477_7 <= 255);
    __CPROVER_assume(sec_r000477_8 >= 0 && sec_r000477_8 <= 255);
    __CPROVER_assume(sec_r000477_9 >= 0 && sec_r000477_9 <= 255);
    __CPROVER_assume(sec_r000477_10 >= 0 && sec_r000477_10 <= 255);
    __CPROVER_assume(sec_r000477_11 >= 0 && sec_r000477_11 <= 255);
    __CPROVER_assume(sec_r000477_12 >= 0 && sec_r000477_12 <= 255);
    __CPROVER_assume(sec_r000477_13 >= 0 && sec_r000477_13 <= 255);
    __CPROVER_assume(sec_r000477_14 >= 0 && sec_r000477_14 <= 255);
    __CPROVER_assume(sec_r000477_15 >= 0 && sec_r000477_15 <= 255);
    __CPROVER_assume(sec_r000477_16 >= 0 && sec_r000477_16 <= 255);
    __CPROVER_assume(sec_r000477_17 >= 0 && sec_r000477_17 <= 255);
    __CPROVER_assume(sec_r000477_18 >= 0 && sec_r000477_18 <= 255);
    __CPROVER_assume(sec_r000477_19 >= 0 && sec_r000477_19 <= 255);
    __CPROVER_assume(sec_r000477_20 >= 0 && sec_r000477_20 <= 255);

    struct Transaction_R000477_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000477_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000477_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000477_0 + 7) & 15;
    struct FilterState_R000477_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000477_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000477_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000477_0 + 9) & 15;
    struct SensorNode_R000477_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000477_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000477_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000477_0 + 11) & 15;
    struct EventLog_R000477_7713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000477_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000477_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000477_0 + 13) & 15;

    union ColorPixel_R000477_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 51) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 18) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 33) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 30) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 45) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 46) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 36) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 51) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 40) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 55) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 15) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 30) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 27) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 42) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 42) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 11) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 26) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 10) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 25) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 36) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 51) {
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
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 32) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 47) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 20) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 35) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
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
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 29) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 44) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 41) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 37) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 52) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 33) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 48) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_3.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 19) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 34) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 31) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 46) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000477_2 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_92 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000477_20 & 1) != 0) {
        if ((sec_r000477_20 & 2) != 0) {
            stage_v_93 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000477_11 & 1) != 0) {
        if ((sec_r000477_2 & 2) != 0) {
            stage_v_94 = (pub_r000477_7 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000477_7 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000477_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_95 = (pub_r000477_17 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000477_17 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000477_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000477_11 & 1) != 0) {
        if ((sec_r000477_5 & 2) != 0) {
            stage_v_96 = (pub_r000477_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000477_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000477_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000477_20 & 1) != 0) {
        if ((sec_r000477_19 & 2) != 0) {
            stage_v_97 = (pub_r000477_18 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000477_18 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000477_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000477_15 & 1) != 0) {
        if ((sec_r000477_12 & 2) != 0) {
            stage_v_98 = (pub_r000477_12 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000477_12 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000477_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000477_4 & 1) != 0) {
        if ((sec_r000477_14 & 2) != 0) {
            stage_v_99 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_100 = (pub_r000477_6 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000477_6 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000477_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_101 = (pub_r000477_18 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000477_18 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000477_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000477_5 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_102 = (pub_r000477_20 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000477_20 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000477_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000477_3 & 2) != 0) {
            stage_v_103 = (pub_r000477_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000477_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000477_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000477_20 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_104 = (pub_r000477_2 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000477_2 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000477_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000477_9 & 1) != 0) {
        if ((sec_r000477_3 & 2) != 0) {
            stage_v_105 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000477_2 & 2) != 0) {
            stage_v_106 = (pub_r000477_13 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000477_13 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000477_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_107 = (pub_r000477_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000477_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000477_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000477_18 & 2) != 0) {
            stage_v_108 = (pub_r000477_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000477_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000477_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000477_18 & 1) != 0) {
        if ((sec_r000477_11 & 2) != 0) {
            stage_v_109 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_110 = (pub_r000477_20 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000477_20 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000477_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000477_2 & 1) != 0) {
        if ((sec_r000477_10 & 2) != 0) {
            stage_v_111 = (pub_r000477_19 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000477_19 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000477_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_112 = (pub_r000477_0 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000477_0 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000477_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_113 = (pub_r000477_7 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000477_7 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000477_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000477_17 & 1) != 0) {
        if ((sec_r000477_6 & 2) != 0) {
            stage_v_114 = (pub_r000477_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000477_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000477_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_115 = (pub_r000477_2 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000477_2 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000477_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_116 = (pub_r000477_18 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000477_18 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000477_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000477_12 & 1) != 0) {
        if ((sec_r000477_5 & 2) != 0) {
            stage_v_117 = (pub_r000477_16 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000477_16 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000477_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000477_5 & 1) != 0) {
        if ((sec_r000477_11 & 2) != 0) {
            stage_v_118 = (pub_r000477_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000477_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000477_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000477_4 & 2) != 0) {
            stage_v_119 = (pub_r000477_19 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000477_19 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000477_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000477_8 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_120 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000477_7 & 2) != 0) {
            stage_v_121 = (pub_r000477_2 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000477_2 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000477_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_122 = (pub_r000477_16 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000477_16 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000477_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000477_14 & 1) != 0) {
        if ((sec_r000477_14 & 2) != 0) {
            stage_v_123 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000477_11 & 1) != 0) {
        if ((sec_r000477_19 & 2) != 0) {
            stage_v_124 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_125 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000477_5 & 1) != 0) {
        if ((sec_r000477_4 & 2) != 0) {
            stage_v_126 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_127 = (pub_r000477_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000477_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000477_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_128 = (pub_r000477_19 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000477_19 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000477_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000477_11 & 1) != 0) {
        if ((sec_r000477_14 & 2) != 0) {
            stage_v_129 = (pub_r000477_12 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000477_12 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000477_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_130 = (pub_r000477_0 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000477_0 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000477_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000477_3 & 1) != 0) {
        if ((sec_r000477_5 & 2) != 0) {
            stage_v_131 = (pub_r000477_16 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000477_16 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000477_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000477_7 & 1) != 0) {
        if ((sec_r000477_13 & 2) != 0) {
            stage_v_132 = (pub_r000477_19 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000477_19 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000477_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_133 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000477_10 & 2) != 0) {
            stage_v_134 = (pub_r000477_12 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000477_12 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000477_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000477_1 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_135 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_136 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000477_13 & 1) != 0) {
        if ((sec_r000477_2 & 2) != 0) {
            stage_v_137 = (pub_r000477_21 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000477_21 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000477_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000477_18 & 1) != 0) {
        if ((sec_r000477_5 & 2) != 0) {
            stage_v_138 = (pub_r000477_15 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000477_15 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000477_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000477_10 & 2) != 0) {
            stage_v_139 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_139 & 1) != 0) {
        if ((sec_r000477_15 & 2) != 0) {
            stage_v_140 = (pub_r000477_15 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000477_15 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000477_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_141 = (pub_r000477_20 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000477_20 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000477_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000477_2 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_142 = (pub_r000477_17 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000477_17 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000477_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000477_17 & 1) != 0) {
        if ((sec_r000477_16 & 2) != 0) {
            stage_v_143 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000477_6 & 2) != 0) {
            stage_v_144 = (pub_r000477_20 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000477_20 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000477_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_145 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000477_11 & 2) != 0) {
            stage_v_146 = (pub_r000477_6 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000477_6 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000477_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_147 = (pub_r000477_5 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000477_5 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000477_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000477_6 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_148 = (pub_r000477_18 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000477_18 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000477_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_149 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000477_1 & 2) != 0) {
            stage_v_150 = (pub_r000477_16 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000477_16 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000477_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000477_3 & 1) != 0) {
        if ((sec_r000477_7 & 2) != 0) {
            stage_v_151 = (pub_r000477_14 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000477_14 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000477_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000477_15 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_152 = (pub_r000477_3 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000477_3 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000477_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000477_16 & 1) != 0) {
        if ((sec_r000477_0 & 2) != 0) {
            stage_v_153 = (pub_r000477_12 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000477_12 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000477_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000477_3 & 2) != 0) {
            stage_v_154 = (pub_r000477_9 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000477_9 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000477_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000477_5 & 1) != 0) {
        if ((sec_r000477_12 & 2) != 0) {
            stage_v_155 = (pub_r000477_11 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000477_11 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000477_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000477_4 & 1) != 0) {
        if ((sec_r000477_10 & 2) != 0) {
            stage_v_156 = (pub_r000477_13 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000477_13 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000477_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_139 & 1) != 0) {
        if ((sec_r000477_6 & 2) != 0) {
            stage_v_157 = (pub_r000477_8 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000477_8 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000477_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000477_12 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_158 = (pub_r000477_12 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000477_12 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000477_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_159 = (pub_r000477_1 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000477_1 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000477_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000477_14 & 1) != 0) {
        if ((sec_r000477_9 & 2) != 0) {
            stage_v_160 = (pub_r000477_2 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000477_2 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000477_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000477_9 & 1) != 0) {
        if ((sec_r000477_8 & 2) != 0) {
            stage_v_161 = (pub_r000477_6 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000477_6 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000477_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r000477_12 & 2) != 0) {
            stage_v_162 = (pub_r000477_17 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000477_17 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000477_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000477_17 & 2) != 0) {
            stage_v_163 = (pub_r000477_8 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000477_8 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000477_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
