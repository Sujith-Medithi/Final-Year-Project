/*
 * Benchmark Program: R001039
 * Security Family: secret_dependent_array
 * Generator Seed: 603913
 * High Inputs: 18 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001039_3913_0 {
    int iv;
    short round_key;
    unsigned char nonce;
    int tag;
    short counter;
    int buffer[3];
};

struct AudioFrame_R001039_3913_1 {
    int sample_rate;
    int rms;
    unsigned char envelope;
    int buffer[3];
};

struct FilterState_R001039_3913_2 {
    int prev_in;
    int gain_db;
    unsigned char cutoff;
    short mode;
    int buffer[3];
};

struct Transaction_R001039_3913_3 {
    int balance;
    unsigned char rate;
    int account_id;
    int buffer[3];
};

union PacketPayload_R001039_3913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001039_3913_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001039_3913_0(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001039_3913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int sample_20 = (aux + st.buffer[1]) & 3;
    switch (sample_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_34 = 0;
    for (int k = 0; k < 2; k++) {
        mask_34 = (mask_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_34) & 127;
    }
    int factor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_61 > 33) {
        acc = (acc + factor_61 * 2 + 5) & 127;
        aux ^= (factor_61 & 15);
    } else {
        acc = (acc - factor_61 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_93 = local_arr[aux % 3];
    acc = (acc + margin_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001039_3913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int metric_23 = local_arr[aux % 3];
    acc = (acc + metric_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int weight_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_25 = local_arr[aux % 3];
    acc = (acc + bound_25 * 2) & 127;
    int index_reg_27 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_27 > 25) {
        acc = (acc + index_reg_27 * 2 + 5) & 127;
        aux ^= (index_reg_27 & 15);
    } else {
        acc = (acc - index_reg_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int stride_48 = local_arr[aux % 3];
    acc = (acc + stride_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_59) & 63;
    acc ^= aux;
    int cursor_81 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_81 > 32) {
        acc = (acc + cursor_81 * 2 + 5) & 127;
        aux ^= (cursor_81 & 15);
    } else {
        acc = (acc - cursor_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_5(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001039_3913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_97 = (aux + st.buffer[1]) & 3;
    switch (parity_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_41 > 44) {
        acc = (acc + cursor_41 * 2 + 5) & 127;
        aux ^= (cursor_41 & 15);
    } else {
        acc = (acc - cursor_41 + 11) & 127;
        aux += 3;
    }
    int quotient_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001039_3913_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_79 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_79 > 35) {
        acc = (acc + threshold_79 * 2 + 5) & 127;
        aux ^= (threshold_79 & 15);
    } else {
        acc = (acc - threshold_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_64 = local_arr[aux % 3];
    acc = (acc + mask_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001039_3913_7(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_68) & 63;
    acc ^= aux;
    int scale_18 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_18 > 40) {
        acc = (acc + scale_18 * 2 + 5) & 127;
        aux ^= (scale_18 & 15);
    } else {
        acc = (acc - scale_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_13 = local_arr[aux % 3];
    acc = (acc + checksum_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001039_3913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int offset_80 = 0;
    for (int k = 0; k < 2; k++) {
        offset_80 = (offset_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_80) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_48 = local_arr[aux % 3];
    acc = (acc + anchor_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_54 = 0;
    for (int k = 0; k < 3; k++) {
        delta_54 = (delta_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_54) & 127;
    }
    int checksum_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_41) & 63;
    acc ^= aux;
    int damping_56 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_56 > 43) {
        acc = (acc + damping_56 * 2 + 5) & 127;
        aux ^= (damping_56 & 15);
    } else {
        acc = (acc - damping_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001039_3913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_79 > 25) {
        acc = (acc + cursor_79 * 2 + 5) & 127;
        aux ^= (cursor_79 & 15);
    } else {
        acc = (acc - cursor_79 + 11) & 127;
        aux += 3;
    }
    int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001039_3913_11(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001039_3913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int metric_98 = local_arr[aux % 3];
    acc = (acc + metric_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_12(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001039_3913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int pivot_82 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_82 > 35) {
        acc = (acc + pivot_82 * 2 + 5) & 127;
        aux ^= (pivot_82 & 15);
    } else {
        acc = (acc - pivot_82 + 11) & 127;
        aux += 3;
    }
    int cursor_37 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_37 = (cursor_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_37) & 127;
    }
    int residue_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001039_3913_13(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int metric_70 = local_arr[aux % 3];
    acc = (acc + metric_70 * 2) & 127;
    int scale_64 = 0;
    for (int k = 0; k < 2; k++) {
        scale_64 = (scale_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001039_3913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_95 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_95 > 20) {
        acc = (acc + tracker_95 * 2 + 5) & 127;
        aux ^= (tracker_95 & 15);
    } else {
        acc = (acc - tracker_95 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001039_3913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int tracker_28 = local_arr[aux % 3];
    acc = (acc + tracker_28 * 2) & 127;
    int stride_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_47) & 63;
    acc ^= aux;
    int residue_73 = 0;
    for (int k = 0; k < 3; k++) {
        residue_73 = (residue_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_16(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int factor_98 = local_arr[aux % 3];
    acc = (acc + factor_98 * 2) & 127;
    int phase_59 = (aux + st.buffer[1]) & 3;
    switch (phase_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_93 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_93 > 17) {
        acc = (acc + vector_93 * 2 + 5) & 127;
        aux ^= (vector_93 & 15);
    } else {
        acc = (acc - vector_93 + 11) & 127;
        aux += 3;
    }
    int cursor_52 = (aux + st.buffer[1]) & 3;
    switch (cursor_52) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001039_3913_18(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001039_3913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_42 = local_arr[aux % 3];
    acc = (acc + cursor_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001039_3913_19(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001039_3913_20(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001039_3913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_47 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_47 > 22) {
        acc = (acc + residue_47 * 2 + 5) & 127;
        aux ^= (residue_47 & 15);
    } else {
        acc = (acc - residue_47 + 11) & 127;
        aux += 3;
    }
    int segment_18 = (aux + st.buffer[1]) & 3;
    switch (segment_18) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_88 = local_arr[aux % 3];
    acc = (acc + tracker_88 * 2) & 127;
    int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001039_0;
    int sec_r001039_1;
    int sec_r001039_2;
    int sec_r001039_3;
    int sec_r001039_4;
    int sec_r001039_5;
    int sec_r001039_6;
    int sec_r001039_7;
    int sec_r001039_8;
    int sec_r001039_9;
    int sec_r001039_10;
    int sec_r001039_11;
    int sec_r001039_12;
    int sec_r001039_13;
    int sec_r001039_14;
    int sec_r001039_15;
    int sec_r001039_16;
    int sec_r001039_17;
    int pub_r001039_0;
    int pub_r001039_1;
    int pub_r001039_2;
    int pub_r001039_3;
    int pub_r001039_4;
    int pub_r001039_5;
    int pub_r001039_6;
    int pub_r001039_7;
    int pub_r001039_8;
    int pub_r001039_9;
    int pub_r001039_10;
    int pub_r001039_11;
    int pub_r001039_12;
    int pub_r001039_13;
    int pub_r001039_14;
    int pub_r001039_15;
    int pub_r001039_16;
    int pub_r001039_17;
    int pub_r001039_18;
    int pub_r001039_19;
    int pub_r001039_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001039_0 >= -100 && pub_r001039_0 <= 100);
    __CPROVER_assume(pub_r001039_1 >= -100 && pub_r001039_1 <= 100);
    __CPROVER_assume(pub_r001039_2 >= -100 && pub_r001039_2 <= 100);
    __CPROVER_assume(pub_r001039_3 >= -100 && pub_r001039_3 <= 100);
    __CPROVER_assume(pub_r001039_4 >= -100 && pub_r001039_4 <= 100);
    __CPROVER_assume(pub_r001039_5 >= -100 && pub_r001039_5 <= 100);
    __CPROVER_assume(pub_r001039_6 >= -100 && pub_r001039_6 <= 100);
    __CPROVER_assume(pub_r001039_7 >= -100 && pub_r001039_7 <= 100);
    __CPROVER_assume(pub_r001039_8 >= -100 && pub_r001039_8 <= 100);
    __CPROVER_assume(pub_r001039_9 >= -100 && pub_r001039_9 <= 100);
    __CPROVER_assume(pub_r001039_10 >= -100 && pub_r001039_10 <= 100);
    __CPROVER_assume(pub_r001039_11 >= -100 && pub_r001039_11 <= 100);
    __CPROVER_assume(pub_r001039_12 >= -100 && pub_r001039_12 <= 100);
    __CPROVER_assume(pub_r001039_13 >= -100 && pub_r001039_13 <= 100);
    __CPROVER_assume(pub_r001039_14 >= -100 && pub_r001039_14 <= 100);
    __CPROVER_assume(pub_r001039_15 >= -100 && pub_r001039_15 <= 100);
    __CPROVER_assume(pub_r001039_16 >= -100 && pub_r001039_16 <= 100);
    __CPROVER_assume(pub_r001039_17 >= -100 && pub_r001039_17 <= 100);
    __CPROVER_assume(pub_r001039_18 >= -100 && pub_r001039_18 <= 100);
    __CPROVER_assume(pub_r001039_19 >= -100 && pub_r001039_19 <= 100);
    __CPROVER_assume(pub_r001039_20 >= -100 && pub_r001039_20 <= 100);
    __CPROVER_assume(sec_r001039_0 >= 0 && sec_r001039_0 <= 255);
    __CPROVER_assume(sec_r001039_1 >= 0 && sec_r001039_1 <= 255);
    __CPROVER_assume(sec_r001039_2 >= 0 && sec_r001039_2 <= 255);
    __CPROVER_assume(sec_r001039_3 >= 0 && sec_r001039_3 <= 255);
    __CPROVER_assume(sec_r001039_4 >= 0 && sec_r001039_4 <= 255);
    __CPROVER_assume(sec_r001039_5 >= 0 && sec_r001039_5 <= 255);
    __CPROVER_assume(sec_r001039_6 >= 0 && sec_r001039_6 <= 255);
    __CPROVER_assume(sec_r001039_7 >= 0 && sec_r001039_7 <= 255);
    __CPROVER_assume(sec_r001039_8 >= 0 && sec_r001039_8 <= 255);
    __CPROVER_assume(sec_r001039_9 >= 0 && sec_r001039_9 <= 255);
    __CPROVER_assume(sec_r001039_10 >= 0 && sec_r001039_10 <= 255);
    __CPROVER_assume(sec_r001039_11 >= 0 && sec_r001039_11 <= 255);
    __CPROVER_assume(sec_r001039_12 >= 0 && sec_r001039_12 <= 255);
    __CPROVER_assume(sec_r001039_13 >= 0 && sec_r001039_13 <= 255);
    __CPROVER_assume(sec_r001039_14 >= 0 && sec_r001039_14 <= 255);
    __CPROVER_assume(sec_r001039_15 >= 0 && sec_r001039_15 <= 255);
    __CPROVER_assume(sec_r001039_16 >= 0 && sec_r001039_16 <= 255);
    __CPROVER_assume(sec_r001039_17 >= 0 && sec_r001039_17 <= 255);

    struct CipherContext_R001039_3913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001039_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001039_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001039_0 + 7) & 15;
    struct AudioFrame_R001039_3913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001039_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001039_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001039_0 + 9) & 15;
    struct FilterState_R001039_3913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001039_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001039_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001039_0 + 11) & 15;
    struct Transaction_R001039_3913_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001039_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001039_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001039_0 + 13) & 15;

    union PacketPayload_R001039_3913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001039_3913_0(sec_r001039_0, pub_r001039_1);
    int helper_flow_1 = fn_R001039_3913_1(sec_r001039_1, sec_r001039_2, pub_r001039_3, pub_r001039_4, pub_r001039_5);
    int helper_flow_2 = fn_R001039_3913_2(sec_r001039_2, sec_r001039_3, pub_r001039_4, pub_r001039_5);
    int helper_flow_3 = fn_R001039_3913_3(sec_r001039_3, pub_r001039_4, pub_r001039_5, pub_r001039_6);
    int helper_flow_4 = fn_R001039_3913_4(sec_r001039_4, sec_r001039_5, pub_r001039_6, pub_r001039_7);
    int helper_flow_5 = fn_R001039_3913_5(sec_r001039_5, pub_r001039_6);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0] + (sec_r001039_8 & 7);
    table[0] = (stage_v_0 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_0 & 127);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001039_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001039_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001039_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0] + (sec_r001039_13 & 7);
    table[0] = (stage_v_4 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_4 & 127);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001039_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001039_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3] + (helper_flow_0 & 7);
    table[3] = (stage_v_7 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_7 & 127);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001039_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001039_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2] + (sec_r001039_5 & 7);
    table[2] = (stage_v_10 + pub_r001039_19) & 63;
    out_sink ^= (stage_v_10 & 127);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001039_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0] + (sec_r001039_13 & 7);
    table[0] = (stage_v_12 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_12 & 127);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001039_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001039_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3] + (helper_flow_4 & 7);
    table[3] = (stage_v_15 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_15 & 127);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001039_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001039_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2] + (helper_flow_1 & 7);
    table[2] = (stage_v_18 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_18 & 127);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3] + (stage_v_10 & 7);
    table[3] = (stage_v_19 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_19 & 127);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001039_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001039_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2] + (sec_r001039_9 & 7);
    table[2] = (stage_v_22 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_22 & 127);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001039_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001039_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001039_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001039_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001039_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001039_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001039_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001039_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001039_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0] + (helper_flow_5 & 7);
    table[0] = (stage_v_32 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_32 & 127);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1] + (sec_r001039_8 & 7);
    table[1] = (stage_v_33 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_33 & 127);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001039_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3] + (sec_r001039_2 & 7);
    table[3] = (stage_v_35 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_35 & 127);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0] + (sec_r001039_7 & 7);
    table[0] = (stage_v_36 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_36 & 127);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1] + (helper_flow_5 & 7);
    table[1] = (stage_v_37 + pub_r001039_14) & 63;
    out_sink ^= (stage_v_37 & 127);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001039_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3] + (stage_v_0 & 7);
    table[3] = (stage_v_39 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_39 & 127);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001039_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1] + (stage_v_4 & 7);
    table[1] = (stage_v_41 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_41 & 127);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2] + (sec_r001039_6 & 7);
    table[2] = (stage_v_42 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_42 & 127);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3] + (helper_flow_5 & 7);
    table[3] = (stage_v_43 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_43 & 127);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001039_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001039_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2] + (helper_flow_2 & 7);
    table[2] = (stage_v_46 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_46 & 127);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3] + (helper_flow_2 & 7);
    table[3] = (stage_v_47 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_47 & 127);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0] + (sec_r001039_10 & 7);
    table[0] = (stage_v_48 + pub_r001039_19) & 63;
    out_sink ^= (stage_v_48 & 127);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1] + (stage_v_32 & 7);
    table[1] = (stage_v_49 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_49 & 127);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001039_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001039_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0] + (sec_r001039_10 & 7);
    table[0] = (stage_v_52 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_52 & 127);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001039_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001039_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001039_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001039_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001039_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001039_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3] + (stage_v_4 & 7);
    table[3] = (stage_v_59 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_59 & 127);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001039_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001039_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001039_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001039_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0] + (helper_flow_3 & 7);
    table[0] = (stage_v_64 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_64 & 127);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1] + (sec_r001039_5 & 7);
    table[1] = (stage_v_65 + pub_r001039_19) & 63;
    out_sink ^= (stage_v_65 & 127);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2] + (sec_r001039_3 & 7);
    table[2] = (stage_v_66 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_66 & 127);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001039_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0] + (stage_v_4 & 7);
    table[0] = (stage_v_68 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_68 & 127);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001039_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2] + (stage_v_65 & 7);
    table[2] = (stage_v_70 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_70 & 127);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3] + (sec_r001039_1 & 7);
    table[3] = (stage_v_71 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_71 & 127);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0] + (stage_v_59 & 7);
    table[0] = (stage_v_72 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_72 & 127);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001039_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001039_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3] + (helper_flow_0 & 7);
    table[3] = (stage_v_75 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_75 & 127);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001039_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001039_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001039_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001039_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0] + (helper_flow_0 & 7);
    table[0] = (stage_v_80 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_80 & 127);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001039_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001039_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001039_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001039_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001039_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2] + (helper_flow_2 & 7);
    table[2] = (stage_v_86 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_86 & 127);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3] + (stage_v_39 & 7);
    table[3] = (stage_v_87 + pub_r001039_8) & 63;
    out_sink ^= (stage_v_87 & 127);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001039_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001039_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2] + (stage_v_47 & 7);
    table[2] = (stage_v_90 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_90 & 127);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001039_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001039_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001039_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2] + (stage_v_80 & 7);
    table[2] = (stage_v_94 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_94 & 127);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001039_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001039_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1] + (stage_v_19 & 7);
    table[1] = (stage_v_97 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_97 & 127);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001039_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001039_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001039_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001039_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2] + (stage_v_72 & 7);
    table[2] = (stage_v_102 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_102 & 127);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3] + (stage_v_86 & 7);
    table[3] = (stage_v_103 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_103 & 127);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001039_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001039_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001039_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3] + (stage_v_68 & 7);
    table[3] = (stage_v_107 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_107 & 127);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0] + (sec_r001039_13 & 7);
    table[0] = (stage_v_108 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_108 & 127);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1] + (stage_v_108 & 7);
    table[1] = (stage_v_109 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_109 & 127);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2] + (sec_r001039_17 & 7);
    table[2] = (stage_v_110 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_110 & 127);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = table[3] + (stage_v_68 & 7);
    table[3] = (stage_v_111 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_111 & 127);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0] + (stage_v_43 & 7);
    table[0] = (stage_v_112 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_112 & 127);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1] + (stage_v_33 & 7);
    table[1] = (stage_v_113 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_113 & 127);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001039_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3] + (stage_v_41 & 7);
    table[3] = (stage_v_115 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_115 & 127);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0] + (stage_v_19 & 7);
    table[0] = (stage_v_116 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_116 & 127);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1] + (stage_v_0 & 7);
    table[1] = (stage_v_117 + pub_r001039_9) & 63;
    out_sink ^= (stage_v_117 & 127);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001039_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3] + (sec_r001039_4 & 7);
    table[3] = (stage_v_119 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_119 & 127);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001039_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = table[1] + (stage_v_59 & 7);
    table[1] = (stage_v_121 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_121 & 127);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2] + (stage_v_52 & 7);
    table[2] = (stage_v_122 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_122 & 127);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001039_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001039_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1] + (stage_v_90 & 7);
    table[1] = (stage_v_125 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_125 & 127);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001039_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3] + (stage_v_86 & 7);
    table[3] = (stage_v_127 + pub_r001039_4) & 63;
    out_sink ^= (stage_v_127 & 127);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0] + (sec_r001039_17 & 7);
    table[0] = (stage_v_128 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_128 & 127);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1] + (sec_r001039_5 & 7);
    table[1] = (stage_v_129 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_129 & 127);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001039_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001039_20 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0] + (stage_v_59 & 7);
    table[0] = (stage_v_132 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_132 & 127);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = table[1] + (sec_r001039_16 & 7);
    table[1] = (stage_v_133 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_133 & 127);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001039_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001039_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001039_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001039_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001039_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3] + (stage_v_70 & 7);
    table[3] = (stage_v_139 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_139 & 127);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0] + (sec_r001039_4 & 7);
    table[0] = (stage_v_140 + pub_r001039_9) & 63;
    out_sink ^= (stage_v_140 & 127);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1] + (helper_flow_4 & 7);
    table[1] = (stage_v_141 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_141 & 127);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001039_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001039_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0] + (stage_v_37 & 7);
    table[0] = (stage_v_144 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_144 & 127);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = table[1] + (stage_v_59 & 7);
    table[1] = (stage_v_145 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_145 & 127);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2] + (stage_v_47 & 7);
    table[2] = (stage_v_146 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_146 & 127);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3] + (sec_r001039_15 & 7);
    table[3] = (stage_v_147 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_147 & 127);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0] + (sec_r001039_14 & 7);
    table[0] = (stage_v_148 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_148 & 127);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001039_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001039_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3] + (stage_v_43 & 7);
    table[3] = (stage_v_151 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_151 & 127);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001039_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001039_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001039_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001039_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001039_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001039_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001039_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001039_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001039_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001039_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = table[2] + (stage_v_22 & 7);
    table[2] = (stage_v_162 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_162 & 127);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001039_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001039_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001039_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2] + (stage_v_132 & 7);
    table[2] = (stage_v_166 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_166 & 127);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3] + (stage_v_139 & 7);
    table[3] = (stage_v_167 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_167 & 127);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001039_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001039_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001039_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001039_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0] + (stage_v_148 & 7);
    table[0] = (stage_v_172 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_172 & 127);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001039_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001039_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001039_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001039_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001039_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2] + (stage_v_10 & 7);
    table[2] = (stage_v_178 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_178 & 127);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001039_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001039_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001039_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001039_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = table[3] + (stage_v_18 & 7);
    table[3] = (stage_v_183 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_183 & 127);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = table[0] + (stage_v_10 & 7);
    table[0] = (stage_v_184 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_184 & 127);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001039_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001039_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001039_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001039_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = table[1] + (stage_v_132 & 7);
    table[1] = (stage_v_189 + pub_r001039_4) & 63;
    out_sink ^= (stage_v_189 & 127);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001039_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001039_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001039_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001039_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2] + (sec_r001039_5 & 7);
    table[2] = (stage_v_194 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_194 & 127);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001039_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001039_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001039_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001039_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001039_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001039_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001039_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = table[2] + (stage_v_140 & 7);
    table[2] = (stage_v_202 + pub_r001039_4) & 63;
    out_sink ^= (stage_v_202 & 127);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = table[3] + (helper_flow_4 & 7);
    table[3] = (stage_v_203 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_203 & 127);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001039_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001039_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = table[2] + (stage_v_19 & 7);
    table[2] = (stage_v_206 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_206 & 127);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001039_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001039_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = table[1] + (sec_r001039_16 & 7);
    table[1] = (stage_v_209 + pub_r001039_2) & 63;
    out_sink ^= (stage_v_209 & 127);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = table[2] + (sec_r001039_2 & 7);
    table[2] = (stage_v_210 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_210 & 127);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001039_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = table[0] + (stage_v_116 & 7);
    table[0] = (stage_v_212 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_212 & 127);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = table[1] + (helper_flow_1 & 7);
    table[1] = (stage_v_213 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_213 & 127);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = table[2] + (stage_v_32 & 7);
    table[2] = (stage_v_214 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_214 & 127);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = table[3] + (stage_v_184 & 7);
    table[3] = (stage_v_215 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_215 & 127);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001039_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001039_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001039_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001039_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001039_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = table[1] + (stage_v_75 & 7);
    table[1] = (stage_v_221 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_221 & 127);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = table[2] + (stage_v_33 & 7);
    table[2] = (stage_v_222 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_222 & 127);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001039_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001039_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001039_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = table[2] + (helper_flow_5 & 7);
    table[2] = (stage_v_226 + pub_r001039_8) & 63;
    out_sink ^= (stage_v_226 & 127);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = table[3] + (sec_r001039_6 & 7);
    table[3] = (stage_v_227 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_227 & 127);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001039_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001039_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001039_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001039_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001039_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001039_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001039_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = table[3] + (stage_v_4 & 7);
    table[3] = (stage_v_235 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_235 & 127);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001039_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001039_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001039_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001039_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = table[0] + (stage_v_151 & 7);
    table[0] = (stage_v_240 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_240 & 127);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001039_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = table[2] + (stage_v_43 & 7);
    table[2] = (stage_v_242 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_242 & 127);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = table[3] + (sec_r001039_13 & 7);
    table[3] = (stage_v_243 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_243 & 127);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001039_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001039_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = table[2] + (stage_v_43 & 7);
    table[2] = (stage_v_246 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_246 & 127);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = table[3] + (sec_r001039_1 & 7);
    table[3] = (stage_v_247 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_247 & 127);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001039_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001039_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001039_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = table[3] + (stage_v_183 & 7);
    table[3] = (stage_v_251 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_251 & 127);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001039_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001039_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001039_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001039_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001039_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = table[1] + (stage_v_128 & 7);
    table[1] = (stage_v_257 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_257 & 127);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001039_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001039_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = table[0] + (stage_v_139 & 7);
    table[0] = (stage_v_260 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_260 & 127);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = table[1] + (stage_v_139 & 7);
    table[1] = (stage_v_261 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_261 & 127);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001039_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = table[3] + (stage_v_49 & 7);
    table[3] = (stage_v_263 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_263 & 127);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001039_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001039_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001039_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001039_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001039_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001039_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = table[2] + (stage_v_194 & 7);
    table[2] = (stage_v_270 + pub_r001039_8) & 63;
    out_sink ^= (stage_v_270 & 127);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = table[3] + (stage_v_18 & 7);
    table[3] = (stage_v_271 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_271 & 127);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = table[0] + (sec_r001039_14 & 7);
    table[0] = (stage_v_272 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_272 & 127);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001039_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001039_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001039_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = table[0] + (stage_v_68 & 7);
    table[0] = (stage_v_276 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_276 & 127);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001039_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001039_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = table[3] + (stage_v_203 & 7);
    table[3] = (stage_v_279 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_279 & 127);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001039_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001039_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001039_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001039_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = table[0] + (helper_flow_0 & 7);
    table[0] = (stage_v_284 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_284 & 127);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = table[1] + (stage_v_141 & 7);
    table[1] = (stage_v_285 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_285 & 127);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = table[2] + (stage_v_285 & 7);
    table[2] = (stage_v_286 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_286 & 127);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = table[3] + (stage_v_48 & 7);
    table[3] = (stage_v_287 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_287 & 127);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001039_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001039_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001039_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = table[3] + (sec_r001039_4 & 7);
    table[3] = (stage_v_291 + pub_r001039_19) & 63;
    out_sink ^= (stage_v_291 & 127);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = table[0] + (sec_r001039_2 & 7);
    table[0] = (stage_v_292 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_292 & 127);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = table[1] + (stage_v_0 & 7);
    table[1] = (stage_v_293 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_293 & 127);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = table[2] + (stage_v_75 & 7);
    table[2] = (stage_v_294 + pub_r001039_9) & 63;
    out_sink ^= (stage_v_294 & 127);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = table[3] + (sec_r001039_15 & 7);
    table[3] = (stage_v_295 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_295 & 127);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001039_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001039_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001039_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001039_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001039_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001039_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001039_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = table[3] + (sec_r001039_6 & 7);
    table[3] = (stage_v_303 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_303 & 127);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001039_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = table[1] + (stage_v_162 & 7);
    table[1] = (stage_v_305 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_305 & 127);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001039_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = table[3] + (stage_v_270 & 7);
    table[3] = (stage_v_307 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_307 & 127);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = table[0] + (stage_v_242 & 7);
    table[0] = (stage_v_308 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_308 & 127);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = table[1] + (stage_v_70 & 7);
    table[1] = (stage_v_309 + pub_r001039_16) & 63;
    out_sink ^= (stage_v_309 & 127);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001039_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001039_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = table[0] + (stage_v_18 & 7);
    table[0] = (stage_v_312 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_312 & 127);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001039_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001039_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = table[3] + (stage_v_209 & 7);
    table[3] = (stage_v_315 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_315 & 127);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = table[0] + (sec_r001039_2 & 7);
    table[0] = (stage_v_316 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_316 & 127);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001039_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001039_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001039_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = table[0] + (sec_r001039_1 & 7);
    table[0] = (stage_v_320 + pub_r001039_9) & 63;
    out_sink ^= (stage_v_320 & 127);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001039_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = table[2] + (stage_v_276 & 7);
    table[2] = (stage_v_322 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_322 & 127);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001039_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = table[0] + (stage_v_307 & 7);
    table[0] = (stage_v_324 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_324 & 127);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001039_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001039_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001039_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001039_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = table[1] + (stage_v_151 & 7);
    table[1] = (stage_v_329 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_329 & 127);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = table[2] + (sec_r001039_12 & 7);
    table[2] = (stage_v_330 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_330 & 127);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001039_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001039_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001039_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = table[2] + (stage_v_206 & 7);
    table[2] = (stage_v_334 + pub_r001039_8) & 63;
    out_sink ^= (stage_v_334 & 127);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001039_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = table[0] + (stage_v_140 & 7);
    table[0] = (stage_v_336 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_336 & 127);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = table[1] + (stage_v_263 & 7);
    table[1] = (stage_v_337 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_337 & 127);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001039_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001039_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001039_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = table[1] + (stage_v_240 & 7);
    table[1] = (stage_v_341 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_341 & 127);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001039_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = table[3] + (stage_v_115 & 7);
    table[3] = (stage_v_343 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_343 & 127);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001039_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001039_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001039_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = table[3] + (stage_v_324 & 7);
    table[3] = (stage_v_347 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_347 & 127);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001039_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001039_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001039_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001039_20 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001039_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = table[1] + (stage_v_203 & 7);
    table[1] = (stage_v_353 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_353 & 127);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = table[2] + (stage_v_103 & 7);
    table[2] = (stage_v_354 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_354 & 127);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = table[3] + (stage_v_214 & 7);
    table[3] = (stage_v_355 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_355 & 127);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001039_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = table[1] + (stage_v_0 & 7);
    table[1] = (stage_v_357 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_357 & 127);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = table[2] + (stage_v_294 & 7);
    table[2] = (stage_v_358 + pub_r001039_15) & 63;
    out_sink ^= (stage_v_358 & 127);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = table[3] + (stage_v_330 & 7);
    table[3] = (stage_v_359 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_359 & 127);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = table[0] + (stage_v_64 & 7);
    table[0] = (stage_v_360 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_360 & 127);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001039_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = table[2] + (stage_v_292 & 7);
    table[2] = (stage_v_362 + pub_r001039_9) & 63;
    out_sink ^= (stage_v_362 & 127);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001039_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = table[0] + (helper_flow_0 & 7);
    table[0] = (stage_v_364 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_364 & 127);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001039_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001039_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001039_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001039_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001039_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001039_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001039_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001039_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001039_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001039_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001039_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001039_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001039_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = table[2] + (stage_v_121 & 7);
    table[2] = (stage_v_378 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_378 & 127);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001039_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = table[0] + (stage_v_42 & 7);
    table[0] = (stage_v_380 + pub_r001039_18) & 63;
    out_sink ^= (stage_v_380 & 127);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = table[1] + (stage_v_178 & 7);
    table[1] = (stage_v_381 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_381 & 127);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = table[2] + (sec_r001039_15 & 7);
    table[2] = (stage_v_382 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_382 & 127);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001039_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001039_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001039_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001039_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001039_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001039_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001039_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = table[2] + (stage_v_202 & 7);
    table[2] = (stage_v_390 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_390 & 127);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001039_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001039_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001039_20 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = table[2] + (stage_v_320 & 7);
    table[2] = (stage_v_394 + pub_r001039_19) & 63;
    out_sink ^= (stage_v_394 & 127);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001039_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = table[0] + (sec_r001039_0 & 7);
    table[0] = (stage_v_396 + pub_r001039_1) & 63;
    out_sink ^= (stage_v_396 & 127);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001039_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = table[2] + (stage_v_202 & 7);
    table[2] = (stage_v_398 + pub_r001039_11) & 63;
    out_sink ^= (stage_v_398 & 127);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001039_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001039_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001039_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = table[2] + (stage_v_316 & 7);
    table[2] = (stage_v_402 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_402 & 127);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = table[3] + (stage_v_110 & 7);
    table[3] = (stage_v_403 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_403 & 127);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001039_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = table[1] + (stage_v_75 & 7);
    table[1] = (stage_v_405 + pub_r001039_7) & 63;
    out_sink ^= (stage_v_405 & 127);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = table[2] + (stage_v_132 & 7);
    table[2] = (stage_v_406 + pub_r001039_6) & 63;
    out_sink ^= (stage_v_406 & 127);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001039_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = table[0] + (stage_v_41 & 7);
    table[0] = (stage_v_408 + pub_r001039_4) & 63;
    out_sink ^= (stage_v_408 & 127);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001039_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001039_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001039_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = table[0] + (stage_v_337 & 7);
    table[0] = (stage_v_412 + pub_r001039_17) & 63;
    out_sink ^= (stage_v_412 & 127);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = table[1] + (stage_v_103 & 7);
    table[1] = (stage_v_413 + pub_r001039_20) & 63;
    out_sink ^= (stage_v_413 & 127);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001039_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001039_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001039_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = table[1] + (stage_v_7 & 7);
    table[1] = (stage_v_417 + pub_r001039_14) & 63;
    out_sink ^= (stage_v_417 & 127);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001039_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = table[3] + (stage_v_390 & 7);
    table[3] = (stage_v_419 + pub_r001039_10) & 63;
    out_sink ^= (stage_v_419 & 127);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001039_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001039_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001039_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001039_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = table[0] + (stage_v_272 & 7);
    table[0] = (stage_v_424 + pub_r001039_5) & 63;
    out_sink ^= (stage_v_424 & 127);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = table[1] + (stage_v_70 & 7);
    table[1] = (stage_v_425 + pub_r001039_14) & 63;
    out_sink ^= (stage_v_425 & 127);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001039_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = table[3] + (sec_r001039_13 & 7);
    table[3] = (stage_v_427 + pub_r001039_13) & 63;
    out_sink ^= (stage_v_427 & 127);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001039_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001039_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = table[2] + (stage_v_71 & 7);
    table[2] = (stage_v_430 + pub_r001039_12) & 63;
    out_sink ^= (stage_v_430 & 127);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001039_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = table[0] + (stage_v_271 & 7);
    table[0] = (stage_v_432 + pub_r001039_3) & 63;
    out_sink ^= (stage_v_432 & 127);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = table[1] + (stage_v_125 & 7);
    table[1] = (stage_v_433 + pub_r001039_0) & 63;
    out_sink ^= (stage_v_433 & 127);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
