/*
 * Benchmark Program: R000248
 * Security Family: secret_dependent_loops
 * Generator Seed: 524813
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000248_4813_0 {
    short stop_bits;
    unsigned char id;
    unsigned char baud_rate;
    unsigned char parity;
    short timeout;
    int buffer[3];
};

struct StreamBuffer_R000248_4813_1 {
    short head;
    int state;
    int capacity;
    short watermark;
    int buffer[3];
};

struct Transaction_R000248_4813_2 {
    int account_id;
    int fee;
    unsigned char rate;
    int auth_code;
    int buffer[3];
};

struct CipherContext_R000248_4813_3 {
    int tag;
    int iv;
    int round_key;
    unsigned char nonce;
    int buffer[3];
};

union RegisterBank_R000248_4813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000248_4813_0(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000248_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_21 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_21 > 34) {
        acc = (acc + margin_21 * 2 + 5) & 127;
        aux ^= (margin_21 & 15);
    } else {
        acc = (acc - margin_21 + 11) & 127;
        aux += 3;
    }
    int cursor_37 = (aux + st.buffer[1]) & 3;
    switch (cursor_37) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_1(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int segment_41 = local_arr[aux % 3];
    acc = (acc + segment_41 * 2) & 127;
    int delta_52 = (aux + st.buffer[1]) & 3;
    switch (delta_52) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_87) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_58) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_15 = local_arr[aux % 3];
    acc = (acc + threshold_15 * 2) & 127;
    int threshold_22 = (aux + st.buffer[1]) & 3;
    switch (threshold_22) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000248_4813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000248_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int accumulator_76 = local_arr[aux % 3];
    acc = (acc + accumulator_76 * 2) & 127;
    int stride_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_47) & 63;
    acc ^= aux;
    int phase_14 = (aux + st.buffer[1]) & 3;
    switch (phase_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000248_4813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_48) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_44 = local_arr[aux % 3];
    acc = (acc + stride_44 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_28 = (aux + st.buffer[1]) & 3;
    switch (stride_28) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000248_4813_5(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int anchor_42 = local_arr[aux % 3];
    acc = (acc + anchor_42 * 2) & 127;
    int offset_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000248_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int coefficient_45 = local_arr[aux % 3];
    acc = (acc + coefficient_45 * 2) & 127;
    int window_91 = (st.buffer[0] * 3 + aux) & 63;
    if (window_91 > 49) {
        acc = (acc + window_91 * 2 + 5) & 127;
        aux ^= (window_91 & 15);
    } else {
        acc = (acc - window_91 + 11) & 127;
        aux += 3;
    }
    int parity_44 = (aux + st.buffer[1]) & 3;
    switch (parity_44) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000248_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int vector_90 = local_arr[aux % 3];
    acc = (acc + vector_90 * 2) & 127;
    int parity_50 = (aux + st.buffer[1]) & 3;
    switch (parity_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_8(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_88 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_88 > 46) {
        acc = (acc + residue_88 * 2 + 5) & 127;
        aux ^= (residue_88 & 15);
    } else {
        acc = (acc - residue_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_45 = local_arr[aux % 3];
    acc = (acc + metric_45 * 2) & 127;
    int stride_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000248_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int scale_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_82 = (aux + st.buffer[1]) & 3;
    switch (weight_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_30 = local_arr[aux % 3];
    acc = (acc + pivot_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_22 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_22 > 50) {
        acc = (acc + weight_22 * 2 + 5) & 127;
        aux ^= (weight_22 & 15);
    } else {
        acc = (acc - weight_22 + 11) & 127;
        aux += 3;
    }
    int offset_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_12(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000248_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_30 = (aux + st.buffer[1]) & 3;
    switch (tally_30) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_85 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_85 > 35) {
        acc = (acc + index_reg_85 * 2 + 5) & 127;
        aux ^= (index_reg_85 & 15);
    } else {
        acc = (acc - index_reg_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000248_4813_13(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_12 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_12 > 20) {
        acc = (acc + quantum_12 * 2 + 5) & 127;
        aux ^= (quantum_12 & 15);
    } else {
        acc = (acc - quantum_12 + 11) & 127;
        aux += 3;
    }
    int residue_55 = (aux + st.buffer[1]) & 3;
    switch (residue_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_14(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000248_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int delta_14 = local_arr[aux % 3];
    acc = (acc + delta_14 * 2) & 127;
    int checksum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_79) & 63;
    acc ^= aux;
    int tally_98 = (aux + st.buffer[1]) & 3;
    switch (tally_98) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000248_4813_15(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000248_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_80 = local_arr[aux % 3];
    acc = (acc + tally_80 * 2) & 127;
    int anchor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_82 > 20) {
        acc = (acc + anchor_82 * 2 + 5) & 127;
        aux ^= (anchor_82 & 15);
    } else {
        acc = (acc - anchor_82 + 11) & 127;
        aux += 3;
    }
    int parity_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000248_4813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000248_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_33 = (aux + st.buffer[1]) & 3;
    switch (margin_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_12 = local_arr[aux % 3];
    acc = (acc + parity_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_17(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000248_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int checksum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_77) & 63;
    acc ^= aux;
    int quotient_39 = (aux + st.buffer[1]) & 3;
    switch (quotient_39) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_40 = local_arr[aux % 3];
    acc = (acc + bound_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000248_4813_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000248_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_94 = (aux + st.buffer[1]) & 3;
    switch (anchor_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000248_0;
    int sec_r000248_1;
    int sec_r000248_2;
    int sec_r000248_3;
    int sec_r000248_4;
    int sec_r000248_5;
    int sec_r000248_6;
    int sec_r000248_7;
    int sec_r000248_8;
    int sec_r000248_9;
    int sec_r000248_10;
    int sec_r000248_11;
    int sec_r000248_12;
    int sec_r000248_13;
    int sec_r000248_14;
    int sec_r000248_15;
    int sec_r000248_16;
    int sec_r000248_17;
    int sec_r000248_18;
    int sec_r000248_19;
    int sec_r000248_20;
    int sec_r000248_21;
    int sec_r000248_22;
    int sec_r000248_23;
    int pub_r000248_0;
    int pub_r000248_1;
    int pub_r000248_2;
    int pub_r000248_3;
    int pub_r000248_4;
    int pub_r000248_5;
    int pub_r000248_6;
    int pub_r000248_7;
    int pub_r000248_8;
    int pub_r000248_9;
    int pub_r000248_10;
    int pub_r000248_11;
    int pub_r000248_12;
    int pub_r000248_13;
    int pub_r000248_14;
    int pub_r000248_15;
    int pub_r000248_16;
    int pub_r000248_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000248_0 >= -100 && pub_r000248_0 <= 100);
    __CPROVER_assume(pub_r000248_1 >= -100 && pub_r000248_1 <= 100);
    __CPROVER_assume(pub_r000248_2 >= -100 && pub_r000248_2 <= 100);
    __CPROVER_assume(pub_r000248_3 >= -100 && pub_r000248_3 <= 100);
    __CPROVER_assume(pub_r000248_4 >= -100 && pub_r000248_4 <= 100);
    __CPROVER_assume(pub_r000248_5 >= -100 && pub_r000248_5 <= 100);
    __CPROVER_assume(pub_r000248_6 >= -100 && pub_r000248_6 <= 100);
    __CPROVER_assume(pub_r000248_7 >= -100 && pub_r000248_7 <= 100);
    __CPROVER_assume(pub_r000248_8 >= -100 && pub_r000248_8 <= 100);
    __CPROVER_assume(pub_r000248_9 >= -100 && pub_r000248_9 <= 100);
    __CPROVER_assume(pub_r000248_10 >= -100 && pub_r000248_10 <= 100);
    __CPROVER_assume(pub_r000248_11 >= -100 && pub_r000248_11 <= 100);
    __CPROVER_assume(pub_r000248_12 >= -100 && pub_r000248_12 <= 100);
    __CPROVER_assume(pub_r000248_13 >= -100 && pub_r000248_13 <= 100);
    __CPROVER_assume(pub_r000248_14 >= -100 && pub_r000248_14 <= 100);
    __CPROVER_assume(pub_r000248_15 >= -100 && pub_r000248_15 <= 100);
    __CPROVER_assume(pub_r000248_16 >= -100 && pub_r000248_16 <= 100);
    __CPROVER_assume(pub_r000248_17 >= -100 && pub_r000248_17 <= 100);
    __CPROVER_assume(sec_r000248_0 >= 0 && sec_r000248_0 <= 255);
    __CPROVER_assume(sec_r000248_1 >= 0 && sec_r000248_1 <= 255);
    __CPROVER_assume(sec_r000248_2 >= 0 && sec_r000248_2 <= 255);
    __CPROVER_assume(sec_r000248_3 >= 0 && sec_r000248_3 <= 255);
    __CPROVER_assume(sec_r000248_4 >= 0 && sec_r000248_4 <= 255);
    __CPROVER_assume(sec_r000248_5 >= 0 && sec_r000248_5 <= 255);
    __CPROVER_assume(sec_r000248_6 >= 0 && sec_r000248_6 <= 255);
    __CPROVER_assume(sec_r000248_7 >= 0 && sec_r000248_7 <= 255);
    __CPROVER_assume(sec_r000248_8 >= 0 && sec_r000248_8 <= 255);
    __CPROVER_assume(sec_r000248_9 >= 0 && sec_r000248_9 <= 255);
    __CPROVER_assume(sec_r000248_10 >= 0 && sec_r000248_10 <= 255);
    __CPROVER_assume(sec_r000248_11 >= 0 && sec_r000248_11 <= 255);
    __CPROVER_assume(sec_r000248_12 >= 0 && sec_r000248_12 <= 255);
    __CPROVER_assume(sec_r000248_13 >= 0 && sec_r000248_13 <= 255);
    __CPROVER_assume(sec_r000248_14 >= 0 && sec_r000248_14 <= 255);
    __CPROVER_assume(sec_r000248_15 >= 0 && sec_r000248_15 <= 255);
    __CPROVER_assume(sec_r000248_16 >= 0 && sec_r000248_16 <= 255);
    __CPROVER_assume(sec_r000248_17 >= 0 && sec_r000248_17 <= 255);
    __CPROVER_assume(sec_r000248_18 >= 0 && sec_r000248_18 <= 255);
    __CPROVER_assume(sec_r000248_19 >= 0 && sec_r000248_19 <= 255);
    __CPROVER_assume(sec_r000248_20 >= 0 && sec_r000248_20 <= 255);
    __CPROVER_assume(sec_r000248_21 >= 0 && sec_r000248_21 <= 255);
    __CPROVER_assume(sec_r000248_22 >= 0 && sec_r000248_22 <= 255);
    __CPROVER_assume(sec_r000248_23 >= 0 && sec_r000248_23 <= 255);

    struct DeviceConfig_R000248_4813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000248_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000248_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000248_0 + 7) & 15;
    struct StreamBuffer_R000248_4813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000248_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000248_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000248_0 + 9) & 15;
    struct Transaction_R000248_4813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000248_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000248_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000248_0 + 11) & 15;
    struct CipherContext_R000248_4813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000248_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000248_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000248_0 + 13) & 15;

    union RegisterBank_R000248_4813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 19) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 34) {
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
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

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
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 14) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 29) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 20) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 35) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 35) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 50) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 19) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 34) {
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
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 14) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 29) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_13 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000248_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000248_13) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000248_3) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000248_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000248_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_4 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000248_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_9 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_22 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000248_0) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000248_9) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_9 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000248_9) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000248_12) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000248_14) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000248_12) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000248_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_7 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000248_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000248_13) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_16 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000248_13) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000248_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_21 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000248_10) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000248_5) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000248_3) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_0 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000248_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000248_5) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000248_9) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000248_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_22 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000248_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000248_12) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_23 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000248_2) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000248_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_5 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000248_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000248_10) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000248_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000248_3) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000248_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_23 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000248_1) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000248_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000248_5) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000248_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000248_14) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_9 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000248_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_17 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000248_13) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000248_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000248_2) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000248_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_4 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000248_15) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000248_3) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000248_10) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000248_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_23 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000248_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_10 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000248_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000248_11) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000248_5) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_3 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000248_16) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_12 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000248_0) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000248_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000248_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000248_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_13 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000248_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_21 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000248_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_13 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000248_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_21 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000248_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000248_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_127 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000248_9) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000248_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000248_15) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000248_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000248_8) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_3 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000248_14) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000248_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000248_17) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000248_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000248_3) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000248_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_135 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000248_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_4 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000248_2) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_1 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000248_5) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000248_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_0 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000248_0) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000248_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_5 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000248_12) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000248_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000248_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000248_14) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000248_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000248_4) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000248_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000248_7) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000248_15) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000248_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000248_11) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000248_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_138 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000248_10) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000248_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000248_1 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000248_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000248_6) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000248_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
