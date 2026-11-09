/*
 * Benchmark Program: R001236
 * Security Family: implicit_flow
 * Generator Seed: 623613
 * High Inputs: 22 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001236_3613_0 {
    int damping;
    short mode;
    unsigned char prev_in;
    int buffer[3];
};

struct AudioFrame_R001236_3613_1 {
    int gain;
    int sample_rate;
    unsigned char envelope;
    unsigned char channels;
    int buffer[3];
};

struct EventLog_R001236_3613_2 {
    int facility;
    unsigned char seq;
    int timestamp;
    int buffer[3];
};

union PacketPayload_R001236_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001236_3613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001236_3613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001236_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_53 = (aux + st.buffer[1]) & 3;
    switch (factor_53) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_13) & 63;
    acc ^= aux;
    int vector_31 = 0;
    for (int k = 0; k < 2; k++) {
        vector_31 = (vector_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001236_3613_1(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001236_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_59 = local_arr[aux % 3];
    acc = (acc + mask_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_2(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001236_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_83 = local_arr[aux % 3];
    acc = (acc + threshold_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_3(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001236_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_57 = 0;
    for (int k = 0; k < 3; k++) {
        residue_57 = (residue_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_57) & 127;
    }
    int damping_42 = (aux + st.buffer[1]) & 3;
    switch (damping_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001236_3613_4(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001236_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_97) & 63;
    acc ^= aux;
    int tracker_95 = (aux + st.buffer[1]) & 3;
    switch (tracker_95) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_61 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_61 = (tracker_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_61) & 127;
    }
    int index_reg_37 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_37 > 16) {
        acc = (acc + index_reg_37 * 2 + 5) & 127;
        aux ^= (index_reg_37 & 15);
    } else {
        acc = (acc - index_reg_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001236_3613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int stride_26 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_26 > 27) {
        acc = (acc + stride_26 * 2 + 5) & 127;
        aux ^= (stride_26 & 15);
    } else {
        acc = (acc - stride_26 + 11) & 127;
        aux += 3;
    }
    int threshold_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_6(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001236_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_32 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_32 > 23) {
        acc = (acc + sample_32 * 2 + 5) & 127;
        aux ^= (sample_32 & 15);
    } else {
        acc = (acc - sample_32 + 11) & 127;
        aux += 3;
    }
    int metric_26 = (aux + st.buffer[1]) & 3;
    switch (metric_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001236_3613_7(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001236_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int index_reg_65 = (aux + st.buffer[1]) & 3;
    switch (index_reg_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_36 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_36 > 44) {
        acc = (acc + weight_36 * 2 + 5) & 127;
        aux ^= (weight_36 & 15);
    } else {
        acc = (acc - weight_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_29 = local_arr[aux % 3];
    acc = (acc + parity_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_8(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int damping_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_71) & 63;
    acc ^= aux;
    int delta_49 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_49 > 45) {
        acc = (acc + delta_49 * 2 + 5) & 127;
        aux ^= (delta_49 & 15);
    } else {
        acc = (acc - delta_49 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int mask_77 = local_arr[aux % 3];
    acc = (acc + mask_77 * 2) & 127;
    int window_51 = 0;
    for (int k = 0; k < 2; k++) {
        window_51 = (window_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_51) & 127;
    }
    int tally_51 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_51 > 27) {
        acc = (acc + tally_51 * 2 + 5) & 127;
        aux ^= (tally_51 & 15);
    } else {
        acc = (acc - tally_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001236_3613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001236_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int index_reg_87 = local_arr[aux % 3];
    acc = (acc + index_reg_87 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_48 = (aux + st.buffer[1]) & 3;
    switch (tally_48) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_44 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_44 = (pivot_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001236_3613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_39 = (aux + st.buffer[1]) & 3;
    switch (factor_39) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001236_3613_12(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001236_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int accumulator_23 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_23 > 20) {
        acc = (acc + accumulator_23 * 2 + 5) & 127;
        aux ^= (accumulator_23 & 15);
    } else {
        acc = (acc - accumulator_23 + 11) & 127;
        aux += 3;
    }
    int bound_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001236_3613_13(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int quotient_24 = local_arr[aux % 3];
    acc = (acc + quotient_24 * 2) & 127;
    int sample_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_74) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001236_3613_14(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001236_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_38 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_38 > 11) {
        acc = (acc + mask_38 * 2 + 5) & 127;
        aux ^= (mask_38 & 15);
    } else {
        acc = (acc - mask_38 + 11) & 127;
        aux += 3;
    }
    int margin_63 = (aux + st.buffer[1]) & 3;
    switch (margin_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001236_0;
    int sec_r001236_1;
    int sec_r001236_2;
    int sec_r001236_3;
    int sec_r001236_4;
    int sec_r001236_5;
    int sec_r001236_6;
    int sec_r001236_7;
    int sec_r001236_8;
    int sec_r001236_9;
    int sec_r001236_10;
    int sec_r001236_11;
    int sec_r001236_12;
    int sec_r001236_13;
    int sec_r001236_14;
    int sec_r001236_15;
    int sec_r001236_16;
    int sec_r001236_17;
    int sec_r001236_18;
    int sec_r001236_19;
    int sec_r001236_20;
    int sec_r001236_21;
    int pub_r001236_0;
    int pub_r001236_1;
    int pub_r001236_2;
    int pub_r001236_3;
    int pub_r001236_4;
    int pub_r001236_5;
    int pub_r001236_6;
    int pub_r001236_7;
    int pub_r001236_8;
    int pub_r001236_9;
    int pub_r001236_10;
    int pub_r001236_11;
    int pub_r001236_12;
    int pub_r001236_13;
    int pub_r001236_14;
    int pub_r001236_15;
    int pub_r001236_16;
    int pub_r001236_17;
    int pub_r001236_18;
    int pub_r001236_19;
    int pub_r001236_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001236_0 >= -100 && pub_r001236_0 <= 100);
    __CPROVER_assume(pub_r001236_1 >= -100 && pub_r001236_1 <= 100);
    __CPROVER_assume(pub_r001236_2 >= -100 && pub_r001236_2 <= 100);
    __CPROVER_assume(pub_r001236_3 >= -100 && pub_r001236_3 <= 100);
    __CPROVER_assume(pub_r001236_4 >= -100 && pub_r001236_4 <= 100);
    __CPROVER_assume(pub_r001236_5 >= -100 && pub_r001236_5 <= 100);
    __CPROVER_assume(pub_r001236_6 >= -100 && pub_r001236_6 <= 100);
    __CPROVER_assume(pub_r001236_7 >= -100 && pub_r001236_7 <= 100);
    __CPROVER_assume(pub_r001236_8 >= -100 && pub_r001236_8 <= 100);
    __CPROVER_assume(pub_r001236_9 >= -100 && pub_r001236_9 <= 100);
    __CPROVER_assume(pub_r001236_10 >= -100 && pub_r001236_10 <= 100);
    __CPROVER_assume(pub_r001236_11 >= -100 && pub_r001236_11 <= 100);
    __CPROVER_assume(pub_r001236_12 >= -100 && pub_r001236_12 <= 100);
    __CPROVER_assume(pub_r001236_13 >= -100 && pub_r001236_13 <= 100);
    __CPROVER_assume(pub_r001236_14 >= -100 && pub_r001236_14 <= 100);
    __CPROVER_assume(pub_r001236_15 >= -100 && pub_r001236_15 <= 100);
    __CPROVER_assume(pub_r001236_16 >= -100 && pub_r001236_16 <= 100);
    __CPROVER_assume(pub_r001236_17 >= -100 && pub_r001236_17 <= 100);
    __CPROVER_assume(pub_r001236_18 >= -100 && pub_r001236_18 <= 100);
    __CPROVER_assume(pub_r001236_19 >= -100 && pub_r001236_19 <= 100);
    __CPROVER_assume(pub_r001236_20 >= -100 && pub_r001236_20 <= 100);
    __CPROVER_assume(sec_r001236_0 >= 0 && sec_r001236_0 <= 255);
    __CPROVER_assume(sec_r001236_1 >= 0 && sec_r001236_1 <= 255);
    __CPROVER_assume(sec_r001236_2 >= 0 && sec_r001236_2 <= 255);
    __CPROVER_assume(sec_r001236_3 >= 0 && sec_r001236_3 <= 255);
    __CPROVER_assume(sec_r001236_4 >= 0 && sec_r001236_4 <= 255);
    __CPROVER_assume(sec_r001236_5 >= 0 && sec_r001236_5 <= 255);
    __CPROVER_assume(sec_r001236_6 >= 0 && sec_r001236_6 <= 255);
    __CPROVER_assume(sec_r001236_7 >= 0 && sec_r001236_7 <= 255);
    __CPROVER_assume(sec_r001236_8 >= 0 && sec_r001236_8 <= 255);
    __CPROVER_assume(sec_r001236_9 >= 0 && sec_r001236_9 <= 255);
    __CPROVER_assume(sec_r001236_10 >= 0 && sec_r001236_10 <= 255);
    __CPROVER_assume(sec_r001236_11 >= 0 && sec_r001236_11 <= 255);
    __CPROVER_assume(sec_r001236_12 >= 0 && sec_r001236_12 <= 255);
    __CPROVER_assume(sec_r001236_13 >= 0 && sec_r001236_13 <= 255);
    __CPROVER_assume(sec_r001236_14 >= 0 && sec_r001236_14 <= 255);
    __CPROVER_assume(sec_r001236_15 >= 0 && sec_r001236_15 <= 255);
    __CPROVER_assume(sec_r001236_16 >= 0 && sec_r001236_16 <= 255);
    __CPROVER_assume(sec_r001236_17 >= 0 && sec_r001236_17 <= 255);
    __CPROVER_assume(sec_r001236_18 >= 0 && sec_r001236_18 <= 255);
    __CPROVER_assume(sec_r001236_19 >= 0 && sec_r001236_19 <= 255);
    __CPROVER_assume(sec_r001236_20 >= 0 && sec_r001236_20 <= 255);
    __CPROVER_assume(sec_r001236_21 >= 0 && sec_r001236_21 <= 255);

    struct FilterState_R001236_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001236_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001236_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001236_0 + 7) & 15;
    struct AudioFrame_R001236_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001236_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001236_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001236_0 + 9) & 15;
    struct EventLog_R001236_3613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001236_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001236_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001236_0 + 11) & 15;

    union PacketPayload_R001236_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001236_3613_0(sec_r001236_0, pub_r001236_1, pub_r001236_2, pub_r001236_3, pub_r001236_4);
    int helper_flow_1 = fn_R001236_3613_1(sec_r001236_1, sec_r001236_2);
    int helper_flow_2 = fn_R001236_3613_2(sec_r001236_2, sec_r001236_3);
    int helper_flow_3 = fn_R001236_3613_3(sec_r001236_3, sec_r001236_4, pub_r001236_5);
    int helper_flow_4 = fn_R001236_3613_4(sec_r001236_4, sec_r001236_5, pub_r001236_6);
    int helper_flow_5 = fn_R001236_3613_5(sec_r001236_5, sec_r001236_6, pub_r001236_7, pub_r001236_8);
    int helper_flow_6 = fn_R001236_3613_6(sec_r001236_6, sec_r001236_7);
    int helper_flow_7 = fn_R001236_3613_7(sec_r001236_7, pub_r001236_8, pub_r001236_9);
    int helper_flow_8 = fn_R001236_3613_8(sec_r001236_8, sec_r001236_9);
    int helper_flow_9 = fn_R001236_3613_9(sec_r001236_9, sec_r001236_10, pub_r001236_11, pub_r001236_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_9 + pub_r001236_10 * 2 + 5) & 127;
    if (stage_v_0 > 38) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001236_12 + pub_r001236_3 * 2 + 8) & 127;
    if (stage_v_1 > 43) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_3 + pub_r001236_19 * 2 + 11) & 127;
    if (stage_v_2 > 16) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001236_1 + pub_r001236_4 * 2 + 14) & 127;
    if (stage_v_3 > 57) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001236_11 + pub_r001236_7 * 2 + 17) & 127;
    if (stage_v_4 > 18) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_3 + pub_r001236_1 * 2 + 20) & 127;
    if (stage_v_5 > 33) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_5 + pub_r001236_7 * 2 + 23) & 127;
    if (stage_v_6 > 44) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001236_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001236_9 + pub_r001236_13 * 2 + 29) & 127;
    if (stage_v_8 > 15) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001236_3 + pub_r001236_12 * 2 + 32) & 127;
    if (stage_v_9 > 18) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001236_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001236_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_1 + pub_r001236_5 * 2 + 41) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_0 + pub_r001236_16 * 2 + 44) & 127;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001236_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001236_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001236_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_8 + pub_r001236_4 * 2 + 56) & 127;
    if (stage_v_17 > 29) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_7 + pub_r001236_1 * 2 + 59) & 127;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001236_3 + pub_r001236_11 * 2 + 62) & 127;
    if (stage_v_19 > 40) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001236_5 + pub_r001236_19 * 2 + 65) & 127;
    if (stage_v_20 > 36) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_4 + pub_r001236_3 * 2 + 68) & 127;
    if (stage_v_21 > 21) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_21 + pub_r001236_20 * 2 + 71) & 127;
    if (stage_v_22 > 26) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001236_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001236_12 + pub_r001236_20 * 2 + 77) & 127;
    if (stage_v_24 > 21) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_6 + pub_r001236_3 * 2 + 80) & 127;
    if (stage_v_25 > 36) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_5 + pub_r001236_16 * 2 + 83) & 127;
    if (stage_v_26 > 57) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001236_10 + pub_r001236_11 * 2 + 86) & 127;
    if (stage_v_27 > 51) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001236_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001236_10 + pub_r001236_7 * 2 + 92) & 127;
    if (stage_v_29 > 36) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001236_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001236_4 + pub_r001236_11 * 2 + 98) & 127;
    if (stage_v_31 > 56) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001236_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001236_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001236_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001236_11 + pub_r001236_9 * 2 + 110) & 127;
    if (stage_v_35 > 29) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001236_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_12 + pub_r001236_12 * 2 + 116) & 127;
    if (stage_v_37 > 26) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_26 + pub_r001236_16 * 2 + 119) & 127;
    if (stage_v_38 > 59) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_9 + pub_r001236_9 * 2 + 122) & 127;
    if (stage_v_39 > 40) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001236_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_20 + pub_r001236_1 * 2 + 128) & 127;
    if (stage_v_41 > 35) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001236_10 + pub_r001236_1 * 2 + 131) & 127;
    if (stage_v_42 > 18) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001236_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_0 + pub_r001236_11 * 2 + 137) & 127;
    if (stage_v_44 > 23) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001236_18 + pub_r001236_14 * 2 + 140) & 127;
    if (stage_v_45 > 47) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001236_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001236_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001236_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001236_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001236_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001236_21 + pub_r001236_6 * 2 + 158) & 127;
    if (stage_v_51 > 53) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001236_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001236_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_35 + pub_r001236_19 * 2 + 167) & 127;
    if (stage_v_54 > 42) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001236_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001236_21 + pub_r001236_0 * 2 + 173) & 127;
    if (stage_v_56 > 37) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001236_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001236_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (helper_flow_4 + pub_r001236_19 * 2 + 182) & 127;
    if (stage_v_59 > 47) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_7 + pub_r001236_0 * 2 + 185) & 127;
    if (stage_v_60 > 55) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_38 + pub_r001236_10 * 2 + 188) & 127;
    if (stage_v_61 > 58) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_56 + pub_r001236_2 * 2 + 191) & 127;
    if (stage_v_62 > 17) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001236_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_35 + pub_r001236_15 * 2 + 197) & 127;
    if (stage_v_64 > 59) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_27 + pub_r001236_11 * 2 + 200) & 127;
    if (stage_v_65 > 36) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_61 + pub_r001236_13 * 2 + 203) & 127;
    if (stage_v_66 > 46) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001236_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_37 + pub_r001236_6 * 2 + 209) & 127;
    if (stage_v_68 > 32) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001236_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_68 + pub_r001236_7 * 2 + 215) & 127;
    if (stage_v_70 > 28) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001236_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001236_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001236_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_6 + pub_r001236_11 * 2 + 227) & 127;
    if (stage_v_74 > 34) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_39 + pub_r001236_3 * 2 + 230) & 127;
    if (stage_v_75 > 60) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001236_11 + pub_r001236_12 * 2 + 233) & 127;
    if (stage_v_76 > 55) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_1 + pub_r001236_6 * 2 + 236) & 127;
    if (stage_v_77 > 55) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001236_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_25 + pub_r001236_0 * 2 + 242) & 127;
    if (stage_v_79 > 24) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_24 + pub_r001236_14 * 2 + 245) & 127;
    if (stage_v_80 > 31) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_59 + pub_r001236_2 * 2 + 248) & 127;
    if (stage_v_81 > 29) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_75 + pub_r001236_12 * 2 + 251) & 127;
    if (stage_v_82 > 49) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_31 + pub_r001236_11 * 2 + 254) & 127;
    if (stage_v_83 > 51) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_3 + pub_r001236_5 * 2 + 257) & 127;
    if (stage_v_84 > 60) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001236_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001236_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001236_20 + pub_r001236_18 * 2 + 266) & 127;
    if (stage_v_87 > 18) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001236_2 + pub_r001236_3 * 2 + 269) & 127;
    if (stage_v_88 > 21) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_19 + pub_r001236_13 * 2 + 272) & 127;
    if (stage_v_89 > 23) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_5 + pub_r001236_14 * 2 + 275) & 127;
    if (stage_v_90 > 18) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001236_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001236_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001236_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001236_14 + pub_r001236_0 * 2 + 287) & 127;
    if (stage_v_94 > 35) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001236_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001236_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_2 + pub_r001236_11 * 2 + 296) & 127;
    if (stage_v_97 > 28) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_13 + pub_r001236_15 * 2 + 299) & 127;
    if (stage_v_98 > 21) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001236_2 + pub_r001236_14 * 2 + 302) & 127;
    if (stage_v_99 > 17) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_98 + pub_r001236_0 * 2 + 305) & 127;
    if (stage_v_100 > 24) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001236_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_8 + pub_r001236_12 * 2 + 311) & 127;
    if (stage_v_102 > 38) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_65 + pub_r001236_19 * 2 + 314) & 127;
    if (stage_v_103 > 31) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001236_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001236_2 + pub_r001236_14 * 2 + 320) & 127;
    if (stage_v_105 > 46) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_1 + pub_r001236_7 * 2 + 323) & 127;
    if (stage_v_106 > 28) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001236_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001236_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001236_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001236_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001236_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_98 + pub_r001236_13 * 2 + 341) & 127;
    if (stage_v_112 > 59) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001236_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001236_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001236_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001236_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_3 + pub_r001236_1 * 2 + 356) & 127;
    if (stage_v_117 > 40) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001236_12 + pub_r001236_19 * 2 + 359) & 127;
    if (stage_v_118 > 55) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_99 + pub_r001236_7 * 2 + 362) & 127;
    if (stage_v_119 > 60) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_117 + pub_r001236_3 * 2 + 365) & 127;
    if (stage_v_120 > 50) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_4 + pub_r001236_13 * 2 + 368) & 127;
    if (stage_v_121 > 33) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001236_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001236_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001236_14 + pub_r001236_16 * 2 + 377) & 127;
    if (stage_v_124 > 22) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_119 + pub_r001236_9 * 2 + 380) & 127;
    if (stage_v_125 > 52) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001236_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_119 + pub_r001236_10 * 2 + 386) & 127;
    if (stage_v_127 > 40) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001236_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001236_17 + pub_r001236_16 * 2 + 392) & 127;
    if (stage_v_129 > 58) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001236_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001236_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_94 + pub_r001236_2 * 2 + 401) & 127;
    if (stage_v_132 > 41) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_75 + pub_r001236_17 * 2 + 404) & 127;
    if (stage_v_133 > 50) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001236_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001236_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001236_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001236_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001236_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_62 + pub_r001236_8 * 2 + 422) & 127;
    if (stage_v_139 > 28) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001236_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001236_7 + pub_r001236_20 * 2 + 428) & 127;
    if (stage_v_141 > 56) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_31 + pub_r001236_1 * 2 + 431) & 127;
    if (stage_v_142 > 27) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001236_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_61 + pub_r001236_18 * 2 + 437) & 127;
    if (stage_v_144 > 42) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001236_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001236_5 + pub_r001236_5 * 2 + 443) & 127;
    if (stage_v_146 > 34) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_142 + pub_r001236_13 * 2 + 446) & 127;
    if (stage_v_147 > 20) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001236_1 + pub_r001236_5 * 2 + 449) & 127;
    if (stage_v_148 > 55) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_87 + pub_r001236_19 * 2 + 452) & 127;
    if (stage_v_149 > 52) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001236_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_81 + pub_r001236_1 * 2 + 458) & 127;
    if (stage_v_151 > 35) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001236_0 + pub_r001236_14 * 2 + 461) & 127;
    if (stage_v_152 > 48) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_75 + pub_r001236_8 * 2 + 464) & 127;
    if (stage_v_153 > 51) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_45 + pub_r001236_13 * 2 + 467) & 127;
    if (stage_v_154 > 56) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001236_16 + pub_r001236_18 * 2 + 470) & 127;
    if (stage_v_155 > 28) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001236_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_118 + pub_r001236_1 * 2 + 476) & 127;
    if (stage_v_157 > 34) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_89 + pub_r001236_18 * 2 + 479) & 127;
    if (stage_v_158 > 38) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001236_20 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_60 + pub_r001236_4 * 2 + 485) & 127;
    if (stage_v_160 > 55) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001236_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_89 + pub_r001236_16 * 2 + 491) & 127;
    if (stage_v_162 > 26) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_17 + pub_r001236_20 * 2 + 494) & 127;
    if (stage_v_163 > 37) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (helper_flow_2 + pub_r001236_11 * 2 + 497) & 127;
    if (stage_v_164 > 20) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001236_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_75 + pub_r001236_17 * 2 + 503) & 127;
    if (stage_v_166 > 15) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_144 + pub_r001236_4 * 2 + 506) & 127;
    if (stage_v_167 > 45) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_87 + pub_r001236_5 * 2 + 509) & 127;
    if (stage_v_168 > 49) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_88 + pub_r001236_1 * 2 + 512) & 127;
    if (stage_v_169 > 58) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_149 + pub_r001236_11 * 2 + 515) & 127;
    if (stage_v_170 > 19) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001236_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001236_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_89 + pub_r001236_1 * 2 + 524) & 127;
    if (stage_v_173 > 37) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_139 + pub_r001236_10 * 2 + 527) & 127;
    if (stage_v_174 > 29) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_169 + pub_r001236_11 * 2 + 530) & 127;
    if (stage_v_175 > 34) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (sec_r001236_14 + pub_r001236_18 * 2 + 533) & 127;
    if (stage_v_176 > 15) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_64 + pub_r001236_7 * 2 + 536) & 127;
    if (stage_v_177 > 57) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_139 + pub_r001236_1 * 2 + 539) & 127;
    if (stage_v_178 > 19) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_89 + pub_r001236_12 * 2 + 542) & 127;
    if (stage_v_179 > 34) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_178 + pub_r001236_8 * 2 + 545) & 127;
    if (stage_v_180 > 51) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_2 + pub_r001236_7 * 2 + 548) & 127;
    if (stage_v_181 > 32) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_3 + pub_r001236_6 * 2 + 551) & 127;
    if (stage_v_182 > 59) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001236_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (helper_flow_9 + pub_r001236_11 * 2 + 557) & 127;
    if (stage_v_184 > 25) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (helper_flow_9 + pub_r001236_0 * 2 + 560) & 127;
    if (stage_v_185 > 33) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001236_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_29 + pub_r001236_14 * 2 + 566) & 127;
    if (stage_v_187 > 28) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_51 + pub_r001236_20 * 2 + 569) & 127;
    if (stage_v_188 > 48) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_139 + pub_r001236_18 * 2 + 572) & 127;
    if (stage_v_189 > 57) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001236_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001236_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001236_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_166 + pub_r001236_10 * 2 + 584) & 127;
    if (stage_v_193 > 49) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_12 + pub_r001236_7 * 2 + 587) & 127;
    if (stage_v_194 > 42) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_176 + pub_r001236_3 * 2 + 590) & 127;
    if (stage_v_195 > 16) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_79 + pub_r001236_12 * 2 + 593) & 127;
    if (stage_v_196 > 51) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (helper_flow_6 + pub_r001236_17 * 2 + 596) & 127;
    if (stage_v_197 > 56) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (helper_flow_6 + pub_r001236_1 * 2 + 599) & 127;
    if (stage_v_198 > 32) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (helper_flow_8 + pub_r001236_11 * 2 + 602) & 127;
    if (stage_v_199 > 36) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_0 + pub_r001236_8 * 2 + 605) & 127;
    if (stage_v_200 > 58) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_163 + pub_r001236_14 * 2 + 608) & 127;
    if (stage_v_201 > 40) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001236_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001236_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_124 + pub_r001236_15 * 2 + 617) & 127;
    if (stage_v_204 > 23) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_157 + pub_r001236_16 * 2 + 620) & 127;
    if (stage_v_205 > 20) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_66 + pub_r001236_1 * 2 + 623) & 127;
    if (stage_v_206 > 45) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_185 + pub_r001236_18 * 2 + 626) & 127;
    if (stage_v_207 > 35) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (helper_flow_4 + pub_r001236_14 * 2 + 629) & 127;
    if (stage_v_208 > 56) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_103 + pub_r001236_11 * 2 + 632) & 127;
    if (stage_v_209 > 44) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_142 + pub_r001236_8 * 2 + 635) & 127;
    if (stage_v_210 > 38) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001236_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001236_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001236_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_167 + pub_r001236_19 * 2 + 647) & 127;
    if (stage_v_214 > 60) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_129 + pub_r001236_1 * 2 + 650) & 127;
    if (stage_v_215 > 43) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001236_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001236_9 + pub_r001236_2 * 2 + 656) & 127;
    if (stage_v_217 > 33) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001236_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001236_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_210 + pub_r001236_7 * 2 + 665) & 127;
    if (stage_v_220 > 53) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_189 + pub_r001236_11 * 2 + 668) & 127;
    if (stage_v_221 > 45) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (sec_r001236_18 + pub_r001236_12 * 2 + 671) & 127;
    if (stage_v_222 > 56) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_79 + pub_r001236_17 * 2 + 674) & 127;
    if (stage_v_223 > 54) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_147 + pub_r001236_20 * 2 + 677) & 127;
    if (stage_v_224 > 38) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001236_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_188 + pub_r001236_9 * 2 + 683) & 127;
    if (stage_v_226 > 23) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_207 + pub_r001236_14 * 2 + 686) & 127;
    if (stage_v_227 > 54) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001236_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001236_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_21 + pub_r001236_5 * 2 + 695) & 127;
    if (stage_v_230 > 32) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_209 + pub_r001236_6 * 2 + 698) & 127;
    if (stage_v_231 > 35) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001236_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_182 + pub_r001236_6 * 2 + 704) & 127;
    if (stage_v_233 > 39) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_2 + pub_r001236_6 * 2 + 707) & 127;
    if (stage_v_234 > 37) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r001236_16 + pub_r001236_19 * 2 + 710) & 127;
    if (stage_v_235 > 43) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001236_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_103 + pub_r001236_10 * 2 + 716) & 127;
    if (stage_v_237 > 17) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001236_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_197 + pub_r001236_3 * 2 + 722) & 127;
    if (stage_v_239 > 29) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001236_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_60 + pub_r001236_9 * 2 + 728) & 127;
    if (stage_v_241 > 44) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_194 + pub_r001236_9 * 2 + 731) & 127;
    if (stage_v_242 > 30) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001236_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_239 + pub_r001236_14 * 2 + 737) & 127;
    if (stage_v_244 > 32) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_227 + pub_r001236_4 * 2 + 740) & 127;
    if (stage_v_245 > 25) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001236_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001236_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_31 + pub_r001236_8 * 2 + 749) & 127;
    if (stage_v_248 > 37) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_4 + pub_r001236_7 * 2 + 752) & 127;
    if (stage_v_249 > 21) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001236_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_166 + pub_r001236_17 * 2 + 758) & 127;
    if (stage_v_251 > 60) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_199 + pub_r001236_6 * 2 + 761) & 127;
    if (stage_v_252 > 42) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_176 + pub_r001236_2 * 2 + 764) & 127;
    if (stage_v_253 > 59) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_80 + pub_r001236_7 * 2 + 767) & 127;
    if (stage_v_254 > 26) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_179 + pub_r001236_15 * 2 + 770) & 127;
    if (stage_v_255 > 19) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_182 + pub_r001236_7 * 2 + 773) & 127;
    if (stage_v_256 > 56) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_119 + pub_r001236_13 * 2 + 776) & 127;
    if (stage_v_257 > 31) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
        sec_accum ^= (stage_v_257 & 31);
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001236_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_208 + pub_r001236_19 * 2 + 782) & 127;
    if (stage_v_259 > 38) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
        sec_accum ^= (stage_v_259 & 31);
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_151 + pub_r001236_3 * 2 + 785) & 127;
    if (stage_v_260 > 50) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
        sec_accum ^= (stage_v_260 & 31);
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_154 + pub_r001236_18 * 2 + 788) & 127;
    if (stage_v_261 > 51) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
        sec_accum ^= (stage_v_261 & 31);
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001236_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
