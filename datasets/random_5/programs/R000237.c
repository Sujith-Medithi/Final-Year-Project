/*
 * Benchmark Program: R000237
 * Security Family: nested_implicit_flow
 * Generator Seed: 523713
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000237_3713_0 {
    int channels;
    short gain;
    short peak;
    int rms;
    short envelope;
    int sample_rate;
    int buffer[3];
};

struct FilterState_R000237_3713_1 {
    int prev_in;
    int damping;
    unsigned char prev_out;
    short cutoff;
    int gain_db;
    int buffer[3];
};

struct CipherContext_R000237_3713_2 {
    int round_key;
    int flags;
    int tag;
    int buffer[3];
};

union PacketPayload_R000237_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000237_3713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_11 = (aux + st.buffer[1]) & 3;
    switch (vector_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_89 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_89 > 40) {
        acc = (acc + damping_89 * 2 + 5) & 127;
        aux ^= (damping_89 & 15);
    } else {
        acc = (acc - damping_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tracker_30 = local_arr[aux % 3];
    acc = (acc + tracker_30 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_92 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_92 > 50) {
        acc = (acc + cursor_92 * 2 + 5) & 127;
        aux ^= (cursor_92 & 15);
    } else {
        acc = (acc - cursor_92 + 11) & 127;
        aux += 3;
    }
    int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000237_3713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int margin_86 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_86 > 42) {
        acc = (acc + margin_86 * 2 + 5) & 127;
        aux ^= (margin_86 & 15);
    } else {
        acc = (acc - margin_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000237_3713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000237_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_39 = (aux + st.buffer[1]) & 3;
    switch (offset_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000237_3713_4(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_35 = (aux + st.buffer[1]) & 3;
    switch (threshold_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_90 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_90 > 25) {
        acc = (acc + sample_90 * 2 + 5) & 127;
        aux ^= (sample_90 & 15);
    } else {
        acc = (acc - sample_90 + 11) & 127;
        aux += 3;
    }
    int vector_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000237_3713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000237_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int damping_92 = local_arr[aux % 3];
    acc = (acc + damping_92 * 2) & 127;
    int tracker_97 = (aux + st.buffer[1]) & 3;
    switch (tracker_97) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_70 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_70 > 50) {
        acc = (acc + accumulator_70 * 2 + 5) & 127;
        aux ^= (accumulator_70 & 15);
    } else {
        acc = (acc - accumulator_70 + 11) & 127;
        aux += 3;
    }
    int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000237_3713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000237_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int parity_15 = local_arr[aux % 3];
    acc = (acc + parity_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_78 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_78 > 34) {
        acc = (acc + checksum_78 * 2 + 5) & 127;
        aux ^= (checksum_78 & 15);
    } else {
        acc = (acc - checksum_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000237_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int margin_82 = local_arr[aux % 3];
    acc = (acc + margin_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 46) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_8(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_76) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_98 = local_arr[aux % 3];
    acc = (acc + index_reg_98 * 2) & 127;
    int cursor_74 = (aux + st.buffer[1]) & 3;
    switch (cursor_74) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int delta_50 = local_arr[aux % 3];
    acc = (acc + delta_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_47) & 63;
    acc ^= aux;
    int segment_96 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_96 > 41) {
        acc = (acc + segment_96 * 2 + 5) & 127;
        aux ^= (segment_96 & 15);
    } else {
        acc = (acc - segment_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_10(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int pivot_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_46) & 63;
    acc ^= aux;
    int vector_97 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_97 > 13) {
        acc = (acc + vector_97 * 2 + 5) & 127;
        aux ^= (vector_97 & 15);
    } else {
        acc = (acc - vector_97 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_88 = local_arr[aux % 3];
    acc = (acc + vector_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000237_3713_11(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_62) & 63;
    acc ^= aux;
    int quantum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_79 > 21) {
        acc = (acc + quantum_79 * 2 + 5) & 127;
        aux ^= (quantum_79 & 15);
    } else {
        acc = (acc - quantum_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_23 = (aux + st.buffer[1]) & 3;
    switch (offset_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_13(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_90 = (aux + st.buffer[1]) & 3;
    switch (window_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_50 = local_arr[aux % 3];
    acc = (acc + index_reg_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000237_3713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000237_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_99 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_99 > 45) {
        acc = (acc + weight_99 * 2 + 5) & 127;
        aux ^= (weight_99 & 15);
    } else {
        acc = (acc - weight_99 + 11) & 127;
        aux += 3;
    }
    int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_52) & 63;
    acc ^= aux;
    int delta_96 = (aux + st.buffer[1]) & 3;
    switch (delta_96) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_15(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_79) & 63;
    acc ^= aux;
    int factor_50 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_50 > 49) {
        acc = (acc + factor_50 * 2 + 5) & 127;
        aux ^= (factor_50 & 15);
    } else {
        acc = (acc - factor_50 + 11) & 127;
        aux += 3;
    }
    int quotient_87 = (aux + st.buffer[1]) & 3;
    switch (quotient_87) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_25 = (aux + st.buffer[1]) & 3;
    switch (segment_25) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_17(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000237_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quantum_27 = (aux + st.buffer[1]) & 3;
    switch (quantum_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_88) & 63;
    acc ^= aux;
    int checksum_88 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_88 > 14) {
        acc = (acc + checksum_88 * 2 + 5) & 127;
        aux ^= (checksum_88 & 15);
    } else {
        acc = (acc - checksum_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000237_3713_18(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_84) & 63;
    acc ^= aux;
    int checksum_94 = (aux + st.buffer[1]) & 3;
    switch (checksum_94) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_82 = local_arr[aux % 3];
    acc = (acc + index_reg_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000237_3713_19(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000237_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_21 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_21 > 34) {
        acc = (acc + metric_21 * 2 + 5) & 127;
        aux ^= (metric_21 & 15);
    } else {
        acc = (acc - metric_21 + 11) & 127;
        aux += 3;
    }
    int sample_62 = (aux + st.buffer[1]) & 3;
    switch (sample_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_65 = local_arr[aux % 3];
    acc = (acc + coefficient_65 * 2) & 127;
    int cursor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000237_0;
    int sec_r000237_1;
    int sec_r000237_2;
    int sec_r000237_3;
    int sec_r000237_4;
    int sec_r000237_5;
    int sec_r000237_6;
    int sec_r000237_7;
    int sec_r000237_8;
    int sec_r000237_9;
    int sec_r000237_10;
    int sec_r000237_11;
    int sec_r000237_12;
    int sec_r000237_13;
    int sec_r000237_14;
    int sec_r000237_15;
    int sec_r000237_16;
    int sec_r000237_17;
    int sec_r000237_18;
    int sec_r000237_19;
    int sec_r000237_20;
    int sec_r000237_21;
    int sec_r000237_22;
    int sec_r000237_23;
    int pub_r000237_0;
    int pub_r000237_1;
    int pub_r000237_2;
    int pub_r000237_3;
    int pub_r000237_4;
    int pub_r000237_5;
    int pub_r000237_6;
    int pub_r000237_7;
    int pub_r000237_8;
    int pub_r000237_9;
    int pub_r000237_10;
    int pub_r000237_11;
    int pub_r000237_12;
    int pub_r000237_13;
    int pub_r000237_14;
    int pub_r000237_15;
    int pub_r000237_16;
    int pub_r000237_17;
    int pub_r000237_18;
    int pub_r000237_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000237_0 >= -100 && pub_r000237_0 <= 100);
    __CPROVER_assume(pub_r000237_1 >= -100 && pub_r000237_1 <= 100);
    __CPROVER_assume(pub_r000237_2 >= -100 && pub_r000237_2 <= 100);
    __CPROVER_assume(pub_r000237_3 >= -100 && pub_r000237_3 <= 100);
    __CPROVER_assume(pub_r000237_4 >= -100 && pub_r000237_4 <= 100);
    __CPROVER_assume(pub_r000237_5 >= -100 && pub_r000237_5 <= 100);
    __CPROVER_assume(pub_r000237_6 >= -100 && pub_r000237_6 <= 100);
    __CPROVER_assume(pub_r000237_7 >= -100 && pub_r000237_7 <= 100);
    __CPROVER_assume(pub_r000237_8 >= -100 && pub_r000237_8 <= 100);
    __CPROVER_assume(pub_r000237_9 >= -100 && pub_r000237_9 <= 100);
    __CPROVER_assume(pub_r000237_10 >= -100 && pub_r000237_10 <= 100);
    __CPROVER_assume(pub_r000237_11 >= -100 && pub_r000237_11 <= 100);
    __CPROVER_assume(pub_r000237_12 >= -100 && pub_r000237_12 <= 100);
    __CPROVER_assume(pub_r000237_13 >= -100 && pub_r000237_13 <= 100);
    __CPROVER_assume(pub_r000237_14 >= -100 && pub_r000237_14 <= 100);
    __CPROVER_assume(pub_r000237_15 >= -100 && pub_r000237_15 <= 100);
    __CPROVER_assume(pub_r000237_16 >= -100 && pub_r000237_16 <= 100);
    __CPROVER_assume(pub_r000237_17 >= -100 && pub_r000237_17 <= 100);
    __CPROVER_assume(pub_r000237_18 >= -100 && pub_r000237_18 <= 100);
    __CPROVER_assume(pub_r000237_19 >= -100 && pub_r000237_19 <= 100);
    __CPROVER_assume(sec_r000237_0 >= 0 && sec_r000237_0 <= 255);
    __CPROVER_assume(sec_r000237_1 >= 0 && sec_r000237_1 <= 255);
    __CPROVER_assume(sec_r000237_2 >= 0 && sec_r000237_2 <= 255);
    __CPROVER_assume(sec_r000237_3 >= 0 && sec_r000237_3 <= 255);
    __CPROVER_assume(sec_r000237_4 >= 0 && sec_r000237_4 <= 255);
    __CPROVER_assume(sec_r000237_5 >= 0 && sec_r000237_5 <= 255);
    __CPROVER_assume(sec_r000237_6 >= 0 && sec_r000237_6 <= 255);
    __CPROVER_assume(sec_r000237_7 >= 0 && sec_r000237_7 <= 255);
    __CPROVER_assume(sec_r000237_8 >= 0 && sec_r000237_8 <= 255);
    __CPROVER_assume(sec_r000237_9 >= 0 && sec_r000237_9 <= 255);
    __CPROVER_assume(sec_r000237_10 >= 0 && sec_r000237_10 <= 255);
    __CPROVER_assume(sec_r000237_11 >= 0 && sec_r000237_11 <= 255);
    __CPROVER_assume(sec_r000237_12 >= 0 && sec_r000237_12 <= 255);
    __CPROVER_assume(sec_r000237_13 >= 0 && sec_r000237_13 <= 255);
    __CPROVER_assume(sec_r000237_14 >= 0 && sec_r000237_14 <= 255);
    __CPROVER_assume(sec_r000237_15 >= 0 && sec_r000237_15 <= 255);
    __CPROVER_assume(sec_r000237_16 >= 0 && sec_r000237_16 <= 255);
    __CPROVER_assume(sec_r000237_17 >= 0 && sec_r000237_17 <= 255);
    __CPROVER_assume(sec_r000237_18 >= 0 && sec_r000237_18 <= 255);
    __CPROVER_assume(sec_r000237_19 >= 0 && sec_r000237_19 <= 255);
    __CPROVER_assume(sec_r000237_20 >= 0 && sec_r000237_20 <= 255);
    __CPROVER_assume(sec_r000237_21 >= 0 && sec_r000237_21 <= 255);
    __CPROVER_assume(sec_r000237_22 >= 0 && sec_r000237_22 <= 255);
    __CPROVER_assume(sec_r000237_23 >= 0 && sec_r000237_23 <= 255);

    struct AudioFrame_R000237_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000237_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000237_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000237_0 + 7) & 15;
    struct FilterState_R000237_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000237_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000237_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000237_0 + 9) & 15;
    struct CipherContext_R000237_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000237_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000237_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000237_0 + 11) & 15;

    union PacketPayload_R000237_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 50) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

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
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 20) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 35) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 18) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 33) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 30) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 45) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 18) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 33) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 10) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 25) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 16) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 31) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 14) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 29) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

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
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 15) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 30) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 15) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 30) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 14) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 29) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 32) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 47) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000237_6 & 1) != 0) {
        if ((sec_r000237_7 & 2) != 0) {
            stage_v_88 = (pub_r000237_9 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000237_9 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000237_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000237_6 & 2) != 0) {
            stage_v_89 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000237_10 & 2) != 0) {
            stage_v_90 = (pub_r000237_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000237_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000237_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000237_20 & 1) != 0) {
        if ((sec_r000237_6 & 2) != 0) {
            stage_v_91 = (pub_r000237_16 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000237_16 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000237_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_92 = (pub_r000237_18 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000237_18 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000237_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000237_1 & 2) != 0) {
            stage_v_93 = (pub_r000237_1 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000237_1 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000237_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_22 & 2) != 0) {
            stage_v_94 = (pub_r000237_17 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000237_17 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000237_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000237_13 & 1) != 0) {
        if ((sec_r000237_17 & 2) != 0) {
            stage_v_95 = (pub_r000237_16 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000237_16 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000237_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_96 = (pub_r000237_17 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000237_17 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000237_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000237_1 & 2) != 0) {
            stage_v_97 = (pub_r000237_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000237_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000237_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000237_3 & 2) != 0) {
            stage_v_98 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_99 = (pub_r000237_13 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000237_13 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000237_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_100 = (pub_r000237_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000237_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000237_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000237_15 & 1) != 0) {
        if ((sec_r000237_17 & 2) != 0) {
            stage_v_101 = (pub_r000237_4 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000237_4 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000237_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000237_9 & 2) != 0) {
            stage_v_102 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_103 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_104 = (pub_r000237_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000237_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000237_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000237_17 & 2) != 0) {
            stage_v_105 = (pub_r000237_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000237_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000237_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000237_15 & 1) != 0) {
        if ((sec_r000237_17 & 2) != 0) {
            stage_v_106 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_16 & 2) != 0) {
            stage_v_107 = (pub_r000237_12 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000237_12 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000237_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000237_21 & 1) != 0) {
        if ((sec_r000237_4 & 2) != 0) {
            stage_v_108 = (pub_r000237_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000237_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000237_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_0 & 2) != 0) {
            stage_v_109 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000237_18 & 2) != 0) {
            stage_v_110 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000237_22 & 2) != 0) {
            stage_v_111 = (pub_r000237_7 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000237_7 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000237_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000237_11 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_112 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000237_16 & 2) != 0) {
            stage_v_113 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000237_11 & 2) != 0) {
            stage_v_114 = (pub_r000237_1 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000237_1 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000237_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000237_13 & 1) != 0) {
        if ((sec_r000237_9 & 2) != 0) {
            stage_v_115 = (pub_r000237_19 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000237_19 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000237_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000237_8 & 2) != 0) {
            stage_v_116 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000237_16 & 2) != 0) {
            stage_v_117 = (pub_r000237_9 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000237_9 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000237_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000237_0 & 1) != 0) {
        if ((sec_r000237_9 & 2) != 0) {
            stage_v_118 = (pub_r000237_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000237_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000237_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000237_7 & 1) != 0) {
        if ((sec_r000237_4 & 2) != 0) {
            stage_v_119 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000237_5 & 2) != 0) {
            stage_v_120 = (pub_r000237_8 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000237_8 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000237_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000237_19 & 1) != 0) {
        if ((sec_r000237_2 & 2) != 0) {
            stage_v_121 = (pub_r000237_11 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000237_11 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000237_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000237_8 & 1) != 0) {
        if ((sec_r000237_0 & 2) != 0) {
            stage_v_122 = (pub_r000237_9 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000237_9 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000237_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000237_2 & 2) != 0) {
            stage_v_123 = (pub_r000237_13 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000237_13 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000237_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000237_0 & 2) != 0) {
            stage_v_124 = (pub_r000237_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000237_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000237_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_125 = (pub_r000237_16 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000237_16 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000237_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000237_3 & 2) != 0) {
            stage_v_126 = (pub_r000237_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000237_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000237_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000237_8 & 2) != 0) {
            stage_v_127 = (pub_r000237_12 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000237_12 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000237_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000237_12 & 2) != 0) {
            stage_v_128 = (pub_r000237_8 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000237_8 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000237_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000237_12 & 2) != 0) {
            stage_v_129 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000237_14 & 1) != 0) {
        if ((sec_r000237_4 & 2) != 0) {
            stage_v_130 = (pub_r000237_17 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000237_17 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000237_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000237_14 & 2) != 0) {
            stage_v_131 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000237_15 & 2) != 0) {
            stage_v_132 = (pub_r000237_9 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000237_9 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000237_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000237_17 & 2) != 0) {
            stage_v_133 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000237_5 & 1) != 0) {
        if ((sec_r000237_14 & 2) != 0) {
            stage_v_134 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000237_22 & 2) != 0) {
            stage_v_135 = (pub_r000237_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000237_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000237_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000237_6 & 1) != 0) {
        if ((sec_r000237_13 & 2) != 0) {
            stage_v_136 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000237_3 & 1) != 0) {
        if ((sec_r000237_11 & 2) != 0) {
            stage_v_137 = (pub_r000237_18 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000237_18 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000237_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000237_2 & 2) != 0) {
            stage_v_138 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000237_20 & 2) != 0) {
            stage_v_139 = (pub_r000237_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000237_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000237_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000237_9 & 2) != 0) {
            stage_v_140 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000237_11 & 2) != 0) {
            stage_v_141 = (pub_r000237_1 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000237_1 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000237_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000237_7 & 2) != 0) {
            stage_v_142 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000237_5 & 2) != 0) {
            stage_v_143 = (pub_r000237_0 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000237_0 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000237_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000237_9 & 1) != 0) {
        if ((sec_r000237_13 & 2) != 0) {
            stage_v_144 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000237_1 & 1) != 0) {
        if ((sec_r000237_15 & 2) != 0) {
            stage_v_145 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000237_10 & 2) != 0) {
            stage_v_146 = (pub_r000237_13 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000237_13 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000237_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000237_18 & 1) != 0) {
        if ((sec_r000237_13 & 2) != 0) {
            stage_v_147 = (pub_r000237_19 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000237_19 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000237_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000237_15 & 1) != 0) {
        if ((sec_r000237_12 & 2) != 0) {
            stage_v_148 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000237_16 & 2) != 0) {
            stage_v_149 = (pub_r000237_2 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000237_2 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000237_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000237_22 & 2) != 0) {
            stage_v_150 = (pub_r000237_11 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000237_11 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000237_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000237_10 & 2) != 0) {
            stage_v_151 = (pub_r000237_2 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000237_2 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000237_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000237_5 & 2) != 0) {
            stage_v_152 = (pub_r000237_3 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000237_3 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000237_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000237_6 & 2) != 0) {
            stage_v_153 = (pub_r000237_16 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000237_16 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000237_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000237_17 & 1) != 0) {
        if ((sec_r000237_16 & 2) != 0) {
            stage_v_154 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000237_3 & 2) != 0) {
            stage_v_155 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000237_1 & 2) != 0) {
            stage_v_156 = (pub_r000237_19 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000237_19 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000237_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000237_7 & 1) != 0) {
        if ((sec_r000237_18 & 2) != 0) {
            stage_v_157 = (pub_r000237_14 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000237_14 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000237_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_158 = (pub_r000237_4 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000237_4 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000237_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000237_15 & 1) != 0) {
        if ((sec_r000237_18 & 2) != 0) {
            stage_v_159 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000237_23 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_160 = (pub_r000237_19 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000237_19 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000237_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r000237_11 & 2) != 0) {
            stage_v_161 = (pub_r000237_0 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000237_0 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000237_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000237_8 & 2) != 0) {
            stage_v_162 = (pub_r000237_11 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000237_11 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000237_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_163 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000237_10 & 1) != 0) {
        if ((sec_r000237_21 & 2) != 0) {
            stage_v_164 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000237_12 & 2) != 0) {
            stage_v_165 = (pub_r000237_19 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000237_19 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000237_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((sec_r000237_16 & 1) != 0) {
        if ((sec_r000237_13 & 2) != 0) {
            stage_v_166 = (pub_r000237_15 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000237_15 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000237_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000237_2 & 2) != 0) {
            stage_v_167 = (pub_r000237_10 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000237_10 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000237_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((sec_r000237_19 & 1) != 0) {
        if ((sec_r000237_12 & 2) != 0) {
            stage_v_168 = (pub_r000237_9 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000237_9 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000237_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((sec_r000237_14 & 1) != 0) {
        if ((sec_r000237_19 & 2) != 0) {
            stage_v_169 = (pub_r000237_18 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000237_18 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000237_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r000237_2 & 2) != 0) {
            stage_v_170 = (pub_r000237_0 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000237_0 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000237_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000237_22 & 2) != 0) {
            stage_v_171 = (pub_r000237_11 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000237_11 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000237_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000237_14 & 2) != 0) {
            stage_v_172 = (pub_r000237_6 + 31) & 127;
        } else {
            stage_v_172 = (pub_r000237_6 + 13) & 127;
        }
    } else {
        stage_v_172 = (pub_r000237_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
