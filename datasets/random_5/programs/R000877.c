/*
 * Benchmark Program: R000877
 * Security Family: nested_implicit_flow
 * Generator Seed: 587713
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000877_7713_0 {
    int gain;
    int offset;
    unsigned char threshold;
    int calib;
    int buffer[3];
};

struct Transaction_R000877_7713_1 {
    int account_id;
    unsigned char fee;
    short rate;
    int buffer[3];
};

union ColorPixel_R000877_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000877_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_96 = local_arr[aux % 3];
    acc = (acc + bound_96 * 2) & 127;
    int threshold_30 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_30 > 20) {
        acc = (acc + threshold_30 * 2 + 5) & 127;
        aux ^= (threshold_30 & 15);
    } else {
        acc = (acc - threshold_30 + 11) & 127;
        aux += 3;
    }
    int segment_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000877_7713_1(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int segment_14 = (aux + st.buffer[1]) & 3;
    switch (segment_14) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_23 = local_arr[aux % 3];
    acc = (acc + window_23 * 2) & 127;
    int stride_20 = (aux + st.buffer[1]) & 3;
    switch (stride_20) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_92) & 63;
    acc ^= aux;
    int damping_38 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_38 > 29) {
        acc = (acc + damping_38 * 2 + 5) & 127;
        aux ^= (damping_38 & 15);
    } else {
        acc = (acc - damping_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000877_7713_5(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_86 = (st.buffer[0] * 3 + aux) & 63;
    if (window_86 > 36) {
        acc = (acc + window_86 * 2 + 5) & 127;
        aux ^= (window_86 & 15);
    } else {
        acc = (acc - window_86 + 11) & 127;
        aux += 3;
    }
    int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_97 = local_arr[aux % 3];
    acc = (acc + weight_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_50 = (aux + st.buffer[1]) & 3;
    switch (weight_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_72 = (st.buffer[0] * 3 + aux) & 63;
    if (window_72 > 37) {
        acc = (acc + window_72 * 2 + 5) & 127;
        aux ^= (window_72 & 15);
    } else {
        acc = (acc - window_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_7(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int cursor_74 = local_arr[aux % 3];
    acc = (acc + cursor_74 * 2) & 127;
    int sample_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_42) & 63;
    acc ^= aux;
    int phase_92 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_92 > 36) {
        acc = (acc + phase_92 * 2 + 5) & 127;
        aux ^= (phase_92 & 15);
    } else {
        acc = (acc - phase_92 + 11) & 127;
        aux += 3;
    }
    int cursor_72 = (aux + st.buffer[1]) & 3;
    switch (cursor_72) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_8(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int damping_32 = local_arr[aux % 3];
    acc = (acc + damping_32 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_38 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_38 > 13) {
        acc = (acc + parity_38 * 2 + 5) & 127;
        aux ^= (parity_38 & 15);
    } else {
        acc = (acc - parity_38 + 11) & 127;
        aux += 3;
    }
    int accumulator_51 = (aux + st.buffer[1]) & 3;
    switch (accumulator_51) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int sample_71 = local_arr[aux % 3];
    acc = (acc + sample_71 * 2) & 127;
    int tracker_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000877_7713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_17) & 63;
    acc ^= aux;
    int scale_59 = (aux + st.buffer[1]) & 3;
    switch (scale_59) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_61 = local_arr[aux % 3];
    acc = (acc + stride_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_12 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_12 > 43) {
        acc = (acc + tally_12 * 2 + 5) & 127;
        aux ^= (tally_12 & 15);
    } else {
        acc = (acc - tally_12 + 11) & 127;
        aux += 3;
    }
    int anchor_15 = (aux + st.buffer[1]) & 3;
    switch (anchor_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_58 = local_arr[aux % 3];
    acc = (acc + quotient_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_12(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_13(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int anchor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_75) & 63;
    acc ^= aux;
    int margin_24 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_24 > 41) {
        acc = (acc + margin_24 * 2 + 5) & 127;
        aux ^= (margin_24 & 15);
    } else {
        acc = (acc - margin_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000877_7713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_59) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_15(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_61 = (aux + st.buffer[1]) & 3;
    switch (index_reg_61) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_64 = local_arr[aux % 3];
    acc = (acc + segment_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_16(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_56 = (aux + st.buffer[1]) & 3;
    switch (index_reg_56) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int residue_27 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_27 > 22) {
        acc = (acc + residue_27 * 2 + 5) & 127;
        aux ^= (residue_27 & 15);
    } else {
        acc = (acc - residue_27 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000877_7713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000877_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_94 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_94 > 15) {
        acc = (acc + accumulator_94 * 2 + 5) & 127;
        aux ^= (accumulator_94 & 15);
    } else {
        acc = (acc - accumulator_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_45 = local_arr[aux % 3];
    acc = (acc + checksum_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000877_7713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000877_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_77 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_77 > 18) {
        acc = (acc + coefficient_77 * 2 + 5) & 127;
        aux ^= (coefficient_77 & 15);
    } else {
        acc = (acc - coefficient_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_90 = local_arr[aux % 3];
    acc = (acc + coefficient_90 * 2) & 127;
    int parity_34 = (aux + st.buffer[1]) & 3;
    switch (parity_34) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000877_0;
    int sec_r000877_1;
    int sec_r000877_2;
    int sec_r000877_3;
    int sec_r000877_4;
    int sec_r000877_5;
    int sec_r000877_6;
    int sec_r000877_7;
    int sec_r000877_8;
    int sec_r000877_9;
    int sec_r000877_10;
    int sec_r000877_11;
    int sec_r000877_12;
    int sec_r000877_13;
    int sec_r000877_14;
    int sec_r000877_15;
    int sec_r000877_16;
    int sec_r000877_17;
    int sec_r000877_18;
    int pub_r000877_0;
    int pub_r000877_1;
    int pub_r000877_2;
    int pub_r000877_3;
    int pub_r000877_4;
    int pub_r000877_5;
    int pub_r000877_6;
    int pub_r000877_7;
    int pub_r000877_8;
    int pub_r000877_9;
    int pub_r000877_10;
    int pub_r000877_11;
    int pub_r000877_12;
    int pub_r000877_13;
    int pub_r000877_14;
    int pub_r000877_15;
    int pub_r000877_16;
    int pub_r000877_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000877_0 >= -100 && pub_r000877_0 <= 100);
    __CPROVER_assume(pub_r000877_1 >= -100 && pub_r000877_1 <= 100);
    __CPROVER_assume(pub_r000877_2 >= -100 && pub_r000877_2 <= 100);
    __CPROVER_assume(pub_r000877_3 >= -100 && pub_r000877_3 <= 100);
    __CPROVER_assume(pub_r000877_4 >= -100 && pub_r000877_4 <= 100);
    __CPROVER_assume(pub_r000877_5 >= -100 && pub_r000877_5 <= 100);
    __CPROVER_assume(pub_r000877_6 >= -100 && pub_r000877_6 <= 100);
    __CPROVER_assume(pub_r000877_7 >= -100 && pub_r000877_7 <= 100);
    __CPROVER_assume(pub_r000877_8 >= -100 && pub_r000877_8 <= 100);
    __CPROVER_assume(pub_r000877_9 >= -100 && pub_r000877_9 <= 100);
    __CPROVER_assume(pub_r000877_10 >= -100 && pub_r000877_10 <= 100);
    __CPROVER_assume(pub_r000877_11 >= -100 && pub_r000877_11 <= 100);
    __CPROVER_assume(pub_r000877_12 >= -100 && pub_r000877_12 <= 100);
    __CPROVER_assume(pub_r000877_13 >= -100 && pub_r000877_13 <= 100);
    __CPROVER_assume(pub_r000877_14 >= -100 && pub_r000877_14 <= 100);
    __CPROVER_assume(pub_r000877_15 >= -100 && pub_r000877_15 <= 100);
    __CPROVER_assume(pub_r000877_16 >= -100 && pub_r000877_16 <= 100);
    __CPROVER_assume(pub_r000877_17 >= -100 && pub_r000877_17 <= 100);
    __CPROVER_assume(sec_r000877_0 >= 0 && sec_r000877_0 <= 255);
    __CPROVER_assume(sec_r000877_1 >= 0 && sec_r000877_1 <= 255);
    __CPROVER_assume(sec_r000877_2 >= 0 && sec_r000877_2 <= 255);
    __CPROVER_assume(sec_r000877_3 >= 0 && sec_r000877_3 <= 255);
    __CPROVER_assume(sec_r000877_4 >= 0 && sec_r000877_4 <= 255);
    __CPROVER_assume(sec_r000877_5 >= 0 && sec_r000877_5 <= 255);
    __CPROVER_assume(sec_r000877_6 >= 0 && sec_r000877_6 <= 255);
    __CPROVER_assume(sec_r000877_7 >= 0 && sec_r000877_7 <= 255);
    __CPROVER_assume(sec_r000877_8 >= 0 && sec_r000877_8 <= 255);
    __CPROVER_assume(sec_r000877_9 >= 0 && sec_r000877_9 <= 255);
    __CPROVER_assume(sec_r000877_10 >= 0 && sec_r000877_10 <= 255);
    __CPROVER_assume(sec_r000877_11 >= 0 && sec_r000877_11 <= 255);
    __CPROVER_assume(sec_r000877_12 >= 0 && sec_r000877_12 <= 255);
    __CPROVER_assume(sec_r000877_13 >= 0 && sec_r000877_13 <= 255);
    __CPROVER_assume(sec_r000877_14 >= 0 && sec_r000877_14 <= 255);
    __CPROVER_assume(sec_r000877_15 >= 0 && sec_r000877_15 <= 255);
    __CPROVER_assume(sec_r000877_16 >= 0 && sec_r000877_16 <= 255);
    __CPROVER_assume(sec_r000877_17 >= 0 && sec_r000877_17 <= 255);
    __CPROVER_assume(sec_r000877_18 >= 0 && sec_r000877_18 <= 255);

    struct SensorNode_R000877_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000877_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000877_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000877_0 + 7) & 15;
    struct Transaction_R000877_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000877_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000877_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000877_0 + 9) & 15;

    union ColorPixel_R000877_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 27) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 42) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 37) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 52) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 17) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 32) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 23) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 38) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 24) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 39) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 32) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 47) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 21) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 36) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 17) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 32) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 23) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 38) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 31) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 46) {
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
    if (stage_v_58 > 25) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 40) {
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
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 24) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 39) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 14) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 29) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 28) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 43) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000877_10 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_85 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000877_2 & 2) != 0) {
            stage_v_86 = (pub_r000877_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000877_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000877_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000877_17 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_87 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000877_6 & 2) != 0) {
            stage_v_88 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_89 = (pub_r000877_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000877_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000877_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000877_17 & 2) != 0) {
            stage_v_90 = (pub_r000877_0 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000877_0 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000877_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_91 = (pub_r000877_1 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000877_1 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000877_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000877_7 & 1) != 0) {
        if ((sec_r000877_15 & 2) != 0) {
            stage_v_92 = (pub_r000877_12 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000877_12 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000877_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000877_0 & 2) != 0) {
            stage_v_93 = (pub_r000877_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000877_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000877_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000877_15 & 1) != 0) {
        if ((sec_r000877_8 & 2) != 0) {
            stage_v_94 = (pub_r000877_17 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000877_17 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000877_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000877_0 & 1) != 0) {
        if ((sec_r000877_2 & 2) != 0) {
            stage_v_95 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000877_12 & 1) != 0) {
        if ((sec_r000877_4 & 2) != 0) {
            stage_v_96 = (pub_r000877_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000877_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000877_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000877_3 & 1) != 0) {
        if ((sec_r000877_2 & 2) != 0) {
            stage_v_97 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000877_8 & 2) != 0) {
            stage_v_98 = (pub_r000877_17 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000877_17 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000877_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000877_1 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_99 = (pub_r000877_3 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000877_3 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000877_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000877_6 & 1) != 0) {
        if ((sec_r000877_14 & 2) != 0) {
            stage_v_100 = (pub_r000877_7 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000877_7 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000877_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000877_13 & 2) != 0) {
            stage_v_101 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000877_11 & 2) != 0) {
            stage_v_102 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000877_9 & 2) != 0) {
            stage_v_103 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000877_12 & 1) != 0) {
        if ((sec_r000877_14 & 2) != 0) {
            stage_v_104 = (pub_r000877_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000877_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000877_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000877_17 & 1) != 0) {
        if ((sec_r000877_5 & 2) != 0) {
            stage_v_105 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000877_15 & 2) != 0) {
            stage_v_106 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000877_1 & 2) != 0) {
            stage_v_107 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000877_7 & 1) != 0) {
        if ((sec_r000877_9 & 2) != 0) {
            stage_v_108 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000877_17 & 2) != 0) {
            stage_v_109 = (pub_r000877_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000877_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000877_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000877_18 & 2) != 0) {
            stage_v_110 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000877_12 & 1) != 0) {
        if ((sec_r000877_6 & 2) != 0) {
            stage_v_111 = (pub_r000877_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000877_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000877_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000877_2 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_112 = (pub_r000877_12 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000877_12 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000877_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000877_15 & 2) != 0) {
            stage_v_113 = (pub_r000877_12 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000877_12 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000877_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_114 = (pub_r000877_15 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000877_15 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000877_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000877_9 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_115 = (pub_r000877_16 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000877_16 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000877_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000877_10 & 2) != 0) {
            stage_v_116 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_117 = (pub_r000877_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000877_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000877_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000877_2 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_118 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000877_0 & 1) != 0) {
        if ((sec_r000877_2 & 2) != 0) {
            stage_v_119 = (pub_r000877_11 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000877_11 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000877_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000877_3 & 2) != 0) {
            stage_v_120 = (pub_r000877_4 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000877_4 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000877_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000877_10 & 2) != 0) {
            stage_v_121 = (pub_r000877_0 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000877_0 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000877_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000877_11 & 2) != 0) {
            stage_v_122 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000877_7 & 1) != 0) {
        if ((sec_r000877_5 & 2) != 0) {
            stage_v_123 = (pub_r000877_0 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000877_0 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000877_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000877_17 & 2) != 0) {
            stage_v_124 = (pub_r000877_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000877_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000877_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000877_11 & 2) != 0) {
            stage_v_125 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000877_15 & 2) != 0) {
            stage_v_126 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000877_11 & 2) != 0) {
            stage_v_127 = (pub_r000877_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000877_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000877_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000877_13 & 2) != 0) {
            stage_v_128 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000877_8 & 1) != 0) {
        if ((sec_r000877_9 & 2) != 0) {
            stage_v_129 = (pub_r000877_1 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000877_1 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000877_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_130 = (pub_r000877_7 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000877_7 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000877_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_131 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000877_3 & 2) != 0) {
            stage_v_132 = (pub_r000877_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000877_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000877_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000877_11 & 2) != 0) {
            stage_v_133 = (pub_r000877_16 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000877_16 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000877_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000877_8 & 2) != 0) {
            stage_v_134 = (pub_r000877_2 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000877_2 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000877_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000877_3 & 2) != 0) {
            stage_v_135 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000877_17 & 2) != 0) {
            stage_v_136 = (pub_r000877_1 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000877_1 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000877_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000877_0 & 2) != 0) {
            stage_v_137 = (pub_r000877_3 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000877_3 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000877_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000877_8 & 1) != 0) {
        if ((sec_r000877_1 & 2) != 0) {
            stage_v_138 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_139 = (pub_r000877_9 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000877_9 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000877_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000877_9 & 2) != 0) {
            stage_v_140 = (pub_r000877_11 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000877_11 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000877_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000877_15 & 2) != 0) {
            stage_v_141 = (pub_r000877_7 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000877_7 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000877_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000877_3 & 2) != 0) {
            stage_v_142 = (pub_r000877_16 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000877_16 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000877_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000877_1 & 2) != 0) {
            stage_v_143 = (pub_r000877_15 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000877_15 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000877_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000877_10 & 1) != 0) {
        if ((sec_r000877_6 & 2) != 0) {
            stage_v_144 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000877_16 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_145 = (pub_r000877_9 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000877_9 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000877_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000877_4 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_146 = (pub_r000877_1 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000877_1 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000877_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000877_4 & 2) != 0) {
            stage_v_147 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000877_10 & 2) != 0) {
            stage_v_148 = (pub_r000877_5 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000877_5 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000877_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_149 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_150 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000877_0 & 2) != 0) {
            stage_v_151 = (pub_r000877_0 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000877_0 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000877_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000877_2 & 1) != 0) {
        if ((sec_r000877_12 & 2) != 0) {
            stage_v_152 = (pub_r000877_7 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000877_7 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000877_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000877_17 & 2) != 0) {
            stage_v_153 = (pub_r000877_1 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000877_1 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000877_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000877_12 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_154 = (pub_r000877_16 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000877_16 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000877_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000877_5 & 2) != 0) {
            stage_v_155 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000877_3 & 2) != 0) {
            stage_v_156 = (pub_r000877_6 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000877_6 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000877_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_157 = (pub_r000877_9 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000877_9 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000877_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000877_7 & 1) != 0) {
        if ((sec_r000877_7 & 2) != 0) {
            stage_v_158 = (pub_r000877_10 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000877_10 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000877_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000877_0 & 1) != 0) {
        if ((sec_r000877_13 & 2) != 0) {
            stage_v_159 = (pub_r000877_9 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000877_9 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000877_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000877_15 & 1) != 0) {
        if ((sec_r000877_0 & 2) != 0) {
            stage_v_160 = (pub_r000877_11 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000877_11 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000877_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000877_1 & 2) != 0) {
            stage_v_161 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000877_0 & 2) != 0) {
            stage_v_162 = (pub_r000877_8 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000877_8 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000877_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000877_4 & 1) != 0) {
        if ((sec_r000877_5 & 2) != 0) {
            stage_v_163 = (pub_r000877_0 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000877_0 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000877_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r000877_10 & 2) != 0) {
            stage_v_164 = (pub_r000877_13 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000877_13 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000877_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000877_10 & 1) != 0) {
        if ((sec_r000877_16 & 2) != 0) {
            stage_v_165 = (pub_r000877_14 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000877_14 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000877_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
