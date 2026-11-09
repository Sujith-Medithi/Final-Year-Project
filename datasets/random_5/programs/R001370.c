/*
 * Benchmark Program: R001370
 * Security Family: mixed_control_data
 * Generator Seed: 637013
 * High Inputs: 20 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001370_7013_0 {
    int sample_rate;
    short envelope;
    unsigned char rms;
    short channels;
    short gain;
    int peak;
    int buffer[3];
};

struct StreamBuffer_R001370_7013_1 {
    int checksum;
    short head;
    unsigned char watermark;
    int capacity;
    int buffer[3];
};

union TelemetryField_R001370_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001370_7013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_53 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_53 > 15) {
        acc = (acc + checksum_53 * 2 + 5) & 127;
        aux ^= (checksum_53 & 15);
    } else {
        acc = (acc - checksum_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_94 = (aux + st.buffer[1]) & 3;
    switch (parity_94) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001370_7013_1(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int anchor_65 = local_arr[aux % 3];
    acc = (acc + anchor_65 * 2) & 127;
    int checksum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_82 > 26) {
        acc = (acc + checksum_82 * 2 + 5) & 127;
        aux ^= (checksum_82 & 15);
    } else {
        acc = (acc - checksum_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001370_7013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_23 = local_arr[aux % 3];
    acc = (acc + delta_23 * 2) & 127;
    int metric_31 = (aux + st.buffer[1]) & 3;
    switch (metric_31) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_3(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_86 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_86 > 37) {
        acc = (acc + stride_86 * 2 + 5) & 127;
        aux ^= (stride_86 & 15);
    } else {
        acc = (acc - stride_86 + 11) & 127;
        aux += 3;
    }
    int tracker_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_61) & 63;
    acc ^= aux;
    int mask_12 = 0;
    for (int k = 0; k < 3; k++) {
        mask_12 = (mask_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_12) & 127;
    }
    int window_22 = (aux + st.buffer[1]) & 3;
    switch (window_22) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_88 = local_arr[aux % 3];
    acc = (acc + vector_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001370_7013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_88 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_88 > 11) {
        acc = (acc + index_reg_88 * 2 + 5) & 127;
        aux ^= (index_reg_88 & 15);
    } else {
        acc = (acc - index_reg_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int coefficient_34 = local_arr[aux % 3];
    acc = (acc + coefficient_34 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_11 > 40) {
        acc = (acc + tally_11 * 2 + 5) & 127;
        aux ^= (tally_11 & 15);
    } else {
        acc = (acc - tally_11 + 11) & 127;
        aux += 3;
    }
    int weight_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001370_7013_7(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_22) & 63;
    acc ^= aux;
    int pivot_66 = (aux + st.buffer[1]) & 3;
    switch (pivot_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int quantum_11 = local_arr[aux % 3];
    acc = (acc + quantum_11 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_78) & 63;
    acc ^= aux;
    int segment_14 = 0;
    for (int k = 0; k < 2; k++) {
        segment_14 = (segment_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int sample_71 = (aux + st.buffer[1]) & 3;
    switch (sample_71) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001370_7013_10(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_20 = (aux + st.buffer[1]) & 3;
    switch (pivot_20) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_72 = local_arr[aux % 3];
    acc = (acc + sample_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001370_7013_12(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_76) & 63;
    acc ^= aux;
    int delta_41 = (aux + st.buffer[1]) & 3;
    switch (delta_41) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_57 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_57 > 21) {
        acc = (acc + stride_57 * 2 + 5) & 127;
        aux ^= (stride_57 & 15);
    } else {
        acc = (acc - stride_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_14(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_51) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_64 = local_arr[aux % 3];
    acc = (acc + factor_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001370_7013_15(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_94 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_94 = (tracker_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_16(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_60 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_60 = (accumulator_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_60) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_94 = local_arr[aux % 3];
    acc = (acc + cursor_94 * 2) & 127;
    int weight_31 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_31 > 46) {
        acc = (acc + weight_31 * 2 + 5) & 127;
        aux ^= (weight_31 & 15);
    } else {
        acc = (acc - weight_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001370_7013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int factor_91 = 0;
    for (int k = 0; k < 3; k++) {
        factor_91 = (factor_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_91) & 127;
    }
    int tracker_24 = (aux + st.buffer[1]) & 3;
    switch (tracker_24) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001370_0;
    int sec_r001370_1;
    int sec_r001370_2;
    int sec_r001370_3;
    int sec_r001370_4;
    int sec_r001370_5;
    int sec_r001370_6;
    int sec_r001370_7;
    int sec_r001370_8;
    int sec_r001370_9;
    int sec_r001370_10;
    int sec_r001370_11;
    int sec_r001370_12;
    int sec_r001370_13;
    int sec_r001370_14;
    int sec_r001370_15;
    int sec_r001370_16;
    int sec_r001370_17;
    int sec_r001370_18;
    int sec_r001370_19;
    int pub_r001370_0;
    int pub_r001370_1;
    int pub_r001370_2;
    int pub_r001370_3;
    int pub_r001370_4;
    int pub_r001370_5;
    int pub_r001370_6;
    int pub_r001370_7;
    int pub_r001370_8;
    int pub_r001370_9;
    int pub_r001370_10;
    int pub_r001370_11;
    int pub_r001370_12;
    int pub_r001370_13;
    int pub_r001370_14;
    int pub_r001370_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001370_0 >= -100 && pub_r001370_0 <= 100);
    __CPROVER_assume(pub_r001370_1 >= -100 && pub_r001370_1 <= 100);
    __CPROVER_assume(pub_r001370_2 >= -100 && pub_r001370_2 <= 100);
    __CPROVER_assume(pub_r001370_3 >= -100 && pub_r001370_3 <= 100);
    __CPROVER_assume(pub_r001370_4 >= -100 && pub_r001370_4 <= 100);
    __CPROVER_assume(pub_r001370_5 >= -100 && pub_r001370_5 <= 100);
    __CPROVER_assume(pub_r001370_6 >= -100 && pub_r001370_6 <= 100);
    __CPROVER_assume(pub_r001370_7 >= -100 && pub_r001370_7 <= 100);
    __CPROVER_assume(pub_r001370_8 >= -100 && pub_r001370_8 <= 100);
    __CPROVER_assume(pub_r001370_9 >= -100 && pub_r001370_9 <= 100);
    __CPROVER_assume(pub_r001370_10 >= -100 && pub_r001370_10 <= 100);
    __CPROVER_assume(pub_r001370_11 >= -100 && pub_r001370_11 <= 100);
    __CPROVER_assume(pub_r001370_12 >= -100 && pub_r001370_12 <= 100);
    __CPROVER_assume(pub_r001370_13 >= -100 && pub_r001370_13 <= 100);
    __CPROVER_assume(pub_r001370_14 >= -100 && pub_r001370_14 <= 100);
    __CPROVER_assume(pub_r001370_15 >= -100 && pub_r001370_15 <= 100);
    __CPROVER_assume(sec_r001370_0 >= 0 && sec_r001370_0 <= 255);
    __CPROVER_assume(sec_r001370_1 >= 0 && sec_r001370_1 <= 255);
    __CPROVER_assume(sec_r001370_2 >= 0 && sec_r001370_2 <= 255);
    __CPROVER_assume(sec_r001370_3 >= 0 && sec_r001370_3 <= 255);
    __CPROVER_assume(sec_r001370_4 >= 0 && sec_r001370_4 <= 255);
    __CPROVER_assume(sec_r001370_5 >= 0 && sec_r001370_5 <= 255);
    __CPROVER_assume(sec_r001370_6 >= 0 && sec_r001370_6 <= 255);
    __CPROVER_assume(sec_r001370_7 >= 0 && sec_r001370_7 <= 255);
    __CPROVER_assume(sec_r001370_8 >= 0 && sec_r001370_8 <= 255);
    __CPROVER_assume(sec_r001370_9 >= 0 && sec_r001370_9 <= 255);
    __CPROVER_assume(sec_r001370_10 >= 0 && sec_r001370_10 <= 255);
    __CPROVER_assume(sec_r001370_11 >= 0 && sec_r001370_11 <= 255);
    __CPROVER_assume(sec_r001370_12 >= 0 && sec_r001370_12 <= 255);
    __CPROVER_assume(sec_r001370_13 >= 0 && sec_r001370_13 <= 255);
    __CPROVER_assume(sec_r001370_14 >= 0 && sec_r001370_14 <= 255);
    __CPROVER_assume(sec_r001370_15 >= 0 && sec_r001370_15 <= 255);
    __CPROVER_assume(sec_r001370_16 >= 0 && sec_r001370_16 <= 255);
    __CPROVER_assume(sec_r001370_17 >= 0 && sec_r001370_17 <= 255);
    __CPROVER_assume(sec_r001370_18 >= 0 && sec_r001370_18 <= 255);
    __CPROVER_assume(sec_r001370_19 >= 0 && sec_r001370_19 <= 255);

    struct AudioFrame_R001370_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001370_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001370_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001370_0 + 7) & 15;
    struct StreamBuffer_R001370_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001370_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001370_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001370_0 + 9) & 15;

    union TelemetryField_R001370_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001370_7013_0(sec_r001370_0, pub_r001370_1, pub_r001370_2, pub_r001370_3, pub_r001370_4);
    int helper_flow_1 = fn_R001370_7013_1(sec_r001370_1, sec_r001370_2, pub_r001370_3);
    int helper_flow_2 = fn_R001370_7013_2(sec_r001370_2, sec_r001370_3, pub_r001370_4, pub_r001370_5);
    int helper_flow_3 = fn_R001370_7013_3(sec_r001370_3, pub_r001370_4);
    int helper_flow_4 = fn_R001370_7013_4(sec_r001370_4, sec_r001370_5, pub_r001370_6, pub_r001370_7);
    int helper_flow_5 = fn_R001370_7013_5(sec_r001370_5, sec_r001370_6, pub_r001370_7, pub_r001370_8, pub_r001370_9);
    int helper_flow_6 = fn_R001370_7013_6(sec_r001370_6, pub_r001370_7, pub_r001370_8, pub_r001370_9, pub_r001370_10);
    int helper_flow_7 = fn_R001370_7013_7(sec_r001370_7, sec_r001370_8, pub_r001370_9);
    int helper_flow_8 = fn_R001370_7013_8(sec_r001370_8, pub_r001370_9, pub_r001370_10, pub_r001370_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_0 > 32) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001370_8 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_1 > 34) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_2 > 45) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001370_10 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_3 > 34) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001370_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001370_19 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_5 > 33) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001370_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_7 > 41) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001370_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001370_0 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_9 > 34) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001370_4 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_10 > 46) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_11 > 49) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001370_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001370_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001370_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_15 > 28) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_16 > 40) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001370_0 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_17 > 49) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_18 > 42) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001370_15 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_19 > 30) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001370_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001370_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_22 > 40) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001370_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001370_3 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_24 > 45) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001370_7 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_25 > 39) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_26 > 45) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001370_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001370_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_29 > 26) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001370_6 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_30 > 25) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_31 > 50) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_32 > 43) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_33 > 31) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_35 > 48) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001370_5 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_36 > 37) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_37 > 22) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_38 > 22) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001370_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001370_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001370_6 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_41 > 21) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001370_11 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_42 > 22) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001370_19 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_43 > 29) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_44 > 48) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001370_13 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_45 > 26) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001370_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001370_19 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_47 > 33) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001370_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_49 > 28) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_50 > 40) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001370_11 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_51 > 34) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_52 > 26) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_53 > 34) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001370_16 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_54 > 46) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_55 > 45) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_56 > 24) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001370_5 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_57 > 45) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001370_16 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001370_8 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_59 > 45) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_61 > 24) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001370_0 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_63 > 36) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001370_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_65 > 43) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001370_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_67 > 45) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_68 > 31) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_69 > 47) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001370_14 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_70 > 40) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_71 > 43) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001370_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_73 > 47) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_74 > 40) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_75 > 29) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001370_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_77 > 47) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001370_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001370_18 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_79 > 21) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_80 > 21) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_81 > 32) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_82 > 40) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_83 > 49) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_84 > 20) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_85 > 40) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_86 > 25) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001370_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_88 > 50) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_89 > 40) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001370_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_91 > 35) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001370_1 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_92 > 25) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_93 > 45) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_94 > 23) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001370_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_96 > 34) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_97 > 44) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_98 > 50) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001370_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_100 > 27) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_101 > 39) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001370_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001370_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_104 > 49) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_105 > 50) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001370_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_107 > 33) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_108 > 22) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_109 > 30) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_110 > 21) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001370_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_112 > 28) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_113 > 30) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001370_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001370_5 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_116 > 26) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_117 > 25) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001370_15 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_118 > 50) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_119 > 38) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_120 > 21) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_121 > 23) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_122 > 33) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001370_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_124 > 50) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_125 > 50) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_126 > 30) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_127 > 40) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_128 > 47) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001370_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_130 > 45) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_131 > 48) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_132 > 26) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001370_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_134 > 49) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001370_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001370_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_137 > 22) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_138 > 31) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_139 > 41) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001370_2 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_140 > 32) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001370_15 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_141 > 48) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_142 > 31) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_143 > 33) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001370_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001370_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_146 > 27) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_147 > 34) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_148 > 44) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_149 > 33) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_150 > 47) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_151 > 31) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_152 > 32) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_153 > 40) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_154 > 27) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001370_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001370_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_157 > 28) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_158 > 32) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_159 > 42) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_160 > 41) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_161 > 26) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_162 > 48) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_163 > 28) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_164 > 38) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_165 > 43) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001370_1) & 127;
    if (stage_v_166 > 46) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_167 > 36) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_168 > 28) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_169 > 41) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_170 > 20) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_171 > 40) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_172 > 25) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r001370_9 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_173 > 38) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_174 > 21) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_175 > 20) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001370_10 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_176 > 46) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_177 > 40) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_178 > 46) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_179 > 21) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_180 > 33) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001370_3 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_181 > 48) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001370_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001370_3 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_184 > 29) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001370_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001370_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001370_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_189 > 30) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001370_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001370_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_192 > 26) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_193 > 21) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001370_5) & 127;
    if (stage_v_194 > 49) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_195 > 45) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_196 > 36) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001370_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001370_11 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_198 > 41) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001370_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001370_15) & 127;
    if (stage_v_200 > 36) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001370_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001370_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_203 > 31) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001370_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_205 > 37) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_206 > 21) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001370_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_208 > 43) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_209 > 24) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001370_8 ^ 0x2A) * 2 + pub_r001370_7) & 127;
    if (stage_v_210 > 29) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_211 > 40) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_212 > 31) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((sec_r001370_15 ^ 0x2A) * 2 + pub_r001370_11) & 127;
    if (stage_v_214 > 27) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001370_14) & 127;
    if (stage_v_215 > 34) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001370_3) & 127;
    if (stage_v_216 > 21) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_217 > 50) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_218 > 35) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001370_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_217 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_220 > 44) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001370_2) & 127;
    if (stage_v_221 > 48) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001370_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_223 > 42) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001370_9) & 127;
    if (stage_v_224 > 25) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001370_8) & 127;
    if (stage_v_225 > 40) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001370_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001370_4) & 127;
    if (stage_v_227 > 45) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_228 > 48) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001370_12) & 127;
    if (stage_v_229 > 35) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_214 ^ 0x2A) * 2 + pub_r001370_0) & 127;
    if (stage_v_230 > 50) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_212 ^ 0x2A) * 2 + pub_r001370_6) & 127;
    if (stage_v_231 > 26) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001370_10) & 127;
    if (stage_v_232 > 35) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001370_13) & 127;
    if (stage_v_233 > 37) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
