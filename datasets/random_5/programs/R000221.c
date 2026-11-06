/*
 * Benchmark Program: R000221
 * Security Family: zero_leakage
 * Generator Seed: 522113
 * High Inputs: 21 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000221_2113_0 {
    int status;
    unsigned char offset;
    unsigned char calib;
    int buffer[3];
};

struct DeviceConfig_R000221_2113_1 {
    int id;
    unsigned char timeout;
    int port;
    int stop_bits;
    unsigned char baud_rate;
    int parity;
    int buffer[3];
};

union RegisterBank_R000221_2113_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000221_2113_0(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_33) & 63;
    acc ^= aux;
    int vector_73 = (aux + st.buffer[1]) & 3;
    switch (vector_73) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_1(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    int segment_52 = (aux + st.buffer[1]) & 3;
    switch (segment_52) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_79 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_79 > 23) {
        acc = (acc + tracker_79 * 2 + 5) & 127;
        aux ^= (tracker_79 & 15);
    } else {
        acc = (acc - tracker_79 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_50) & 63;
    acc ^= aux;
    int delta_39 = (aux + st.buffer[1]) & 3;
    switch (delta_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_3(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_83 = (aux + st.buffer[1]) & 3;
    switch (factor_83) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_43 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_43 > 28) {
        acc = (acc + bound_43 * 2 + 5) & 127;
        aux ^= (bound_43 & 15);
    } else {
        acc = (acc - bound_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_34 = local_arr[aux % 3];
    acc = (acc + threshold_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_5(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_11 > 15) {
        acc = (acc + tally_11 * 2 + 5) & 127;
        aux ^= (tally_11 & 15);
    } else {
        acc = (acc - tally_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int segment_91 = local_arr[aux % 3];
    acc = (acc + segment_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_13 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_13 > 39) {
        acc = (acc + accumulator_13 * 2 + 5) & 127;
        aux ^= (accumulator_13 & 15);
    } else {
        acc = (acc - accumulator_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_7(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_58) & 63;
    acc ^= aux;
    int vector_10 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_10 > 15) {
        acc = (acc + vector_10 * 2 + 5) & 127;
        aux ^= (vector_10 & 15);
    } else {
        acc = (acc - vector_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_8(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_39 > 39) {
        acc = (acc + anchor_39 * 2 + 5) & 127;
        aux ^= (anchor_39 & 15);
    } else {
        acc = (acc - anchor_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_86 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_86 > 31) {
        acc = (acc + coefficient_86 * 2 + 5) & 127;
        aux ^= (coefficient_86 & 15);
    } else {
        acc = (acc - coefficient_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_41 = local_arr[aux % 3];
    acc = (acc + scale_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_10(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int margin_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_37 = local_arr[aux % 3];
    acc = (acc + vector_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_96) & 63;
    acc ^= aux;
    int tally_21 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_21 > 40) {
        acc = (acc + tally_21 * 2 + 5) & 127;
        aux ^= (tally_21 & 15);
    } else {
        acc = (acc - tally_21 + 11) & 127;
        aux += 3;
    }
    int tally_74 = (aux + st.buffer[1]) & 3;
    switch (tally_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000221_2113_12(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000221_2113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_75 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_75 > 46) {
        acc = (acc + residue_75 * 2 + 5) & 127;
        aux ^= (residue_75 & 15);
    } else {
        acc = (acc - residue_75 + 11) & 127;
        aux += 3;
    }
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_58 = local_arr[aux % 3];
    acc = (acc + sample_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_46 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_46 > 22) {
        acc = (acc + factor_46 * 2 + 5) & 127;
        aux ^= (factor_46 & 15);
    } else {
        acc = (acc - factor_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_48 = local_arr[aux % 3];
    acc = (acc + pivot_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000221_2113_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000221_2113_15(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int accumulator_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_19) & 63;
    acc ^= aux;
    int segment_18 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_18 > 11) {
        acc = (acc + segment_18 * 2 + 5) & 127;
        aux ^= (segment_18 & 15);
    } else {
        acc = (acc - segment_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_15 = local_arr[aux % 3];
    acc = (acc + sample_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000221_2113_16(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000221_2113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_28 = local_arr[aux % 3];
    acc = (acc + damping_28 * 2) & 127;
    int phase_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000221_0;
    int sec_r000221_1;
    int sec_r000221_2;
    int sec_r000221_3;
    int sec_r000221_4;
    int sec_r000221_5;
    int sec_r000221_6;
    int sec_r000221_7;
    int sec_r000221_8;
    int sec_r000221_9;
    int sec_r000221_10;
    int sec_r000221_11;
    int sec_r000221_12;
    int sec_r000221_13;
    int sec_r000221_14;
    int sec_r000221_15;
    int sec_r000221_16;
    int sec_r000221_17;
    int sec_r000221_18;
    int sec_r000221_19;
    int sec_r000221_20;
    int pub_r000221_0;
    int pub_r000221_1;
    int pub_r000221_2;
    int pub_r000221_3;
    int pub_r000221_4;
    int pub_r000221_5;
    int pub_r000221_6;
    int pub_r000221_7;
    int pub_r000221_8;
    int pub_r000221_9;
    int pub_r000221_10;
    int pub_r000221_11;
    int pub_r000221_12;
    int pub_r000221_13;
    int pub_r000221_14;
    int pub_r000221_15;
    int pub_r000221_16;
    int pub_r000221_17;
    int pub_r000221_18;
    int pub_r000221_19;
    int pub_r000221_20;
    int pub_r000221_21;
    int pub_r000221_22;
    int pub_r000221_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000221_0 >= -100 && pub_r000221_0 <= 100);
    __CPROVER_assume(pub_r000221_1 >= -100 && pub_r000221_1 <= 100);
    __CPROVER_assume(pub_r000221_2 >= -100 && pub_r000221_2 <= 100);
    __CPROVER_assume(pub_r000221_3 >= -100 && pub_r000221_3 <= 100);
    __CPROVER_assume(pub_r000221_4 >= -100 && pub_r000221_4 <= 100);
    __CPROVER_assume(pub_r000221_5 >= -100 && pub_r000221_5 <= 100);
    __CPROVER_assume(pub_r000221_6 >= -100 && pub_r000221_6 <= 100);
    __CPROVER_assume(pub_r000221_7 >= -100 && pub_r000221_7 <= 100);
    __CPROVER_assume(pub_r000221_8 >= -100 && pub_r000221_8 <= 100);
    __CPROVER_assume(pub_r000221_9 >= -100 && pub_r000221_9 <= 100);
    __CPROVER_assume(pub_r000221_10 >= -100 && pub_r000221_10 <= 100);
    __CPROVER_assume(pub_r000221_11 >= -100 && pub_r000221_11 <= 100);
    __CPROVER_assume(pub_r000221_12 >= -100 && pub_r000221_12 <= 100);
    __CPROVER_assume(pub_r000221_13 >= -100 && pub_r000221_13 <= 100);
    __CPROVER_assume(pub_r000221_14 >= -100 && pub_r000221_14 <= 100);
    __CPROVER_assume(pub_r000221_15 >= -100 && pub_r000221_15 <= 100);
    __CPROVER_assume(pub_r000221_16 >= -100 && pub_r000221_16 <= 100);
    __CPROVER_assume(pub_r000221_17 >= -100 && pub_r000221_17 <= 100);
    __CPROVER_assume(pub_r000221_18 >= -100 && pub_r000221_18 <= 100);
    __CPROVER_assume(pub_r000221_19 >= -100 && pub_r000221_19 <= 100);
    __CPROVER_assume(pub_r000221_20 >= -100 && pub_r000221_20 <= 100);
    __CPROVER_assume(pub_r000221_21 >= -100 && pub_r000221_21 <= 100);
    __CPROVER_assume(pub_r000221_22 >= -100 && pub_r000221_22 <= 100);
    __CPROVER_assume(pub_r000221_23 >= -100 && pub_r000221_23 <= 100);
    __CPROVER_assume(sec_r000221_0 >= 0 && sec_r000221_0 <= 255);
    __CPROVER_assume(sec_r000221_1 >= 0 && sec_r000221_1 <= 255);
    __CPROVER_assume(sec_r000221_2 >= 0 && sec_r000221_2 <= 255);
    __CPROVER_assume(sec_r000221_3 >= 0 && sec_r000221_3 <= 255);
    __CPROVER_assume(sec_r000221_4 >= 0 && sec_r000221_4 <= 255);
    __CPROVER_assume(sec_r000221_5 >= 0 && sec_r000221_5 <= 255);
    __CPROVER_assume(sec_r000221_6 >= 0 && sec_r000221_6 <= 255);
    __CPROVER_assume(sec_r000221_7 >= 0 && sec_r000221_7 <= 255);
    __CPROVER_assume(sec_r000221_8 >= 0 && sec_r000221_8 <= 255);
    __CPROVER_assume(sec_r000221_9 >= 0 && sec_r000221_9 <= 255);
    __CPROVER_assume(sec_r000221_10 >= 0 && sec_r000221_10 <= 255);
    __CPROVER_assume(sec_r000221_11 >= 0 && sec_r000221_11 <= 255);
    __CPROVER_assume(sec_r000221_12 >= 0 && sec_r000221_12 <= 255);
    __CPROVER_assume(sec_r000221_13 >= 0 && sec_r000221_13 <= 255);
    __CPROVER_assume(sec_r000221_14 >= 0 && sec_r000221_14 <= 255);
    __CPROVER_assume(sec_r000221_15 >= 0 && sec_r000221_15 <= 255);
    __CPROVER_assume(sec_r000221_16 >= 0 && sec_r000221_16 <= 255);
    __CPROVER_assume(sec_r000221_17 >= 0 && sec_r000221_17 <= 255);
    __CPROVER_assume(sec_r000221_18 >= 0 && sec_r000221_18 <= 255);
    __CPROVER_assume(sec_r000221_19 >= 0 && sec_r000221_19 <= 255);
    __CPROVER_assume(sec_r000221_20 >= 0 && sec_r000221_20 <= 255);

    struct SensorNode_R000221_2113_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000221_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000221_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000221_0 + 7) & 15;
    struct DeviceConfig_R000221_2113_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000221_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000221_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000221_0 + 9) & 15;

    union RegisterBank_R000221_2113_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 40) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 55) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

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
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 29) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 44) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 17) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 32) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
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
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 40) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 55) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 14) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 29) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 39) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 40) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 55) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 19) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 34) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = table[2];
    table[2] = (table[3] + 157) & 63;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 13) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 28) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 34) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 49) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 12) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 27) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_0.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
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

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 35) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 50) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[1] * 2 + 316) & 63;
    if (stage_v_103 > 16) {
        out_sink = (out_sink + stage_v_103 - 5) & 255;
        if (stage_v_103 > 31) {
            chk_sum ^= (stage_v_103 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_103 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_104 = (stage_v_104 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

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
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_0.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 17) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 32) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_1.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 28) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 43) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_1.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 29) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 44) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_0.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
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

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (out_sink > 100) ? (chk_sum & 31) : (157 & 31);
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= (stage_v_152 << 1) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 36) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 51) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_0.buffer[0] ^ 163) & 3;
    switch (stage_v_160) {
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

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 39) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 54) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 11) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 26) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_0.buffer[1] * 2 + 505) & 63;
    if (stage_v_166 > 40) {
        out_sink = (out_sink + stage_v_166 - 5) & 255;
        if (stage_v_166 > 55) {
            chk_sum ^= (stage_v_166 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_166 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 171) & 15;
    int stage_v_170 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= stage_v_170;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_171 = (stage_v_171 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (out_sink > 100) ? (chk_sum & 31) : (178 & 31);
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= (stage_v_173 << 1) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 177 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 181 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 182) & 15;
    int stage_v_181 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= stage_v_181;

    /* Execution Pipeline Stage 182 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 183) & 15;
    int stage_v_182 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= stage_v_182;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (out_sink > 100) ? (chk_sum & 31) : (191 & 31);
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= (stage_v_186 << 1) & 127;

    /* Execution Pipeline Stage 187 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 188) & 15;
    int stage_v_187 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= stage_v_187;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_1.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = table[0];
    table[0] = (table[1] + 385) & 63;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2];
    table[2] = (table[3] + 389) & 63;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = table[3];
    table[3] = (table[0] + 391) & 63;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_0.buffer[0] ^ 199) & 3;
    switch (stage_v_196) {
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

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_197 = (stage_v_197 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_197) & 127;
    }
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 29) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 44) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 200) & 15;
    int stage_v_199 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= stage_v_199;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (out_sink > 100) ? (chk_sum & 31) : (206 & 31);
    out_sink = (out_sink + stage_v_201) & 255;
    chk_sum ^= (stage_v_201 << 1) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = table[2];
    table[2] = (table[3] + 405) & 63;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (st_var_1.buffer[2] * 2 + 616) & 63;
    if (stage_v_203 > 10) {
        out_sink = (out_sink + stage_v_203 - 5) & 255;
        if (stage_v_203 > 25) {
            chk_sum ^= (stage_v_203 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_203 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_204 = (stage_v_204 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_204) & 127;
    }
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (st_var_1.buffer[1] * 2 + 622) & 63;
    if (stage_v_205 > 30) {
        out_sink = (out_sink + stage_v_205 - 5) & 255;
        if (stage_v_205 > 45) {
            chk_sum ^= (stage_v_205 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_205 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (out_sink > 100) ? (chk_sum & 31) : (211 & 31);
    out_sink = (out_sink + stage_v_206) & 255;
    chk_sum ^= (stage_v_206 << 1) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = table[3];
    table[3] = (table[0] + 415) & 63;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (st_var_1.buffer[1] * 2 + 640) & 63;
    if (stage_v_211 > 37) {
        out_sink = (out_sink + stage_v_211 - 5) & 255;
        if (stage_v_211 > 52) {
            chk_sum ^= (stage_v_211 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_211 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (st_var_1.buffer[0] * 2 + 646) & 63;
    if (stage_v_213 > 14) {
        out_sink = (out_sink + stage_v_213 - 5) & 255;
        if (stage_v_213 > 29) {
            chk_sum ^= (stage_v_213 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_213 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_214 = (stage_v_214 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_214) & 127;
    }
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = table[3];
    table[3] = (table[0] + 431) & 63;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_216 = (stage_v_216 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_216) & 127;
    }
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (st_var_1.buffer[0] ^ 220) & 3;
    switch (stage_v_217) {
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

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (st_var_0.buffer[2] * 2 + 661) & 63;
    if (stage_v_218 > 11) {
        out_sink = (out_sink + stage_v_218 - 5) & 255;
        if (stage_v_218 > 26) {
            chk_sum ^= (stage_v_218 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_218 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (out_sink > 100) ? (chk_sum & 31) : (226 & 31);
    out_sink = (out_sink + stage_v_221) & 255;
    chk_sum ^= (stage_v_221 << 1) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (out_sink > 100) ? (chk_sum & 31) : (227 & 31);
    out_sink = (out_sink + stage_v_222) & 255;
    chk_sum ^= (stage_v_222 << 1) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_223 = (stage_v_223 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_223) & 127;
    }
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (st_var_0.buffer[0] ^ 227) & 3;
    switch (stage_v_224) {
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

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = table[1];
    table[1] = (table[2] + 451) & 63;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 227) & 15;
    int stage_v_226 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_226) & 255;
    chk_sum ^= stage_v_226;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = table[3];
    table[3] = (table[0] + 455) & 63;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (st_var_0.buffer[0] ^ 231) & 3;
    switch (stage_v_228) {
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

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (out_sink > 100) ? (chk_sum & 31) : (234 & 31);
    out_sink = (out_sink + stage_v_229) & 255;
    chk_sum ^= (stage_v_229 << 1) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = table[3];
    table[3] = (table[0] + 463) & 63;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = table[0];
    table[0] = (table[1] + 465) & 63;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 234) & 15;
    int stage_v_233 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_233) & 255;
    chk_sum ^= stage_v_233;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = table[2];
    table[2] = (table[3] + 469) & 63;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (st_var_1.buffer[0] ^ 238) & 3;
    switch (stage_v_235) {
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

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (st_var_0.buffer[2] * 2 + 715) & 63;
    if (stage_v_236 > 39) {
        out_sink = (out_sink + stage_v_236 - 5) & 255;
        if (stage_v_236 > 54) {
            chk_sum ^= (stage_v_236 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_236 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (out_sink > 100) ? (chk_sum & 31) : (242 & 31);
    out_sink = (out_sink + stage_v_237) & 255;
    chk_sum ^= (stage_v_237 << 1) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (out_sink > 100) ? (chk_sum & 31) : (243 & 31);
    out_sink = (out_sink + stage_v_238) & 255;
    chk_sum ^= (stage_v_238 << 1) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (out_sink > 100) ? (chk_sum & 31) : (244 & 31);
    out_sink = (out_sink + stage_v_239) & 255;
    chk_sum ^= (stage_v_239 << 1) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = table[0];
    table[0] = (table[1] + 481) & 63;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_241 = (stage_v_241 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_241) & 127;
    }
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = table[2];
    table[2] = (table[3] + 485) & 63;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Zero Leakage Neutralization */
    int dead_sec_0 = (sec_r000221_0 ^ sec_r000221_0) * 0;
    int dead_sec_1 = (sec_r000221_1 ^ sec_r000221_1) * 0;
    int dead_sec_2 = (sec_r000221_2 ^ sec_r000221_2) * 0;
    int dead_sec_3 = (sec_r000221_3 ^ sec_r000221_3) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1 + dead_sec_2 + dead_sec_3) & 255;
    g_out = out_sink;
    g_chk = chk_sum;
    g_telemetry = (chk_sum ^ 0x55) & 127;
    return 0;
}
