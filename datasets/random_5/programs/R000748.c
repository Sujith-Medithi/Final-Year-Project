/*
 * Benchmark Program: R000748
 * Security Family: secret_dependent_loops
 * Generator Seed: 574813
 * High Inputs: 23 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000748_4813_0 {
    unsigned char prev_in;
    int cutoff;
    int damping;
    int prev_out;
    short mode;
    unsigned char gain_db;
    int buffer[3];
};

struct DeviceConfig_R000748_4813_1 {
    short id;
    short parity;
    unsigned char baud_rate;
    short stop_bits;
    int timeout;
    short port;
    int buffer[3];
};

struct CipherContext_R000748_4813_2 {
    int round_key;
    short tag;
    unsigned char nonce;
    unsigned char iv;
    int buffer[3];
};

struct StreamBuffer_R000748_4813_3 {
    short checksum;
    short tail;
    unsigned char head;
    unsigned char state;
    unsigned char capacity;
    int buffer[3];
};

union RegisterBank_R000748_4813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000748_4813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000748_4813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_57) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_45 = local_arr[aux % 3];
    acc = (acc + checksum_45 * 2) & 127;
    int sample_89 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_89 > 32) {
        acc = (acc + sample_89 * 2 + 5) & 127;
        aux ^= (sample_89 & 15);
    } else {
        acc = (acc - sample_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_41 = local_arr[aux % 3];
    acc = (acc + pivot_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_2(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_3(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_42 = (aux + st.buffer[1]) & 3;
    switch (tally_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_76 = local_arr[aux % 3];
    acc = (acc + parity_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_4(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int vector_31 = local_arr[aux % 3];
    acc = (acc + vector_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_31 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_31 > 17) {
        acc = (acc + stride_31 * 2 + 5) & 127;
        aux ^= (stride_31 & 15);
    } else {
        acc = (acc - stride_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_5(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_29) & 63;
    acc ^= aux;
    int delta_93 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_93 > 25) {
        acc = (acc + delta_93 * 2 + 5) & 127;
        aux ^= (delta_93 & 15);
    } else {
        acc = (acc - delta_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int parity_41 = local_arr[aux % 3];
    acc = (acc + parity_41 * 2) & 127;
    int phase_31 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_31 > 26) {
        acc = (acc + phase_31 * 2 + 5) & 127;
        aux ^= (phase_31 & 15);
    } else {
        acc = (acc - phase_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_7(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_25 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_25 > 29) {
        acc = (acc + stride_25 * 2 + 5) & 127;
        aux ^= (stride_25 & 15);
    } else {
        acc = (acc - stride_25 + 11) & 127;
        aux += 3;
    }
    int threshold_62 = (aux + st.buffer[1]) & 3;
    switch (threshold_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_85 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_85 > 38) {
        acc = (acc + checksum_85 * 2 + 5) & 127;
        aux ^= (checksum_85 & 15);
    } else {
        acc = (acc - checksum_85 + 11) & 127;
        aux += 3;
    }
    int checksum_29 = (aux + st.buffer[1]) & 3;
    switch (checksum_29) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_79 > 29) {
        acc = (acc + factor_79 * 2 + 5) & 127;
        aux ^= (factor_79 & 15);
    } else {
        acc = (acc - factor_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_71 = local_arr[aux % 3];
    acc = (acc + weight_71 * 2) & 127;
    int cursor_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000748_4813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int scale_68 = local_arr[aux % 3];
    acc = (acc + scale_68 * 2) & 127;
    int stride_75 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_75 > 17) {
        acc = (acc + stride_75 * 2 + 5) & 127;
        aux ^= (stride_75 & 15);
    } else {
        acc = (acc - stride_75 + 11) & 127;
        aux += 3;
    }
    int window_43 = (aux + st.buffer[1]) & 3;
    switch (window_43) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_17 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_17 > 15) {
        acc = (acc + tally_17 * 2 + 5) & 127;
        aux ^= (tally_17 & 15);
    } else {
        acc = (acc - tally_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_16 = local_arr[aux % 3];
    acc = (acc + quantum_16 * 2) & 127;
    int residue_83 = (aux + st.buffer[1]) & 3;
    switch (residue_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_12(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_96) & 63;
    acc ^= aux;
    int accumulator_41 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_41 > 13) {
        acc = (acc + accumulator_41 * 2 + 5) & 127;
        aux ^= (accumulator_41 & 15);
    } else {
        acc = (acc - accumulator_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_13(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int weight_37 = local_arr[aux % 3];
    acc = (acc + weight_37 * 2) & 127;
    int offset_96 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_96 > 41) {
        acc = (acc + offset_96 * 2 + 5) & 127;
        aux ^= (offset_96 & 15);
    } else {
        acc = (acc - offset_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_19 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_19 > 15) {
        acc = (acc + margin_19 * 2 + 5) & 127;
        aux ^= (margin_19 & 15);
    } else {
        acc = (acc - margin_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_49 = local_arr[aux % 3];
    acc = (acc + sample_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_99 = (aux + st.buffer[1]) & 3;
    switch (sample_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_21 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_21 > 25) {
        acc = (acc + pivot_21 * 2 + 5) & 127;
        aux ^= (pivot_21 & 15);
    } else {
        acc = (acc - pivot_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_16(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_74 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_74 > 40) {
        acc = (acc + coefficient_74 * 2 + 5) & 127;
        aux ^= (coefficient_74 & 15);
    } else {
        acc = (acc - coefficient_74 + 11) & 127;
        aux += 3;
    }
    int phase_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000748_4813_17(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_92 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_92 > 22) {
        acc = (acc + phase_92 * 2 + 5) & 127;
        aux ^= (phase_92 & 15);
    } else {
        acc = (acc - phase_92 + 11) & 127;
        aux += 3;
    }
    int bound_20 = (aux + st.buffer[1]) & 3;
    switch (bound_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int threshold_54 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_54 > 17) {
        acc = (acc + threshold_54 * 2 + 5) & 127;
        aux ^= (threshold_54 & 15);
    } else {
        acc = (acc - threshold_54 + 11) & 127;
        aux += 3;
    }
    int residue_96 = (aux + st.buffer[1]) & 3;
    switch (residue_96) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_19(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_68) & 63;
    acc ^= aux;
    int scale_11 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_11 > 10) {
        acc = (acc + scale_11 * 2 + 5) & 127;
        aux ^= (scale_11 & 15);
    } else {
        acc = (acc - scale_11 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_23 = local_arr[aux % 3];
    acc = (acc + coefficient_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_20(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int threshold_79 = (aux + st.buffer[1]) & 3;
    switch (threshold_79) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000748_4813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_10 = (aux + st.buffer[1]) & 3;
    switch (factor_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_83 = local_arr[aux % 3];
    acc = (acc + stride_83 * 2) & 127;
    int pivot_72 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_72 > 11) {
        acc = (acc + pivot_72 * 2 + 5) & 127;
        aux ^= (pivot_72 & 15);
    } else {
        acc = (acc - pivot_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000748_4813_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quantum_39 = (aux + st.buffer[1]) & 3;
    switch (quantum_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_95 = local_arr[aux % 3];
    acc = (acc + sample_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000748_4813_23(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int stride_88 = local_arr[aux % 3];
    acc = (acc + stride_88 * 2) & 127;
    int tally_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_14) & 63;
    acc ^= aux;
    int checksum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_79 > 13) {
        acc = (acc + checksum_79 * 2 + 5) & 127;
        aux ^= (checksum_79 & 15);
    } else {
        acc = (acc - checksum_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000748_0;
    int sec_r000748_1;
    int sec_r000748_2;
    int sec_r000748_3;
    int sec_r000748_4;
    int sec_r000748_5;
    int sec_r000748_6;
    int sec_r000748_7;
    int sec_r000748_8;
    int sec_r000748_9;
    int sec_r000748_10;
    int sec_r000748_11;
    int sec_r000748_12;
    int sec_r000748_13;
    int sec_r000748_14;
    int sec_r000748_15;
    int sec_r000748_16;
    int sec_r000748_17;
    int sec_r000748_18;
    int sec_r000748_19;
    int sec_r000748_20;
    int sec_r000748_21;
    int sec_r000748_22;
    int pub_r000748_0;
    int pub_r000748_1;
    int pub_r000748_2;
    int pub_r000748_3;
    int pub_r000748_4;
    int pub_r000748_5;
    int pub_r000748_6;
    int pub_r000748_7;
    int pub_r000748_8;
    int pub_r000748_9;
    int pub_r000748_10;
    int pub_r000748_11;
    int pub_r000748_12;
    int pub_r000748_13;
    int pub_r000748_14;
    int pub_r000748_15;
    int pub_r000748_16;
    int pub_r000748_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000748_0 >= -100 && pub_r000748_0 <= 100);
    __CPROVER_assume(pub_r000748_1 >= -100 && pub_r000748_1 <= 100);
    __CPROVER_assume(pub_r000748_2 >= -100 && pub_r000748_2 <= 100);
    __CPROVER_assume(pub_r000748_3 >= -100 && pub_r000748_3 <= 100);
    __CPROVER_assume(pub_r000748_4 >= -100 && pub_r000748_4 <= 100);
    __CPROVER_assume(pub_r000748_5 >= -100 && pub_r000748_5 <= 100);
    __CPROVER_assume(pub_r000748_6 >= -100 && pub_r000748_6 <= 100);
    __CPROVER_assume(pub_r000748_7 >= -100 && pub_r000748_7 <= 100);
    __CPROVER_assume(pub_r000748_8 >= -100 && pub_r000748_8 <= 100);
    __CPROVER_assume(pub_r000748_9 >= -100 && pub_r000748_9 <= 100);
    __CPROVER_assume(pub_r000748_10 >= -100 && pub_r000748_10 <= 100);
    __CPROVER_assume(pub_r000748_11 >= -100 && pub_r000748_11 <= 100);
    __CPROVER_assume(pub_r000748_12 >= -100 && pub_r000748_12 <= 100);
    __CPROVER_assume(pub_r000748_13 >= -100 && pub_r000748_13 <= 100);
    __CPROVER_assume(pub_r000748_14 >= -100 && pub_r000748_14 <= 100);
    __CPROVER_assume(pub_r000748_15 >= -100 && pub_r000748_15 <= 100);
    __CPROVER_assume(pub_r000748_16 >= -100 && pub_r000748_16 <= 100);
    __CPROVER_assume(pub_r000748_17 >= -100 && pub_r000748_17 <= 100);
    __CPROVER_assume(sec_r000748_0 >= 0 && sec_r000748_0 <= 255);
    __CPROVER_assume(sec_r000748_1 >= 0 && sec_r000748_1 <= 255);
    __CPROVER_assume(sec_r000748_2 >= 0 && sec_r000748_2 <= 255);
    __CPROVER_assume(sec_r000748_3 >= 0 && sec_r000748_3 <= 255);
    __CPROVER_assume(sec_r000748_4 >= 0 && sec_r000748_4 <= 255);
    __CPROVER_assume(sec_r000748_5 >= 0 && sec_r000748_5 <= 255);
    __CPROVER_assume(sec_r000748_6 >= 0 && sec_r000748_6 <= 255);
    __CPROVER_assume(sec_r000748_7 >= 0 && sec_r000748_7 <= 255);
    __CPROVER_assume(sec_r000748_8 >= 0 && sec_r000748_8 <= 255);
    __CPROVER_assume(sec_r000748_9 >= 0 && sec_r000748_9 <= 255);
    __CPROVER_assume(sec_r000748_10 >= 0 && sec_r000748_10 <= 255);
    __CPROVER_assume(sec_r000748_11 >= 0 && sec_r000748_11 <= 255);
    __CPROVER_assume(sec_r000748_12 >= 0 && sec_r000748_12 <= 255);
    __CPROVER_assume(sec_r000748_13 >= 0 && sec_r000748_13 <= 255);
    __CPROVER_assume(sec_r000748_14 >= 0 && sec_r000748_14 <= 255);
    __CPROVER_assume(sec_r000748_15 >= 0 && sec_r000748_15 <= 255);
    __CPROVER_assume(sec_r000748_16 >= 0 && sec_r000748_16 <= 255);
    __CPROVER_assume(sec_r000748_17 >= 0 && sec_r000748_17 <= 255);
    __CPROVER_assume(sec_r000748_18 >= 0 && sec_r000748_18 <= 255);
    __CPROVER_assume(sec_r000748_19 >= 0 && sec_r000748_19 <= 255);
    __CPROVER_assume(sec_r000748_20 >= 0 && sec_r000748_20 <= 255);
    __CPROVER_assume(sec_r000748_21 >= 0 && sec_r000748_21 <= 255);
    __CPROVER_assume(sec_r000748_22 >= 0 && sec_r000748_22 <= 255);

    struct FilterState_R000748_4813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000748_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000748_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000748_0 + 7) & 15;
    struct DeviceConfig_R000748_4813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000748_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000748_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000748_0 + 9) & 15;
    struct CipherContext_R000748_4813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000748_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000748_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000748_0 + 11) & 15;
    struct StreamBuffer_R000748_4813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000748_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000748_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000748_0 + 13) & 15;

    union RegisterBank_R000748_4813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

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
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 31) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 46) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
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
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 19) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 34) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_9 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000748_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000748_0) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000748_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000748_17) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000748_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000748_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000748_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000748_15) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000748_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_1 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000748_6) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_10 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000748_2) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000748_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000748_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000748_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000748_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000748_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_22 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000748_0) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000748_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_18 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000748_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_13 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000748_3) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000748_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_21 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000748_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_9 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000748_16) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000748_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000748_1) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_3 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000748_1) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000748_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000748_16) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_17 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000748_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_22 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_15 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000748_1) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000748_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_10 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000748_5) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000748_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000748_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000748_16) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000748_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000748_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_0 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000748_15) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000748_17) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000748_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000748_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000748_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_18 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_13 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000748_4) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000748_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000748_12) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000748_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_0 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_8 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000748_15) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000748_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000748_3) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000748_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000748_0) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000748_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_8 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000748_1) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000748_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_3 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_107 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000748_6) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000748_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_3 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_17 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000748_13) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000748_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000748_10) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000748_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000748_7) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000748_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000748_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_21 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000748_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_13 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000748_15) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000748_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000748_2) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000748_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_4 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000748_15) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000748_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_17 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000748_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000748_9) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000748_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000748_5) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000748_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_12 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000748_11) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000748_0) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000748_17) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000748_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000748_14) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000748_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000748_8) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000748_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000748_12 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000748_10) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000748_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
