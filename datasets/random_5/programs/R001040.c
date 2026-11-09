/*
 * Benchmark Program: R001040
 * Security Family: mixed_control_data
 * Generator Seed: 604013
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001040_4013_0 {
    short gain_db;
    int prev_in;
    unsigned char mode;
    int damping;
    int cutoff;
    unsigned char prev_out;
    int buffer[3];
};

struct CipherContext_R001040_4013_1 {
    int tag;
    int counter;
    int round_key;
    int nonce;
    int buffer[3];
};

union RegisterBank_R001040_4013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001040_4013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001040_4013_0(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_84 = 0;
    for (int k = 0; k < 2; k++) {
        bound_84 = (bound_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_84) & 127;
    }
    int offset_20 = (aux + st.buffer[1]) & 3;
    switch (offset_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_21 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_21 > 35) {
        acc = (acc + anchor_21 * 2 + 5) & 127;
        aux ^= (anchor_21 & 15);
    } else {
        acc = (acc - anchor_21 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_1(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_48 = (aux + st.buffer[1]) & 3;
    switch (stride_48) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001040_4013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int segment_54 = local_arr[aux % 3];
    acc = (acc + segment_54 * 2) & 127;
    int anchor_10 = (aux + st.buffer[1]) & 3;
    switch (anchor_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001040_4013_3(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_79 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_79 > 23) {
        acc = (acc + sample_79 * 2 + 5) & 127;
        aux ^= (sample_79 & 15);
    } else {
        acc = (acc - sample_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_36 = local_arr[aux % 3];
    acc = (acc + segment_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_28 = (aux + st.buffer[1]) & 3;
    switch (accumulator_28) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_85 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_85 > 20) {
        acc = (acc + bound_85 * 2 + 5) & 127;
        aux ^= (bound_85 & 15);
    } else {
        acc = (acc - bound_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_96 = local_arr[aux % 3];
    acc = (acc + tally_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_5(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int vector_91 = (aux + st.buffer[1]) & 3;
    switch (vector_91) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_48 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_48 > 30) {
        acc = (acc + delta_48 * 2 + 5) & 127;
        aux ^= (delta_48 & 15);
    } else {
        acc = (acc - delta_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001040_4013_6(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_16 = (aux + st.buffer[1]) & 3;
    switch (factor_16) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_81 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_81 = (cursor_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_81) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_7(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001040_4013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_26 = local_arr[aux % 3];
    acc = (acc + quantum_26 * 2) & 127;
    int tally_41 = 0;
    for (int k = 0; k < 2; k++) {
        tally_41 = (tally_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_41) & 127;
    }
    int sample_72 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_72 > 30) {
        acc = (acc + sample_72 * 2 + 5) & 127;
        aux ^= (sample_72 & 15);
    } else {
        acc = (acc - sample_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001040_4013_9(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int pivot_47 = (aux + st.buffer[1]) & 3;
    switch (pivot_47) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_94 = 0;
    for (int k = 0; k < 3; k++) {
        margin_94 = (margin_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_94) & 127;
    }
    int scale_84 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_84 > 24) {
        acc = (acc + scale_84 * 2 + 5) & 127;
        aux ^= (scale_84 & 15);
    } else {
        acc = (acc - scale_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001040_4013_10(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_28 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_28 > 26) {
        acc = (acc + bound_28 * 2 + 5) & 127;
        aux ^= (bound_28 & 15);
    } else {
        acc = (acc - bound_28 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_97 = local_arr[aux % 3];
    acc = (acc + weight_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_61 = (aux + st.buffer[1]) & 3;
    switch (anchor_61) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_99 = local_arr[aux % 3];
    acc = (acc + mask_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_51 = (aux + st.buffer[1]) & 3;
    switch (margin_51) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_51 = local_arr[aux % 3];
    acc = (acc + sample_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_13(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_90 = 0;
    for (int k = 0; k < 3; k++) {
        factor_90 = (factor_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_24 = local_arr[aux % 3];
    acc = (acc + vector_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_99 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_99 > 19) {
        acc = (acc + residue_99 * 2 + 5) & 127;
        aux ^= (residue_99 & 15);
    } else {
        acc = (acc - residue_99 + 11) & 127;
        aux += 3;
    }
    int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_91) & 63;
    acc ^= aux;
    int tracker_27 = (aux + st.buffer[1]) & 3;
    switch (tracker_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001040_4013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001040_4013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_63 = 0;
    for (int k = 0; k < 3; k++) {
        metric_63 = (metric_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_53 = (aux + st.buffer[1]) & 3;
    switch (stride_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001040_4013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001040_4013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_33 = local_arr[aux % 3];
    acc = (acc + metric_33 * 2) & 127;
    int vector_29 = (aux + st.buffer[1]) & 3;
    switch (vector_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001040_0;
    int sec_r001040_1;
    int sec_r001040_2;
    int sec_r001040_3;
    int sec_r001040_4;
    int sec_r001040_5;
    int sec_r001040_6;
    int sec_r001040_7;
    int sec_r001040_8;
    int sec_r001040_9;
    int sec_r001040_10;
    int sec_r001040_11;
    int sec_r001040_12;
    int sec_r001040_13;
    int sec_r001040_14;
    int sec_r001040_15;
    int sec_r001040_16;
    int sec_r001040_17;
    int sec_r001040_18;
    int pub_r001040_0;
    int pub_r001040_1;
    int pub_r001040_2;
    int pub_r001040_3;
    int pub_r001040_4;
    int pub_r001040_5;
    int pub_r001040_6;
    int pub_r001040_7;
    int pub_r001040_8;
    int pub_r001040_9;
    int pub_r001040_10;
    int pub_r001040_11;
    int pub_r001040_12;
    int pub_r001040_13;
    int pub_r001040_14;
    int pub_r001040_15;
    int pub_r001040_16;
    int pub_r001040_17;
    int pub_r001040_18;
    int pub_r001040_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001040_0 >= -100 && pub_r001040_0 <= 100);
    __CPROVER_assume(pub_r001040_1 >= -100 && pub_r001040_1 <= 100);
    __CPROVER_assume(pub_r001040_2 >= -100 && pub_r001040_2 <= 100);
    __CPROVER_assume(pub_r001040_3 >= -100 && pub_r001040_3 <= 100);
    __CPROVER_assume(pub_r001040_4 >= -100 && pub_r001040_4 <= 100);
    __CPROVER_assume(pub_r001040_5 >= -100 && pub_r001040_5 <= 100);
    __CPROVER_assume(pub_r001040_6 >= -100 && pub_r001040_6 <= 100);
    __CPROVER_assume(pub_r001040_7 >= -100 && pub_r001040_7 <= 100);
    __CPROVER_assume(pub_r001040_8 >= -100 && pub_r001040_8 <= 100);
    __CPROVER_assume(pub_r001040_9 >= -100 && pub_r001040_9 <= 100);
    __CPROVER_assume(pub_r001040_10 >= -100 && pub_r001040_10 <= 100);
    __CPROVER_assume(pub_r001040_11 >= -100 && pub_r001040_11 <= 100);
    __CPROVER_assume(pub_r001040_12 >= -100 && pub_r001040_12 <= 100);
    __CPROVER_assume(pub_r001040_13 >= -100 && pub_r001040_13 <= 100);
    __CPROVER_assume(pub_r001040_14 >= -100 && pub_r001040_14 <= 100);
    __CPROVER_assume(pub_r001040_15 >= -100 && pub_r001040_15 <= 100);
    __CPROVER_assume(pub_r001040_16 >= -100 && pub_r001040_16 <= 100);
    __CPROVER_assume(pub_r001040_17 >= -100 && pub_r001040_17 <= 100);
    __CPROVER_assume(pub_r001040_18 >= -100 && pub_r001040_18 <= 100);
    __CPROVER_assume(pub_r001040_19 >= -100 && pub_r001040_19 <= 100);
    __CPROVER_assume(sec_r001040_0 >= 0 && sec_r001040_0 <= 255);
    __CPROVER_assume(sec_r001040_1 >= 0 && sec_r001040_1 <= 255);
    __CPROVER_assume(sec_r001040_2 >= 0 && sec_r001040_2 <= 255);
    __CPROVER_assume(sec_r001040_3 >= 0 && sec_r001040_3 <= 255);
    __CPROVER_assume(sec_r001040_4 >= 0 && sec_r001040_4 <= 255);
    __CPROVER_assume(sec_r001040_5 >= 0 && sec_r001040_5 <= 255);
    __CPROVER_assume(sec_r001040_6 >= 0 && sec_r001040_6 <= 255);
    __CPROVER_assume(sec_r001040_7 >= 0 && sec_r001040_7 <= 255);
    __CPROVER_assume(sec_r001040_8 >= 0 && sec_r001040_8 <= 255);
    __CPROVER_assume(sec_r001040_9 >= 0 && sec_r001040_9 <= 255);
    __CPROVER_assume(sec_r001040_10 >= 0 && sec_r001040_10 <= 255);
    __CPROVER_assume(sec_r001040_11 >= 0 && sec_r001040_11 <= 255);
    __CPROVER_assume(sec_r001040_12 >= 0 && sec_r001040_12 <= 255);
    __CPROVER_assume(sec_r001040_13 >= 0 && sec_r001040_13 <= 255);
    __CPROVER_assume(sec_r001040_14 >= 0 && sec_r001040_14 <= 255);
    __CPROVER_assume(sec_r001040_15 >= 0 && sec_r001040_15 <= 255);
    __CPROVER_assume(sec_r001040_16 >= 0 && sec_r001040_16 <= 255);
    __CPROVER_assume(sec_r001040_17 >= 0 && sec_r001040_17 <= 255);
    __CPROVER_assume(sec_r001040_18 >= 0 && sec_r001040_18 <= 255);

    struct FilterState_R001040_4013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001040_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001040_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001040_0 + 7) & 15;
    struct CipherContext_R001040_4013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001040_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001040_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001040_0 + 9) & 15;

    union RegisterBank_R001040_4013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001040_4013_0(sec_r001040_0, sec_r001040_1, pub_r001040_2);
    int helper_flow_1 = fn_R001040_4013_1(sec_r001040_1, sec_r001040_2);
    int helper_flow_2 = fn_R001040_4013_2(sec_r001040_2, pub_r001040_3, pub_r001040_4, pub_r001040_5);
    int helper_flow_3 = fn_R001040_4013_3(sec_r001040_3, pub_r001040_4, pub_r001040_5);
    int helper_flow_4 = fn_R001040_4013_4(sec_r001040_4, sec_r001040_5, pub_r001040_6, pub_r001040_7);
    int helper_flow_5 = fn_R001040_4013_5(sec_r001040_5, pub_r001040_6, pub_r001040_7);
    int helper_flow_6 = fn_R001040_4013_6(sec_r001040_6, pub_r001040_7, pub_r001040_8);
    int helper_flow_7 = fn_R001040_4013_7(sec_r001040_7, sec_r001040_8, pub_r001040_9);
    int helper_flow_8 = fn_R001040_4013_8(sec_r001040_8, pub_r001040_9, pub_r001040_10, pub_r001040_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_1 > 39) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001040_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_3 > 39) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_4 > 49) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001040_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_6 > 20) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001040_2 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_7 > 42) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001040_12) & 127;
    if (stage_v_8 > 49) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_9 > 33) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001040_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001040_7 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_11 > 38) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001040_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_13 > 32) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_14 > 24) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_15 > 48) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001040_3) & 127;
    if (stage_v_16 > 42) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001040_2 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_17 > 39) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001040_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001040_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_20 > 44) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_21 > 45) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001040_1 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_22 > 50) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_23 > 21) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001040_14 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001040_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_26 > 21) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_27 > 31) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_28 > 46) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001040_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001040_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001040_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001040_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_33 > 46) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001040_11 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_34 > 32) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_35 > 47) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001040_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001040_1 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_37 > 30) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_38 > 48) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_39 > 25) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001040_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_41 > 31) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_42 > 22) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001040_14 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_43 > 36) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001040_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001040_6 ^ 0x2A) * 2 + pub_r001040_3) & 127;
    if (stage_v_46 > 23) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_47 > 29) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_48 > 39) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_49 > 40) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001040_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001040_6 ^ 0x2A) * 2 + pub_r001040_2) & 127;
    if (stage_v_51 > 26) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_52 > 40) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001040_6 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_53 > 34) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_54 > 21) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_55 > 38) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001040_2 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_56 > 49) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001040_18 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_57 > 21) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001040_17 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_58 > 47) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001040_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_60 > 41) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001040_2) & 127;
    if (stage_v_61 > 37) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_63 > 40) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001040_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_65 > 37) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001040_1 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_66 > 22) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_67 > 35) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001040_19) & 127;
    if (stage_v_68 > 35) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001040_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001040_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001040_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_72 > 49) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001040_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001040_15 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_74 > 34) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001040_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001040_5 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_78 > 39) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_79 > 25) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001040_2 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_80 > 39) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001040_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_82 > 40) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_84 > 36) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_85 > 35) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001040_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001040_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_88 > 34) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001040_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001040_17 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_90 > 45) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_91 > 42) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_92 > 32) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_93 > 33) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001040_13 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_94 > 21) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001040_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_96 > 30) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_97 > 35) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_98 > 47) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001040_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_100 > 26) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001040_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_102 > 35) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_103 > 48) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001040_19) & 127;
    if (stage_v_104 > 47) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_105 > 39) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_106 > 23) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_107 > 23) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001040_19) & 127;
    if (stage_v_108 > 42) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_109 > 33) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_110 > 36) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001040_5 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_111 > 44) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001040_2) & 127;
    if (stage_v_112 > 43) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_113 > 24) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r001040_15 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001040_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001040_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_117 > 22) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_118 > 27) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001040_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001040_7 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_120 > 29) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_121 > 28) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_122 > 21) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001040_7 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_123 > 20) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_124 > 30) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001040_7 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_125 > 28) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_126 > 43) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_127 > 32) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001040_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_129 > 29) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001040_14 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_130 > 34) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001040_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001040_18 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_132 > 32) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_133 > 48) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_134 > 36) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001040_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_136 > 44) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_137 > 45) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_138 > 20) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001040_11 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_139 > 44) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_140 > 46) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_141 > 32) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_142 > 41) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_143 > 35) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_144 > 23) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_145 > 41) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001040_6 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_146 > 23) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001040_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_148 > 23) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001040_12) & 127;
    if (stage_v_149 > 20) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001040_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001040_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001040_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001040_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_154 > 31) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_155 > 25) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_156 > 34) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_157 > 30) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001040_2) & 127;
    if (stage_v_158 > 44) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_159 > 34) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_160 > 34) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_161 > 20) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_162 > 34) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001040_3) & 127;
    if (stage_v_163 > 41) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_164 > 38) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_166 > 42) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001040_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_168 > 41) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001040_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001040_1 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_170 > 24) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001040_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_172 > 24) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_173 > 37) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001040_3) & 127;
    if (stage_v_174 > 47) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001040_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_176 > 20) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001040_11 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_177 > 20) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_179 > 32) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_180 > 36) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_181 > 23) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_182 > 48) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_183 > 42) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_184 > 43) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001040_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_186 > 34) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001040_7 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_187 > 33) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_188 > 21) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001040_11) & 127;
    if (stage_v_189 > 26) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_190 > 44) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_191 > 26) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_184 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_192 > 44) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001040_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001040_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001040_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001040_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_197 > 41) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001040_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_199 > 35) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_200 > 21) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_201 > 25) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_202 > 33) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001040_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_204 > 27) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001040_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_206 > 39) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_207 > 24) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001040_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001040_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001040_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001040_2) & 127;
    if (stage_v_211 > 40) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001040_7) & 127;
    if (stage_v_212 > 44) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001040_6) & 127;
    if (stage_v_213 > 46) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_15) & 127;
    if (stage_v_214 > 28) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_186 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_215 > 33) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_216 > 39) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_217 > 28) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_218 > 40) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_219 > 49) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001040_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_221 > 41) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_222 > 35) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001040_16) & 127;
    if (stage_v_223 > 23) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001040_19) & 127;
    if (stage_v_224 > 46) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001040_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001040_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001040_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_228 > 23) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_228 ^ 0x2A) * 2 + pub_r001040_12) & 127;
    if (stage_v_229 > 27) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001040_3) & 127;
    if (stage_v_230 > 30) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_231 > 22) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001040_14) & 127;
    if (stage_v_232 > 24) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001040_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_234 > 32) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001040_10) & 127;
    if (stage_v_235 > 42) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001040_19) & 127;
    if (stage_v_236 > 39) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_237 > 40) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001040_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001040_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001040_0) & 127;
    if (stage_v_240 > 24) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001040_8) & 127;
    if (stage_v_241 > 24) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_218 ^ 0x2A) * 2 + pub_r001040_17) & 127;
    if (stage_v_242 > 42) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_243 > 43) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_244 > 38) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001040_1) & 127;
    if (stage_v_245 > 50) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001040_13) & 127;
    if (stage_v_246 > 26) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_247 > 28) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001040_18) & 127;
    if (stage_v_248 > 44) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001040_4) & 127;
    if (stage_v_249 > 26) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001040_12) & 127;
    if (stage_v_250 > 30) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001040_12) & 127;
    if (stage_v_251 > 43) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001040_5) & 127;
    if (stage_v_252 > 46) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_245 ^ 0x2A) * 2 + pub_r001040_9) & 127;
    if (stage_v_253 > 42) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001040_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001040_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
