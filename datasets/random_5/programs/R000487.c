/*
 * Benchmark Program: R000487
 * Security Family: nested_implicit_flow
 * Generator Seed: 548713
 * High Inputs: 16 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000487_8713_0 {
    unsigned char stop_bits;
    short baud_rate;
    unsigned char port;
    unsigned char id;
    int parity;
    int buffer[3];
};

struct EventLog_R000487_8713_1 {
    int severity;
    int seq;
    short code;
    unsigned char signature;
    int buffer[3];
};

struct SensorNode_R000487_8713_2 {
    unsigned char status;
    unsigned char offset;
    short gain;
    unsigned char reading;
    unsigned char threshold;
    unsigned char calib;
    int buffer[3];
};

union PacketPayload_R000487_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000487_8713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000487_8713_0(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_37 > 14) {
        acc = (acc + anchor_37 * 2 + 5) & 127;
        aux ^= (anchor_37 & 15);
    } else {
        acc = (acc - anchor_37 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_10 = (aux + st.buffer[1]) & 3;
    switch (anchor_10) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_57) & 63;
    acc ^= aux;
    int anchor_67 = (aux + st.buffer[1]) & 3;
    switch (anchor_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int accumulator_21 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_21 > 25) {
        acc = (acc + accumulator_21 * 2 + 5) & 127;
        aux ^= (accumulator_21 & 15);
    } else {
        acc = (acc - accumulator_21 + 11) & 127;
        aux += 3;
    }
    int quantum_30 = (aux + st.buffer[1]) & 3;
    switch (quantum_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000487_8713_3(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000487_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_39 = (aux + st.buffer[1]) & 3;
    switch (coefficient_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_15 = local_arr[aux % 3];
    acc = (acc + tally_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_25 = local_arr[aux % 3];
    acc = (acc + weight_25 * 2) & 127;
    int index_reg_68 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_68 > 27) {
        acc = (acc + index_reg_68 * 2 + 5) & 127;
        aux ^= (index_reg_68 & 15);
    } else {
        acc = (acc - index_reg_68 + 11) & 127;
        aux += 3;
    }
    int coefficient_29 = (aux + st.buffer[1]) & 3;
    switch (coefficient_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int residue_87 = local_arr[aux % 3];
    acc = (acc + residue_87 * 2) & 127;
    int sample_41 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_41 > 18) {
        acc = (acc + sample_41 * 2 + 5) & 127;
        aux ^= (sample_41 & 15);
    } else {
        acc = (acc - sample_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_6(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int factor_14 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_14 > 13) {
        acc = (acc + factor_14 * 2 + 5) & 127;
        aux ^= (factor_14 & 15);
    } else {
        acc = (acc - factor_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_54 = local_arr[aux % 3];
    acc = (acc + anchor_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_7(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000487_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_22) & 63;
    acc ^= aux;
    int accumulator_29 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_29 > 32) {
        acc = (acc + accumulator_29 * 2 + 5) & 127;
        aux ^= (accumulator_29 & 15);
    } else {
        acc = (acc - accumulator_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_41 = local_arr[aux % 3];
    acc = (acc + anchor_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000487_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_58 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_58 > 28) {
        acc = (acc + sample_58 * 2 + 5) & 127;
        aux ^= (sample_58 & 15);
    } else {
        acc = (acc - sample_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_62 = local_arr[aux % 3];
    acc = (acc + quotient_62 * 2) & 127;
    int stride_71 = (aux + st.buffer[1]) & 3;
    switch (stride_71) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000487_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_13 = (st.buffer[0] * 3 + aux) & 63;
    if (window_13 > 34) {
        acc = (acc + window_13 * 2 + 5) & 127;
        aux ^= (window_13 & 15);
    } else {
        acc = (acc - window_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_22 = local_arr[aux % 3];
    acc = (acc + metric_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_29 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_29 > 37) {
        acc = (acc + scale_29 * 2 + 5) & 127;
        aux ^= (scale_29 & 15);
    } else {
        acc = (acc - scale_29 + 11) & 127;
        aux += 3;
    }
    int anchor_12 = (aux + st.buffer[1]) & 3;
    switch (anchor_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_11(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000487_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int threshold_89 = (aux + st.buffer[1]) & 3;
    switch (threshold_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_76 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_76 > 14) {
        acc = (acc + quantum_76 * 2 + 5) & 127;
        aux ^= (quantum_76 & 15);
    } else {
        acc = (acc - quantum_76 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_12(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int parity_90 = (aux + st.buffer[1]) & 3;
    switch (parity_90) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_33) & 63;
    acc ^= aux;
    int metric_34 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_34 > 50) {
        acc = (acc + metric_34 * 2 + 5) & 127;
        aux ^= (metric_34 & 15);
    } else {
        acc = (acc - metric_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_76) & 63;
    acc ^= aux;
    int scale_35 = (aux + st.buffer[1]) & 3;
    switch (scale_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_22 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_22 > 25) {
        acc = (acc + parity_22 * 2 + 5) & 127;
        aux ^= (parity_22 & 15);
    } else {
        acc = (acc - parity_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int vector_87 = local_arr[aux % 3];
    acc = (acc + vector_87 * 2) & 127;
    int phase_82 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_82 > 36) {
        acc = (acc + phase_82 * 2 + 5) & 127;
        aux ^= (phase_82 & 15);
    } else {
        acc = (acc - phase_82 + 11) & 127;
        aux += 3;
    }
    int margin_57 = (aux + st.buffer[1]) & 3;
    switch (margin_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_15(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int index_reg_11 = local_arr[aux % 3];
    acc = (acc + index_reg_11 * 2) & 127;
    int stride_73 = (aux + st.buffer[1]) & 3;
    switch (stride_73) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000487_8713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int vector_78 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_78 > 48) {
        acc = (acc + vector_78 * 2 + 5) & 127;
        aux ^= (vector_78 & 15);
    } else {
        acc = (acc - vector_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_73 = local_arr[aux % 3];
    acc = (acc + offset_73 * 2) & 127;
    int quotient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_81) & 63;
    acc ^= aux;
    int mask_96 = (aux + st.buffer[1]) & 3;
    switch (mask_96) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000487_8713_17(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000487_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int damping_17 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_17 > 35) {
        acc = (acc + damping_17 * 2 + 5) & 127;
        aux ^= (damping_17 & 15);
    } else {
        acc = (acc - damping_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_92 = local_arr[aux % 3];
    acc = (acc + metric_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_18(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_78 = (aux + st.buffer[1]) & 3;
    switch (coefficient_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_51 = local_arr[aux % 3];
    acc = (acc + scale_51 * 2) & 127;
    int quantum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000487_8713_19(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000487_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_35) & 63;
    acc ^= aux;
    int stride_63 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_63 > 13) {
        acc = (acc + stride_63 * 2 + 5) & 127;
        aux ^= (stride_63 & 15);
    } else {
        acc = (acc - stride_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000487_0;
    int sec_r000487_1;
    int sec_r000487_2;
    int sec_r000487_3;
    int sec_r000487_4;
    int sec_r000487_5;
    int sec_r000487_6;
    int sec_r000487_7;
    int sec_r000487_8;
    int sec_r000487_9;
    int sec_r000487_10;
    int sec_r000487_11;
    int sec_r000487_12;
    int sec_r000487_13;
    int sec_r000487_14;
    int sec_r000487_15;
    int pub_r000487_0;
    int pub_r000487_1;
    int pub_r000487_2;
    int pub_r000487_3;
    int pub_r000487_4;
    int pub_r000487_5;
    int pub_r000487_6;
    int pub_r000487_7;
    int pub_r000487_8;
    int pub_r000487_9;
    int pub_r000487_10;
    int pub_r000487_11;
    int pub_r000487_12;
    int pub_r000487_13;
    int pub_r000487_14;
    int pub_r000487_15;
    int pub_r000487_16;
    int pub_r000487_17;
    int pub_r000487_18;
    int pub_r000487_19;
    int pub_r000487_20;
    int pub_r000487_21;
    int pub_r000487_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000487_0 >= -100 && pub_r000487_0 <= 100);
    __CPROVER_assume(pub_r000487_1 >= -100 && pub_r000487_1 <= 100);
    __CPROVER_assume(pub_r000487_2 >= -100 && pub_r000487_2 <= 100);
    __CPROVER_assume(pub_r000487_3 >= -100 && pub_r000487_3 <= 100);
    __CPROVER_assume(pub_r000487_4 >= -100 && pub_r000487_4 <= 100);
    __CPROVER_assume(pub_r000487_5 >= -100 && pub_r000487_5 <= 100);
    __CPROVER_assume(pub_r000487_6 >= -100 && pub_r000487_6 <= 100);
    __CPROVER_assume(pub_r000487_7 >= -100 && pub_r000487_7 <= 100);
    __CPROVER_assume(pub_r000487_8 >= -100 && pub_r000487_8 <= 100);
    __CPROVER_assume(pub_r000487_9 >= -100 && pub_r000487_9 <= 100);
    __CPROVER_assume(pub_r000487_10 >= -100 && pub_r000487_10 <= 100);
    __CPROVER_assume(pub_r000487_11 >= -100 && pub_r000487_11 <= 100);
    __CPROVER_assume(pub_r000487_12 >= -100 && pub_r000487_12 <= 100);
    __CPROVER_assume(pub_r000487_13 >= -100 && pub_r000487_13 <= 100);
    __CPROVER_assume(pub_r000487_14 >= -100 && pub_r000487_14 <= 100);
    __CPROVER_assume(pub_r000487_15 >= -100 && pub_r000487_15 <= 100);
    __CPROVER_assume(pub_r000487_16 >= -100 && pub_r000487_16 <= 100);
    __CPROVER_assume(pub_r000487_17 >= -100 && pub_r000487_17 <= 100);
    __CPROVER_assume(pub_r000487_18 >= -100 && pub_r000487_18 <= 100);
    __CPROVER_assume(pub_r000487_19 >= -100 && pub_r000487_19 <= 100);
    __CPROVER_assume(pub_r000487_20 >= -100 && pub_r000487_20 <= 100);
    __CPROVER_assume(pub_r000487_21 >= -100 && pub_r000487_21 <= 100);
    __CPROVER_assume(pub_r000487_22 >= -100 && pub_r000487_22 <= 100);
    __CPROVER_assume(sec_r000487_0 >= 0 && sec_r000487_0 <= 255);
    __CPROVER_assume(sec_r000487_1 >= 0 && sec_r000487_1 <= 255);
    __CPROVER_assume(sec_r000487_2 >= 0 && sec_r000487_2 <= 255);
    __CPROVER_assume(sec_r000487_3 >= 0 && sec_r000487_3 <= 255);
    __CPROVER_assume(sec_r000487_4 >= 0 && sec_r000487_4 <= 255);
    __CPROVER_assume(sec_r000487_5 >= 0 && sec_r000487_5 <= 255);
    __CPROVER_assume(sec_r000487_6 >= 0 && sec_r000487_6 <= 255);
    __CPROVER_assume(sec_r000487_7 >= 0 && sec_r000487_7 <= 255);
    __CPROVER_assume(sec_r000487_8 >= 0 && sec_r000487_8 <= 255);
    __CPROVER_assume(sec_r000487_9 >= 0 && sec_r000487_9 <= 255);
    __CPROVER_assume(sec_r000487_10 >= 0 && sec_r000487_10 <= 255);
    __CPROVER_assume(sec_r000487_11 >= 0 && sec_r000487_11 <= 255);
    __CPROVER_assume(sec_r000487_12 >= 0 && sec_r000487_12 <= 255);
    __CPROVER_assume(sec_r000487_13 >= 0 && sec_r000487_13 <= 255);
    __CPROVER_assume(sec_r000487_14 >= 0 && sec_r000487_14 <= 255);
    __CPROVER_assume(sec_r000487_15 >= 0 && sec_r000487_15 <= 255);

    struct DeviceConfig_R000487_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000487_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000487_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000487_0 + 7) & 15;
    struct EventLog_R000487_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000487_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000487_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000487_0 + 9) & 15;
    struct SensorNode_R000487_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000487_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000487_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000487_0 + 11) & 15;

    union PacketPayload_R000487_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 12) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 27) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 13) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 28) {
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
    if (stage_v_6 > 32) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 47) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 32) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 47) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 15) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 30) {
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
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 24) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 39) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 40) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 55) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 30) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 45) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 38) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 53) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 11) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 26) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 36) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 51) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 37) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 52) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 25) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 40) {
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
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

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
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000487_11 & 1) != 0) {
        if ((sec_r000487_8 & 2) != 0) {
            stage_v_62 = (pub_r000487_4 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000487_4 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000487_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_2 & 2) != 0) {
            stage_v_63 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_12 & 2) != 0) {
            stage_v_64 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_6 & 2) != 0) {
            stage_v_65 = (pub_r000487_0 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000487_0 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000487_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_66 = (pub_r000487_11 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000487_11 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000487_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_11 & 2) != 0) {
            stage_v_67 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_68 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_69 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_70 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_71 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000487_15 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_72 = (pub_r000487_1 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000487_1 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000487_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_73 = (pub_r000487_17 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000487_17 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000487_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_74 = (pub_r000487_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000487_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000487_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000487_8 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_75 = (pub_r000487_16 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000487_16 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000487_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_76 = (pub_r000487_3 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000487_3 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000487_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_77 = (pub_r000487_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000487_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000487_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000487_13 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_78 = (pub_r000487_1 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000487_1 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000487_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_79 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000487_12 & 1) != 0) {
        if ((sec_r000487_11 & 2) != 0) {
            stage_v_80 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_81 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_82 = (pub_r000487_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000487_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000487_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000487_0 & 1) != 0) {
        if ((sec_r000487_3 & 2) != 0) {
            stage_v_83 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000487_0 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_84 = (pub_r000487_5 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000487_5 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000487_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_85 = (pub_r000487_2 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000487_2 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000487_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000487_9 & 2) != 0) {
            stage_v_86 = (pub_r000487_21 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000487_21 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000487_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_87 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000487_15 & 2) != 0) {
            stage_v_88 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000487_4 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_89 = (pub_r000487_13 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000487_13 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000487_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_90 = (pub_r000487_11 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000487_11 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000487_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000487_2 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_91 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_92 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_93 = (pub_r000487_20 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000487_20 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000487_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_94 = (pub_r000487_5 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000487_5 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000487_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_95 = (pub_r000487_7 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000487_7 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000487_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000487_4 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_96 = (pub_r000487_3 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000487_3 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000487_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000487_15 & 2) != 0) {
            stage_v_97 = (pub_r000487_1 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000487_1 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000487_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000487_8 & 2) != 0) {
            stage_v_98 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_99 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_100 = (pub_r000487_2 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000487_2 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000487_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_101 = (pub_r000487_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000487_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000487_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000487_13 & 1) != 0) {
        if ((sec_r000487_2 & 2) != 0) {
            stage_v_102 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_103 = (pub_r000487_3 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000487_3 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000487_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000487_14 & 1) != 0) {
        if ((sec_r000487_11 & 2) != 0) {
            stage_v_104 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000487_1 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_105 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_106 = (pub_r000487_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000487_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000487_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000487_12 & 2) != 0) {
            stage_v_107 = (pub_r000487_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000487_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000487_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000487_12 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_108 = (pub_r000487_5 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000487_5 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000487_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_109 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_110 = (pub_r000487_2 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000487_2 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000487_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000487_5 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_111 = (pub_r000487_0 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000487_0 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000487_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_112 = (pub_r000487_11 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000487_11 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000487_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_113 = (pub_r000487_20 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000487_20 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000487_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000487_5 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_114 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000487_11 & 1) != 0) {
        if ((sec_r000487_8 & 2) != 0) {
            stage_v_115 = (pub_r000487_11 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000487_11 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000487_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_116 = (pub_r000487_22 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000487_22 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000487_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000487_15 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_117 = (pub_r000487_1 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000487_1 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000487_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000487_13 & 1) != 0) {
        if ((sec_r000487_9 & 2) != 0) {
            stage_v_118 = (pub_r000487_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000487_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000487_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000487_12 & 2) != 0) {
            stage_v_119 = (pub_r000487_4 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000487_4 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000487_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000487_14 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_120 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_121 = (pub_r000487_21 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000487_21 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000487_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000487_2 & 2) != 0) {
            stage_v_122 = (pub_r000487_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000487_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000487_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_123 = (pub_r000487_20 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000487_20 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000487_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000487_3 & 1) != 0) {
        if ((sec_r000487_3 & 2) != 0) {
            stage_v_124 = (pub_r000487_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000487_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000487_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_125 = (pub_r000487_18 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000487_18 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000487_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_126 = (pub_r000487_9 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000487_9 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000487_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_127 = (pub_r000487_18 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000487_18 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000487_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_128 = (pub_r000487_4 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000487_4 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000487_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000487_15 & 2) != 0) {
            stage_v_129 = (pub_r000487_12 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000487_12 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000487_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_130 = (pub_r000487_15 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000487_15 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000487_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000487_13 & 2) != 0) {
            stage_v_131 = (pub_r000487_20 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000487_20 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000487_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000487_3 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_132 = (pub_r000487_12 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000487_12 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000487_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_133 = (pub_r000487_1 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000487_1 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000487_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_134 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_135 = (pub_r000487_17 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000487_17 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000487_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000487_12 & 2) != 0) {
            stage_v_136 = (pub_r000487_14 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000487_14 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000487_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000487_2 & 2) != 0) {
            stage_v_137 = (pub_r000487_4 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000487_4 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000487_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000487_9 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_138 = (pub_r000487_6 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000487_6 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000487_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000487_13 & 1) != 0) {
        if ((sec_r000487_6 & 2) != 0) {
            stage_v_139 = (pub_r000487_16 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000487_16 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000487_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000487_15 & 1) != 0) {
        if ((sec_r000487_4 & 2) != 0) {
            stage_v_140 = (pub_r000487_15 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000487_15 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000487_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_141 = (pub_r000487_3 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000487_3 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000487_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_142 = (pub_r000487_19 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000487_19 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000487_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000487_11 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_143 = (pub_r000487_21 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000487_21 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000487_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000487_1 & 2) != 0) {
            stage_v_144 = (pub_r000487_9 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000487_9 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000487_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000487_7 & 2) != 0) {
            stage_v_145 = (pub_r000487_21 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000487_21 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000487_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_146 = (pub_r000487_10 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000487_10 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000487_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000487_8 & 1) != 0) {
        if ((sec_r000487_14 & 2) != 0) {
            stage_v_147 = (pub_r000487_17 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000487_17 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000487_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_148 = (pub_r000487_15 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000487_15 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000487_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000487_11 & 1) != 0) {
        if ((sec_r000487_10 & 2) != 0) {
            stage_v_149 = (pub_r000487_14 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000487_14 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000487_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_150 = (pub_r000487_13 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000487_13 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000487_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000487_1 & 1) != 0) {
        if ((sec_r000487_5 & 2) != 0) {
            stage_v_151 = (pub_r000487_17 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000487_17 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000487_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000487_0 & 2) != 0) {
            stage_v_152 = (pub_r000487_11 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000487_11 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000487_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
