/*
 * Benchmark Program: R000785
 * Security Family: bitwise_flow
 * Generator Seed: 578513
 * High Inputs: 24 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000785_8513_0 {
    short status;
    int threshold;
    unsigned char gain;
    short calib;
    int offset;
    int buffer[3];
};

struct DeviceConfig_R000785_8513_1 {
    int stop_bits;
    unsigned char timeout;
    int parity;
    short id;
    int buffer[3];
};

union RegisterBank_R000785_8513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000785_8513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000785_8513_0(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int parity_53 = (aux + st.buffer[1]) & 3;
    switch (parity_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_38 = local_arr[aux % 3];
    acc = (acc + stride_38 * 2) & 127;
    int weight_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_15) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000785_8513_1(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int mask_47 = local_arr[aux % 3];
    acc = (acc + mask_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_83 = (aux + st.buffer[1]) & 3;
    switch (threshold_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000785_8513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_13) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_3(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_97) & 63;
    acc ^= aux;
    int bound_11 = (aux + st.buffer[1]) & 3;
    switch (bound_11) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_96 = local_arr[aux % 3];
    acc = (acc + window_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_30 = (aux + st.buffer[1]) & 3;
    switch (window_30) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_87 = local_arr[aux % 3];
    acc = (acc + segment_87 * 2) & 127;
    int bound_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_61) & 63;
    acc ^= aux;
    int offset_26 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_26 > 10) {
        acc = (acc + offset_26 * 2 + 5) & 127;
        aux ^= (offset_26 & 15);
    } else {
        acc = (acc - offset_26 + 11) & 127;
        aux += 3;
    }
    int pivot_78 = (aux + st.buffer[1]) & 3;
    switch (pivot_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_68 = local_arr[aux % 3];
    acc = (acc + tracker_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_7(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int phase_24 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_24 > 11) {
        acc = (acc + phase_24 * 2 + 5) & 127;
        aux ^= (phase_24 & 15);
    } else {
        acc = (acc - phase_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000785_8513_8(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_45 = local_arr[aux % 3];
    acc = (acc + quantum_45 * 2) & 127;
    int parity_12 = (aux + st.buffer[1]) & 3;
    switch (parity_12) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_82 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_82 > 32) {
        acc = (acc + parity_82 * 2 + 5) & 127;
        aux ^= (parity_82 & 15);
    } else {
        acc = (acc - parity_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000785_8513_9(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int bound_14 = (aux + st.buffer[1]) & 3;
    switch (bound_14) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_18 = local_arr[aux % 3];
    acc = (acc + checksum_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000785_8513_10(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_63 = local_arr[aux % 3];
    acc = (acc + delta_63 * 2) & 127;
    int segment_61 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_61 > 44) {
        acc = (acc + segment_61 * 2 + 5) & 127;
        aux ^= (segment_61 & 15);
    } else {
        acc = (acc - segment_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000785_8513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000785_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int quantum_75 = local_arr[aux % 3];
    acc = (acc + quantum_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_50 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_50 > 50) {
        acc = (acc + tracker_50 * 2 + 5) & 127;
        aux ^= (tracker_50 & 15);
    } else {
        acc = (acc - tracker_50 + 11) & 127;
        aux += 3;
    }
    int metric_38 = (aux + st.buffer[1]) & 3;
    switch (metric_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000785_8513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_46 = local_arr[aux % 3];
    acc = (acc + sample_46 * 2) & 127;
    int segment_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_62) & 63;
    acc ^= aux;
    int threshold_85 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_85 > 49) {
        acc = (acc + threshold_85 * 2 + 5) & 127;
        aux ^= (threshold_85 & 15);
    } else {
        acc = (acc - threshold_85 + 11) & 127;
        aux += 3;
    }
    int threshold_18 = (aux + st.buffer[1]) & 3;
    switch (threshold_18) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000785_8513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000785_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int damping_37 = local_arr[aux % 3];
    acc = (acc + damping_37 * 2) & 127;
    int offset_96 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_96 > 32) {
        acc = (acc + offset_96 * 2 + 5) & 127;
        aux ^= (offset_96 & 15);
    } else {
        acc = (acc - offset_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000785_0;
    int sec_r000785_1;
    int sec_r000785_2;
    int sec_r000785_3;
    int sec_r000785_4;
    int sec_r000785_5;
    int sec_r000785_6;
    int sec_r000785_7;
    int sec_r000785_8;
    int sec_r000785_9;
    int sec_r000785_10;
    int sec_r000785_11;
    int sec_r000785_12;
    int sec_r000785_13;
    int sec_r000785_14;
    int sec_r000785_15;
    int sec_r000785_16;
    int sec_r000785_17;
    int sec_r000785_18;
    int sec_r000785_19;
    int sec_r000785_20;
    int sec_r000785_21;
    int sec_r000785_22;
    int sec_r000785_23;
    int pub_r000785_0;
    int pub_r000785_1;
    int pub_r000785_2;
    int pub_r000785_3;
    int pub_r000785_4;
    int pub_r000785_5;
    int pub_r000785_6;
    int pub_r000785_7;
    int pub_r000785_8;
    int pub_r000785_9;
    int pub_r000785_10;
    int pub_r000785_11;
    int pub_r000785_12;
    int pub_r000785_13;
    int pub_r000785_14;
    int pub_r000785_15;
    int pub_r000785_16;
    int pub_r000785_17;
    int pub_r000785_18;
    int pub_r000785_19;
    int pub_r000785_20;
    int pub_r000785_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000785_0 >= -100 && pub_r000785_0 <= 100);
    __CPROVER_assume(pub_r000785_1 >= -100 && pub_r000785_1 <= 100);
    __CPROVER_assume(pub_r000785_2 >= -100 && pub_r000785_2 <= 100);
    __CPROVER_assume(pub_r000785_3 >= -100 && pub_r000785_3 <= 100);
    __CPROVER_assume(pub_r000785_4 >= -100 && pub_r000785_4 <= 100);
    __CPROVER_assume(pub_r000785_5 >= -100 && pub_r000785_5 <= 100);
    __CPROVER_assume(pub_r000785_6 >= -100 && pub_r000785_6 <= 100);
    __CPROVER_assume(pub_r000785_7 >= -100 && pub_r000785_7 <= 100);
    __CPROVER_assume(pub_r000785_8 >= -100 && pub_r000785_8 <= 100);
    __CPROVER_assume(pub_r000785_9 >= -100 && pub_r000785_9 <= 100);
    __CPROVER_assume(pub_r000785_10 >= -100 && pub_r000785_10 <= 100);
    __CPROVER_assume(pub_r000785_11 >= -100 && pub_r000785_11 <= 100);
    __CPROVER_assume(pub_r000785_12 >= -100 && pub_r000785_12 <= 100);
    __CPROVER_assume(pub_r000785_13 >= -100 && pub_r000785_13 <= 100);
    __CPROVER_assume(pub_r000785_14 >= -100 && pub_r000785_14 <= 100);
    __CPROVER_assume(pub_r000785_15 >= -100 && pub_r000785_15 <= 100);
    __CPROVER_assume(pub_r000785_16 >= -100 && pub_r000785_16 <= 100);
    __CPROVER_assume(pub_r000785_17 >= -100 && pub_r000785_17 <= 100);
    __CPROVER_assume(pub_r000785_18 >= -100 && pub_r000785_18 <= 100);
    __CPROVER_assume(pub_r000785_19 >= -100 && pub_r000785_19 <= 100);
    __CPROVER_assume(pub_r000785_20 >= -100 && pub_r000785_20 <= 100);
    __CPROVER_assume(pub_r000785_21 >= -100 && pub_r000785_21 <= 100);
    __CPROVER_assume(sec_r000785_0 >= 0 && sec_r000785_0 <= 255);
    __CPROVER_assume(sec_r000785_1 >= 0 && sec_r000785_1 <= 255);
    __CPROVER_assume(sec_r000785_2 >= 0 && sec_r000785_2 <= 255);
    __CPROVER_assume(sec_r000785_3 >= 0 && sec_r000785_3 <= 255);
    __CPROVER_assume(sec_r000785_4 >= 0 && sec_r000785_4 <= 255);
    __CPROVER_assume(sec_r000785_5 >= 0 && sec_r000785_5 <= 255);
    __CPROVER_assume(sec_r000785_6 >= 0 && sec_r000785_6 <= 255);
    __CPROVER_assume(sec_r000785_7 >= 0 && sec_r000785_7 <= 255);
    __CPROVER_assume(sec_r000785_8 >= 0 && sec_r000785_8 <= 255);
    __CPROVER_assume(sec_r000785_9 >= 0 && sec_r000785_9 <= 255);
    __CPROVER_assume(sec_r000785_10 >= 0 && sec_r000785_10 <= 255);
    __CPROVER_assume(sec_r000785_11 >= 0 && sec_r000785_11 <= 255);
    __CPROVER_assume(sec_r000785_12 >= 0 && sec_r000785_12 <= 255);
    __CPROVER_assume(sec_r000785_13 >= 0 && sec_r000785_13 <= 255);
    __CPROVER_assume(sec_r000785_14 >= 0 && sec_r000785_14 <= 255);
    __CPROVER_assume(sec_r000785_15 >= 0 && sec_r000785_15 <= 255);
    __CPROVER_assume(sec_r000785_16 >= 0 && sec_r000785_16 <= 255);
    __CPROVER_assume(sec_r000785_17 >= 0 && sec_r000785_17 <= 255);
    __CPROVER_assume(sec_r000785_18 >= 0 && sec_r000785_18 <= 255);
    __CPROVER_assume(sec_r000785_19 >= 0 && sec_r000785_19 <= 255);
    __CPROVER_assume(sec_r000785_20 >= 0 && sec_r000785_20 <= 255);
    __CPROVER_assume(sec_r000785_21 >= 0 && sec_r000785_21 <= 255);
    __CPROVER_assume(sec_r000785_22 >= 0 && sec_r000785_22 <= 255);
    __CPROVER_assume(sec_r000785_23 >= 0 && sec_r000785_23 <= 255);

    struct SensorNode_R000785_8513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000785_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000785_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000785_0 + 7) & 15;
    struct DeviceConfig_R000785_8513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000785_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000785_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000785_0 + 9) & 15;

    union RegisterBank_R000785_8513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 13) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 28) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 23) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 38) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 37) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 52) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 21) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 36) {
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 14) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 29) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 40) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 55) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 18) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 33) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 29) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 44) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r000785_5 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_59 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000785_12 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_59 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_59 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000785_22 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r000785_9 << 2) ^ (sec_r000785_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000785_6 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_59 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_59 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000785_6 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_62 << 2) ^ (sec_r000785_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_62 << 2) ^ (sec_r000785_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_64 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_60 << 1) ^ (sec_r000785_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_62 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r000785_5 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_64 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_64 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_76 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_69 << 2) ^ (sec_r000785_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_61 << 1) ^ (sec_r000785_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_65 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000785_23 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_59 << 1) ^ (sec_r000785_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000785_17 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000785_6 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_85 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_68 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_81 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000785_0 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_71 << 1) ^ (sec_r000785_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_87 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000785_4 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_71 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_83 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_92 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_62 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_87 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000785_14 << 2) ^ (sec_r000785_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_88 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_86 << 2) ^ (sec_r000785_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_73 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_60 << 2) ^ (sec_r000785_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000785_9 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_64 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r000785_8 << 2) ^ (sec_r000785_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_66 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000785_20 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_80 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000785_8 << 1) ^ (sec_r000785_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000785_23 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_63 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_70 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_80 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000785_4 << 2) ^ (sec_r000785_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_100 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_61 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_96 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_61 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_92 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_62 << 2) ^ (sec_r000785_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_103 << 2) ^ (sec_r000785_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_110 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r000785_11 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_75 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_75 << 2) ^ (sec_r000785_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_117 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_96 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000785_19 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_106 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000785_14 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_117 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_67 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_123 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_131 << 1) ^ (sec_r000785_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_59 << 1) ^ (sec_r000785_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000785_3 << 2) ^ (sec_r000785_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r000785_19 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_119 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_116 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_122 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_113 << 1) ^ (sec_r000785_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_103 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_68 << 2) ^ (sec_r000785_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_121 << 2) ^ (sec_r000785_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000785_16 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000785_3 << 2) ^ (sec_r000785_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_66 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000785_6 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000785_20 << 2) ^ (sec_r000785_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_95 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_151 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_122 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000785_3 << 1) ^ (sec_r000785_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_153 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_104 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000785_8 << 1) ^ (sec_r000785_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_133 << 2) ^ (sec_r000785_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_71 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_111 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_144 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_65 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_117 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_140 << 1) ^ (sec_r000785_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000785_10 << 2) ^ (sec_r000785_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_145 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_112 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_62 << 2) ^ (sec_r000785_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_144 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000785_1 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_73 << 2) ^ (sec_r000785_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000785_20 << 2) ^ (sec_r000785_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r000785_20 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000785_2 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_164 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_102 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000785_22 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_85 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000785_11 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_98 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_141 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_134 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000785_17 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000785_15 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000785_7 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_82 << 1) ^ (sec_r000785_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_91 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r000785_7 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_94 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_127 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000785_12 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_97 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_120 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_196 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000785_4 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000785_7 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_61 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r000785_15 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_91 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_201 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_147 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_202 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_203 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_74 << 2) ^ (sec_r000785_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_120 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r000785_2 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_200 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_87 << 1) ^ (sec_r000785_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000785_1 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_79 << 2) ^ (sec_r000785_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_132 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_211 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_102 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_149 << 1) ^ (sec_r000785_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_213 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_62 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000785_19 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_72 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r000785_17 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r000785_21 << 1) ^ (sec_r000785_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_218 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_148 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_105 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_202 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_221 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_90 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_120 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_223 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_223 << 1) ^ (sec_r000785_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_144 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_225 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_169 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_226 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_203 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_227 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_65 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_228 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_166 << 1) ^ (sec_r000785_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_229 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_65 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_119 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_231 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_116 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_232 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_214 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_233 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((sec_r000785_17 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_234 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r000785_22 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_235 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r000785_2 << 1) ^ (sec_r000785_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_236 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_233 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_237 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_232 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_238 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_161 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_239 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_240 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_239 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_241 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_122 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_242 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_161 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_243 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_194 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_244 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_190 << 1) ^ (sec_r000785_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_245 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_72 << 2) ^ (sec_r000785_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_246 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_164 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_247 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_196 << 2) ^ (sec_r000785_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_248 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_223 << 2) ^ (sec_r000785_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_249 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_153 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_250 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000785_10 << 1) ^ (sec_r000785_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_251 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_242 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_252 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_234 << 1) ^ (sec_r000785_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_253 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_78 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_254 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r000785_2 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_255 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r000785_9 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_256 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_142 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_257 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_62 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_258 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_238 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_259 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r000785_11 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_260 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((sec_r000785_14 << 2) ^ (sec_r000785_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_261 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_101 << 2) ^ (sec_r000785_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_262 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_239 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_263 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_206 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_264 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r000785_5 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_265 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_161 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_266 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((sec_r000785_22 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_267 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_238 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_268 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_61 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_269 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((sec_r000785_9 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_270 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_133 << 2) ^ (sec_r000785_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_271 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_144 << 2) ^ (sec_r000785_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_272 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_133 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_273 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_75 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_274 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_176 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_275 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_209 << 2) ^ (sec_r000785_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_276 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_225 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_277 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r000785_19 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_278 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_156 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_279 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_170 << 1) ^ (sec_r000785_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_280 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_205 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_281 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_151 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_282 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r000785_16 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_283 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_188 << 1) ^ (sec_r000785_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_284 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_79 << 2) ^ (sec_r000785_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_285 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_147 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_286 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_224 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_287 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000785_18 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_288 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000785_21 << 1) ^ (sec_r000785_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_289 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_165 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_290 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_125 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_291 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_246 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_292 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_122 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_293 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_93 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_294 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_290 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_295 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r000785_16 << 1) ^ (sec_r000785_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_296 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((sec_r000785_7 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_297 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((sec_r000785_2 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_298 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_106 << 1) ^ (sec_r000785_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_299 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_183 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_300 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((sec_r000785_21 << 1) ^ (sec_r000785_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_301 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((sec_r000785_22 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_302 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_288 << 2) ^ (sec_r000785_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_303 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((sec_r000785_23 << 2) ^ (sec_r000785_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_304 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r000785_23 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_305 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_267 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_306 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_246 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_307 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((sec_r000785_21 << 2) ^ (sec_r000785_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_308 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_148 << 1) ^ (sec_r000785_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_309 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_246 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_310 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r000785_12 << 2) ^ (sec_r000785_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_311 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r000785_11 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_312 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r000785_13 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_313 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_262 << 2) ^ (sec_r000785_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_314 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((sec_r000785_10 << 1) ^ (sec_r000785_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_315 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_245 << 2) ^ (sec_r000785_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_316 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_119 << 2) ^ (sec_r000785_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_317 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_125 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_318 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((sec_r000785_9 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_319 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_260 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_320 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_179 << 1) ^ (sec_r000785_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_321 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_98 << 2) ^ (sec_r000785_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_322 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_281 << 1) ^ (sec_r000785_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_323 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_144 << 2) ^ (sec_r000785_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_324 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_281 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_325 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_308 << 2) ^ (sec_r000785_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_326 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_119 << 1) ^ (sec_r000785_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_327 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_144 << 1) ^ (sec_r000785_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_328 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_124 << 1) ^ (sec_r000785_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_329 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((sec_r000785_1 << 1) ^ (sec_r000785_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_330 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_229 << 1) ^ (sec_r000785_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_331 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_234 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_332 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((sec_r000785_1 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_333 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r000785_22 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_334 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_140 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_335 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((sec_r000785_6 << 1) ^ (sec_r000785_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_336 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((sec_r000785_5 << 2) ^ (sec_r000785_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_337 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_163 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_338 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_62 << 2) ^ (sec_r000785_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_339 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((sec_r000785_4 << 2) ^ (sec_r000785_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_340 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r000785_0 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_341 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r000785_7 << 2) ^ (sec_r000785_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_342 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_135 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_343 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((sec_r000785_0 << 2) ^ (sec_r000785_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_344 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_217 << 2) ^ (sec_r000785_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_345 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_337 << 1) ^ (sec_r000785_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_346 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_202 << 1) ^ (sec_r000785_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_347 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_184 << 1) ^ (sec_r000785_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_348 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r000785_14 << 1) ^ (sec_r000785_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_349 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_344 << 1) ^ (sec_r000785_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_350 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_112 << 2) ^ (sec_r000785_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_351 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_90 << 1) ^ (sec_r000785_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_352 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_325 << 2) ^ (sec_r000785_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_353 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_330 << 2) ^ (sec_r000785_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_354 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r000785_8 << 2) ^ (sec_r000785_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_355 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_281 << 1) ^ (sec_r000785_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_356 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_249 << 2) ^ (sec_r000785_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_357 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_353 << 2) ^ (sec_r000785_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_358 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_356 << 2) ^ (sec_r000785_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_359 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_290 << 2) ^ (sec_r000785_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_360 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_360 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
