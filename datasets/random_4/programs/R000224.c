/*
 * Benchmark Program: R000224
 * Family: multi_step_explicit
 * Generator Seed: 422413
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000224_2413_0 {
    unsigned char channels;
    unsigned char gain;
    int envelope;
    int peak;
    int buffer[3];
};

struct FilterState_R000224_2413_1 {
    short cutoff;
    int mode;
    int gain_db;
    int prev_in;
    int buffer[3];
};

struct StreamBuffer_R000224_2413_2 {
    unsigned char capacity;
    int state;
    int checksum;
    int buffer[3];
};

struct EventLog_R000224_2413_3 {
    short severity;
    int timestamp;
    int seq;
    short code;
    int buffer[3];
};

union TelemetryField_R000224_2413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000224_2413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000224_2413_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_93 = local_arr[aux % 3];
    acc = (acc + offset_93 * 2) & 127;
    int residue_82 = (aux + st.buffer[1]) & 3;
    switch (residue_82) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_49 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_49 > 49) {
        acc = (acc + checksum_49 * 2 + 5) & 127;
        aux ^= (checksum_49 & 15);
    } else {
        acc = (acc - checksum_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_1(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000224_2413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int index_reg_37 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_37 = (index_reg_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_37) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_53 = (aux + st.buffer[1]) & 3;
    switch (offset_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_93 = local_arr[aux % 3];
    acc = (acc + parity_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000224_2413_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000224_2413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_54 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_54 > 26) {
        acc = (acc + metric_54 * 2 + 5) & 127;
        aux ^= (metric_54 & 15);
    } else {
        acc = (acc - metric_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_91 = local_arr[aux % 3];
    acc = (acc + accumulator_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_67 = 0;
    for (int k = 0; k < 2; k++) {
        residue_67 = (residue_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_3(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000224_2413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_33 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_33 > 46) {
        acc = (acc + residue_33 * 2 + 5) & 127;
        aux ^= (residue_33 & 15);
    } else {
        acc = (acc - residue_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_64 = local_arr[aux % 3];
    acc = (acc + sample_64 * 2) & 127;
    int vector_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000224_2413_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int checksum_45 = local_arr[aux % 3];
    acc = (acc + checksum_45 * 2) & 127;
    int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_57) & 63;
    acc ^= aux;
    int offset_53 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_53 > 24) {
        acc = (acc + offset_53 * 2 + 5) & 127;
        aux ^= (offset_53 & 15);
    } else {
        acc = (acc - offset_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_98 = local_arr[aux % 3];
    acc = (acc + coefficient_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000224_2413_6(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_90) & 63;
    acc ^= aux;
    int coefficient_65 = (aux + st.buffer[1]) & 3;
    switch (coefficient_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000224_2413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_81 = (aux + st.buffer[1]) & 3;
    switch (margin_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_22 = local_arr[aux % 3];
    acc = (acc + accumulator_22 * 2) & 127;
    int tally_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_98) & 63;
    acc ^= aux;
    int quotient_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_55 > 47) {
        acc = (acc + quotient_55 * 2 + 5) & 127;
        aux ^= (quotient_55 & 15);
    } else {
        acc = (acc - quotient_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_8(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_46 = (aux + st.buffer[1]) & 3;
    switch (delta_46) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_95 = local_arr[aux % 3];
    acc = (acc + factor_95 * 2) & 127;
    int index_reg_86 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_86 > 29) {
        acc = (acc + index_reg_86 * 2 + 5) & 127;
        aux ^= (index_reg_86 & 15);
    } else {
        acc = (acc - index_reg_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_9(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int margin_32 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_32 > 24) {
        acc = (acc + margin_32 * 2 + 5) & 127;
        aux ^= (margin_32 & 15);
    } else {
        acc = (acc - margin_32 + 11) & 127;
        aux += 3;
    }
    int cursor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_20) & 63;
    acc ^= aux;
    int phase_88 = (aux + st.buffer[1]) & 3;
    switch (phase_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000224_2413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int window_53 = (st.buffer[0] * 3 + aux) & 63;
    if (window_53 > 12) {
        acc = (acc + window_53 * 2 + 5) & 127;
        aux ^= (window_53 & 15);
    } else {
        acc = (acc - window_53 + 11) & 127;
        aux += 3;
    }
    int residue_98 = (aux + st.buffer[1]) & 3;
    switch (residue_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_11(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_53 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_53 > 19) {
        acc = (acc + checksum_53 * 2 + 5) & 127;
        aux ^= (checksum_53 & 15);
    } else {
        acc = (acc - checksum_53 + 11) & 127;
        aux += 3;
    }
    int index_reg_82 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_82 = (index_reg_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_82) & 127;
    }
    int weight_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_50 = local_arr[aux % 3];
    acc = (acc + window_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000224_2413_12(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_15 = (aux + st.buffer[1]) & 3;
    switch (index_reg_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_13(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000224_2413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_51 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_51 > 21) {
        acc = (acc + metric_51 * 2 + 5) & 127;
        aux ^= (metric_51 & 15);
    } else {
        acc = (acc - metric_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_14(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000224_2413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_44 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_44 > 10) {
        acc = (acc + phase_44 * 2 + 5) & 127;
        aux ^= (phase_44 & 15);
    } else {
        acc = (acc - phase_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000224_2413_15(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000224_2413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_16 = (aux + st.buffer[1]) & 3;
    switch (metric_16) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_33) & 63;
    acc ^= aux;
    int pivot_66 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_66 = (pivot_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_16(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000224_2413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int offset_51 = local_arr[aux % 3];
    acc = (acc + offset_51 * 2) & 127;
    int parity_96 = (aux + st.buffer[1]) & 3;
    switch (parity_96) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000224_2413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_40 = 0;
    for (int k = 0; k < 3; k++) {
        sample_40 = (sample_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_40) & 127;
    }
    int delta_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_76) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_52 = local_arr[aux % 3];
    acc = (acc + margin_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000224_2413_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int bound_82 = 0;
    for (int k = 0; k < 3; k++) {
        bound_82 = (bound_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_82) & 127;
    }
    int offset_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000224_2413_19(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_75 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_75 > 12) {
        acc = (acc + bound_75 * 2 + 5) & 127;
        aux ^= (bound_75 & 15);
    } else {
        acc = (acc - bound_75 + 11) & 127;
        aux += 3;
    }
    int weight_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000224_2413_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_19) & 63;
    acc ^= aux;
    int damping_37 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_37 > 22) {
        acc = (acc + damping_37 * 2 + 5) & 127;
        aux ^= (damping_37 & 15);
    } else {
        acc = (acc - damping_37 + 11) & 127;
        aux += 3;
    }
    int damping_79 = (aux + st.buffer[1]) & 3;
    switch (damping_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_74 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_74 = (threshold_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_21(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int sample_69 = 0;
    for (int k = 0; k < 3; k++) {
        sample_69 = (sample_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_69) & 127;
    }
    int mask_67 = (aux + st.buffer[1]) & 3;
    switch (mask_67) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000224_2413_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000224_2413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_10 = local_arr[aux % 3];
    acc = (acc + segment_10 * 2) & 127;
    int residue_42 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_42 > 10) {
        acc = (acc + residue_42 * 2 + 5) & 127;
        aux ^= (residue_42 & 15);
    } else {
        acc = (acc - residue_42 + 11) & 127;
        aux += 3;
    }
    int threshold_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000224_2413_23(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int mask_18 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_18 > 18) {
        acc = (acc + mask_18 * 2 + 5) & 127;
        aux ^= (mask_18 & 15);
    } else {
        acc = (acc - mask_18 + 11) & 127;
        aux += 3;
    }
    int offset_66 = 0;
    for (int k = 0; k < 2; k++) {
        offset_66 = (offset_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_66) & 127;
    }
    int metric_25 = (aux + st.buffer[1]) & 3;
    switch (metric_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000224_2413_24(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000224_2413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_38) & 63;
    acc ^= aux;
    int offset_58 = (aux + st.buffer[1]) & 3;
    switch (offset_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_99 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_99 > 44) {
        acc = (acc + tally_99 * 2 + 5) & 127;
        aux ^= (tally_99 & 15);
    } else {
        acc = (acc - tally_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000224_0;
    int sec_r000224_1;
    int sec_r000224_2;
    int sec_r000224_3;
    int sec_r000224_4;
    int sec_r000224_5;
    int sec_r000224_6;
    int sec_r000224_7;
    int sec_r000224_8;
    int sec_r000224_9;
    int sec_r000224_10;
    int sec_r000224_11;
    int sec_r000224_12;
    int sec_r000224_13;
    int sec_r000224_14;
    int sec_r000224_15;
    int sec_r000224_16;
    int pub_r000224_0;
    int pub_r000224_1;
    int pub_r000224_2;
    int pub_r000224_3;
    int pub_r000224_4;
    int pub_r000224_5;
    int pub_r000224_6;
    int pub_r000224_7;
    int pub_r000224_8;
    int pub_r000224_9;
    int pub_r000224_10;
    int pub_r000224_11;
    int pub_r000224_12;
    int pub_r000224_13;
    int pub_r000224_14;
    int pub_r000224_15;
    int pub_r000224_16;
    int pub_r000224_17;
    int pub_r000224_18;
    int pub_r000224_19;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000224_0 >= -100 && pub_r000224_0 <= 100);
    __CPROVER_assume(pub_r000224_1 >= -100 && pub_r000224_1 <= 100);
    __CPROVER_assume(pub_r000224_2 >= -100 && pub_r000224_2 <= 100);
    __CPROVER_assume(pub_r000224_3 >= -100 && pub_r000224_3 <= 100);
    __CPROVER_assume(pub_r000224_4 >= -100 && pub_r000224_4 <= 100);
    __CPROVER_assume(pub_r000224_5 >= -100 && pub_r000224_5 <= 100);
    __CPROVER_assume(pub_r000224_6 >= -100 && pub_r000224_6 <= 100);
    __CPROVER_assume(pub_r000224_7 >= -100 && pub_r000224_7 <= 100);
    __CPROVER_assume(pub_r000224_8 >= -100 && pub_r000224_8 <= 100);
    __CPROVER_assume(pub_r000224_9 >= -100 && pub_r000224_9 <= 100);
    __CPROVER_assume(pub_r000224_10 >= -100 && pub_r000224_10 <= 100);
    __CPROVER_assume(pub_r000224_11 >= -100 && pub_r000224_11 <= 100);
    __CPROVER_assume(pub_r000224_12 >= -100 && pub_r000224_12 <= 100);
    __CPROVER_assume(pub_r000224_13 >= -100 && pub_r000224_13 <= 100);
    __CPROVER_assume(pub_r000224_14 >= -100 && pub_r000224_14 <= 100);
    __CPROVER_assume(pub_r000224_15 >= -100 && pub_r000224_15 <= 100);
    __CPROVER_assume(pub_r000224_16 >= -100 && pub_r000224_16 <= 100);
    __CPROVER_assume(pub_r000224_17 >= -100 && pub_r000224_17 <= 100);
    __CPROVER_assume(pub_r000224_18 >= -100 && pub_r000224_18 <= 100);
    __CPROVER_assume(pub_r000224_19 >= -100 && pub_r000224_19 <= 100);
    __CPROVER_assume(sec_r000224_0 >= 0 && sec_r000224_0 <= 255);
    __CPROVER_assume(sec_r000224_1 >= 0 && sec_r000224_1 <= 255);
    __CPROVER_assume(sec_r000224_2 >= 0 && sec_r000224_2 <= 255);
    __CPROVER_assume(sec_r000224_3 >= 0 && sec_r000224_3 <= 255);
    __CPROVER_assume(sec_r000224_4 >= 0 && sec_r000224_4 <= 255);
    __CPROVER_assume(sec_r000224_5 >= 0 && sec_r000224_5 <= 255);
    __CPROVER_assume(sec_r000224_6 >= 0 && sec_r000224_6 <= 255);
    __CPROVER_assume(sec_r000224_7 >= 0 && sec_r000224_7 <= 255);
    __CPROVER_assume(sec_r000224_8 >= 0 && sec_r000224_8 <= 255);
    __CPROVER_assume(sec_r000224_9 >= 0 && sec_r000224_9 <= 255);
    __CPROVER_assume(sec_r000224_10 >= 0 && sec_r000224_10 <= 255);
    __CPROVER_assume(sec_r000224_11 >= 0 && sec_r000224_11 <= 255);
    __CPROVER_assume(sec_r000224_12 >= 0 && sec_r000224_12 <= 255);
    __CPROVER_assume(sec_r000224_13 >= 0 && sec_r000224_13 <= 255);
    __CPROVER_assume(sec_r000224_14 >= 0 && sec_r000224_14 <= 255);
    __CPROVER_assume(sec_r000224_15 >= 0 && sec_r000224_15 <= 255);
    __CPROVER_assume(sec_r000224_16 >= 0 && sec_r000224_16 <= 255);

    struct AudioFrame_R000224_2413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000224_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000224_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000224_0 + 7) & 15;
    struct FilterState_R000224_2413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000224_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000224_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000224_0 + 9) & 15;
    struct StreamBuffer_R000224_2413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000224_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000224_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000224_0 + 11) & 15;
    struct EventLog_R000224_2413_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000224_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000224_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000224_0 + 13) & 15;

    union TelemetryField_R000224_2413_0 u_var;
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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 27) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 42) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 26) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 41) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 11) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 26) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 18) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 33) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 25) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 40) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 29) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 44) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 26) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 41) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_37 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 35) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 50) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 37) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 52) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 34) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 49) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 36) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 51) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 38) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 53) {
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
    if (stage_v_60 > 31) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 46) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 33) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 48) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 82) & 15;
    int stage_v_81 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= stage_v_81;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_2.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 27) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 42) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 13) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 28) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_3.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (out_sink > 100) ? (chk_sum & 31) : (114 & 31);
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= (stage_v_109 << 1) & 127;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = table[3];
    table[3] = (table[0] + 223) & 63;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] ^ 117) & 3;
    switch (stage_v_114) {
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

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_119 = (stage_v_119 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (out_sink > 100) ? (chk_sum & 31) : (128 & 31);
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= (stage_v_123 << 1) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_3.buffer[1] * 3) & 63;
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
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[0] ^ 136) & 3;
    switch (stage_v_133) {
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

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[0] ^ 137) & 3;
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
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_135 = (stage_v_135 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_2.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 157) & 15;
    int stage_v_156 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= stage_v_156;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_3.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 23) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 38) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 14) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 29) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_2.buffer[1] * 2 + 505) & 63;
    if (stage_v_166 > 17) {
        out_sink = (out_sink + stage_v_166 - 5) & 255;
        if (stage_v_166 > 32) {
            chk_sum ^= (stage_v_166 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_166 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = multi_step_explicit */
    int m_step_0 = (sec_r000224_4 + pub_r000224_6 + 9) & 127;
    int m_step_1 = (m_step_0 + pub_r000224_1 + 6) & 127;
    int m_step_2 = (m_step_1 + pub_r000224_6 + 24) & 127;
    out_sink = (out_sink + m_step_2) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
