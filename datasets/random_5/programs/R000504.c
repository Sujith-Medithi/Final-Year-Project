/*
 * Benchmark Program: R000504
 * Security Family: arithmetic_flow
 * Generator Seed: 550413
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000504_413_0 {
    unsigned char threshold;
    unsigned char offset;
    int reading;
    int gain;
    short status;
    int calib;
    int buffer[3];
};

struct StreamBuffer_R000504_413_1 {
    unsigned char checksum;
    int capacity;
    int state;
    int buffer[3];
};

union PacketPayload_R000504_413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000504_413_0(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_72 = (aux + st.buffer[1]) & 3;
    switch (quotient_72) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_24 = local_arr[aux % 3];
    acc = (acc + coefficient_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000504_413_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_57 = (aux + st.buffer[1]) & 3;
    switch (quotient_57) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_83 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_83 > 47) {
        acc = (acc + pivot_83 * 2 + 5) & 127;
        aux ^= (pivot_83 & 15);
    } else {
        acc = (acc - pivot_83 + 11) & 127;
        aux += 3;
    }
    int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000504_413_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_41 > 40) {
        acc = (acc + factor_41 * 2 + 5) & 127;
        aux ^= (factor_41 & 15);
    } else {
        acc = (acc - factor_41 + 11) & 127;
        aux += 3;
    }
    int tracker_29 = (aux + st.buffer[1]) & 3;
    switch (tracker_29) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000504_413_3(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int segment_71 = local_arr[aux % 3];
    acc = (acc + segment_71 * 2) & 127;
    int tracker_49 = (aux + st.buffer[1]) & 3;
    switch (tracker_49) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_4(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int damping_29 = local_arr[aux % 3];
    acc = (acc + damping_29 * 2) & 127;
    int accumulator_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_21) & 63;
    acc ^= aux;
    int quotient_91 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_91 > 50) {
        acc = (acc + quotient_91 * 2 + 5) & 127;
        aux ^= (quotient_91 & 15);
    } else {
        acc = (acc - quotient_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_5(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_99 = (aux + st.buffer[1]) & 3;
    switch (delta_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_38 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_38 > 28) {
        acc = (acc + weight_38 * 2 + 5) & 127;
        aux ^= (weight_38 & 15);
    } else {
        acc = (acc - weight_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_45 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_45 > 39) {
        acc = (acc + tally_45 * 2 + 5) & 127;
        aux ^= (tally_45 & 15);
    } else {
        acc = (acc - tally_45 + 11) & 127;
        aux += 3;
    }
    int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_43) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_78 = local_arr[aux % 3];
    acc = (acc + quotient_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000504_413_7(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_95 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_95 > 21) {
        acc = (acc + phase_95 * 2 + 5) & 127;
        aux ^= (phase_95 & 15);
    } else {
        acc = (acc - phase_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_8(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int parity_47 = local_arr[aux % 3];
    acc = (acc + parity_47 * 2) & 127;
    int threshold_80 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_80 > 30) {
        acc = (acc + threshold_80 * 2 + 5) & 127;
        aux ^= (threshold_80 & 15);
    } else {
        acc = (acc - threshold_80 + 11) & 127;
        aux += 3;
    }
    int coefficient_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000504_413_9(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_57 = (aux + st.buffer[1]) & 3;
    switch (coefficient_57) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_86) & 63;
    acc ^= aux;
    int cursor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_59 > 12) {
        acc = (acc + cursor_59 * 2 + 5) & 127;
        aux ^= (cursor_59 & 15);
    } else {
        acc = (acc - cursor_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_10(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int delta_61 = local_arr[aux % 3];
    acc = (acc + delta_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000504_413_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_13 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_13 > 42) {
        acc = (acc + offset_13 * 2 + 5) & 127;
        aux ^= (offset_13 & 15);
    } else {
        acc = (acc - offset_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_22 = local_arr[aux % 3];
    acc = (acc + coefficient_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000504_413_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_68 = (aux + st.buffer[1]) & 3;
    switch (checksum_68) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_36 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_36 > 32) {
        acc = (acc + quotient_36 * 2 + 5) & 127;
        aux ^= (quotient_36 & 15);
    } else {
        acc = (acc - quotient_36 + 11) & 127;
        aux += 3;
    }
    int tracker_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000504_413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_81 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_81 > 26) {
        acc = (acc + scale_81 * 2 + 5) & 127;
        aux ^= (scale_81 & 15);
    } else {
        acc = (acc - scale_81 + 11) & 127;
        aux += 3;
    }
    int coefficient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000504_413_14(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000504_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_18 = (aux + st.buffer[1]) & 3;
    switch (stride_18) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_64 = local_arr[aux % 3];
    acc = (acc + damping_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_99 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_99 > 45) {
        acc = (acc + scale_99 * 2 + 5) & 127;
        aux ^= (scale_99 & 15);
    } else {
        acc = (acc - scale_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000504_413_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000504_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_38 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_38 > 21) {
        acc = (acc + stride_38 * 2 + 5) & 127;
        aux ^= (stride_38 & 15);
    } else {
        acc = (acc - stride_38 + 11) & 127;
        aux += 3;
    }
    int residue_59 = (aux + st.buffer[1]) & 3;
    switch (residue_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_65 = local_arr[aux % 3];
    acc = (acc + residue_65 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000504_0;
    int sec_r000504_1;
    int sec_r000504_2;
    int sec_r000504_3;
    int sec_r000504_4;
    int sec_r000504_5;
    int sec_r000504_6;
    int sec_r000504_7;
    int sec_r000504_8;
    int sec_r000504_9;
    int sec_r000504_10;
    int sec_r000504_11;
    int sec_r000504_12;
    int sec_r000504_13;
    int sec_r000504_14;
    int sec_r000504_15;
    int sec_r000504_16;
    int sec_r000504_17;
    int sec_r000504_18;
    int sec_r000504_19;
    int sec_r000504_20;
    int sec_r000504_21;
    int sec_r000504_22;
    int pub_r000504_0;
    int pub_r000504_1;
    int pub_r000504_2;
    int pub_r000504_3;
    int pub_r000504_4;
    int pub_r000504_5;
    int pub_r000504_6;
    int pub_r000504_7;
    int pub_r000504_8;
    int pub_r000504_9;
    int pub_r000504_10;
    int pub_r000504_11;
    int pub_r000504_12;
    int pub_r000504_13;
    int pub_r000504_14;
    int pub_r000504_15;
    int pub_r000504_16;
    int pub_r000504_17;
    int pub_r000504_18;
    int pub_r000504_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000504_0 >= -100 && pub_r000504_0 <= 100);
    __CPROVER_assume(pub_r000504_1 >= -100 && pub_r000504_1 <= 100);
    __CPROVER_assume(pub_r000504_2 >= -100 && pub_r000504_2 <= 100);
    __CPROVER_assume(pub_r000504_3 >= -100 && pub_r000504_3 <= 100);
    __CPROVER_assume(pub_r000504_4 >= -100 && pub_r000504_4 <= 100);
    __CPROVER_assume(pub_r000504_5 >= -100 && pub_r000504_5 <= 100);
    __CPROVER_assume(pub_r000504_6 >= -100 && pub_r000504_6 <= 100);
    __CPROVER_assume(pub_r000504_7 >= -100 && pub_r000504_7 <= 100);
    __CPROVER_assume(pub_r000504_8 >= -100 && pub_r000504_8 <= 100);
    __CPROVER_assume(pub_r000504_9 >= -100 && pub_r000504_9 <= 100);
    __CPROVER_assume(pub_r000504_10 >= -100 && pub_r000504_10 <= 100);
    __CPROVER_assume(pub_r000504_11 >= -100 && pub_r000504_11 <= 100);
    __CPROVER_assume(pub_r000504_12 >= -100 && pub_r000504_12 <= 100);
    __CPROVER_assume(pub_r000504_13 >= -100 && pub_r000504_13 <= 100);
    __CPROVER_assume(pub_r000504_14 >= -100 && pub_r000504_14 <= 100);
    __CPROVER_assume(pub_r000504_15 >= -100 && pub_r000504_15 <= 100);
    __CPROVER_assume(pub_r000504_16 >= -100 && pub_r000504_16 <= 100);
    __CPROVER_assume(pub_r000504_17 >= -100 && pub_r000504_17 <= 100);
    __CPROVER_assume(pub_r000504_18 >= -100 && pub_r000504_18 <= 100);
    __CPROVER_assume(pub_r000504_19 >= -100 && pub_r000504_19 <= 100);
    __CPROVER_assume(sec_r000504_0 >= 0 && sec_r000504_0 <= 255);
    __CPROVER_assume(sec_r000504_1 >= 0 && sec_r000504_1 <= 255);
    __CPROVER_assume(sec_r000504_2 >= 0 && sec_r000504_2 <= 255);
    __CPROVER_assume(sec_r000504_3 >= 0 && sec_r000504_3 <= 255);
    __CPROVER_assume(sec_r000504_4 >= 0 && sec_r000504_4 <= 255);
    __CPROVER_assume(sec_r000504_5 >= 0 && sec_r000504_5 <= 255);
    __CPROVER_assume(sec_r000504_6 >= 0 && sec_r000504_6 <= 255);
    __CPROVER_assume(sec_r000504_7 >= 0 && sec_r000504_7 <= 255);
    __CPROVER_assume(sec_r000504_8 >= 0 && sec_r000504_8 <= 255);
    __CPROVER_assume(sec_r000504_9 >= 0 && sec_r000504_9 <= 255);
    __CPROVER_assume(sec_r000504_10 >= 0 && sec_r000504_10 <= 255);
    __CPROVER_assume(sec_r000504_11 >= 0 && sec_r000504_11 <= 255);
    __CPROVER_assume(sec_r000504_12 >= 0 && sec_r000504_12 <= 255);
    __CPROVER_assume(sec_r000504_13 >= 0 && sec_r000504_13 <= 255);
    __CPROVER_assume(sec_r000504_14 >= 0 && sec_r000504_14 <= 255);
    __CPROVER_assume(sec_r000504_15 >= 0 && sec_r000504_15 <= 255);
    __CPROVER_assume(sec_r000504_16 >= 0 && sec_r000504_16 <= 255);
    __CPROVER_assume(sec_r000504_17 >= 0 && sec_r000504_17 <= 255);
    __CPROVER_assume(sec_r000504_18 >= 0 && sec_r000504_18 <= 255);
    __CPROVER_assume(sec_r000504_19 >= 0 && sec_r000504_19 <= 255);
    __CPROVER_assume(sec_r000504_20 >= 0 && sec_r000504_20 <= 255);
    __CPROVER_assume(sec_r000504_21 >= 0 && sec_r000504_21 <= 255);
    __CPROVER_assume(sec_r000504_22 >= 0 && sec_r000504_22 <= 255);

    struct SensorNode_R000504_413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000504_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000504_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000504_0 + 7) & 15;
    struct StreamBuffer_R000504_413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000504_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000504_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000504_0 + 9) & 15;

    union PacketPayload_R000504_413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 12) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 27) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 12) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 27) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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
    int stage_v_31 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_31 * 3) + (sec_r000504_6 * 2) - pub_r000504_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_31 * 3) + (sec_r000504_22 * 2) - pub_r000504_0 + 27) & 127;
    sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_31 * 3) + (sec_r000504_3 * 2) - pub_r000504_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_33 * 3) + (sec_r000504_8 * 2) - pub_r000504_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_34 * 3) + (sec_r000504_11 * 2) - pub_r000504_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r000504_20 * 3) + (sec_r000504_20 * 2) - pub_r000504_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_36 * 3) + (sec_r000504_18 * 2) - pub_r000504_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_35 * 3) + (sec_r000504_22 * 2) - pub_r000504_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_33 * 3) + (sec_r000504_18 * 2) - pub_r000504_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r000504_9 * 3) + (sec_r000504_9 * 2) - pub_r000504_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_40 * 3) + (sec_r000504_9 * 2) - pub_r000504_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_42 * 3) + (sec_r000504_17 * 2) - pub_r000504_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_38 * 3) + (sec_r000504_1 * 2) - pub_r000504_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_39 * 3) + (sec_r000504_14 * 2) - pub_r000504_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_33 * 3) + (sec_r000504_12 * 2) - pub_r000504_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_42 * 3) + (sec_r000504_8 * 2) - pub_r000504_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000504_13 * 3) + (sec_r000504_13 * 2) - pub_r000504_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r000504_17 * 3) + (sec_r000504_17 * 2) - pub_r000504_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_43 * 3) + (sec_r000504_22 * 2) - pub_r000504_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_50 * 3) + (sec_r000504_5 * 2) - pub_r000504_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000504_12 * 3) + (sec_r000504_12 * 2) - pub_r000504_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_45 * 3) + (sec_r000504_7 * 2) - pub_r000504_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_50 * 3) + (sec_r000504_9 * 2) - pub_r000504_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_44 * 3) + (sec_r000504_1 * 2) - pub_r000504_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_59 * 3) + (sec_r000504_21 * 2) - pub_r000504_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_52 * 3) + (sec_r000504_19 * 2) - pub_r000504_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_34 * 3) + (sec_r000504_0 * 2) - pub_r000504_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r000504_2 * 3) + (sec_r000504_2 * 2) - pub_r000504_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000504_15 * 3) + (sec_r000504_15 * 2) - pub_r000504_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_48 * 3) + (sec_r000504_12 * 2) - pub_r000504_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_61 * 3) + (sec_r000504_16 * 2) - pub_r000504_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_52 * 3) + (sec_r000504_17 * 2) - pub_r000504_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_35 * 3) + (sec_r000504_13 * 2) - pub_r000504_19 + 9) & 127;
    sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_43 * 3) + (sec_r000504_3 * 2) - pub_r000504_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_57 * 3) + (sec_r000504_20 * 2) - pub_r000504_19 + 15) & 127;
    sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000504_22 * 3) + (sec_r000504_22 * 2) - pub_r000504_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r000504_10 * 3) + (sec_r000504_10 * 2) - pub_r000504_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_63 * 3) + (sec_r000504_19 * 2) - pub_r000504_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_44 * 3) + (sec_r000504_1 * 2) - pub_r000504_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_42 * 3) + (sec_r000504_11 * 2) - pub_r000504_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_41 * 3) + (sec_r000504_17 * 2) - pub_r000504_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_54 * 3) + (sec_r000504_0 * 2) - pub_r000504_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_57 * 3) + (sec_r000504_6 * 2) - pub_r000504_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_31 * 3) + (sec_r000504_11 * 2) - pub_r000504_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_63 * 3) + (sec_r000504_11 * 2) - pub_r000504_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_74 * 3) + (sec_r000504_14 * 2) - pub_r000504_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_56 * 3) + (sec_r000504_9 * 2) - pub_r000504_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_82 * 3) + (sec_r000504_5 * 2) - pub_r000504_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000504_19 * 3) + (sec_r000504_19 * 2) - pub_r000504_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_57 * 3) + (sec_r000504_1 * 2) - pub_r000504_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_83 * 3) + (sec_r000504_18 * 2) - pub_r000504_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000504_22 * 3) + (sec_r000504_22 * 2) - pub_r000504_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_52 * 3) + (sec_r000504_17 * 2) - pub_r000504_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_68 * 3) + (sec_r000504_2 * 2) - pub_r000504_4 + 34) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_56 * 3) + (sec_r000504_8 * 2) - pub_r000504_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_51 * 3) + (sec_r000504_14 * 2) - pub_r000504_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r000504_5 * 3) + (sec_r000504_5 * 2) - pub_r000504_19 + 13) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000504_7 * 3) + (sec_r000504_7 * 2) - pub_r000504_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_79 * 3) + (sec_r000504_15 * 2) - pub_r000504_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_79 * 3) + (sec_r000504_11 * 2) - pub_r000504_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_85 * 3) + (sec_r000504_13 * 2) - pub_r000504_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_69 * 3) + (sec_r000504_15 * 2) - pub_r000504_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_98 * 3) + (sec_r000504_13 * 2) - pub_r000504_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_73 * 3) + (sec_r000504_3 * 2) - pub_r000504_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000504_15 * 3) + (sec_r000504_15 * 2) - pub_r000504_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_87 * 3) + (sec_r000504_16 * 2) - pub_r000504_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_81 * 3) + (sec_r000504_22 * 2) - pub_r000504_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_106 * 3) + (sec_r000504_22 * 2) - pub_r000504_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_56 * 3) + (sec_r000504_14 * 2) - pub_r000504_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_56 * 3) + (sec_r000504_15 * 2) - pub_r000504_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_54 * 3) + (sec_r000504_15 * 2) - pub_r000504_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_107 * 3) + (sec_r000504_12 * 2) - pub_r000504_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_53 * 3) + (sec_r000504_19 * 2) - pub_r000504_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r000504_4 * 3) + (sec_r000504_4 * 2) - pub_r000504_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_101 * 3) + (sec_r000504_6 * 2) - pub_r000504_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_64 * 3) + (sec_r000504_6 * 2) - pub_r000504_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000504_2 * 3) + (sec_r000504_2 * 2) - pub_r000504_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_79 * 3) + (sec_r000504_2 * 2) - pub_r000504_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000504_17 * 3) + (sec_r000504_17 * 2) - pub_r000504_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_101 * 3) + (sec_r000504_19 * 2) - pub_r000504_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_120 * 3) + (sec_r000504_14 * 2) - pub_r000504_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_64 * 3) + (sec_r000504_17 * 2) - pub_r000504_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_78 * 3) + (sec_r000504_17 * 2) - pub_r000504_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_59 * 3) + (sec_r000504_15 * 2) - pub_r000504_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_74 * 3) + (sec_r000504_22 * 2) - pub_r000504_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_72 * 3) + (sec_r000504_10 * 2) - pub_r000504_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_0 + 5) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_83 * 3) + (sec_r000504_20 * 2) - pub_r000504_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000504_7 * 3) + (sec_r000504_7 * 2) - pub_r000504_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_127 * 3) + (sec_r000504_4 * 2) - pub_r000504_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_121 * 3) + (sec_r000504_0 * 2) - pub_r000504_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_65 * 3) + (sec_r000504_19 * 2) - pub_r000504_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r000504_13 * 3) + (sec_r000504_13 * 2) - pub_r000504_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_46 * 3) + (sec_r000504_7 * 2) - pub_r000504_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_51 * 3) + (sec_r000504_2 * 2) - pub_r000504_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r000504_3 * 3) + (sec_r000504_3 * 2) - pub_r000504_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_98 * 3) + (sec_r000504_16 * 2) - pub_r000504_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_116 * 3) + (sec_r000504_22 * 2) - pub_r000504_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_33 * 3) + (sec_r000504_16 * 2) - pub_r000504_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_41 * 3) + (sec_r000504_5 * 2) - pub_r000504_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_48 * 3) + (sec_r000504_11 * 2) - pub_r000504_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_135 * 3) + (sec_r000504_14 * 2) - pub_r000504_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_55 * 3) + (sec_r000504_21 * 2) - pub_r000504_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_96 * 3) + (sec_r000504_0 * 2) - pub_r000504_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r000504_12 * 3) + (sec_r000504_12 * 2) - pub_r000504_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_92 * 3) + (sec_r000504_8 * 2) - pub_r000504_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000504_11 * 3) + (sec_r000504_11 * 2) - pub_r000504_19 + 23) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_119 * 3) + (sec_r000504_10 * 2) - pub_r000504_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_55 * 3) + (sec_r000504_20 * 2) - pub_r000504_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_131 * 3) + (sec_r000504_3 * 2) - pub_r000504_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_47 * 3) + (sec_r000504_13 * 2) - pub_r000504_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_138 * 3) + (sec_r000504_2 * 2) - pub_r000504_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_115 * 3) + (sec_r000504_5 * 2) - pub_r000504_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000504_22 * 3) + (sec_r000504_22 * 2) - pub_r000504_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000504_17 * 3) + (sec_r000504_17 * 2) - pub_r000504_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_73 * 3) + (sec_r000504_16 * 2) - pub_r000504_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_94 * 3) + (sec_r000504_6 * 2) - pub_r000504_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_37 * 3) + (sec_r000504_12 * 2) - pub_r000504_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_43 * 3) + (sec_r000504_6 * 2) - pub_r000504_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000504_9 * 3) + (sec_r000504_9 * 2) - pub_r000504_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_114 * 3) + (sec_r000504_15 * 2) - pub_r000504_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r000504_10 * 3) + (sec_r000504_10 * 2) - pub_r000504_19 + 15) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_90 * 3) + (sec_r000504_5 * 2) - pub_r000504_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_66 * 3) + (sec_r000504_18 * 2) - pub_r000504_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000504_8 * 3) + (sec_r000504_8 * 2) - pub_r000504_19 + 9) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000504_19 * 3) + (sec_r000504_19 * 2) - pub_r000504_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_152 * 3) + (sec_r000504_11 * 2) - pub_r000504_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_88 * 3) + (sec_r000504_5 * 2) - pub_r000504_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_40 * 3) + (sec_r000504_15 * 2) - pub_r000504_12 + 18) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000504_15 * 3) + (sec_r000504_15 * 2) - pub_r000504_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_54 * 3) + (sec_r000504_21 * 2) - pub_r000504_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_150 * 3) + (sec_r000504_9 * 2) - pub_r000504_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r000504_20 * 3) + (sec_r000504_20 * 2) - pub_r000504_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_92 * 3) + (sec_r000504_22 * 2) - pub_r000504_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_96 * 3) + (sec_r000504_14 * 2) - pub_r000504_2 + 27) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_124 * 3) + (sec_r000504_8 * 2) - pub_r000504_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_52 * 3) + (sec_r000504_8 * 2) - pub_r000504_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_158 * 3) + (sec_r000504_8 * 2) - pub_r000504_19 + 25) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000504_20 * 3) + (sec_r000504_20 * 2) - pub_r000504_17 + 13) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_42 * 3) + (sec_r000504_3 * 2) - pub_r000504_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_128 * 3) + (sec_r000504_20 * 2) - pub_r000504_14 + 3) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_59 * 3) + (sec_r000504_1 * 2) - pub_r000504_10 + 16) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000504_3 * 3) + (sec_r000504_3 * 2) - pub_r000504_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_45 * 3) + (sec_r000504_18 * 2) - pub_r000504_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000504_15 * 3) + (sec_r000504_15 * 2) - pub_r000504_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_182 * 3) + (sec_r000504_3 * 2) - pub_r000504_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000504_3 * 3) + (sec_r000504_3 * 2) - pub_r000504_18 + 12) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_156 * 3) + (sec_r000504_1 * 2) - pub_r000504_19 + 20) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_173 * 3) + (sec_r000504_2 * 2) - pub_r000504_18 + 26) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_155 * 3) + (sec_r000504_1 * 2) - pub_r000504_17 + 13) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_69 * 3) + (sec_r000504_20 * 2) - pub_r000504_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_79 * 3) + (sec_r000504_2 * 2) - pub_r000504_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_115 * 3) + (sec_r000504_18 * 2) - pub_r000504_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_88 * 3) + (sec_r000504_12 * 2) - pub_r000504_3 + 7) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_84 * 3) + (sec_r000504_20 * 2) - pub_r000504_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_206 * 3) + (sec_r000504_12 * 2) - pub_r000504_19 + 22) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_189 * 3) + (sec_r000504_0 * 2) - pub_r000504_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000504_2 * 3) + (sec_r000504_2 * 2) - pub_r000504_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_201 * 3) + (sec_r000504_21 * 2) - pub_r000504_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_174 * 3) + (sec_r000504_4 * 2) - pub_r000504_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000504_7 * 3) + (sec_r000504_7 * 2) - pub_r000504_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_134 * 3) + (sec_r000504_18 * 2) - pub_r000504_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_210 * 3) + (sec_r000504_7 * 2) - pub_r000504_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_182 * 3) + (sec_r000504_6 * 2) - pub_r000504_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_64 * 3) + (sec_r000504_0 * 2) - pub_r000504_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_33 * 3) + (sec_r000504_8 * 2) - pub_r000504_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_145 * 3) + (sec_r000504_14 * 2) - pub_r000504_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_213 * 3) + (sec_r000504_1 * 2) - pub_r000504_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r000504_8 * 3) + (sec_r000504_8 * 2) - pub_r000504_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_46 * 3) + (sec_r000504_0 * 2) - pub_r000504_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_188 * 3) + (sec_r000504_13 * 2) - pub_r000504_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_123 * 3) + (sec_r000504_20 * 2) - pub_r000504_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_162 * 3) + (sec_r000504_6 * 2) - pub_r000504_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_2 + 10) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_78 * 3) + (sec_r000504_17 * 2) - pub_r000504_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000504_4 * 3) + (sec_r000504_4 * 2) - pub_r000504_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_71 * 3) + (sec_r000504_19 * 2) - pub_r000504_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_167 * 3) + (sec_r000504_9 * 2) - pub_r000504_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_158 * 3) + (sec_r000504_20 * 2) - pub_r000504_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_144 * 3) + (sec_r000504_5 * 2) - pub_r000504_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_124 * 3) + (sec_r000504_4 * 2) - pub_r000504_19 + 30) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_78 * 3) + (sec_r000504_21 * 2) - pub_r000504_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_148 * 3) + (sec_r000504_19 * 2) - pub_r000504_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r000504_22 * 3) + (sec_r000504_22 * 2) - pub_r000504_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_155 * 3) + (sec_r000504_19 * 2) - pub_r000504_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r000504_8 * 3) + (sec_r000504_8 * 2) - pub_r000504_18 + 26) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_197 * 3) + (sec_r000504_19 * 2) - pub_r000504_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_89 * 3) + (sec_r000504_15 * 2) - pub_r000504_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_51 * 3) + (sec_r000504_22 * 2) - pub_r000504_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_203 * 3) + (sec_r000504_17 * 2) - pub_r000504_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_107 * 3) + (sec_r000504_14 * 2) - pub_r000504_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((sec_r000504_19 * 3) + (sec_r000504_19 * 2) - pub_r000504_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_52 * 3) + (sec_r000504_11 * 2) - pub_r000504_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_235 * 3) + (sec_r000504_17 * 2) - pub_r000504_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_158 * 3) + (sec_r000504_11 * 2) - pub_r000504_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_83 * 3) + (sec_r000504_19 * 2) - pub_r000504_9 + 26) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_224 * 3) + (sec_r000504_5 * 2) - pub_r000504_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_74 * 3) + (sec_r000504_22 * 2) - pub_r000504_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r000504_3 * 3) + (sec_r000504_3 * 2) - pub_r000504_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_108 * 3) + (sec_r000504_5 * 2) - pub_r000504_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_40 * 3) + (sec_r000504_10 * 2) - pub_r000504_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_158 * 3) + (sec_r000504_6 * 2) - pub_r000504_19 + 31) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r000504_20 * 3) + (sec_r000504_20 * 2) - pub_r000504_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_157 * 3) + (sec_r000504_16 * 2) - pub_r000504_7 + 16) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_81 * 3) + (sec_r000504_19 * 2) - pub_r000504_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_183 * 3) + (sec_r000504_19 * 2) - pub_r000504_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_151 * 3) + (sec_r000504_5 * 2) - pub_r000504_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((sec_r000504_5 * 3) + (sec_r000504_5 * 2) - pub_r000504_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r000504_18 * 3) + (sec_r000504_18 * 2) - pub_r000504_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_233 * 3) + (sec_r000504_13 * 2) - pub_r000504_17 + 20) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_31 * 3) + (sec_r000504_8 * 2) - pub_r000504_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_234 * 3) + (sec_r000504_9 * 2) - pub_r000504_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_136 * 3) + (sec_r000504_8 * 2) - pub_r000504_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_183 * 3) + (sec_r000504_13 * 2) - pub_r000504_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_226 * 3) + (sec_r000504_4 * 2) - pub_r000504_5 + 24) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_32 * 3) + (sec_r000504_19 * 2) - pub_r000504_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_255 * 3) + (sec_r000504_2 * 2) - pub_r000504_18 + 21) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_94 * 3) + (sec_r000504_20 * 2) - pub_r000504_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((sec_r000504_11 * 3) + (sec_r000504_11 * 2) - pub_r000504_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_232 * 3) + (sec_r000504_8 * 2) - pub_r000504_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_219 * 3) + (sec_r000504_20 * 2) - pub_r000504_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_112 * 3) + (sec_r000504_7 * 2) - pub_r000504_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r000504_11 * 3) + (sec_r000504_11 * 2) - pub_r000504_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_82 * 3) + (sec_r000504_15 * 2) - pub_r000504_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_208 * 3) + (sec_r000504_8 * 2) - pub_r000504_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_88 * 3) + (sec_r000504_8 * 2) - pub_r000504_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_281 * 3) + (sec_r000504_18 * 2) - pub_r000504_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_76 * 3) + (sec_r000504_12 * 2) - pub_r000504_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000504_16 * 3) + (sec_r000504_16 * 2) - pub_r000504_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_198 * 3) + (sec_r000504_10 * 2) - pub_r000504_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_134 * 3) + (sec_r000504_2 * 2) - pub_r000504_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_138 * 3) + (sec_r000504_2 * 2) - pub_r000504_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_105 * 3) + (sec_r000504_11 * 2) - pub_r000504_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_80 * 3) + (sec_r000504_4 * 2) - pub_r000504_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((sec_r000504_13 * 3) + (sec_r000504_13 * 2) - pub_r000504_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_58 * 3) + (sec_r000504_6 * 2) - pub_r000504_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_69 * 3) + (sec_r000504_22 * 2) - pub_r000504_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_90 * 3) + (sec_r000504_19 * 2) - pub_r000504_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_59 * 3) + (sec_r000504_11 * 2) - pub_r000504_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_232 * 3) + (sec_r000504_1 * 2) - pub_r000504_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_244 * 3) + (sec_r000504_20 * 2) - pub_r000504_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_143 * 3) + (sec_r000504_14 * 2) - pub_r000504_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_298 * 3) + (sec_r000504_4 * 2) - pub_r000504_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r000504_19 * 3) + (sec_r000504_19 * 2) - pub_r000504_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_207 * 3) + (sec_r000504_17 * 2) - pub_r000504_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r000504_10 * 3) + (sec_r000504_10 * 2) - pub_r000504_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_38 * 3) + (sec_r000504_9 * 2) - pub_r000504_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r000504_0 * 3) + (sec_r000504_0 * 2) - pub_r000504_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_310 * 2) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_311 * 2) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r000504_22 * 3) + (sec_r000504_22 * 2) - pub_r000504_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_312 * 2) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_122 * 3) + (sec_r000504_15 * 2) - pub_r000504_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_313 * 2) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((sec_r000504_17 * 3) + (sec_r000504_17 * 2) - pub_r000504_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_314 * 2) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_163 * 3) + (sec_r000504_12 * 2) - pub_r000504_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_315 * 2) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_136 * 3) + (sec_r000504_18 * 2) - pub_r000504_19 + 25) & 127;
    sec_accum = (sec_accum + stage_v_316 * 2) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_317 * 2) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((sec_r000504_1 * 3) + (sec_r000504_1 * 2) - pub_r000504_15 + 32) & 127;
    sec_accum = (sec_accum + stage_v_318 * 2) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((sec_r000504_2 * 3) + (sec_r000504_2 * 2) - pub_r000504_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_319 * 2) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r000504_4 * 3) + (sec_r000504_4 * 2) - pub_r000504_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_320 * 2) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_257 * 3) + (sec_r000504_14 * 2) - pub_r000504_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_321 * 2) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_201 * 3) + (sec_r000504_6 * 2) - pub_r000504_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_322 * 2) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((sec_r000504_6 * 3) + (sec_r000504_6 * 2) - pub_r000504_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_323 * 2) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_101 * 3) + (sec_r000504_6 * 2) - pub_r000504_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_324 * 2) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_226 * 3) + (sec_r000504_10 * 2) - pub_r000504_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_325 * 2) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_306 * 3) + (sec_r000504_10 * 2) - pub_r000504_18 + 21) & 127;
    sec_accum = (sec_accum + stage_v_326 * 2) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_206 * 3) + (sec_r000504_5 * 2) - pub_r000504_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_327 * 2) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_311 * 3) + (sec_r000504_18 * 2) - pub_r000504_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_328 * 2) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_320 * 3) + (sec_r000504_2 * 2) - pub_r000504_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_329 * 2) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_102 * 3) + (sec_r000504_2 * 2) - pub_r000504_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_330 * 2) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_90 * 3) + (sec_r000504_8 * 2) - pub_r000504_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_331 * 2) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r000504_20 * 3) + (sec_r000504_20 * 2) - pub_r000504_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_332 * 2) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_58 * 3) + (sec_r000504_3 * 2) - pub_r000504_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_333 * 2) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r000504_14 * 3) + (sec_r000504_14 * 2) - pub_r000504_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_334 * 2) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_149 * 3) + (sec_r000504_4 * 2) - pub_r000504_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_335 * 2) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_204 * 3) + (sec_r000504_2 * 2) - pub_r000504_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_336 * 2) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_290 * 3) + (sec_r000504_10 * 2) - pub_r000504_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_337 * 2) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_67 * 3) + (sec_r000504_13 * 2) - pub_r000504_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_338 * 2) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r000504_8 * 3) + (sec_r000504_8 * 2) - pub_r000504_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_339 * 2) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_311 * 3) + (sec_r000504_14 * 2) - pub_r000504_17 + 36) & 127;
    sec_accum = (sec_accum + stage_v_340 * 2) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_97 * 3) + (sec_r000504_12 * 2) - pub_r000504_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_341 * 2) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_276 * 3) + (sec_r000504_14 * 2) - pub_r000504_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_342 * 2) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_256 * 3) + (sec_r000504_3 * 2) - pub_r000504_17 + 16) & 127;
    sec_accum = (sec_accum + stage_v_343 * 2) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_201 * 3) + (sec_r000504_10 * 2) - pub_r000504_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_344 * 2) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_112 * 3) + (sec_r000504_19 * 2) - pub_r000504_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_345 * 2) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r000504_13 * 3) + (sec_r000504_13 * 2) - pub_r000504_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_346 * 2) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_342 * 3) + (sec_r000504_7 * 2) - pub_r000504_8 + 32) & 127;
    sec_accum = (sec_accum + stage_v_347 * 2) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_166 * 3) + (sec_r000504_4 * 2) - pub_r000504_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_348 * 2) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_48 * 3) + (sec_r000504_13 * 2) - pub_r000504_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_349 * 2) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
