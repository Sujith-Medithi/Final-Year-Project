/*
 * Benchmark Program: R001435
 * Security Family: bitwise_flow
 * Generator Seed: 643513
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001435_3513_0 {
    int rate;
    int status;
    int account_id;
    short fee;
    unsigned char balance;
    int buffer[3];
};

struct AudioFrame_R001435_3513_1 {
    short peak;
    int channels;
    int sample_rate;
    int rms;
    int gain;
    short envelope;
    int buffer[3];
};

struct FilterState_R001435_3513_2 {
    unsigned char prev_out;
    short cutoff;
    unsigned char damping;
    int gain_db;
    int mode;
    int prev_in;
    int buffer[3];
};

union TelemetryField_R001435_3513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001435_3513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001435_3513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int bound_48 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_48 > 29) {
        acc = (acc + bound_48 * 2 + 5) & 127;
        aux ^= (bound_48 & 15);
    } else {
        acc = (acc - bound_48 + 11) & 127;
        aux += 3;
    }
    int vector_13 = 0;
    for (int k = 0; k < 3; k++) {
        vector_13 = (vector_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_96) & 63;
    acc ^= aux;
    int factor_17 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_17 > 13) {
        acc = (acc + factor_17 * 2 + 5) & 127;
        aux ^= (factor_17 & 15);
    } else {
        acc = (acc - factor_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_84) & 63;
    acc ^= aux;
    int window_23 = 0;
    for (int k = 0; k < 2; k++) {
        window_23 = (window_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_23) & 127;
    }
    int scale_58 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_58 > 33) {
        acc = (acc + scale_58 * 2 + 5) & 127;
        aux ^= (scale_58 & 15);
    } else {
        acc = (acc - scale_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_3(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int mask_58 = (aux + st.buffer[1]) & 3;
    switch (mask_58) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_81 = local_arr[aux % 3];
    acc = (acc + bound_81 * 2) & 127;
    int threshold_65 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_65 > 21) {
        acc = (acc + threshold_65 * 2 + 5) & 127;
        aux ^= (threshold_65 & 15);
    } else {
        acc = (acc - threshold_65 + 11) & 127;
        aux += 3;
    }
    int cursor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001435_3513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tracker_37 = local_arr[aux % 3];
    acc = (acc + tracker_37 * 2) & 127;
    int cursor_66 = (aux + st.buffer[1]) & 3;
    switch (cursor_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_87) & 63;
    acc ^= aux;
    int parity_96 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_96 > 26) {
        acc = (acc + parity_96 * 2 + 5) & 127;
        aux ^= (parity_96 & 15);
    } else {
        acc = (acc - parity_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_5(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_70 = local_arr[aux % 3];
    acc = (acc + mask_70 * 2) & 127;
    int residue_74 = (aux + st.buffer[1]) & 3;
    switch (residue_74) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_54) & 63;
    acc ^= aux;
    int anchor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_20 > 29) {
        acc = (acc + anchor_20 * 2 + 5) & 127;
        aux ^= (anchor_20 & 15);
    } else {
        acc = (acc - anchor_20 + 11) & 127;
        aux += 3;
    }
    int tracker_52 = (aux + st.buffer[1]) & 3;
    switch (tracker_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001435_3513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_87) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001435_3513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_98 = (aux + st.buffer[1]) & 3;
    switch (factor_98) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_87 = local_arr[aux % 3];
    acc = (acc + quotient_87 * 2) & 127;
    int tracker_91 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_91 = (tracker_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_9(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int weight_12 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_12 > 12) {
        acc = (acc + weight_12 * 2 + 5) & 127;
        aux ^= (weight_12 & 15);
    } else {
        acc = (acc - weight_12 + 11) & 127;
        aux += 3;
    }
    int metric_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_79) & 63;
    acc ^= aux;
    int threshold_23 = (aux + st.buffer[1]) & 3;
    switch (threshold_23) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_73 = 0;
    for (int k = 0; k < 2; k++) {
        segment_73 = (segment_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_18) & 63;
    acc ^= aux;
    int index_reg_30 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_30 > 31) {
        acc = (acc + index_reg_30 * 2 + 5) & 127;
        aux ^= (index_reg_30 & 15);
    } else {
        acc = (acc - index_reg_30 + 11) & 127;
        aux += 3;
    }
    int damping_89 = 0;
    for (int k = 0; k < 2; k++) {
        damping_89 = (damping_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_89) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int threshold_50 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_50 = (threshold_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001435_3513_12(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001435_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_86 = 0;
    for (int k = 0; k < 3; k++) {
        delta_86 = (delta_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_86) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001435_3513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001435_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_68 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_68 > 12) {
        acc = (acc + parity_68 * 2 + 5) & 127;
        aux ^= (parity_68 & 15);
    } else {
        acc = (acc - parity_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_66 = local_arr[aux % 3];
    acc = (acc + sample_66 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001435_0;
    int sec_r001435_1;
    int sec_r001435_2;
    int sec_r001435_3;
    int sec_r001435_4;
    int sec_r001435_5;
    int sec_r001435_6;
    int sec_r001435_7;
    int sec_r001435_8;
    int sec_r001435_9;
    int sec_r001435_10;
    int sec_r001435_11;
    int sec_r001435_12;
    int sec_r001435_13;
    int sec_r001435_14;
    int sec_r001435_15;
    int pub_r001435_0;
    int pub_r001435_1;
    int pub_r001435_2;
    int pub_r001435_3;
    int pub_r001435_4;
    int pub_r001435_5;
    int pub_r001435_6;
    int pub_r001435_7;
    int pub_r001435_8;
    int pub_r001435_9;
    int pub_r001435_10;
    int pub_r001435_11;
    int pub_r001435_12;
    int pub_r001435_13;
    int pub_r001435_14;
    int pub_r001435_15;
    int pub_r001435_16;
    int pub_r001435_17;
    int pub_r001435_18;
    int pub_r001435_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001435_0 >= -100 && pub_r001435_0 <= 100);
    __CPROVER_assume(pub_r001435_1 >= -100 && pub_r001435_1 <= 100);
    __CPROVER_assume(pub_r001435_2 >= -100 && pub_r001435_2 <= 100);
    __CPROVER_assume(pub_r001435_3 >= -100 && pub_r001435_3 <= 100);
    __CPROVER_assume(pub_r001435_4 >= -100 && pub_r001435_4 <= 100);
    __CPROVER_assume(pub_r001435_5 >= -100 && pub_r001435_5 <= 100);
    __CPROVER_assume(pub_r001435_6 >= -100 && pub_r001435_6 <= 100);
    __CPROVER_assume(pub_r001435_7 >= -100 && pub_r001435_7 <= 100);
    __CPROVER_assume(pub_r001435_8 >= -100 && pub_r001435_8 <= 100);
    __CPROVER_assume(pub_r001435_9 >= -100 && pub_r001435_9 <= 100);
    __CPROVER_assume(pub_r001435_10 >= -100 && pub_r001435_10 <= 100);
    __CPROVER_assume(pub_r001435_11 >= -100 && pub_r001435_11 <= 100);
    __CPROVER_assume(pub_r001435_12 >= -100 && pub_r001435_12 <= 100);
    __CPROVER_assume(pub_r001435_13 >= -100 && pub_r001435_13 <= 100);
    __CPROVER_assume(pub_r001435_14 >= -100 && pub_r001435_14 <= 100);
    __CPROVER_assume(pub_r001435_15 >= -100 && pub_r001435_15 <= 100);
    __CPROVER_assume(pub_r001435_16 >= -100 && pub_r001435_16 <= 100);
    __CPROVER_assume(pub_r001435_17 >= -100 && pub_r001435_17 <= 100);
    __CPROVER_assume(pub_r001435_18 >= -100 && pub_r001435_18 <= 100);
    __CPROVER_assume(pub_r001435_19 >= -100 && pub_r001435_19 <= 100);
    __CPROVER_assume(sec_r001435_0 >= 0 && sec_r001435_0 <= 255);
    __CPROVER_assume(sec_r001435_1 >= 0 && sec_r001435_1 <= 255);
    __CPROVER_assume(sec_r001435_2 >= 0 && sec_r001435_2 <= 255);
    __CPROVER_assume(sec_r001435_3 >= 0 && sec_r001435_3 <= 255);
    __CPROVER_assume(sec_r001435_4 >= 0 && sec_r001435_4 <= 255);
    __CPROVER_assume(sec_r001435_5 >= 0 && sec_r001435_5 <= 255);
    __CPROVER_assume(sec_r001435_6 >= 0 && sec_r001435_6 <= 255);
    __CPROVER_assume(sec_r001435_7 >= 0 && sec_r001435_7 <= 255);
    __CPROVER_assume(sec_r001435_8 >= 0 && sec_r001435_8 <= 255);
    __CPROVER_assume(sec_r001435_9 >= 0 && sec_r001435_9 <= 255);
    __CPROVER_assume(sec_r001435_10 >= 0 && sec_r001435_10 <= 255);
    __CPROVER_assume(sec_r001435_11 >= 0 && sec_r001435_11 <= 255);
    __CPROVER_assume(sec_r001435_12 >= 0 && sec_r001435_12 <= 255);
    __CPROVER_assume(sec_r001435_13 >= 0 && sec_r001435_13 <= 255);
    __CPROVER_assume(sec_r001435_14 >= 0 && sec_r001435_14 <= 255);
    __CPROVER_assume(sec_r001435_15 >= 0 && sec_r001435_15 <= 255);

    struct Transaction_R001435_3513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001435_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001435_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001435_0 + 7) & 15;
    struct AudioFrame_R001435_3513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001435_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001435_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001435_0 + 9) & 15;
    struct FilterState_R001435_3513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001435_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001435_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001435_0 + 11) & 15;

    union TelemetryField_R001435_3513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001435_3513_0(sec_r001435_0, sec_r001435_1, pub_r001435_2, pub_r001435_3);
    int helper_flow_1 = fn_R001435_3513_1(sec_r001435_1, pub_r001435_2, pub_r001435_3, pub_r001435_4, pub_r001435_5);
    int helper_flow_2 = fn_R001435_3513_2(sec_r001435_2, pub_r001435_3, pub_r001435_4, pub_r001435_5);
    int helper_flow_3 = fn_R001435_3513_3(sec_r001435_3, pub_r001435_4, pub_r001435_5);
    int helper_flow_4 = fn_R001435_3513_4(sec_r001435_4, sec_r001435_5, pub_r001435_6, pub_r001435_7);
    int helper_flow_5 = fn_R001435_3513_5(sec_r001435_5, sec_r001435_6, pub_r001435_7);
    int helper_flow_6 = fn_R001435_3513_6(sec_r001435_6, pub_r001435_7, pub_r001435_8, pub_r001435_9);
    int helper_flow_7 = fn_R001435_3513_7(sec_r001435_7, sec_r001435_8, pub_r001435_9, pub_r001435_10, pub_r001435_11);
    int helper_flow_8 = fn_R001435_3513_8(sec_r001435_8, pub_r001435_9, pub_r001435_10, pub_r001435_11, pub_r001435_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001435_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001435_10 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001435_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001435_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001435_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001435_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001435_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001435_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_1 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001435_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001435_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_1 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_7 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001435_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_8 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001435_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_5 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001435_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_8 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001435_0 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_8 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001435_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001435_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_3 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_7 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001435_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001435_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001435_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001435_3 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001435_7 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001435_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_1 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001435_3 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001435_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001435_14 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001435_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001435_11 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001435_10 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001435_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001435_1 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_11 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001435_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_1 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001435_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001435_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_20 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_24 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_1 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_12 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_46 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001435_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001435_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_16 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001435_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001435_1 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001435_4 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_0 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_49 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001435_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001435_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001435_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001435_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_24 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001435_3 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001435_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001435_10 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001435_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_62 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001435_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001435_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001435_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001435_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_31 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001435_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001435_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001435_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((helper_flow_3 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((helper_flow_6 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001435_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001435_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001435_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_7 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001435_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001435_8 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001435_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001435_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001435_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001435_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001435_9 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_48 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_77 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001435_7 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001435_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_4 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_65 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_3 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001435_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_42 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001435_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001435_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_6 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_19 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((helper_flow_7 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_7 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_24 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001435_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001435_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_103 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001435_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_77 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001435_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001435_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((helper_flow_0 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001435_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_1 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001435_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001435_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001435_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001435_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_57 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_54 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001435_7 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_109 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001435_14 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_95 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001435_0 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001435_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_97 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001435_7 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001435_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_65 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001435_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_112 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_32 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_20 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001435_4 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_57 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001435_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001435_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_45 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_47 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001435_4 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001435_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_48 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001435_8 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_67 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001435_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_31 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_57 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_134 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001435_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001435_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_128 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_102 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001435_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001435_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_34 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_0 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001435_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001435_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_76 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_76 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_143 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001435_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_46 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_47 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001435_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001435_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_94 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001435_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001435_15 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_63 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_1 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_160 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_14 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001435_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001435_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001435_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_128 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001435_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_165 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001435_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001435_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001435_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001435_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_94 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_136 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_28 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001435_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_172 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_8 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_57 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001435_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001435_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001435_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001435_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001435_7 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_11 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_125 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001435_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001435_10 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001435_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001435_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_20 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001435_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001435_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001435_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001435_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_11 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001435_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001435_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_132 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_14 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_174 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001435_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001435_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001435_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_1 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_57 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001435_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001435_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_65 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_218 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001435_1 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001435_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_40 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_156 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_77 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_109 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_198 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001435_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001435_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001435_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_57 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_140 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001435_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_173 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001435_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_162 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_112 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_134 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_130 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_56 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001435_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_67 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001435_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001435_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001435_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_121 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_200 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001435_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_112 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001435_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001435_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_20 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_239 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001435_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_114 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001435_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_123 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001435_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001435_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001435_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_145 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001435_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001435_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((sec_r001435_5 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001435_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001435_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_42 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_259 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001435_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001435_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001435_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001435_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001435_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((helper_flow_3 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_121 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001435_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001435_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r001435_13 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001435_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((helper_flow_8 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_229 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_20 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((helper_flow_5 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001435_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001435_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_28 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_81 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001435_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_172 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001435_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001435_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_259 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_31 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_145 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001435_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001435_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001435_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001435_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001435_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_294 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_190 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001435_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_23 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001435_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_140 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_55 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r001435_6 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_72 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r001435_12 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_165 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001435_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_259 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001435_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001435_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_40 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001435_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_136 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001435_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_55 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_283 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001435_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_123 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_238 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001435_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_1 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_18 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_14 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001435_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001435_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_18 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001435_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001435_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001435_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_228 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_125 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001435_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_127 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((sec_r001435_9 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((helper_flow_1 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001435_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_180 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_162 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001435_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001435_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_54 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_223 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_63 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001435_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001435_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001435_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001435_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001435_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_189 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001435_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_139 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((helper_flow_3 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001435_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001435_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_295 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001435_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001435_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_122 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001435_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001435_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001435_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001435_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_358 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001435_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_364 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_348 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_46 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((sec_r001435_7 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((sec_r001435_5 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001435_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_36 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_147 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001435_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_317 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001435_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_303 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_18 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001435_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_344 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_305 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_288 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_114 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001435_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001435_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_49 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_305 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001435_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001435_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001435_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001435_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_211 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_289 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_107 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_276 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001435_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_18 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_225 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001435_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_12 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001435_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001435_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_23 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_42 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001435_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_307 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_134 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_263 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_88 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001435_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_34 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001435_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001435_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001435_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_339 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_289 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_141 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001435_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_49 << 1) ^ (pub_r001435_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001435_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001435_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001435_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_128 << 1) ^ (pub_r001435_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_385 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_65 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001435_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001435_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_422 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001435_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_94 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_72 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001435_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001435_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((sec_r001435_2 << 1) ^ (pub_r001435_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_81 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001435_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_255 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_309 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_145 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_305 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001435_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_102 << 1) ^ (pub_r001435_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001435_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_24 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001435_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001435_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001435_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_162 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_453 + 1) & 15;
    out_sink ^= (stage_v_453 & 63);

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_16 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_454 + 1) & 15;
    out_sink ^= (stage_v_454 & 63);

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001435_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_11 << 1) ^ (pub_r001435_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_456 + 1) & 15;
    out_sink ^= (stage_v_456 & 63);

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001435_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_20 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001435_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_284 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001435_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_42 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_76 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_463 + 1) & 15;
    out_sink ^= (stage_v_463 & 63);

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001435_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_37 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_465 + 1) & 15;
    out_sink ^= (stage_v_465 & 63);

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_361 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((sec_r001435_4 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_382 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((sec_r001435_5 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_469 + 1) & 15;
    out_sink ^= (stage_v_469 & 63);

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((stage_v_37 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_470 + 1) & 15;
    out_sink ^= (stage_v_470 & 63);

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_114 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_471 + 1) & 15;
    out_sink ^= (stage_v_471 & 63);

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_453 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_257 << 1) ^ (pub_r001435_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_473 + 1) & 15;
    out_sink ^= (stage_v_473 & 63);

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001435_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001435_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001435_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_403 << 1) ^ (pub_r001435_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_477 + 1) & 15;
    out_sink ^= (stage_v_477 & 63);

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001435_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_241 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_479 + 1) & 15;
    out_sink ^= (stage_v_479 & 63);

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_160 << 1) ^ (pub_r001435_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_480 + 1) & 15;
    out_sink ^= (stage_v_480 & 63);

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = ((stage_v_349 << 1) ^ (pub_r001435_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_481 + 1) & 15;
    out_sink ^= (stage_v_481 & 63);

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001435_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_170 << 1) ^ (pub_r001435_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_483 + 1) & 15;
    out_sink ^= (stage_v_483 & 63);

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_14 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_484 + 1) & 15;
    out_sink ^= (stage_v_484 & 63);

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = ((stage_v_114 << 1) ^ (pub_r001435_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_485 + 1) & 15;
    out_sink ^= (stage_v_485 & 63);

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001435_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001435_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_285 << 1) ^ (pub_r001435_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_488 + 1) & 15;
    out_sink ^= (stage_v_488 & 63);

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = ((stage_v_152 << 1) ^ (pub_r001435_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_489 + 1) & 15;
    out_sink ^= (stage_v_489 & 63);

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = ((stage_v_336 << 1) ^ (pub_r001435_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_490 + 1) & 15;
    out_sink ^= (stage_v_490 & 63);

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001435_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001435_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001435_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_140 << 1) ^ (pub_r001435_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_494 + 1) & 15;
    out_sink ^= (stage_v_494 & 63);

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((sec_r001435_15 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_495 + 1) & 15;
    out_sink ^= (stage_v_495 & 63);

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001435_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_114 << 1) ^ (pub_r001435_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_497 + 1) & 15;
    out_sink ^= (stage_v_497 & 63);

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001435_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001435_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001435_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((stage_v_24 << 1) ^ (pub_r001435_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_501 + 1) & 15;
    out_sink ^= (stage_v_501 & 63);

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = ((sec_r001435_14 << 1) ^ (pub_r001435_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_502 + 1) & 15;
    out_sink ^= (stage_v_502 & 63);

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = ((stage_v_136 << 1) ^ (pub_r001435_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_503 + 1) & 15;
    out_sink ^= (stage_v_503 & 63);

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_186 << 1) ^ (pub_r001435_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_504 + 1) & 15;
    out_sink ^= (stage_v_504 & 63);

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001435_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001435_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001435_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001435_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
