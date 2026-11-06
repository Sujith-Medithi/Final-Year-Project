/*
 * Benchmark Program: R000577
 * Security Family: nested_implicit_flow
 * Generator Seed: 557713
 * High Inputs: 18 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000577_7713_0 {
    int prev_out;
    short damping;
    unsigned char mode;
    int cutoff;
    short gain_db;
    int buffer[3];
};

struct StreamBuffer_R000577_7713_1 {
    unsigned char checksum;
    int watermark;
    unsigned char head;
    int state;
    int tail;
    int capacity;
    int buffer[3];
};

struct EventLog_R000577_7713_2 {
    short severity;
    unsigned char facility;
    unsigned char timestamp;
    int buffer[3];
};

union PacketPayload_R000577_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000577_7713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000577_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_20 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_20 > 43) {
        acc = (acc + offset_20 * 2 + 5) & 127;
        aux ^= (offset_20 & 15);
    } else {
        acc = (acc - offset_20 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_32 = local_arr[aux % 3];
    acc = (acc + margin_32 * 2) & 127;
    int cursor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_43) & 63;
    acc ^= aux;
    int index_reg_37 = (aux + st.buffer[1]) & 3;
    switch (index_reg_37) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_40) & 63;
    acc ^= aux;
    int bound_95 = (aux + st.buffer[1]) & 3;
    switch (bound_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_76 = local_arr[aux % 3];
    acc = (acc + segment_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_2(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_64 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_64 > 32) {
        acc = (acc + phase_64 * 2 + 5) & 127;
        aux ^= (phase_64 & 15);
    } else {
        acc = (acc - phase_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_69 = local_arr[aux % 3];
    acc = (acc + quotient_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_65 = (aux + st.buffer[1]) & 3;
    switch (factor_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_95 = local_arr[aux % 3];
    acc = (acc + vector_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_24 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_24 > 34) {
        acc = (acc + residue_24 * 2 + 5) & 127;
        aux ^= (residue_24 & 15);
    } else {
        acc = (acc - residue_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000577_7713_5(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int window_81 = (aux + st.buffer[1]) & 3;
    switch (window_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_46 = local_arr[aux % 3];
    acc = (acc + index_reg_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_6(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int window_26 = (aux + st.buffer[1]) & 3;
    switch (window_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_18 = local_arr[aux % 3];
    acc = (acc + accumulator_18 * 2) & 127;
    int damping_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000577_7713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_93) & 63;
    acc ^= aux;
    int factor_92 = (aux + st.buffer[1]) & 3;
    switch (factor_92) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_47 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_47 > 46) {
        acc = (acc + delta_47 * 2 + 5) & 127;
        aux ^= (delta_47 & 15);
    } else {
        acc = (acc - delta_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_93) & 63;
    acc ^= aux;
    int damping_39 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_39 > 31) {
        acc = (acc + damping_39 * 2 + 5) & 127;
        aux ^= (damping_39 & 15);
    } else {
        acc = (acc - damping_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000577_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_32 = (aux + st.buffer[1]) & 3;
    switch (bound_32) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_93 = local_arr[aux % 3];
    acc = (acc + phase_93 * 2) & 127;
    int delta_54 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_54 > 39) {
        acc = (acc + delta_54 * 2 + 5) & 127;
        aux ^= (delta_54 & 15);
    } else {
        acc = (acc - delta_54 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_11(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_57 = local_arr[aux % 3];
    acc = (acc + threshold_57 * 2) & 127;
    int tracker_91 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_91 > 47) {
        acc = (acc + tracker_91 * 2 + 5) & 127;
        aux ^= (tracker_91 & 15);
    } else {
        acc = (acc - tracker_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_90 = (aux + st.buffer[1]) & 3;
    switch (window_90) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int index_reg_81 = local_arr[aux % 3];
    acc = (acc + index_reg_81 * 2) & 127;
    int residue_50 = (aux + st.buffer[1]) & 3;
    switch (residue_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_74) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_84 = (aux + st.buffer[1]) & 3;
    switch (margin_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_88 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_88 > 18) {
        acc = (acc + margin_88 * 2 + 5) & 127;
        aux ^= (margin_88 & 15);
    } else {
        acc = (acc - margin_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000577_7713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int accumulator_45 = local_arr[aux % 3];
    acc = (acc + accumulator_45 * 2) & 127;
    int quantum_56 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_56 > 41) {
        acc = (acc + quantum_56 * 2 + 5) & 127;
        aux ^= (quantum_56 & 15);
    } else {
        acc = (acc - quantum_56 + 11) & 127;
        aux += 3;
    }
    int anchor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000577_7713_16(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_44 = local_arr[aux % 3];
    acc = (acc + margin_44 * 2) & 127;
    int quantum_75 = (aux + st.buffer[1]) & 3;
    switch (quantum_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_49 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_49 > 30) {
        acc = (acc + phase_49 * 2 + 5) & 127;
        aux ^= (phase_49 & 15);
    } else {
        acc = (acc - phase_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000577_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int factor_26 = local_arr[aux % 3];
    acc = (acc + factor_26 * 2) & 127;
    int weight_56 = (aux + st.buffer[1]) & 3;
    switch (weight_56) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_18(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000577_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_82 = (aux + st.buffer[1]) & 3;
    switch (tracker_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_71) & 63;
    acc ^= aux;
    int segment_40 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_40 > 15) {
        acc = (acc + segment_40 * 2 + 5) & 127;
        aux ^= (segment_40 & 15);
    } else {
        acc = (acc - segment_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_19(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000577_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_86 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_86 > 30) {
        acc = (acc + coefficient_86 * 2 + 5) & 127;
        aux ^= (coefficient_86 & 15);
    } else {
        acc = (acc - coefficient_86 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = (aux + st.buffer[1]) & 3;
    switch (pivot_12) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000577_7713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000577_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_10 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_10 > 38) {
        acc = (acc + vector_10 * 2 + 5) & 127;
        aux ^= (vector_10 & 15);
    } else {
        acc = (acc - vector_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_84 = local_arr[aux % 3];
    acc = (acc + factor_84 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000577_0;
    int sec_r000577_1;
    int sec_r000577_2;
    int sec_r000577_3;
    int sec_r000577_4;
    int sec_r000577_5;
    int sec_r000577_6;
    int sec_r000577_7;
    int sec_r000577_8;
    int sec_r000577_9;
    int sec_r000577_10;
    int sec_r000577_11;
    int sec_r000577_12;
    int sec_r000577_13;
    int sec_r000577_14;
    int sec_r000577_15;
    int sec_r000577_16;
    int sec_r000577_17;
    int pub_r000577_0;
    int pub_r000577_1;
    int pub_r000577_2;
    int pub_r000577_3;
    int pub_r000577_4;
    int pub_r000577_5;
    int pub_r000577_6;
    int pub_r000577_7;
    int pub_r000577_8;
    int pub_r000577_9;
    int pub_r000577_10;
    int pub_r000577_11;
    int pub_r000577_12;
    int pub_r000577_13;
    int pub_r000577_14;
    int pub_r000577_15;
    int pub_r000577_16;
    int pub_r000577_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000577_0 >= -100 && pub_r000577_0 <= 100);
    __CPROVER_assume(pub_r000577_1 >= -100 && pub_r000577_1 <= 100);
    __CPROVER_assume(pub_r000577_2 >= -100 && pub_r000577_2 <= 100);
    __CPROVER_assume(pub_r000577_3 >= -100 && pub_r000577_3 <= 100);
    __CPROVER_assume(pub_r000577_4 >= -100 && pub_r000577_4 <= 100);
    __CPROVER_assume(pub_r000577_5 >= -100 && pub_r000577_5 <= 100);
    __CPROVER_assume(pub_r000577_6 >= -100 && pub_r000577_6 <= 100);
    __CPROVER_assume(pub_r000577_7 >= -100 && pub_r000577_7 <= 100);
    __CPROVER_assume(pub_r000577_8 >= -100 && pub_r000577_8 <= 100);
    __CPROVER_assume(pub_r000577_9 >= -100 && pub_r000577_9 <= 100);
    __CPROVER_assume(pub_r000577_10 >= -100 && pub_r000577_10 <= 100);
    __CPROVER_assume(pub_r000577_11 >= -100 && pub_r000577_11 <= 100);
    __CPROVER_assume(pub_r000577_12 >= -100 && pub_r000577_12 <= 100);
    __CPROVER_assume(pub_r000577_13 >= -100 && pub_r000577_13 <= 100);
    __CPROVER_assume(pub_r000577_14 >= -100 && pub_r000577_14 <= 100);
    __CPROVER_assume(pub_r000577_15 >= -100 && pub_r000577_15 <= 100);
    __CPROVER_assume(pub_r000577_16 >= -100 && pub_r000577_16 <= 100);
    __CPROVER_assume(pub_r000577_17 >= -100 && pub_r000577_17 <= 100);
    __CPROVER_assume(sec_r000577_0 >= 0 && sec_r000577_0 <= 255);
    __CPROVER_assume(sec_r000577_1 >= 0 && sec_r000577_1 <= 255);
    __CPROVER_assume(sec_r000577_2 >= 0 && sec_r000577_2 <= 255);
    __CPROVER_assume(sec_r000577_3 >= 0 && sec_r000577_3 <= 255);
    __CPROVER_assume(sec_r000577_4 >= 0 && sec_r000577_4 <= 255);
    __CPROVER_assume(sec_r000577_5 >= 0 && sec_r000577_5 <= 255);
    __CPROVER_assume(sec_r000577_6 >= 0 && sec_r000577_6 <= 255);
    __CPROVER_assume(sec_r000577_7 >= 0 && sec_r000577_7 <= 255);
    __CPROVER_assume(sec_r000577_8 >= 0 && sec_r000577_8 <= 255);
    __CPROVER_assume(sec_r000577_9 >= 0 && sec_r000577_9 <= 255);
    __CPROVER_assume(sec_r000577_10 >= 0 && sec_r000577_10 <= 255);
    __CPROVER_assume(sec_r000577_11 >= 0 && sec_r000577_11 <= 255);
    __CPROVER_assume(sec_r000577_12 >= 0 && sec_r000577_12 <= 255);
    __CPROVER_assume(sec_r000577_13 >= 0 && sec_r000577_13 <= 255);
    __CPROVER_assume(sec_r000577_14 >= 0 && sec_r000577_14 <= 255);
    __CPROVER_assume(sec_r000577_15 >= 0 && sec_r000577_15 <= 255);
    __CPROVER_assume(sec_r000577_16 >= 0 && sec_r000577_16 <= 255);
    __CPROVER_assume(sec_r000577_17 >= 0 && sec_r000577_17 <= 255);

    struct FilterState_R000577_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000577_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000577_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000577_0 + 7) & 15;
    struct StreamBuffer_R000577_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000577_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000577_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000577_0 + 9) & 15;
    struct EventLog_R000577_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000577_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000577_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000577_0 + 11) & 15;

    union PacketPayload_R000577_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 28) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 43) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 13) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 28) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 12) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 27) {
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
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 20) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 35) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 11) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 26) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 14) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 29) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_59 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_60 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_61 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000577_4 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_62 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_63 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_64 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_65 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_66 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_67 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000577_17 & 2) != 0) {
            stage_v_68 = (pub_r000577_2 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000577_2 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000577_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000577_3 & 2) != 0) {
            stage_v_69 = (pub_r000577_2 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000577_2 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000577_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_70 = (pub_r000577_9 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000577_9 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000577_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000577_4 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_71 = (pub_r000577_9 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000577_9 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000577_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_72 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000577_9 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_73 = (pub_r000577_2 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000577_2 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000577_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000577_6 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_74 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000577_0 & 2) != 0) {
            stage_v_75 = (pub_r000577_8 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000577_8 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000577_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_76 = (pub_r000577_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000577_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000577_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_77 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000577_9 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_78 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_79 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_80 = (pub_r000577_4 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000577_4 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000577_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000577_11 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_81 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000577_3 & 1) != 0) {
        if ((sec_r000577_5 & 2) != 0) {
            stage_v_82 = (pub_r000577_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000577_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000577_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000577_15 & 1) != 0) {
        if ((sec_r000577_10 & 2) != 0) {
            stage_v_83 = (pub_r000577_8 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000577_8 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000577_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000577_3 & 2) != 0) {
            stage_v_84 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_85 = (pub_r000577_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000577_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000577_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000577_17 & 2) != 0) {
            stage_v_86 = (pub_r000577_16 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000577_16 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000577_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000577_3 & 2) != 0) {
            stage_v_87 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_88 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_17 & 2) != 0) {
            stage_v_89 = (pub_r000577_0 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000577_0 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000577_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000577_7 & 1) != 0) {
        if ((sec_r000577_4 & 2) != 0) {
            stage_v_90 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_91 = (pub_r000577_14 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000577_14 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000577_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_92 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_93 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_94 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000577_13 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_95 = (pub_r000577_8 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000577_8 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000577_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_96 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_97 = (pub_r000577_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000577_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000577_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_98 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_99 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000577_15 & 1) != 0) {
        if ((sec_r000577_5 & 2) != 0) {
            stage_v_100 = (pub_r000577_5 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000577_5 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000577_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000577_9 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_101 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_102 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_103 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_104 = (pub_r000577_5 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000577_5 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000577_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_105 = (pub_r000577_10 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000577_10 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000577_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_106 = (pub_r000577_12 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000577_12 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000577_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_107 = (pub_r000577_16 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000577_16 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000577_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000577_0 & 1) != 0) {
        if ((sec_r000577_11 & 2) != 0) {
            stage_v_108 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000577_7 & 1) != 0) {
        if ((sec_r000577_11 & 2) != 0) {
            stage_v_109 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_110 = (pub_r000577_4 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000577_4 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000577_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000577_2 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_111 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_112 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000577_0 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_113 = (pub_r000577_4 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000577_4 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000577_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_114 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000577_16 & 2) != 0) {
            stage_v_115 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_116 = (pub_r000577_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000577_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000577_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000577_16 & 2) != 0) {
            stage_v_117 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_5 & 2) != 0) {
            stage_v_118 = (pub_r000577_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000577_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000577_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000577_1 & 1) != 0) {
        if ((sec_r000577_13 & 2) != 0) {
            stage_v_119 = (pub_r000577_2 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000577_2 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000577_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000577_9 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_120 = (pub_r000577_15 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000577_15 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000577_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000577_2 & 1) != 0) {
        if ((sec_r000577_2 & 2) != 0) {
            stage_v_121 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_122 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000577_10 & 2) != 0) {
            stage_v_123 = (pub_r000577_9 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000577_9 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000577_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000577_17 & 2) != 0) {
            stage_v_124 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000577_12 & 1) != 0) {
        if ((sec_r000577_14 & 2) != 0) {
            stage_v_125 = (pub_r000577_12 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000577_12 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000577_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000577_12 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_126 = (pub_r000577_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000577_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000577_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000577_4 & 2) != 0) {
            stage_v_127 = (pub_r000577_9 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000577_9 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000577_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_128 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_129 = (pub_r000577_0 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000577_0 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000577_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_130 = (pub_r000577_12 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000577_12 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000577_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_8 & 2) != 0) {
            stage_v_131 = (pub_r000577_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000577_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000577_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000577_8 & 1) != 0) {
        if ((sec_r000577_17 & 2) != 0) {
            stage_v_132 = (pub_r000577_14 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000577_14 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000577_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_133 = (pub_r000577_4 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000577_4 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000577_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000577_0 & 2) != 0) {
            stage_v_134 = (pub_r000577_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000577_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000577_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_0 & 2) != 0) {
            stage_v_135 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000577_12 & 2) != 0) {
            stage_v_136 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000577_5 & 2) != 0) {
            stage_v_137 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000577_9 & 2) != 0) {
            stage_v_138 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_139 = (pub_r000577_13 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000577_13 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000577_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000577_14 & 1) != 0) {
        if ((sec_r000577_6 & 2) != 0) {
            stage_v_140 = (pub_r000577_17 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000577_17 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000577_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000577_5 & 1) != 0) {
        if ((sec_r000577_10 & 2) != 0) {
            stage_v_141 = (pub_r000577_12 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000577_12 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000577_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000577_1 & 2) != 0) {
            stage_v_142 = (pub_r000577_11 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000577_11 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000577_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000577_0 & 1) != 0) {
        if ((sec_r000577_4 & 2) != 0) {
            stage_v_143 = (pub_r000577_1 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000577_1 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000577_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000577_3 & 1) != 0) {
        if ((sec_r000577_7 & 2) != 0) {
            stage_v_144 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000577_11 & 2) != 0) {
            stage_v_145 = (pub_r000577_4 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000577_4 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000577_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000577_8 & 2) != 0) {
            stage_v_146 = (pub_r000577_6 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000577_6 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000577_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000577_1 & 1) != 0) {
        if ((sec_r000577_15 & 2) != 0) {
            stage_v_147 = (pub_r000577_12 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000577_12 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000577_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
