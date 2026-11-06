/*
 * Benchmark Program: R000597
 * Security Family: nested_implicit_flow
 * Generator Seed: 559713
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000597_9713_0 {
    int prev_in;
    int gain_db;
    unsigned char prev_out;
    short mode;
    int buffer[3];
};

struct StreamBuffer_R000597_9713_1 {
    int watermark;
    short state;
    short head;
    unsigned char checksum;
    unsigned char tail;
    int capacity;
    int buffer[3];
};

struct SensorNode_R000597_9713_2 {
    int gain;
    int status;
    unsigned char threshold;
    int buffer[3];
};

union ColorPixel_R000597_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000597_9713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int delta_47 = local_arr[aux % 3];
    acc = (acc + delta_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_85 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_85 > 39) {
        acc = (acc + cursor_85 * 2 + 5) & 127;
        aux ^= (cursor_85 & 15);
    } else {
        acc = (acc - cursor_85 + 11) & 127;
        aux += 3;
    }
    int vector_29 = (aux + st.buffer[1]) & 3;
    switch (vector_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int factor_93 = local_arr[aux % 3];
    acc = (acc + factor_93 * 2) & 127;
    int accumulator_81 = (aux + st.buffer[1]) & 3;
    switch (accumulator_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_2(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int window_24 = local_arr[aux % 3];
    acc = (acc + window_24 * 2) & 127;
    int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_17) & 63;
    acc ^= aux;
    int damping_18 = (aux + st.buffer[1]) & 3;
    switch (damping_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int accumulator_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_37) & 63;
    acc ^= aux;
    int tally_51 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_51 > 45) {
        acc = (acc + tally_51 * 2 + 5) & 127;
        aux ^= (tally_51 & 15);
    } else {
        acc = (acc - tally_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_79 = local_arr[aux % 3];
    acc = (acc + accumulator_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_4(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_72 = (aux + st.buffer[1]) & 3;
    switch (parity_72) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_72 = local_arr[aux % 3];
    acc = (acc + pivot_72 * 2) & 127;
    int mask_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000597_9713_5(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_69 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_69 > 41) {
        acc = (acc + bound_69 * 2 + 5) & 127;
        aux ^= (bound_69 & 15);
    } else {
        acc = (acc - bound_69 + 11) & 127;
        aux += 3;
    }
    int index_reg_57 = (aux + st.buffer[1]) & 3;
    switch (index_reg_57) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000597_9713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_24 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_24 > 32) {
        acc = (acc + quantum_24 * 2 + 5) & 127;
        aux ^= (quantum_24 & 15);
    } else {
        acc = (acc - quantum_24 + 11) & 127;
        aux += 3;
    }
    int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_48) & 63;
    acc ^= aux;
    int parity_17 = (aux + st.buffer[1]) & 3;
    switch (parity_17) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_7(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_57 = local_arr[aux % 3];
    acc = (acc + damping_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int threshold_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_75 = local_arr[aux % 3];
    acc = (acc + bound_75 * 2) & 127;
    int segment_38 = (aux + st.buffer[1]) & 3;
    switch (segment_38) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int delta_56 = local_arr[aux % 3];
    acc = (acc + delta_56 * 2) & 127;
    int mask_49 = (aux + st.buffer[1]) & 3;
    switch (mask_49) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_87 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_87 > 32) {
        acc = (acc + anchor_87 * 2 + 5) & 127;
        aux ^= (anchor_87 & 15);
    } else {
        acc = (acc - anchor_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_79 = (aux + st.buffer[1]) & 3;
    switch (anchor_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_85 = local_arr[aux % 3];
    acc = (acc + accumulator_85 * 2) & 127;
    int coefficient_87 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_87 > 41) {
        acc = (acc + coefficient_87 * 2 + 5) & 127;
        aux ^= (coefficient_87 & 15);
    } else {
        acc = (acc - coefficient_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int metric_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_86) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_55 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_55 > 22) {
        acc = (acc + bound_55 * 2 + 5) & 127;
        aux ^= (bound_55 & 15);
    } else {
        acc = (acc - bound_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_71 = local_arr[aux % 3];
    acc = (acc + index_reg_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_12(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int checksum_63 = local_arr[aux % 3];
    acc = (acc + checksum_63 * 2) & 127;
    int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000597_9713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int weight_22 = local_arr[aux % 3];
    acc = (acc + weight_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_14(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_56 > 44) {
        acc = (acc + cursor_56 * 2 + 5) & 127;
        aux ^= (cursor_56 & 15);
    } else {
        acc = (acc - cursor_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_15(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_83 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_83 > 28) {
        acc = (acc + cursor_83 * 2 + 5) & 127;
        aux ^= (cursor_83 & 15);
    } else {
        acc = (acc - cursor_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000597_9713_16(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_42) & 63;
    acc ^= aux;
    int accumulator_11 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_11 > 15) {
        acc = (acc + accumulator_11 * 2 + 5) & 127;
        aux ^= (accumulator_11 & 15);
    } else {
        acc = (acc - accumulator_11 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_11 = local_arr[aux % 3];
    acc = (acc + tally_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000597_9713_17(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_15 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_15 > 38) {
        acc = (acc + tally_15 * 2 + 5) & 127;
        aux ^= (tally_15 & 15);
    } else {
        acc = (acc - tally_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000597_0;
    int sec_r000597_1;
    int sec_r000597_2;
    int sec_r000597_3;
    int sec_r000597_4;
    int sec_r000597_5;
    int sec_r000597_6;
    int sec_r000597_7;
    int sec_r000597_8;
    int sec_r000597_9;
    int sec_r000597_10;
    int sec_r000597_11;
    int sec_r000597_12;
    int sec_r000597_13;
    int sec_r000597_14;
    int sec_r000597_15;
    int sec_r000597_16;
    int sec_r000597_17;
    int pub_r000597_0;
    int pub_r000597_1;
    int pub_r000597_2;
    int pub_r000597_3;
    int pub_r000597_4;
    int pub_r000597_5;
    int pub_r000597_6;
    int pub_r000597_7;
    int pub_r000597_8;
    int pub_r000597_9;
    int pub_r000597_10;
    int pub_r000597_11;
    int pub_r000597_12;
    int pub_r000597_13;
    int pub_r000597_14;
    int pub_r000597_15;
    int pub_r000597_16;
    int pub_r000597_17;
    int pub_r000597_18;
    int pub_r000597_19;
    int pub_r000597_20;
    int pub_r000597_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000597_0 >= -100 && pub_r000597_0 <= 100);
    __CPROVER_assume(pub_r000597_1 >= -100 && pub_r000597_1 <= 100);
    __CPROVER_assume(pub_r000597_2 >= -100 && pub_r000597_2 <= 100);
    __CPROVER_assume(pub_r000597_3 >= -100 && pub_r000597_3 <= 100);
    __CPROVER_assume(pub_r000597_4 >= -100 && pub_r000597_4 <= 100);
    __CPROVER_assume(pub_r000597_5 >= -100 && pub_r000597_5 <= 100);
    __CPROVER_assume(pub_r000597_6 >= -100 && pub_r000597_6 <= 100);
    __CPROVER_assume(pub_r000597_7 >= -100 && pub_r000597_7 <= 100);
    __CPROVER_assume(pub_r000597_8 >= -100 && pub_r000597_8 <= 100);
    __CPROVER_assume(pub_r000597_9 >= -100 && pub_r000597_9 <= 100);
    __CPROVER_assume(pub_r000597_10 >= -100 && pub_r000597_10 <= 100);
    __CPROVER_assume(pub_r000597_11 >= -100 && pub_r000597_11 <= 100);
    __CPROVER_assume(pub_r000597_12 >= -100 && pub_r000597_12 <= 100);
    __CPROVER_assume(pub_r000597_13 >= -100 && pub_r000597_13 <= 100);
    __CPROVER_assume(pub_r000597_14 >= -100 && pub_r000597_14 <= 100);
    __CPROVER_assume(pub_r000597_15 >= -100 && pub_r000597_15 <= 100);
    __CPROVER_assume(pub_r000597_16 >= -100 && pub_r000597_16 <= 100);
    __CPROVER_assume(pub_r000597_17 >= -100 && pub_r000597_17 <= 100);
    __CPROVER_assume(pub_r000597_18 >= -100 && pub_r000597_18 <= 100);
    __CPROVER_assume(pub_r000597_19 >= -100 && pub_r000597_19 <= 100);
    __CPROVER_assume(pub_r000597_20 >= -100 && pub_r000597_20 <= 100);
    __CPROVER_assume(pub_r000597_21 >= -100 && pub_r000597_21 <= 100);
    __CPROVER_assume(sec_r000597_0 >= 0 && sec_r000597_0 <= 255);
    __CPROVER_assume(sec_r000597_1 >= 0 && sec_r000597_1 <= 255);
    __CPROVER_assume(sec_r000597_2 >= 0 && sec_r000597_2 <= 255);
    __CPROVER_assume(sec_r000597_3 >= 0 && sec_r000597_3 <= 255);
    __CPROVER_assume(sec_r000597_4 >= 0 && sec_r000597_4 <= 255);
    __CPROVER_assume(sec_r000597_5 >= 0 && sec_r000597_5 <= 255);
    __CPROVER_assume(sec_r000597_6 >= 0 && sec_r000597_6 <= 255);
    __CPROVER_assume(sec_r000597_7 >= 0 && sec_r000597_7 <= 255);
    __CPROVER_assume(sec_r000597_8 >= 0 && sec_r000597_8 <= 255);
    __CPROVER_assume(sec_r000597_9 >= 0 && sec_r000597_9 <= 255);
    __CPROVER_assume(sec_r000597_10 >= 0 && sec_r000597_10 <= 255);
    __CPROVER_assume(sec_r000597_11 >= 0 && sec_r000597_11 <= 255);
    __CPROVER_assume(sec_r000597_12 >= 0 && sec_r000597_12 <= 255);
    __CPROVER_assume(sec_r000597_13 >= 0 && sec_r000597_13 <= 255);
    __CPROVER_assume(sec_r000597_14 >= 0 && sec_r000597_14 <= 255);
    __CPROVER_assume(sec_r000597_15 >= 0 && sec_r000597_15 <= 255);
    __CPROVER_assume(sec_r000597_16 >= 0 && sec_r000597_16 <= 255);
    __CPROVER_assume(sec_r000597_17 >= 0 && sec_r000597_17 <= 255);

    struct FilterState_R000597_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000597_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000597_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000597_0 + 7) & 15;
    struct StreamBuffer_R000597_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000597_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000597_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000597_0 + 9) & 15;
    struct SensorNode_R000597_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000597_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000597_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000597_0 + 11) & 15;

    union ColorPixel_R000597_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 26) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 41) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 13) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 28) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

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
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 21) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 36) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 40) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 55) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 28) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 43) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 19) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 34) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 39) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 54) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 13) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 28) {
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
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 35) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 50) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 34) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 49) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 39) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 54) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 37) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 52) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 19) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 34) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 11) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 26) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 40) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 55) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
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
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 22) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 37) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 33) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 48) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000597_4 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_77 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000597_16 & 2) != 0) {
            stage_v_78 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_79 = (pub_r000597_14 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000597_14 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000597_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000597_0 & 1) != 0) {
        if ((sec_r000597_0 & 2) != 0) {
            stage_v_80 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_1 & 2) != 0) {
            stage_v_81 = (pub_r000597_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000597_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000597_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000597_17 & 1) != 0) {
        if ((sec_r000597_9 & 2) != 0) {
            stage_v_82 = (pub_r000597_10 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000597_10 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000597_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_83 = (pub_r000597_1 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000597_1 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000597_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000597_7 & 2) != 0) {
            stage_v_84 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000597_13 & 2) != 0) {
            stage_v_85 = (pub_r000597_7 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000597_7 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000597_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_11 & 2) != 0) {
            stage_v_86 = (pub_r000597_16 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000597_16 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000597_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_87 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_12 & 2) != 0) {
            stage_v_88 = (pub_r000597_6 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000597_6 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000597_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000597_8 & 2) != 0) {
            stage_v_89 = (pub_r000597_11 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000597_11 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000597_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_90 = (pub_r000597_9 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000597_9 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000597_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_9 & 2) != 0) {
            stage_v_91 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_92 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000597_9 & 1) != 0) {
        if ((sec_r000597_15 & 2) != 0) {
            stage_v_93 = (pub_r000597_15 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000597_15 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000597_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_94 = (pub_r000597_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000597_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000597_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_95 = (pub_r000597_7 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000597_7 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000597_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000597_8 & 1) != 0) {
        if ((sec_r000597_11 & 2) != 0) {
            stage_v_96 = (pub_r000597_21 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000597_21 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000597_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000597_7 & 2) != 0) {
            stage_v_97 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000597_1 & 2) != 0) {
            stage_v_98 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_14 & 2) != 0) {
            stage_v_99 = (pub_r000597_10 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000597_10 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000597_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000597_12 & 1) != 0) {
        if ((sec_r000597_0 & 2) != 0) {
            stage_v_100 = (pub_r000597_4 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000597_4 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000597_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000597_11 & 1) != 0) {
        if ((sec_r000597_10 & 2) != 0) {
            stage_v_101 = (pub_r000597_12 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000597_12 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000597_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_102 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_103 = (pub_r000597_20 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000597_20 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000597_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_104 = (pub_r000597_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000597_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000597_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000597_3 & 1) != 0) {
        if ((sec_r000597_9 & 2) != 0) {
            stage_v_105 = (pub_r000597_14 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000597_14 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000597_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000597_12 & 2) != 0) {
            stage_v_106 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000597_13 & 2) != 0) {
            stage_v_107 = (pub_r000597_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000597_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000597_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000597_16 & 2) != 0) {
            stage_v_108 = (pub_r000597_15 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000597_15 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000597_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000597_0 & 2) != 0) {
            stage_v_109 = (pub_r000597_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000597_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000597_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000597_14 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_110 = (pub_r000597_10 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000597_10 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000597_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_111 = (pub_r000597_8 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000597_8 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000597_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000597_5 & 2) != 0) {
            stage_v_112 = (pub_r000597_0 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000597_0 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000597_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000597_17 & 1) != 0) {
        if ((sec_r000597_5 & 2) != 0) {
            stage_v_113 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000597_17 & 1) != 0) {
        if ((sec_r000597_0 & 2) != 0) {
            stage_v_114 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_115 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000597_4 & 1) != 0) {
        if ((sec_r000597_8 & 2) != 0) {
            stage_v_116 = (pub_r000597_4 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000597_4 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000597_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_117 = (pub_r000597_1 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000597_1 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000597_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000597_10 & 2) != 0) {
            stage_v_118 = (pub_r000597_19 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000597_19 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000597_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000597_6 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_119 = (pub_r000597_20 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000597_20 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000597_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_120 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000597_14 & 2) != 0) {
            stage_v_121 = (pub_r000597_0 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000597_0 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000597_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000597_3 & 1) != 0) {
        if ((sec_r000597_13 & 2) != 0) {
            stage_v_122 = (pub_r000597_0 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000597_0 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000597_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000597_10 & 1) != 0) {
        if ((sec_r000597_15 & 2) != 0) {
            stage_v_123 = (pub_r000597_17 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000597_17 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000597_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000597_4 & 1) != 0) {
        if ((sec_r000597_16 & 2) != 0) {
            stage_v_124 = (pub_r000597_18 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000597_18 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000597_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000597_8 & 2) != 0) {
            stage_v_125 = (pub_r000597_17 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000597_17 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000597_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000597_5 & 2) != 0) {
            stage_v_126 = (pub_r000597_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000597_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000597_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_127 = (pub_r000597_12 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000597_12 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000597_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000597_16 & 2) != 0) {
            stage_v_128 = (pub_r000597_20 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000597_20 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000597_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_129 = (pub_r000597_17 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000597_17 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000597_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000597_14 & 2) != 0) {
            stage_v_130 = (pub_r000597_9 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000597_9 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000597_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_131 = (pub_r000597_16 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000597_16 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000597_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000597_16 & 2) != 0) {
            stage_v_132 = (pub_r000597_7 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000597_7 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000597_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000597_11 & 2) != 0) {
            stage_v_133 = (pub_r000597_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000597_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000597_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000597_0 & 1) != 0) {
        if ((sec_r000597_13 & 2) != 0) {
            stage_v_134 = (pub_r000597_13 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000597_13 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000597_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000597_7 & 2) != 0) {
            stage_v_135 = (pub_r000597_1 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000597_1 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000597_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000597_7 & 2) != 0) {
            stage_v_136 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000597_15 & 1) != 0) {
        if ((sec_r000597_0 & 2) != 0) {
            stage_v_137 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000597_8 & 2) != 0) {
            stage_v_138 = (pub_r000597_21 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000597_21 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000597_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000597_0 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_139 = (pub_r000597_6 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000597_6 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000597_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000597_8 & 2) != 0) {
            stage_v_140 = (pub_r000597_13 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000597_13 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000597_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000597_7 & 1) != 0) {
        if ((sec_r000597_14 & 2) != 0) {
            stage_v_141 = (pub_r000597_16 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000597_16 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000597_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000597_0 & 1) != 0) {
        if ((sec_r000597_13 & 2) != 0) {
            stage_v_142 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_143 = (pub_r000597_9 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000597_9 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000597_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000597_9 & 1) != 0) {
        if ((sec_r000597_5 & 2) != 0) {
            stage_v_144 = (pub_r000597_13 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000597_13 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000597_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_145 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000597_17 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_146 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000597_8 & 1) != 0) {
        if ((sec_r000597_4 & 2) != 0) {
            stage_v_147 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000597_1 & 1) != 0) {
        if ((sec_r000597_17 & 2) != 0) {
            stage_v_148 = (pub_r000597_2 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000597_2 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000597_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_149 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000597_11 & 1) != 0) {
        if ((sec_r000597_10 & 2) != 0) {
            stage_v_150 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000597_9 & 2) != 0) {
            stage_v_151 = (pub_r000597_1 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000597_1 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000597_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_152 = (pub_r000597_8 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000597_8 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000597_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000597_2 & 2) != 0) {
            stage_v_153 = (pub_r000597_15 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000597_15 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000597_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r000597_14 & 2) != 0) {
            stage_v_154 = (pub_r000597_3 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000597_3 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000597_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000597_1 & 2) != 0) {
            stage_v_155 = (pub_r000597_17 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000597_17 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000597_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000597_6 & 1) != 0) {
        if ((sec_r000597_15 & 2) != 0) {
            stage_v_156 = (pub_r000597_15 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000597_15 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000597_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000597_6 & 1) != 0) {
        if ((sec_r000597_6 & 2) != 0) {
            stage_v_157 = (pub_r000597_7 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000597_7 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000597_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000597_3 & 2) != 0) {
            stage_v_158 = (pub_r000597_5 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000597_5 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000597_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
