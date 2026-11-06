/*
 * Benchmark Program: R000037
 * Security Family: nested_implicit_flow
 * Generator Seed: 503713
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000037_3713_0 {
    int checksum;
    unsigned char capacity;
    int tail;
    int buffer[3];
};

struct Transaction_R000037_3713_1 {
    short fee;
    unsigned char rate;
    int balance;
    int buffer[3];
};

struct CipherContext_R000037_3713_2 {
    unsigned char tag;
    int counter;
    int flags;
    int buffer[3];
};

struct EventLog_R000037_3713_3 {
    int code;
    unsigned char severity;
    unsigned char seq;
    int signature;
    unsigned char facility;
    int buffer[3];
};

union ColorPixel_R000037_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000037_3713_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int mask_69 = local_arr[aux % 3];
    acc = (acc + mask_69 * 2) & 127;
    int margin_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_24) & 63;
    acc ^= aux;
    int weight_36 = (aux + st.buffer[1]) & 3;
    switch (weight_36) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int checksum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_38 > 46) {
        acc = (acc + checksum_38 * 2 + 5) & 127;
        aux ^= (checksum_38 & 15);
    } else {
        acc = (acc - checksum_38 + 11) & 127;
        aux += 3;
    }
    int cursor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_3(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000037_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_94 = local_arr[aux % 3];
    acc = (acc + phase_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000037_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int phase_50 = (aux + st.buffer[1]) & 3;
    switch (phase_50) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_28 = local_arr[aux % 3];
    acc = (acc + tally_28 * 2) & 127;
    int cursor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_32 > 26) {
        acc = (acc + cursor_32 * 2 + 5) & 127;
        aux ^= (cursor_32 & 15);
    } else {
        acc = (acc - cursor_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_11 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_11 > 35) {
        acc = (acc + delta_11 * 2 + 5) & 127;
        aux ^= (delta_11 & 15);
    } else {
        acc = (acc - delta_11 + 11) & 127;
        aux += 3;
    }
    int weight_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000037_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int parity_90 = local_arr[aux % 3];
    acc = (acc + parity_90 * 2) & 127;
    int threshold_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int damping_20 = local_arr[aux % 3];
    acc = (acc + damping_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_91 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_91 > 40) {
        acc = (acc + checksum_91 * 2 + 5) & 127;
        aux ^= (checksum_91 & 15);
    } else {
        acc = (acc - checksum_91 + 11) & 127;
        aux += 3;
    }
    int residue_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_18) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_77 = local_arr[aux % 3];
    acc = (acc + offset_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_59 = (st.buffer[0] * 3 + aux) & 63;
    if (window_59 > 49) {
        acc = (acc + window_59 * 2 + 5) & 127;
        aux ^= (window_59 & 15);
    } else {
        acc = (acc - window_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_35 = local_arr[aux % 3];
    acc = (acc + quotient_35 * 2) & 127;
    int segment_35 = (aux + st.buffer[1]) & 3;
    switch (segment_35) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000037_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_11(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_96 = (aux + st.buffer[1]) & 3;
    switch (factor_96) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_84 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_84 > 37) {
        acc = (acc + segment_84 * 2 + 5) & 127;
        aux ^= (segment_84 & 15);
    } else {
        acc = (acc - segment_84 + 11) & 127;
        aux += 3;
    }
    int tally_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_31 = local_arr[aux % 3];
    acc = (acc + phase_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_12(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int pivot_57 = local_arr[aux % 3];
    acc = (acc + pivot_57 * 2) & 127;
    int parity_62 = (aux + st.buffer[1]) & 3;
    switch (parity_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_61 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_61 > 46) {
        acc = (acc + scale_61 * 2 + 5) & 127;
        aux ^= (scale_61 & 15);
    } else {
        acc = (acc - scale_61 + 11) & 127;
        aux += 3;
    }
    int phase_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_13(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000037_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_31 = (aux + st.buffer[1]) & 3;
    switch (window_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_49 = local_arr[aux % 3];
    acc = (acc + factor_49 * 2) & 127;
    int threshold_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000037_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int metric_68 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_68 > 16) {
        acc = (acc + metric_68 * 2 + 5) & 127;
        aux ^= (metric_68 & 15);
    } else {
        acc = (acc - metric_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_11) & 63;
    acc ^= aux;
    int damping_74 = (aux + st.buffer[1]) & 3;
    switch (damping_74) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int accumulator_32 = local_arr[aux % 3];
    acc = (acc + accumulator_32 * 2) & 127;
    int anchor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_77 > 21) {
        acc = (acc + anchor_77 * 2 + 5) & 127;
        aux ^= (anchor_77 & 15);
    } else {
        acc = (acc - anchor_77 + 11) & 127;
        aux += 3;
    }
    int tracker_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_15) & 63;
    acc ^= aux;
    int mask_72 = (aux + st.buffer[1]) & 3;
    switch (mask_72) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_28 = local_arr[aux % 3];
    acc = (acc + quotient_28 * 2) & 127;
    int mask_75 = (aux + st.buffer[1]) & 3;
    switch (mask_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000037_3713_17(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000037_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000037_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_81 = (aux + st.buffer[1]) & 3;
    switch (anchor_81) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_11 = local_arr[aux % 3];
    acc = (acc + coefficient_11 * 2) & 127;
    int threshold_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_19(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000037_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_53 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_53 > 14) {
        acc = (acc + checksum_53 * 2 + 5) & 127;
        aux ^= (checksum_53 & 15);
    } else {
        acc = (acc - checksum_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_25 = local_arr[aux % 3];
    acc = (acc + parity_25 * 2) & 127;
    int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000037_3713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_92 = (aux + st.buffer[1]) & 3;
    switch (coefficient_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_85 = local_arr[aux % 3];
    acc = (acc + residue_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_87 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_87 > 23) {
        acc = (acc + cursor_87 * 2 + 5) & 127;
        aux ^= (cursor_87 & 15);
    } else {
        acc = (acc - cursor_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_21(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000037_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_27 = local_arr[aux % 3];
    acc = (acc + vector_27 * 2) & 127;
    int bound_79 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_79 > 40) {
        acc = (acc + bound_79 * 2 + 5) & 127;
        aux ^= (bound_79 & 15);
    } else {
        acc = (acc - bound_79 + 11) & 127;
        aux += 3;
    }
    int index_reg_97 = (aux + st.buffer[1]) & 3;
    switch (index_reg_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000037_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int metric_66 = (aux + st.buffer[1]) & 3;
    switch (metric_66) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_32) & 63;
    acc ^= aux;
    int offset_84 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_84 > 45) {
        acc = (acc + offset_84 * 2 + 5) & 127;
        aux ^= (offset_84 & 15);
    } else {
        acc = (acc - offset_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000037_3713_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000037_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    int offset_44 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_44 > 30) {
        acc = (acc + offset_44 * 2 + 5) & 127;
        aux ^= (offset_44 & 15);
    } else {
        acc = (acc - offset_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000037_0;
    int sec_r000037_1;
    int sec_r000037_2;
    int sec_r000037_3;
    int sec_r000037_4;
    int sec_r000037_5;
    int sec_r000037_6;
    int sec_r000037_7;
    int sec_r000037_8;
    int sec_r000037_9;
    int sec_r000037_10;
    int sec_r000037_11;
    int sec_r000037_12;
    int sec_r000037_13;
    int sec_r000037_14;
    int sec_r000037_15;
    int sec_r000037_16;
    int sec_r000037_17;
    int sec_r000037_18;
    int sec_r000037_19;
    int pub_r000037_0;
    int pub_r000037_1;
    int pub_r000037_2;
    int pub_r000037_3;
    int pub_r000037_4;
    int pub_r000037_5;
    int pub_r000037_6;
    int pub_r000037_7;
    int pub_r000037_8;
    int pub_r000037_9;
    int pub_r000037_10;
    int pub_r000037_11;
    int pub_r000037_12;
    int pub_r000037_13;
    int pub_r000037_14;
    int pub_r000037_15;
    int pub_r000037_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000037_0 >= -100 && pub_r000037_0 <= 100);
    __CPROVER_assume(pub_r000037_1 >= -100 && pub_r000037_1 <= 100);
    __CPROVER_assume(pub_r000037_2 >= -100 && pub_r000037_2 <= 100);
    __CPROVER_assume(pub_r000037_3 >= -100 && pub_r000037_3 <= 100);
    __CPROVER_assume(pub_r000037_4 >= -100 && pub_r000037_4 <= 100);
    __CPROVER_assume(pub_r000037_5 >= -100 && pub_r000037_5 <= 100);
    __CPROVER_assume(pub_r000037_6 >= -100 && pub_r000037_6 <= 100);
    __CPROVER_assume(pub_r000037_7 >= -100 && pub_r000037_7 <= 100);
    __CPROVER_assume(pub_r000037_8 >= -100 && pub_r000037_8 <= 100);
    __CPROVER_assume(pub_r000037_9 >= -100 && pub_r000037_9 <= 100);
    __CPROVER_assume(pub_r000037_10 >= -100 && pub_r000037_10 <= 100);
    __CPROVER_assume(pub_r000037_11 >= -100 && pub_r000037_11 <= 100);
    __CPROVER_assume(pub_r000037_12 >= -100 && pub_r000037_12 <= 100);
    __CPROVER_assume(pub_r000037_13 >= -100 && pub_r000037_13 <= 100);
    __CPROVER_assume(pub_r000037_14 >= -100 && pub_r000037_14 <= 100);
    __CPROVER_assume(pub_r000037_15 >= -100 && pub_r000037_15 <= 100);
    __CPROVER_assume(pub_r000037_16 >= -100 && pub_r000037_16 <= 100);
    __CPROVER_assume(sec_r000037_0 >= 0 && sec_r000037_0 <= 255);
    __CPROVER_assume(sec_r000037_1 >= 0 && sec_r000037_1 <= 255);
    __CPROVER_assume(sec_r000037_2 >= 0 && sec_r000037_2 <= 255);
    __CPROVER_assume(sec_r000037_3 >= 0 && sec_r000037_3 <= 255);
    __CPROVER_assume(sec_r000037_4 >= 0 && sec_r000037_4 <= 255);
    __CPROVER_assume(sec_r000037_5 >= 0 && sec_r000037_5 <= 255);
    __CPROVER_assume(sec_r000037_6 >= 0 && sec_r000037_6 <= 255);
    __CPROVER_assume(sec_r000037_7 >= 0 && sec_r000037_7 <= 255);
    __CPROVER_assume(sec_r000037_8 >= 0 && sec_r000037_8 <= 255);
    __CPROVER_assume(sec_r000037_9 >= 0 && sec_r000037_9 <= 255);
    __CPROVER_assume(sec_r000037_10 >= 0 && sec_r000037_10 <= 255);
    __CPROVER_assume(sec_r000037_11 >= 0 && sec_r000037_11 <= 255);
    __CPROVER_assume(sec_r000037_12 >= 0 && sec_r000037_12 <= 255);
    __CPROVER_assume(sec_r000037_13 >= 0 && sec_r000037_13 <= 255);
    __CPROVER_assume(sec_r000037_14 >= 0 && sec_r000037_14 <= 255);
    __CPROVER_assume(sec_r000037_15 >= 0 && sec_r000037_15 <= 255);
    __CPROVER_assume(sec_r000037_16 >= 0 && sec_r000037_16 <= 255);
    __CPROVER_assume(sec_r000037_17 >= 0 && sec_r000037_17 <= 255);
    __CPROVER_assume(sec_r000037_18 >= 0 && sec_r000037_18 <= 255);
    __CPROVER_assume(sec_r000037_19 >= 0 && sec_r000037_19 <= 255);

    struct StreamBuffer_R000037_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000037_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000037_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000037_0 + 7) & 15;
    struct Transaction_R000037_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000037_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000037_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000037_0 + 9) & 15;
    struct CipherContext_R000037_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000037_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000037_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000037_0 + 11) & 15;
    struct EventLog_R000037_3713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000037_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000037_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000037_0 + 13) & 15;

    union ColorPixel_R000037_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 35) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 50) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
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
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 20) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 35) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 17) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 32) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 14) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 29) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 30) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 45) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 42) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 12) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 27) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 34) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 49) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 17) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 32) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000037_11 & 1) != 0) {
        if ((sec_r000037_9 & 2) != 0) {
            stage_v_44 = (pub_r000037_1 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000037_1 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000037_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000037_12 & 2) != 0) {
            stage_v_45 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_46 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_47 = (pub_r000037_3 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000037_3 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000037_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000037_17 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_48 = (pub_r000037_10 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000037_10 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000037_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000037_7 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_49 = (pub_r000037_9 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000037_9 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000037_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000037_18 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_50 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000037_13 & 2) != 0) {
            stage_v_51 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000037_12 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_52 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000037_2 & 2) != 0) {
            stage_v_53 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000037_4 & 1) != 0) {
        if ((sec_r000037_8 & 2) != 0) {
            stage_v_54 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000037_10 & 1) != 0) {
        if ((sec_r000037_18 & 2) != 0) {
            stage_v_55 = (pub_r000037_11 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000037_11 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000037_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000037_19 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_56 = (pub_r000037_1 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000037_1 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000037_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000037_5 & 2) != 0) {
            stage_v_57 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000037_14 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_58 = (pub_r000037_6 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000037_6 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000037_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000037_14 & 1) != 0) {
        if ((sec_r000037_14 & 2) != 0) {
            stage_v_59 = (pub_r000037_10 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000037_10 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000037_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000037_8 & 1) != 0) {
        if ((sec_r000037_8 & 2) != 0) {
            stage_v_60 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_61 = (pub_r000037_8 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000037_8 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000037_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000037_10 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_62 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_63 = (pub_r000037_9 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000037_9 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000037_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000037_18 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_64 = (pub_r000037_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000037_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000037_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000037_3 & 2) != 0) {
            stage_v_65 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_66 = (pub_r000037_8 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000037_8 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000037_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_67 = (pub_r000037_0 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000037_0 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000037_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000037_2 & 2) != 0) {
            stage_v_68 = (pub_r000037_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000037_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000037_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_69 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000037_8 & 1) != 0) {
        if ((sec_r000037_1 & 2) != 0) {
            stage_v_70 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000037_19 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_71 = (pub_r000037_3 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000037_3 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000037_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_72 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000037_6 & 2) != 0) {
            stage_v_73 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000037_5 & 2) != 0) {
            stage_v_74 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000037_15 & 1) != 0) {
        if ((sec_r000037_18 & 2) != 0) {
            stage_v_75 = (pub_r000037_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000037_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000037_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000037_14 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_76 = (pub_r000037_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000037_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000037_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_77 = (pub_r000037_16 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000037_16 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000037_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_78 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000037_12 & 2) != 0) {
            stage_v_79 = (pub_r000037_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000037_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000037_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000037_12 & 2) != 0) {
            stage_v_80 = (pub_r000037_0 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000037_0 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000037_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000037_15 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_81 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000037_5 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_82 = (pub_r000037_2 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000037_2 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000037_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_83 = (pub_r000037_11 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000037_11 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000037_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000037_18 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_84 = (pub_r000037_10 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000037_10 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000037_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000037_4 & 1) != 0) {
        if ((sec_r000037_19 & 2) != 0) {
            stage_v_85 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_86 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000037_1 & 2) != 0) {
            stage_v_87 = (pub_r000037_13 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000037_13 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000037_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000037_2 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_88 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000037_11 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_89 = (pub_r000037_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000037_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000037_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000037_9 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_90 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000037_14 & 2) != 0) {
            stage_v_91 = (pub_r000037_3 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000037_3 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000037_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_92 = (pub_r000037_13 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000037_13 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000037_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_93 = (pub_r000037_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000037_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000037_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000037_1 & 2) != 0) {
            stage_v_94 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000037_2 & 2) != 0) {
            stage_v_95 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000037_5 & 2) != 0) {
            stage_v_96 = (pub_r000037_0 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000037_0 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000037_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000037_3 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_97 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000037_9 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_98 = (pub_r000037_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000037_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000037_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_99 = (pub_r000037_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000037_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000037_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000037_7 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_100 = (pub_r000037_13 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000037_13 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000037_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_101 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_102 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000037_18 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_103 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000037_3 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_104 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_105 = (pub_r000037_1 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000037_1 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000037_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000037_9 & 2) != 0) {
            stage_v_106 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_107 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000037_11 & 1) != 0) {
        if ((sec_r000037_1 & 2) != 0) {
            stage_v_108 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_109 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_110 = (pub_r000037_0 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000037_0 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000037_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000037_0 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_111 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000037_4 & 1) != 0) {
        if ((sec_r000037_9 & 2) != 0) {
            stage_v_112 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000037_16 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_113 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000037_6 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_114 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_115 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000037_3 & 2) != 0) {
            stage_v_116 = (pub_r000037_14 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000037_14 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000037_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000037_6 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_117 = (pub_r000037_8 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000037_8 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000037_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000037_19 & 2) != 0) {
            stage_v_118 = (pub_r000037_1 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000037_1 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000037_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_119 = (pub_r000037_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000037_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000037_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000037_11 & 2) != 0) {
            stage_v_120 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000037_13 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_121 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000037_18 & 2) != 0) {
            stage_v_122 = (pub_r000037_6 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000037_6 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000037_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000037_10 & 2) != 0) {
            stage_v_123 = (pub_r000037_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000037_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000037_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000037_5 & 2) != 0) {
            stage_v_124 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000037_18 & 2) != 0) {
            stage_v_125 = (pub_r000037_13 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000037_13 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000037_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000037_0 & 2) != 0) {
            stage_v_126 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000037_14 & 1) != 0) {
        if ((sec_r000037_6 & 2) != 0) {
            stage_v_127 = (pub_r000037_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000037_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000037_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000037_11 & 1) != 0) {
        if ((sec_r000037_16 & 2) != 0) {
            stage_v_128 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_129 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000037_13 & 1) != 0) {
        if ((sec_r000037_15 & 2) != 0) {
            stage_v_130 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000037_13 & 2) != 0) {
            stage_v_131 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000037_2 & 2) != 0) {
            stage_v_132 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000037_4 & 2) != 0) {
            stage_v_133 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000037_17 & 2) != 0) {
            stage_v_134 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000037_2 & 1) != 0) {
        if ((sec_r000037_3 & 2) != 0) {
            stage_v_135 = (pub_r000037_7 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000037_7 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000037_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000037_5 & 1) != 0) {
        if ((sec_r000037_7 & 2) != 0) {
            stage_v_136 = (pub_r000037_5 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000037_5 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000037_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000037_3 & 2) != 0) {
            stage_v_137 = (pub_r000037_15 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000037_15 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000037_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000037_14 & 2) != 0) {
            stage_v_138 = (pub_r000037_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000037_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000037_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
