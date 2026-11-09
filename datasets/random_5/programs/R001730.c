/*
 * Benchmark Program: R001730
 * Security Family: mixed_control_data
 * Generator Seed: 673013
 * High Inputs: 16 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001730_3013_0 {
    int damping;
    int prev_in;
    int cutoff;
    int buffer[3];
};

struct CipherContext_R001730_3013_1 {
    short iv;
    unsigned char nonce;
    short flags;
    int counter;
    unsigned char round_key;
    int buffer[3];
};

struct AudioFrame_R001730_3013_2 {
    int channels;
    int envelope;
    int sample_rate;
    int peak;
    int buffer[3];
};

union ColorPixel_R001730_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001730_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001730_3013_0(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_30 = (aux + st.buffer[1]) & 3;
    switch (quantum_30) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_90 = 0;
    for (int k = 0; k < 3; k++) {
        offset_90 = (offset_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_90) & 127;
    }
    int delta_76 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_76 > 30) {
        acc = (acc + delta_76 * 2 + 5) & 127;
        aux ^= (delta_76 & 15);
    } else {
        acc = (acc - delta_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_1(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int anchor_77 = local_arr[aux % 3];
    acc = (acc + anchor_77 * 2) & 127;
    int index_reg_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001730_3013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_27 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_27 > 27) {
        acc = (acc + tracker_27 * 2 + 5) & 127;
        aux ^= (tracker_27 & 15);
    } else {
        acc = (acc - tracker_27 + 11) & 127;
        aux += 3;
    }
    int scale_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_91) & 63;
    acc ^= aux;
    int tally_81 = (aux + st.buffer[1]) & 3;
    switch (tally_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_3(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tally_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_40 > 29) {
        acc = (acc + tally_40 * 2 + 5) & 127;
        aux ^= (tally_40 & 15);
    } else {
        acc = (acc - tally_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_71 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_71 = (checksum_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int cursor_38 = local_arr[aux % 3];
    acc = (acc + cursor_38 * 2) & 127;
    int offset_17 = (aux + st.buffer[1]) & 3;
    switch (offset_17) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_11 = (st.buffer[0] * 3 + aux) & 63;
    if (window_11 > 40) {
        acc = (acc + window_11 * 2 + 5) & 127;
        aux ^= (window_11 & 15);
    } else {
        acc = (acc - window_11 + 11) & 127;
        aux += 3;
    }
    int tally_55 = 0;
    for (int k = 0; k < 2; k++) {
        tally_55 = (tally_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_5(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_54 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_54 > 43) {
        acc = (acc + tracker_54 * 2 + 5) & 127;
        aux ^= (tracker_54 & 15);
    } else {
        acc = (acc - tracker_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_51 = local_arr[aux % 3];
    acc = (acc + vector_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001730_3013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_64) & 63;
    acc ^= aux;
    int phase_16 = (aux + st.buffer[1]) & 3;
    switch (phase_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_7(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_72 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_72 > 32) {
        acc = (acc + residue_72 * 2 + 5) & 127;
        aux ^= (residue_72 & 15);
    } else {
        acc = (acc - residue_72 + 11) & 127;
        aux += 3;
    }
    int checksum_78 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_78 = (checksum_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001730_3013_8(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_61 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_61 > 40) {
        acc = (acc + stride_61 * 2 + 5) & 127;
        aux ^= (stride_61 & 15);
    } else {
        acc = (acc - stride_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_9(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_94 = (aux + st.buffer[1]) & 3;
    switch (accumulator_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_19 = local_arr[aux % 3];
    acc = (acc + quotient_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001730_3013_10(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_87 = (aux + st.buffer[1]) & 3;
    switch (coefficient_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001730_3013_11(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001730_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int vector_53 = local_arr[aux % 3];
    acc = (acc + vector_53 * 2) & 127;
    int tracker_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_83) & 63;
    acc ^= aux;
    int damping_36 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_36 > 22) {
        acc = (acc + damping_36 * 2 + 5) & 127;
        aux ^= (damping_36 & 15);
    } else {
        acc = (acc - damping_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_12(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_10 = local_arr[aux % 3];
    acc = (acc + phase_10 * 2) & 127;
    int margin_12 = (aux + st.buffer[1]) & 3;
    switch (margin_12) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_13(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001730_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_86) & 63;
    acc ^= aux;
    int margin_55 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_55 > 38) {
        acc = (acc + margin_55 * 2 + 5) & 127;
        aux ^= (margin_55 & 15);
    } else {
        acc = (acc - margin_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001730_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_50 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_50 = (tracker_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001730_3013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_23) & 63;
    acc ^= aux;
    int tally_85 = 0;
    for (int k = 0; k < 2; k++) {
        tally_85 = (tally_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_85) & 127;
    }
    int damping_30 = (aux + st.buffer[1]) & 3;
    switch (damping_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_16 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_16 > 17) {
        acc = (acc + tracker_16 * 2 + 5) & 127;
        aux ^= (tracker_16 & 15);
    } else {
        acc = (acc - tracker_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001730_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_64 = (aux + st.buffer[1]) & 3;
    switch (quantum_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001730_3013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001730_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_29 = 0;
    for (int k = 0; k < 2; k++) {
        segment_29 = (segment_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_29) & 127;
    }
    int mask_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001730_0;
    int sec_r001730_1;
    int sec_r001730_2;
    int sec_r001730_3;
    int sec_r001730_4;
    int sec_r001730_5;
    int sec_r001730_6;
    int sec_r001730_7;
    int sec_r001730_8;
    int sec_r001730_9;
    int sec_r001730_10;
    int sec_r001730_11;
    int sec_r001730_12;
    int sec_r001730_13;
    int sec_r001730_14;
    int sec_r001730_15;
    int pub_r001730_0;
    int pub_r001730_1;
    int pub_r001730_2;
    int pub_r001730_3;
    int pub_r001730_4;
    int pub_r001730_5;
    int pub_r001730_6;
    int pub_r001730_7;
    int pub_r001730_8;
    int pub_r001730_9;
    int pub_r001730_10;
    int pub_r001730_11;
    int pub_r001730_12;
    int pub_r001730_13;
    int pub_r001730_14;
    int pub_r001730_15;
    int pub_r001730_16;
    int pub_r001730_17;
    int pub_r001730_18;
    int pub_r001730_19;
    int pub_r001730_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001730_0 >= -100 && pub_r001730_0 <= 100);
    __CPROVER_assume(pub_r001730_1 >= -100 && pub_r001730_1 <= 100);
    __CPROVER_assume(pub_r001730_2 >= -100 && pub_r001730_2 <= 100);
    __CPROVER_assume(pub_r001730_3 >= -100 && pub_r001730_3 <= 100);
    __CPROVER_assume(pub_r001730_4 >= -100 && pub_r001730_4 <= 100);
    __CPROVER_assume(pub_r001730_5 >= -100 && pub_r001730_5 <= 100);
    __CPROVER_assume(pub_r001730_6 >= -100 && pub_r001730_6 <= 100);
    __CPROVER_assume(pub_r001730_7 >= -100 && pub_r001730_7 <= 100);
    __CPROVER_assume(pub_r001730_8 >= -100 && pub_r001730_8 <= 100);
    __CPROVER_assume(pub_r001730_9 >= -100 && pub_r001730_9 <= 100);
    __CPROVER_assume(pub_r001730_10 >= -100 && pub_r001730_10 <= 100);
    __CPROVER_assume(pub_r001730_11 >= -100 && pub_r001730_11 <= 100);
    __CPROVER_assume(pub_r001730_12 >= -100 && pub_r001730_12 <= 100);
    __CPROVER_assume(pub_r001730_13 >= -100 && pub_r001730_13 <= 100);
    __CPROVER_assume(pub_r001730_14 >= -100 && pub_r001730_14 <= 100);
    __CPROVER_assume(pub_r001730_15 >= -100 && pub_r001730_15 <= 100);
    __CPROVER_assume(pub_r001730_16 >= -100 && pub_r001730_16 <= 100);
    __CPROVER_assume(pub_r001730_17 >= -100 && pub_r001730_17 <= 100);
    __CPROVER_assume(pub_r001730_18 >= -100 && pub_r001730_18 <= 100);
    __CPROVER_assume(pub_r001730_19 >= -100 && pub_r001730_19 <= 100);
    __CPROVER_assume(pub_r001730_20 >= -100 && pub_r001730_20 <= 100);
    __CPROVER_assume(sec_r001730_0 >= 0 && sec_r001730_0 <= 255);
    __CPROVER_assume(sec_r001730_1 >= 0 && sec_r001730_1 <= 255);
    __CPROVER_assume(sec_r001730_2 >= 0 && sec_r001730_2 <= 255);
    __CPROVER_assume(sec_r001730_3 >= 0 && sec_r001730_3 <= 255);
    __CPROVER_assume(sec_r001730_4 >= 0 && sec_r001730_4 <= 255);
    __CPROVER_assume(sec_r001730_5 >= 0 && sec_r001730_5 <= 255);
    __CPROVER_assume(sec_r001730_6 >= 0 && sec_r001730_6 <= 255);
    __CPROVER_assume(sec_r001730_7 >= 0 && sec_r001730_7 <= 255);
    __CPROVER_assume(sec_r001730_8 >= 0 && sec_r001730_8 <= 255);
    __CPROVER_assume(sec_r001730_9 >= 0 && sec_r001730_9 <= 255);
    __CPROVER_assume(sec_r001730_10 >= 0 && sec_r001730_10 <= 255);
    __CPROVER_assume(sec_r001730_11 >= 0 && sec_r001730_11 <= 255);
    __CPROVER_assume(sec_r001730_12 >= 0 && sec_r001730_12 <= 255);
    __CPROVER_assume(sec_r001730_13 >= 0 && sec_r001730_13 <= 255);
    __CPROVER_assume(sec_r001730_14 >= 0 && sec_r001730_14 <= 255);
    __CPROVER_assume(sec_r001730_15 >= 0 && sec_r001730_15 <= 255);

    struct FilterState_R001730_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001730_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001730_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001730_0 + 7) & 15;
    struct CipherContext_R001730_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001730_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001730_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001730_0 + 9) & 15;
    struct AudioFrame_R001730_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001730_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001730_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001730_0 + 11) & 15;

    union ColorPixel_R001730_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001730_3013_0(sec_r001730_0, pub_r001730_1, pub_r001730_2);
    int helper_flow_1 = fn_R001730_3013_1(sec_r001730_1, pub_r001730_2, pub_r001730_3);
    int helper_flow_2 = fn_R001730_3013_2(sec_r001730_2, sec_r001730_3, pub_r001730_4, pub_r001730_5);
    int helper_flow_3 = fn_R001730_3013_3(sec_r001730_3, sec_r001730_4, pub_r001730_5);
    int helper_flow_4 = fn_R001730_3013_4(sec_r001730_4, sec_r001730_5, pub_r001730_6, pub_r001730_7, pub_r001730_8);
    int helper_flow_5 = fn_R001730_3013_5(sec_r001730_5, sec_r001730_6, pub_r001730_7);
    int helper_flow_6 = fn_R001730_3013_6(sec_r001730_6, pub_r001730_7, pub_r001730_8, pub_r001730_9, pub_r001730_10);
    int helper_flow_7 = fn_R001730_3013_7(sec_r001730_7, sec_r001730_8);
    int helper_flow_8 = fn_R001730_3013_8(sec_r001730_8, pub_r001730_9);
    int helper_flow_9 = fn_R001730_3013_9(sec_r001730_9, sec_r001730_10);
    int helper_flow_10 = fn_R001730_3013_10(sec_r001730_10, sec_r001730_11);
    int helper_flow_11 = fn_R001730_3013_11(sec_r001730_11, sec_r001730_12);
    int helper_flow_12 = fn_R001730_3013_12(sec_r001730_12, pub_r001730_13, pub_r001730_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001730_11) & 127;
    if (stage_v_0 > 47) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_1 > 29) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_2 > 25) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001730_10 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_3 > 20) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001730_9 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_4 > 41) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001730_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_6 > 36) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001730_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_8 > 47) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001730_9 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_9 > 35) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001730_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001730_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001730_5 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001730_7 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_13 > 31) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_14 > 29) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001730_6 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_15 > 23) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001730_1 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_16 > 32) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_17 > 40) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001730_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_19 > 37) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001730_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_21 > 26) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001730_8 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001730_8 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_23 > 28) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001730_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001730_13 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_25 > 24) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_26 > 23) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001730_5 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_27 > 32) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001730_0) & 127;
    if (stage_v_28 > 45) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001730_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001730_20 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_31 > 31) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001730_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001730_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_34 > 25) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_35 > 40) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001730_9 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_36 > 46) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_37 > 36) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_39 > 22) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001730_7 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_40 > 28) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_41 > 46) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001730_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_43 > 22) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001730_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001730_2 ^ 0x2A) * 2 + pub_r001730_9) & 127;
    if (stage_v_45 > 49) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001730_17) & 127;
    if (stage_v_46 > 35) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001730_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_48 > 39) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_49 > 40) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001730_1 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_50 > 40) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001730_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001730_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_53 > 23) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001730_10 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_54 > 25) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_55 > 48) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001730_0 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_56 > 42) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_57 > 23) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_58 > 39) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001730_11 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_59 > 25) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001730_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001730_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_62 > 20) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001730_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_64 > 29) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_65 > 34) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001730_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001730_8 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_67 > 49) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001730_9) & 127;
    if (stage_v_68 > 35) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_69 > 26) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_70 > 21) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_71 > 32) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_72 > 27) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_73 > 43) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001730_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001730_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001730_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_77 > 27) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_78 > 31) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_79 > 26) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001730_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001730_15 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_81 > 22) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001730_5 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_82 > 34) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_83 > 47) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001730_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_85 > 43) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_86 > 43) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001730_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_88 > 45) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001730_9) & 127;
    if (stage_v_89 > 42) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001730_5 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_90 > 45) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_91 > 43) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001730_9) & 127;
    if (stage_v_92 > 49) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_93 > 42) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001730_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_95 > 41) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001730_17) & 127;
    if (stage_v_96 > 21) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_97 > 39) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_98 > 33) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001730_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_100 > 22) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001730_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_102 > 41) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001730_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001730_12 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_104 > 25) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001730_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001730_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_107 > 24) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001730_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001730_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001730_12 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_110 > 25) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_111 > 26) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_113 > 48) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_114 > 23) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001730_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001730_4 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_116 > 24) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_117 > 42) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_118 > 40) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_119 > 38) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_121 > 34) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_123 > 32) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_124 > 26) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_125 > 37) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_126 > 24) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001730_11) & 127;
    if (stage_v_127 > 35) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001730_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001730_3 ^ 0x2A) * 2 + pub_r001730_9) & 127;
    if (stage_v_129 > 22) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_130 > 28) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001730_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_132 > 37) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001730_0) & 127;
    if (stage_v_133 > 33) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_134 > 42) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_135 > 33) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001730_11) & 127;
    if (stage_v_136 > 37) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001730_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_138 > 36) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_139 > 22) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001730_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_141 > 37) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001730_20) & 127;
    if (stage_v_142 > 33) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001730_15 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_144 > 48) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_145 > 50) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001730_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001730_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_148 > 30) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_149 > 37) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_150 > 34) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_151 > 41) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_152 > 32) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001730_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_154 > 21) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001730_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_156 > 27) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001730_17) & 127;
    if (stage_v_157 > 44) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001730_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_159 > 48) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_160 > 37) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001730_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001730_13 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_163 > 29) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001730_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_165 > 22) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_166 > 47) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_167 > 41) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_168 > 37) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_169 > 29) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_170 > 38) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_171 > 45) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001730_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_173 > 21) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_174 > 44) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001730_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001730_13) & 127;
    if (stage_v_176 > 47) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001730_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001730_5 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_178 > 24) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_179 > 28) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001730_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001730_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001730_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001730_0 ^ 0x2A) * 2 + pub_r001730_11) & 127;
    if (stage_v_183 > 28) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_184 > 29) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_185 > 36) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001730_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_187 > 41) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001730_4 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_188 > 27) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001730_0) & 127;
    if (stage_v_189 > 31) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001730_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001730_17) & 127;
    if (stage_v_191 > 21) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_192 > 40) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001730_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_194 > 37) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_195 > 46) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001730_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001730_5) & 127;
    if (stage_v_197 > 39) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001730_17) & 127;
    if (stage_v_198 > 33) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001730_6) & 127;
    if (stage_v_199 > 40) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001730_8) & 127;
    if (stage_v_200 > 26) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001730_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_202 > 44) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_203 > 49) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001730_16) & 127;
    if (stage_v_204 > 38) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_205 > 46) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001730_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_207 > 23) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001730_0) & 127;
    if (stage_v_208 > 25) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_209 > 48) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001730_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_211 > 32) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_212 > 33) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001730_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_214 > 42) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001730_12) & 127;
    if (stage_v_215 > 28) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001730_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001730_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001730_13 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_218 > 20) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_219 > 32) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001730_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_221 > 48) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_222 > 21) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001730_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001730_2) & 127;
    if (stage_v_224 > 48) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001730_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_226 > 49) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_227 > 40) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001730_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_229 > 23) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001730_18) & 127;
    if (stage_v_230 > 48) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001730_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001730_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001730_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_234 > 28) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001730_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001730_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_237 > 37) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001730_3) & 127;
    if (stage_v_238 > 40) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_239 > 34) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001730_7) & 127;
    if (stage_v_240 > 21) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001730_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_242 > 23) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001730_15) & 127;
    if (stage_v_243 > 27) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001730_11) & 127;
    if (stage_v_244 > 20) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001730_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001730_1) & 127;
    if (stage_v_246 > 49) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_208 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_247 > 43) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_212 ^ 0x2A) * 2 + pub_r001730_14) & 127;
    if (stage_v_248 > 31) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001730_4) & 127;
    if (stage_v_249 > 46) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001730_19) & 127;
    if (stage_v_250 > 28) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_239 ^ 0x2A) * 2 + pub_r001730_10) & 127;
    if (stage_v_251 > 46) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001730_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
