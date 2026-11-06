/*
 * Benchmark Program: R000027
 * Security Family: nested_implicit_flow
 * Generator Seed: 502713
 * High Inputs: 20 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000027_2713_0 {
    short timeout;
    unsigned char id;
    int parity;
    int buffer[3];
};

struct CipherContext_R000027_2713_1 {
    short round_key;
    int tag;
    unsigned char nonce;
    int buffer[3];
};

struct FilterState_R000027_2713_2 {
    int damping;
    int prev_in;
    int cutoff;
    unsigned char mode;
    int prev_out;
    int buffer[3];
};

struct EventLog_R000027_2713_3 {
    short facility;
    unsigned char timestamp;
    int signature;
    unsigned char code;
    int seq;
    int buffer[3];
};

union RegisterBank_R000027_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000027_2713_0(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000027_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int parity_47 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_47 > 23) {
        acc = (acc + parity_47 * 2 + 5) & 127;
        aux ^= (parity_47 & 15);
    } else {
        acc = (acc - parity_47 + 11) & 127;
        aux += 3;
    }
    int parity_73 = (aux + st.buffer[1]) & 3;
    switch (parity_73) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_1(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_96 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_96 > 28) {
        acc = (acc + factor_96 * 2 + 5) & 127;
        aux ^= (factor_96 & 15);
    } else {
        acc = (acc - factor_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_18 = local_arr[aux % 3];
    acc = (acc + quotient_18 * 2) & 127;
    int damping_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000027_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000027_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_42 = (aux + st.buffer[1]) & 3;
    switch (sample_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_78 = local_arr[aux % 3];
    acc = (acc + coefficient_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_65 = (aux + st.buffer[1]) & 3;
    switch (threshold_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_4(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_63) & 63;
    acc ^= aux;
    int threshold_75 = (aux + st.buffer[1]) & 3;
    switch (threshold_75) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_95 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_95 > 44) {
        acc = (acc + accumulator_95 * 2 + 5) & 127;
        aux ^= (accumulator_95 & 15);
    } else {
        acc = (acc - accumulator_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_92 = local_arr[aux % 3];
    acc = (acc + accumulator_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_6(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_36 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_36 > 14) {
        acc = (acc + pivot_36 * 2 + 5) & 127;
        aux ^= (pivot_36 & 15);
    } else {
        acc = (acc - pivot_36 + 11) & 127;
        aux += 3;
    }
    int tracker_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000027_2713_7(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int phase_75 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_75 > 10) {
        acc = (acc + phase_75 * 2 + 5) & 127;
        aux ^= (phase_75 & 15);
    } else {
        acc = (acc - phase_75 + 11) & 127;
        aux += 3;
    }
    int mask_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_72) & 63;
    acc ^= aux;
    int tally_75 = (aux + st.buffer[1]) & 3;
    switch (tally_75) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_8(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_46) & 63;
    acc ^= aux;
    int anchor_49 = (aux + st.buffer[1]) & 3;
    switch (anchor_49) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int bound_10 = local_arr[aux % 3];
    acc = (acc + bound_10 * 2) & 127;
    int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_81) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_87 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_87 > 20) {
        acc = (acc + tracker_87 * 2 + 5) & 127;
        aux ^= (tracker_87 & 15);
    } else {
        acc = (acc - tracker_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_99 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_99 > 21) {
        acc = (acc + damping_99 * 2 + 5) & 127;
        aux ^= (damping_99 & 15);
    } else {
        acc = (acc - damping_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_11(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000027_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_58 = (aux + st.buffer[1]) & 3;
    switch (parity_58) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_72 = local_arr[aux % 3];
    acc = (acc + delta_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_12(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_66 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_66 > 23) {
        acc = (acc + vector_66 * 2 + 5) & 127;
        aux ^= (vector_66 & 15);
    } else {
        acc = (acc - vector_66 + 11) & 127;
        aux += 3;
    }
    int window_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_91) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_22 = local_arr[aux % 3];
    acc = (acc + vector_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_13(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000027_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int sample_75 = local_arr[aux % 3];
    acc = (acc + sample_75 * 2) & 127;
    int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_45) & 63;
    acc ^= aux;
    int delta_80 = (aux + st.buffer[1]) & 3;
    switch (delta_80) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_14(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_61 = (aux + st.buffer[1]) & 3;
    switch (index_reg_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_77 = local_arr[aux % 3];
    acc = (acc + segment_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000027_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_54 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_54 > 30) {
        acc = (acc + delta_54 * 2 + 5) & 127;
        aux ^= (delta_54 & 15);
    } else {
        acc = (acc - delta_54 + 11) & 127;
        aux += 3;
    }
    int threshold_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000027_2713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int bound_33 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_33 > 18) {
        acc = (acc + bound_33 * 2 + 5) & 127;
        aux ^= (bound_33 & 15);
    } else {
        acc = (acc - bound_33 + 11) & 127;
        aux += 3;
    }
    int checksum_89 = (aux + st.buffer[1]) & 3;
    switch (checksum_89) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_91 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_91 > 12) {
        acc = (acc + damping_91 * 2 + 5) & 127;
        aux ^= (damping_91 & 15);
    } else {
        acc = (acc - damping_91 + 11) & 127;
        aux += 3;
    }
    int window_42 = (aux + st.buffer[1]) & 3;
    switch (window_42) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_74 = local_arr[aux % 3];
    acc = (acc + residue_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000027_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_73 = (aux + st.buffer[1]) & 3;
    switch (vector_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_50 = local_arr[aux % 3];
    acc = (acc + quantum_50 * 2) & 127;
    int offset_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000027_2713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_14) & 63;
    acc ^= aux;
    int coefficient_89 = (aux + st.buffer[1]) & 3;
    switch (coefficient_89) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000027_2713_20(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int window_71 = (st.buffer[0] * 3 + aux) & 63;
    if (window_71 > 14) {
        acc = (acc + window_71 * 2 + 5) & 127;
        aux ^= (window_71 & 15);
    } else {
        acc = (acc - window_71 + 11) & 127;
        aux += 3;
    }
    int threshold_66 = (aux + st.buffer[1]) & 3;
    switch (threshold_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_56 = local_arr[aux % 3];
    acc = (acc + coefficient_56 * 2) & 127;
    int cursor_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000027_0;
    int sec_r000027_1;
    int sec_r000027_2;
    int sec_r000027_3;
    int sec_r000027_4;
    int sec_r000027_5;
    int sec_r000027_6;
    int sec_r000027_7;
    int sec_r000027_8;
    int sec_r000027_9;
    int sec_r000027_10;
    int sec_r000027_11;
    int sec_r000027_12;
    int sec_r000027_13;
    int sec_r000027_14;
    int sec_r000027_15;
    int sec_r000027_16;
    int sec_r000027_17;
    int sec_r000027_18;
    int sec_r000027_19;
    int pub_r000027_0;
    int pub_r000027_1;
    int pub_r000027_2;
    int pub_r000027_3;
    int pub_r000027_4;
    int pub_r000027_5;
    int pub_r000027_6;
    int pub_r000027_7;
    int pub_r000027_8;
    int pub_r000027_9;
    int pub_r000027_10;
    int pub_r000027_11;
    int pub_r000027_12;
    int pub_r000027_13;
    int pub_r000027_14;
    int pub_r000027_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000027_0 >= -100 && pub_r000027_0 <= 100);
    __CPROVER_assume(pub_r000027_1 >= -100 && pub_r000027_1 <= 100);
    __CPROVER_assume(pub_r000027_2 >= -100 && pub_r000027_2 <= 100);
    __CPROVER_assume(pub_r000027_3 >= -100 && pub_r000027_3 <= 100);
    __CPROVER_assume(pub_r000027_4 >= -100 && pub_r000027_4 <= 100);
    __CPROVER_assume(pub_r000027_5 >= -100 && pub_r000027_5 <= 100);
    __CPROVER_assume(pub_r000027_6 >= -100 && pub_r000027_6 <= 100);
    __CPROVER_assume(pub_r000027_7 >= -100 && pub_r000027_7 <= 100);
    __CPROVER_assume(pub_r000027_8 >= -100 && pub_r000027_8 <= 100);
    __CPROVER_assume(pub_r000027_9 >= -100 && pub_r000027_9 <= 100);
    __CPROVER_assume(pub_r000027_10 >= -100 && pub_r000027_10 <= 100);
    __CPROVER_assume(pub_r000027_11 >= -100 && pub_r000027_11 <= 100);
    __CPROVER_assume(pub_r000027_12 >= -100 && pub_r000027_12 <= 100);
    __CPROVER_assume(pub_r000027_13 >= -100 && pub_r000027_13 <= 100);
    __CPROVER_assume(pub_r000027_14 >= -100 && pub_r000027_14 <= 100);
    __CPROVER_assume(pub_r000027_15 >= -100 && pub_r000027_15 <= 100);
    __CPROVER_assume(sec_r000027_0 >= 0 && sec_r000027_0 <= 255);
    __CPROVER_assume(sec_r000027_1 >= 0 && sec_r000027_1 <= 255);
    __CPROVER_assume(sec_r000027_2 >= 0 && sec_r000027_2 <= 255);
    __CPROVER_assume(sec_r000027_3 >= 0 && sec_r000027_3 <= 255);
    __CPROVER_assume(sec_r000027_4 >= 0 && sec_r000027_4 <= 255);
    __CPROVER_assume(sec_r000027_5 >= 0 && sec_r000027_5 <= 255);
    __CPROVER_assume(sec_r000027_6 >= 0 && sec_r000027_6 <= 255);
    __CPROVER_assume(sec_r000027_7 >= 0 && sec_r000027_7 <= 255);
    __CPROVER_assume(sec_r000027_8 >= 0 && sec_r000027_8 <= 255);
    __CPROVER_assume(sec_r000027_9 >= 0 && sec_r000027_9 <= 255);
    __CPROVER_assume(sec_r000027_10 >= 0 && sec_r000027_10 <= 255);
    __CPROVER_assume(sec_r000027_11 >= 0 && sec_r000027_11 <= 255);
    __CPROVER_assume(sec_r000027_12 >= 0 && sec_r000027_12 <= 255);
    __CPROVER_assume(sec_r000027_13 >= 0 && sec_r000027_13 <= 255);
    __CPROVER_assume(sec_r000027_14 >= 0 && sec_r000027_14 <= 255);
    __CPROVER_assume(sec_r000027_15 >= 0 && sec_r000027_15 <= 255);
    __CPROVER_assume(sec_r000027_16 >= 0 && sec_r000027_16 <= 255);
    __CPROVER_assume(sec_r000027_17 >= 0 && sec_r000027_17 <= 255);
    __CPROVER_assume(sec_r000027_18 >= 0 && sec_r000027_18 <= 255);
    __CPROVER_assume(sec_r000027_19 >= 0 && sec_r000027_19 <= 255);

    struct DeviceConfig_R000027_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000027_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000027_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000027_0 + 7) & 15;
    struct CipherContext_R000027_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000027_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000027_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000027_0 + 9) & 15;
    struct FilterState_R000027_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000027_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000027_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000027_0 + 11) & 15;
    struct EventLog_R000027_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000027_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000027_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000027_0 + 13) & 15;

    union RegisterBank_R000027_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 31) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 46) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 32) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 47) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 14) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 29) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 37) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 52) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
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
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 33) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 48) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 31) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 46) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 37) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 52) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 27) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 42) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 12) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 27) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

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
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000027_5 & 1) != 0) {
        if ((sec_r000027_19 & 2) != 0) {
            stage_v_77 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000027_12 & 1) != 0) {
        if ((sec_r000027_0 & 2) != 0) {
            stage_v_78 = (pub_r000027_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000027_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000027_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000027_18 & 2) != 0) {
            stage_v_79 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000027_11 & 2) != 0) {
            stage_v_80 = (pub_r000027_1 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000027_1 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000027_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000027_5 & 1) != 0) {
        if ((sec_r000027_6 & 2) != 0) {
            stage_v_81 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000027_10 & 1) != 0) {
        if ((sec_r000027_8 & 2) != 0) {
            stage_v_82 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000027_19 & 2) != 0) {
            stage_v_83 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000027_17 & 1) != 0) {
        if ((sec_r000027_17 & 2) != 0) {
            stage_v_84 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000027_12 & 2) != 0) {
            stage_v_85 = (pub_r000027_9 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000027_9 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000027_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000027_10 & 2) != 0) {
            stage_v_86 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000027_6 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_87 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_88 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000027_3 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_89 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000027_19 & 1) != 0) {
        if ((sec_r000027_15 & 2) != 0) {
            stage_v_90 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000027_8 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_91 = (pub_r000027_15 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000027_15 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000027_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000027_19 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_92 = (pub_r000027_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000027_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000027_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000027_18 & 2) != 0) {
            stage_v_93 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_94 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_95 = (pub_r000027_14 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000027_14 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000027_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_96 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_97 = (pub_r000027_0 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000027_0 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000027_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_98 = (pub_r000027_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000027_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000027_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000027_16 & 1) != 0) {
        if ((sec_r000027_1 & 2) != 0) {
            stage_v_99 = (pub_r000027_15 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000027_15 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000027_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000027_15 & 1) != 0) {
        if ((sec_r000027_8 & 2) != 0) {
            stage_v_100 = (pub_r000027_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000027_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000027_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000027_9 & 2) != 0) {
            stage_v_101 = (pub_r000027_14 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000027_14 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000027_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000027_1 & 2) != 0) {
            stage_v_102 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000027_8 & 2) != 0) {
            stage_v_103 = (pub_r000027_6 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000027_6 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000027_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000027_19 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_104 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000027_12 & 2) != 0) {
            stage_v_105 = (pub_r000027_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000027_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000027_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000027_8 & 2) != 0) {
            stage_v_106 = (pub_r000027_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000027_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000027_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000027_0 & 2) != 0) {
            stage_v_107 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000027_18 & 2) != 0) {
            stage_v_108 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000027_0 & 2) != 0) {
            stage_v_109 = (pub_r000027_15 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000027_15 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000027_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000027_6 & 2) != 0) {
            stage_v_110 = (pub_r000027_13 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000027_13 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000027_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000027_6 & 2) != 0) {
            stage_v_111 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000027_14 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_112 = (pub_r000027_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000027_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000027_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_113 = (pub_r000027_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000027_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000027_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000027_12 & 2) != 0) {
            stage_v_114 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000027_18 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_115 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_116 = (pub_r000027_9 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000027_9 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000027_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000027_7 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_117 = (pub_r000027_11 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000027_11 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000027_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000027_1 & 2) != 0) {
            stage_v_118 = (pub_r000027_6 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000027_6 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000027_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000027_2 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_119 = (pub_r000027_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000027_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000027_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000027_7 & 1) != 0) {
        if ((sec_r000027_7 & 2) != 0) {
            stage_v_120 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000027_16 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_121 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000027_5 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_122 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000027_7 & 2) != 0) {
            stage_v_123 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_124 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_125 = (pub_r000027_15 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000027_15 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000027_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000027_3 & 1) != 0) {
        if ((sec_r000027_17 & 2) != 0) {
            stage_v_126 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000027_7 & 2) != 0) {
            stage_v_127 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000027_15 & 2) != 0) {
            stage_v_128 = (pub_r000027_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000027_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000027_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000027_7 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_129 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000027_11 & 2) != 0) {
            stage_v_130 = (pub_r000027_10 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000027_10 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000027_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000027_9 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_131 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000027_6 & 2) != 0) {
            stage_v_132 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000027_11 & 2) != 0) {
            stage_v_133 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_134 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000027_16 & 2) != 0) {
            stage_v_135 = (pub_r000027_14 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000027_14 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000027_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000027_17 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_136 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000027_5 & 2) != 0) {
            stage_v_137 = (pub_r000027_2 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000027_2 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000027_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000027_11 & 1) != 0) {
        if ((sec_r000027_2 & 2) != 0) {
            stage_v_138 = (pub_r000027_1 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000027_1 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000027_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000027_5 & 2) != 0) {
            stage_v_139 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000027_0 & 1) != 0) {
        if ((sec_r000027_6 & 2) != 0) {
            stage_v_140 = (pub_r000027_0 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000027_0 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000027_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_141 = (pub_r000027_3 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000027_3 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000027_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000027_14 & 2) != 0) {
            stage_v_142 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000027_17 & 1) != 0) {
        if ((sec_r000027_19 & 2) != 0) {
            stage_v_143 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000027_11 & 2) != 0) {
            stage_v_144 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000027_7 & 2) != 0) {
            stage_v_145 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000027_17 & 2) != 0) {
            stage_v_146 = (pub_r000027_12 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000027_12 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000027_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000027_11 & 1) != 0) {
        if ((sec_r000027_18 & 2) != 0) {
            stage_v_147 = (pub_r000027_7 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000027_7 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000027_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000027_0 & 1) != 0) {
        if ((sec_r000027_0 & 2) != 0) {
            stage_v_148 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000027_12 & 2) != 0) {
            stage_v_149 = (pub_r000027_11 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000027_11 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000027_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000027_11 & 1) != 0) {
        if ((sec_r000027_5 & 2) != 0) {
            stage_v_150 = (pub_r000027_13 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000027_13 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000027_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000027_17 & 1) != 0) {
        if ((sec_r000027_3 & 2) != 0) {
            stage_v_151 = (pub_r000027_5 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000027_5 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000027_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000027_12 & 1) != 0) {
        if ((sec_r000027_4 & 2) != 0) {
            stage_v_152 = (pub_r000027_4 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000027_4 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000027_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000027_13 & 2) != 0) {
            stage_v_153 = (pub_r000027_14 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000027_14 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000027_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
