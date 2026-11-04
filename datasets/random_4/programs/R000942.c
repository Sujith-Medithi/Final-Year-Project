/*
 * Benchmark Program: R000942
 * Family: mixed_control_data
 * Generator Seed: 494213
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000942_4213_0 {
    short watermark;
    short state;
    int checksum;
    int capacity;
    unsigned char head;
    int tail;
    int buffer[3];
};

struct FilterState_R000942_4213_1 {
    int mode;
    short prev_out;
    unsigned char prev_in;
    int buffer[3];
};

struct CipherContext_R000942_4213_2 {
    int counter;
    int iv;
    unsigned char nonce;
    unsigned char flags;
    unsigned char tag;
    int round_key;
    int buffer[3];
};

union TelemetryField_R000942_4213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000942_4213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000942_4213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tracker_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_14) & 63;
    acc ^= aux;
    int offset_53 = (aux + st.buffer[1]) & 3;
    switch (offset_53) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000942_4213_1(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_50 = (aux + st.buffer[1]) & 3;
    switch (anchor_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000942_4213_2(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_63 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_63 > 39) {
        acc = (acc + damping_63 * 2 + 5) & 127;
        aux ^= (damping_63 & 15);
    } else {
        acc = (acc - damping_63 + 11) & 127;
        aux += 3;
    }
    int parity_87 = 0;
    for (int k = 0; k < 2; k++) {
        parity_87 = (parity_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_87) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_15 = (aux + st.buffer[1]) & 3;
    switch (residue_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000942_4213_3(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_97 = (aux + st.buffer[1]) & 3;
    switch (tally_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_61 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_61 > 13) {
        acc = (acc + bound_61 * 2 + 5) & 127;
        aux ^= (bound_61 & 15);
    } else {
        acc = (acc - bound_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_23 = local_arr[aux % 3];
    acc = (acc + weight_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_4(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_47 = 0;
    for (int k = 0; k < 3; k++) {
        tally_47 = (tally_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_47) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_59 = (aux + st.buffer[1]) & 3;
    switch (stride_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000942_4213_5(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000942_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_74 = (aux + st.buffer[1]) & 3;
    switch (margin_74) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_50 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_50 > 19) {
        acc = (acc + margin_50 * 2 + 5) & 127;
        aux ^= (margin_50 & 15);
    } else {
        acc = (acc - margin_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_6(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_66 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_66 = (accumulator_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_66) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_27 = local_arr[aux % 3];
    acc = (acc + tracker_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_86 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_86 > 12) {
        acc = (acc + parity_86 * 2 + 5) & 127;
        aux ^= (parity_86 & 15);
    } else {
        acc = (acc - parity_86 + 11) & 127;
        aux += 3;
    }
    int anchor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_35 = local_arr[aux % 3];
    acc = (acc + cursor_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int accumulator_27 = local_arr[aux % 3];
    acc = (acc + accumulator_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_53 = (aux + st.buffer[1]) & 3;
    switch (segment_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000942_4213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_96) & 63;
    acc ^= aux;
    int accumulator_45 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_45 = (accumulator_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_45) & 127;
    }
    int bound_23 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_23 > 26) {
        acc = (acc + bound_23 * 2 + 5) & 127;
        aux ^= (bound_23 & 15);
    } else {
        acc = (acc - bound_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000942_4213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_41 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_41 > 43) {
        acc = (acc + metric_41 * 2 + 5) & 127;
        aux ^= (metric_41 & 15);
    } else {
        acc = (acc - metric_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_27 = local_arr[aux % 3];
    acc = (acc + mask_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_11(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int quotient_58 = local_arr[aux % 3];
    acc = (acc + quotient_58 * 2) & 127;
    int mask_31 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_31 > 15) {
        acc = (acc + mask_31 * 2 + 5) & 127;
        aux ^= (mask_31 & 15);
    } else {
        acc = (acc - mask_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_12(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_90 = (aux + st.buffer[1]) & 3;
    switch (tally_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_15) & 63;
    acc ^= aux;
    int anchor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_39 > 48) {
        acc = (acc + anchor_39 * 2 + 5) & 127;
        aux ^= (anchor_39 & 15);
    } else {
        acc = (acc - anchor_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_17 = local_arr[aux % 3];
    acc = (acc + index_reg_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_13(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_35 = (aux + st.buffer[1]) & 3;
    switch (mask_35) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_80 = (st.buffer[0] * 3 + aux) & 63;
    if (window_80 > 47) {
        acc = (acc + window_80 * 2 + 5) & 127;
        aux ^= (window_80 & 15);
    } else {
        acc = (acc - window_80 + 11) & 127;
        aux += 3;
    }
    int anchor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000942_4213_14(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000942_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int scale_99 = 0;
    for (int k = 0; k < 2; k++) {
        scale_99 = (scale_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_99) & 127;
    }
    int accumulator_50 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_50 > 23) {
        acc = (acc + accumulator_50 * 2 + 5) & 127;
        aux ^= (accumulator_50 & 15);
    } else {
        acc = (acc - accumulator_50 + 11) & 127;
        aux += 3;
    }
    int cursor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_91 = local_arr[aux % 3];
    acc = (acc + bound_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000942_4213_15(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000942_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_58) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_85 = (aux + st.buffer[1]) & 3;
    switch (weight_85) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_43 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_43 > 42) {
        acc = (acc + vector_43 * 2 + 5) & 127;
        aux ^= (vector_43 & 15);
    } else {
        acc = (acc - vector_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000942_0;
    int sec_r000942_1;
    int sec_r000942_2;
    int sec_r000942_3;
    int sec_r000942_4;
    int sec_r000942_5;
    int sec_r000942_6;
    int sec_r000942_7;
    int sec_r000942_8;
    int sec_r000942_9;
    int sec_r000942_10;
    int sec_r000942_11;
    int sec_r000942_12;
    int sec_r000942_13;
    int sec_r000942_14;
    int sec_r000942_15;
    int sec_r000942_16;
    int sec_r000942_17;
    int sec_r000942_18;
    int pub_r000942_0;
    int pub_r000942_1;
    int pub_r000942_2;
    int pub_r000942_3;
    int pub_r000942_4;
    int pub_r000942_5;
    int pub_r000942_6;
    int pub_r000942_7;
    int pub_r000942_8;
    int pub_r000942_9;
    int pub_r000942_10;
    int pub_r000942_11;
    int pub_r000942_12;
    int pub_r000942_13;
    int pub_r000942_14;
    int pub_r000942_15;
    int pub_r000942_16;
    int pub_r000942_17;
    int pub_r000942_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000942_0 >= -100 && pub_r000942_0 <= 100);
    __CPROVER_assume(pub_r000942_1 >= -100 && pub_r000942_1 <= 100);
    __CPROVER_assume(pub_r000942_2 >= -100 && pub_r000942_2 <= 100);
    __CPROVER_assume(pub_r000942_3 >= -100 && pub_r000942_3 <= 100);
    __CPROVER_assume(pub_r000942_4 >= -100 && pub_r000942_4 <= 100);
    __CPROVER_assume(pub_r000942_5 >= -100 && pub_r000942_5 <= 100);
    __CPROVER_assume(pub_r000942_6 >= -100 && pub_r000942_6 <= 100);
    __CPROVER_assume(pub_r000942_7 >= -100 && pub_r000942_7 <= 100);
    __CPROVER_assume(pub_r000942_8 >= -100 && pub_r000942_8 <= 100);
    __CPROVER_assume(pub_r000942_9 >= -100 && pub_r000942_9 <= 100);
    __CPROVER_assume(pub_r000942_10 >= -100 && pub_r000942_10 <= 100);
    __CPROVER_assume(pub_r000942_11 >= -100 && pub_r000942_11 <= 100);
    __CPROVER_assume(pub_r000942_12 >= -100 && pub_r000942_12 <= 100);
    __CPROVER_assume(pub_r000942_13 >= -100 && pub_r000942_13 <= 100);
    __CPROVER_assume(pub_r000942_14 >= -100 && pub_r000942_14 <= 100);
    __CPROVER_assume(pub_r000942_15 >= -100 && pub_r000942_15 <= 100);
    __CPROVER_assume(pub_r000942_16 >= -100 && pub_r000942_16 <= 100);
    __CPROVER_assume(pub_r000942_17 >= -100 && pub_r000942_17 <= 100);
    __CPROVER_assume(pub_r000942_18 >= -100 && pub_r000942_18 <= 100);
    __CPROVER_assume(sec_r000942_0 >= 0 && sec_r000942_0 <= 255);
    __CPROVER_assume(sec_r000942_1 >= 0 && sec_r000942_1 <= 255);
    __CPROVER_assume(sec_r000942_2 >= 0 && sec_r000942_2 <= 255);
    __CPROVER_assume(sec_r000942_3 >= 0 && sec_r000942_3 <= 255);
    __CPROVER_assume(sec_r000942_4 >= 0 && sec_r000942_4 <= 255);
    __CPROVER_assume(sec_r000942_5 >= 0 && sec_r000942_5 <= 255);
    __CPROVER_assume(sec_r000942_6 >= 0 && sec_r000942_6 <= 255);
    __CPROVER_assume(sec_r000942_7 >= 0 && sec_r000942_7 <= 255);
    __CPROVER_assume(sec_r000942_8 >= 0 && sec_r000942_8 <= 255);
    __CPROVER_assume(sec_r000942_9 >= 0 && sec_r000942_9 <= 255);
    __CPROVER_assume(sec_r000942_10 >= 0 && sec_r000942_10 <= 255);
    __CPROVER_assume(sec_r000942_11 >= 0 && sec_r000942_11 <= 255);
    __CPROVER_assume(sec_r000942_12 >= 0 && sec_r000942_12 <= 255);
    __CPROVER_assume(sec_r000942_13 >= 0 && sec_r000942_13 <= 255);
    __CPROVER_assume(sec_r000942_14 >= 0 && sec_r000942_14 <= 255);
    __CPROVER_assume(sec_r000942_15 >= 0 && sec_r000942_15 <= 255);
    __CPROVER_assume(sec_r000942_16 >= 0 && sec_r000942_16 <= 255);
    __CPROVER_assume(sec_r000942_17 >= 0 && sec_r000942_17 <= 255);
    __CPROVER_assume(sec_r000942_18 >= 0 && sec_r000942_18 <= 255);

    struct StreamBuffer_R000942_4213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000942_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000942_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000942_0 + 7) & 15;
    struct FilterState_R000942_4213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000942_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000942_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000942_0 + 9) & 15;
    struct CipherContext_R000942_4213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000942_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000942_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000942_0 + 11) & 15;

    union TelemetryField_R000942_4213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 29) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 44) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 39) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 54) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 25) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 40) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 25) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 40) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 19) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 34) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 34) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 49) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 18) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 33) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[2] * 2 + 202) & 63;
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
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 29) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 44) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 17) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 32) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 11) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 26) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_2.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 14) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 29) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[1] * 2 + 316) & 63;
    if (stage_v_103 > 22) {
        out_sink = (out_sink + stage_v_103 - 5) & 255;
        if (stage_v_103 > 37) {
            chk_sum ^= (stage_v_103 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_103 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 31) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 46) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] ^ 117) & 3;
    switch (stage_v_114) {
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

    /* Execution Pipeline Stage 115 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = table[1];
    table[1] = (table[2] + 243) & 63;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (out_sink > 100) ? (chk_sum & 31) : (132 & 31);
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= (stage_v_127 << 1) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_128 = (stage_v_128 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 15) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 30) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 135 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_136 = (stage_v_136 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (out_sink > 100) ? (chk_sum & 31) : (145 & 31);
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= (stage_v_140 << 1) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
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

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 33) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 48) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_153 = (stage_v_153 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_2.buffer[2] * 2 + 472) & 63;
    if (stage_v_155 > 27) {
        out_sink = (out_sink + stage_v_155 - 5) & 255;
        if (stage_v_155 > 42) {
            chk_sum ^= (stage_v_155 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_155 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[0] ^ 160) & 3;
    switch (stage_v_157) {
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

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_1.buffer[0] ^ 163) & 3;
    switch (stage_v_160) {
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

    /* Execution Pipeline Stage 161 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 162) & 15;
    int stage_v_161 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= stage_v_161;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 32) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 47) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 18) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 33) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 169) & 15;
    int stage_v_168 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= stage_v_168;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_0.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 27) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 42) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (out_sink > 100) ? (chk_sum & 31) : (181 & 31);
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= (stage_v_176 << 1) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_1.buffer[1] * 2 + 541) & 63;
    if (stage_v_178 > 36) {
        out_sink = (out_sink + stage_v_178 - 5) & 255;
        if (stage_v_178 > 51) {
            chk_sum ^= (stage_v_178 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_178 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (out_sink > 100) ? (chk_sum & 31) : (184 & 31);
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= (stage_v_179 << 1) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (out_sink > 100) ? (chk_sum & 31) : (185 & 31);
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= (stage_v_180 << 1) & 127;

    /* Execution Pipeline Stage 181 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 182) & 15;
    int stage_v_181 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= stage_v_181;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_2.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000942_3 ^ 0x55) & 63;
    if (m_var > 34) {
        out_sink += (m_var * 2 + pub_r000942_2) & 127;
    } else {
        out_sink -= (m_var + 8) & 31;
    }
    out_sink ^= (sec_r000942_18 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
