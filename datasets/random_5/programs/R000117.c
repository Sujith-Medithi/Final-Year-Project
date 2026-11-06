/*
 * Benchmark Program: R000117
 * Security Family: nested_implicit_flow
 * Generator Seed: 511713
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000117_1713_0 {
    unsigned char flags;
    int round_key;
    unsigned char tag;
    int nonce;
    int buffer[3];
};

struct EventLog_R000117_1713_1 {
    int code;
    short facility;
    unsigned char signature;
    int timestamp;
    int severity;
    int seq;
    int buffer[3];
};

union TelemetryField_R000117_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000117_1713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000117_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int bound_31 = local_arr[aux % 3];
    acc = (acc + bound_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_92 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_92 > 30) {
        acc = (acc + tally_92 * 2 + 5) & 127;
        aux ^= (tally_92 & 15);
    } else {
        acc = (acc - tally_92 + 11) & 127;
        aux += 3;
    }
    int cursor_50 = (aux + st.buffer[1]) & 3;
    switch (cursor_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_1(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_51) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_71 = local_arr[aux % 3];
    acc = (acc + pivot_71 * 2) & 127;
    int quotient_93 = (aux + st.buffer[1]) & 3;
    switch (quotient_93) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tally_16 = local_arr[aux % 3];
    acc = (acc + tally_16 * 2) & 127;
    int window_80 = (aux + st.buffer[1]) & 3;
    switch (window_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_43) & 63;
    acc ^= aux;
    int vector_99 = (aux + st.buffer[1]) & 3;
    switch (vector_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int index_reg_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_33) & 63;
    acc ^= aux;
    int scale_75 = (aux + st.buffer[1]) & 3;
    switch (scale_75) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_84 = local_arr[aux % 3];
    acc = (acc + weight_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_72 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_72 > 13) {
        acc = (acc + factor_72 * 2 + 5) & 127;
        aux ^= (factor_72 & 15);
    } else {
        acc = (acc - factor_72 + 11) & 127;
        aux += 3;
    }
    int vector_15 = (aux + st.buffer[1]) & 3;
    switch (vector_15) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_6(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_82) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_66 = (aux + st.buffer[1]) & 3;
    switch (damping_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_96 = local_arr[aux % 3];
    acc = (acc + checksum_96 * 2) & 127;
    int threshold_97 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_97 > 25) {
        acc = (acc + threshold_97 * 2 + 5) & 127;
        aux ^= (threshold_97 & 15);
    } else {
        acc = (acc - threshold_97 + 11) & 127;
        aux += 3;
    }
    int window_48 = (aux + st.buffer[1]) & 3;
    switch (window_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_55 = (st.buffer[0] * 3 + aux) & 63;
    if (window_55 > 20) {
        acc = (acc + window_55 * 2 + 5) & 127;
        aux ^= (window_55 & 15);
    } else {
        acc = (acc - window_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_81 = local_arr[aux % 3];
    acc = (acc + quotient_81 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000117_1713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_94) & 63;
    acc ^= aux;
    int bound_48 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_48 > 44) {
        acc = (acc + bound_48 * 2 + 5) & 127;
        aux ^= (bound_48 & 15);
    } else {
        acc = (acc - bound_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_52 = local_arr[aux % 3];
    acc = (acc + vector_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_41 = (aux + st.buffer[1]) & 3;
    switch (index_reg_41) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int tracker_23 = local_arr[aux % 3];
    acc = (acc + tracker_23 * 2) & 127;
    int pivot_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_41) & 63;
    acc ^= aux;
    int checksum_14 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_14 > 36) {
        acc = (acc + checksum_14 * 2 + 5) & 127;
        aux ^= (checksum_14 & 15);
    } else {
        acc = (acc - checksum_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_41 = local_arr[aux % 3];
    acc = (acc + index_reg_41 * 2) & 127;
    int segment_69 = (aux + st.buffer[1]) & 3;
    switch (segment_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_13(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int residue_67 = (aux + st.buffer[1]) & 3;
    switch (residue_67) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_59 = local_arr[aux % 3];
    acc = (acc + residue_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_14(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int segment_57 = local_arr[aux % 3];
    acc = (acc + segment_57 * 2) & 127;
    int delta_87 = (aux + st.buffer[1]) & 3;
    switch (delta_87) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000117_1713_15(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_54 = (aux + st.buffer[1]) & 3;
    switch (mask_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_60 = local_arr[aux % 3];
    acc = (acc + quotient_60 * 2) & 127;
    int segment_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000117_1713_16(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_94) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_50 = local_arr[aux % 3];
    acc = (acc + tracker_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_17(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_65 = (aux + st.buffer[1]) & 3;
    switch (scale_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_44 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_44 > 47) {
        acc = (acc + parity_44 * 2 + 5) & 127;
        aux ^= (parity_44 & 15);
    } else {
        acc = (acc - parity_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000117_1713_18(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tracker_17 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_17 > 45) {
        acc = (acc + tracker_17 * 2 + 5) & 127;
        aux ^= (tracker_17 & 15);
    } else {
        acc = (acc - tracker_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_84 = local_arr[aux % 3];
    acc = (acc + factor_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000117_1713_19(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int anchor_12 = local_arr[aux % 3];
    acc = (acc + anchor_12 * 2) & 127;
    int index_reg_27 = (aux + st.buffer[1]) & 3;
    switch (index_reg_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000117_1713_20(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_40 = local_arr[aux % 3];
    acc = (acc + delta_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000117_1713_21(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_57 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_57 > 36) {
        acc = (acc + phase_57 * 2 + 5) & 127;
        aux ^= (phase_57 & 15);
    } else {
        acc = (acc - phase_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000117_0;
    int sec_r000117_1;
    int sec_r000117_2;
    int sec_r000117_3;
    int sec_r000117_4;
    int sec_r000117_5;
    int sec_r000117_6;
    int sec_r000117_7;
    int sec_r000117_8;
    int sec_r000117_9;
    int sec_r000117_10;
    int sec_r000117_11;
    int sec_r000117_12;
    int sec_r000117_13;
    int sec_r000117_14;
    int sec_r000117_15;
    int sec_r000117_16;
    int sec_r000117_17;
    int sec_r000117_18;
    int pub_r000117_0;
    int pub_r000117_1;
    int pub_r000117_2;
    int pub_r000117_3;
    int pub_r000117_4;
    int pub_r000117_5;
    int pub_r000117_6;
    int pub_r000117_7;
    int pub_r000117_8;
    int pub_r000117_9;
    int pub_r000117_10;
    int pub_r000117_11;
    int pub_r000117_12;
    int pub_r000117_13;
    int pub_r000117_14;
    int pub_r000117_15;
    int pub_r000117_16;
    int pub_r000117_17;
    int pub_r000117_18;
    int pub_r000117_19;
    int pub_r000117_20;
    int pub_r000117_21;
    int pub_r000117_22;
    int pub_r000117_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000117_0 >= -100 && pub_r000117_0 <= 100);
    __CPROVER_assume(pub_r000117_1 >= -100 && pub_r000117_1 <= 100);
    __CPROVER_assume(pub_r000117_2 >= -100 && pub_r000117_2 <= 100);
    __CPROVER_assume(pub_r000117_3 >= -100 && pub_r000117_3 <= 100);
    __CPROVER_assume(pub_r000117_4 >= -100 && pub_r000117_4 <= 100);
    __CPROVER_assume(pub_r000117_5 >= -100 && pub_r000117_5 <= 100);
    __CPROVER_assume(pub_r000117_6 >= -100 && pub_r000117_6 <= 100);
    __CPROVER_assume(pub_r000117_7 >= -100 && pub_r000117_7 <= 100);
    __CPROVER_assume(pub_r000117_8 >= -100 && pub_r000117_8 <= 100);
    __CPROVER_assume(pub_r000117_9 >= -100 && pub_r000117_9 <= 100);
    __CPROVER_assume(pub_r000117_10 >= -100 && pub_r000117_10 <= 100);
    __CPROVER_assume(pub_r000117_11 >= -100 && pub_r000117_11 <= 100);
    __CPROVER_assume(pub_r000117_12 >= -100 && pub_r000117_12 <= 100);
    __CPROVER_assume(pub_r000117_13 >= -100 && pub_r000117_13 <= 100);
    __CPROVER_assume(pub_r000117_14 >= -100 && pub_r000117_14 <= 100);
    __CPROVER_assume(pub_r000117_15 >= -100 && pub_r000117_15 <= 100);
    __CPROVER_assume(pub_r000117_16 >= -100 && pub_r000117_16 <= 100);
    __CPROVER_assume(pub_r000117_17 >= -100 && pub_r000117_17 <= 100);
    __CPROVER_assume(pub_r000117_18 >= -100 && pub_r000117_18 <= 100);
    __CPROVER_assume(pub_r000117_19 >= -100 && pub_r000117_19 <= 100);
    __CPROVER_assume(pub_r000117_20 >= -100 && pub_r000117_20 <= 100);
    __CPROVER_assume(pub_r000117_21 >= -100 && pub_r000117_21 <= 100);
    __CPROVER_assume(pub_r000117_22 >= -100 && pub_r000117_22 <= 100);
    __CPROVER_assume(pub_r000117_23 >= -100 && pub_r000117_23 <= 100);
    __CPROVER_assume(sec_r000117_0 >= 0 && sec_r000117_0 <= 255);
    __CPROVER_assume(sec_r000117_1 >= 0 && sec_r000117_1 <= 255);
    __CPROVER_assume(sec_r000117_2 >= 0 && sec_r000117_2 <= 255);
    __CPROVER_assume(sec_r000117_3 >= 0 && sec_r000117_3 <= 255);
    __CPROVER_assume(sec_r000117_4 >= 0 && sec_r000117_4 <= 255);
    __CPROVER_assume(sec_r000117_5 >= 0 && sec_r000117_5 <= 255);
    __CPROVER_assume(sec_r000117_6 >= 0 && sec_r000117_6 <= 255);
    __CPROVER_assume(sec_r000117_7 >= 0 && sec_r000117_7 <= 255);
    __CPROVER_assume(sec_r000117_8 >= 0 && sec_r000117_8 <= 255);
    __CPROVER_assume(sec_r000117_9 >= 0 && sec_r000117_9 <= 255);
    __CPROVER_assume(sec_r000117_10 >= 0 && sec_r000117_10 <= 255);
    __CPROVER_assume(sec_r000117_11 >= 0 && sec_r000117_11 <= 255);
    __CPROVER_assume(sec_r000117_12 >= 0 && sec_r000117_12 <= 255);
    __CPROVER_assume(sec_r000117_13 >= 0 && sec_r000117_13 <= 255);
    __CPROVER_assume(sec_r000117_14 >= 0 && sec_r000117_14 <= 255);
    __CPROVER_assume(sec_r000117_15 >= 0 && sec_r000117_15 <= 255);
    __CPROVER_assume(sec_r000117_16 >= 0 && sec_r000117_16 <= 255);
    __CPROVER_assume(sec_r000117_17 >= 0 && sec_r000117_17 <= 255);
    __CPROVER_assume(sec_r000117_18 >= 0 && sec_r000117_18 <= 255);

    struct CipherContext_R000117_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000117_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000117_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000117_0 + 7) & 15;
    struct EventLog_R000117_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000117_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000117_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000117_0 + 9) & 15;

    union TelemetryField_R000117_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 33) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 48) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 24) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 39) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 37) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 52) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 38) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 53) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 15) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 30) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 37) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 52) {
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
    if (stage_v_23 > 36) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 51) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 10) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 25) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 19) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 34) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 28) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 43) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((sec_r000117_14 & 1) != 0) {
        if ((sec_r000117_0 & 2) != 0) {
            stage_v_37 = (pub_r000117_14 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000117_14 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000117_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000117_16 & 2) != 0) {
            stage_v_38 = (pub_r000117_9 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000117_9 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000117_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_39 = (pub_r000117_17 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000117_17 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000117_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000117_9 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_40 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000117_13 & 1) != 0) {
        if ((sec_r000117_15 & 2) != 0) {
            stage_v_41 = (pub_r000117_18 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000117_18 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000117_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_42 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000117_8 & 2) != 0) {
            stage_v_43 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000117_18 & 2) != 0) {
            stage_v_44 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000117_16 & 2) != 0) {
            stage_v_45 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_46 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000117_17 & 2) != 0) {
            stage_v_47 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000117_5 & 1) != 0) {
        if ((sec_r000117_17 & 2) != 0) {
            stage_v_48 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000117_1 & 1) != 0) {
        if ((sec_r000117_15 & 2) != 0) {
            stage_v_49 = (pub_r000117_3 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000117_3 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000117_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000117_16 & 2) != 0) {
            stage_v_50 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_51 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_52 = (pub_r000117_9 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000117_9 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000117_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000117_4 & 2) != 0) {
            stage_v_53 = (pub_r000117_21 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000117_21 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000117_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_54 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_55 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000117_10 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_56 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000117_8 & 2) != 0) {
            stage_v_57 = (pub_r000117_11 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000117_11 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000117_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000117_17 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_58 = (pub_r000117_3 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000117_3 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000117_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000117_2 & 2) != 0) {
            stage_v_59 = (pub_r000117_4 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000117_4 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000117_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000117_13 & 2) != 0) {
            stage_v_60 = (pub_r000117_12 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000117_12 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000117_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000117_0 & 2) != 0) {
            stage_v_61 = (pub_r000117_10 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000117_10 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000117_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000117_13 & 2) != 0) {
            stage_v_62 = (pub_r000117_21 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000117_21 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000117_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_63 = (pub_r000117_21 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000117_21 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000117_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_64 = (pub_r000117_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000117_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000117_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_65 = (pub_r000117_16 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000117_16 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000117_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000117_8 & 2) != 0) {
            stage_v_66 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000117_10 & 2) != 0) {
            stage_v_67 = (pub_r000117_7 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000117_7 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000117_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000117_17 & 2) != 0) {
            stage_v_68 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000117_1 & 1) != 0) {
        if ((sec_r000117_5 & 2) != 0) {
            stage_v_69 = (pub_r000117_10 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000117_10 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000117_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000117_0 & 1) != 0) {
        if ((sec_r000117_18 & 2) != 0) {
            stage_v_70 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000117_0 & 1) != 0) {
        if ((sec_r000117_9 & 2) != 0) {
            stage_v_71 = (pub_r000117_7 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000117_7 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000117_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000117_16 & 1) != 0) {
        if ((sec_r000117_15 & 2) != 0) {
            stage_v_72 = (pub_r000117_15 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000117_15 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000117_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000117_17 & 2) != 0) {
            stage_v_73 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000117_3 & 1) != 0) {
        if ((sec_r000117_9 & 2) != 0) {
            stage_v_74 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000117_4 & 2) != 0) {
            stage_v_75 = (pub_r000117_11 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000117_11 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000117_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000117_2 & 1) != 0) {
        if ((sec_r000117_17 & 2) != 0) {
            stage_v_76 = (pub_r000117_5 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000117_5 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000117_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000117_11 & 2) != 0) {
            stage_v_77 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000117_1 & 1) != 0) {
        if ((sec_r000117_2 & 2) != 0) {
            stage_v_78 = (pub_r000117_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000117_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000117_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000117_5 & 1) != 0) {
        if ((sec_r000117_4 & 2) != 0) {
            stage_v_79 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_80 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000117_0 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_81 = (pub_r000117_18 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000117_18 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000117_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_82 = (pub_r000117_18 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000117_18 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000117_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000117_3 & 1) != 0) {
        if ((sec_r000117_11 & 2) != 0) {
            stage_v_83 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000117_1 & 1) != 0) {
        if ((sec_r000117_18 & 2) != 0) {
            stage_v_84 = (pub_r000117_18 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000117_18 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000117_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000117_16 & 2) != 0) {
            stage_v_85 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000117_5 & 2) != 0) {
            stage_v_86 = (pub_r000117_17 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000117_17 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000117_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000117_1 & 2) != 0) {
            stage_v_87 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_88 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_89 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000117_5 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_90 = (pub_r000117_21 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000117_21 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000117_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000117_7 & 1) != 0) {
        if ((sec_r000117_9 & 2) != 0) {
            stage_v_91 = (pub_r000117_11 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000117_11 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000117_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000117_13 & 2) != 0) {
            stage_v_92 = (pub_r000117_22 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000117_22 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000117_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000117_9 & 2) != 0) {
            stage_v_93 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000117_18 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_94 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000117_1 & 2) != 0) {
            stage_v_95 = (pub_r000117_13 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000117_13 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000117_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000117_7 & 2) != 0) {
            stage_v_96 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000117_18 & 1) != 0) {
        if ((sec_r000117_2 & 2) != 0) {
            stage_v_97 = (pub_r000117_23 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000117_23 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000117_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000117_2 & 1) != 0) {
        if ((sec_r000117_11 & 2) != 0) {
            stage_v_98 = (pub_r000117_12 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000117_12 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000117_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000117_0 & 2) != 0) {
            stage_v_99 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000117_2 & 1) != 0) {
        if ((sec_r000117_1 & 2) != 0) {
            stage_v_100 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000117_4 & 2) != 0) {
            stage_v_101 = (pub_r000117_17 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000117_17 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000117_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000117_16 & 2) != 0) {
            stage_v_102 = (pub_r000117_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000117_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000117_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000117_10 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_103 = (pub_r000117_20 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000117_20 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000117_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000117_11 & 2) != 0) {
            stage_v_104 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000117_14 & 1) != 0) {
        if ((sec_r000117_2 & 2) != 0) {
            stage_v_105 = (pub_r000117_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000117_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000117_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000117_10 & 2) != 0) {
            stage_v_106 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000117_15 & 1) != 0) {
        if ((sec_r000117_7 & 2) != 0) {
            stage_v_107 = (pub_r000117_10 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000117_10 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000117_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000117_9 & 1) != 0) {
        if ((sec_r000117_5 & 2) != 0) {
            stage_v_108 = (pub_r000117_3 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000117_3 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000117_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000117_18 & 2) != 0) {
            stage_v_109 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000117_11 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_110 = (pub_r000117_7 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000117_7 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000117_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_111 = (pub_r000117_10 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000117_10 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000117_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000117_3 & 2) != 0) {
            stage_v_112 = (pub_r000117_19 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000117_19 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000117_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000117_10 & 2) != 0) {
            stage_v_113 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_114 = (pub_r000117_3 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000117_3 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000117_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000117_1 & 2) != 0) {
            stage_v_115 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000117_6 & 2) != 0) {
            stage_v_116 = (pub_r000117_4 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000117_4 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000117_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000117_15 & 2) != 0) {
            stage_v_117 = (pub_r000117_2 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000117_2 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000117_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000117_2 & 1) != 0) {
        if ((sec_r000117_13 & 2) != 0) {
            stage_v_118 = (pub_r000117_17 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000117_17 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000117_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000117_12 & 2) != 0) {
            stage_v_119 = (pub_r000117_11 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000117_11 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000117_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000117_15 & 1) != 0) {
        if ((sec_r000117_14 & 2) != 0) {
            stage_v_120 = (pub_r000117_8 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000117_8 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000117_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000117_5 & 2) != 0) {
            stage_v_121 = (pub_r000117_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000117_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000117_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000117_9 & 1) != 0) {
        if ((sec_r000117_10 & 2) != 0) {
            stage_v_122 = (pub_r000117_1 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000117_1 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000117_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
