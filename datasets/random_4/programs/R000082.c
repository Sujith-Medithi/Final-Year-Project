/*
 * Benchmark Program: R000082
 * Family: zero_leakage
 * Generator Seed: 408213
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000082_8213_0 {
    int tail;
    int checksum;
    int watermark;
    short capacity;
    unsigned char head;
    unsigned char state;
    int buffer[3];
};

struct EventLog_R000082_8213_1 {
    unsigned char seq;
    short timestamp;
    int severity;
    short code;
    int signature;
    short facility;
    int buffer[3];
};

union PacketPayload_R000082_8213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000082_8213_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_37) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_39 = local_arr[aux % 3];
    acc = (acc + window_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000082_8213_1(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_69 = local_arr[aux % 3];
    acc = (acc + accumulator_69 * 2) & 127;
    int segment_90 = 0;
    for (int k = 0; k < 3; k++) {
        segment_90 = (segment_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_2(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int window_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_39) & 63;
    acc ^= aux;
    int factor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_29 > 19) {
        acc = (acc + factor_29 * 2 + 5) & 127;
        aux ^= (factor_29 & 15);
    } else {
        acc = (acc - factor_29 + 11) & 127;
        aux += 3;
    }
    int scale_12 = (aux + st.buffer[1]) & 3;
    switch (scale_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_3(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int parity_95 = local_arr[aux % 3];
    acc = (acc + parity_95 * 2) & 127;
    int offset_77 = (aux + st.buffer[1]) & 3;
    switch (offset_77) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_4(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_14 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_14 > 18) {
        acc = (acc + scale_14 * 2 + 5) & 127;
        aux ^= (scale_14 & 15);
    } else {
        acc = (acc - scale_14 + 11) & 127;
        aux += 3;
    }
    int tally_66 = 0;
    for (int k = 0; k < 3; k++) {
        tally_66 = (tally_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_73 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_73 > 36) {
        acc = (acc + mask_73 * 2 + 5) & 127;
        aux ^= (mask_73 & 15);
    } else {
        acc = (acc - mask_73 + 11) & 127;
        aux += 3;
    }
    int tracker_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000082_8213_6(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_65 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_65 > 27) {
        acc = (acc + damping_65 * 2 + 5) & 127;
        aux ^= (damping_65 & 15);
    } else {
        acc = (acc - damping_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_42) & 63;
    acc ^= aux;
    int tally_32 = (aux + st.buffer[1]) & 3;
    switch (tally_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_8(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_80 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_80 > 11) {
        acc = (acc + cursor_80 * 2 + 5) & 127;
        aux ^= (cursor_80 & 15);
    } else {
        acc = (acc - cursor_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_13 = (aux + st.buffer[1]) & 3;
    switch (coefficient_13) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_9(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int residue_13 = local_arr[aux % 3];
    acc = (acc + residue_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000082_8213_10(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_33 = (aux + st.buffer[1]) & 3;
    switch (residue_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_46 = local_arr[aux % 3];
    acc = (acc + margin_46 * 2) & 127;
    int weight_24 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_24 > 23) {
        acc = (acc + weight_24 * 2 + 5) & 127;
        aux ^= (weight_24 & 15);
    } else {
        acc = (acc - weight_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_11(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int sample_71 = 0;
    for (int k = 0; k < 2; k++) {
        sample_71 = (sample_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_76 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_76 > 49) {
        acc = (acc + parity_76 * 2 + 5) & 127;
        aux ^= (parity_76 & 15);
    } else {
        acc = (acc - parity_76 + 11) & 127;
        aux += 3;
    }
    int coefficient_75 = (aux + st.buffer[1]) & 3;
    switch (coefficient_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_12(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_31 = (aux + st.buffer[1]) & 3;
    switch (mask_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_82 = 0;
    for (int k = 0; k < 2; k++) {
        offset_82 = (offset_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_82) & 127;
    }
    int weight_81 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_81 > 45) {
        acc = (acc + weight_81 * 2 + 5) & 127;
        aux ^= (weight_81 & 15);
    } else {
        acc = (acc - weight_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_13(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int bound_81 = 0;
    for (int k = 0; k < 3; k++) {
        bound_81 = (bound_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_81) & 127;
    }
    int parity_54 = (aux + st.buffer[1]) & 3;
    switch (parity_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000082_8213_14(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_61 = (aux + st.buffer[1]) & 3;
    switch (window_61) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_85 = local_arr[aux % 3];
    acc = (acc + factor_85 * 2) & 127;
    int tracker_97 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_97 > 49) {
        acc = (acc + tracker_97 * 2 + 5) & 127;
        aux ^= (tracker_97 & 15);
    } else {
        acc = (acc - tracker_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_15(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int threshold_96 = local_arr[aux % 3];
    acc = (acc + threshold_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_27 = 0;
    for (int k = 0; k < 3; k++) {
        margin_27 = (margin_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_27) & 127;
    }
    int checksum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_38 > 35) {
        acc = (acc + checksum_38 * 2 + 5) & 127;
        aux ^= (checksum_38 & 15);
    } else {
        acc = (acc - checksum_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_44 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_44 > 19) {
        acc = (acc + pivot_44 * 2 + 5) & 127;
        aux ^= (pivot_44 & 15);
    } else {
        acc = (acc - pivot_44 + 11) & 127;
        aux += 3;
    }
    int segment_59 = 0;
    for (int k = 0; k < 2; k++) {
        segment_59 = (segment_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_59) & 127;
    }
    int index_reg_95 = (aux + st.buffer[1]) & 3;
    switch (index_reg_95) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_17(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_34 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_34 = (cursor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_34) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_54 = local_arr[aux % 3];
    acc = (acc + vector_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000082_8213_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_45 = (aux + st.buffer[1]) & 3;
    switch (pivot_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_96 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_96 = (coefficient_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_96) & 127;
    }
    int factor_62 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_62 > 44) {
        acc = (acc + factor_62 * 2 + 5) & 127;
        aux ^= (factor_62 & 15);
    } else {
        acc = (acc - factor_62 + 11) & 127;
        aux += 3;
    }
    int anchor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000082_8213_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_91 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_91 > 35) {
        acc = (acc + metric_91 * 2 + 5) & 127;
        aux ^= (metric_91 & 15);
    } else {
        acc = (acc - metric_91 + 11) & 127;
        aux += 3;
    }
    int stride_66 = 0;
    for (int k = 0; k < 2; k++) {
        stride_66 = (stride_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000082_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_71 = local_arr[aux % 3];
    acc = (acc + window_71 * 2) & 127;
    int metric_38 = (aux + st.buffer[1]) & 3;
    switch (metric_38) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000082_8213_21(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000082_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_54) & 63;
    acc ^= aux;
    int vector_45 = 0;
    for (int k = 0; k < 3; k++) {
        vector_45 = (vector_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_45) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_69 = local_arr[aux % 3];
    acc = (acc + residue_69 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000082_0;
    int sec_r000082_1;
    int sec_r000082_2;
    int sec_r000082_3;
    int sec_r000082_4;
    int sec_r000082_5;
    int sec_r000082_6;
    int sec_r000082_7;
    int sec_r000082_8;
    int sec_r000082_9;
    int sec_r000082_10;
    int sec_r000082_11;
    int sec_r000082_12;
    int sec_r000082_13;
    int sec_r000082_14;
    int sec_r000082_15;
    int sec_r000082_16;
    int sec_r000082_17;
    int sec_r000082_18;
    int sec_r000082_19;
    int pub_r000082_0;
    int pub_r000082_1;
    int pub_r000082_2;
    int pub_r000082_3;
    int pub_r000082_4;
    int pub_r000082_5;
    int pub_r000082_6;
    int pub_r000082_7;
    int pub_r000082_8;
    int pub_r000082_9;
    int pub_r000082_10;
    int pub_r000082_11;
    int pub_r000082_12;
    int pub_r000082_13;
    int pub_r000082_14;
    int pub_r000082_15;
    int pub_r000082_16;
    int pub_r000082_17;
    int pub_r000082_18;
    int pub_r000082_19;
    int pub_r000082_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000082_0 >= -100 && pub_r000082_0 <= 100);
    __CPROVER_assume(pub_r000082_1 >= -100 && pub_r000082_1 <= 100);
    __CPROVER_assume(pub_r000082_2 >= -100 && pub_r000082_2 <= 100);
    __CPROVER_assume(pub_r000082_3 >= -100 && pub_r000082_3 <= 100);
    __CPROVER_assume(pub_r000082_4 >= -100 && pub_r000082_4 <= 100);
    __CPROVER_assume(pub_r000082_5 >= -100 && pub_r000082_5 <= 100);
    __CPROVER_assume(pub_r000082_6 >= -100 && pub_r000082_6 <= 100);
    __CPROVER_assume(pub_r000082_7 >= -100 && pub_r000082_7 <= 100);
    __CPROVER_assume(pub_r000082_8 >= -100 && pub_r000082_8 <= 100);
    __CPROVER_assume(pub_r000082_9 >= -100 && pub_r000082_9 <= 100);
    __CPROVER_assume(pub_r000082_10 >= -100 && pub_r000082_10 <= 100);
    __CPROVER_assume(pub_r000082_11 >= -100 && pub_r000082_11 <= 100);
    __CPROVER_assume(pub_r000082_12 >= -100 && pub_r000082_12 <= 100);
    __CPROVER_assume(pub_r000082_13 >= -100 && pub_r000082_13 <= 100);
    __CPROVER_assume(pub_r000082_14 >= -100 && pub_r000082_14 <= 100);
    __CPROVER_assume(pub_r000082_15 >= -100 && pub_r000082_15 <= 100);
    __CPROVER_assume(pub_r000082_16 >= -100 && pub_r000082_16 <= 100);
    __CPROVER_assume(pub_r000082_17 >= -100 && pub_r000082_17 <= 100);
    __CPROVER_assume(pub_r000082_18 >= -100 && pub_r000082_18 <= 100);
    __CPROVER_assume(pub_r000082_19 >= -100 && pub_r000082_19 <= 100);
    __CPROVER_assume(pub_r000082_20 >= -100 && pub_r000082_20 <= 100);
    __CPROVER_assume(sec_r000082_0 >= 0 && sec_r000082_0 <= 255);
    __CPROVER_assume(sec_r000082_1 >= 0 && sec_r000082_1 <= 255);
    __CPROVER_assume(sec_r000082_2 >= 0 && sec_r000082_2 <= 255);
    __CPROVER_assume(sec_r000082_3 >= 0 && sec_r000082_3 <= 255);
    __CPROVER_assume(sec_r000082_4 >= 0 && sec_r000082_4 <= 255);
    __CPROVER_assume(sec_r000082_5 >= 0 && sec_r000082_5 <= 255);
    __CPROVER_assume(sec_r000082_6 >= 0 && sec_r000082_6 <= 255);
    __CPROVER_assume(sec_r000082_7 >= 0 && sec_r000082_7 <= 255);
    __CPROVER_assume(sec_r000082_8 >= 0 && sec_r000082_8 <= 255);
    __CPROVER_assume(sec_r000082_9 >= 0 && sec_r000082_9 <= 255);
    __CPROVER_assume(sec_r000082_10 >= 0 && sec_r000082_10 <= 255);
    __CPROVER_assume(sec_r000082_11 >= 0 && sec_r000082_11 <= 255);
    __CPROVER_assume(sec_r000082_12 >= 0 && sec_r000082_12 <= 255);
    __CPROVER_assume(sec_r000082_13 >= 0 && sec_r000082_13 <= 255);
    __CPROVER_assume(sec_r000082_14 >= 0 && sec_r000082_14 <= 255);
    __CPROVER_assume(sec_r000082_15 >= 0 && sec_r000082_15 <= 255);
    __CPROVER_assume(sec_r000082_16 >= 0 && sec_r000082_16 <= 255);
    __CPROVER_assume(sec_r000082_17 >= 0 && sec_r000082_17 <= 255);
    __CPROVER_assume(sec_r000082_18 >= 0 && sec_r000082_18 <= 255);
    __CPROVER_assume(sec_r000082_19 >= 0 && sec_r000082_19 <= 255);

    struct StreamBuffer_R000082_8213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000082_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000082_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000082_0 + 7) & 15;
    struct EventLog_R000082_8213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000082_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000082_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000082_0 + 9) & 15;

    union PacketPayload_R000082_8213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 36) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 51) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

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
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 40) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 55) {
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 15) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 30) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 23) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 38) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 22) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 37) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
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
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 23) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 38) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

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
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 32) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 47) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 27) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 42) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 26) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 41) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 26) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 41) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 31) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 46) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 29) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 44) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
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

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 37) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 52) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_0.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_0.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 22) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 37) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 23) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 38) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_1.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 39) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 54) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 49) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_141 = (stage_v_141 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 143) & 15;
    int stage_v_142 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= stage_v_142;

    /* Execution Pipeline Stage 143 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[1] * 2 + 442) & 63;
    if (stage_v_145 > 33) {
        out_sink = (out_sink + stage_v_145 - 5) & 255;
        if (stage_v_145 > 48) {
            chk_sum ^= (stage_v_145 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_145 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 146 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_147 = (stage_v_147 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = table[3];
    table[3] = (table[0] + 311) & 63;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (out_sink > 100) ? (chk_sum & 31) : (161 & 31);
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= (stage_v_156 << 1) & 127;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 18) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 33) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 27) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 42) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 19) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 34) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_1.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 20) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 35) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] * 2 + 547) & 63;
    if (stage_v_180 > 10) {
        out_sink = (out_sink + stage_v_180 - 5) & 255;
        if (stage_v_180 > 25) {
            chk_sum ^= (stage_v_180 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_180 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[0] ^ 184) & 3;
    switch (stage_v_181) {
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

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_0.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_184 = (stage_v_184 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (out_sink > 100) ? (chk_sum & 31) : (190 & 31);
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= (stage_v_185 << 1) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (out_sink > 100) ? (chk_sum & 31) : (192 & 31);
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= (stage_v_187 << 1) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (out_sink > 100) ? (chk_sum & 31) : (194 & 31);
    out_sink = (out_sink + stage_v_189) & 255;
    chk_sum ^= (stage_v_189 << 1) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_0.buffer[0] ^ 193) & 3;
    switch (stage_v_190) {
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

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_191 = (stage_v_191 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_191) & 127;
    }
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] ^ 195) & 3;
    switch (stage_v_192) {
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

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Security Information Flow: Family = zero_leakage */
    int dead_sec_0 = ((sec_r000082_8 << 2) ^ (sec_r000082_8 << 2)) * 0;
    int dead_sec_1 = ((sec_r000082_13 + 15) - (sec_r000082_13 + 15)) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
