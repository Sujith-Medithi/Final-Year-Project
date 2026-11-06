/*
 * Benchmark Program: R000003
 * Security Family: multi_step_explicit
 * Generator Seed: 500313
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000003_313_0 {
    short tag;
    short round_key;
    int flags;
    int buffer[3];
};

struct AudioFrame_R000003_313_1 {
    int sample_rate;
    unsigned char gain;
    int rms;
    short envelope;
    int peak;
    short channels;
    int buffer[3];
};

union ColorPixel_R000003_313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000003_313_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_62) & 63;
    acc ^= aux;
    int segment_71 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_71 > 14) {
        acc = (acc + segment_71 * 2 + 5) & 127;
        aux ^= (segment_71 & 15);
    } else {
        acc = (acc - segment_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_1(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_28) & 63;
    acc ^= aux;
    int tracker_14 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_14 > 33) {
        acc = (acc + tracker_14 * 2 + 5) & 127;
        aux ^= (tracker_14 & 15);
    } else {
        acc = (acc - tracker_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_2(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_26 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_26 > 11) {
        acc = (acc + segment_26 * 2 + 5) & 127;
        aux ^= (segment_26 & 15);
    } else {
        acc = (acc - segment_26 + 11) & 127;
        aux += 3;
    }
    int accumulator_10 = (aux + st.buffer[1]) & 3;
    switch (accumulator_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int checksum_26 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_26 > 33) {
        acc = (acc + checksum_26 * 2 + 5) & 127;
        aux ^= (checksum_26 & 15);
    } else {
        acc = (acc - checksum_26 + 11) & 127;
        aux += 3;
    }
    int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000003_313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int cursor_30 = local_arr[aux % 3];
    acc = (acc + cursor_30 * 2) & 127;
    int vector_82 = (aux + st.buffer[1]) & 3;
    switch (vector_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int damping_74 = local_arr[aux % 3];
    acc = (acc + damping_74 * 2) & 127;
    int sample_92 = (aux + st.buffer[1]) & 3;
    switch (sample_92) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000003_313_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_22 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_22 > 41) {
        acc = (acc + residue_22 * 2 + 5) & 127;
        aux ^= (residue_22 & 15);
    } else {
        acc = (acc - residue_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_87 = local_arr[aux % 3];
    acc = (acc + vector_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_9(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_11) & 63;
    acc ^= aux;
    int window_70 = (st.buffer[0] * 3 + aux) & 63;
    if (window_70 > 36) {
        acc = (acc + window_70 * 2 + 5) & 127;
        aux ^= (window_70 & 15);
    } else {
        acc = (acc - window_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_28 = local_arr[aux % 3];
    acc = (acc + pivot_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_50 = (aux + st.buffer[1]) & 3;
    switch (factor_50) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_15 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_15 > 20) {
        acc = (acc + sample_15 * 2 + 5) & 127;
        aux ^= (sample_15 & 15);
    } else {
        acc = (acc - sample_15 + 11) & 127;
        aux += 3;
    }
    int parity_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_31) & 63;
    acc ^= aux;
    int index_reg_47 = (aux + st.buffer[1]) & 3;
    switch (index_reg_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_12(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_17) & 63;
    acc ^= aux;
    int stride_84 = (aux + st.buffer[1]) & 3;
    switch (stride_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_59 = local_arr[aux % 3];
    acc = (acc + mask_59 * 2) & 127;
    int weight_38 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_38 > 32) {
        acc = (acc + weight_38 * 2 + 5) & 127;
        aux ^= (weight_38 & 15);
    } else {
        acc = (acc - weight_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int sample_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_97) & 63;
    acc ^= aux;
    int accumulator_20 = (aux + st.buffer[1]) & 3;
    switch (accumulator_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_14(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int stride_96 = local_arr[aux % 3];
    acc = (acc + stride_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_15 = (aux + st.buffer[1]) & 3;
    switch (metric_15) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000003_313_15(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000003_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int factor_71 = (aux + st.buffer[1]) & 3;
    switch (factor_71) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_91 = local_arr[aux % 3];
    acc = (acc + phase_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int bound_24 = local_arr[aux % 3];
    acc = (acc + bound_24 * 2) & 127;
    int anchor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_79 > 18) {
        acc = (acc + anchor_79 * 2 + 5) & 127;
        aux ^= (anchor_79 & 15);
    } else {
        acc = (acc - anchor_79 + 11) & 127;
        aux += 3;
    }
    int weight_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000003_313_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_82 = (aux + st.buffer[1]) & 3;
    switch (sample_82) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_78 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_78 > 49) {
        acc = (acc + mask_78 * 2 + 5) & 127;
        aux ^= (mask_78 & 15);
    } else {
        acc = (acc - mask_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000003_313_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000003_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_98 = (aux + st.buffer[1]) & 3;
    switch (window_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_66 = local_arr[aux % 3];
    acc = (acc + checksum_66 * 2) & 127;
    int quotient_70 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_70 > 46) {
        acc = (acc + quotient_70 * 2 + 5) & 127;
        aux ^= (quotient_70 & 15);
    } else {
        acc = (acc - quotient_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000003_0;
    int sec_r000003_1;
    int sec_r000003_2;
    int sec_r000003_3;
    int sec_r000003_4;
    int sec_r000003_5;
    int sec_r000003_6;
    int sec_r000003_7;
    int sec_r000003_8;
    int sec_r000003_9;
    int sec_r000003_10;
    int sec_r000003_11;
    int sec_r000003_12;
    int sec_r000003_13;
    int sec_r000003_14;
    int sec_r000003_15;
    int sec_r000003_16;
    int sec_r000003_17;
    int sec_r000003_18;
    int sec_r000003_19;
    int sec_r000003_20;
    int sec_r000003_21;
    int pub_r000003_0;
    int pub_r000003_1;
    int pub_r000003_2;
    int pub_r000003_3;
    int pub_r000003_4;
    int pub_r000003_5;
    int pub_r000003_6;
    int pub_r000003_7;
    int pub_r000003_8;
    int pub_r000003_9;
    int pub_r000003_10;
    int pub_r000003_11;
    int pub_r000003_12;
    int pub_r000003_13;
    int pub_r000003_14;
    int pub_r000003_15;
    int pub_r000003_16;
    int pub_r000003_17;
    int pub_r000003_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000003_0 >= -100 && pub_r000003_0 <= 100);
    __CPROVER_assume(pub_r000003_1 >= -100 && pub_r000003_1 <= 100);
    __CPROVER_assume(pub_r000003_2 >= -100 && pub_r000003_2 <= 100);
    __CPROVER_assume(pub_r000003_3 >= -100 && pub_r000003_3 <= 100);
    __CPROVER_assume(pub_r000003_4 >= -100 && pub_r000003_4 <= 100);
    __CPROVER_assume(pub_r000003_5 >= -100 && pub_r000003_5 <= 100);
    __CPROVER_assume(pub_r000003_6 >= -100 && pub_r000003_6 <= 100);
    __CPROVER_assume(pub_r000003_7 >= -100 && pub_r000003_7 <= 100);
    __CPROVER_assume(pub_r000003_8 >= -100 && pub_r000003_8 <= 100);
    __CPROVER_assume(pub_r000003_9 >= -100 && pub_r000003_9 <= 100);
    __CPROVER_assume(pub_r000003_10 >= -100 && pub_r000003_10 <= 100);
    __CPROVER_assume(pub_r000003_11 >= -100 && pub_r000003_11 <= 100);
    __CPROVER_assume(pub_r000003_12 >= -100 && pub_r000003_12 <= 100);
    __CPROVER_assume(pub_r000003_13 >= -100 && pub_r000003_13 <= 100);
    __CPROVER_assume(pub_r000003_14 >= -100 && pub_r000003_14 <= 100);
    __CPROVER_assume(pub_r000003_15 >= -100 && pub_r000003_15 <= 100);
    __CPROVER_assume(pub_r000003_16 >= -100 && pub_r000003_16 <= 100);
    __CPROVER_assume(pub_r000003_17 >= -100 && pub_r000003_17 <= 100);
    __CPROVER_assume(pub_r000003_18 >= -100 && pub_r000003_18 <= 100);
    __CPROVER_assume(sec_r000003_0 >= 0 && sec_r000003_0 <= 255);
    __CPROVER_assume(sec_r000003_1 >= 0 && sec_r000003_1 <= 255);
    __CPROVER_assume(sec_r000003_2 >= 0 && sec_r000003_2 <= 255);
    __CPROVER_assume(sec_r000003_3 >= 0 && sec_r000003_3 <= 255);
    __CPROVER_assume(sec_r000003_4 >= 0 && sec_r000003_4 <= 255);
    __CPROVER_assume(sec_r000003_5 >= 0 && sec_r000003_5 <= 255);
    __CPROVER_assume(sec_r000003_6 >= 0 && sec_r000003_6 <= 255);
    __CPROVER_assume(sec_r000003_7 >= 0 && sec_r000003_7 <= 255);
    __CPROVER_assume(sec_r000003_8 >= 0 && sec_r000003_8 <= 255);
    __CPROVER_assume(sec_r000003_9 >= 0 && sec_r000003_9 <= 255);
    __CPROVER_assume(sec_r000003_10 >= 0 && sec_r000003_10 <= 255);
    __CPROVER_assume(sec_r000003_11 >= 0 && sec_r000003_11 <= 255);
    __CPROVER_assume(sec_r000003_12 >= 0 && sec_r000003_12 <= 255);
    __CPROVER_assume(sec_r000003_13 >= 0 && sec_r000003_13 <= 255);
    __CPROVER_assume(sec_r000003_14 >= 0 && sec_r000003_14 <= 255);
    __CPROVER_assume(sec_r000003_15 >= 0 && sec_r000003_15 <= 255);
    __CPROVER_assume(sec_r000003_16 >= 0 && sec_r000003_16 <= 255);
    __CPROVER_assume(sec_r000003_17 >= 0 && sec_r000003_17 <= 255);
    __CPROVER_assume(sec_r000003_18 >= 0 && sec_r000003_18 <= 255);
    __CPROVER_assume(sec_r000003_19 >= 0 && sec_r000003_19 <= 255);
    __CPROVER_assume(sec_r000003_20 >= 0 && sec_r000003_20 <= 255);
    __CPROVER_assume(sec_r000003_21 >= 0 && sec_r000003_21 <= 255);

    struct CipherContext_R000003_313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000003_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000003_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000003_0 + 7) & 15;
    struct AudioFrame_R000003_313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000003_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000003_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000003_0 + 9) & 15;

    union ColorPixel_R000003_313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 37) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 52) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
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
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 27) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 42) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 13) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 28) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 19) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 34) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 10) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 25) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 15) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 30) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

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
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 40) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 55) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 20) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 35) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 48) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 27) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 42) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (sec_r000003_20 + pub_r000003_9 + 25) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000003_18) & 127;
    st_var_1.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (stage_v_87 + pub_r000003_9 + 29) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000003_10) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sub_step_87 + pub_r000003_0 + 35) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000003_16) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (stage_v_89 + pub_r000003_5 + 8) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000003_14 + pub_r000003_17 + 14) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (stage_v_88 + pub_r000003_14 + 8) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (stage_v_92 + pub_r000003_2 + 34) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000003_15) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sub_step_92 + pub_r000003_6 + 5) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000003_16) & 127;
    st_var_0.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sub_step_88 + pub_r000003_1 + 32) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000003_14) & 127;
    st_var_1.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (stage_v_88 + pub_r000003_10 + 24) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sub_step_94 + pub_r000003_2 + 14) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000003_4) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sec_r000003_0 + pub_r000003_17 + 5) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000003_12 + pub_r000003_2 + 7) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000003_4) & 127;
    st_var_1.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sub_step_94 + pub_r000003_5 + 14) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sub_step_92 + pub_r000003_16 + 12) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000003_4 + pub_r000003_3 + 11) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sub_step_88 + pub_r000003_11 + 34) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sub_step_103 + pub_r000003_17 + 30) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000003_12) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sub_step_102 + pub_r000003_10 + 10) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000003_3) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_90 + pub_r000003_8 + 15) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (stage_v_96 + pub_r000003_16 + 20) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_101 + pub_r000003_8 + 20) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sub_step_90 + pub_r000003_13 + 29) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_107 + pub_r000003_3 + 19) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sub_step_90 + pub_r000003_3 + 33) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000003_7) & 127;
    st_var_1.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000003_7 + pub_r000003_2 + 18) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000003_15) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000003_19 + pub_r000003_15 + 9) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000003_6) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_89 + pub_r000003_14 + 5) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (stage_v_103 + pub_r000003_16 + 19) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000003_3) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_107 + pub_r000003_13 + 18) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (stage_v_91 + pub_r000003_5 + 23) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000003_10) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_114 + pub_r000003_3 + 25) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000003_18) & 127;
    st_var_0.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (stage_v_109 + pub_r000003_12 + 33) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (stage_v_102 + pub_r000003_13 + 14) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000003_10) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sec_r000003_8 + pub_r000003_15 + 16) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000003_14) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000003_18 + pub_r000003_3 + 24) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000003_13 + pub_r000003_12 + 18) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000003_14) & 127;
    st_var_1.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (stage_v_103 + pub_r000003_16 + 32) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000003_13) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sec_r000003_5 + pub_r000003_7 + 24) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000003_9) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_119 + pub_r000003_16 + 22) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (stage_v_98 + pub_r000003_8 + 29) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (sec_r000003_0 + pub_r000003_14 + 28) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000003_20 + pub_r000003_6 + 16) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sub_step_116 + pub_r000003_10 + 31) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000003_13) & 127;
    st_var_0.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000003_20 + pub_r000003_13 + 11) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (sec_r000003_11 + pub_r000003_15 + 11) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000003_7) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_132 + pub_r000003_1 + 18) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000003_9) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sec_r000003_2 + pub_r000003_8 + 17) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000003_18) & 127;
    st_var_0.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sub_step_131 + pub_r000003_5 + 17) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000003_0) & 127;
    st_var_1.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (stage_v_117 + pub_r000003_15 + 9) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000003_7) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sub_step_103 + pub_r000003_10 + 10) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000003_13) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sec_r000003_16 + pub_r000003_7 + 18) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_135 + pub_r000003_18 + 23) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000003_15) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sec_r000003_16 + pub_r000003_13 + 12) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sub_step_98 + pub_r000003_17 + 18) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sec_r000003_11 + pub_r000003_10 + 14) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000003_16) & 127;
    st_var_0.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000003_12 + pub_r000003_18 + 21) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_105 + pub_r000003_11 + 6) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sub_step_90 + pub_r000003_8 + 9) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000003_9) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_135 + pub_r000003_4 + 17) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (stage_v_141 + pub_r000003_5 + 5) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000003_13) & 127;
    st_var_1.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sub_step_120 + pub_r000003_15 + 22) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_123 + pub_r000003_10 + 9) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000003_9) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sec_r000003_13 + pub_r000003_1 + 35) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000003_12) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sub_step_99 + pub_r000003_17 + 8) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000003_7) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (stage_v_101 + pub_r000003_0 + 8) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_150 + pub_r000003_16 + 11) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000003_4) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sec_r000003_10 + pub_r000003_1 + 11) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sub_step_97 + pub_r000003_2 + 16) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000003_12) & 127;
    st_var_1.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000003_7 + pub_r000003_14 + 34) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (stage_v_119 + pub_r000003_5 + 26) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000003_12) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_117 + pub_r000003_9 + 27) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sub_step_151 + pub_r000003_7 + 9) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000003_16) & 127;
    st_var_1.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sub_step_103 + pub_r000003_8 + 19) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000003_13) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sub_step_94 + pub_r000003_0 + 17) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000003_14) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sec_r000003_14 + pub_r000003_16 + 24) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000003_14) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (stage_v_151 + pub_r000003_16 + 33) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000003_10) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000003_1 + pub_r000003_5 + 27) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sub_step_104 + pub_r000003_8 + 29) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000003_14) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (stage_v_100 + pub_r000003_12 + 33) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (stage_v_127 + pub_r000003_12 + 32) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sub_step_97 + pub_r000003_1 + 15) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000003_15) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sec_r000003_13 + pub_r000003_7 + 15) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000003_5) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_168 + pub_r000003_7 + 16) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000003_15) & 127;
    st_var_0.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000003_0 + pub_r000003_8 + 25) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000003_11) & 127;
    st_var_1.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (stage_v_160 + pub_r000003_17 + 9) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000003_16) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sec_r000003_6 + pub_r000003_17 + 35) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000003_10) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (stage_v_159 + pub_r000003_10 + 30) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (sec_r000003_17 + pub_r000003_1 + 20) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000003_6) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (stage_v_104 + pub_r000003_16 + 15) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000003_9) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (stage_v_114 + pub_r000003_13 + 24) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000003_18) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sub_step_173 + pub_r000003_6 + 14) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000003_8) & 127;
    st_var_0.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000003_10 + pub_r000003_11 + 14) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000003_6) & 127;
    st_var_1.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sub_step_137 + pub_r000003_10 + 33) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000003_9) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (stage_v_142 + pub_r000003_14 + 7) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000003_11) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_130 + pub_r000003_0 + 24) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000003_3 + pub_r000003_16 + 18) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000003_0) & 127;
    st_var_1.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (stage_v_135 + pub_r000003_1 + 11) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000003_14 + pub_r000003_14 + 33) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000003_18 + pub_r000003_18 + 11) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000003_18) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sec_r000003_14 + pub_r000003_9 + 22) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000003_13) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (stage_v_186 + pub_r000003_3 + 16) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sec_r000003_7 + pub_r000003_5 + 17) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sec_r000003_21 + pub_r000003_9 + 28) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000003_12) & 127;
    st_var_0.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (sec_r000003_9 + pub_r000003_17 + 23) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000003_6) & 127;
    st_var_1.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sec_r000003_6 + pub_r000003_7 + 25) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000003_17) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sub_step_119 + pub_r000003_13 + 17) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000003_12) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (sub_step_163 + pub_r000003_6 + 32) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000003_16) & 127;
    st_var_0.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000003_15 + pub_r000003_9 + 35) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000003_4) & 127;
    st_var_1.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sub_step_195 + pub_r000003_9 + 30) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (stage_v_120 + pub_r000003_5 + 8) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000003_1) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (stage_v_117 + pub_r000003_18 + 24) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000003_12) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (sec_r000003_0 + pub_r000003_17 + 25) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_108 + pub_r000003_16 + 24) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000003_17 + pub_r000003_10 + 16) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000003_12) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (stage_v_152 + pub_r000003_18 + 6) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000003_2) & 127;
    st_var_0.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (stage_v_135 + pub_r000003_15 + 17) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sub_step_188 + pub_r000003_10 + 14) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sub_step_122 + pub_r000003_18 + 30) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000003_7) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (stage_v_111 + pub_r000003_16 + 23) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000003_17) & 127;
    st_var_0.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_197 + pub_r000003_2 + 25) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000003_2) & 127;
    st_var_1.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000003_0 + pub_r000003_7 + 16) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000003_7) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sub_step_197 + pub_r000003_15 + 24) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (stage_v_200 + pub_r000003_5 + 29) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000003_10) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (stage_v_178 + pub_r000003_18 + 26) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sec_r000003_19 + pub_r000003_18 + 28) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000003_10) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_88 + pub_r000003_9 + 25) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000003_4) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_119 + pub_r000003_3 + 10) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000003_15) & 127;
    st_var_0.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_160 + pub_r000003_16 + 18) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000003_11) & 127;
    st_var_1.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sub_step_114 + pub_r000003_16 + 33) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (stage_v_203 + pub_r000003_3 + 16) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sub_step_213 + pub_r000003_1 + 32) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000003_18) & 127;
    st_var_0.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000003_3 + pub_r000003_16 + 29) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_213 + pub_r000003_0 + 26) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000003_7) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sec_r000003_18 + pub_r000003_6 + 25) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000003_7) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_196 + pub_r000003_2 + 5) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (stage_v_165 + pub_r000003_18 + 29) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000003_7 + pub_r000003_17 + 11) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000003_5) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_212 + pub_r000003_1 + 33) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000003_13) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sub_step_125 + pub_r000003_9 + 30) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (stage_v_118 + pub_r000003_16 + 10) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (sub_step_211 + pub_r000003_18 + 17) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000003_15) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (stage_v_92 + pub_r000003_16 + 12) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000003_8) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000003_7 + pub_r000003_7 + 5) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000003_12) & 127;
    st_var_0.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sub_step_154 + pub_r000003_8 + 34) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000003_16) & 127;
    st_var_1.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sec_r000003_5 + pub_r000003_13 + 13) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000003_17) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sub_step_130 + pub_r000003_15 + 29) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000003_15) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sub_step_127 + pub_r000003_7 + 22) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000003_17) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sec_r000003_0 + pub_r000003_18 + 20) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (sub_step_104 + pub_r000003_16 + 20) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_181 + pub_r000003_6 + 24) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000003_17) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sub_step_177 + pub_r000003_4 + 29) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000003_1) & 127;
    st_var_0.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000003_16 + pub_r000003_1 + 5) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000003_16) & 127;
    st_var_1.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sub_step_134 + pub_r000003_0 + 12) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_176 + pub_r000003_12 + 30) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000003_10) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sub_step_166 + pub_r000003_9 + 15) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000003_7) & 127;
    st_var_0.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (stage_v_112 + pub_r000003_16 + 15) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000003_15) & 127;
    st_var_1.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (stage_v_240 + pub_r000003_14 + 20) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sub_step_228 + pub_r000003_0 + 22) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000003_18) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (stage_v_194 + pub_r000003_10 + 15) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000003_4) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (stage_v_230 + pub_r000003_4 + 33) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000003_1) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sub_step_153 + pub_r000003_5 + 20) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000003_6) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (sec_r000003_3 + pub_r000003_17 + 23) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000003_18) & 127;
    st_var_1.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (sec_r000003_16 + pub_r000003_7 + 14) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000003_5) & 127;
    st_var_0.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (stage_v_246 + pub_r000003_4 + 30) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000003_16) & 127;
    st_var_1.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sub_step_145 + pub_r000003_8 + 33) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000003_0) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (sub_step_179 + pub_r000003_1 + 11) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000003_18) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (stage_v_132 + pub_r000003_6 + 16) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000003_3) & 127;
    st_var_0.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sub_step_93 + pub_r000003_1 + 31) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000003_13) & 127;
    st_var_1.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sub_step_147 + pub_r000003_13 + 31) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000003_17) & 127;
    st_var_0.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (sec_r000003_14 + pub_r000003_14 + 8) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000003_9) & 127;
    st_var_1.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (sec_r000003_9 + pub_r000003_7 + 30) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000003_11) & 127;
    st_var_0.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (sec_r000003_13 + pub_r000003_3 + 19) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000003_1) & 127;
    st_var_1.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (sub_step_164 + pub_r000003_1 + 33) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000003_18) & 127;
    st_var_0.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
