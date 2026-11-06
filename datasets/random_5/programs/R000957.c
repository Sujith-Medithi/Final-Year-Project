/*
 * Benchmark Program: R000957
 * Security Family: nested_implicit_flow
 * Generator Seed: 595713
 * High Inputs: 21 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000957_5713_0 {
    int gain;
    unsigned char reading;
    int offset;
    int calib;
    int status;
    int threshold;
    int buffer[3];
};

struct Transaction_R000957_5713_1 {
    unsigned char status;
    short balance;
    short fee;
    int auth_code;
    int account_id;
    int buffer[3];
};

struct CipherContext_R000957_5713_2 {
    int flags;
    int nonce;
    int tag;
    short iv;
    int round_key;
    short counter;
    int buffer[3];
};

union TelemetryField_R000957_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000957_5713_0(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_72 = local_arr[aux % 3];
    acc = (acc + checksum_72 * 2) & 127;
    int threshold_24 = (aux + st.buffer[1]) & 3;
    switch (threshold_24) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_83 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_83 > 49) {
        acc = (acc + mask_83 * 2 + 5) & 127;
        aux ^= (mask_83 & 15);
    } else {
        acc = (acc - mask_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_33) & 63;
    acc ^= aux;
    int mask_58 = (aux + st.buffer[1]) & 3;
    switch (mask_58) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_85 = local_arr[aux % 3];
    acc = (acc + factor_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_3(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int sample_82 = local_arr[aux % 3];
    acc = (acc + sample_82 * 2) & 127;
    int checksum_84 = (aux + st.buffer[1]) & 3;
    switch (checksum_84) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_4(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_73 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_73 > 32) {
        acc = (acc + factor_73 * 2 + 5) & 127;
        aux ^= (factor_73 & 15);
    } else {
        acc = (acc - factor_73 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_98 = local_arr[aux % 3];
    acc = (acc + accumulator_98 * 2) & 127;
    int weight_97 = (aux + st.buffer[1]) & 3;
    switch (weight_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quotient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_10) & 63;
    acc ^= aux;
    int quotient_75 = (aux + st.buffer[1]) & 3;
    switch (quotient_75) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_86 = local_arr[aux % 3];
    acc = (acc + tracker_86 * 2) & 127;
    int cursor_74 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_74 > 25) {
        acc = (acc + cursor_74 * 2 + 5) & 127;
        aux ^= (cursor_74 & 15);
    } else {
        acc = (acc - cursor_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_91 = local_arr[aux % 3];
    acc = (acc + phase_91 * 2) & 127;
    int metric_47 = (aux + st.buffer[1]) & 3;
    switch (metric_47) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_7(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_98 = (aux + st.buffer[1]) & 3;
    switch (segment_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_93 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_93 > 45) {
        acc = (acc + scale_93 * 2 + 5) & 127;
        aux ^= (scale_93 & 15);
    } else {
        acc = (acc - scale_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_8(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_75 = (aux + st.buffer[1]) & 3;
    switch (cursor_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_87 = local_arr[aux % 3];
    acc = (acc + coefficient_87 * 2) & 127;
    int tally_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_22 > 47) {
        acc = (acc + tally_22 * 2 + 5) & 127;
        aux ^= (tally_22 & 15);
    } else {
        acc = (acc - tally_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_9(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int bound_33 = local_arr[aux % 3];
    acc = (acc + bound_33 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int segment_10 = (aux + st.buffer[1]) & 3;
    switch (segment_10) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_11(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int window_83 = local_arr[aux % 3];
    acc = (acc + window_83 * 2) & 127;
    int margin_76 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_76 > 11) {
        acc = (acc + margin_76 * 2 + 5) & 127;
        aux ^= (margin_76 & 15);
    } else {
        acc = (acc - margin_76 + 11) & 127;
        aux += 3;
    }
    int index_reg_15 = (aux + st.buffer[1]) & 3;
    switch (index_reg_15) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_12(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int pivot_92 = (aux + st.buffer[1]) & 3;
    switch (pivot_92) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_33 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_33 > 44) {
        acc = (acc + bound_33 * 2 + 5) & 127;
        aux ^= (bound_33 & 15);
    } else {
        acc = (acc - bound_33 + 11) & 127;
        aux += 3;
    }
    int tally_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_80 = local_arr[aux % 3];
    acc = (acc + scale_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_13(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int coefficient_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_83) & 63;
    acc ^= aux;
    int anchor_43 = (aux + st.buffer[1]) & 3;
    switch (anchor_43) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_78 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_78 > 15) {
        acc = (acc + offset_78 * 2 + 5) & 127;
        aux ^= (offset_78 & 15);
    } else {
        acc = (acc - offset_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_86 = local_arr[aux % 3];
    acc = (acc + scale_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_23 = local_arr[aux % 3];
    acc = (acc + factor_23 * 2) & 127;
    int vector_20 = (aux + st.buffer[1]) & 3;
    switch (vector_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_97) & 63;
    acc ^= aux;
    int factor_42 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_42 > 27) {
        acc = (acc + factor_42 * 2 + 5) & 127;
        aux ^= (factor_42 & 15);
    } else {
        acc = (acc - factor_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_16(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int scale_66 = local_arr[aux % 3];
    acc = (acc + scale_66 * 2) & 127;
    int metric_77 = (aux + st.buffer[1]) & 3;
    switch (metric_77) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_78 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_78 > 40) {
        acc = (acc + stride_78 * 2 + 5) & 127;
        aux ^= (stride_78 & 15);
    } else {
        acc = (acc - stride_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_17(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000957_5713_18(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_19 = (aux + st.buffer[1]) & 3;
    switch (scale_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_61 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_61 > 36) {
        acc = (acc + stride_61 * 2 + 5) & 127;
        aux ^= (stride_61 & 15);
    } else {
        acc = (acc - stride_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_90 = local_arr[aux % 3];
    acc = (acc + threshold_90 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_19(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_56 = (aux + st.buffer[1]) & 3;
    switch (threshold_56) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_23 = local_arr[aux % 3];
    acc = (acc + bound_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_86 = (aux + st.buffer[1]) & 3;
    switch (threshold_86) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_92 = local_arr[aux % 3];
    acc = (acc + quotient_92 * 2) & 127;
    int vector_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000957_0;
    int sec_r000957_1;
    int sec_r000957_2;
    int sec_r000957_3;
    int sec_r000957_4;
    int sec_r000957_5;
    int sec_r000957_6;
    int sec_r000957_7;
    int sec_r000957_8;
    int sec_r000957_9;
    int sec_r000957_10;
    int sec_r000957_11;
    int sec_r000957_12;
    int sec_r000957_13;
    int sec_r000957_14;
    int sec_r000957_15;
    int sec_r000957_16;
    int sec_r000957_17;
    int sec_r000957_18;
    int sec_r000957_19;
    int sec_r000957_20;
    int pub_r000957_0;
    int pub_r000957_1;
    int pub_r000957_2;
    int pub_r000957_3;
    int pub_r000957_4;
    int pub_r000957_5;
    int pub_r000957_6;
    int pub_r000957_7;
    int pub_r000957_8;
    int pub_r000957_9;
    int pub_r000957_10;
    int pub_r000957_11;
    int pub_r000957_12;
    int pub_r000957_13;
    int pub_r000957_14;
    int pub_r000957_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000957_0 >= -100 && pub_r000957_0 <= 100);
    __CPROVER_assume(pub_r000957_1 >= -100 && pub_r000957_1 <= 100);
    __CPROVER_assume(pub_r000957_2 >= -100 && pub_r000957_2 <= 100);
    __CPROVER_assume(pub_r000957_3 >= -100 && pub_r000957_3 <= 100);
    __CPROVER_assume(pub_r000957_4 >= -100 && pub_r000957_4 <= 100);
    __CPROVER_assume(pub_r000957_5 >= -100 && pub_r000957_5 <= 100);
    __CPROVER_assume(pub_r000957_6 >= -100 && pub_r000957_6 <= 100);
    __CPROVER_assume(pub_r000957_7 >= -100 && pub_r000957_7 <= 100);
    __CPROVER_assume(pub_r000957_8 >= -100 && pub_r000957_8 <= 100);
    __CPROVER_assume(pub_r000957_9 >= -100 && pub_r000957_9 <= 100);
    __CPROVER_assume(pub_r000957_10 >= -100 && pub_r000957_10 <= 100);
    __CPROVER_assume(pub_r000957_11 >= -100 && pub_r000957_11 <= 100);
    __CPROVER_assume(pub_r000957_12 >= -100 && pub_r000957_12 <= 100);
    __CPROVER_assume(pub_r000957_13 >= -100 && pub_r000957_13 <= 100);
    __CPROVER_assume(pub_r000957_14 >= -100 && pub_r000957_14 <= 100);
    __CPROVER_assume(pub_r000957_15 >= -100 && pub_r000957_15 <= 100);
    __CPROVER_assume(sec_r000957_0 >= 0 && sec_r000957_0 <= 255);
    __CPROVER_assume(sec_r000957_1 >= 0 && sec_r000957_1 <= 255);
    __CPROVER_assume(sec_r000957_2 >= 0 && sec_r000957_2 <= 255);
    __CPROVER_assume(sec_r000957_3 >= 0 && sec_r000957_3 <= 255);
    __CPROVER_assume(sec_r000957_4 >= 0 && sec_r000957_4 <= 255);
    __CPROVER_assume(sec_r000957_5 >= 0 && sec_r000957_5 <= 255);
    __CPROVER_assume(sec_r000957_6 >= 0 && sec_r000957_6 <= 255);
    __CPROVER_assume(sec_r000957_7 >= 0 && sec_r000957_7 <= 255);
    __CPROVER_assume(sec_r000957_8 >= 0 && sec_r000957_8 <= 255);
    __CPROVER_assume(sec_r000957_9 >= 0 && sec_r000957_9 <= 255);
    __CPROVER_assume(sec_r000957_10 >= 0 && sec_r000957_10 <= 255);
    __CPROVER_assume(sec_r000957_11 >= 0 && sec_r000957_11 <= 255);
    __CPROVER_assume(sec_r000957_12 >= 0 && sec_r000957_12 <= 255);
    __CPROVER_assume(sec_r000957_13 >= 0 && sec_r000957_13 <= 255);
    __CPROVER_assume(sec_r000957_14 >= 0 && sec_r000957_14 <= 255);
    __CPROVER_assume(sec_r000957_15 >= 0 && sec_r000957_15 <= 255);
    __CPROVER_assume(sec_r000957_16 >= 0 && sec_r000957_16 <= 255);
    __CPROVER_assume(sec_r000957_17 >= 0 && sec_r000957_17 <= 255);
    __CPROVER_assume(sec_r000957_18 >= 0 && sec_r000957_18 <= 255);
    __CPROVER_assume(sec_r000957_19 >= 0 && sec_r000957_19 <= 255);
    __CPROVER_assume(sec_r000957_20 >= 0 && sec_r000957_20 <= 255);

    struct SensorNode_R000957_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000957_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000957_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000957_0 + 7) & 15;
    struct Transaction_R000957_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000957_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000957_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000957_0 + 9) & 15;
    struct CipherContext_R000957_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000957_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000957_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000957_0 + 11) & 15;

    union TelemetryField_R000957_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 16) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 31) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 21) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 36) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
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
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 20) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 35) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

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
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
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
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 26) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 41) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
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
    if (stage_v_42 > 30) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 45) {
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
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

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
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 27) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 42) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 33) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 48) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 23) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 38) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 38) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 53) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000957_0 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_64 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000957_18 & 1) != 0) {
        if ((sec_r000957_16 & 2) != 0) {
            stage_v_65 = (pub_r000957_1 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000957_1 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000957_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000957_19 & 1) != 0) {
        if ((sec_r000957_6 & 2) != 0) {
            stage_v_66 = (pub_r000957_12 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000957_12 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000957_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000957_9 & 2) != 0) {
            stage_v_67 = (pub_r000957_1 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000957_1 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000957_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000957_11 & 1) != 0) {
        if ((sec_r000957_3 & 2) != 0) {
            stage_v_68 = (pub_r000957_8 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000957_8 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000957_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000957_10 & 1) != 0) {
        if ((sec_r000957_15 & 2) != 0) {
            stage_v_69 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000957_19 & 1) != 0) {
        if ((sec_r000957_7 & 2) != 0) {
            stage_v_70 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000957_11 & 1) != 0) {
        if ((sec_r000957_11 & 2) != 0) {
            stage_v_71 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000957_2 & 2) != 0) {
            stage_v_72 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000957_18 & 1) != 0) {
        if ((sec_r000957_2 & 2) != 0) {
            stage_v_73 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000957_0 & 2) != 0) {
            stage_v_74 = (pub_r000957_6 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000957_6 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000957_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_75 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_76 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000957_7 & 2) != 0) {
            stage_v_77 = (pub_r000957_7 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000957_7 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000957_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000957_13 & 2) != 0) {
            stage_v_78 = (pub_r000957_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000957_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000957_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000957_20 & 2) != 0) {
            stage_v_79 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000957_10 & 1) != 0) {
        if ((sec_r000957_9 & 2) != 0) {
            stage_v_80 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000957_17 & 1) != 0) {
        if ((sec_r000957_11 & 2) != 0) {
            stage_v_81 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000957_8 & 2) != 0) {
            stage_v_82 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000957_1 & 1) != 0) {
        if ((sec_r000957_15 & 2) != 0) {
            stage_v_83 = (pub_r000957_8 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000957_8 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000957_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000957_7 & 2) != 0) {
            stage_v_84 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_85 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000957_5 & 1) != 0) {
        if ((sec_r000957_5 & 2) != 0) {
            stage_v_86 = (pub_r000957_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000957_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000957_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000957_7 & 2) != 0) {
            stage_v_87 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000957_10 & 2) != 0) {
            stage_v_88 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000957_6 & 1) != 0) {
        if ((sec_r000957_16 & 2) != 0) {
            stage_v_89 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000957_12 & 1) != 0) {
        if ((sec_r000957_2 & 2) != 0) {
            stage_v_90 = (pub_r000957_14 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000957_14 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000957_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000957_7 & 2) != 0) {
            stage_v_91 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000957_1 & 1) != 0) {
        if ((sec_r000957_9 & 2) != 0) {
            stage_v_92 = (pub_r000957_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000957_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000957_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000957_2 & 2) != 0) {
            stage_v_93 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_94 = (pub_r000957_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000957_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000957_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000957_5 & 2) != 0) {
            stage_v_95 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000957_5 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_96 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000957_14 & 1) != 0) {
        if ((sec_r000957_12 & 2) != 0) {
            stage_v_97 = (pub_r000957_12 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000957_12 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000957_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000957_6 & 2) != 0) {
            stage_v_98 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000957_17 & 2) != 0) {
            stage_v_99 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000957_6 & 1) != 0) {
        if ((sec_r000957_14 & 2) != 0) {
            stage_v_100 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000957_8 & 1) != 0) {
        if ((sec_r000957_10 & 2) != 0) {
            stage_v_101 = (pub_r000957_0 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000957_0 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000957_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000957_3 & 2) != 0) {
            stage_v_102 = (pub_r000957_14 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000957_14 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000957_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_103 = (pub_r000957_3 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000957_3 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000957_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000957_16 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_104 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000957_12 & 2) != 0) {
            stage_v_105 = (pub_r000957_8 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000957_8 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000957_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000957_13 & 2) != 0) {
            stage_v_106 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000957_8 & 1) != 0) {
        if ((sec_r000957_12 & 2) != 0) {
            stage_v_107 = (pub_r000957_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000957_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000957_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000957_18 & 1) != 0) {
        if ((sec_r000957_14 & 2) != 0) {
            stage_v_108 = (pub_r000957_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000957_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000957_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000957_15 & 2) != 0) {
            stage_v_109 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000957_10 & 1) != 0) {
        if ((sec_r000957_1 & 2) != 0) {
            stage_v_110 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000957_11 & 2) != 0) {
            stage_v_111 = (pub_r000957_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000957_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000957_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000957_15 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_112 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000957_11 & 2) != 0) {
            stage_v_113 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000957_16 & 1) != 0) {
        if ((sec_r000957_12 & 2) != 0) {
            stage_v_114 = (pub_r000957_13 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000957_13 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000957_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000957_5 & 2) != 0) {
            stage_v_115 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000957_9 & 2) != 0) {
            stage_v_116 = (pub_r000957_11 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000957_11 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000957_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000957_4 & 2) != 0) {
            stage_v_117 = (pub_r000957_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000957_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000957_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000957_0 & 2) != 0) {
            stage_v_118 = (pub_r000957_12 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000957_12 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000957_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000957_6 & 2) != 0) {
            stage_v_119 = (pub_r000957_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000957_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000957_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000957_4 & 1) != 0) {
        if ((sec_r000957_8 & 2) != 0) {
            stage_v_120 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000957_16 & 2) != 0) {
            stage_v_121 = (pub_r000957_0 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000957_0 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000957_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000957_14 & 1) != 0) {
        if ((sec_r000957_4 & 2) != 0) {
            stage_v_122 = (pub_r000957_13 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000957_13 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000957_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000957_16 & 2) != 0) {
            stage_v_123 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000957_0 & 2) != 0) {
            stage_v_124 = (pub_r000957_13 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000957_13 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000957_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000957_2 & 1) != 0) {
        if ((sec_r000957_5 & 2) != 0) {
            stage_v_125 = (pub_r000957_0 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000957_0 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000957_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000957_10 & 2) != 0) {
            stage_v_126 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_127 = (pub_r000957_13 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000957_13 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000957_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000957_20 & 2) != 0) {
            stage_v_128 = (pub_r000957_7 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000957_7 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000957_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000957_10 & 2) != 0) {
            stage_v_129 = (pub_r000957_7 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000957_7 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000957_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000957_11 & 2) != 0) {
            stage_v_130 = (pub_r000957_15 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000957_15 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000957_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000957_8 & 1) != 0) {
        if ((sec_r000957_14 & 2) != 0) {
            stage_v_131 = (pub_r000957_8 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000957_8 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000957_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000957_19 & 2) != 0) {
            stage_v_132 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000957_2 & 2) != 0) {
            stage_v_133 = (pub_r000957_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000957_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000957_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000957_0 & 2) != 0) {
            stage_v_134 = (pub_r000957_5 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000957_5 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000957_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000957_13 & 2) != 0) {
            stage_v_135 = (pub_r000957_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000957_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000957_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000957_18 & 2) != 0) {
            stage_v_136 = (pub_r000957_9 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000957_9 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000957_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
