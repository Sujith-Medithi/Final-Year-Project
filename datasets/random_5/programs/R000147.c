/*
 * Benchmark Program: R000147
 * Security Family: nested_implicit_flow
 * Generator Seed: 514713
 * High Inputs: 21 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000147_4713_0 {
    short threshold;
    unsigned char calib;
    int offset;
    int reading;
    int buffer[3];
};

struct DeviceConfig_R000147_4713_1 {
    int parity;
    short baud_rate;
    int timeout;
    int buffer[3];
};

struct Transaction_R000147_4713_2 {
    int fee;
    int rate;
    int auth_code;
    int status;
    int buffer[3];
};

struct EventLog_R000147_4713_3 {
    short facility;
    unsigned char signature;
    unsigned char timestamp;
    unsigned char seq;
    int buffer[3];
};

union ColorPixel_R000147_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000147_4713_0(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_63 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_63 > 43) {
        acc = (acc + offset_63 * 2 + 5) & 127;
        aux ^= (offset_63 & 15);
    } else {
        acc = (acc - offset_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_74 = (aux + st.buffer[1]) & 3;
    switch (quotient_74) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_89 = local_arr[aux % 3];
    acc = (acc + factor_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_77 = local_arr[aux % 3];
    acc = (acc + stride_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_2(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_20) & 63;
    acc ^= aux;
    int parity_73 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_73 > 22) {
        acc = (acc + parity_73 * 2 + 5) & 127;
        aux ^= (parity_73 & 15);
    } else {
        acc = (acc - parity_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000147_4713_3(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000147_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_57 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_57 > 35) {
        acc = (acc + quantum_57 * 2 + 5) & 127;
        aux ^= (quantum_57 & 15);
    } else {
        acc = (acc - quantum_57 + 11) & 127;
        aux += 3;
    }
    int coefficient_47 = (aux + st.buffer[1]) & 3;
    switch (coefficient_47) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_45 = local_arr[aux % 3];
    acc = (acc + segment_45 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_92) & 63;
    acc ^= aux;
    int margin_82 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_82 > 20) {
        acc = (acc + margin_82 * 2 + 5) & 127;
        aux ^= (margin_82 & 15);
    } else {
        acc = (acc - margin_82 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_88 = local_arr[aux % 3];
    acc = (acc + phase_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_5(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_78 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_78 > 17) {
        acc = (acc + segment_78 * 2 + 5) & 127;
        aux ^= (segment_78 & 15);
    } else {
        acc = (acc - segment_78 + 11) & 127;
        aux += 3;
    }
    int pivot_54 = (aux + st.buffer[1]) & 3;
    switch (pivot_54) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000147_4713_6(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int parity_99 = local_arr[aux % 3];
    acc = (acc + parity_99 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_21) & 63;
    acc ^= aux;
    int metric_86 = (aux + st.buffer[1]) & 3;
    switch (metric_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000147_4713_7(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int offset_58 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_58 > 42) {
        acc = (acc + offset_58 * 2 + 5) & 127;
        aux ^= (offset_58 & 15);
    } else {
        acc = (acc - offset_58 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_11 = local_arr[aux % 3];
    acc = (acc + offset_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_8(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_33 = (aux + st.buffer[1]) & 3;
    switch (anchor_33) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_50 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_50 > 43) {
        acc = (acc + tracker_50 * 2 + 5) & 127;
        aux ^= (tracker_50 & 15);
    } else {
        acc = (acc - tracker_50 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_12 = local_arr[aux % 3];
    acc = (acc + index_reg_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_9(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000147_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_11 = local_arr[aux % 3];
    acc = (acc + window_11 * 2) & 127;
    int coefficient_96 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_96 > 44) {
        acc = (acc + coefficient_96 * 2 + 5) & 127;
        aux ^= (coefficient_96 & 15);
    } else {
        acc = (acc - coefficient_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000147_4713_10(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000147_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tally_87 = local_arr[aux % 3];
    acc = (acc + tally_87 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_11(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000147_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int factor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_59 > 34) {
        acc = (acc + factor_59 * 2 + 5) & 127;
        aux ^= (factor_59 & 15);
    } else {
        acc = (acc - factor_59 + 11) & 127;
        aux += 3;
    }
    int tracker_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_92 = (aux + st.buffer[1]) & 3;
    switch (factor_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000147_4713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_64 = (aux + st.buffer[1]) & 3;
    switch (stride_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_13(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000147_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int damping_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_44 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_44 > 23) {
        acc = (acc + checksum_44 * 2 + 5) & 127;
        aux ^= (checksum_44 & 15);
    } else {
        acc = (acc - checksum_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_14 = local_arr[aux % 3];
    acc = (acc + metric_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000147_4713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000147_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int coefficient_32 = local_arr[aux % 3];
    acc = (acc + coefficient_32 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000147_0;
    int sec_r000147_1;
    int sec_r000147_2;
    int sec_r000147_3;
    int sec_r000147_4;
    int sec_r000147_5;
    int sec_r000147_6;
    int sec_r000147_7;
    int sec_r000147_8;
    int sec_r000147_9;
    int sec_r000147_10;
    int sec_r000147_11;
    int sec_r000147_12;
    int sec_r000147_13;
    int sec_r000147_14;
    int sec_r000147_15;
    int sec_r000147_16;
    int sec_r000147_17;
    int sec_r000147_18;
    int sec_r000147_19;
    int sec_r000147_20;
    int pub_r000147_0;
    int pub_r000147_1;
    int pub_r000147_2;
    int pub_r000147_3;
    int pub_r000147_4;
    int pub_r000147_5;
    int pub_r000147_6;
    int pub_r000147_7;
    int pub_r000147_8;
    int pub_r000147_9;
    int pub_r000147_10;
    int pub_r000147_11;
    int pub_r000147_12;
    int pub_r000147_13;
    int pub_r000147_14;
    int pub_r000147_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000147_0 >= -100 && pub_r000147_0 <= 100);
    __CPROVER_assume(pub_r000147_1 >= -100 && pub_r000147_1 <= 100);
    __CPROVER_assume(pub_r000147_2 >= -100 && pub_r000147_2 <= 100);
    __CPROVER_assume(pub_r000147_3 >= -100 && pub_r000147_3 <= 100);
    __CPROVER_assume(pub_r000147_4 >= -100 && pub_r000147_4 <= 100);
    __CPROVER_assume(pub_r000147_5 >= -100 && pub_r000147_5 <= 100);
    __CPROVER_assume(pub_r000147_6 >= -100 && pub_r000147_6 <= 100);
    __CPROVER_assume(pub_r000147_7 >= -100 && pub_r000147_7 <= 100);
    __CPROVER_assume(pub_r000147_8 >= -100 && pub_r000147_8 <= 100);
    __CPROVER_assume(pub_r000147_9 >= -100 && pub_r000147_9 <= 100);
    __CPROVER_assume(pub_r000147_10 >= -100 && pub_r000147_10 <= 100);
    __CPROVER_assume(pub_r000147_11 >= -100 && pub_r000147_11 <= 100);
    __CPROVER_assume(pub_r000147_12 >= -100 && pub_r000147_12 <= 100);
    __CPROVER_assume(pub_r000147_13 >= -100 && pub_r000147_13 <= 100);
    __CPROVER_assume(pub_r000147_14 >= -100 && pub_r000147_14 <= 100);
    __CPROVER_assume(pub_r000147_15 >= -100 && pub_r000147_15 <= 100);
    __CPROVER_assume(sec_r000147_0 >= 0 && sec_r000147_0 <= 255);
    __CPROVER_assume(sec_r000147_1 >= 0 && sec_r000147_1 <= 255);
    __CPROVER_assume(sec_r000147_2 >= 0 && sec_r000147_2 <= 255);
    __CPROVER_assume(sec_r000147_3 >= 0 && sec_r000147_3 <= 255);
    __CPROVER_assume(sec_r000147_4 >= 0 && sec_r000147_4 <= 255);
    __CPROVER_assume(sec_r000147_5 >= 0 && sec_r000147_5 <= 255);
    __CPROVER_assume(sec_r000147_6 >= 0 && sec_r000147_6 <= 255);
    __CPROVER_assume(sec_r000147_7 >= 0 && sec_r000147_7 <= 255);
    __CPROVER_assume(sec_r000147_8 >= 0 && sec_r000147_8 <= 255);
    __CPROVER_assume(sec_r000147_9 >= 0 && sec_r000147_9 <= 255);
    __CPROVER_assume(sec_r000147_10 >= 0 && sec_r000147_10 <= 255);
    __CPROVER_assume(sec_r000147_11 >= 0 && sec_r000147_11 <= 255);
    __CPROVER_assume(sec_r000147_12 >= 0 && sec_r000147_12 <= 255);
    __CPROVER_assume(sec_r000147_13 >= 0 && sec_r000147_13 <= 255);
    __CPROVER_assume(sec_r000147_14 >= 0 && sec_r000147_14 <= 255);
    __CPROVER_assume(sec_r000147_15 >= 0 && sec_r000147_15 <= 255);
    __CPROVER_assume(sec_r000147_16 >= 0 && sec_r000147_16 <= 255);
    __CPROVER_assume(sec_r000147_17 >= 0 && sec_r000147_17 <= 255);
    __CPROVER_assume(sec_r000147_18 >= 0 && sec_r000147_18 <= 255);
    __CPROVER_assume(sec_r000147_19 >= 0 && sec_r000147_19 <= 255);
    __CPROVER_assume(sec_r000147_20 >= 0 && sec_r000147_20 <= 255);

    struct SensorNode_R000147_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000147_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000147_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000147_0 + 7) & 15;
    struct DeviceConfig_R000147_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000147_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000147_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000147_0 + 9) & 15;
    struct Transaction_R000147_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000147_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000147_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000147_0 + 11) & 15;
    struct EventLog_R000147_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000147_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000147_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000147_0 + 13) & 15;

    union ColorPixel_R000147_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 11) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 26) {
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
    if (stage_v_1 > 17) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 32) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
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
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
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
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 35) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 25) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 40) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 40) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 55) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 19) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 34) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 20) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 35) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 17) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 32) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
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
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
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
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 39) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 54) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

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
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_2.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_3.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000147_6 & 1) != 0) {
        if ((sec_r000147_17 & 2) != 0) {
            stage_v_89 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000147_6 & 2) != 0) {
            stage_v_90 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000147_0 & 1) != 0) {
        if ((sec_r000147_6 & 2) != 0) {
            stage_v_91 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000147_2 & 1) != 0) {
        if ((sec_r000147_17 & 2) != 0) {
            stage_v_92 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000147_4 & 1) != 0) {
        if ((sec_r000147_8 & 2) != 0) {
            stage_v_93 = (pub_r000147_11 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000147_11 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000147_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_94 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000147_19 & 2) != 0) {
            stage_v_95 = (pub_r000147_14 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000147_14 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000147_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000147_12 & 2) != 0) {
            stage_v_96 = (pub_r000147_14 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000147_14 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000147_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000147_4 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_97 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000147_17 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_98 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_99 = (pub_r000147_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000147_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000147_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_100 = (pub_r000147_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000147_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000147_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000147_20 & 2) != 0) {
            stage_v_101 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_102 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000147_12 & 2) != 0) {
            stage_v_103 = (pub_r000147_10 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000147_10 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000147_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000147_9 & 1) != 0) {
        if ((sec_r000147_7 & 2) != 0) {
            stage_v_104 = (pub_r000147_1 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000147_1 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000147_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000147_3 & 2) != 0) {
            stage_v_105 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_106 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_107 = (pub_r000147_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000147_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000147_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000147_1 & 1) != 0) {
        if ((sec_r000147_14 & 2) != 0) {
            stage_v_108 = (pub_r000147_4 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000147_4 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000147_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000147_9 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_109 = (pub_r000147_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000147_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000147_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000147_18 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_110 = (pub_r000147_0 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000147_0 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000147_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000147_8 & 2) != 0) {
            stage_v_111 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_112 = (pub_r000147_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000147_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000147_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000147_12 & 2) != 0) {
            stage_v_113 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000147_1 & 2) != 0) {
            stage_v_114 = (pub_r000147_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000147_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000147_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000147_3 & 2) != 0) {
            stage_v_115 = (pub_r000147_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000147_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000147_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000147_19 & 2) != 0) {
            stage_v_116 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000147_1 & 1) != 0) {
        if ((sec_r000147_1 & 2) != 0) {
            stage_v_117 = (pub_r000147_8 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000147_8 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000147_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000147_20 & 2) != 0) {
            stage_v_118 = (pub_r000147_4 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000147_4 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000147_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000147_20 & 1) != 0) {
        if ((sec_r000147_2 & 2) != 0) {
            stage_v_119 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_120 = (pub_r000147_7 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000147_7 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000147_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000147_5 & 2) != 0) {
            stage_v_121 = (pub_r000147_11 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000147_11 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000147_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000147_1 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_122 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_123 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000147_14 & 2) != 0) {
            stage_v_124 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000147_2 & 2) != 0) {
            stage_v_125 = (pub_r000147_0 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000147_0 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000147_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000147_11 & 1) != 0) {
        if ((sec_r000147_14 & 2) != 0) {
            stage_v_126 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000147_3 & 2) != 0) {
            stage_v_127 = (pub_r000147_1 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000147_1 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000147_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000147_12 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_128 = (pub_r000147_12 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000147_12 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000147_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000147_8 & 2) != 0) {
            stage_v_129 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000147_4 & 2) != 0) {
            stage_v_130 = (pub_r000147_0 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000147_0 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000147_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000147_12 & 1) != 0) {
        if ((sec_r000147_2 & 2) != 0) {
            stage_v_131 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000147_18 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_132 = (pub_r000147_11 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000147_11 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000147_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000147_5 & 2) != 0) {
            stage_v_133 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000147_14 & 1) != 0) {
        if ((sec_r000147_6 & 2) != 0) {
            stage_v_134 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000147_20 & 2) != 0) {
            stage_v_135 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_136 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_137 = (pub_r000147_7 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000147_7 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000147_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000147_4 & 1) != 0) {
        if ((sec_r000147_3 & 2) != 0) {
            stage_v_138 = (pub_r000147_11 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000147_11 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000147_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000147_19 & 1) != 0) {
        if ((sec_r000147_14 & 2) != 0) {
            stage_v_139 = (pub_r000147_10 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000147_10 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000147_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000147_4 & 2) != 0) {
            stage_v_140 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000147_13 & 1) != 0) {
        if ((sec_r000147_11 & 2) != 0) {
            stage_v_141 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000147_20 & 2) != 0) {
            stage_v_142 = (pub_r000147_0 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000147_0 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000147_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_143 = (pub_r000147_0 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000147_0 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000147_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000147_0 & 2) != 0) {
            stage_v_144 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000147_7 & 2) != 0) {
            stage_v_145 = (pub_r000147_5 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000147_5 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000147_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000147_18 & 2) != 0) {
            stage_v_146 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000147_1 & 2) != 0) {
            stage_v_147 = (pub_r000147_6 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000147_6 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000147_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r000147_16 & 2) != 0) {
            stage_v_148 = (pub_r000147_10 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000147_10 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000147_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_149 = (pub_r000147_11 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000147_11 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000147_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000147_5 & 2) != 0) {
            stage_v_150 = (pub_r000147_10 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000147_10 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000147_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000147_12 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_151 = (pub_r000147_12 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000147_12 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000147_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000147_6 & 2) != 0) {
            stage_v_152 = (pub_r000147_15 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000147_15 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000147_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000147_14 & 1) != 0) {
        if ((sec_r000147_16 & 2) != 0) {
            stage_v_153 = (pub_r000147_7 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000147_7 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000147_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000147_9 & 2) != 0) {
            stage_v_154 = (pub_r000147_12 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000147_12 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000147_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000147_1 & 2) != 0) {
            stage_v_155 = (pub_r000147_14 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000147_14 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000147_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r000147_16 & 2) != 0) {
            stage_v_156 = (pub_r000147_2 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000147_2 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000147_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000147_20 & 2) != 0) {
            stage_v_157 = (pub_r000147_4 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000147_4 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000147_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000147_15 & 2) != 0) {
            stage_v_158 = (pub_r000147_8 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000147_8 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000147_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000147_19 & 2) != 0) {
            stage_v_159 = (pub_r000147_14 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000147_14 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000147_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000147_6 & 2) != 0) {
            stage_v_160 = (pub_r000147_9 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000147_9 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000147_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000147_7 & 1) != 0) {
        if ((sec_r000147_13 & 2) != 0) {
            stage_v_161 = (pub_r000147_3 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000147_3 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000147_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
