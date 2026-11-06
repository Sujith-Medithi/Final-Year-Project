/*
 * Benchmark Program: R000713
 * Security Family: multi_step_explicit
 * Generator Seed: 571313
 * High Inputs: 17 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000713_1313_0 {
    int status;
    int fee;
    int balance;
    int rate;
    int buffer[3];
};

struct DeviceConfig_R000713_1313_1 {
    short port;
    short id;
    short timeout;
    unsigned char parity;
    short stop_bits;
    int buffer[3];
};

union PacketPayload_R000713_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000713_1313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000713_1313_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_52 = (aux + st.buffer[1]) & 3;
    switch (factor_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_24) & 63;
    acc ^= aux;
    int residue_13 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_13 > 18) {
        acc = (acc + residue_13 * 2 + 5) & 127;
        aux ^= (residue_13 & 15);
    } else {
        acc = (acc - residue_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_18 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_18 > 44) {
        acc = (acc + scale_18 * 2 + 5) & 127;
        aux ^= (scale_18 & 15);
    } else {
        acc = (acc - scale_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_32 = local_arr[aux % 3];
    acc = (acc + mask_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000713_1313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int bound_62 = local_arr[aux % 3];
    acc = (acc + bound_62 * 2) & 127;
    int segment_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_58) & 63;
    acc ^= aux;
    int bound_73 = (aux + st.buffer[1]) & 3;
    switch (bound_73) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_3(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int coefficient_68 = local_arr[aux % 3];
    acc = (acc + coefficient_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_86 = (aux + st.buffer[1]) & 3;
    switch (residue_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_4(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int accumulator_20 = local_arr[aux % 3];
    acc = (acc + accumulator_20 * 2) & 127;
    int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000713_1313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_43) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_47 = local_arr[aux % 3];
    acc = (acc + threshold_47 * 2) & 127;
    int tracker_24 = (aux + st.buffer[1]) & 3;
    switch (tracker_24) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_6(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000713_1313_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_93 = local_arr[aux % 3];
    acc = (acc + delta_93 * 2) & 127;
    int parity_23 = (aux + st.buffer[1]) & 3;
    switch (parity_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_98) & 63;
    acc ^= aux;
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 49) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_9(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int threshold_73 = local_arr[aux % 3];
    acc = (acc + threshold_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000713_1313_10(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_25 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_25 > 15) {
        acc = (acc + scale_25 * 2 + 5) & 127;
        aux ^= (scale_25 & 15);
    } else {
        acc = (acc - scale_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_11(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int residue_70 = local_arr[aux % 3];
    acc = (acc + residue_70 * 2) & 127;
    int accumulator_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_81) & 63;
    acc ^= aux;
    int segment_99 = (aux + st.buffer[1]) & 3;
    switch (segment_99) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000713_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_12 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_12 > 40) {
        acc = (acc + index_reg_12 * 2 + 5) & 127;
        aux ^= (index_reg_12 & 15);
    } else {
        acc = (acc - index_reg_12 + 11) & 127;
        aux += 3;
    }
    int sample_64 = (aux + st.buffer[1]) & 3;
    switch (sample_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_83 = local_arr[aux % 3];
    acc = (acc + vector_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000713_1313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_71 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_71 > 42) {
        acc = (acc + anchor_71 * 2 + 5) & 127;
        aux ^= (anchor_71 & 15);
    } else {
        acc = (acc - anchor_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_55 = local_arr[aux % 3];
    acc = (acc + residue_55 * 2) & 127;
    int window_92 = (aux + st.buffer[1]) & 3;
    switch (window_92) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000713_1313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int scale_75 = local_arr[aux % 3];
    acc = (acc + scale_75 * 2) & 127;
    int scale_32 = (aux + st.buffer[1]) & 3;
    switch (scale_32) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_48) & 63;
    acc ^= aux;
    int residue_90 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_90 > 50) {
        acc = (acc + residue_90 * 2 + 5) & 127;
        aux ^= (residue_90 & 15);
    } else {
        acc = (acc - residue_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000713_1313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000713_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor_93 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_93 > 36) {
        acc = (acc + cursor_93 * 2 + 5) & 127;
        aux ^= (cursor_93 & 15);
    } else {
        acc = (acc - cursor_93 + 11) & 127;
        aux += 3;
    }
    int vector_33 = (aux + st.buffer[1]) & 3;
    switch (vector_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000713_0;
    int sec_r000713_1;
    int sec_r000713_2;
    int sec_r000713_3;
    int sec_r000713_4;
    int sec_r000713_5;
    int sec_r000713_6;
    int sec_r000713_7;
    int sec_r000713_8;
    int sec_r000713_9;
    int sec_r000713_10;
    int sec_r000713_11;
    int sec_r000713_12;
    int sec_r000713_13;
    int sec_r000713_14;
    int sec_r000713_15;
    int sec_r000713_16;
    int pub_r000713_0;
    int pub_r000713_1;
    int pub_r000713_2;
    int pub_r000713_3;
    int pub_r000713_4;
    int pub_r000713_5;
    int pub_r000713_6;
    int pub_r000713_7;
    int pub_r000713_8;
    int pub_r000713_9;
    int pub_r000713_10;
    int pub_r000713_11;
    int pub_r000713_12;
    int pub_r000713_13;
    int pub_r000713_14;
    int pub_r000713_15;
    int pub_r000713_16;
    int pub_r000713_17;
    int pub_r000713_18;
    int pub_r000713_19;
    int pub_r000713_20;
    int pub_r000713_21;
    int pub_r000713_22;
    int pub_r000713_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000713_0 >= -100 && pub_r000713_0 <= 100);
    __CPROVER_assume(pub_r000713_1 >= -100 && pub_r000713_1 <= 100);
    __CPROVER_assume(pub_r000713_2 >= -100 && pub_r000713_2 <= 100);
    __CPROVER_assume(pub_r000713_3 >= -100 && pub_r000713_3 <= 100);
    __CPROVER_assume(pub_r000713_4 >= -100 && pub_r000713_4 <= 100);
    __CPROVER_assume(pub_r000713_5 >= -100 && pub_r000713_5 <= 100);
    __CPROVER_assume(pub_r000713_6 >= -100 && pub_r000713_6 <= 100);
    __CPROVER_assume(pub_r000713_7 >= -100 && pub_r000713_7 <= 100);
    __CPROVER_assume(pub_r000713_8 >= -100 && pub_r000713_8 <= 100);
    __CPROVER_assume(pub_r000713_9 >= -100 && pub_r000713_9 <= 100);
    __CPROVER_assume(pub_r000713_10 >= -100 && pub_r000713_10 <= 100);
    __CPROVER_assume(pub_r000713_11 >= -100 && pub_r000713_11 <= 100);
    __CPROVER_assume(pub_r000713_12 >= -100 && pub_r000713_12 <= 100);
    __CPROVER_assume(pub_r000713_13 >= -100 && pub_r000713_13 <= 100);
    __CPROVER_assume(pub_r000713_14 >= -100 && pub_r000713_14 <= 100);
    __CPROVER_assume(pub_r000713_15 >= -100 && pub_r000713_15 <= 100);
    __CPROVER_assume(pub_r000713_16 >= -100 && pub_r000713_16 <= 100);
    __CPROVER_assume(pub_r000713_17 >= -100 && pub_r000713_17 <= 100);
    __CPROVER_assume(pub_r000713_18 >= -100 && pub_r000713_18 <= 100);
    __CPROVER_assume(pub_r000713_19 >= -100 && pub_r000713_19 <= 100);
    __CPROVER_assume(pub_r000713_20 >= -100 && pub_r000713_20 <= 100);
    __CPROVER_assume(pub_r000713_21 >= -100 && pub_r000713_21 <= 100);
    __CPROVER_assume(pub_r000713_22 >= -100 && pub_r000713_22 <= 100);
    __CPROVER_assume(pub_r000713_23 >= -100 && pub_r000713_23 <= 100);
    __CPROVER_assume(sec_r000713_0 >= 0 && sec_r000713_0 <= 255);
    __CPROVER_assume(sec_r000713_1 >= 0 && sec_r000713_1 <= 255);
    __CPROVER_assume(sec_r000713_2 >= 0 && sec_r000713_2 <= 255);
    __CPROVER_assume(sec_r000713_3 >= 0 && sec_r000713_3 <= 255);
    __CPROVER_assume(sec_r000713_4 >= 0 && sec_r000713_4 <= 255);
    __CPROVER_assume(sec_r000713_5 >= 0 && sec_r000713_5 <= 255);
    __CPROVER_assume(sec_r000713_6 >= 0 && sec_r000713_6 <= 255);
    __CPROVER_assume(sec_r000713_7 >= 0 && sec_r000713_7 <= 255);
    __CPROVER_assume(sec_r000713_8 >= 0 && sec_r000713_8 <= 255);
    __CPROVER_assume(sec_r000713_9 >= 0 && sec_r000713_9 <= 255);
    __CPROVER_assume(sec_r000713_10 >= 0 && sec_r000713_10 <= 255);
    __CPROVER_assume(sec_r000713_11 >= 0 && sec_r000713_11 <= 255);
    __CPROVER_assume(sec_r000713_12 >= 0 && sec_r000713_12 <= 255);
    __CPROVER_assume(sec_r000713_13 >= 0 && sec_r000713_13 <= 255);
    __CPROVER_assume(sec_r000713_14 >= 0 && sec_r000713_14 <= 255);
    __CPROVER_assume(sec_r000713_15 >= 0 && sec_r000713_15 <= 255);
    __CPROVER_assume(sec_r000713_16 >= 0 && sec_r000713_16 <= 255);

    struct Transaction_R000713_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000713_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000713_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000713_0 + 7) & 15;
    struct DeviceConfig_R000713_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000713_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000713_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000713_0 + 9) & 15;

    union PacketPayload_R000713_1313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 14) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 29) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

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
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 39) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 54) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 17) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 32) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 20) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 35) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 31) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 46) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 33) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 48) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 12) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 27) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 25) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 40) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 14) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 29) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 39) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 54) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 31) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 46) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

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
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 35) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 50) {
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
    int sub_step_65 = (sec_r000713_11 + pub_r000713_20 + 26) & 127;
    int stage_v_65 = (sub_step_65 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[2] = (stage_v_65 & 15);
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int sub_step_66 = (sec_r000713_10 + pub_r000713_17 + 24) & 127;
    int stage_v_66 = (sub_step_66 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[0] = (stage_v_66 & 15);
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int sub_step_67 = (stage_v_66 + pub_r000713_1 + 17) & 127;
    int stage_v_67 = (sub_step_67 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[1] = (stage_v_67 & 15);
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int sub_step_68 = (sub_step_67 + pub_r000713_15 + 9) & 127;
    int stage_v_68 = (sub_step_68 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[2] = (stage_v_68 & 15);
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int sub_step_69 = (sec_r000713_7 + pub_r000713_20 + 27) & 127;
    int stage_v_69 = (sub_step_69 * 2 + pub_r000713_22) & 127;
    st_var_1.buffer[0] = (stage_v_69 & 15);
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int sub_step_70 = (stage_v_65 + pub_r000713_17 + 21) & 127;
    int stage_v_70 = (sub_step_70 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[1] = (stage_v_70 & 15);
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int sub_step_71 = (sec_r000713_2 + pub_r000713_10 + 19) & 127;
    int stage_v_71 = (sub_step_71 * 2 + pub_r000713_21) & 127;
    st_var_1.buffer[2] = (stage_v_71 & 15);
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (sec_r000713_16 + pub_r000713_21 + 35) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000713_17) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (stage_v_66 + pub_r000713_8 + 18) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (stage_v_69 + pub_r000713_23 + 10) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000713_19) & 127;
    st_var_0.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (sub_step_69 + pub_r000713_5 + 17) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000713_20) & 127;
    st_var_1.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (sub_step_66 + pub_r000713_1 + 16) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (sec_r000713_9 + pub_r000713_4 + 34) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000713_5) & 127;
    st_var_1.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (stage_v_73 + pub_r000713_12 + 30) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000713_9) & 127;
    st_var_0.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sec_r000713_15 + pub_r000713_11 + 19) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (sec_r000713_15 + pub_r000713_17 + 15) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000713_12 + pub_r000713_17 + 12) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sec_r000713_10 + pub_r000713_5 + 30) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (sec_r000713_5 + pub_r000713_1 + 35) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sub_step_72 + pub_r000713_0 + 13) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000713_18) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sec_r000713_12 + pub_r000713_10 + 29) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000713_10) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sub_step_80 + pub_r000713_19 + 27) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (sub_step_65 + pub_r000713_9 + 17) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (stage_v_70 + pub_r000713_2 + 10) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sec_r000713_3 + pub_r000713_1 + 33) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (stage_v_80 + pub_r000713_7 + 15) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (stage_v_80 + pub_r000713_20 + 15) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sec_r000713_8 + pub_r000713_10 + 25) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sec_r000713_5 + pub_r000713_13 + 27) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000713_4) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000713_11 + pub_r000713_20 + 21) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sub_step_89 + pub_r000713_4 + 18) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (stage_v_94 + pub_r000713_16 + 7) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000713_8) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (stage_v_77 + pub_r000713_17 + 32) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000713_5) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (stage_v_70 + pub_r000713_8 + 30) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000713_3 + pub_r000713_16 + 27) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_87 + pub_r000713_2 + 12) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sub_step_93 + pub_r000713_9 + 11) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000713_14 + pub_r000713_4 + 30) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000713_1 + pub_r000713_19 + 24) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_79 + pub_r000713_1 + 9) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (stage_v_77 + pub_r000713_16 + 19) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000713_21) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sec_r000713_0 + pub_r000713_20 + 6) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000713_13) & 127;
    st_var_0.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sec_r000713_9 + pub_r000713_9 + 24) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_77 + pub_r000713_2 + 10) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sub_step_69 + pub_r000713_7 + 33) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_94 + pub_r000713_23 + 20) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sec_r000713_9 + pub_r000713_23 + 8) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000713_3 + pub_r000713_2 + 34) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000713_15 + pub_r000713_9 + 20) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000713_18) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_109 + pub_r000713_20 + 21) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000713_13) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (stage_v_100 + pub_r000713_0 + 27) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sec_r000713_8 + pub_r000713_20 + 10) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_88 + pub_r000713_14 + 15) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_81 + pub_r000713_15 + 8) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000713_13) & 127;
    st_var_0.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (stage_v_110 + pub_r000713_4 + 14) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000713_7 + pub_r000713_3 + 27) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sub_step_88 + pub_r000713_14 + 17) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sub_step_78 + pub_r000713_12 + 18) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (stage_v_98 + pub_r000713_21 + 30) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000713_2) & 127;
    st_var_1.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_118 + pub_r000713_2 + 16) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000713_8) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sub_step_72 + pub_r000713_7 + 22) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (sub_step_79 + pub_r000713_12 + 20) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000713_22) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sec_r000713_7 + pub_r000713_21 + 21) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000713_2) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (sub_step_83 + pub_r000713_17 + 7) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000713_5 + pub_r000713_14 + 11) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000713_4) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sec_r000713_16 + pub_r000713_23 + 15) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (stage_v_75 + pub_r000713_7 + 22) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_86 + pub_r000713_1 + 22) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sec_r000713_6 + pub_r000713_2 + 30) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (stage_v_98 + pub_r000713_9 + 29) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_115 + pub_r000713_7 + 24) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_79 + pub_r000713_18 + 10) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sec_r000713_0 + pub_r000713_22 + 31) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (stage_v_81 + pub_r000713_14 + 10) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sec_r000713_9 + pub_r000713_22 + 7) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sec_r000713_11 + pub_r000713_14 + 35) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000713_2) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (stage_v_124 + pub_r000713_11 + 25) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sub_step_136 + pub_r000713_5 + 22) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000713_5 + pub_r000713_21 + 21) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_134 + pub_r000713_20 + 32) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_94 + pub_r000713_8 + 10) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000713_21) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sec_r000713_15 + pub_r000713_17 + 22) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sub_step_91 + pub_r000713_7 + 8) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000713_15 + pub_r000713_17 + 35) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_114 + pub_r000713_9 + 21) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sec_r000713_11 + pub_r000713_7 + 10) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sub_step_131 + pub_r000713_17 + 25) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (stage_v_104 + pub_r000713_0 + 34) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_117 + pub_r000713_14 + 20) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000713_2) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sec_r000713_2 + pub_r000713_23 + 17) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sub_step_135 + pub_r000713_10 + 28) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (stage_v_100 + pub_r000713_19 + 11) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sub_step_139 + pub_r000713_11 + 21) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_115 + pub_r000713_1 + 16) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000713_8 + pub_r000713_7 + 12) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (stage_v_121 + pub_r000713_18 + 29) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (stage_v_110 + pub_r000713_20 + 23) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (stage_v_120 + pub_r000713_14 + 6) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000713_18) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_137 + pub_r000713_2 + 5) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sub_step_129 + pub_r000713_15 + 24) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_136 + pub_r000713_18 + 27) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sec_r000713_4 + pub_r000713_5 + 32) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (stage_v_107 + pub_r000713_5 + 20) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sub_step_113 + pub_r000713_23 + 13) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000713_7) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sec_r000713_7 + pub_r000713_11 + 28) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000713_18) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_111 + pub_r000713_5 + 24) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (stage_v_134 + pub_r000713_10 + 28) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000713_20) & 127;
    st_var_1.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sec_r000713_10 + pub_r000713_2 + 25) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sec_r000713_11 + pub_r000713_19 + 21) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sub_step_121 + pub_r000713_3 + 18) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (sub_step_174 + pub_r000713_19 + 26) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000713_13) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sub_step_121 + pub_r000713_14 + 24) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sec_r000713_5 + pub_r000713_22 + 34) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (stage_v_143 + pub_r000713_20 + 9) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000713_8 + pub_r000713_9 + 6) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (stage_v_149 + pub_r000713_15 + 24) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (stage_v_165 + pub_r000713_8 + 23) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000713_22) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_132 + pub_r000713_15 + 27) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000713_10 + pub_r000713_9 + 19) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sub_step_163 + pub_r000713_2 + 35) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000713_2 + pub_r000713_23 + 23) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000713_8) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000713_3 + pub_r000713_9 + 16) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sec_r000713_6 + pub_r000713_17 + 21) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000713_18) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_135 + pub_r000713_3 + 14) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sec_r000713_11 + pub_r000713_1 + 22) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (stage_v_156 + pub_r000713_18 + 28) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_105 + pub_r000713_17 + 6) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000713_10) & 127;
    st_var_1.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sub_step_78 + pub_r000713_4 + 22) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (stage_v_169 + pub_r000713_9 + 24) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000713_5) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (sub_step_78 + pub_r000713_0 + 8) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (stage_v_84 + pub_r000713_19 + 8) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sec_r000713_3 + pub_r000713_16 + 24) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sub_step_84 + pub_r000713_15 + 12) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000713_8) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_69 + pub_r000713_20 + 11) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000713_7) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (sec_r000713_9 + pub_r000713_18 + 28) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sec_r000713_8 + pub_r000713_0 + 22) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (stage_v_121 + pub_r000713_12 + 19) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000713_20) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sub_step_96 + pub_r000713_3 + 11) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000713_18) & 127;
    st_var_0.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sub_step_158 + pub_r000713_0 + 8) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000713_7) & 127;
    st_var_1.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sub_step_187 + pub_r000713_16 + 10) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sub_step_195 + pub_r000713_9 + 34) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000713_10) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sec_r000713_4 + pub_r000713_7 + 21) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (stage_v_154 + pub_r000713_10 + 8) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000713_2) & 127;
    st_var_1.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000713_5 + pub_r000713_9 + 11) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (stage_v_139 + pub_r000713_15 + 23) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000713_9) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sub_step_110 + pub_r000713_20 + 20) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (stage_v_138 + pub_r000713_18 + 14) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000713_7) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sec_r000713_10 + pub_r000713_17 + 29) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_98 + pub_r000713_1 + 12) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (sub_step_159 + pub_r000713_12 + 22) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000713_15) & 127;
    st_var_0.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_126 + pub_r000713_7 + 25) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000713_8 + pub_r000713_20 + 24) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000713_13) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sec_r000713_12 + pub_r000713_7 + 33) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_113 + pub_r000713_9 + 18) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (stage_v_110 + pub_r000713_9 + 19) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000713_4) & 127;
    st_var_1.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_166 + pub_r000713_4 + 17) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_84 + pub_r000713_1 + 10) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (stage_v_101 + pub_r000713_4 + 28) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000713_4 + pub_r000713_13 + 34) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sub_step_159 + pub_r000713_16 + 18) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sec_r000713_2 + pub_r000713_23 + 29) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000713_21) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sec_r000713_16 + pub_r000713_16 + 29) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (stage_v_213 + pub_r000713_0 + 23) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_217 + pub_r000713_3 + 26) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000713_22) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sub_step_208 + pub_r000713_7 + 33) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (stage_v_133 + pub_r000713_17 + 16) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sec_r000713_13 + pub_r000713_19 + 18) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sec_r000713_15 + pub_r000713_20 + 30) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (stage_v_164 + pub_r000713_16 + 34) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000713_8) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sub_step_80 + pub_r000713_2 + 32) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_225 + pub_r000713_12 + 34) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_86 + pub_r000713_12 + 32) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_181 + pub_r000713_17 + 20) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sub_step_76 + pub_r000713_9 + 34) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000713_7 + pub_r000713_23 + 17) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (stage_v_201 + pub_r000713_13 + 31) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000713_5) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (stage_v_143 + pub_r000713_11 + 8) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (stage_v_170 + pub_r000713_18 + 8) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000713_10) & 127;
    st_var_0.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sub_step_89 + pub_r000713_4 + 9) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (sec_r000713_0 + pub_r000713_8 + 21) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000713_17) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (stage_v_178 + pub_r000713_1 + 31) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (sub_step_195 + pub_r000713_14 + 12) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (stage_v_204 + pub_r000713_20 + 7) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sec_r000713_7 + pub_r000713_22 + 10) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (sec_r000713_11 + pub_r000713_21 + 10) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (stage_v_144 + pub_r000713_14 + 28) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (sub_step_80 + pub_r000713_23 + 29) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sec_r000713_6 + pub_r000713_14 + 35) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000713_3) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (stage_v_185 + pub_r000713_16 + 10) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000713_22) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sec_r000713_5 + pub_r000713_8 + 26) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sec_r000713_4 + pub_r000713_19 + 24) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sub_step_168 + pub_r000713_10 + 11) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (sec_r000713_5 + pub_r000713_14 + 33) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (stage_v_167 + pub_r000713_11 + 30) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000713_8) & 127;
    st_var_0.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (stage_v_123 + pub_r000713_7 + 21) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (sub_step_154 + pub_r000713_1 + 34) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000713_17) & 127;
    st_var_0.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int sub_step_261 = (sec_r000713_10 + pub_r000713_6 + 9) & 127;
    int stage_v_261 = (sub_step_261 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[0] = (stage_v_261 & 15);
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int sub_step_262 = (stage_v_222 + pub_r000713_21 + 17) & 127;
    int stage_v_262 = (sub_step_262 * 2 + pub_r000713_9) & 127;
    st_var_0.buffer[1] = (stage_v_262 & 15);
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int sub_step_263 = (sub_step_113 + pub_r000713_18 + 12) & 127;
    int stage_v_263 = (sub_step_263 * 2 + pub_r000713_1) & 127;
    st_var_1.buffer[2] = (stage_v_263 & 15);
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int sub_step_264 = (sec_r000713_8 + pub_r000713_4 + 23) & 127;
    int stage_v_264 = (sub_step_264 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[0] = (stage_v_264 & 15);
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int sub_step_265 = (sub_step_230 + pub_r000713_13 + 17) & 127;
    int stage_v_265 = (sub_step_265 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[1] = (stage_v_265 & 15);
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int sub_step_266 = (sub_step_125 + pub_r000713_4 + 33) & 127;
    int stage_v_266 = (sub_step_266 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[2] = (stage_v_266 & 15);
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int sub_step_267 = (stage_v_90 + pub_r000713_20 + 34) & 127;
    int stage_v_267 = (sub_step_267 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[0] = (stage_v_267 & 15);
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int sub_step_268 = (stage_v_246 + pub_r000713_11 + 31) & 127;
    int stage_v_268 = (sub_step_268 * 2 + pub_r000713_18) & 127;
    st_var_0.buffer[1] = (stage_v_268 & 15);
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int sub_step_269 = (stage_v_152 + pub_r000713_12 + 20) & 127;
    int stage_v_269 = (sub_step_269 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[2] = (stage_v_269 & 15);
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int sub_step_270 = (sec_r000713_6 + pub_r000713_19 + 13) & 127;
    int stage_v_270 = (sub_step_270 * 2 + pub_r000713_19) & 127;
    st_var_0.buffer[0] = (stage_v_270 & 15);
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int sub_step_271 = (sub_step_202 + pub_r000713_7 + 15) & 127;
    int stage_v_271 = (sub_step_271 * 2 + pub_r000713_13) & 127;
    st_var_1.buffer[1] = (stage_v_271 & 15);
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int sub_step_272 = (sec_r000713_11 + pub_r000713_7 + 25) & 127;
    int stage_v_272 = (sub_step_272 * 2 + pub_r000713_4) & 127;
    st_var_0.buffer[2] = (stage_v_272 & 15);
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int sub_step_273 = (sub_step_257 + pub_r000713_13 + 19) & 127;
    int stage_v_273 = (sub_step_273 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_273 & 15);
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int sub_step_274 = (stage_v_143 + pub_r000713_13 + 29) & 127;
    int stage_v_274 = (sub_step_274 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[1] = (stage_v_274 & 15);
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int sub_step_275 = (sec_r000713_9 + pub_r000713_9 + 17) & 127;
    int stage_v_275 = (sub_step_275 * 2 + pub_r000713_13) & 127;
    st_var_1.buffer[2] = (stage_v_275 & 15);
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int sub_step_276 = (stage_v_263 + pub_r000713_4 + 34) & 127;
    int stage_v_276 = (sub_step_276 * 2 + pub_r000713_23) & 127;
    st_var_0.buffer[0] = (stage_v_276 & 15);
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int sub_step_277 = (sec_r000713_12 + pub_r000713_14 + 22) & 127;
    int stage_v_277 = (sub_step_277 * 2 + pub_r000713_8) & 127;
    st_var_1.buffer[1] = (stage_v_277 & 15);
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int sub_step_278 = (stage_v_236 + pub_r000713_12 + 17) & 127;
    int stage_v_278 = (sub_step_278 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[2] = (stage_v_278 & 15);
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int sub_step_279 = (sub_step_261 + pub_r000713_10 + 32) & 127;
    int stage_v_279 = (sub_step_279 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_279 & 15);
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int sub_step_280 = (sub_step_189 + pub_r000713_11 + 26) & 127;
    int stage_v_280 = (sub_step_280 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[1] = (stage_v_280 & 15);
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int sub_step_281 = (sec_r000713_7 + pub_r000713_20 + 21) & 127;
    int stage_v_281 = (sub_step_281 * 2 + pub_r000713_14) & 127;
    st_var_1.buffer[2] = (stage_v_281 & 15);
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int sub_step_282 = (stage_v_87 + pub_r000713_3 + 16) & 127;
    int stage_v_282 = (sub_step_282 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[0] = (stage_v_282 & 15);
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int sub_step_283 = (sec_r000713_10 + pub_r000713_22 + 8) & 127;
    int stage_v_283 = (sub_step_283 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[1] = (stage_v_283 & 15);
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int sub_step_284 = (stage_v_121 + pub_r000713_7 + 19) & 127;
    int stage_v_284 = (sub_step_284 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[2] = (stage_v_284 & 15);
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int sub_step_285 = (stage_v_240 + pub_r000713_7 + 17) & 127;
    int stage_v_285 = (sub_step_285 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[0] = (stage_v_285 & 15);
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int sub_step_286 = (sub_step_112 + pub_r000713_19 + 33) & 127;
    int stage_v_286 = (sub_step_286 * 2 + pub_r000713_20) & 127;
    st_var_0.buffer[1] = (stage_v_286 & 15);
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int sub_step_287 = (stage_v_286 + pub_r000713_22 + 6) & 127;
    int stage_v_287 = (sub_step_287 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[2] = (stage_v_287 & 15);
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int sub_step_288 = (sub_step_154 + pub_r000713_16 + 8) & 127;
    int stage_v_288 = (sub_step_288 * 2 + pub_r000713_10) & 127;
    st_var_0.buffer[0] = (stage_v_288 & 15);
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int sub_step_289 = (sec_r000713_13 + pub_r000713_23 + 22) & 127;
    int stage_v_289 = (sub_step_289 * 2 + pub_r000713_20) & 127;
    st_var_1.buffer[1] = (stage_v_289 & 15);
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int sub_step_290 = (sub_step_255 + pub_r000713_20 + 12) & 127;
    int stage_v_290 = (sub_step_290 * 2 + pub_r000713_10) & 127;
    st_var_0.buffer[2] = (stage_v_290 & 15);
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int sub_step_291 = (sec_r000713_7 + pub_r000713_1 + 10) & 127;
    int stage_v_291 = (sub_step_291 * 2 + pub_r000713_7) & 127;
    st_var_1.buffer[0] = (stage_v_291 & 15);
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int sub_step_292 = (sub_step_285 + pub_r000713_3 + 27) & 127;
    int stage_v_292 = (sub_step_292 * 2 + pub_r000713_15) & 127;
    st_var_0.buffer[1] = (stage_v_292 & 15);
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int sub_step_293 = (stage_v_125 + pub_r000713_12 + 21) & 127;
    int stage_v_293 = (sub_step_293 * 2 + pub_r000713_19) & 127;
    st_var_1.buffer[2] = (stage_v_293 & 15);
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int sub_step_294 = (sub_step_252 + pub_r000713_12 + 23) & 127;
    int stage_v_294 = (sub_step_294 * 2 + pub_r000713_15) & 127;
    st_var_0.buffer[0] = (stage_v_294 & 15);
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int sub_step_295 = (sub_step_87 + pub_r000713_1 + 10) & 127;
    int stage_v_295 = (sub_step_295 * 2 + pub_r000713_0) & 127;
    st_var_1.buffer[1] = (stage_v_295 & 15);
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int sub_step_296 = (stage_v_116 + pub_r000713_4 + 8) & 127;
    int stage_v_296 = (sub_step_296 * 2 + pub_r000713_7) & 127;
    st_var_0.buffer[2] = (stage_v_296 & 15);
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int sub_step_297 = (sub_step_132 + pub_r000713_16 + 31) & 127;
    int stage_v_297 = (sub_step_297 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[0] = (stage_v_297 & 15);
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int sub_step_298 = (sec_r000713_3 + pub_r000713_19 + 27) & 127;
    int stage_v_298 = (sub_step_298 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[1] = (stage_v_298 & 15);
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int sub_step_299 = (sec_r000713_2 + pub_r000713_9 + 8) & 127;
    int stage_v_299 = (sub_step_299 * 2 + pub_r000713_15) & 127;
    st_var_1.buffer[2] = (stage_v_299 & 15);
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int sub_step_300 = (stage_v_78 + pub_r000713_17 + 28) & 127;
    int stage_v_300 = (sub_step_300 * 2 + pub_r000713_8) & 127;
    st_var_0.buffer[0] = (stage_v_300 & 15);
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int sub_step_301 = (stage_v_97 + pub_r000713_20 + 11) & 127;
    int stage_v_301 = (sub_step_301 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[1] = (stage_v_301 & 15);
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int sub_step_302 = (stage_v_278 + pub_r000713_0 + 13) & 127;
    int stage_v_302 = (sub_step_302 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[2] = (stage_v_302 & 15);
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int sub_step_303 = (stage_v_207 + pub_r000713_6 + 13) & 127;
    int stage_v_303 = (sub_step_303 * 2 + pub_r000713_16) & 127;
    st_var_1.buffer[0] = (stage_v_303 & 15);
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int sub_step_304 = (sec_r000713_4 + pub_r000713_7 + 24) & 127;
    int stage_v_304 = (sub_step_304 * 2 + pub_r000713_13) & 127;
    st_var_0.buffer[1] = (stage_v_304 & 15);
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int sub_step_305 = (stage_v_94 + pub_r000713_7 + 21) & 127;
    int stage_v_305 = (sub_step_305 * 2 + pub_r000713_22) & 127;
    st_var_1.buffer[2] = (stage_v_305 & 15);
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int sub_step_306 = (stage_v_269 + pub_r000713_3 + 27) & 127;
    int stage_v_306 = (sub_step_306 * 2 + pub_r000713_14) & 127;
    st_var_0.buffer[0] = (stage_v_306 & 15);
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int sub_step_307 = (sec_r000713_2 + pub_r000713_21 + 33) & 127;
    int stage_v_307 = (sub_step_307 * 2 + pub_r000713_17) & 127;
    st_var_1.buffer[1] = (stage_v_307 & 15);
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int sub_step_308 = (stage_v_262 + pub_r000713_17 + 35) & 127;
    int stage_v_308 = (sub_step_308 * 2 + pub_r000713_21) & 127;
    st_var_0.buffer[2] = (stage_v_308 & 15);
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int sub_step_309 = (stage_v_190 + pub_r000713_18 + 13) & 127;
    int stage_v_309 = (sub_step_309 * 2 + pub_r000713_13) & 127;
    st_var_1.buffer[0] = (stage_v_309 & 15);
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int sub_step_310 = (stage_v_95 + pub_r000713_8 + 32) & 127;
    int stage_v_310 = (sub_step_310 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[1] = (stage_v_310 & 15);
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int sub_step_311 = (sub_step_197 + pub_r000713_3 + 16) & 127;
    int stage_v_311 = (sub_step_311 * 2 + pub_r000713_3) & 127;
    st_var_1.buffer[2] = (stage_v_311 & 15);
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int sub_step_312 = (sub_step_197 + pub_r000713_18 + 16) & 127;
    int stage_v_312 = (sub_step_312 * 2 + pub_r000713_16) & 127;
    st_var_0.buffer[0] = (stage_v_312 & 15);
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int sub_step_313 = (stage_v_138 + pub_r000713_16 + 11) & 127;
    int stage_v_313 = (sub_step_313 * 2 + pub_r000713_12) & 127;
    st_var_1.buffer[1] = (stage_v_313 & 15);
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int sub_step_314 = (sec_r000713_2 + pub_r000713_8 + 18) & 127;
    int stage_v_314 = (sub_step_314 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[2] = (stage_v_314 & 15);
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int sub_step_315 = (sec_r000713_5 + pub_r000713_5 + 32) & 127;
    int stage_v_315 = (sub_step_315 * 2 + pub_r000713_2) & 127;
    st_var_1.buffer[0] = (stage_v_315 & 15);
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int sub_step_316 = (sec_r000713_10 + pub_r000713_23 + 35) & 127;
    int stage_v_316 = (sub_step_316 * 2 + pub_r000713_12) & 127;
    st_var_0.buffer[1] = (stage_v_316 & 15);
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int sub_step_317 = (stage_v_113 + pub_r000713_19 + 6) & 127;
    int stage_v_317 = (sub_step_317 * 2 + pub_r000713_7) & 127;
    st_var_1.buffer[2] = (stage_v_317 & 15);
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int sub_step_318 = (stage_v_284 + pub_r000713_18 + 31) & 127;
    int stage_v_318 = (sub_step_318 * 2 + pub_r000713_2) & 127;
    st_var_0.buffer[0] = (stage_v_318 & 15);
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int sub_step_319 = (sec_r000713_5 + pub_r000713_11 + 29) & 127;
    int stage_v_319 = (sub_step_319 * 2 + pub_r000713_11) & 127;
    st_var_1.buffer[1] = (stage_v_319 & 15);
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int sub_step_320 = (stage_v_276 + pub_r000713_23 + 15) & 127;
    int stage_v_320 = (sub_step_320 * 2 + pub_r000713_11) & 127;
    st_var_0.buffer[2] = (stage_v_320 & 15);
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int sub_step_321 = (sec_r000713_5 + pub_r000713_13 + 26) & 127;
    int stage_v_321 = (sub_step_321 * 2 + pub_r000713_13) & 127;
    st_var_1.buffer[0] = (stage_v_321 & 15);
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int sub_step_322 = (stage_v_117 + pub_r000713_17 + 31) & 127;
    int stage_v_322 = (sub_step_322 * 2 + pub_r000713_6) & 127;
    st_var_0.buffer[1] = (stage_v_322 & 15);
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int sub_step_323 = (sub_step_238 + pub_r000713_4 + 8) & 127;
    int stage_v_323 = (sub_step_323 * 2 + pub_r000713_6) & 127;
    st_var_1.buffer[2] = (stage_v_323 & 15);
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int sub_step_324 = (sub_step_179 + pub_r000713_5 + 29) & 127;
    int stage_v_324 = (sub_step_324 * 2 + pub_r000713_0) & 127;
    st_var_0.buffer[0] = (stage_v_324 & 15);
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int sub_step_325 = (stage_v_223 + pub_r000713_12 + 34) & 127;
    int stage_v_325 = (sub_step_325 * 2 + pub_r000713_4) & 127;
    st_var_1.buffer[1] = (stage_v_325 & 15);
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int sub_step_326 = (stage_v_322 + pub_r000713_19 + 24) & 127;
    int stage_v_326 = (sub_step_326 * 2 + pub_r000713_17) & 127;
    st_var_0.buffer[2] = (stage_v_326 & 15);
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int sub_step_327 = (sub_step_236 + pub_r000713_1 + 33) & 127;
    int stage_v_327 = (sub_step_327 * 2 + pub_r000713_5) & 127;
    st_var_1.buffer[0] = (stage_v_327 & 15);
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int sub_step_328 = (sub_step_323 + pub_r000713_21 + 28) & 127;
    int stage_v_328 = (sub_step_328 * 2 + pub_r000713_15) & 127;
    st_var_0.buffer[1] = (stage_v_328 & 15);
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int sub_step_329 = (sec_r000713_9 + pub_r000713_2 + 19) & 127;
    int stage_v_329 = (sub_step_329 * 2 + pub_r000713_22) & 127;
    st_var_1.buffer[2] = (stage_v_329 & 15);
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int sub_step_330 = (sec_r000713_9 + pub_r000713_2 + 32) & 127;
    int stage_v_330 = (sub_step_330 * 2 + pub_r000713_10) & 127;
    st_var_0.buffer[0] = (stage_v_330 & 15);
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int sub_step_331 = (stage_v_257 + pub_r000713_14 + 14) & 127;
    int stage_v_331 = (sub_step_331 * 2 + pub_r000713_21) & 127;
    st_var_1.buffer[1] = (stage_v_331 & 15);
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int sub_step_332 = (sub_step_262 + pub_r000713_17 + 17) & 127;
    int stage_v_332 = (sub_step_332 * 2 + pub_r000713_1) & 127;
    st_var_0.buffer[2] = (stage_v_332 & 15);
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int sub_step_333 = (sub_step_90 + pub_r000713_14 + 33) & 127;
    int stage_v_333 = (sub_step_333 * 2 + pub_r000713_9) & 127;
    st_var_1.buffer[0] = (stage_v_333 & 15);
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int sub_step_334 = (sec_r000713_12 + pub_r000713_0 + 20) & 127;
    int stage_v_334 = (sub_step_334 * 2 + pub_r000713_8) & 127;
    st_var_0.buffer[1] = (stage_v_334 & 15);
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int sub_step_335 = (sec_r000713_6 + pub_r000713_14 + 31) & 127;
    int stage_v_335 = (sub_step_335 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[2] = (stage_v_335 & 15);
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int sub_step_336 = (sub_step_331 + pub_r000713_23 + 14) & 127;
    int stage_v_336 = (sub_step_336 * 2 + pub_r000713_18) & 127;
    st_var_0.buffer[0] = (stage_v_336 & 15);
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int sub_step_337 = (stage_v_336 + pub_r000713_1 + 35) & 127;
    int stage_v_337 = (sub_step_337 * 2 + pub_r000713_10) & 127;
    st_var_1.buffer[1] = (stage_v_337 & 15);
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int sub_step_338 = (sub_step_190 + pub_r000713_20 + 31) & 127;
    int stage_v_338 = (sub_step_338 * 2 + pub_r000713_9) & 127;
    st_var_0.buffer[2] = (stage_v_338 & 15);
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int sub_step_339 = (sec_r000713_10 + pub_r000713_3 + 9) & 127;
    int stage_v_339 = (sub_step_339 * 2 + pub_r000713_23) & 127;
    st_var_1.buffer[0] = (stage_v_339 & 15);
    out_sink = (out_sink + stage_v_339) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
