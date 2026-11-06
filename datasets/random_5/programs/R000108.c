/*
 * Benchmark Program: R000108
 * Security Family: secret_dependent_loops
 * Generator Seed: 510813
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000108_813_0 {
    int code;
    int seq;
    int timestamp;
    int facility;
    int signature;
    unsigned char severity;
    int buffer[3];
};

struct FilterState_R000108_813_1 {
    short mode;
    unsigned char damping;
    short prev_out;
    int buffer[3];
};

union TelemetryField_R000108_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000108_813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000108_813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_33 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_33 > 27) {
        acc = (acc + residue_33 * 2 + 5) & 127;
        aux ^= (residue_33 & 15);
    } else {
        acc = (acc - residue_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_33 = local_arr[aux % 3];
    acc = (acc + phase_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000108_813_1(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_19 = (aux + st.buffer[1]) & 3;
    switch (coefficient_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int coefficient_12 = local_arr[aux % 3];
    acc = (acc + coefficient_12 * 2) & 127;
    int parity_13 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_13 > 14) {
        acc = (acc + parity_13 * 2 + 5) & 127;
        aux ^= (parity_13 & 15);
    } else {
        acc = (acc - parity_13 + 11) & 127;
        aux += 3;
    }
    int index_reg_68 = (aux + st.buffer[1]) & 3;
    switch (index_reg_68) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000108_813_3(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_53 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_53 > 22) {
        acc = (acc + cursor_53 * 2 + 5) & 127;
        aux ^= (cursor_53 & 15);
    } else {
        acc = (acc - cursor_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_4(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int window_55 = local_arr[aux % 3];
    acc = (acc + window_55 * 2) & 127;
    int anchor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_57) & 63;
    acc ^= aux;
    int residue_92 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_92 > 28) {
        acc = (acc + residue_92 * 2 + 5) & 127;
        aux ^= (residue_92 & 15);
    } else {
        acc = (acc - residue_92 + 11) & 127;
        aux += 3;
    }
    int vector_29 = (aux + st.buffer[1]) & 3;
    switch (vector_29) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_12 = (aux + st.buffer[1]) & 3;
    switch (margin_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_49) & 63;
    acc ^= aux;
    int margin_84 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_84 > 31) {
        acc = (acc + margin_84 * 2 + 5) & 127;
        aux ^= (margin_84 & 15);
    } else {
        acc = (acc - margin_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int metric_93 = local_arr[aux % 3];
    acc = (acc + metric_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_85 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_85 > 17) {
        acc = (acc + margin_85 * 2 + 5) & 127;
        aux ^= (margin_85 & 15);
    } else {
        acc = (acc - margin_85 + 11) & 127;
        aux += 3;
    }
    int weight_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_7(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int quotient_41 = local_arr[aux % 3];
    acc = (acc + quotient_41 * 2) & 127;
    int weight_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_89) & 63;
    acc ^= aux;
    int stride_14 = (aux + st.buffer[1]) & 3;
    switch (stride_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_8(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_88 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_88 > 33) {
        acc = (acc + threshold_88 * 2 + 5) & 127;
        aux ^= (threshold_88 & 15);
    } else {
        acc = (acc - threshold_88 + 11) & 127;
        aux += 3;
    }
    int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_38) & 63;
    acc ^= aux;
    int index_reg_84 = (aux + st.buffer[1]) & 3;
    switch (index_reg_84) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_9(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_86 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_86 > 37) {
        acc = (acc + phase_86 * 2 + 5) & 127;
        aux ^= (phase_86 & 15);
    } else {
        acc = (acc - phase_86 + 11) & 127;
        aux += 3;
    }
    int window_87 = (aux + st.buffer[1]) & 3;
    switch (window_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_10(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_92 = (aux + st.buffer[1]) & 3;
    switch (weight_92) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_63 = (st.buffer[0] * 3 + aux) & 63;
    if (window_63 > 27) {
        acc = (acc + window_63 * 2 + 5) & 127;
        aux ^= (window_63 & 15);
    } else {
        acc = (acc - window_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_70 = local_arr[aux % 3];
    acc = (acc + scale_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000108_813_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_89 = (aux + st.buffer[1]) & 3;
    switch (tally_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_25 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_25 > 31) {
        acc = (acc + sample_25 * 2 + 5) & 127;
        aux ^= (sample_25 & 15);
    } else {
        acc = (acc - sample_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_12(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int tally_48 = local_arr[aux % 3];
    acc = (acc + tally_48 * 2) & 127;
    int coefficient_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int delta_86 = local_arr[aux % 3];
    acc = (acc + delta_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_92 = (st.buffer[0] * 3 + aux) & 63;
    if (window_92 > 39) {
        acc = (acc + window_92 * 2 + 5) & 127;
        aux ^= (window_92 & 15);
    } else {
        acc = (acc - window_92 + 11) & 127;
        aux += 3;
    }
    int quantum_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_71 = (aux + st.buffer[1]) & 3;
    switch (accumulator_71) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_15(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_96 = (aux + st.buffer[1]) & 3;
    switch (window_96) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_69 = local_arr[aux % 3];
    acc = (acc + delta_69 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_82) & 63;
    acc ^= aux;
    int accumulator_75 = (aux + st.buffer[1]) & 3;
    switch (accumulator_75) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_17(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_73 = (aux + st.buffer[1]) & 3;
    switch (offset_73) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000108_813_18(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int pivot_44 = local_arr[aux % 3];
    acc = (acc + pivot_44 * 2) & 127;
    int stride_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_58) & 63;
    acc ^= aux;
    int accumulator_60 = (aux + st.buffer[1]) & 3;
    switch (accumulator_60) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000108_813_19(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_18 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_18 > 14) {
        acc = (acc + phase_18 * 2 + 5) & 127;
        aux ^= (phase_18 & 15);
    } else {
        acc = (acc - phase_18 + 11) & 127;
        aux += 3;
    }
    int stride_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_63) & 63;
    acc ^= aux;
    int offset_12 = (aux + st.buffer[1]) & 3;
    switch (offset_12) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000108_813_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_79 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_79 > 31) {
        acc = (acc + phase_79 * 2 + 5) & 127;
        aux ^= (phase_79 & 15);
    } else {
        acc = (acc - phase_79 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000108_0;
    int sec_r000108_1;
    int sec_r000108_2;
    int sec_r000108_3;
    int sec_r000108_4;
    int sec_r000108_5;
    int sec_r000108_6;
    int sec_r000108_7;
    int sec_r000108_8;
    int sec_r000108_9;
    int sec_r000108_10;
    int sec_r000108_11;
    int sec_r000108_12;
    int sec_r000108_13;
    int sec_r000108_14;
    int sec_r000108_15;
    int sec_r000108_16;
    int sec_r000108_17;
    int sec_r000108_18;
    int pub_r000108_0;
    int pub_r000108_1;
    int pub_r000108_2;
    int pub_r000108_3;
    int pub_r000108_4;
    int pub_r000108_5;
    int pub_r000108_6;
    int pub_r000108_7;
    int pub_r000108_8;
    int pub_r000108_9;
    int pub_r000108_10;
    int pub_r000108_11;
    int pub_r000108_12;
    int pub_r000108_13;
    int pub_r000108_14;
    int pub_r000108_15;
    int pub_r000108_16;
    int pub_r000108_17;
    int pub_r000108_18;
    int pub_r000108_19;
    int pub_r000108_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000108_0 >= -100 && pub_r000108_0 <= 100);
    __CPROVER_assume(pub_r000108_1 >= -100 && pub_r000108_1 <= 100);
    __CPROVER_assume(pub_r000108_2 >= -100 && pub_r000108_2 <= 100);
    __CPROVER_assume(pub_r000108_3 >= -100 && pub_r000108_3 <= 100);
    __CPROVER_assume(pub_r000108_4 >= -100 && pub_r000108_4 <= 100);
    __CPROVER_assume(pub_r000108_5 >= -100 && pub_r000108_5 <= 100);
    __CPROVER_assume(pub_r000108_6 >= -100 && pub_r000108_6 <= 100);
    __CPROVER_assume(pub_r000108_7 >= -100 && pub_r000108_7 <= 100);
    __CPROVER_assume(pub_r000108_8 >= -100 && pub_r000108_8 <= 100);
    __CPROVER_assume(pub_r000108_9 >= -100 && pub_r000108_9 <= 100);
    __CPROVER_assume(pub_r000108_10 >= -100 && pub_r000108_10 <= 100);
    __CPROVER_assume(pub_r000108_11 >= -100 && pub_r000108_11 <= 100);
    __CPROVER_assume(pub_r000108_12 >= -100 && pub_r000108_12 <= 100);
    __CPROVER_assume(pub_r000108_13 >= -100 && pub_r000108_13 <= 100);
    __CPROVER_assume(pub_r000108_14 >= -100 && pub_r000108_14 <= 100);
    __CPROVER_assume(pub_r000108_15 >= -100 && pub_r000108_15 <= 100);
    __CPROVER_assume(pub_r000108_16 >= -100 && pub_r000108_16 <= 100);
    __CPROVER_assume(pub_r000108_17 >= -100 && pub_r000108_17 <= 100);
    __CPROVER_assume(pub_r000108_18 >= -100 && pub_r000108_18 <= 100);
    __CPROVER_assume(pub_r000108_19 >= -100 && pub_r000108_19 <= 100);
    __CPROVER_assume(pub_r000108_20 >= -100 && pub_r000108_20 <= 100);
    __CPROVER_assume(sec_r000108_0 >= 0 && sec_r000108_0 <= 255);
    __CPROVER_assume(sec_r000108_1 >= 0 && sec_r000108_1 <= 255);
    __CPROVER_assume(sec_r000108_2 >= 0 && sec_r000108_2 <= 255);
    __CPROVER_assume(sec_r000108_3 >= 0 && sec_r000108_3 <= 255);
    __CPROVER_assume(sec_r000108_4 >= 0 && sec_r000108_4 <= 255);
    __CPROVER_assume(sec_r000108_5 >= 0 && sec_r000108_5 <= 255);
    __CPROVER_assume(sec_r000108_6 >= 0 && sec_r000108_6 <= 255);
    __CPROVER_assume(sec_r000108_7 >= 0 && sec_r000108_7 <= 255);
    __CPROVER_assume(sec_r000108_8 >= 0 && sec_r000108_8 <= 255);
    __CPROVER_assume(sec_r000108_9 >= 0 && sec_r000108_9 <= 255);
    __CPROVER_assume(sec_r000108_10 >= 0 && sec_r000108_10 <= 255);
    __CPROVER_assume(sec_r000108_11 >= 0 && sec_r000108_11 <= 255);
    __CPROVER_assume(sec_r000108_12 >= 0 && sec_r000108_12 <= 255);
    __CPROVER_assume(sec_r000108_13 >= 0 && sec_r000108_13 <= 255);
    __CPROVER_assume(sec_r000108_14 >= 0 && sec_r000108_14 <= 255);
    __CPROVER_assume(sec_r000108_15 >= 0 && sec_r000108_15 <= 255);
    __CPROVER_assume(sec_r000108_16 >= 0 && sec_r000108_16 <= 255);
    __CPROVER_assume(sec_r000108_17 >= 0 && sec_r000108_17 <= 255);
    __CPROVER_assume(sec_r000108_18 >= 0 && sec_r000108_18 <= 255);

    struct EventLog_R000108_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000108_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000108_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000108_0 + 7) & 15;
    struct FilterState_R000108_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000108_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000108_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000108_0 + 9) & 15;

    union TelemetryField_R000108_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
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
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 39) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 54) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 40) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 55) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 14) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 29) {
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
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 29) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 44) {
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
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 15) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 30) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 22) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 37) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 21) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 36) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

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
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 15) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 30) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_12 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000108_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_7 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000108_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000108_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_12 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000108_1) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000108_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000108_18) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000108_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000108_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000108_19) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_0 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000108_5) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000108_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_17 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000108_1) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000108_12) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000108_12) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000108_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_5 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000108_20) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000108_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000108_19) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_6 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000108_11) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_11 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000108_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_2 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000108_18) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000108_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000108_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000108_3) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000108_11) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000108_1) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000108_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_10 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000108_13) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000108_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000108_4) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000108_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000108_12) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000108_3) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000108_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_4 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000108_8) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000108_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_8 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000108_4) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000108_12) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000108_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_3 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000108_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000108_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000108_18) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000108_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000108_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000108_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_3 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000108_18) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000108_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000108_13) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_17 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000108_19) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000108_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000108_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000108_6) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000108_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000108_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_15 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000108_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000108_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_12 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000108_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000108_11) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000108_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000108_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000108_3) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000108_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_14 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000108_3) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000108_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_11 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000108_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000108_1) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000108_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000108_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_1 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000108_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_9 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000108_9) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000108_15) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_7 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_1 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000108_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000108_19) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000108_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_14 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000108_9) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000108_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_16 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000108_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000108_9) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000108_4) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000108_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_15 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000108_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000108_3) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000108_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000108_7) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000108_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_9 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000108_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000108_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_14 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000108_10) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000108_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_5 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000108_18) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000108_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000108_8) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_7 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000108_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000108_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_15 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000108_16) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000108_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_9 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000108_9) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000108_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000108_0) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000108_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000108_11) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000108_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000108_17) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000108_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_141 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000108_20) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000108_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000108_14 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000108_14) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000108_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000108_2) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000108_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
