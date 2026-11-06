/*
 * Benchmark Program: R000397
 * Security Family: nested_implicit_flow
 * Generator Seed: 539713
 * High Inputs: 24 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000397_9713_0 {
    short iv;
    int round_key;
    int counter;
    int nonce;
    int buffer[3];
};

struct FilterState_R000397_9713_1 {
    int gain_db;
    int prev_out;
    unsigned char damping;
    short cutoff;
    int buffer[3];
};

union TelemetryField_R000397_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000397_9713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000397_9713_0(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_24 = (aux + st.buffer[1]) & 3;
    switch (threshold_24) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_82 = local_arr[aux % 3];
    acc = (acc + segment_82 * 2) & 127;
    int delta_64 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_64 > 12) {
        acc = (acc + delta_64 * 2 + 5) & 127;
        aux ^= (delta_64 & 15);
    } else {
        acc = (acc - delta_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_1(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_36 = (aux + st.buffer[1]) & 3;
    switch (mask_36) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_56 = local_arr[aux % 3];
    acc = (acc + metric_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_2(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tracker_60 = local_arr[aux % 3];
    acc = (acc + tracker_60 * 2) & 127;
    int quantum_29 = (aux + st.buffer[1]) & 3;
    switch (quantum_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int scale_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_89) & 63;
    acc ^= aux;
    int segment_64 = (aux + st.buffer[1]) & 3;
    switch (segment_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_46 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_46 > 20) {
        acc = (acc + coefficient_46 * 2 + 5) & 127;
        aux ^= (coefficient_46 & 15);
    } else {
        acc = (acc - coefficient_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_17 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_17 > 36) {
        acc = (acc + quotient_17 * 2 + 5) & 127;
        aux ^= (quotient_17 & 15);
    } else {
        acc = (acc - quotient_17 + 11) & 127;
        aux += 3;
    }
    int pivot_56 = (aux + st.buffer[1]) & 3;
    switch (pivot_56) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_99) & 63;
    acc ^= aux;
    int coefficient_87 = (aux + st.buffer[1]) & 3;
    switch (coefficient_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_79 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_79 > 18) {
        acc = (acc + mask_79 * 2 + 5) & 127;
        aux ^= (mask_79 & 15);
    } else {
        acc = (acc - mask_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_19 = (aux + st.buffer[1]) & 3;
    switch (damping_19) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_62 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_62 > 28) {
        acc = (acc + coefficient_62 * 2 + 5) & 127;
        aux ^= (coefficient_62 & 15);
    } else {
        acc = (acc - coefficient_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_96 = local_arr[aux % 3];
    acc = (acc + stride_96 * 2) & 127;
    int damping_69 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_69 > 13) {
        acc = (acc + damping_69 * 2 + 5) & 127;
        aux ^= (damping_69 & 15);
    } else {
        acc = (acc - damping_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int phase_39 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_39 > 40) {
        acc = (acc + phase_39 * 2 + 5) & 127;
        aux ^= (phase_39 & 15);
    } else {
        acc = (acc - phase_39 + 11) & 127;
        aux += 3;
    }
    int accumulator_66 = (aux + st.buffer[1]) & 3;
    switch (accumulator_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int residue_93 = local_arr[aux % 3];
    acc = (acc + residue_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_66 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_66 > 24) {
        acc = (acc + scale_66 * 2 + 5) & 127;
        aux ^= (scale_66 & 15);
    } else {
        acc = (acc - scale_66 + 11) & 127;
        aux += 3;
    }
    int factor_21 = (aux + st.buffer[1]) & 3;
    switch (factor_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_46 = (aux + st.buffer[1]) & 3;
    switch (scale_46) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_33 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_33 > 27) {
        acc = (acc + residue_33 * 2 + 5) & 127;
        aux ^= (residue_33 & 15);
    } else {
        acc = (acc - residue_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_18 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_18 > 50) {
        acc = (acc + coefficient_18 * 2 + 5) & 127;
        aux ^= (coefficient_18 & 15);
    } else {
        acc = (acc - coefficient_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000397_9713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000397_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int stride_63 = local_arr[aux % 3];
    acc = (acc + stride_63 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000397_9713_14(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000397_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int offset_24 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_24 > 41) {
        acc = (acc + offset_24 * 2 + 5) & 127;
        aux ^= (offset_24 & 15);
    } else {
        acc = (acc - offset_24 + 11) & 127;
        aux += 3;
    }
    int factor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000397_0;
    int sec_r000397_1;
    int sec_r000397_2;
    int sec_r000397_3;
    int sec_r000397_4;
    int sec_r000397_5;
    int sec_r000397_6;
    int sec_r000397_7;
    int sec_r000397_8;
    int sec_r000397_9;
    int sec_r000397_10;
    int sec_r000397_11;
    int sec_r000397_12;
    int sec_r000397_13;
    int sec_r000397_14;
    int sec_r000397_15;
    int sec_r000397_16;
    int sec_r000397_17;
    int sec_r000397_18;
    int sec_r000397_19;
    int sec_r000397_20;
    int sec_r000397_21;
    int sec_r000397_22;
    int sec_r000397_23;
    int pub_r000397_0;
    int pub_r000397_1;
    int pub_r000397_2;
    int pub_r000397_3;
    int pub_r000397_4;
    int pub_r000397_5;
    int pub_r000397_6;
    int pub_r000397_7;
    int pub_r000397_8;
    int pub_r000397_9;
    int pub_r000397_10;
    int pub_r000397_11;
    int pub_r000397_12;
    int pub_r000397_13;
    int pub_r000397_14;
    int pub_r000397_15;
    int pub_r000397_16;
    int pub_r000397_17;
    int pub_r000397_18;
    int pub_r000397_19;
    int pub_r000397_20;
    int pub_r000397_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000397_0 >= -100 && pub_r000397_0 <= 100);
    __CPROVER_assume(pub_r000397_1 >= -100 && pub_r000397_1 <= 100);
    __CPROVER_assume(pub_r000397_2 >= -100 && pub_r000397_2 <= 100);
    __CPROVER_assume(pub_r000397_3 >= -100 && pub_r000397_3 <= 100);
    __CPROVER_assume(pub_r000397_4 >= -100 && pub_r000397_4 <= 100);
    __CPROVER_assume(pub_r000397_5 >= -100 && pub_r000397_5 <= 100);
    __CPROVER_assume(pub_r000397_6 >= -100 && pub_r000397_6 <= 100);
    __CPROVER_assume(pub_r000397_7 >= -100 && pub_r000397_7 <= 100);
    __CPROVER_assume(pub_r000397_8 >= -100 && pub_r000397_8 <= 100);
    __CPROVER_assume(pub_r000397_9 >= -100 && pub_r000397_9 <= 100);
    __CPROVER_assume(pub_r000397_10 >= -100 && pub_r000397_10 <= 100);
    __CPROVER_assume(pub_r000397_11 >= -100 && pub_r000397_11 <= 100);
    __CPROVER_assume(pub_r000397_12 >= -100 && pub_r000397_12 <= 100);
    __CPROVER_assume(pub_r000397_13 >= -100 && pub_r000397_13 <= 100);
    __CPROVER_assume(pub_r000397_14 >= -100 && pub_r000397_14 <= 100);
    __CPROVER_assume(pub_r000397_15 >= -100 && pub_r000397_15 <= 100);
    __CPROVER_assume(pub_r000397_16 >= -100 && pub_r000397_16 <= 100);
    __CPROVER_assume(pub_r000397_17 >= -100 && pub_r000397_17 <= 100);
    __CPROVER_assume(pub_r000397_18 >= -100 && pub_r000397_18 <= 100);
    __CPROVER_assume(pub_r000397_19 >= -100 && pub_r000397_19 <= 100);
    __CPROVER_assume(pub_r000397_20 >= -100 && pub_r000397_20 <= 100);
    __CPROVER_assume(pub_r000397_21 >= -100 && pub_r000397_21 <= 100);
    __CPROVER_assume(sec_r000397_0 >= 0 && sec_r000397_0 <= 255);
    __CPROVER_assume(sec_r000397_1 >= 0 && sec_r000397_1 <= 255);
    __CPROVER_assume(sec_r000397_2 >= 0 && sec_r000397_2 <= 255);
    __CPROVER_assume(sec_r000397_3 >= 0 && sec_r000397_3 <= 255);
    __CPROVER_assume(sec_r000397_4 >= 0 && sec_r000397_4 <= 255);
    __CPROVER_assume(sec_r000397_5 >= 0 && sec_r000397_5 <= 255);
    __CPROVER_assume(sec_r000397_6 >= 0 && sec_r000397_6 <= 255);
    __CPROVER_assume(sec_r000397_7 >= 0 && sec_r000397_7 <= 255);
    __CPROVER_assume(sec_r000397_8 >= 0 && sec_r000397_8 <= 255);
    __CPROVER_assume(sec_r000397_9 >= 0 && sec_r000397_9 <= 255);
    __CPROVER_assume(sec_r000397_10 >= 0 && sec_r000397_10 <= 255);
    __CPROVER_assume(sec_r000397_11 >= 0 && sec_r000397_11 <= 255);
    __CPROVER_assume(sec_r000397_12 >= 0 && sec_r000397_12 <= 255);
    __CPROVER_assume(sec_r000397_13 >= 0 && sec_r000397_13 <= 255);
    __CPROVER_assume(sec_r000397_14 >= 0 && sec_r000397_14 <= 255);
    __CPROVER_assume(sec_r000397_15 >= 0 && sec_r000397_15 <= 255);
    __CPROVER_assume(sec_r000397_16 >= 0 && sec_r000397_16 <= 255);
    __CPROVER_assume(sec_r000397_17 >= 0 && sec_r000397_17 <= 255);
    __CPROVER_assume(sec_r000397_18 >= 0 && sec_r000397_18 <= 255);
    __CPROVER_assume(sec_r000397_19 >= 0 && sec_r000397_19 <= 255);
    __CPROVER_assume(sec_r000397_20 >= 0 && sec_r000397_20 <= 255);
    __CPROVER_assume(sec_r000397_21 >= 0 && sec_r000397_21 <= 255);
    __CPROVER_assume(sec_r000397_22 >= 0 && sec_r000397_22 <= 255);
    __CPROVER_assume(sec_r000397_23 >= 0 && sec_r000397_23 <= 255);

    struct CipherContext_R000397_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000397_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000397_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000397_0 + 7) & 15;
    struct FilterState_R000397_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000397_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000397_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000397_0 + 9) & 15;

    union TelemetryField_R000397_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 29) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 44) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 11) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 26) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 37) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 52) {
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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

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
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

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
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 22) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 37) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 25) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 40) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 35) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 50) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 38) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 53) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000397_20 & 1) != 0) {
        if ((sec_r000397_16 & 2) != 0) {
            stage_v_69 = (pub_r000397_6 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000397_6 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000397_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_9 & 2) != 0) {
            stage_v_70 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000397_18 & 1) != 0) {
        if ((sec_r000397_9 & 2) != 0) {
            stage_v_71 = (pub_r000397_0 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000397_0 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000397_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000397_4 & 1) != 0) {
        if ((sec_r000397_18 & 2) != 0) {
            stage_v_72 = (pub_r000397_7 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000397_7 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000397_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_17 & 2) != 0) {
            stage_v_73 = (pub_r000397_10 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000397_10 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000397_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000397_7 & 1) != 0) {
        if ((sec_r000397_23 & 2) != 0) {
            stage_v_74 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_75 = (pub_r000397_9 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000397_9 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000397_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000397_21 & 1) != 0) {
        if ((sec_r000397_10 & 2) != 0) {
            stage_v_76 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000397_20 & 1) != 0) {
        if ((sec_r000397_14 & 2) != 0) {
            stage_v_77 = (pub_r000397_21 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000397_21 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000397_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_22 & 2) != 0) {
            stage_v_78 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000397_16 & 2) != 0) {
            stage_v_79 = (pub_r000397_18 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000397_18 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000397_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_80 = (pub_r000397_6 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000397_6 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000397_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_13 & 2) != 0) {
            stage_v_81 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_5 & 2) != 0) {
            stage_v_82 = (pub_r000397_6 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000397_6 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000397_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000397_6 & 2) != 0) {
            stage_v_83 = (pub_r000397_17 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000397_17 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000397_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_18 & 2) != 0) {
            stage_v_84 = (pub_r000397_4 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000397_4 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000397_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_85 = (pub_r000397_18 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000397_18 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000397_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000397_3 & 1) != 0) {
        if ((sec_r000397_23 & 2) != 0) {
            stage_v_86 = (pub_r000397_0 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000397_0 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000397_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_18 & 2) != 0) {
            stage_v_87 = (pub_r000397_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000397_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000397_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000397_4 & 1) != 0) {
        if ((sec_r000397_5 & 2) != 0) {
            stage_v_88 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000397_3 & 1) != 0) {
        if ((sec_r000397_17 & 2) != 0) {
            stage_v_89 = (pub_r000397_21 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000397_21 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000397_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_22 & 2) != 0) {
            stage_v_90 = (pub_r000397_1 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000397_1 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000397_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000397_22 & 1) != 0) {
        if ((sec_r000397_18 & 2) != 0) {
            stage_v_91 = (pub_r000397_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000397_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000397_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000397_14 & 2) != 0) {
            stage_v_92 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000397_20 & 1) != 0) {
        if ((sec_r000397_11 & 2) != 0) {
            stage_v_93 = (pub_r000397_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000397_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000397_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000397_13 & 2) != 0) {
            stage_v_94 = (pub_r000397_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000397_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000397_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_95 = (pub_r000397_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000397_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000397_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000397_0 & 2) != 0) {
            stage_v_96 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000397_6 & 1) != 0) {
        if ((sec_r000397_22 & 2) != 0) {
            stage_v_97 = (pub_r000397_21 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000397_21 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000397_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000397_17 & 2) != 0) {
            stage_v_98 = (pub_r000397_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000397_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000397_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_99 = (pub_r000397_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000397_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000397_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000397_21 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_100 = (pub_r000397_9 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000397_9 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000397_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000397_13 & 2) != 0) {
            stage_v_101 = (pub_r000397_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000397_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000397_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000397_17 & 2) != 0) {
            stage_v_102 = (pub_r000397_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000397_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000397_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000397_9 & 2) != 0) {
            stage_v_103 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_104 = (pub_r000397_13 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000397_13 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000397_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000397_11 & 2) != 0) {
            stage_v_105 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000397_12 & 2) != 0) {
            stage_v_106 = (pub_r000397_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000397_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000397_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000397_5 & 2) != 0) {
            stage_v_107 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000397_15 & 1) != 0) {
        if ((sec_r000397_11 & 2) != 0) {
            stage_v_108 = (pub_r000397_1 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000397_1 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000397_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000397_8 & 2) != 0) {
            stage_v_109 = (pub_r000397_2 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000397_2 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000397_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000397_2 & 1) != 0) {
        if ((sec_r000397_16 & 2) != 0) {
            stage_v_110 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000397_8 & 2) != 0) {
            stage_v_111 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000397_8 & 1) != 0) {
        if ((sec_r000397_8 & 2) != 0) {
            stage_v_112 = (pub_r000397_2 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000397_2 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000397_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000397_3 & 2) != 0) {
            stage_v_113 = (pub_r000397_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000397_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000397_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_114 = (pub_r000397_18 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000397_18 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000397_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000397_4 & 2) != 0) {
            stage_v_115 = (pub_r000397_1 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000397_1 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000397_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000397_2 & 2) != 0) {
            stage_v_116 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000397_15 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_117 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_118 = (pub_r000397_20 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000397_20 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000397_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_119 = (pub_r000397_0 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000397_0 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000397_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000397_3 & 1) != 0) {
        if ((sec_r000397_3 & 2) != 0) {
            stage_v_120 = (pub_r000397_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000397_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000397_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000397_3 & 1) != 0) {
        if ((sec_r000397_14 & 2) != 0) {
            stage_v_121 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000397_15 & 2) != 0) {
            stage_v_122 = (pub_r000397_20 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000397_20 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000397_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000397_14 & 2) != 0) {
            stage_v_123 = (pub_r000397_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000397_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000397_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000397_10 & 1) != 0) {
        if ((sec_r000397_10 & 2) != 0) {
            stage_v_124 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000397_22 & 2) != 0) {
            stage_v_125 = (pub_r000397_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000397_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000397_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000397_5 & 2) != 0) {
            stage_v_126 = (pub_r000397_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000397_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000397_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000397_9 & 2) != 0) {
            stage_v_127 = (pub_r000397_21 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000397_21 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000397_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_128 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000397_5 & 1) != 0) {
        if ((sec_r000397_23 & 2) != 0) {
            stage_v_129 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000397_11 & 1) != 0) {
        if ((sec_r000397_13 & 2) != 0) {
            stage_v_130 = (pub_r000397_9 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000397_9 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000397_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_131 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_132 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_133 = (pub_r000397_11 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000397_11 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000397_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000397_3 & 2) != 0) {
            stage_v_134 = (pub_r000397_21 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000397_21 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000397_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_135 = (pub_r000397_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000397_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000397_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000397_16 & 2) != 0) {
            stage_v_136 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_137 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000397_8 & 2) != 0) {
            stage_v_138 = (pub_r000397_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000397_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000397_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_139 = (pub_r000397_4 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000397_4 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000397_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000397_23 & 2) != 0) {
            stage_v_140 = (pub_r000397_20 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000397_20 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000397_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_141 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000397_22 & 1) != 0) {
        if ((sec_r000397_22 & 2) != 0) {
            stage_v_142 = (pub_r000397_3 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000397_3 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000397_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000397_12 & 2) != 0) {
            stage_v_143 = (pub_r000397_1 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000397_1 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000397_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000397_15 & 2) != 0) {
            stage_v_144 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000397_23 & 1) != 0) {
        if ((sec_r000397_13 & 2) != 0) {
            stage_v_145 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000397_0 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_146 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000397_10 & 2) != 0) {
            stage_v_147 = (pub_r000397_16 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000397_16 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000397_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000397_12 & 2) != 0) {
            stage_v_148 = (pub_r000397_14 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000397_14 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000397_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000397_7 & 2) != 0) {
            stage_v_149 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_150 = (pub_r000397_20 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000397_20 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000397_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000397_16 & 1) != 0) {
        if ((sec_r000397_16 & 2) != 0) {
            stage_v_151 = (pub_r000397_5 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000397_5 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000397_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000397_2 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_152 = (pub_r000397_7 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000397_7 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000397_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000397_23 & 2) != 0) {
            stage_v_153 = (pub_r000397_4 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000397_4 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000397_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000397_6 & 1) != 0) {
        if ((sec_r000397_17 & 2) != 0) {
            stage_v_154 = (pub_r000397_8 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000397_8 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000397_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000397_19 & 2) != 0) {
            stage_v_155 = (pub_r000397_18 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000397_18 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000397_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000397_4 & 1) != 0) {
        if ((sec_r000397_18 & 2) != 0) {
            stage_v_156 = (pub_r000397_7 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000397_7 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000397_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000397_0 & 2) != 0) {
            stage_v_157 = (pub_r000397_19 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000397_19 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000397_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r000397_1 & 2) != 0) {
            stage_v_158 = (pub_r000397_20 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000397_20 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000397_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000397_2 & 1) != 0) {
        if ((sec_r000397_10 & 2) != 0) {
            stage_v_159 = (pub_r000397_17 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000397_17 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000397_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000397_21 & 2) != 0) {
            stage_v_160 = (pub_r000397_11 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000397_11 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000397_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
