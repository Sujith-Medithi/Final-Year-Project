/*
 * Benchmark Program: R000478
 * Security Family: secret_dependent_loops
 * Generator Seed: 549824
 * High Inputs: 23 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000478_9824_0 {
    int fee;
    short account_id;
    int balance;
    int status;
    int buffer[3];
};

struct DeviceConfig_R000478_9824_1 {
    unsigned char stop_bits;
    int timeout;
    short id;
    int port;
    int buffer[3];
};

struct StreamBuffer_R000478_9824_2 {
    short head;
    short checksum;
    short watermark;
    int state;
    short capacity;
    unsigned char tail;
    int buffer[3];
};

struct SensorNode_R000478_9824_3 {
    short gain;
    short status;
    int reading;
    int offset;
    int calib;
    unsigned char threshold;
    int buffer[3];
};

union PacketPayload_R000478_9824_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000478_9824_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000478_9824_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int parity_35 = local_arr[aux % 3];
    acc = (acc + parity_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int quantum_43 = local_arr[aux % 3];
    acc = (acc + quantum_43 * 2) & 127;
    int threshold_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_2(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_75 = (aux + st.buffer[1]) & 3;
    switch (anchor_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_63 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_63 > 29) {
        acc = (acc + vector_63 * 2 + 5) & 127;
        aux ^= (vector_63 & 15);
    } else {
        acc = (acc - vector_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_4(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_5(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000478_9824_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_74 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_74 > 30) {
        acc = (acc + index_reg_74 * 2 + 5) & 127;
        aux ^= (index_reg_74 & 15);
    } else {
        acc = (acc - index_reg_74 + 11) & 127;
        aux += 3;
    }
    int scale_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_25 = local_arr[aux % 3];
    acc = (acc + threshold_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000478_9824_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_16 = (aux + st.buffer[1]) & 3;
    switch (quantum_16) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_12 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_12 > 13) {
        acc = (acc + weight_12 * 2 + 5) & 127;
        aux ^= (weight_12 & 15);
    } else {
        acc = (acc - weight_12 + 11) & 127;
        aux += 3;
    }
    int delta_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int index_reg_73 = local_arr[aux % 3];
    acc = (acc + index_reg_73 * 2) & 127;
    int anchor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000478_9824_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_62 = (aux + st.buffer[1]) & 3;
    switch (tally_62) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_28 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_28 > 37) {
        acc = (acc + index_reg_28 * 2 + 5) & 127;
        aux ^= (index_reg_28 & 15);
    } else {
        acc = (acc - index_reg_28 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_74 = local_arr[aux % 3];
    acc = (acc + anchor_74 * 2) & 127;
    int pivot_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_72 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_72 > 49) {
        acc = (acc + bound_72 * 2 + 5) & 127;
        aux ^= (bound_72 & 15);
    } else {
        acc = (acc - bound_72 + 11) & 127;
        aux += 3;
    }
    int weight_86 = (aux + st.buffer[1]) & 3;
    switch (weight_86) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_10(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000478_9824_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int sample_41 = local_arr[aux % 3];
    acc = (acc + sample_41 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000478_9824_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_63 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_63 > 27) {
        acc = (acc + sample_63 * 2 + 5) & 127;
        aux ^= (sample_63 & 15);
    } else {
        acc = (acc - sample_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000478_9824_12(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_39 = local_arr[aux % 3];
    acc = (acc + weight_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_13(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_24 > 17) {
        acc = (acc + anchor_24 * 2 + 5) & 127;
        aux ^= (anchor_24 & 15);
    } else {
        acc = (acc - anchor_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_48 = local_arr[aux % 3];
    acc = (acc + phase_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_14(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int offset_10 = (aux + st.buffer[1]) & 3;
    switch (offset_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_87 = local_arr[aux % 3];
    acc = (acc + margin_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_15(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_30 = local_arr[aux % 3];
    acc = (acc + mask_30 * 2) & 127;
    int cursor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_54 > 16) {
        acc = (acc + cursor_54 * 2 + 5) & 127;
        aux ^= (cursor_54 & 15);
    } else {
        acc = (acc - cursor_54 + 11) & 127;
        aux += 3;
    }
    int accumulator_30 = (aux + st.buffer[1]) & 3;
    switch (accumulator_30) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000478_9824_16(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000478_9824_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_71) & 63;
    acc ^= aux;
    int checksum_78 = (aux + st.buffer[1]) & 3;
    switch (checksum_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_10 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_10 > 21) {
        acc = (acc + bound_10 * 2 + 5) & 127;
        aux ^= (bound_10 & 15);
    } else {
        acc = (acc - bound_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000478_9824_17(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_44) & 63;
    acc ^= aux;
    int parity_95 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_95 > 34) {
        acc = (acc + parity_95 * 2 + 5) & 127;
        aux ^= (parity_95 & 15);
    } else {
        acc = (acc - parity_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_19 = local_arr[aux % 3];
    acc = (acc + parity_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000478_9824_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_91 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_91 > 33) {
        acc = (acc + offset_91 * 2 + 5) & 127;
        aux ^= (offset_91 & 15);
    } else {
        acc = (acc - offset_91 + 11) & 127;
        aux += 3;
    }
    int delta_23 = (aux + st.buffer[1]) & 3;
    switch (delta_23) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000478_9824_19(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000478_9824_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_89 = (aux + st.buffer[1]) & 3;
    switch (cursor_89) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_22) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_37 = local_arr[aux % 3];
    acc = (acc + checksum_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000478_9824_20(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000478_9824_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int accumulator_33 = local_arr[aux % 3];
    acc = (acc + accumulator_33 * 2) & 127;
    int margin_82 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_82 > 41) {
        acc = (acc + margin_82 * 2 + 5) & 127;
        aux ^= (margin_82 & 15);
    } else {
        acc = (acc - margin_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_61 = (aux + st.buffer[1]) & 3;
    switch (parity_61) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000478_9824_21(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000478_9824_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_91 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_91 > 25) {
        acc = (acc + tally_91 * 2 + 5) & 127;
        aux ^= (tally_91 & 15);
    } else {
        acc = (acc - tally_91 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_42 = local_arr[aux % 3];
    acc = (acc + mask_42 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000478_0;
    int sec_r000478_1;
    int sec_r000478_2;
    int sec_r000478_3;
    int sec_r000478_4;
    int sec_r000478_5;
    int sec_r000478_6;
    int sec_r000478_7;
    int sec_r000478_8;
    int sec_r000478_9;
    int sec_r000478_10;
    int sec_r000478_11;
    int sec_r000478_12;
    int sec_r000478_13;
    int sec_r000478_14;
    int sec_r000478_15;
    int sec_r000478_16;
    int sec_r000478_17;
    int sec_r000478_18;
    int sec_r000478_19;
    int sec_r000478_20;
    int sec_r000478_21;
    int sec_r000478_22;
    int pub_r000478_0;
    int pub_r000478_1;
    int pub_r000478_2;
    int pub_r000478_3;
    int pub_r000478_4;
    int pub_r000478_5;
    int pub_r000478_6;
    int pub_r000478_7;
    int pub_r000478_8;
    int pub_r000478_9;
    int pub_r000478_10;
    int pub_r000478_11;
    int pub_r000478_12;
    int pub_r000478_13;
    int pub_r000478_14;
    int pub_r000478_15;
    int pub_r000478_16;
    int pub_r000478_17;
    int pub_r000478_18;
    int pub_r000478_19;
    int pub_r000478_20;
    int pub_r000478_21;
    int pub_r000478_22;
    int pub_r000478_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000478_0 >= -100 && pub_r000478_0 <= 100);
    __CPROVER_assume(pub_r000478_1 >= -100 && pub_r000478_1 <= 100);
    __CPROVER_assume(pub_r000478_2 >= -100 && pub_r000478_2 <= 100);
    __CPROVER_assume(pub_r000478_3 >= -100 && pub_r000478_3 <= 100);
    __CPROVER_assume(pub_r000478_4 >= -100 && pub_r000478_4 <= 100);
    __CPROVER_assume(pub_r000478_5 >= -100 && pub_r000478_5 <= 100);
    __CPROVER_assume(pub_r000478_6 >= -100 && pub_r000478_6 <= 100);
    __CPROVER_assume(pub_r000478_7 >= -100 && pub_r000478_7 <= 100);
    __CPROVER_assume(pub_r000478_8 >= -100 && pub_r000478_8 <= 100);
    __CPROVER_assume(pub_r000478_9 >= -100 && pub_r000478_9 <= 100);
    __CPROVER_assume(pub_r000478_10 >= -100 && pub_r000478_10 <= 100);
    __CPROVER_assume(pub_r000478_11 >= -100 && pub_r000478_11 <= 100);
    __CPROVER_assume(pub_r000478_12 >= -100 && pub_r000478_12 <= 100);
    __CPROVER_assume(pub_r000478_13 >= -100 && pub_r000478_13 <= 100);
    __CPROVER_assume(pub_r000478_14 >= -100 && pub_r000478_14 <= 100);
    __CPROVER_assume(pub_r000478_15 >= -100 && pub_r000478_15 <= 100);
    __CPROVER_assume(pub_r000478_16 >= -100 && pub_r000478_16 <= 100);
    __CPROVER_assume(pub_r000478_17 >= -100 && pub_r000478_17 <= 100);
    __CPROVER_assume(pub_r000478_18 >= -100 && pub_r000478_18 <= 100);
    __CPROVER_assume(pub_r000478_19 >= -100 && pub_r000478_19 <= 100);
    __CPROVER_assume(pub_r000478_20 >= -100 && pub_r000478_20 <= 100);
    __CPROVER_assume(pub_r000478_21 >= -100 && pub_r000478_21 <= 100);
    __CPROVER_assume(pub_r000478_22 >= -100 && pub_r000478_22 <= 100);
    __CPROVER_assume(pub_r000478_23 >= -100 && pub_r000478_23 <= 100);
    __CPROVER_assume(sec_r000478_0 >= 0 && sec_r000478_0 <= 255);
    __CPROVER_assume(sec_r000478_1 >= 0 && sec_r000478_1 <= 255);
    __CPROVER_assume(sec_r000478_2 >= 0 && sec_r000478_2 <= 255);
    __CPROVER_assume(sec_r000478_3 >= 0 && sec_r000478_3 <= 255);
    __CPROVER_assume(sec_r000478_4 >= 0 && sec_r000478_4 <= 255);
    __CPROVER_assume(sec_r000478_5 >= 0 && sec_r000478_5 <= 255);
    __CPROVER_assume(sec_r000478_6 >= 0 && sec_r000478_6 <= 255);
    __CPROVER_assume(sec_r000478_7 >= 0 && sec_r000478_7 <= 255);
    __CPROVER_assume(sec_r000478_8 >= 0 && sec_r000478_8 <= 255);
    __CPROVER_assume(sec_r000478_9 >= 0 && sec_r000478_9 <= 255);
    __CPROVER_assume(sec_r000478_10 >= 0 && sec_r000478_10 <= 255);
    __CPROVER_assume(sec_r000478_11 >= 0 && sec_r000478_11 <= 255);
    __CPROVER_assume(sec_r000478_12 >= 0 && sec_r000478_12 <= 255);
    __CPROVER_assume(sec_r000478_13 >= 0 && sec_r000478_13 <= 255);
    __CPROVER_assume(sec_r000478_14 >= 0 && sec_r000478_14 <= 255);
    __CPROVER_assume(sec_r000478_15 >= 0 && sec_r000478_15 <= 255);
    __CPROVER_assume(sec_r000478_16 >= 0 && sec_r000478_16 <= 255);
    __CPROVER_assume(sec_r000478_17 >= 0 && sec_r000478_17 <= 255);
    __CPROVER_assume(sec_r000478_18 >= 0 && sec_r000478_18 <= 255);
    __CPROVER_assume(sec_r000478_19 >= 0 && sec_r000478_19 <= 255);
    __CPROVER_assume(sec_r000478_20 >= 0 && sec_r000478_20 <= 255);
    __CPROVER_assume(sec_r000478_21 >= 0 && sec_r000478_21 <= 255);
    __CPROVER_assume(sec_r000478_22 >= 0 && sec_r000478_22 <= 255);

    struct Transaction_R000478_9824_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000478_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000478_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000478_0 + 7) & 15;
    struct DeviceConfig_R000478_9824_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000478_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000478_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000478_0 + 9) & 15;
    struct StreamBuffer_R000478_9824_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000478_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000478_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000478_0 + 11) & 15;
    struct SensorNode_R000478_9824_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000478_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000478_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000478_0 + 13) & 15;

    union PacketPayload_R000478_9824_0 u_var;
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
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
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
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 55) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 35) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 50) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 27) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 42) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

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
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 38) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 53) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 31) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 46) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 31) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 46) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 19) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 34) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 18) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 33) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 39) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_20 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000478_0) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000478_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000478_10) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000478_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000478_15) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000478_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000478_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_8 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000478_23) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000478_4) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000478_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_21 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000478_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000478_6) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000478_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000478_23) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000478_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000478_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_17 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000478_15) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000478_21) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000478_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000478_21) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000478_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000478_10) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_14 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000478_0) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000478_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000478_17) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000478_6) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000478_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000478_10) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_6 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000478_3) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000478_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000478_17) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000478_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_11 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000478_18) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000478_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000478_23) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000478_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000478_5) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000478_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000478_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000478_0) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000478_15) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000478_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_18 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000478_17) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_14 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000478_7) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_15 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000478_3) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000478_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_4 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000478_4) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_12 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000478_21) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000478_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000478_10) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000478_3) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000478_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000478_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_17 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000478_2) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000478_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000478_14) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_16 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000478_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_20 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000478_19) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000478_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_21 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000478_1) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000478_7) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000478_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000478_15) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000478_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_6 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000478_13) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_14 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000478_11) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000478_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000478_15) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000478_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000478_16) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000478_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000478_16) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000478_6) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_5 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000478_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000478_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000478_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000478_13) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000478_16) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000478_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000478_1) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000478_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000478_13) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000478_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000478_14) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000478_4) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000478_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_16 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000478_6) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000478_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_22 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000478_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000478_1) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000478_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000478_5) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000478_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000478_11) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000478_10) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000478_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000478_18) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_8 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000478_1) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000478_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000478_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000478_12) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000478_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000478_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000478_13) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000478_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_18 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000478_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000478_9) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000478_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000478_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000478_16 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000478_1) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000478_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000478_8) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000478_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000478_20) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000478_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000478_13) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000478_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
